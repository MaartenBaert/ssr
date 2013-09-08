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

#include <pulse/mainloop.h>
#include <pulse/context.h>
#include <pulse/stream.h>
#include <pulse/error.h>

class PulseAudioInput : public AudioSource {

private:
	static const int64_t START_DELAY;

private:
	QString m_source_name;
	unsigned int m_sample_rate, m_channels;

	//pa_simple *m_pa_connection;
	pa_mainloop *m_pa_mainloop;
	pa_context *m_pa_context;
	pa_stream *m_pa_stream;
	unsigned int m_pa_periods, m_pa_period_size;

	std::thread m_thread;
	std::atomic<bool> m_should_stop, m_error_occurred;

public:
	PulseAudioInput(const QString& source_name, unsigned int sample_rate);
	~PulseAudioInput();

	// Returns whether an error has occurred in the input thread.
	// This function is thread-safe.
	inline bool HasErrorOccurred() { return m_error_occurred; }

private:
	void Init();
	void Free();

	void Iterate();
	void InputThread();

};
