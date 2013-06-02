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

#include "VPair.h"
#include "YUVConverter.h"

class Synchronizer;
class GLInjectLauncher;
class VideoPreviewer;

class GLInjectInput : private QThread {

private:
	struct SharedData {
		VideoPreviewer *m_video_previewer;
	};
	typedef VPair<SharedData>::Lock SharedLock;

private:
	static const int64_t MAX_FRAME_DELAY, MAX_COMMUNICATION_LATENCY;

private:
	Synchronizer *m_synchronizer;
	GLInjectLauncher *m_launcher;

	unsigned int m_cbuffer_size, m_max_bytes;
	unsigned int m_frame_rate, m_out_width, m_out_height;
	bool m_insert_duplicates;

	volatile char *m_shm_main_ptr;
	std::vector<volatile char*> m_shm_frame_ptrs;

	bool m_warn_swscale;
	YUVConverter m_yuv_converter;
	SwsContext *m_sws_context;

	VPair<SharedData> m_shared_data;
	volatile bool m_should_stop, m_error_occurred;

public:
	GLInjectInput(Synchronizer* synchronizer, GLInjectLauncher* launcher, bool insert_duplicates);
	~GLInjectInput();

	// Connect the video previewer.
	// video_previewer can be NULL.
	void ConnectVideoPreviewer(VideoPreviewer* video_previewer);

	// Returns whether an error has occurred in the input thread.
	// This function is thread-safe.
	inline bool HasErrorOccurred() { return m_error_occurred; }

private:
	void Init();
	void Free();

private:
	virtual void run();

};
