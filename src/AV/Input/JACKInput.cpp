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

#include "Logger.h"

const unsigned int JACKInput::RING_BUFFER_SIZE = 50;

JACKInput::JACKInput(unsigned int sample_rate) {

	m_sample_rate = sample_rate;
	m_channels = 2; // always 2 channels because the synchronizer and encoder don't support anything else at this point

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

	m_command_ring.resize(RING_BUFFER_SIZE);
	m_command_ring_read_pos = 0;
	m_command_ring_write_pos = 0;
	std::atomic_thread_fence(std::memory_order_release);

	m_jack_client = jack_client_open("SimpleScreenRecorder", JackNullOption, NULL);
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

void JACKInput::WriteCommand(bool is_hole, jack_nframes_t nframes) {
	std::atomic_thread_fence(std::memory_order_acquire);
	unsigned int commands_ready = positive_mod((int) m_command_ring_write_pos - (int) m_command_ring_read_pos, (int) RING_BUFFER_SIZE * 2);
	if(commands_ready >= RING_BUFFER_SIZE)
		return;
	Command &cmd = m_command_ring[m_command_ring_write_pos % RING_BUFFER_SIZE];
	if(is_hole || commands_ready == RING_BUFFER_SIZE - 1) {
		cmd.m_is_hole = true;
	} else {
		cmd.m_is_hole = false;
		cmd.m_timestamp = hrt_time_micro() - (int64_t) nframes * (int64_t) 1000000 / (int64_t) m_sample_rate;
		cmd.m_sample_rate = m_sample_rate;
		cmd.m_data.resize(nframes * m_channels * 2);
		for(unsigned int p = 0; p < m_channels; ++p) {
			float *data_in = (float*) jack_port_get_buffer(m_jack_ports[p], nframes);
			int16_t *data_out = (int16_t*) cmd.m_data.data() + p;
			for(jack_nframes_t i = 0; i < nframes; ++i) {
				*data_out = clamp((int) lrint(*(data_in++) * 32768.0f), -32768, 32767);
				data_out += m_channels;
			}
		}
	}
	std::atomic_thread_fence(std::memory_order_acq_rel);
	m_command_ring_write_pos = (m_command_ring_write_pos + 1) % (RING_BUFFER_SIZE * 2);
	std::atomic_thread_fence(std::memory_order_release);
}

int JACKInput::ProcessCallback(jack_nframes_t nframes, void* arg) {
	JACKInput *input = (JACKInput*) arg;
	// This function is called from a real-time thread, so it's not a good idea to do actual work here.
	// The data is moved to a queue, and if the frame size hasn't changed, this is done without locking or allocating new memory.
	// Otherwise it does allocate memory, but that should rarely happen.
	input->WriteCommand(false, nframes);
	return 0;
}

int JACKInput::SampleRateCallback(jack_nframes_t nframes, void* arg) {
	JACKInput *input = (JACKInput*) arg;
	input->m_sample_rate = nframes;
	input->WriteCommand(true);
	return 0;
}

int JACKInput::XRunCallback(void* arg) {
	JACKInput *input = (JACKInput*) arg;
	input->WriteCommand(true);
	return 0;
}

void JACKInput::InputThread() {
	try {

		Logger::LogInfo("[JACKInput::InputThread] Input thread started.");

		while(!m_should_stop) {

			std::atomic_thread_fence(std::memory_order_acquire);
			unsigned int commands_ready = positive_mod((int) m_command_ring_write_pos - (int) m_command_ring_read_pos, (int) RING_BUFFER_SIZE * 2);
			if(commands_ready == 0) {
				usleep(10000);
				continue;
			}
			Command &cmd = m_command_ring[m_command_ring_read_pos % RING_BUFFER_SIZE];
			if(cmd.m_is_hole) {
				PushAudioHole();
			} else {
				PushAudioSamples(cmd.m_sample_rate, m_channels, cmd.m_data.size() / (m_channels * 2), cmd.m_data.data(), AV_SAMPLE_FMT_S16, cmd.m_timestamp);
			}
			std::atomic_thread_fence(std::memory_order_acq_rel);
			m_command_ring_read_pos = (m_command_ring_read_pos + 1) % (RING_BUFFER_SIZE * 2);
			std::atomic_thread_fence(std::memory_order_release);

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
