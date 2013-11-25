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
#include "WaylandInput.h"

#if SSR_USE_JACK

#include "Logger.h"

//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

// BEGIN screenshooter interface
static const struct wl_interface *types[] = {
	&wl_output_interface,
	&wl_buffer_interface,
};
static const struct wl_message screenshooter_requests[] = {
	{ "shoot", "oo", types + 0 },
};
static const struct wl_message screenshooter_events[] = {
	{ "done", "", types + 0 },
};
const struct wl_interface screenshooter_interface = {
	"screenshooter", 1,
	1, screenshooter_requests,
	1, screenshooter_events,
};
// END screenshooter interface

WaylandInput::Output::~Output() {
	if(m_wl_buffer != NULL) {
		wl_buffer_destroy(m_wl_buffer);
		m_wl_buffer = NULL;
	}
	if(m_wl_output != NULL) {
		wl_output_destroy(m_wl_output);
		m_wl_output = NULL;
	}
}

WaylandInput::WaylandInput(unsigned int x, unsigned int y, unsigned int width, unsigned int height, bool record_cursor, bool follow_cursor) {

	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_record_cursor = record_cursor;
	m_follow_cursor = follow_cursor;

	m_wl_display = NULL;
	m_wl_registry = NULL;
	m_wl_shm = NULL;
	m_screenshooter = NULL;

	m_pool_fd = -1;
	m_pool_ptr = (void*) -1;
	m_wl_shm_pool = NULL;

	if(m_width < 2 || m_height < 2) {
		Logger::LogError("[WaylandInput::WaylandInput] " + QObject::tr("Error: Width or height is too small, the minimum width and height is %1!").arg(2));
		throw WaylandException();
	}
	if(m_width > 10000 || m_height > 10000) {
		Logger::LogError("[WaylandInput::WaylandInput] " + QObject::tr("Error: Width or height is too large, the maximum width and height is %1!").arg(10000));
		throw WaylandException();
	}

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

WaylandInput::~WaylandInput() {

	// tell the thread to stop
	if(m_thread.joinable()) {
		Logger::LogInfo("[WaylandInput::~WaylandInput] " + QObject::tr("Stopping input thread ..."));
		m_should_stop = true;
		m_thread.join();
	}

	// free everything
	Free();

}

uint32_t WaylandInput::GetFrameCounter() {
	return m_frame_counter;
}

void WaylandInput::Init() {

	// initialize listeners
	m_wl_registry_listener.global = HandleRegistryGlobal;
	m_wl_registry_listener.global_remove = HandleRegistryGlobalRemove;
	m_wl_output_listener.geometry = HandleDisplayGeometry;
	m_wl_output_listener.mode = HandleDisplayMode;
	m_screenshooter_listener.done = HandleScreenshooterDone;

	// connect to wayland display
	m_wl_display = wl_display_connect(NULL);
	if(m_wl_display == NULL) {
		Logger::LogError("[WaylandInput::Init] " + QObject::tr("Error: Could not connect to Wayland server!"));
		throw WaylandException();
	}

	// get the registry
	m_wl_registry = wl_display_get_registry(m_wl_display);
	wl_registry_add_listener(m_wl_registry, &m_wl_registry_listener, this);
	wl_display_dispatch(m_wl_display);

	// wait until all the events have arrived
	wl_display_roundtrip(m_wl_display);

	// do we have a screenshooter?
	if(m_screenshooter == NULL) {
		Logger::LogError("[WaylandInput::Init] " + QObject::tr("Error: The Wayland server does not provide a screenshooter interface!"));
		throw WaylandException();
	}

	// create a shared memory pool
	size_t page_size = sysconf(_SC_PAGE_SIZE);
	m_pool_stride = grow_align16(m_width * 4);
	m_pool_size = (m_pool_stride * m_height + page_size - 1) / page_size * page_size;
	m_pool_fd = open("/dev/zero", O_RDWR);
	if(m_pool_fd == -1) {
		Logger::LogError("[WaylandInput::Init] " + QObject::tr("Error: Could not get file descriptor for shared memory pool!"));
		throw WaylandException();
	}
	m_pool_ptr = mmap(NULL, m_pool_size, PROT_READ | PROT_WRITE, MAP_SHARED, m_pool_fd, 0);
	if(m_pool_ptr == (void*) -1) {
		Logger::LogError("[WaylandInput::Init] " + QObject::tr("Error: Could not get memory for shared memory pool!"));
		throw WaylandException();
	}
	m_wl_shm_pool = wl_shm_create_pool(m_wl_shm, m_pool_fd, m_pool_size);
	if(m_wl_shm_pool == NULL) {
		Logger::LogError("[WaylandInput::Init] " + QObject::tr("Error: Could not create shared memory pool!"));
		throw WaylandException();
	}

	// initialize frame counter
	m_frame_counter = 0;

	// start input thread
	m_should_stop = false;
	m_error_occurred = false;
	m_thread = std::thread(&WaylandInput::InputThread, this);

}

void WaylandInput::Free() {
	m_outputs.clear();
	if(m_wl_shm_pool != NULL) {
		wl_shm_pool_destroy(m_wl_shm_pool);
		m_wl_shm_pool = NULL;
	}
	if(m_pool_ptr != (void*) -1) {
		munmap(m_pool_ptr, m_pool_size);
		m_pool_ptr = (void*) -1;
	}
	if(m_pool_fd != -1) {
		close(m_pool_fd);
		m_pool_fd = -1;
	}
	if(m_screenshooter != NULL) {
		screenshooter_destroy(m_screenshooter);
		m_screenshooter = NULL;
	}
	if(m_wl_shm != NULL) {
		wl_shm_destroy(m_wl_shm);
		m_wl_shm = NULL;
	}
	if(m_wl_registry != NULL) {
		wl_registry_destroy(m_wl_registry);
		m_wl_registry = NULL;
	}
	if(m_wl_display != NULL) {
		wl_display_flush(m_wl_display);
		wl_display_disconnect(m_wl_display);
		m_wl_display = NULL;
	}
}

void WaylandInput::HandleRegistryGlobal(void* data, wl_registry* registry, uint32_t name, const char* interface, uint32_t version) {
	WaylandInput *input = (WaylandInput*) data;
	if(strcmp(interface, "wl_output") == 0) {
		std::unique_ptr<Output> output(new Output());
		output->m_parent = input;
		output->m_wl_output = (wl_output*) wl_registry_bind(registry, name, &wl_output_interface, 1);
		output->m_wl_buffer = NULL;
		output->m_x = 0;
		output->m_y = 0;
		output->m_width = 0;
		output->m_height = 0;
		wl_output_add_listener(output->m_wl_output, &input->m_wl_output_listener, output.get());
		input->m_outputs.insert(std::make_pair(name, std::move(output)));
		qDebug() << "got wl_output" << name;
	} else if(strcmp(interface, "wl_shm") == 0) {
		input->m_wl_shm = (wl_shm*) wl_registry_bind(registry, name, &wl_shm_interface, 1);
		qDebug() << "got wl_shm" << name;
	} else if(strcmp(interface, "screenshooter") == 0) {
		input->m_screenshooter = (screenshooter*) wl_registry_bind(registry, name, &screenshooter_interface, 1);
		screenshooter_add_listener(input->m_screenshooter, &input->m_screenshooter_listener, input);
		qDebug() << "got screenshooter" << name;
	}
}

void WaylandInput::HandleRegistryGlobalRemove(void* data, wl_registry* registry, uint32_t name) {
	WaylandInput *input = (WaylandInput*) data;
	input->m_outputs.erase(name);
	qDebug() << "removed" << name;
}

void WaylandInput::HandleDisplayGeometry(void* data, wl_output* wl_output, int x, int y, int physical_width, int physical_height, int subpixel, const char* make, const char* model, int transform) {
	Output *output = (Output*) data;
	output->m_x = x;
	output->m_y = y;
	if(output->m_wl_buffer != NULL) {
		wl_buffer_destroy(output->m_wl_buffer);
		output->m_wl_buffer = NULL;
	}
	qDebug() << "geometry" << output << output->m_wl_output << wl_output << x << y;
}

void WaylandInput::HandleDisplayMode(void* data, wl_output* wl_output, uint32_t flags, int width, int height, int refresh) {
	Output *output = (Output*) data;
	if(flags & WL_OUTPUT_MODE_CURRENT) {
		output->m_width = width;
		output->m_height = height;
		if(output->m_wl_buffer != NULL) {
			wl_buffer_destroy(output->m_wl_buffer);
			output->m_wl_buffer = NULL;
		}
		qDebug() << "mode" << output << output->m_wl_output << wl_output << width << height;
	}
}

void WaylandInput::HandleScreenshooterDone(void* data, screenshooter* screenshooter) {
	WaylandInput *input = (WaylandInput*) data;
	--input->m_screenshot_counter;
}

void WaylandInput::InputThread() {
	try {

		Logger::LogInfo("[WaylandInput::InputThread] " + QObject::tr("Input thread started."));

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

		Logger::LogInfo("[WaylandInput::InputThread] " + QObject::tr("Input thread stopped."));

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError("[WaylandInput::InputThread] " + QObject::tr("Exception '%1' in input thread.").arg(e.what()));
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[WaylandInput::InputThread] " + QObject::tr("Unknown exception in input thread."));
	}
}

#endif
