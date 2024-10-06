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
#include <libavutil/pixfmt.h>

#if SSR_USE_PIPEWIRE

#include <pipewire/pipewire.h>
#include <spa/param/video/format-utils.h>
#include <spa/param/props.h>
#include <spa/debug/types.h>

class PipeWireInput : public VideoSource {

private:
	struct PipeWireBuffer {
		void *m_data;
		size_t m_size;
	};

private:
	QString m_node_id;
	unsigned int m_width, m_height, m_frame_rate;
	AVPixelFormat m_pixel_format;
	int m_colorspace;
	unsigned int m_buffers;

	std::atomic<uint32_t> m_frame_counter;
	int64_t m_fps_last_timestamp;
	uint32_t m_fps_last_counter;
	double m_fps_current;

	pw_main_loop *m_loop;
	pw_stream_events m_stream_events;
	pw_stream *m_stream;
	spa_hook m_stream_listener;
	std::vector<PipeWireBuffer> m_pw_buffers;

	std::thread m_thread;
	std::atomic<bool> m_should_stop, m_error_occurred;

public:
	PipeWireInput(const QString& node_id, unsigned int width, unsigned int height, unsigned int frame_rate);
	~PipeWireInput();

	// Reads the current size of the stream.
	// This function is thread-safe.
	void GetCurrentSize(unsigned int* width, unsigned int* height);

	// Returns the total number of captured frames.
	// This function is thread-safe.
	double GetFPS();

	// Returns whether an error has occurred in the input thread.
	// This function is thread-safe.
	inline bool HasErrorOccurred() { return m_error_occurred; }

private:
	void Init();
	void Free();

private:
	void AllocateBuffers(unsigned int width, unsigned int height);
	void FreeBuffers();

private:
	void InputThread();
	static void OnProcess(void *userdata);
	static void OnParamChange(void *userdata, uint32_t id, const struct spa_pod *param);

};

#endif
