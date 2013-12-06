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
#include "DRMInput.h"

#if SSR_USE_DRM

#include "Logger.h"

#include <xf86drm.h>

//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <sys/mman.h>

DRMInput::DRMInput(unsigned int x, unsigned int y, unsigned int width, unsigned int height, bool record_cursor, bool follow_cursor) {

	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_record_cursor = record_cursor;
	m_follow_cursor = follow_cursor;

	m_drm_fd = -1;

	if(m_width < 2 || m_height < 2) {
		Logger::LogError("[DRMInput::DRMInput] " + QObject::tr("Error: Width or height is too small, the minimum width and height is %1!").arg(2));
		throw WaylandException();
	}
	if(m_width > 10000 || m_height > 10000) {
		Logger::LogError("[DRMInput::DRMInput] " + QObject::tr("Error: Width or height is too large, the maximum width and height is %1!").arg(10000));
		throw WaylandException();
	}

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

DRMInput::~DRMInput() {

	// tell the thread to stop
	if(m_thread.joinable()) {
		Logger::LogInfo("[DRMInput::~DRMInput] " + QObject::tr("Stopping input thread ..."));
		m_should_stop = true;
		m_thread.join();
	}

	// free everything
	Free();

}

uint32_t DRMInput::GetFrameCounter() {
	return m_frame_counter;
}

void DRMInput::Init() {

	// open Direct Rendering Manager device
	m_drm_fd = drmOpen("/dev/card0", NULL);
	if(m_drm_fd < 0) {
		Logger::LogError("[DRMInput::Init] " + QObject::tr("Error: Can't open Direct Rendering Manager device!"));
		throw DRMInput();
	}

	// get frame buffer
	drm_handle_t frame_buffer_offset;
	drmSize frame_buffer_size;
	drmMapType frame_buffer_type;
	drmMapFlags frame_buffer_flags;
	drm_handle_t frame_buffer_handle;
	int frame_buffer_mtrr;

	// initialize frame counter
	m_frame_counter = 0;

	// start input thread
	m_should_stop = false;
	m_error_occurred = false;
	m_thread = std::thread(&WaylandInput::InputThread, this);

}

void DRMInput::Free() {
	if(m_drm_fd >= 0) {
		drmClose(m_drm_fd);
		m_drm_fd = -1;
	}
}

void DRMInput::InputThread() {
	try {

		Logger::LogInfo("[DRMInput::InputThread] " + QObject::tr("Input thread started."));

		while(!m_should_stop) {

			// sleep
			int64_t next_timestamp = CalculateNextVideoTimestamp();
			int64_t timestamp = hrt_time_micro();
			if(next_timestamp == SINK_TIMESTAMP_NONE) {
				usleep(10000);
				continue;
			} else if(next_timestamp != SINK_TIMESTAMP_ANY) {
				int64_t wait = next_timestamp - timestamp;
				if(wait > 11000) {
					// the thread can't sleep for too long because it still has to check the m_should_stop flag periodically
					usleep(10000);
					continue;
				} else if(wait > 0) {
					usleep(wait);
					timestamp = hrt_time_micro();
				}
			}

			// get the image
			m_screenshot_counter = 0;
			for(auto &p : m_outputs) {
				Output *output = p.second.get();
				int capture_left = std::max(0, (int) m_x - output->m_x);
				int capture_right = std::min((int) output->m_width, (int) (m_x + m_width) - output->m_x);
				int capture_top = std::max(0, (int) m_y - output->m_y);
				int capture_bottom = std::min((int) output->m_height, (int) (m_y + m_height) - output->m_y);
				if(capture_right > capture_left && capture_bottom > capture_top) {
					int out_x = capture_left + output->m_x - (int) m_x;
					int out_y = capture_top + output->m_y - (int) m_y;
					int out_w = capture_right - capture_left;
					int out_h = capture_bottom - capture_top;
					output->m_wl_buffer = wl_shm_pool_create_buffer(m_wl_shm_pool, out_x * 4 + out_y * m_pool_stride, out_w, out_h, m_pool_stride, WL_SHM_FORMAT_XRGB8888);
					screenshooter_shoot(m_screenshooter, output->m_wl_output, output->m_wl_buffer); //TODO// offset!
					++m_screenshot_counter;
					qDebug() << "shoot" << out_x << out_y << out_w << out_h;
				}
			}
			wl_display_dispatch(m_wl_display);
			wl_display_roundtrip(m_wl_display);
			Q_ASSERT(m_screenshot_counter == 0);

			// increase the frame counter
			++m_frame_counter;

			// push the frame
			PushVideoFrame(m_width, m_height, (uint8_t*) m_pool_ptr, m_pool_stride, PIX_FMT_BGRA, timestamp);

		}

		Logger::LogInfo("[DRMInput::InputThread] " + QObject::tr("Input thread stopped."));

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError("[DRMInput::InputThread] " + QObject::tr("Exception '%1' in input thread.").arg(e.what()));
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[DRMInput::InputThread] " + QObject::tr("Unknown exception in input thread."));
	}
}

#endif
