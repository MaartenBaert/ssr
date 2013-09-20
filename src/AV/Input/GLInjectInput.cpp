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

#include "../glinject/ShmStructs.h"

// The highest expected latency between GLInject and the input thread.
const int64_t GLInjectInput::MAX_COMMUNICATION_LATENCY = 100000;

GLInjectInput::GLInjectInput(GLInjectLauncher *launcher) {

	m_launcher = launcher;

	m_cbuffer_size = m_launcher->GetCBufferSize();
	m_max_bytes = m_launcher->GetMaxBytes();

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

GLInjectInput::~GLInjectInput() {

	// tell the thread to stop
	if(m_thread.joinable()) {
		Logger::LogInfo("[GLInjectInput::~GLInjectInput] Telling input thread to stop ...");
		m_should_stop = true;
		m_thread.join();
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
	GLInjectHeader *header = (GLInjectHeader*) m_shm_main_ptr;
	std::atomic_thread_fence(std::memory_order_acquire);
	header->read_pos = header->write_pos;
	std::atomic_thread_fence(std::memory_order_release);

	// start input thread
	m_should_stop = false;
	m_error_occurred = false;
	m_thread = std::thread(&GLInjectInput::InputThread, this);

}

void GLInjectInput::Free() {

}

void GLInjectInput::InputThread() {
	try {

		Logger::LogInfo("[GLInjectInput::InputThread] Input thread started.");

		//int64_t next_frame_time = hrt_time_micro();
		while(!m_should_stop) {

			// is a frame ready?
			GLInjectHeader *header = (GLInjectHeader*) m_shm_main_ptr;
			std::atomic_thread_fence(std::memory_order_acquire);
			unsigned int read_pos = header->read_pos;
			unsigned int write_pos = header->write_pos;
			std::atomic_thread_fence(std::memory_order_release);
			unsigned int frames_ready = positive_mod((int) write_pos - (int) read_pos, (int) m_cbuffer_size * 2);
			if(frames_ready == 0) {
				PushVideoPing(hrt_time_micro() - MAX_COMMUNICATION_LATENCY);
				usleep(10000);
				continue;
			}

			std::atomic_thread_fence(std::memory_order_acquire); // start reading frame

			// get the frame info
			unsigned int current_frame = read_pos % m_cbuffer_size;
			GLInjectFrameInfo *frameinfo = (GLInjectFrameInfo*) (m_shm_main_ptr + sizeof(GLInjectHeader) + sizeof(GLInjectFrameInfo) * current_frame);
			int64_t timestamp = frameinfo->timestamp;
			unsigned int frame_width = frameinfo->width;
			unsigned int frame_height = frameinfo->height;
			if(frame_width < 2 || frame_height < 2) {
				Logger::LogInfo("[GLInjectInput::InputThread] Error: Image is too small!");
				throw GLInjectException();
			}
			if(frame_width > 10000 || frame_height > 10000) {
				Logger::LogInfo("[GLInjectInput::InputThread] Error: Image is too large!");
				throw GLInjectException();
			}

			// get the image
			uint8_t *image_data = (uint8_t*) m_shm_frame_ptrs[current_frame];
			int image_stride = grow_align16(frame_width * 4);
			if(image_stride * frame_height > m_max_bytes) {
				Logger::LogInfo("[GLInjectInput::InputThread] Error: Image is supposedly larger than the maximum size!");
				throw GLInjectException();
			}

			// flip the image upside down by changing the pointer and stride
			// this is needed because OpenGL stores frames upside-down
			image_data += image_stride * (frame_height - 1);
			image_stride = -image_stride;

			// push out the frame
			PushVideoFrame(frame_width, frame_height, image_data, image_stride, PIX_FMT_BGRA, timestamp);

			std::atomic_thread_fence(std::memory_order_release); // stop reading frame

			// go to the next frame
			std::atomic_thread_fence(std::memory_order_acquire);
			header->read_pos = (read_pos + 1) % (m_cbuffer_size * 2);
			std::atomic_thread_fence(std::memory_order_release);

		}

		Logger::LogInfo("[GLInjectInput::InputThread] Input thread stopped.");

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError(QString("[GLInjectInput::InputThread] Exception '") + e.what() + "' in input thread.");
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[GLInjectInput::InputThread] Unknown exception in input thread.");
	}
}
