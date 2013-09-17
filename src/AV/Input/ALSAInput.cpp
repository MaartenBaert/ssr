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
#include "ALSAInput.h"

#include "Logger.h"

// Artificial delay after the first samples have been received (in microseconds). Any samples received during this time will be dropped.
// This is needed because the first samples sometimes have weird timestamps, especially when PulseAudio is active
// (I've seen one situation where PulseAudio instantly 'captures' 2 seconds of silence when the recording is started).
// It also eliminates the clicking sound when the microphone is started for the first time.
const int64_t ALSAInput::START_DELAY = 100000;

static void ALSARecoverAfterOverrun(snd_pcm_t* pcm) {
	Logger::LogWarning("[ALSARecoverAfterOverrun] Warning: Overrun occurred, some samples were lost.");
	if(snd_pcm_prepare(pcm) < 0) {
		Logger::LogError("[ALSARecoverAfterOverrun] Error: Can't recover device after overrun!");
		throw ALSAException();
	}
	if(snd_pcm_start(pcm) < 0) {
		Logger::LogError("[ALSARecoverAfterOverrun] Error: Can't start PCM device after overrun!");
		throw ALSAException();
	}
}

ALSAInput::ALSAInput(const QString& device_name, unsigned int sample_rate) {

	m_device_name = device_name;
	m_sample_rate = sample_rate;
	m_channels = 2; // always 2 channels because the synchronizer and encoder don't support anything else at this point

	m_alsa_pcm = NULL;
	m_alsa_periods = 10;
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
	if(m_thread.joinable()) {
		Logger::LogInfo("[ALSAInput::~ALSAInput] Telling input thread to stop ...");
		m_should_stop = true;
		m_thread.join();
	}

	// free everything
	Free();

}

void ALSAInput::Init() {

	snd_pcm_hw_params_t *alsa_hw_params = NULL;

	try {

		// allocate parameter structure
		if(snd_pcm_hw_params_malloc(&alsa_hw_params) < 0) {
			throw std::bad_alloc();
		}

		// open PCM device
		if(snd_pcm_open(&m_alsa_pcm, qPrintable(m_device_name), SND_PCM_STREAM_CAPTURE, 0) < 0) {
			Logger::LogError("[ALSAInput::Init] Error: Can't open PCM device!");
			throw ALSAException();
		}
		if(snd_pcm_hw_params_any(m_alsa_pcm, alsa_hw_params) < 0) {
			Logger::LogError("[ALSAInput::Init] Error: Can't get PCM hardware parameters!");
			throw ALSAException();
		}

		// set access type
		if(snd_pcm_hw_params_set_access(m_alsa_pcm, alsa_hw_params, SND_PCM_ACCESS_RW_INTERLEAVED) < 0) {
			Logger::LogError("[ALSAInput::Init] Error: Can't set access type!");
			throw ALSAException();
		}

		// set sample format
		if(snd_pcm_hw_params_set_format(m_alsa_pcm, alsa_hw_params, SND_PCM_FORMAT_S16_LE) < 0) {
			Logger::LogError("[ALSAInput::Init] Error: Can't set sample format!");
			throw ALSAException();
		}

		// set sample rate
		unsigned int rate = m_sample_rate;
		if(snd_pcm_hw_params_set_rate_near(m_alsa_pcm, alsa_hw_params, &rate, NULL) < 0) {
			Logger::LogError("[ALSAInput::Init] Error: Can't set sample rate!");
			throw ALSAException();
		}
		if(rate != m_sample_rate) {
			Logger::LogWarning("[ALSAInput::Init] Warning: Sample rate " + QString::number(m_sample_rate) + " is not supported, using " + QString::number(rate) + " instead. This could be a problem if the difference is large.");
			//TODO// enable once resampling is ready
			//m_sample_rate = rate;
		}

		// set channels
		if(snd_pcm_hw_params_set_channels(m_alsa_pcm, alsa_hw_params, m_channels) < 0) {
			Logger::LogError("[ALSAInput::Init] Error: Can't set channels!");
			throw ALSAException();
		}

		// set periods
		unsigned int periods = m_alsa_periods;
		if(snd_pcm_hw_params_set_periods_near(m_alsa_pcm, alsa_hw_params, &periods, NULL) < 0) {
			Logger::LogError("[ALSAInput::Init] Error: Can't set periods!");
			throw ALSAException();
		}
		if(periods != m_alsa_periods) {
			Logger::LogWarning("[ALSAInput::Init] Warning: Period count " + QString::number(m_alsa_periods) + " is not supported, using " + QString::number(periods) + " instead. This is not a problem.");
			m_alsa_periods = periods;
		}

		// set period size
		snd_pcm_uframes_t period_size = m_alsa_period_size;
		if(snd_pcm_hw_params_set_period_size_near(m_alsa_pcm, alsa_hw_params, &period_size, NULL) < 0) {
			Logger::LogError("[ALSAInput::Init] Error: Can't set period size!");
			throw ALSAException();
		}
		if(period_size != m_alsa_period_size) {
			Logger::LogWarning("[ALSAInput::Init] Warning: Period size " + QString::number(m_alsa_period_size) + " is not supported, using " + QString::number(period_size) + " instead. This is not a problem.");
			m_alsa_period_size = period_size;
		}

		// apply parameters
		if(snd_pcm_hw_params(m_alsa_pcm, alsa_hw_params) < 0) {
			Logger::LogError("[ALSAInput::Init] Error: Can't apply PCM hardware parameters!");
			throw ALSAException();
		}

		// free parameter structure
		snd_pcm_hw_params_free(alsa_hw_params);
		alsa_hw_params = NULL;

	} catch(...) {
		if(alsa_hw_params != NULL) {
			snd_pcm_hw_params_free(alsa_hw_params);
			alsa_hw_params = NULL;
		}
		throw;
	}

	// start PCM device
	if(snd_pcm_start(m_alsa_pcm) < 0) {
		Logger::LogError("[ALSAInput::Init] Error: Can't start PCM device!");
		throw ALSAException();
	}

	// start input thread
	m_should_stop = false;
	m_error_occurred = false;
	m_thread = std::thread(&ALSAInput::InputThread, this);

}

void ALSAInput::Free() {
	if(m_alsa_pcm != NULL) {
		snd_pcm_close(m_alsa_pcm);
		m_alsa_pcm = NULL;
	}
}

void ALSAInput::InputThread() {
	try {

		Logger::LogInfo("[ALSAInput::run] Input thread started.");

		std::vector<uint8_t> buffer(m_alsa_period_size * m_channels * 2);
		bool has_first_samples = false;
		int64_t first_timestamp = 0; // value won't be used, but GCC gives a warning otherwise

		while(!m_should_stop) {

			// wait until samples are available
			// This is not actually required since snd_pcm_readi is blocking, but unlike snd_pcm_read,
			// this function has a timeout value. This means the input thread won't hang if the device turns out to be dead.
			int res = snd_pcm_wait(m_alsa_pcm, 1000);
			if(res == 0) {
				Logger::LogInfo("[ALSAInput::run] No samples after waiting for 1000ms, the device is probably dead.");
				continue;
			}
			if(res < 0) {
				if(res == -EPIPE) {
					ALSARecoverAfterOverrun(m_alsa_pcm);
					PushAudioHole();
				} else {
					Logger::LogError("[ALSAInput::run] Error: Can't check whether samples are available!");
					throw ALSAException();
				}
				continue;
			}

			// read the samples
			snd_pcm_sframes_t samples_read = snd_pcm_readi(m_alsa_pcm, buffer.data(), m_alsa_period_size);
			if(samples_read < 0) {
				if(samples_read == -EPIPE) {
					ALSARecoverAfterOverrun(m_alsa_pcm);
					PushAudioHole();
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
				if(timestamp > first_timestamp + START_DELAY) {

					// send the samples to the synchronizer
					int64_t time = timestamp - (int64_t) samples_read * (int64_t) 1000000 / (int64_t) m_sample_rate;
					PushAudioSamples(m_sample_rate, m_channels, samples_read, buffer.data(), AV_SAMPLE_FMT_S16, time);

				}
			} else {
				has_first_samples = true;
				first_timestamp = timestamp;
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
