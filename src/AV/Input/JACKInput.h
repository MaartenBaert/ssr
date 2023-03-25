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

#if SSR_USE_JACK

#include "SourceSink.h"
#include "LockFreeMessageQueue.h"

#include <jack/jack.h>

class JACKInput : public AudioSource {

public:
	static const unsigned int RING_BUFFER_SIZE;

private:
	enum enum_eventtype : int {
		EVENTTYPE_HOLE,
		EVENTTYPE_DATA,
	};
	struct EventData {
		int64_t m_timestamp;
		unsigned int m_sample_rate, m_sample_count;
	};
	struct ConnectCommand {
		bool m_connect;
		std::string m_source, m_destination;
	};
	struct SharedData {
		std::vector<ConnectCommand> m_connect_commands;
	};
	typedef MutexDataPair<SharedData>::Lock SharedLock;

private:
	bool m_connect_system_capture, m_connect_system_playback;
	unsigned int m_channels;

	std::atomic<unsigned int> m_jackthread_sample_rate;
	std::atomic<bool> m_jackthread_hole;

	LockFreeMessageQueue m_message_queue;

	jack_client_t *m_jack_client;
	std::vector<jack_port_t*> m_jack_ports;

	std::thread m_thread;
	MutexDataPair<SharedData> m_shared_data;
	std::atomic<bool> m_should_stop, m_error_occurred;

public:
	JACKInput(bool connect_system_capture, bool connect_system_playback);
	~JACKInput();

	// Returns whether an error has occurred in the input thread.
	// This function is thread-safe.
	inline bool HasErrorOccurred() { return m_error_occurred; }

private:
	void Init();
	void Free();

	static int ProcessCallback(jack_nframes_t nframes, void* arg);
	static int SampleRateCallback(jack_nframes_t nframes, void* arg);
	static int XRunCallback(void* arg);
	static void PortConnectCallback(jack_port_id_t a, jack_port_id_t b, int connect, void* arg);

	void InputThread();

};

#endif
