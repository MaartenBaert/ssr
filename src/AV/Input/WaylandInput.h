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

#pragma once
#include "Global.h"

#if SSR_USE_JACK

#include "SourceSink.h"

#include <wayland-client.h>
#include "screenshooter-client-protocol.h" // Warning: This protocol is specific to Weston and not stable yet!

class WaylandInput : public VideoSource {

private:
	struct Output {
		WaylandInput *m_parent;
		wl_output *m_wl_output;
		wl_buffer *m_wl_buffer;
		int m_x, m_y, m_width, m_height;
		~Output();
	};

private:
	unsigned int m_x, m_y, m_width, m_height;
	bool m_record_cursor, m_follow_cursor;

	wl_display *m_wl_display;
	wl_registry *m_wl_registry;
	std::map<uint32_t, std::unique_ptr<Output> > m_outputs;
	wl_shm *m_wl_shm;
	screenshooter *m_screenshooter;
	unsigned int m_screenshot_counter;

	size_t m_pool_stride, m_pool_size;
	int m_pool_fd;
	void *m_pool_ptr;
	wl_shm_pool *m_wl_shm_pool;

	wl_registry_listener m_wl_registry_listener;
	wl_output_listener m_wl_output_listener;
	//wl_shm_listener m_wl_shm_listener;
	screenshooter_listener m_screenshooter_listener;

	std::thread m_thread;
	std::atomic<bool> m_should_stop, m_error_occurred;
	std::atomic<uint32_t> m_frame_counter;

public:
	WaylandInput(unsigned int x, unsigned int y, unsigned int width, unsigned int height, bool record_cursor, bool follow_cursor);
	~WaylandInput();

	// Returns the total number of captured frames.
	// This function is thread-safe.
	uint32_t GetFrameCounter();

	// Returns whether an error has occurred in the input thread.
	// This function is thread-safe.
	inline bool HasErrorOccurred() { return m_error_occurred; }

private:
	void Init();
	void Free();

	static void HandleRegistryGlobal(void* data, wl_registry* registry, uint32_t name, const char* interface, uint32_t version);
	static void HandleRegistryGlobalRemove(void* data, wl_registry* registry, uint32_t name);

	static void HandleDisplayGeometry(void* data, wl_output* wl_output, int x, int y, int physical_width, int physical_height, int subpixel, const char* make, const char* model, int transform);
	static void HandleDisplayMode(void* data, wl_output* wl_output, uint32_t flags, int width, int height, int refresh);

	static void HandleScreenshooterDone(void* data, screenshooter* screenshooter);

private:
	void InputThread();

};

#endif
