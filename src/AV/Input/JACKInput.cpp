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

#include "JACKInput.h"

#if SSR_USE_JACK

#include "SampleCast.h"

#include "Logger.h"

#if SSR_USE_JACK_METADATA
#include <jack/metadata.h>
#endif

// Size of the ring buffer (samples).
const unsigned int JACKInput::RING_BUFFER_SIZE = 1024 * 32;

JACKInput::JACKInput(bool connect_system_capture, bool connect_system_playback) {

	m_connect_system_capture = connect_system_capture;
	m_connect_system_playback = connect_system_playback;
	m_channels = 2; // always 2 channels because the synchronizer and encoder don't support anything else at this point

	m_jackthread_sample_rate = 0; // the sample rate is set by JACK
	m_jackthread_hole = false;

	m_jack_client = NULL;

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

JACKInput::~JACKInput() {

	// tell the thread to stop
	if(m_thread.joinable()) {
		Logger::LogInfo("[JACKInput::~JACKInput] " + Logger::tr("Stopping input thread ..."));
		m_should_stop = true;
		m_thread.join();
	}

	// free everything
	Free();

}

void JACKInput::Init() {

	m_message_queue.Reset(RING_BUFFER_SIZE * m_channels * sizeof(float));

	m_jack_client = jack_client_open("SimpleScreenRecorder", JackNoStartServer, NULL);
	if(m_jack_client == NULL) {
		Logger::LogError("[JACKInput::Init] " + Logger::tr("Error: Could not connect to JACK!"));
		throw JACKException();
	}

	m_jack_ports.resize(m_channels, NULL);
	for(unsigned int i = 0; i < m_channels; ++i) {
		std::string port_name = "in_" + NumToString(i + 1);
		m_jack_ports[i] = jack_port_register(m_jack_client, port_name.c_str(), JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
		if(m_jack_ports[i] == NULL) {
			Logger::LogError("[JACKInput::Init] " + Logger::tr("Error: Could not create JACK port!"));
			throw JACKException();
		}
	}

#if SSR_USE_JACK_METADATA
	if(m_channels == 1) {
		jack_set_property(m_jack_client, jack_port_uuid(m_jack_ports[0]), JACK_METADATA_PRETTY_NAME, "Input Mono", "text/plain");
	}
	if(m_channels == 2) {
		jack_set_property(m_jack_client, jack_port_uuid(m_jack_ports[0]), JACK_METADATA_PRETTY_NAME, "Input Left", "text/plain");
		jack_set_property(m_jack_client, jack_port_uuid(m_jack_ports[1]), JACK_METADATA_PRETTY_NAME, "Input Right", "text/plain");
	}
#endif

	if(jack_set_process_callback(m_jack_client, ProcessCallback, this) != 0) {
		Logger::LogError("[JACKInput::Init] " + Logger::tr("Error: Could not set JACK process callback!"));
		throw JACKException();
	}
	if(jack_set_sample_rate_callback(m_jack_client, SampleRateCallback, this) != 0) {
		Logger::LogError("[JACKInput::Init] " + Logger::tr("Error: Could not set JACK sample rate callback!"));
		throw JACKException();
	}
	if(jack_set_xrun_callback(m_jack_client, XRunCallback, this) != 0) {
		Logger::LogError("[JACKInput::Init] " + Logger::tr("Error: Could not set JACK xrun callback!"));
		throw JACKException();
	}
	if(jack_set_port_connect_callback(m_jack_client, PortConnectCallback, this) != 0) {
		Logger::LogError("[JACKInput::Init] " + Logger::tr("Error: Could not set JACK port connect callback!"));
		throw JACKException();
	}

	if(jack_activate(m_jack_client) != 0) {
		Logger::LogError("[JACKInput::Init] " + Logger::tr("Error: Could not activate JACK client!"));
		throw JACKException();
	}

	for(unsigned int i = 0; i < m_channels; ++i) {
		std::string port_name_full = std::string(jack_get_client_name(m_jack_client)) + ":in_" + NumToString(i + 1);
		if(m_connect_system_capture) {
			std::string capture_name = "system:capture_" + NumToString(i + 1);
			Logger::LogInfo("[JACKInput::Init] " + Logger::tr("Connecting port %1 to %2.")
							.arg(QString::fromStdString(capture_name)).arg(QString::fromStdString(port_name_full)));
			jack_connect(m_jack_client, capture_name.c_str(), port_name_full.c_str());
		}
		if(m_connect_system_playback) {
			std::string playback_name = "system:playback_" + NumToString(i + 1);
			jack_port_t *port = jack_port_by_name(m_jack_client, playback_name.c_str());
			if(port != NULL) {
				const char **connected_ports = jack_port_get_all_connections(m_jack_client, port);
				if(connected_ports != NULL) {
					for(const char **p = connected_ports; *p != NULL; ++p) {
						Logger::LogInfo("[JACKInput::Init] " + Logger::tr("Connecting port %1 to %2.")
										.arg(*p).arg(QString::fromStdString(port_name_full)));
						jack_connect(m_jack_client, *p, port_name_full.c_str());
					}
					jack_free(connected_ports);
				}
			}
		}

	}

	// start input thread
	m_should_stop = false;
	m_error_occurred = false;
	m_thread = std::thread(&JACKInput::InputThread, this);

}

void JACKInput::Free() {
	if(m_jack_client != NULL) {
		jack_deactivate(m_jack_client);
	}
	for(unsigned int i = 0; i < m_jack_ports.size(); ++i) {
		if(m_jack_ports[i] != NULL) {
			jack_port_unregister(m_jack_client, m_jack_ports[i]);
			m_jack_ports[i] = NULL;
		}
	}
	if(m_jack_client != NULL) {
		jack_client_close(m_jack_client);
		m_jack_client = NULL;
	}
}

int JACKInput::ProcessCallback(jack_nframes_t nframes, void* arg) {
	JACKInput *input = (JACKInput*) arg;

	// deal with holes
	if(input->m_jackthread_hole) {
		char *message = input->m_message_queue.PrepareWriteMessage(sizeof(enum_eventtype));
		if(message == NULL)
			return 0;
		*((enum_eventtype*) message) = EVENTTYPE_HOLE;
		input->m_message_queue.WriteMessage();
		input->m_jackthread_hole = false;
	}

	// This function is called from a real-time thread, so it's not a good idea to do actual work here.
	// The data is moved to a queue, and a second thread will do the work as usual.
	//TODO// if nframes is small, then combine multiple blocks into one?
	char *message = input->m_message_queue.PrepareWriteMessage(sizeof(enum_eventtype) + sizeof(EventData) + nframes * input->m_channels * sizeof(float));
	if(message == NULL) {
		input->m_jackthread_hole = true;
		return 0;
	}
	*((enum_eventtype*) message) = EVENTTYPE_DATA;
	message += sizeof(enum_eventtype);
	((EventData*) message)->m_timestamp = hrt_time_micro() - (int64_t) nframes * (int64_t) 1000000 / (int64_t) input->m_jackthread_sample_rate;
	((EventData*) message)->m_sample_rate = input->m_jackthread_sample_rate;
	((EventData*) message)->m_sample_count = nframes;
	message += sizeof(EventData);
	for(unsigned int p = 0; p < input->m_channels; ++p) {
		SampleCopy(nframes, (float*) jack_port_get_buffer(input->m_jack_ports[p], nframes), 1, (float*) message + p, input->m_channels);
	}
	input->m_message_queue.WriteMessage();

	return 0;
}

int JACKInput::SampleRateCallback(jack_nframes_t nframes, void* arg) {
	// This callback is called from the notification thread (not the realtime processing thread), so sadly the timing can never be fully accurate.
	JACKInput *input = (JACKInput*) arg;
	input->m_jackthread_sample_rate = nframes;
	input->m_jackthread_hole = true;
	return 0;
}

int JACKInput::XRunCallback(void* arg) {
	// This callback is called from the notification thread (not the realtime processing thread), so sadly the timing can never be fully accurate.
	JACKInput *input = (JACKInput*) arg;
	input->m_jackthread_hole = true;
	return 0;
}

void JACKInput::PortConnectCallback(jack_port_id_t a, jack_port_id_t b, int connect, void* arg) {
	// This callback is called from the notification thread (not the realtime processing thread), so sadly the timing can never be fully accurate.
	// To make things worse, we're not allowed to connect/disconnect ports from this thread, so we have to send a command to the input thread instead.
	JACKInput *input = (JACKInput*) arg;
	if(input->m_connect_system_playback) {
		jack_port_t *port_a = jack_port_by_id(input->m_jack_client, a);
		if(port_a == NULL)
			return;
		jack_port_t *port_b = jack_port_by_id(input->m_jack_client, b);
		if(port_b == NULL)
			return;
		const char *port_a_name = jack_port_name(port_a);
		const char *port_b_name = jack_port_name(port_b);
		for(unsigned int i = 0; i < input->m_channels; ++i) {
			std::string playback_name = "system:playback_" + NumToString(i + 1);
			if(port_b_name == playback_name) {
				std::string port_name_full = std::string(jack_get_client_name(input->m_jack_client)) + ":in_" + NumToString(i + 1);
				SharedLock lock(&input->m_shared_data);
				ConnectCommand cmd;
				cmd.m_connect = connect;
				cmd.m_source = port_a_name;
				cmd.m_destination = port_name_full;
				lock->m_connect_commands.push_back(cmd);
			}
		}
	}
}

void JACKInput::InputThread() {
	try {

		Logger::LogInfo("[JACKInput::InputThread] " + Logger::tr("Input thread started."));

		while(!m_should_stop) {

			// process connect commands
			// JACK will send notifications when we connect/disconnect ports, so holding the lock while doing this is a bad idea.
			// It seems that JACK is designed in such a way that a single misbehaving application can lock up the entire server, so let's avoid that.
			std::vector<ConnectCommand> connect_commands;
			{
				SharedLock lock(&m_shared_data);
				connect_commands.swap(lock->m_connect_commands);
			}
			for(ConnectCommand &cmd : connect_commands) {
				if(cmd.m_connect) {
					Logger::LogInfo("[JACKInput::InputThread] " + Logger::tr("Connecting port %1 to %2.")
									.arg(QString::fromStdString(cmd.m_source)).arg(QString::fromStdString(cmd.m_destination)));
					jack_connect(m_jack_client, cmd.m_source.c_str(), cmd.m_destination.c_str());
				} else {
					Logger::LogInfo("[JACKInput::InputThread] " + Logger::tr("Disconnecting port %1 from %2.")
									.arg(QString::fromStdString(cmd.m_source)).arg(QString::fromStdString(cmd.m_destination)));
					jack_disconnect(m_jack_client, cmd.m_source.c_str(), cmd.m_destination.c_str());
				}
			}

			// is there a new message?
			unsigned int message_size;
			char *message = m_message_queue.PrepareReadMessage(&message_size);
			if(message == NULL) {
				usleep(20000);
				continue;
			}

			// read the message
			assert(message_size >= sizeof(enum_eventtype));
			enum_eventtype type = *((enum_eventtype*) message);
			message += sizeof(enum_eventtype);
			if(type == EVENTTYPE_HOLE) {
				PushAudioHole();
			}
			if(type == EVENTTYPE_DATA) {
				assert(message_size >= sizeof(enum_eventtype) + sizeof(EventData));
				assert(message_size >= sizeof(enum_eventtype) + sizeof(EventData) + ((EventData*) message)->m_sample_count * m_channels * sizeof(float));
				PushAudioSamples(m_channels, ((EventData*) message)->m_sample_rate, AV_SAMPLE_FMT_FLT, ((EventData*) message)->m_sample_count,
								 (uint8_t*) (message + sizeof(EventData)), ((EventData*) message)->m_timestamp);
			}

			// go to next message
			m_message_queue.ReadMessage();

		}

		Logger::LogInfo("[JACKInput::InputThread] " + Logger::tr("Input thread stopped."));

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError("[JACKInput::InputThread] " + Logger::tr("Exception '%1' in input thread.").arg(e.what()));
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[JACKInput::InputThread] " + Logger::tr("Unknown exception in input thread."));
	}
}

#endif
