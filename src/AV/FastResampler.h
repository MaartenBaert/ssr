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
#include "TempBuffer.h"
#include "QueueBuffer.h"

#include "FastResampler_FirFilter.h"

#include <utility>

class FastResampler {

private:
#if SSR_USE_X86_ASM
	// CPU feature detection
	bool m_use_sse2;
#endif

	// settings
	unsigned int m_channels;
	float m_gain;
	double m_resample_ratio, m_drift_ratio;

	// filter coefficient sets
	unsigned int m_filter_length, m_filter_rows;
	TempBuffer<float> m_filter_coefficients;

	// resampler state
	double m_time;
	QueueBuffer<float> m_samples_memory;

	// function pointers
	FirFilter2Ptr m_firfilter2_ptr;

public:
	FastResampler(unsigned int channels, float gain);

	// Processes input audio and writes the resampled audio to a queue. 'samples_in' can be NULL to flush the resampler.
	unsigned int Resample(double resample_ratio, double drift_ratio, const float* samples_in, unsigned int sample_count_in, TempBuffer<float>* samples_out, unsigned int sample_offset_out);

	// Returns the total resampler latency in input samples.
	double GetInputLatency();

	// Returns the total resampler latency in output samples.
	double GetOutputLatency();

private:
	void UpdateFilterCoefficients();
	void ResetResamplerState();

	std::pair<unsigned int, unsigned int> ResampleBatch(float* samples_in, unsigned int sample_count_in, float* samples_out);

};
