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

#if SSR_USE_ALSA

#include "MutexDataPair.h"

#include <alsa/asoundlib.h>

class SimpleSynth {

public:
	struct Note {
		unsigned int m_time, m_duration_in, m_duration_out;
		float m_frequency, m_amplitude;
	};

private:
	struct SharedData {
		std::vector<Note> m_notes;
		unsigned int m_current_time;
	};
	typedef MutexDataPair<SharedData>::Lock SharedLock;

private:
	QString m_sink_name;
	unsigned int m_sample_rate;

	snd_pcm_t *m_alsa_pcm;
	unsigned int m_period_size, m_buffer_size;

	std::thread m_thread;
	MutexDataPair<SharedData> m_shared_data;
	std::atomic<bool> m_should_stop, m_error_occurred;

public:
	SimpleSynth(const QString& sink_name, unsigned int sample_rate);
	~SimpleSynth();

	// This function is thread-safe.
	void PlaySequence(const Note* notes, unsigned int note_count);

private:
	void Init();
	void Free();

	void SynthThread();

};

#endif
