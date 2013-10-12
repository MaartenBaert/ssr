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

#include "Resampler.h"

Resampler::Resampler() {

	m_channels = 0;
	m_in_sample_rate = 0;
	m_out_sample_rate = 0;

	m_soxr = NULL;

}

Resampler::~Resampler() {
	if(m_soxr != NULL) {
		soxr_delete(m_soxr);
		m_soxr = NULL;
	}
}

void Resampler::Resample(unsigned int channels,
						 unsigned int in_sample_rate, unsigned int in_sample_count, const uint8_t* in_data, AVSampleFormat in_format,
						 unsigned int out_sample_rate, unsigned int* out_sample_count, const uint8_t** out_data, AVSampleFormat out_format) {

	if(m_channels == 0) {
		m_channels = channels;
	} else {
		Q_ASSERT(m_channels == channels);
	}
	if(m_in_sample_rate != in_sample_rate || m_out_sample_rate != out_sample_rate) {
		m_in_sample_rate = in_sample_rate;
		m_out_sample_rate = out_sample_rate;
		Logger::LogInfo("[Resampler::Resample] Resampling " + QString::number(m_in_sample_rate) + " to " + QString::number(m_out_sample_rate) + ".");
	}

	// prepare input samples
	float *in_float;
	if(in_format == AV_SAMPLE_FMT_FLT) {
		in_float = (float*) in_data;
	} else if(in_format == AV_SAMPLE_FMT_S16) {
		m_in_data.resize(in_sample_count * channels * sizeof(float));
		SampleCopy((const int16_t*) in_data, 1, (float*) m_in_data.data(), 1, in_sample_count * channels);
		in_float = (float*) m_in_data.data();
	} else {
		Q_ASSERT(false); // unsupported input format
	}

	// prepare output samples
	float *out_float;
	unsigned int out_sample_count_estimate = (uint64_t) in_sample_count * (uint64_t) out_sample_rate / (uint64_t) in_sample_rate + 100;
	out_sample_count_estimate += out_sample_count_estimate / 4;
	if(out_format == AV_SAMPLE_FMT_FLT) {
		m_out_data.resize(out_sample_count_estimate * channels * sizeof(float));
		out_float = (float*) m_out_data.data();
		*out_data = m_out_data.data();
	} else {
		Q_ASSERT(false); // unsupported input format
	}

	if(m_in_sample_rate == m_out_sample_rate) {

		//TODO// flush

		if(in_format == out_format) {
			*out_sample_count = in_sample_count;
			*out_data = in_data;
		}

	} else {

		// create the resampler if it doesn't exist yet
		if(lock->m_soxr == NULL) {
			soxr_error_t error;
			soxr_quality_spec_t quality = soxr_quality_spec(SOXR_HQ, SOXR_VR);
			lock->m_soxr = soxr_create(100.0, 1.0, m_audio_channels, &error, NULL, &quality, NULL);
			if(lock->m_soxr == NULL || error != NULL) {
				Logger::LogError("[FastScaler::Scale] Error: Can't get swscale context!");
				throw SoxrException();
			}
		}

		// set the new ratio
		soxr_set_io_ratio(lock->m_soxr, (double) in_sample_rate)

		size_t in_processed, out_processed;
		error = soxr_process(lock->m_soxr, in_float, in_sample_count, &in_processed, out_float, out_sample_count, &out_processed);
		if(error != NULL) {
			Logger::LogError("[FastScaler::Scale] Error: Can't get swscale context!");
			throw SoxrException();
		}

	}

}
