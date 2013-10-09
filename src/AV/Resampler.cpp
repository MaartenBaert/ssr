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

}

Resampler::~Resampler() {

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

	if(m_in_sample_rate == m_out_sample_rate) {
		//TODO// flush
		*out_sample_count = in_sample_count;
		*out_data = in_data;
	} else {

	}

}
