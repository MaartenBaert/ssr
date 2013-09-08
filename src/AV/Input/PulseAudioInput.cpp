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
#include "PulseAudioInput.h"

#include "Logger.h"

// Artificial delay after the first samples have been received (in microseconds). Any samples received during this time will be dropped.
// This is needed because the first samples sometimes have weird timestamps, especially when PulseAudio is active
// (I've seen one situation where PulseAudio instantly 'captures' 2 seconds of silence when the recording is started).
// It also eliminates the clicking sound when the microphone is started for the first time.
const int64_t PulseAudioInput::START_DELAY = 100000;

PulseAudioInput::PulseAudioInput(const QString& source_name, unsigned int sample_rate) {

	m_source_name = source_name;
	m_sample_rate = sample_rate;
	m_channels = 2; // always 2 channels because the synchronizer and encoder don't support anything else at this point

	m_pa_context = NULL;
	m_pa_stream = NULL;
	m_pa_periods = 10;
	m_pa_period_size = 1024; // number of samples per period

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

PulseAudioInput::~PulseAudioInput() {

	// tell the thread to stop
	if(m_thread.joinable()) {
		Logger::LogInfo("[PulseAudioInput::~PulseAudioInput] Telling input thread to stop ...");
		m_should_stop = true;
		m_thread.join();
	}

	// free everything
	Free();

}

void PulseAudioInput::Init() {

	pa_sample_spec sample_spec;
	sample_spec.format = PA_SAMPLE_S16LE;
	sample_spec.rate = m_sample_rate;
	sample_spec.channels = m_channels;

	pa_buffer_attr buffer_attr;
	buffer_attr.fragsize = m_pa_period_size * m_channels * 2;
	buffer_attr.maxlength = m_pa_periods * buffer_attr.fragsize;
	buffer_attr.minreq = (uint32_t) -1;
	buffer_attr.prebuf = (uint32_t) -1;
	buffer_attr.tlength = (uint32_t) -1;

	// create PulseAudio main loop
	m_pa_mainloop = pa_mainloop_new();
	if(m_pa_mainloop == NULL) {
		Logger::LogError("[PulseAudioInput::Init] Error: Could not create main loop!");
		throw PulseAudioException();
	}

	// connect to PulseAudio
	m_pa_context = pa_context_new(pa_mainloop_get_api(m_pa_mainloop), "SimpleScreenRecorder");
	if(m_pa_context == NULL) {
		Logger::LogError("[PulseAudioInput::Init] Error: Could not create context!");
		throw PulseAudioException();
	}
	if(pa_context_connect(m_pa_context, NULL, 0, NULL) < 0) {
		Logger::LogError(QString("[PulseAudioInput::Init] Error: Could not connect! Reason: ") + pa_strerror(pa_context_errno(m_pa_context)));
		throw PulseAudioException();
	}

	// wait until the connection is ready
	for( ; ; ) {
		Iterate();
		pa_context_state_t state = pa_context_get_state(m_pa_context);
		if(state == PA_CONTEXT_READY)
			break;
		if(!PA_CONTEXT_IS_GOOD(state)) {
			Logger::LogError(QString("[PulseAudioInput::Init] Error: Connection attempt failed! Reason: ") + pa_strerror(pa_context_errno(m_pa_context)));
			throw PulseAudioException();
		}
	}

	// create a stream
	m_pa_stream = pa_stream_new(m_pa_context, "SimpleScreenRecorder Audio Input", &sample_spec, NULL);
	if(m_pa_stream == NULL) {
		Logger::LogError(QString("[PulseAudioInput::Init] Error: Could not create stream! Reason: ") + pa_strerror(pa_context_errno(m_pa_context)));
		throw PulseAudioException();
	}

	// connect the stream
	if(pa_stream_connect_record(m_pa_stream, qPrintable(m_source_name), &buffer_attr, PA_STREAM_INTERPOLATE_TIMING | PA_STREAM_AUTO_TIMING_UPDATE | PA_STREAM_ADJUST_LATENCY) < 0) {
		Logger::LogError(QString("[PulseAudioInput::Init] Error: Could not connect stream! Reason: ") + pa_strerror(pa_context_errno(m_pa_context)));
		throw PulseAudioException();
	}

	// wait until the stream is ready
	for( ; ; ) {
		Iterate();
		pa_stream_state_t state = pa_stream_get_state(m_pa_context);
		if(state == PA_STREAM_READY)
			break;
		if(!PA_STREAM_IS_GOOD(state)) {
			Logger::LogError(QString("[PulseAudioInput::Init] Error: Stream connection attempt failed! Reason: ") + pa_strerror(pa_context_errno(m_pa_context)));
			throw PulseAudioException();
		}
	}

	/*int error;
	m_pa_connection = pa_simple_new(NULL, "SimpleScreenRecorder", PA_STREAM_RECORD, qPrintable(m_source_name),
									"SimpleScreenRecorder Audio Input", &sample_spec, NULL, &buffer_attr, &error);
	if(m_pa_connection == NULL) {
		Logger::LogError(QString("[PulseAudioInput::Init] Error: Could not connect to PulseAudio! Error: ") + pa_strerror(error));
		throw PulseAudioException();
	}*/

	// start input thread
	m_should_stop = false;
	m_error_occurred = false;
	m_thread = std::thread(&PulseAudioInput::InputThread, this);

}

void PulseAudioInput::Free() {
	if(m_pa_stream != NULL) {
		pa_stream_unref(m_pa_stream);
		m_pa_stream = NULL;
	}
	if(m_pa_context != NULL) {
		pa_context_disconnect(m_pa_context);
		pa_context_unref(m_pa_context);
		m_pa_context = NULL;
	}
	if(m_pa_mainloop != NULL) {
		pa_mainloop_free(m_pa_mainloop);
		m_pa_mainloop = NULL;
	}
	/*if(m_pa_connection != NULL) {
		pa_simple_free(m_pa_connection);
		m_pa_connection = NULL;
	}*/
}

void PulseAudioInput::Iterate() {
	if(pa_mainloop_prepare(m_pa_mainloop, 1000) < 0) {
		Logger::LogError("[PulseAudioInput::Init] Error: Main loop prepare failed!");
		throw PulseAudioException();
	}
	if(pa_mainloop_poll(m_pa_mainloop) < 0) {
		Logger::LogError("[PulseAudioInput::Init] Error: Main loop poll failed!");
		throw PulseAudioException();
	}
	if(pa_mainloop_dispatch(m_pa_mainloop) < 0) {
		Logger::LogError("[PulseAudioInput::Init] Error: Main loop dispatch failed!");
		throw PulseAudioException();
	}
}

void PulseAudioInput::InputThread() {
	try {

		Logger::LogInfo("[PulseAudioInput::run] Input thread started.");

		std::vector<uint8_t> buffer(m_pa_period_size * m_channels * 2);
		bool has_first_samples = false;
		int64_t first_timestamp = 0; // value won't be used, but GCC gives a warning otherwise

		while(!m_should_stop) {



			// read the samples
			snd_pcm_sframes_t samples_read = snd_pcm_readi(m_alsa_pcm, buffer.data(), m_alsa_period_size);
			if(samples_read < 0) {
				if(samples_read == -EPIPE) {
					ALSARecoverAfterOverrun(m_alsa_pcm);
				} else {
					Logger::LogError("[ALSAInput::run] Error: Can't read samples!");
					throw ALSAException();
				}
				continue;
			}
			if(samples_read <= 0)
				continue;

			int64_t timestamp = hrt_time_micro();

			// skip the first samples
			if(has_first_samples) {
				if(timestamp < first_timestamp + START_DELAY)
					continue;
			} else {
				has_first_samples = true;
				first_timestamp = timestamp;
				continue;
			}

			// send the samples to the synchronizer
			int64_t time = timestamp - (int64_t) m_alsa_period_size * (int64_t) 1000000 / (int64_t) m_sample_rate;
			PushAudioSamples(m_sample_rate, m_channels, samples_read, buffer.data(), AV_SAMPLE_FMT_S16, time);

		}

		Logger::LogInfo("[PulseAudioInput::run] Input thread stopped.");

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError(QString("[PulseAudioInput::run] Exception '") + e.what() + "' in input thread.");
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[PulseAudioInput::run] Unknown exception in input thread.");
	}
}
