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

#if SSR_USE_V4L2

#include <libv4l2.h>
#include <linux/videodev2.h>

class V4L2Input : public VideoSource {

private:
	struct V4L2Buffer {
		void *m_data;
		size_t m_size;
	};

private:
	QString m_device;
	unsigned int m_width, m_height;
	int m_colorspace;
	unsigned int m_buffers;

	std::atomic<uint32_t> m_frame_counter;
	int64_t m_fps_last_timestamp;
	uint32_t m_fps_last_counter;
	double m_fps_current;

	int m_v4l2_device;
	std::vector<V4L2Buffer> m_v4l2_buffers;
	unsigned int m_v4l2_bytes_per_line;

	std::thread m_thread;
	std::atomic<bool> m_should_stop, m_error_occurred;

public:
	V4L2Input(const QString& device, unsigned int width, unsigned int height);
	~V4L2Input();

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
	void AllocateImage(unsigned int width, unsigned int height);
	void FreeImage();
	void UpdateScreenConfiguration();

private:
	void InputThread();

};

#endif
