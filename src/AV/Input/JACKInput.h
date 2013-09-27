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

#include <jack/jack.h>

class JACKInput : public AudioSource {

public:
	static const unsigned int RING_BUFFER_SIZE;

private:
	struct Command {
		bool m_is_hole;
		int64_t m_timestamp;
		unsigned int m_sample_rate;
		std::vector<uint8_t> m_data;
		Command() = default;
		Command(Command&&) = default;
		Command& operator=(Command&&) = default;
	};
	struct SharedData {
		std::deque<Command> m_commands;
	};

private:
	unsigned int m_sample_rate, m_channels;

	jack_client_t *m_jack_client;
	std::vector<jack_port_t*> m_jack_ports;

	std::thread m_thread;
	MutexDataPair<SharedData> m_shared_data;
	std::atomic<bool> m_should_stop, m_error_occurred;

	std::vector<Command> m_command_ring;
	unsigned int m_command_ring_read_pos, m_command_ring_write_pos;

public:
	JACKInput(unsigned int sample_rate);
	~JACKInput();

	// Returns whether an error has occurred in the input thread.
	// This function is thread-safe.
	inline bool HasErrorOccurred() { return m_error_occurred; }

private:
	void Init();
	void Free();

	void WriteCommand(bool is_hole, jack_nframes_t nframes = 0);

	static int ProcessCallback(jack_nframes_t nframes, void* arg);
	static int SampleRateCallback(jack_nframes_t nframes, void* arg);
	static int XRunCallback(void* arg);

	void InputThread();

};
