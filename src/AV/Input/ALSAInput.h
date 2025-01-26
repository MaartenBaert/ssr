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

#include "SourceSink.h"
#include "MutexDataPair.h"

#include <alsa/asoundlib.h>

class ALSAInput : public AudioSource {

public:
	struct Source {
		std::string m_name, m_description;
		inline Source(const std::string& name, const std::string& description) : m_name(name), m_description(description) {}
	};

private:
	static const int64_t START_DELAY;

private:
	QString m_source_name;
	AVSampleFormat m_sample_format;
	bool m_convert_24_to_32;
	unsigned int m_sample_rate, m_channels;
	unsigned int m_period_size, m_buffer_size;

	snd_pcm_t *m_alsa_pcm;

	std::thread m_thread;
	std::atomic<bool> m_should_stop, m_error_occurred;

public:
	ALSAInput(const QString& source_name, unsigned int sample_rate);
	~ALSAInput();

	// Returns whether an error has occurred in the input thread.
	// This function is thread-safe.
	inline bool HasErrorOccurred() { return m_error_occurred; }

public:
	static std::vector<Source> GetSourceList();

private:
	void Init();
	void Free();

	void InputThread();

};

#endif
