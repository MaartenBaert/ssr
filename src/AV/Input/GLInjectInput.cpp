/*
Copyright (c) 2012-2013 Maarten Baert <maarten-baert@hotmail.com>

This file is part of SimpleScreenRecorder.

SimpleScreenRecorder is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

SimpleScreenRecorder is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with SimpleScreenRecorder.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Global.h"
#include "GLInjectInput.h"

#include "Logger.h"
#include "AVWrapper.h"
#include "Synchronizer.h"
#include "VideoEncoder.h"
#include "GLInjectLauncher.h"

#include "VideoPreviewer.h"

GLInjectInput::GLInjectInput(Synchronizer* synchronizer, GLInjectLauncher* launcher) {
	Q_ASSERT(synchronizer->GetVideoEncoder() != NULL);

	m_synchronizer = synchronizer;
	m_launcher = launcher;

	m_cbuffer_size = m_launcher->GetCBufferSize();
	m_max_bytes = m_launcher->GetMaxBytes();
	m_frame_rate = m_synchronizer->GetVideoEncoder()->GetFrameRate();
	m_out_width = m_synchronizer->GetVideoEncoder()->GetWidth();
	m_out_height = m_synchronizer->GetVideoEncoder()->GetHeight();

	m_warn_swscale = true;
	m_sws_context = NULL;

	{
		SharedLock lock(&m_shared_data);
		lock->m_video_previewer = NULL;
	}

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

GLInjectInput::~GLInjectInput() {

	// tell the thread to stop
	if(isRunning()) {
		Logger::LogInfo("[GLInjectInput::~GLInjectInput] Telling input thread to stop ...");
		m_should_stop = true;
		wait();
	}

	// free everything
	Free();

}

void GLInjectInput::ConnectVideoPreviewer(VideoPreviewer* video_previewer) {
	SharedLock lock(&m_shared_data);
	lock->m_video_previewer = video_previewer;
}

void GLInjectInput::Init() {

	// get the main shared memory
	m_shm_main_ptr = m_launcher->GetMainSharedPointer();

	// get the frame shared memory
	for(unsigned int i = 0; i < m_cbuffer_size; ++i) {
		m_shm_frame_ptrs.push_back(m_launcher->GetFrameSharedPointer(i));
	}

	// flush the circular buffer
	((GLInjectHeader*) m_shm_main_ptr)->read_pos = ((GLInjectHeader*) m_shm_main_ptr)->write_pos;

	// start input thread
	m_should_stop = false;
	m_error_occurred = false;
	start();

}

void GLInjectInput::Free() {
	if(m_sws_context != NULL) {
		sws_freeContext(m_sws_context);
		m_sws_context = NULL;
	}
}

void GLInjectInput::run() {
	try {

		Logger::LogInfo("[GLInjectInput::run] Input thread started.");

		int64_t next_frame_time = hrt_time_micro();
		while(!m_should_stop) {

			// is a frame ready?
			GLInjectHeader header = *(GLInjectHeader*) m_shm_main_ptr;
			unsigned int frames_ready = positive_mod((int) header.write_pos - (int) header.read_pos, (int) m_cbuffer_size * 2);
			if(frames_ready == 0) {
				usleep(10000);
				continue;
			}

			// get the frame info
			unsigned int current_frame = header.read_pos % m_cbuffer_size;
			GLInjectFrameInfo frameinfo = *(GLInjectFrameInfo*) (m_shm_main_ptr + sizeof(GLInjectHeader) + sizeof(GLInjectFrameInfo) * current_frame);
			if(frameinfo.width < 2 || frameinfo.height < 2) {
				Logger::LogInfo("[GLInjectInput::run] Error: Image is too small!");
				throw GLInjectException();
			}
			if(frameinfo.width > 10000 || frameinfo.height > 10000) {
				Logger::LogInfo("[GLInjectInput::run] Error: Image is too large!");
				throw GLInjectException();
			}
			if(frameinfo.timestamp < next_frame_time) {
				((GLInjectHeader*) m_shm_main_ptr)->read_pos = (header.read_pos + 1) % (m_cbuffer_size * 2);
				continue;
			}
			next_frame_time = std::max(next_frame_time + m_synchronizer->GetVideoEncoder()->GetFrameDelay(), frameinfo.timestamp);

			SharedLock lock(&m_shared_data);

			// get the image
			uint8_t *image_data = (uint8_t*) m_shm_frame_ptrs[current_frame];
			int image_stride = grow_align16(frameinfo.width * 4);
			if(image_stride * frameinfo.height > m_max_bytes) {
				Logger::LogInfo("[GLInjectInput::run] Error: Image is supposedly larger than the maximum size!");
				throw GLInjectException();
			}

			// flip the image upside down by changing the pointer and stride
			// this is needed because OpenGL stores frames upside-down
			image_data += image_stride * (frameinfo.height - 1);
			image_stride = -image_stride;

			// let the previewer read the frame
			if(lock->m_video_previewer != NULL) {
				lock->m_video_previewer->ReadFrame(frameinfo.width, frameinfo.height, image_data, image_stride, PIX_FMT_BGRA);
			}

			// allocate the converted frame, with proper alignment
			// Y = 1 byte per pixel, U or V = 1 byte per 2x2 pixels
			int l1 = grow_align16(m_out_width);
			int l2 = grow_align16(m_out_width / 2);
			int s1 = grow_align16(l1 * m_out_height);
			int s2 = grow_align16(l2 * m_out_height / 2);
			std::unique_ptr<AVFrameWrapper> converted_frame(new AVFrameWrapper(s1 + 2 * s2));
			converted_frame->data[1] = converted_frame->data[0] + s1;
			converted_frame->data[2] = converted_frame->data[1] + s2;
			converted_frame->linesize[0] = l1;
			converted_frame->linesize[1] = l2;
			converted_frame->linesize[2] = l2;

			// convert the frame to YUV420P
			bool scaling = (frameinfo.width != m_out_width || frameinfo.height != m_out_height);
			if(!scaling) {

				// use my faster converter
				m_yuv_converter.Convert(frameinfo.width, frameinfo.height, image_data, image_stride, converted_frame->data, converted_frame->linesize);

			} else {

				if(m_warn_swscale) {
					m_warn_swscale = false;
					Logger::LogInfo("[GLInjectInput::run] Using swscale for scaling.");
				}

				// get sws context
				m_sws_context = sws_getCachedContext(m_sws_context,
													 frameinfo.width, frameinfo.height, PIX_FMT_BGRA,
													 m_out_width, m_out_height, PIX_FMT_YUV420P,
													 SWS_BILINEAR, NULL, NULL, NULL);
				if(m_sws_context == NULL) {
					Logger::LogError("[GLInjectInput::run] Error: Can't get swscale context!");
					throw LibavException();
				}
				sws_scale(m_sws_context, &image_data, &image_stride, 0, frameinfo.height, converted_frame->data, converted_frame->linesize);

			}

			// go to the next frame
			((GLInjectHeader*) m_shm_main_ptr)->read_pos = (header.read_pos + 1) % (m_cbuffer_size * 2);

			// save the frame
			m_synchronizer->AddVideoFrame(std::move(converted_frame), frameinfo.timestamp);

		}

		Logger::LogInfo("[GLInjectInput::run] Input thread stopped.");

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError(QString("[GLInjectInput::run] Exception '") + e.what() + "' in input thread.");
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[GLInjectInput::run] Unknown exception in input thread.");
	}
}

