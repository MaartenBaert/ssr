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

template<typename IN, typename OUT> OUT SampleCast(IN x);
template<> inline int16_t SampleCast<int16_t, int16_t>(int16_t x) { return x; }
template<> inline int16_t SampleCast<float  , int16_t>(float   x) { return lrint(fmin(fmax(x * 32768.0f, -32768.0f), 32767.0f)); }
template<> inline float   SampleCast<int16_t, float  >(int16_t x) { return (float) x * (1.0f / 32768.0f); }
template<> inline float   SampleCast<float  , float  >(float   x) { return x; }

template<typename IN, typename OUT>
inline void SampleCopy(unsigned int sample_count, const IN* in_data, int in_step, OUT* out_data, int out_step) {
	for(unsigned int i = 0; i < sample_count; ++i) {
		*out_data = SampleCast<IN, OUT>(*in_data);
		in_data += in_step;
		out_data += out_step;
	}
}
