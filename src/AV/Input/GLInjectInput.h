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

#include "SourceSink.h"
#include "MutexDataPair.h"

class SSRVideoStreamReader;

class GLInjectInput : public VideoSource {

private:
	static const int64_t MAX_COMMUNICATION_LATENCY;

private:
	QString m_pid, m_source, m_program_name;
	unsigned int m_flags;
	unsigned int m_target_fps;

	SSRVideoStreamReader *m_stream_reader;

	std::thread m_thread;
	std::atomic<bool> m_should_stop, m_error_occurred;

public:
	GLInjectInput(const QString& pid, const QString& source, const QString& program_name, bool record_cursor, bool limit_fps, unsigned int target_fps);
	~GLInjectInput();

	// Reads the current size of the stream. If the stream hasn't been started yet, this will be 0x0.
	void GetCurrentSize(unsigned int* width, unsigned int* height);

	// Returns the total number of captured frames.
	// This function is thread-safe.
	double GetFPS();

	// Start capturing.
	void Start();

	// Stop capturing.
	void Stop();

	// Returns whether an error has occurred in the input thread.
	// This function is thread-safe.
	inline bool HasErrorOccurred() { return m_error_occurred; }

private:
	void Init();
	void Free();

private:
	void InputThread();

};
