/*
Copyright (c) 2012 Maarten Baert <maarten-baert@hotmail.com>

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

#include "StdAfx.h"
#include "ALSAInput.h"

#include "Logger.h"
#include "Synchronizer.h"
#include "AudioEncoder.h"

ALSAInput::ALSAInput(Synchronizer* synchronizer, const QString& device_name) {
	Q_ASSERT(synchronizer->GetAudioEncoder() != NULL);

	m_synchronizer = synchronizer;

	m_device_name = device_name;
	m_sample_rate = m_synchronizer->GetAudioEncoder()->GetSampleRate();
	m_channels = 2; // always 2 channels because the synchronizer and encoder don't support anything else at this point

	m_alsa_pcm = NULL;
	m_alsa_hw_params = NULL;
	m_alsa_periods = 8;
	m_alsa_period_size = 1024; // number of samples per period

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

ALSAInput::~ALSAInput() {

	// tell the thread to stop
	if(isRunning()) {
		Logger::LogInfo("[ALSAInput::~ALSAInput] Telling input thread to stop ...");
		m_should_stop = true;
		wait();
	}

	// free everything
	Free();

}

void ALSAInput::Init() {

	// allocate hardware parameter structure
	snd_pcm_hw_params_malloc(&m_alsa_hw_params);
	if(m_alsa_hw_params == NULL)
		throw std::bad_alloc();

	// open alsa device
	if(snd_pcm_open(&m_alsa_pcm, qPrintable(m_device_name), SND_PCM_STREAM_CAPTURE, 0) < 0) {
		Logger::LogError("[ALSAInput::Init] Error: Can't open PCM device!");
		throw ALSAException();
	}
	if(snd_pcm_hw_params_any(m_alsa_pcm, m_alsa_hw_params) < 0) {
		Logger::LogError("[ALSAInput::Init] Error: Can't get PCM hardware parameters!");
		throw ALSAException();
	}

	// set sample format
	if(snd_pcm_hw_params_set_format(m_alsa_pcm, m_alsa_hw_params, SND_PCM_FORMAT_S16_LE) < 0) {
		Logger::LogError("[ALSAInput::Init] Error: Can't set sample format!");
		throw ALSAException();
	}

	// set sample rate
	unsigned int rate = m_sample_rate;
	if(snd_pcm_hw_params_set_rate_near(m_alsa_pcm, m_alsa_hw_params, &rate, NULL) < 0) {
		Logger::LogError("[ALSAInput::Init] Error: Can't set sample rate!");
		throw ALSAException();
	}
	if(rate != m_sample_rate) {
		Logger::LogWarning("[ALSAInput::Init] Warning: Sample rate " + QString::number(m_sample_rate) + " is not supported, using " + QString::number(rate) + " instead. This could be a problem if the difference is large.");
	}

	// set channels
	if(snd_pcm_hw_params_set_channels(m_alsa_pcm, m_alsa_hw_params, m_channels) < 0) {
		Logger::LogError("[ALSAInput::Init] Error: Can't set channels!");
		throw ALSAException();
	}

	// set periods
	unsigned int periods = m_alsa_periods;
	if(snd_pcm_hw_params_set_periods_near(m_alsa_pcm, m_alsa_hw_params, &periods, NULL) < 0) {
		Logger::LogError("[ALSAInput::Init] Error: Can't set periods!");
		throw ALSAException();
	}
	if(periods != m_alsa_periods) {
		Logger::LogWarning("[ALSAInput::Init] Warning: Period count " + QString::number(m_alsa_periods) + " is not supported, using " + QString::number(periods) + " instead. This is not a problem.");
	}

	// set period size
	snd_pcm_uframes_t period_size = m_alsa_period_size;
	if(snd_pcm_hw_params_set_period_size_near(m_alsa_pcm, m_alsa_hw_params, &period_size, NULL) < 0) {
		Logger::LogError("[ALSAInput::Init] Error: Can't set period size!");
		throw ALSAException();
	}
	if(period_size != m_alsa_period_size) {
		Logger::LogWarning("[ALSAInput::Init] Warning: Period size " + QString::number(m_alsa_period_size) + " is not supported, using " + QString::number(period_size) + " instead. This is not a problem.");
	}

	// apply parameters
	if(snd_pcm_hw_params(m_alsa_pcm, m_alsa_hw_params) < 0) {
		Logger::LogError("[ALSAInput::Init] Error: Can't apply PCM hardware parameters!");
		throw ALSAException();
	}

	// start input thread
	m_should_stop = false;
	m_error_occurred = false;
	start();

}

void ALSAInput::Free() {
	if(m_alsa_pcm != NULL) {
		snd_pcm_close(m_alsa_pcm);
		m_alsa_pcm = NULL;
	}
	if(m_alsa_hw_params != NULL) {
		snd_pcm_hw_params_free(m_alsa_hw_params);
		m_alsa_hw_params = NULL;
	}
}

void ALSAInput::run() {
	try {

		Logger::LogInfo("[ALSAInput::run] Input thread started.");

		std::vector<char> buffer(m_alsa_period_size * m_channels * 2);

		while(!m_should_stop) {

			// check whether samples are available
			snd_pcm_sframes_t samples_available, capture_delay;
			if(snd_pcm_avail_delay(m_alsa_pcm, &samples_available, &capture_delay) < 0) {
				Logger::LogError("[ALSAInput::run] Error: Can't get number of available samples!");
				throw ALSAException();
			}
			if(samples_available < m_alsa_period_size) {
				usleep(10000);
				continue;
			}
			int64_t time = hrt_time_micro() - (int64_t) (samples_available + capture_delay) * (int64_t) 1000000 / (int64_t) m_sample_rate;

			// read the samples
			snd_pcm_sframes_t samples_read = snd_pcm_readi(m_alsa_pcm, buffer.data(), m_alsa_period_size);
			if(samples_read < 0) {

				if(samples_read == EPIPE) {
					Logger::LogWarning("[ALSAInput::run] Warning: Overrun occurred, some samples were lost!");
					if(snd_pcm_prepare(m_alsa_pcm) < 0) {
						Logger::LogError("[ALSAInput::run] Error: Can't recover device after overrun!");
						throw ALSAException();
					}
				} else {
					Logger::LogError("[ALSAInput::run] Error: Can't read samples!");
					throw ALSAException();
				}

			} else if(samples_read > 0) {

				// send the samples to the synchronizer
				m_synchronizer->AddAudioSamples(buffer.data(), samples_read, time);

			}


		}

		Logger::LogInfo("[ALSAInput::run] Input thread stopped.");

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError(QString("[ALSAInput::run] Exception '") + e.what() + "' in input thread.");
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[ALSAInput::run] Unknown exception in input thread.");
	}
}
