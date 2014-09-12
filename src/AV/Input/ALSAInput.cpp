/*
Copyright (c) 2012-2014 Maarten Baert <maarten-baert@hotmail.com>

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
	Logger::LogWarning("[ALSARecoverAfterOverrun] " + Logger::tr("Warning: An overrun has occurred, some samples were lost.", "Don't translate 'overrun'"));
	if(snd_pcm_prepare(pcm) < 0) {
		Logger::LogError("[ALSARecoverAfterOverrun] " + Logger::tr("Error: Can't recover device after overrun!", "Don't translate 'overrun'"));
		throw ALSAException();
	}
	if(snd_pcm_start(pcm) < 0) {
		Logger::LogError("[ALSARecoverAfterOverrun] " + Logger::tr("Error: Can't start PCM device after overrun!", "Don't translate 'overrun'"));
		throw ALSAException();
	}
}

ALSAInput::ALSAInput(const QString& source_name, unsigned int sample_rate) {

	m_source_name = source_name;
	m_sample_rate = sample_rate;
	m_channels = 2; // always 2 channels because the synchronizer and encoder don't support anything else at this point
	m_period_size = 1024; // number of samples per period
	m_buffer_size = m_period_size * 8; // number of samples in the buffer

	m_alsa_pcm = NULL;

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
		Logger::LogInfo("[ALSAInput::~ALSAInput] " + Logger::tr("Stopping input thread ..."));
		m_should_stop = true;
		m_thread.join();
	}

	// free everything
	Free();

}

std::vector<ALSAInput::Source> ALSAInput::GetSourceList() {
	std::vector<Source> list;

	/*
	This code is based on the ALSA device detection code used in PortAudio. I just ported it to C++ and improved it a bit.
	All credit goes to the PortAudio devs, they saved me a lot of time :).
	*/

	// these ALSA plugins are blacklisted because they are always defined but rarely useful
	// 'pulse' is also blacklisted because the native PulseAudio backend is more reliable
	std::vector<std::string> plugin_blacklist = {
		"cards", "default", "sysdefault", "hw", "plughw", "plug", "dmix", "dsnoop", "shm", "tee", "file", "null",
		"front", "rear", "center_lfe", "side", "surround40", "surround41", "surround50", "surround51", "surround71",
		"iec958", "spdif", "hdmi", "modem", "phoneline", "pulse",
	};
	std::sort(plugin_blacklist.begin(), plugin_blacklist.end());

	// the 'default' PCM must be first, so add it explicitly
	list.push_back(Source("default", "Default source"));

	Logger::LogInfo("[ALSAInput::GetSourceList] " + Logger::tr("Generating source list ..."));

	snd_ctl_card_info_t *alsa_card_info = NULL;
	snd_pcm_info_t *alsa_pcm_info = NULL;
	snd_ctl_t *alsa_ctl = NULL;

	try {

		// allocate card and PCM info structure
		if(snd_ctl_card_info_malloc(&alsa_card_info) < 0) {
			throw std::bad_alloc();
		}
		if(snd_pcm_info_malloc(&alsa_pcm_info) < 0) {
			throw std::bad_alloc();
		}

		// update the ALSA configuration
		snd_config_update_free_global();
		if(snd_config_update() < 0) {
			Logger::LogError("[ALSAInput::GetSourceList] " + Logger::tr("Error: Could not update ALSA configuration!"));
			throw ALSAException();
		}

		// find all PCM plugins (by parsing the config file)
		snd_config_t *alsa_config_pcms = NULL;
		if(snd_config_search(snd_config, "pcm", &alsa_config_pcms) == 0) {
			snd_config_iterator_t i, next;
			snd_config_for_each(i, next, alsa_config_pcms) {
				snd_config_t *alsa_config_pcm = snd_config_iterator_entry(i);

				// get the name
				const char *id = NULL;
				if(snd_config_get_id(alsa_config_pcm, &id) < 0 || id == NULL)
					continue;
				std::string plugin_name = id;

				// ignore the plugin if it is blacklisted
				if(std::binary_search(plugin_blacklist.begin(), plugin_blacklist.end(), plugin_name))
					continue;

				// try to get the description
				std::string plugin_description;
				snd_config_t *alsa_config_description = NULL;
				if(snd_config_search(alsa_config_pcm, "hint.description", &alsa_config_description) == 0) {
					const char *str = NULL;
					if(snd_config_get_string(alsa_config_description, &str) >= 0 && str != NULL) {
						plugin_description = str;
					}
				}

				// if there is no description, ignore it, because it's probably not meant to be used
				if(plugin_description.empty())
					continue;

				// if there is no description, use the type instead
				/*if(plugin_description.empty()) {
					snd_config_t *alsa_config_type = NULL;
					if(snd_config_search(alsa_config_pcm, "type", &alsa_config_type) >= 0) {
						const char *str = NULL;
						if(snd_config_get_string(alsa_config_type, &str) >= 0 && str != NULL) {
							plugin_description = std::string(str) + " plugin";
						}
					}
				}*/

				// add to list
				Logger::LogInfo("[ALSAInput::GetSourceList] " + Logger::tr("Found plugin: [%1] %2").arg(QString::fromStdString(plugin_name)).arg(QString::fromStdString(plugin_description)));
				list.push_back(Source(plugin_name, plugin_description));

			}
		}

		// find all sound cards
		int card = -1;
		while(snd_card_next(&card) == 0 && card >= 0) {

			// try to open the card
			std::string card_name = "hw:" + NumToString(card);
			if(snd_ctl_open(&alsa_ctl, card_name.c_str(), 0) < 0) {
				Logger::LogWarning("[ALSAInput::GetSourceList] " + Logger::tr("Warning: Could not open sound card %1.").arg(card));
				continue;
			}

			// get card info
			if(snd_ctl_card_info(alsa_ctl, alsa_card_info) < 0) {
				Logger::LogWarning("[ALSAInput::GetSourceList] " + Logger::tr("Warning: Could not get info for sound card %1.").arg(card));
				continue;
			}
			std::string card_description = snd_ctl_card_info_get_name(alsa_card_info);
			Logger::LogInfo("[ALSAInput::GetSourceList] " + Logger::tr("Found card: [%1] %2").arg(QString::fromStdString(card_name)).arg(QString::fromStdString(card_description)));

			// find all devices for this card
			int device = -1;
			bool should_add_shared = true;
			while(snd_ctl_pcm_next_device(alsa_ctl, &device) == 0 && device >= 0) {

				// get device info
				snd_pcm_info_set_device(alsa_pcm_info, device);
				snd_pcm_info_set_subdevice(alsa_pcm_info, 0);
				snd_pcm_info_set_stream(alsa_pcm_info, SND_PCM_STREAM_CAPTURE);
				if(snd_ctl_pcm_info(alsa_ctl, alsa_pcm_info) < 0)
					continue; // not a capture device

				// add a shared source if needed
				if(should_add_shared) {
					list.push_back(Source("sysdefault:" + NumToString(card), card_description + " (shared)"));
					should_add_shared = false;
				}

				// get device description
				std::string device_name = "hw:" + NumToString(card) + "," + NumToString(device);
				std::string device_description = card_description + ": " + snd_pcm_info_get_name(alsa_pcm_info);

				// add to list
				Logger::LogInfo("[ALSAInput::GetSourceList] " + Logger::tr("Found device: [%1] %2").arg(QString::fromStdString(device_name)).arg(QString::fromStdString(device_description)));
				list.push_back(Source(device_name, device_description));

			}

			// close the card
			snd_ctl_close(alsa_ctl);
			alsa_ctl = NULL;

		}

		// free card and PCM info struction
		snd_pcm_info_free(alsa_pcm_info);
		alsa_pcm_info = NULL;
		snd_ctl_card_info_free(alsa_card_info);
		alsa_card_info = NULL;

	} catch(...) {
		if(alsa_ctl != NULL) {
			snd_ctl_close(alsa_ctl);
			alsa_ctl = NULL;
		}
		if(alsa_pcm_info != NULL) {
			snd_pcm_info_free(alsa_pcm_info);
			alsa_pcm_info = NULL;
		}
		if(alsa_card_info != NULL) {
			snd_ctl_card_info_free(alsa_card_info);
			alsa_card_info = NULL;
		}
		// don't re-throw exception
	}

	return list;
}

void ALSAInput::Init() {

	snd_pcm_hw_params_t *alsa_hw_params = NULL;

	try {

		// allocate parameter structure
		if(snd_pcm_hw_params_malloc(&alsa_hw_params) < 0) {
			throw std::bad_alloc();
		}

		// open PCM device
		if(snd_pcm_open(&m_alsa_pcm, m_source_name.toUtf8().constData(), SND_PCM_STREAM_CAPTURE, 0) < 0) {
			Logger::LogError("[ALSAInput::Init] " + Logger::tr("Error: Can't open PCM device!"));
			throw ALSAException();
		}
		if(snd_pcm_hw_params_any(m_alsa_pcm, alsa_hw_params) < 0) {
			Logger::LogError("[ALSAInput::Init] " + Logger::tr("Error: Can't get PCM hardware parameters!"));
			throw ALSAException();
		}

		// set access type
		if(snd_pcm_hw_params_set_access(m_alsa_pcm, alsa_hw_params, SND_PCM_ACCESS_RW_INTERLEAVED) < 0) {
			Logger::LogError("[ALSAInput::Init] " + Logger::tr("Error: Can't set access type!"));
			throw ALSAException();
		}

		// set sample format
		if(snd_pcm_hw_params_set_format(m_alsa_pcm, alsa_hw_params, SND_PCM_FORMAT_S16_LE) < 0) {
			Logger::LogError("[ALSAInput::Init] " + Logger::tr("Error: Can't set sample format!"));
			throw ALSAException();
		}

		// set sample rate
		unsigned int rate = m_sample_rate;
		if(snd_pcm_hw_params_set_rate_near(m_alsa_pcm, alsa_hw_params, &rate, NULL) < 0) {
			Logger::LogError("[ALSAInput::Init] " + Logger::tr("Error: Can't set sample rate!"));
			throw ALSAException();
		}
		if(rate != m_sample_rate) {
			Logger::LogWarning("[ALSAInput::Init] " + Logger::tr("Warning: Sample rate %1 is not supported, using %2 instead. "
																 "This is not a problem.")
							   .arg(m_sample_rate).arg(rate));
			m_sample_rate = rate;
		}

		// set channel count
		unsigned int channels = m_channels;
		if(snd_pcm_hw_params_set_channels_near(m_alsa_pcm, alsa_hw_params, &channels) < 0) {
			Logger::LogError("[ALSAInput::Init] " + Logger::tr("Error: Can't set channel count!"));
			throw ALSAException();
		}
		if(channels != m_channels) {
			Logger::LogWarning("[ALSAInput::Init] " + Logger::tr("Warning: Channel count %1 is not supported, using %2 instead. "
																 "This is not a problem.")
							   .arg(m_channels).arg(channels));
			m_channels = channels;
		}

		// set period size
		snd_pcm_uframes_t period_size = m_period_size;
		if(snd_pcm_hw_params_set_period_size_near(m_alsa_pcm, alsa_hw_params, &period_size, NULL) < 0) {
			Logger::LogError("[ALSAInput::Init] " + Logger::tr("Error: Can't set period size!"));
			throw ALSAException();
		}
		if(period_size != m_period_size) {
			Logger::LogWarning("[ALSAInput::Init] " + Logger::tr("Warning: Period size %1 is not supported, using %2 instead. "
																 "This is not a problem.")
							   .arg(m_period_size).arg(period_size));
			m_period_size = period_size;
		}

		// set buffer size
		snd_pcm_uframes_t buffer_size = m_buffer_size;
		if(snd_pcm_hw_params_set_buffer_size_near(m_alsa_pcm, alsa_hw_params, &buffer_size) < 0) {
			Logger::LogError("[ALSAInput::Init] " + Logger::tr("Error: Can't set buffer size!"));
			throw ALSAException();
		}
		if(buffer_size != m_buffer_size) {
			Logger::LogWarning("[ALSAInput::Init] " + Logger::tr("Warning: Buffer size %1 is not supported, using %2 instead. "
																 "This is not a problem.")
							   .arg(m_buffer_size).arg(buffer_size));
			m_buffer_size = buffer_size;
		}

		// apply parameters
		if(snd_pcm_hw_params(m_alsa_pcm, alsa_hw_params) < 0) {
			Logger::LogError("[ALSAInput::Init] " + Logger::tr("Error: Can't apply PCM hardware parameters!"));
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
		Logger::LogError("[ALSAInput::Init] " + Logger::tr("Error: Can't start PCM device!"));
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

		Logger::LogInfo("[ALSAInput::InputThread] " + Logger::tr("Input thread started."));

		std::vector<uint16_t> buffer(m_period_size * m_channels);
		bool has_first_samples = false;
		int64_t first_timestamp = 0; // value won't be used, but GCC gives a warning otherwise

		while(!m_should_stop) {

			// read the samples
			snd_pcm_sframes_t samples_read = snd_pcm_readi(m_alsa_pcm, buffer.data(), m_period_size);
			if(samples_read < 0) {
				if(samples_read == -EPIPE) {
					ALSARecoverAfterOverrun(m_alsa_pcm);
					PushAudioHole();
				} else {
					Logger::LogError("[ALSAInput::InputThread] " + Logger::tr("Error: Can't read samples!"));
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

					// push the samples
					int64_t time = timestamp - (int64_t) samples_read * (int64_t) 1000000 / (int64_t) m_sample_rate;
					PushAudioSamples(m_channels, m_sample_rate, AV_SAMPLE_FMT_S16, samples_read, (uint8_t*) buffer.data(), time);

				}
			} else {
				has_first_samples = true;
				first_timestamp = timestamp;
			}

		}

		Logger::LogInfo("[ALSAInput::InputThread] " + Logger::tr("Input thread stopped."));

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError("[ALSAInput::InputThread] " + Logger::tr("Exception '%1' in input thread.").arg(e.what()));
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[ALSAInput::InputThread] " + Logger::tr("Unknown exception in input thread."));
	}
}
