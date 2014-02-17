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

#include "Global.h"
#include "JACKInput.h"

#if SSR_USE_JACK

#include "SampleCast.h"

#include "Logger.h"

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
		Logger::LogInfo("[JACKInput::~JACKInput] Telling input thread to stop ...");
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
		Logger::LogError("[JACKInput::Init] Error: Could not connect to JACK!");
		throw JACKException();
	}

	m_jack_ports.resize(m_channels, NULL);
	for(unsigned int i = 0; i < m_channels; ++i) {
		QString name = "in_" + QString::number(i + 1);
		m_jack_ports[i] = jack_port_register(m_jack_client, name.toAscii().constData(), JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
		if(m_jack_ports[i] == NULL) {
			Logger::LogError("[JACKInput::Init] Error: Could not create JACK port!");
			throw JACKException();
		}
	}

	if(jack_set_process_callback(m_jack_client, ProcessCallback, this) != 0) {
		Logger::LogError("[JACKInput::Init] Error: Could not set JACK process callback!");
		throw JACKException();
	}
	if(jack_set_sample_rate_callback(m_jack_client, SampleRateCallback, this) != 0) {
		Logger::LogError("[JACKInput::Init] Error: Could not set JACK sample rate callback!");
		throw JACKException();
	}
	if(jack_set_xrun_callback(m_jack_client, XRunCallback, this) != 0) {
		Logger::LogError("[JACKInput::Init] Error: Could not set JACK xrun callback!");
		throw JACKException();
	}

	if(jack_activate(m_jack_client) != 0) {
		Logger::LogError("[JACKInput::Init] Error: Could not activate JACK client!");
		throw JACKException();
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
	char *message = input->m_message_queue.PrepareWriteMessage(sizeof(enum_eventtype) + sizeof(Event_Data) + nframes * input->m_channels * sizeof(float));
	if(message == NULL) {
		input->m_jackthread_hole = true;
		return 0;
	}
	*((enum_eventtype*) message) = EVENTTYPE_DATA;
	message += sizeof(enum_eventtype);
	((Event_Data*) message)->m_timestamp = hrt_time_micro() - (int64_t) nframes * (int64_t) 1000000 / (int64_t) input->m_jackthread_sample_rate;
	((Event_Data*) message)->m_sample_rate = input->m_jackthread_sample_rate;
	((Event_Data*) message)->m_sample_count = nframes;
	message += sizeof(Event_Data);
	for(unsigned int p = 0; p < input->m_channels; ++p) {
		SampleCopy(nframes, (float*) jack_port_get_buffer(input->m_jack_ports[p], nframes), 1, (float*) message + p, input->m_channels);
	}
	input->m_message_queue.WriteMessage();

	return 0;
}

int JACKInput::SampleRateCallback(jack_nframes_t nframes, void* arg) {
	JACKInput *input = (JACKInput*) arg;
	input->m_jackthread_sample_rate = nframes;
	input->m_jackthread_hole = true;
	return 0;
}

int JACKInput::XRunCallback(void* arg) {
	JACKInput *input = (JACKInput*) arg;
	input->m_jackthread_hole = true;
	return 0;
}

void JACKInput::InputThread() {
	try {

		Logger::LogInfo("[JACKInput::InputThread] Input thread started.");

		while(!m_should_stop) {

			unsigned int message_size;
			char *message = m_message_queue.PrepareReadMessage(&message_size);
			if(message == NULL) {
				usleep(10000);
				continue;
			}

			assert(message_size >= sizeof(enum_eventtype));
			enum_eventtype type = *((enum_eventtype*) message);
			message += sizeof(enum_eventtype);
			if(type == EVENTTYPE_HOLE) {
				PushAudioHole();
			}
			if(type == EVENTTYPE_DATA) {
				assert(message_size >= sizeof(enum_eventtype) + sizeof(Event_Data));
				assert(message_size >= sizeof(enum_eventtype) + sizeof(Event_Data) + ((Event_Data*) message)->m_sample_count * m_channels * sizeof(float));
				PushAudioSamples(m_channels, ((Event_Data*) message)->m_sample_rate, AV_SAMPLE_FMT_FLT, ((Event_Data*) message)->m_sample_count,
								 (uint8_t*) (message + sizeof(Event_Data)), ((Event_Data*) message)->m_timestamp);
			}

			m_message_queue.ReadMessage();

		}

		Logger::LogInfo("[JACKInput::InputThread] Input thread stopped.");

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError(QString("[JACKInput::InputThread] Exception '") + e.what() + "' in input thread.");
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[JACKInput::InputThread] Unknown exception in input thread.");
	}
}

#endif
