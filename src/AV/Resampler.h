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

#include <soxr.h>

template<typename IN, typename OUT> OUT SampleCast(IN x);
template<typename T> inline T       SampleCast<T,       T      >(T       x) { return x; }
template<>           inline int16_t SampleCast<float  , int16_t>(float   x) { return lrint(fmin(fmax(x * 32768.0f, -32768.0f), 32767.0f)); }
template<>           inline float   SampleCast<int16_t, float  >(int16_t x) { return (float) x * (1.0f / 32768.0f); }

template<typename IN, typename OUT>
inline void SampleCopy(const IN* in_data, int in_step, OUT* out_data, int out_step, unsigned int sample_count) {
	for(unsigned int i = 0; i < sample_count; ++i) {
		*out_data = SampleCast<IN, OUT>(*in_data);
		in_data += in_step;
		out_data += out_step;
	}
}

// Simple class that allocates temporary buffers efficiently by reusing memory to avoid new memory allocations.
// It is more efficient than std::vector because it doesn't copy data or initialize it to zero.
class TempBuffer {

private:
	uint8_t *m_data;
	size_t m_size;

public:
	inline TempBuffer() {
		m_data = NULL;
		m_size = 0;
	}
	inline ~TempBuffer() {
		free(m_data);
	}
	inline void resize(size_t size) {
		if(size > m_size) {
			free(m_data);
			m_data = (uint8_t*) malloc(size + size / 4);
			if(m_data == NULL) {
				m_size = 0;
				throw std::bad_alloc();
			}
			m_size = size;
		}
	}

	inline uint8_t* data() { return m_data; }
	inline size_t size() { return m_size; }

	// noncopyable
	TempBuffer(const TempBuffer&) = delete;
	TempBuffer& operator=(const TempBuffer&) = delete;

};

class Resampler {

private:
	unsigned int m_channels;
	unsigned int m_in_sample_rate, m_out_sample_rate;

	soxr_t m_soxr;

	TempBuffer m_in_data;
	TempBuffer m_out_data;

public:
	Resampler();
	~Resampler();
	void Resample(unsigned int channels,
				  unsigned int in_sample_rate, unsigned int in_sample_count, const uint8_t* in_data, AVSampleFormat in_format,
				  unsigned int out_sample_rate, unsigned int* out_sample_count, const uint8_t** out_data, AVSampleFormat out_format);

};
