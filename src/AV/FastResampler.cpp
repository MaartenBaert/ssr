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

#include "FastResampler.h"

#include "Logger.h"
#include "CPUFeatures.h"

/*
This resampler is based on the resampling algorithm described here:
https://ccrma.stanford.edu/~jos/resample/resample.html
The Speex resampler (a.k.a. Public Parrot Hack) uses almost the same algorithm.

This implementation tries to find a balance between performance and quality. The quality is comparable to
quality level 3 of the Speex resampler, however this implementation is roughly 3 times faster
(mostly because of the SSE2-optimized floating point code).

This resampler can handle non-fractional resampling ratios and is suitable for drift correction, but it is not a
full variable-rate resampler though: the filter coefficients are calculated for one specific resampling ratio,
independent of the drift ratio. The resampling ratio can be changed, but this will result in a small glitch.
The drift ratio can be changed at any time without introducing glitches, but since the filter coefficients won't be updated,
large drift ratios will result in aliasing (at least for downsampling). It is not meant for corrections larger than a few percent.
*/

// Kaiser window function (beta = 7)
// Stats for sinc filter with length 44:
// - best cutoff = 0.9060 * nyquist_freq
// - minimum stopband attenuation = 71.97 dB
// - average stopband attenuation = 87.92 dB
#define KAISER7_TABLE_LENGTH 64
float kaiser7_table[67] = {
	0.99920941f, 1.00000000f, 0.99920941f, 0.99684085f, 0.99290397f, 0.98741477f, 0.98039552f, 0.97187462f,
	0.96188648f, 0.95047123f, 0.93767458f, 0.92354751f, 0.90814596f, 0.89153054f, 0.87376619f, 0.85492177f,
	0.83506970f, 0.81428555f, 0.79264763f, 0.77023650f, 0.74713462f, 0.72342583f, 0.69919492f, 0.67452719f,
	0.64950799f, 0.62422230f, 0.59875427f, 0.57318683f, 0.54760127f, 0.52207683f, 0.49669039f, 0.47151607f,
	0.44662491f, 0.42208462f, 0.39795925f, 0.37430898f, 0.35118989f, 0.32865378f, 0.30674805f, 0.28551550f,
	0.26499434f, 0.24521804f, 0.22621536f, 0.20801032f, 0.19062228f, 0.17406592f, 0.15835140f, 0.14348447f,
	0.12946657f, 0.11629501f, 0.10396318f, 0.09246071f, 0.08177374f, 0.07188512f, 0.06277467f, 0.05441946f,
	0.04679404f, 0.03987076f, 0.03362001f, 0.02801054f, 0.02300971f, 0.01858379f, 0.01469823f, 0.01131792f,
	0.00840746f, 0.00593141f, 0.00000000f,
};

// filter properties
#define FILTER_BASE_LENGTH  44.0f    // typical number of zero crossings for sinc filter
#define FILTER_BASE_SETS    256.0f   // typical number of filter samples per zero crossing
#define FILTER_CUTOFF       0.9060f  // bandwidth of sinc filter (relative to lowest Nyquist frequency)

// This function calculates window function values based on cubic interpolation (Catmull-Rom spline).
inline float WindowFunction(float* table, unsigned int table_length, float x) {
	x = fabs(x * (float) table_length);
	unsigned int index = (int) x; // float-to-int cast is faster than float-to-uint
	if(index >= table_length) {
		return 0.0f;
	} else {
		float *val = table + index;
		float t = x - (float) index, s = 1.0f - t;
		return s * s * (s * val[1] + t * (val[1] * 3.0f + (val[2] - val[0]) * 0.5f))
			 + t * t * (t * val[2] + s * (val[2] * 3.0f + (val[1] - val[3]) * 0.5f));
	}
}

// sinc function = sin(x*pi)/(x*pi)
inline float Sinc(float x) {
	if(fabs(x) < 0.0001f)
		return 1.0f;
	x *= (float) M_PI;
	return sinf(x) / x;
}

FastResampler::FastResampler(unsigned int channels, float gain) {
	assert(channels != 0);

	// settings
	m_channels = channels;
	m_gain = gain;
	m_resample_ratio = 0.0;
	m_drift_ratio = 0.0;

	// filter coefficient sets
	m_filter_length = 0;
	m_filter_rows = 0;

	// CPU feature detection
#if SSR_USE_X86_ASM
	if(CPUFeatures::HasMMX() && CPUFeatures::HasSSE() && CPUFeatures::HasSSE2()) {
		switch(m_channels) {
			case 1:  m_firfilter2_ptr = &FastResampler_FirFilter2_C1_SSE2; break;
			case 2:  m_firfilter2_ptr = &FastResampler_FirFilter2_C2_SSE2; break;
			default: m_firfilter2_ptr = &FastResampler_FirFilter2_Cn_SSE2; break;
		}
	} else {
#endif
		switch(m_channels) {
			case 1:  m_firfilter2_ptr = &FastResampler_FirFilter2_C1_Fallback; break;
			case 2:  m_firfilter2_ptr = &FastResampler_FirFilter2_C2_Fallback; break;
			default: m_firfilter2_ptr = &FastResampler_FirFilter2_Cn_Fallback; break;
		}
#if SSR_USE_X86_ASM
	}
#endif

}

unsigned int FastResampler::Resample(double resample_ratio, double drift_ratio, const float* samples_in, unsigned int sample_count_in, TempBuffer<float>* samples_out, unsigned int sample_offset_out) {

	// check the resampling ratio
	if(resample_ratio < 1.0e-3 || resample_ratio > 1.0e3) {
		Logger::LogError("[FastResampler::Resample] " + Logger::tr("Error: Resample ratio is out of range!"));
		throw ResamplerException();
	}
	if(drift_ratio < 1.0e-1 || drift_ratio > 1.0e1) {
		Logger::LogError("[FastResampler::Resample] " + Logger::tr("Error: Drift ratio is out of range!"));
		throw ResamplerException();
	}

	// should we flush old samples first?
	if((m_resample_ratio != resample_ratio || samples_in == NULL) && m_filter_length != 0) {

		// pad with zero samples
		unsigned int pad = m_filter_length / 2 * m_channels;
		std::fill_n(m_samples_memory.Reserve(pad), pad, 0.0f);
		m_samples_memory.Push(pad);

		// reserve memory (with some margin since floating-point isn't 100% accurate)
		unsigned int available = m_samples_memory.GetSize() / m_channels;
		samples_out->Alloc((sample_offset_out + (unsigned int) lrint((double) available / (m_resample_ratio * m_drift_ratio) * 1.001) + 4) * m_channels, (sample_offset_out != 0));

		// resample
		std::pair<unsigned int, unsigned int> done = ResampleBatch(m_samples_memory.GetData(), available, samples_out->GetData() + sample_offset_out * m_channels);
		sample_offset_out += done.second;

	}

	// is there new input data?
	if(samples_in == NULL) {
		ResetResamplerState();
		return sample_offset_out;
	}

	// update filter if the resample ratio changes
	if(m_resample_ratio != resample_ratio) {
		Logger::LogInfo("[FastResampler::Resample] " + Logger::tr("Resample ratio is %1 (was %2).").arg(resample_ratio, 0, 'f', 4).arg(m_resample_ratio, 0, 'f', 4));
		m_resample_ratio = resample_ratio;
		UpdateFilterCoefficients();
		ResetResamplerState();
	}
	m_drift_ratio = drift_ratio;

	// save input samples
	m_samples_memory.Push(samples_in, sample_count_in * m_channels);

	// resample one batch at a time
	for( ; ; ) {

		// reserve memory (with some margin since floating-point isn't 100% accurate)
		unsigned int available = m_samples_memory.GetSize() / m_channels;
		unsigned int batch = std::min(available, m_filter_length * 256); // needs to be limited to avoid some numerical problems
		samples_out->Alloc((sample_offset_out + (unsigned int) lrint((double) batch / (m_resample_ratio * m_drift_ratio) * 1.001) + 4) * m_channels, (sample_offset_out != 0));

		// resample
		std::pair<unsigned int, unsigned int> done = ResampleBatch(m_samples_memory.GetData(), batch, samples_out->GetData() + sample_offset_out * m_channels);
		m_samples_memory.Pop(done.first * m_channels);
		sample_offset_out += done.second;

		// is this the last batch?
		if(batch == available)
			break;

	}

	return sample_offset_out;
}

double FastResampler::GetInputLatency() {
	if(m_filter_length == 0)
		return 0.0;
	int samples_left = (int) (m_samples_memory.GetSize() / m_channels) - (int) (m_filter_length / 2 - 1);
	return (double) samples_left - m_time / (double) m_filter_rows;
}

double FastResampler::GetOutputLatency() {
	if(m_filter_length == 0)
		return 0.0;
	return GetInputLatency() / (m_resample_ratio * m_drift_ratio);
}

void FastResampler::UpdateFilterCoefficients() {

	// calculate filter parameters
	float filter_cutoff = FILTER_CUTOFF / (float) fmax(1.0, m_resample_ratio);
	m_filter_length = lrint(FILTER_BASE_LENGTH / filter_cutoff * 0.25f) * 4;
	m_filter_rows = std::max(1u, (unsigned int) lrint(FILTER_BASE_SETS * filter_cutoff));

	// allocate memory for coefficients
	m_filter_coefficients.Alloc(m_filter_length * (m_filter_rows + 1));

	// generate coefficients
	float *coef = m_filter_coefficients.GetData();
	float window = 1.0f / (float) (m_filter_length / 2);
	for(unsigned int j = 0; j <= m_filter_rows; ++j) {
		float shift = 1.0f - (float) j / (float) m_filter_rows - (float) (m_filter_length / 2);
		for(unsigned int i = 0; i < m_filter_length; ++i) {
			float x = (float) i + shift;
			*(coef++) = WindowFunction(kaiser7_table, KAISER7_TABLE_LENGTH, x * window) * Sinc(x * filter_cutoff) * filter_cutoff * m_gain;
		}
	}

}

void FastResampler::ResetResamplerState() {
	m_time = 0.0;
	m_samples_memory.Clear();
	unsigned int pad = (m_filter_length / 2 - 1) * m_channels;
	std::fill_n(m_samples_memory.Reserve(pad), pad, 0.0f);
	m_samples_memory.Push(pad);
}

std::pair<unsigned int, unsigned int> FastResampler::ResampleBatch(float* samples_in, unsigned int sample_count_in, float* samples_out) {

	// prepare for resampling
	double step = (double) m_filter_rows * m_resample_ratio * m_drift_ratio;

	// actual resampling
	unsigned int output_samples = 0;
	for( ; ; ) {

		// calculate the input sample and filter row
		unsigned int index = (int) m_time; // float-to-int cast is faster than float-to-uint
		unsigned int sample = index / m_filter_rows, row = index % m_filter_rows;

		// do we have the required input samples?
		if(sample + m_filter_length > sample_count_in) {
			unsigned int input_samples = std::min(sample_count_in, sample);
			m_time -= input_samples * m_filter_rows;
			return std::make_pair(input_samples, output_samples);
		}

		// calculate the next sample
		float *coef1 = m_filter_coefficients.GetData() + m_filter_length * row;
		float *coef2 = coef1 + m_filter_length;
		float frac = m_time - (double) index;
		float *input = samples_in + sample * m_channels;
		m_firfilter2_ptr(m_channels, m_filter_length, coef1, coef2, frac, input, samples_out);
		samples_out += m_channels;
		++output_samples;

		// increase the time
		m_time += step;

	}

}
