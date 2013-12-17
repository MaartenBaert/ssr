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

#include "Logger.h"

Resampler::Resampler() {

	m_started = false;

	m_soxr = NULL;

}

Resampler::~Resampler() {
	if(m_soxr != NULL) {
		soxr_delete(m_soxr);
		m_soxr = NULL;
	}
}

void Resampler::Resample(unsigned int in_channels, unsigned int in_sample_rate, AVSampleFormat in_format, unsigned int in_sample_count, const uint8_t* in_data,
						 unsigned int out_channels, unsigned int out_sample_rate, AVSampleFormat out_format, unsigned int* out_sample_count, const uint8_t** out_data) {
	Q_ASSERT(in_channels > 0 && out_channels > 0);
	Q_ASSERT(in_sample_rate > 0 && out_sample_rate > 0);
	Q_ASSERT(in_channels == out_channels);
	Q_ASSERT(out_format == AV_SAMPLE_FMT_FLT);

	if(m_started) {
		Q_ASSERT(m_out_channels == out_channels);
		Q_ASSERT(m_out_sample_rate == out_sample_rate);
	} else {
		m_started = true;
		m_in_sample_rate = 0; // trigger creation of new resampler
		m_out_channels = out_channels;
		m_out_sample_rate = out_sample_rate;
	}

	// prepare output samples
	unsigned int out_pos = 0;
	m_out_data.alloc(16 * 1024);

	// do we need a new resampler?
	if(in_sample_rate != m_in_sample_rate) {

		// delete old resampler
		if(m_soxr != NULL) {

			// flush resampler
			for( ; ; ) {
				size_t out_done;
				soxr_error_t error = soxr_process(m_soxr,
												  NULL, 0, NULL,
												  m_out_data.data() + out_pos * out_channels * sizeof(float), m_out_data.size() / (out_channels * sizeof(float)) - out_pos, &out_done);
				if(error != NULL) {
					Logger::LogError("[Resampler::Resample] " + QObject::tr("Error: Flushing resampler failed! Reason: %s").arg(soxr_strerror(error)));
					throw SoxrException();
				}
				out_pos += out_done;
				if(out_pos < m_out_data.size() / (out_channels * sizeof(float)))
					break;
				m_out_data.realloc(m_out_data.size() * 2);
			}

			soxr_delete(m_soxr);
			m_soxr = NULL;
		}

		m_in_sample_rate = in_sample_rate;

		// do we really need a resampler?
		if(m_in_sample_rate != m_out_sample_rate) {
			Logger::LogInfo("[Resampler::Resampler] " + QObject::tr("Resampling from %1 to %2.").arg(m_in_sample_rate).arg(m_out_sample_rate));
			soxr_error_t error;
			soxr_quality_spec_t quality = soxr_quality_spec(SOXR_MQ, 0);
			m_soxr = soxr_create((double) m_in_sample_rate, (double) m_out_sample_rate, out_channels, &error, NULL, &quality, NULL);
			if(m_soxr == NULL || error != NULL) {
				m_in_sample_rate = 0;
				Logger::LogError("[Resampler::Resampler] " + QObject::tr("Error: Can't create resampler! Reason: %s").arg(soxr_strerror(error)));
				throw SoxrException();
			}
		} else {
			Logger::LogInfo("[Resampler::Resampler] " + QObject::tr("Resampling not needed."));
		}

	}

	// prepare input samples
	uint8_t *in_data_float;
	unsigned int in_pos = 0;
	if(in_format == AV_SAMPLE_FMT_FLT) {
		in_data_float = (uint8_t*) in_data;
	} else if(in_format == AV_SAMPLE_FMT_S16) {
		m_in_data.alloc(in_sample_count * out_channels * sizeof(float));
		SampleCopy(in_sample_count * out_channels, (const int16_t*) in_data, 1, (float*) m_in_data.data(), 1);
		in_data_float = (uint8_t*) m_in_data.data();
	} else {
		Q_ASSERT(false); // unsupported input format
		return;
	}

	// no resampling needed?
	if(m_in_sample_rate == m_out_sample_rate) {
		if(out_pos == 0) {
			*out_sample_count = in_sample_count;
			*out_data = in_data_float;
		} else {
			m_out_data.realloc((out_pos + in_sample_count) * out_channels * sizeof(float));
			memcpy(m_out_data.data() + out_pos * out_channels * sizeof(float), in_data_float, in_sample_count * out_channels * sizeof(float));
			*out_sample_count = out_pos + in_sample_count;
			*out_data = m_out_data.data();
		}
		return;
	}

	// resample
	for( ; ; ) {
		size_t in_done, out_done;
		soxr_error_t error = soxr_process(m_soxr,
										  in_data_float + in_pos * out_channels * sizeof(float), in_sample_count - in_pos, &in_done,
										  m_out_data.data() + out_pos * out_channels * sizeof(float), m_out_data.size() / (out_channels * sizeof(float)) - out_pos, &out_done);
		if(error != NULL) {
			Logger::LogError("[Resampler::Resample] " + QObject::tr("Error: Resampling failed!"));
			throw SoxrException();
		}
		in_pos += in_done;
		out_pos += out_done;
		if(in_pos == in_sample_count)
			break;
		m_out_data.realloc(m_out_data.size() * 2);
	}

	*out_sample_count = out_pos;
	*out_data = m_out_data.data();

}

double Resampler::GetDelayedSamples() {
	if(m_soxr == NULL)
		return 0.0;
	return soxr_delay(m_soxr);
}
