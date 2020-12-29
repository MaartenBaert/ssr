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

#pragma once
#include "Global.h"

template<typename IN, typename OUT> OUT SampleCast(IN x);
template<> inline int16_t SampleCast<int16_t, int16_t>(int16_t x) { return x; }
template<> inline int16_t SampleCast<int32_t, int16_t>(int32_t x) { return (x + (1 << 15)) >> 16; }
template<> inline int16_t SampleCast<float  , int16_t>(float   x) { return lrint(fmin(fmax(x * 32768.0f, -32768.0f), 32767.0f)); }
template<> inline float   SampleCast<int16_t, float  >(int16_t x) { return (float) x * (1.0f / 32768.0f); }
template<> inline float   SampleCast<int32_t, float  >(int32_t x) { return (float) x * (1.0f / 2147483648.0f); }
template<> inline float   SampleCast<float  , float  >(float   x) { return x; }

template<typename IN> IN SampleMix(IN a, IN b);
template<> inline int16_t SampleMix<int16_t>(int16_t a, int16_t b) { return (a + b) >> 1; }
template<> inline float   SampleMix<float  >(float   a, float   b) { return (a + b) * 0.5f; }

// Simple sample format conversion.
// The in_step and out_step parameters are useful for converting between planar and interleaved audio.
template<typename IN, typename OUT>
inline void SampleCopy(unsigned int sample_count, const IN* in_data, int in_step, OUT* out_data, int out_step) {
	for(unsigned int i = 0; i < sample_count; ++i) {
		*out_data = SampleCast<IN, OUT>(*in_data);
		in_data += in_step;
		out_data += out_step;
	}
}

// Sample format conversion and channel remapping in one step.
// This function only supports interleaved audio.
template<typename IN, typename OUT>
inline void SampleChannelRemap(unsigned int sample_count, const IN* in_data, unsigned int in_channels, OUT* out_data, unsigned int out_channels) {
	if(in_channels == out_channels) { // no remapping needed
		for(unsigned int i = 0; i < sample_count * in_channels; ++i) {
			*(out_data++) = SampleCast<IN, OUT>(*(in_data++));
		}
	} else if(in_channels == 1 && out_channels == 2) { // mono to stereo
		for(unsigned int i = 0; i < sample_count; ++i) {
			OUT val = SampleCast<IN, OUT>(*(in_data++));
			*(out_data++) = val;
			*(out_data++) = val;
		}
	} else if(in_channels == 2 && out_channels == 1) { // stereo to mono
		for(unsigned int i = 0; i < sample_count; ++i) {
			OUT val1 = SampleCast<IN, OUT>(*(in_data++));
			OUT val2 = SampleCast<IN, OUT>(*(in_data++));
			*(out_data++) = SampleMix(val1, val2);
		}
	} else if(in_channels < out_channels) { // fill additional channels with silence
		for(unsigned int i = 0; i < sample_count; ++i) {
			for(unsigned int j = 0; j < in_channels; ++j)
				*(out_data++) = SampleCast<IN, OUT>(*(in_data++));
			for(unsigned int j = 0; j < out_channels - in_channels; ++j)
				*(out_data++) = (OUT) 0;
		}
	} else { // drop redundant channels
		for(unsigned int i = 0; i < sample_count; ++i) {
			for(unsigned int j = 0; j < out_channels; ++j)
				*(out_data++) = SampleCast<IN, OUT>(*(in_data++));
			in_data += in_channels - out_channels;
		}
	}
}
