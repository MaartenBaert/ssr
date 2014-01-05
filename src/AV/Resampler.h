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

#pragma once
#include "Global.h"

#include "TempBuffer.h"

#include <soxr.h>

template<typename IN, typename OUT> inline OUT SampleCast(IN x) { return x; }
template<> inline int16_t SampleCast<float  , int16_t>(float   x) { return round_to<int16_t>(fminf(fmaxf(x * 32768.0f, -32768.0f), 32767.0f)); }
template<> inline float   SampleCast<int16_t, float  >(int16_t x) { return (float) x * (1.0f / 32768.0f); }

template<typename IN, typename OUT>
inline void SampleCopy(unsigned int sample_count, const IN* in_data, int in_step, OUT* out_data, int out_step) {
	for(unsigned int i = 0; i < sample_count; ++i) {
		*out_data = SampleCast<IN, OUT>(*in_data);
		in_data += in_step;
		out_data += out_step;
	}
}

class Resampler {

private:
	bool m_started;
	unsigned int m_in_sample_rate;
	unsigned int m_out_channels, m_out_sample_rate;

	soxr_t m_soxr;

	TempBuffer<uint8_t> m_in_data, m_out_data;

public:
	Resampler();
	~Resampler();
	void Resample(unsigned int in_channels, unsigned int in_sample_rate, AVSampleFormat in_format, unsigned int in_sample_count, const uint8_t* in_data,
				  unsigned int out_channels, unsigned int out_sample_rate, AVSampleFormat out_format, unsigned int* out_sample_count, const uint8_t** out_data);
	double GetDelayedSamples();

};
