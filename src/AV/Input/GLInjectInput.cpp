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

// The maximum delay between frames, in microseconds. If the delay is longer, duplicates will be inserted.
// This is needed because some codecs/players can't handle long delays.
const int64_t GLInjectInput::MAX_FRAME_DELAY = 200000;

// The highest expected latency between GLInject and the input thread.
const int64_t GLInjectInput::MAX_COMMUNICATION_LATENCY = 50000;

GLInjectInput::GLInjectInput(GLInjectLauncher *launcher, unsigned int frame_rate, bool insert_duplicates) {

	m_launcher = launcher;

	m_cbuffer_size = m_launcher->GetCBufferSize();
	m_max_bytes = m_launcher->GetMaxBytes();
	m_frame_rate = frame_rate;
	m_insert_duplicates = insert_duplicates;

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

}

void GLInjectInput::run() {
	try {

		Logger::LogInfo("[GLInjectInput::run] Input thread started.");

		// Sometimes long delays between frames can occur, e.g. when a game is showing a loading screen.
		// Not all codecs/players can handle that. It's also a problem for streaming. To fix this, long delays should be avoided by
		// duplicating the previous frame a few times when needed. The problem is that the previous frame has been passed on to the
		// synchronizer and can't be used anymore. This could be fixed by creating a copy of each frame, but that is wasteful.
		// Instead, the last frame is simply held back until the next frame is available. This increases the latency by one frame,
		// which is not really a problem (the synchronizer will simply hold on to the audio a bit longer, which doesn't change the result).
		//TODO// std::unique_ptr<AVFrameWrapper> previous_frame;
		//TODO// int64_t previous_timestamp = 0; // value won't be used, but GCC gives a warning otherwise

		int64_t next_frame_time = hrt_time_micro();
		while(!m_should_stop) {

			// is a frame ready?
			GLInjectHeader header = *(GLInjectHeader*) m_shm_main_ptr;
			unsigned int frames_ready = positive_mod((int) header.write_pos - (int) header.read_pos, (int) m_cbuffer_size * 2);
			if(frames_ready == 0) {

				//TODO//
				// Calculate at what point in time the duplicate should be inserted.
				// This is always in the past, because we don't want to drop a real frame because it was captured
				// right after the duplicate was inserted. MAX_COMMUNICATION_LATENCY simulates the latency between GLInject and this thread,
				// i.e. any new frame is assumed to have a timestamp higher than the current time minus MAX_COMMUNICATION_LATENCY. The duplicate
				// frame will have a timestamp that's one frame earlier than that time, so it will never interfere with the real frame.
				/*int64_t delay = m_synchronizer->GetVideoEncoder()->GetFrameDelay();
				int64_t duplicate_timestamp = hrt_time_micro() - MAX_COMMUNICATION_LATENCY - delay;
				int64_t extra_delay = (m_insert_duplicates)? 0 : MAX_FRAME_DELAY;

				// is the delay too high?
				if(previous_frame != NULL && duplicate_timestamp >= next_frame_time + extra_delay) {

					// insert a duplicate frame
					next_frame_time = std::max(next_frame_time + delay, duplicate_timestamp);

					// allocate the duplicate frame, with proper alignment
					// Y = 1 byte per pixel, U or V = 1 byte per 2x2 pixels
					int l1 = grow_align16(m_out_width);
					int l2 = grow_align16(m_out_width / 2);
					int s1 = grow_align16(l1 * m_out_height);
					int s2 = grow_align16(l2 * m_out_height / 2);
					std::unique_ptr<AVFrameWrapper> duplicate_frame(new AVFrameWrapper(s1 + 2 * s2));
					duplicate_frame->data[1] = duplicate_frame->data[0] + s1;
					duplicate_frame->data[2] = duplicate_frame->data[1] + s2;
					duplicate_frame->linesize[0] = l1;
					duplicate_frame->linesize[1] = l2;
					duplicate_frame->linesize[2] = l2;

					// copy the data (this is simple because we know how the frame was allocated)
					memcpy(duplicate_frame->data[0], previous_frame->data[0], s1 + 2 * s2);

					// save the frame
					m_synchronizer->AddVideoFrame(std::move(previous_frame), previous_timestamp);
					previous_frame = std::move(duplicate_frame);
					previous_timestamp = duplicate_timestamp;

					continue;

				}*/

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
				// this frame is too early, go to the next frame
				((GLInjectHeader*) m_shm_main_ptr)->read_pos = (header.read_pos + 1) % (m_cbuffer_size * 2);
				continue;
			}
			next_frame_time = std::max(next_frame_time + CalculateVideoFrameInterval(m_frame_rate), frameinfo.timestamp);

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

			// push out the frame
			PushVideoFrame(frameinfo.width, frameinfo.height, image_data, image_stride, PIX_FMT_BGRA, frameinfo.timestamp);

			// go to the next frame
			((GLInjectHeader*) m_shm_main_ptr)->read_pos = (header.read_pos + 1) % (m_cbuffer_size * 2);

			// save the frame
			/*if(previous_frame != NULL) {
				m_synchronizer->AddVideoFrame(std::move(previous_frame), previous_timestamp);
			}
			previous_frame = std::move(converted_frame);
			previous_timestamp = frameinfo.timestamp;*/

		}

		// save the frame that was held back
		/*if(previous_frame != NULL) {
			m_synchronizer->AddVideoFrame(std::move(previous_frame), previous_timestamp);
		}*/

		Logger::LogInfo("[GLInjectInput::run] Input thread stopped.");

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError(QString("[GLInjectInput::run] Exception '") + e.what() + "' in input thread.");
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[GLInjectInput::run] Unknown exception in input thread.");
	}
}

