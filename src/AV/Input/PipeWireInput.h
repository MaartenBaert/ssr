/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

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

#include "SourceSink.h"
#include "MutexDataPair.h"

#if SSR_USE_PIPEWIRE

#include <pipewire/pipewire.h>
#include <spa/param/video/format-utils.h>
#include <spa/param/props.h>
#include <spa/debug/types.h>

#include <condition_variable>

class PipeWireInput : public VideoSource {

private:
	struct PipeWireBuffer {
		void *m_data;
		size_t m_size;
	};

private:
	uint32_t m_target_node_id; // resolved from either the manual text field or the portal-provided node id
	int m_portal_fd; // >= 0 if connecting through an XDG desktop portal remote, -1 for the default/manual connection
	unsigned int m_width, m_height, m_frame_rate;
	AVPixelFormat m_pixel_format;
	int m_colorspace;
	unsigned int m_buffers;

	std::atomic<uint32_t> m_frame_counter;
	int64_t m_fps_last_timestamp;
	uint32_t m_fps_last_counter;
	double m_fps_current;

	// Guards m_width/m_height/m_pixel_format/m_format_known, which are written
	// from the PipeWire thread (OnParamChange) and read from the GUI thread.
	std::mutex m_format_mutex;
	std::condition_variable m_format_cv;
	bool m_format_known;

	pw_main_loop *m_loop;
	pw_context *m_context;
	pw_core *m_core;
	spa_hook m_core_listener;
	pw_core_events m_core_events;
	pw_stream_events m_stream_events;
	pw_stream *m_stream;
	spa_hook m_stream_listener;
	std::vector<PipeWireBuffer> m_pw_buffers;

	std::thread m_thread;
	std::atomic<bool> m_should_stop, m_error_occurred;

public:
	// Manual/advanced mode: connects to the default PipeWire session and a
	// user-specified numeric node id.
	PipeWireInput(const QString& node_id, unsigned int width, unsigned int height, unsigned int frame_rate);

	// Portal mode: connects to the PipeWire remote opened by the XDG desktop
	// portal (see XdgDesktopPortal). Takes ownership of portal_fd, which will
	// be closed by pw_context_connect_fd() (even on failure).
	PipeWireInput(int portal_fd, uint32_t node_id, unsigned int width, unsigned int height, unsigned int frame_rate);

	~PipeWireInput();

	// Reads the current size of the stream.
	// This function is thread-safe.
	void GetCurrentSize(unsigned int* width, unsigned int* height);

	// Blocks until the PipeWire stream has negotiated a format (so GetCurrentSize
	// returns the actual negotiated size rather than the initially requested
	// size), an error occurs, or the timeout elapses. Returns whether the format
	// is known. This function is thread-safe, but must not be called from the
	// PipeWire thread itself.
	bool WaitUntilFormatKnown(unsigned int timeout_ms);

	// Returns the total number of captured frames.
	// This function is thread-safe.
	double GetFPS();

	// Returns whether an error has occurred in the input thread.
	// This function is thread-safe.
	inline bool HasErrorOccurred() { return m_error_occurred; }

private:
	void Init(const QString& manual_node_id, uint32_t portal_node_id, bool use_portal);
	void Free();

private:
	void AllocateBuffers(unsigned int width, unsigned int height);
	void FreeBuffers();

private:
	void InputThread();
	static void OnProcess(void *userdata);
	static void OnParamChange(void *userdata, uint32_t id, const struct spa_pod *param);
	static void OnStreamStateChanged(void *userdata, enum pw_stream_state old_state, enum pw_stream_state state, const char *error);
	static void OnCoreError(void *userdata, uint32_t id, int seq, int res, const char *message);

};

#endif
