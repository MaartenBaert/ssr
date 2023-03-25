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

#include "SimpleSynth.h"

#if SSR_USE_ALSA

#include "Logger.h"
#include "SampleCast.h"

#include <sched.h>
#include <sys/time.h>
#include <sys/resource.h>

static void MakeThreadHighPriority() {
#ifdef __linux__
	rlimit limit;

	// try to get real-time priority
	getrlimit(RLIMIT_RTPRIO, &limit);
	int rt_limit = (limit.rlim_cur == RLIM_INFINITY)? std::numeric_limits<int>::max() : limit.rlim_cur;
	if(rt_limit > 0) {
		int priority = std::min(10, rt_limit);
		if(sched_setscheduler(0, SCHED_FIFO, (sched_param*) &priority) == 0) {
			Logger::LogInfo("[MakeThreadHighPriority] " + Logger::tr("Using real-time priority."));
			return;
		}
	}

	// if that fails, use a low nice value instead
	getrlimit(RLIMIT_NICE, &limit);
	int nice_limit = (limit.rlim_cur == RLIM_INFINITY)? std::numeric_limits<int>::min() : 20 - limit.rlim_cur; // see man page
	if(nice_limit < 0) {
		if(setpriority(PRIO_PROCESS, 0, std::max(-10, nice_limit)) == 0) {
			Logger::LogInfo("[MakeThreadHighPriority] " + Logger::tr("Using nice priority.", "Don't translate 'nice', it's a UNIX parameter that defines the priority of a process."));
			return;
		}
	}

	Logger::LogWarning("[MakeThreadHighPriority] " + Logger::tr("Warning: Can't increase the thread priority."));
#endif
}

static void ALSARecoverAfterUnderrun(snd_pcm_t* pcm) {
	// this is not really a problem so don't show the warning
	//Logger::LogWarning("[ALSARecoverAfterUnderrun] " + Logger::tr("Warning: An underrun has occurred, some samples were too late.", "Don't translate 'underrun'"));
	if(snd_pcm_prepare(pcm) < 0) {
		Logger::LogError("[ALSARecoverAfterUnderrun] " + Logger::tr("Error: Can't recover device after underrun!", "Don't translate 'underrun'"));
		throw ALSAException();
	}
}

SimpleSynth::SimpleSynth(const QString& sink_name, unsigned int sample_rate) {

	m_sink_name = sink_name;
	m_sample_rate = sample_rate;
	m_period_size = 1024; // number of samples per period
	m_buffer_size = m_period_size * 2; // number of samples in the buffer

	m_alsa_pcm = NULL;

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

SimpleSynth::~SimpleSynth() {

	// tell the thread to stop
	if(m_thread.joinable()) {
		Logger::LogInfo("[SimpleSynth::~SimpleSynth] " + Logger::tr("Stopping synth thread ..."));
		m_should_stop = true;
		m_thread.join();
	}

	// free everything
	Free();

}

void SimpleSynth::PlaySequence(const Note* notes, unsigned int note_count) {
	if(m_error_occurred)
		return;
	SharedLock lock(&m_shared_data);
	for(unsigned int i = 0; i < note_count; ++i) {
		lock->m_notes.push_back(notes[i]);
		lock->m_notes.back().m_time += lock->m_current_time;
	}
}

void SimpleSynth::Init() {

	snd_pcm_hw_params_t *alsa_hw_params = NULL;

	try {

		// allocate parameter structure
		if(snd_pcm_hw_params_malloc(&alsa_hw_params) < 0) {
			throw std::bad_alloc();
		}

		// open PCM device
		if(snd_pcm_open(&m_alsa_pcm, m_sink_name.toUtf8().constData(), SND_PCM_STREAM_PLAYBACK, 0) < 0) {
			Logger::LogError("[SimpleSynth::Init] " + Logger::tr("Error: Can't open PCM device!"));
			throw ALSAException();
		}
		if(snd_pcm_hw_params_any(m_alsa_pcm, alsa_hw_params) < 0) {
			Logger::LogError("[SimpleSynth::Init] " + Logger::tr("Error: Can't get PCM hardware parameters!"));
			throw ALSAException();
		}

		// set access type
		if(snd_pcm_hw_params_set_access(m_alsa_pcm, alsa_hw_params, SND_PCM_ACCESS_RW_INTERLEAVED) < 0) {
			Logger::LogError("[SimpleSynth::Init] " + Logger::tr("Error: Can't set access type!"));
			throw ALSAException();
		}

		// set sample format
		if(snd_pcm_hw_params_set_format(m_alsa_pcm, alsa_hw_params, SND_PCM_FORMAT_S16_LE) < 0) {
			Logger::LogError("[SimpleSynth::Init] " + Logger::tr("Error: Can't set sample format!"));
			throw ALSAException();
		}

		// set sample rate
		unsigned int sample_rate = m_sample_rate;
		if(snd_pcm_hw_params_set_rate_near(m_alsa_pcm, alsa_hw_params, &sample_rate, NULL) < 0) {
			Logger::LogError("[SimpleSynth::Init] " + Logger::tr("Error: Can't set sample rate!"));
			throw ALSAException();
		}
		if(sample_rate != m_sample_rate) {
			Logger::LogWarning("[SimpleSynth::Init] " + Logger::tr("Warning: Sample rate %1 is not supported, using %2 instead. "
																	"This is not a problem.")
							   .arg(m_sample_rate).arg(sample_rate));
			m_sample_rate = sample_rate;
		}

		// set channel count
		if(snd_pcm_hw_params_set_channels(m_alsa_pcm, alsa_hw_params, 1) < 0) {
			Logger::LogError("[SimpleSynth::Init] " + Logger::tr("Error: Can't set channel count!"));
			throw ALSAException();
		}

		// set period size
		snd_pcm_uframes_t period_size = m_period_size;
		if(snd_pcm_hw_params_set_period_size_near(m_alsa_pcm, alsa_hw_params, &period_size, NULL) < 0) {
			Logger::LogError("[SimpleSynth::Init] " + Logger::tr("Error: Can't set period size!"));
			throw ALSAException();
		}
		if(period_size != m_period_size) {
			Logger::LogWarning("[SimpleSynth::Init] " + Logger::tr("Warning: Period size %1 is not supported, using %2 instead. "
																	"This is not a problem.")
							   .arg(m_period_size).arg(period_size));
			m_period_size = period_size;
		}

		// set buffer size
		snd_pcm_uframes_t buffer_size = m_buffer_size;
		if(snd_pcm_hw_params_set_buffer_size_near(m_alsa_pcm, alsa_hw_params, &buffer_size) < 0) {
			Logger::LogError("[SimpleSynth::Init] " + Logger::tr("Error: Can't set buffer size!"));
			throw ALSAException();
		}
		if(buffer_size != m_buffer_size) {
			Logger::LogWarning("[SimpleSynth::Init] " + Logger::tr("Warning: Buffer size %1 is not supported, using %2 instead. "
																  "This is not a problem.")
							   .arg(m_buffer_size).arg(buffer_size));
			m_buffer_size = buffer_size;
		}

		// apply parameters
		if(snd_pcm_hw_params(m_alsa_pcm, alsa_hw_params) < 0) {
			Logger::LogError("[SimpleSynth::Init] " + Logger::tr("Error: Can't apply PCM hardware parameters!"));
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

	// start input thread
	m_should_stop = false;
	m_error_occurred = false;
	m_thread = std::thread(&SimpleSynth::SynthThread, this);

}

void SimpleSynth::Free() {
	if(m_alsa_pcm != NULL) {
		snd_pcm_close(m_alsa_pcm);
		m_alsa_pcm = NULL;
	}
}

void SimpleSynth::SynthThread() {
	try {

		Logger::LogInfo("[SimpleSynth::SynthThread] " + Logger::tr("Synth thread started."));

		MakeThreadHighPriority();

		std::vector<float> buffer_float(m_period_size);
		std::vector<int16_t> buffer_int16(m_period_size);

		while(!m_should_stop) {

			// generate the samples
			{
				SharedLock lock(&m_shared_data);
				if(lock->m_notes.empty()) { // faster version
					memset(buffer_int16.data(), 0, m_period_size * sizeof(int16_t));
				} else {
					memset(buffer_float.data(), 0, m_period_size * sizeof(float));
					for(unsigned int i = 0; i < lock->m_notes.size(); ) {
						Note &n = lock->m_notes[i];
						int trel = n.m_time - lock->m_current_time;
						int t1 = clamp(trel, 0, (int) m_period_size);
						int t2 = clamp(trel + (int) n.m_duration_in, 0, (int) m_period_size);
						int t3 = clamp(trel + (int) n.m_duration_in + (int) n.m_duration_out, 0, (int) m_period_size);
						if(t1 == (int) m_period_size) { // beep not started yet
							++i;
							continue;
						}
						if(t3 == 0) { // beep done
							if(i != lock->m_notes.size() - 1)
								n = lock->m_notes.back();
							lock->m_notes.pop_back();
							continue;
						}
						float k = 2.0f * M_PI * n.m_frequency / (float) m_sample_rate;
						float amp_low = log2(n.m_amplitude * 0.001f), amp_high = log2(n.m_amplitude);
						for(int t = t1; t < t2; ++t) {
							buffer_float[t] += sin((float) (t - trel) * k) * exp2(amp_low + (amp_high - amp_low) * (float) (t - trel) / (float) n.m_duration_in);
						}
						for(int t = t2; t < t3; ++t) {
							buffer_float[t] += sin((float) (t - trel) * k) * exp2(amp_high + (amp_low - amp_high) * (float) (t - trel - (int) n.m_duration_in) / (float) n.m_duration_out);
						}
						++i;
					}
					lock->m_current_time += m_period_size;
					SampleCopy(m_period_size, buffer_float.data(), 1, buffer_int16.data(), 1);
				}
			}

			// write the samples
			snd_pcm_sframes_t samples_written = snd_pcm_writei(m_alsa_pcm, buffer_int16.data(), m_period_size);
			if(samples_written < 0) {
				if(samples_written == -EPIPE) {
					ALSARecoverAfterUnderrun(m_alsa_pcm);
				} else {
					Logger::LogError("[SimpleSynth::SynthThread] " + Logger::tr("Error: Can't write samples!"));
					throw ALSAException();
				}
				continue;
			}

		}

		Logger::LogInfo("[SimpleSynth::SynthThread] " + Logger::tr("Synth thread stopped."));

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError("[SimpleSynth::SynthThread] " + Logger::tr("Exception '%1' in synth thread.").arg(e.what()));
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[SimpleSynth::SynthThread] " + Logger::tr("Unknown exception in synth thread."));
	}
}

#endif
