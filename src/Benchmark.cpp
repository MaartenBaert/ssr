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

#include "Benchmark.h"

#include "AVWrapper.h"
#include "CPUFeatures.h"
#include "FastScaler_Convert.h"
#include "FastScaler_Scale.h"
#include "Logger.h"
#include "TempBuffer.h"

#include <random>

struct ImageGeneric {

	TempBuffer<uint8_t> m_buffer;
	std::vector<uint8_t*> m_data;
	std::vector<int> m_stride;

	ImageGeneric(const std::vector<unsigned int>& stride, const std::vector<unsigned int>& rows, std::mt19937& rng) {

		// count planes
		assert(stride.size() == rows.size());
		unsigned int planes = stride.size();
		m_data.resize(planes);
		m_stride.resize(planes);

		// calculate stride and total size
		size_t totalsize = 0;
		for(unsigned int p = 0; p < planes; ++p) {
			m_stride[p] = grow_align16(stride[p]);
			totalsize += m_stride[p] * rows[p];
		}

		// allocate buffer
		m_buffer.Alloc(totalsize);
		for(unsigned int i = 0; i < totalsize; ++i) {
			m_buffer[i] = rng();
		}

		// set data
		uint8_t *data = m_buffer.GetData();
		for(unsigned int p = 0; p < planes; ++p) {
			m_data[p] = data;
			data += m_stride[p] * rows[p];
		}

	}

};

std::unique_ptr<ImageGeneric> NewImageBGRA(unsigned int w, unsigned int h, std::mt19937& rng) {
	return std::unique_ptr<ImageGeneric>(new ImageGeneric({w * 4}, {h}, rng));
}
std::unique_ptr<ImageGeneric> NewImageYUV444(unsigned int w, unsigned int h, std::mt19937& rng) {
	return std::unique_ptr<ImageGeneric>(new ImageGeneric({w, w, w}, {h, h, h}, rng));
}
std::unique_ptr<ImageGeneric> NewImageYUV422(unsigned int w, unsigned int h, std::mt19937& rng) {
	return std::unique_ptr<ImageGeneric>(new ImageGeneric({w, w / 2, w / 2}, {h, h, h}, rng));
}
std::unique_ptr<ImageGeneric> NewImageYUV420(unsigned int w, unsigned int h, std::mt19937& rng) {
	return std::unique_ptr<ImageGeneric>(new ImageGeneric({w, w / 2, w / 2}, {h, h / 2, h / 2}, rng));
}
std::unique_ptr<ImageGeneric> NewImageNV12(unsigned int w, unsigned int h, std::mt19937& rng) {
	return std::unique_ptr<ImageGeneric>(new ImageGeneric({w, w}, {h, h / 2}, rng));
}
std::unique_ptr<ImageGeneric> NewImageBGR(unsigned int w, unsigned int h, std::mt19937& rng) {
	return std::unique_ptr<ImageGeneric>(new ImageGeneric({w * 3}, {h}, rng));
}

typedef std::unique_ptr<ImageGeneric> (*NewImageFunc)(unsigned int, unsigned int, std::mt19937&);
typedef void (*ConvertFunc)(unsigned int, unsigned int, const uint8_t*, int, uint8_t* const*, const int*);

template<void (*T)(unsigned int, unsigned int, const uint8_t*, int, uint8_t*, int)>
void PlaneWrapper(unsigned int w, unsigned int h, const uint8_t* in_data, int in_stride, uint8_t* const* out_data, const int* out_stride) {
	T(w, h, in_data, in_stride, out_data[0], out_stride[0]);
}

void BenchmarkScale(unsigned int in_w, unsigned int in_h, unsigned int out_w, unsigned int out_h) {

	std::mt19937 rng(12345);
#if SSR_USE_X86_ASM
	bool use_ssse3 = (CPUFeatures::HasMMX() && CPUFeatures::HasSSE() && CPUFeatures::HasSSE2() && CPUFeatures::HasSSE3() && CPUFeatures::HasSSSE3());
#endif

	// the queue needs to use enough memory to make sure that the CPU cache is flushed
	unsigned int pixels = std::max(in_w * in_h, out_w * out_h);
	unsigned int queue_size = 1 + 20000000 / pixels;
	unsigned int run_size = queue_size * 20;

	// create queue
	std::vector<std::unique_ptr<ImageGeneric> > queue_in(queue_size);
	std::vector<std::unique_ptr<ImageGeneric> > queue_out(queue_size);
	for(unsigned int i = 0; i < queue_size; ++i) {
		queue_in[i] = NewImageBGRA(in_w, in_h, rng);
		queue_out[i] = NewImageBGRA(out_w, out_h, rng);
	}

	// run test
	unsigned int time_swscale = 0, time_fallback = 0, time_ssse3 = 0;
	{
		SwsContext *sws = sws_getCachedContext(NULL,
											   in_w, in_h, AV_PIX_FMT_BGRA,
											   out_w, out_h, AV_PIX_FMT_BGRA,
											   SWS_BILINEAR, NULL, NULL, NULL);
		if(sws == NULL) {
			Logger::LogError("[BenchmarkScale] " + Logger::tr("Error: Can't get swscale context!", "Don't translate 'swscale'"));
			throw LibavException();
		}
		sws_setColorspaceDetails(sws,
								 sws_getCoefficients(SWS_CS_ITU709), 0,
								 sws_getCoefficients(SWS_CS_DEFAULT), 0,
								 0, 1 << 16, 1 << 16);
		int64_t t1 = hrt_time_micro();
		for(unsigned int i = 0; i < run_size / 2; ++i) {
			unsigned int ii = i % queue_size;
			sws_scale(sws, queue_in[ii]->m_data.data(), queue_in[ii]->m_stride.data(), 0, in_h, queue_out[ii]->m_data.data(), queue_out[ii]->m_stride.data());
		}
		int64_t t2 = hrt_time_micro();
		time_swscale = (t2 - t1) / (run_size / 2);
	}
	{
		int64_t t1 = hrt_time_micro();
		for(unsigned int i = 0; i < run_size; ++i) {
			unsigned int ii = i % queue_size;
			Scale_BGRA_Fallback(in_w, in_h, queue_in[ii]->m_data[0], queue_in[ii]->m_stride[0],
								out_w, out_h, queue_out[ii]->m_data[0], queue_out[ii]->m_stride[0]);
		}
		int64_t t2 = hrt_time_micro();
		time_fallback = (t2 - t1) / run_size;
	}
#if SSR_USE_X86_ASM
	if(use_ssse3) {
		int64_t t1 = hrt_time_micro();
		for(unsigned int i = 0; i < run_size; ++i) {
			unsigned int ii = i % queue_size;
			Scale_BGRA_SSSE3(in_w, in_h, queue_in[ii]->m_data[0], queue_in[ii]->m_stride[0],
							 out_w, out_h, queue_out[ii]->m_data[0], queue_out[ii]->m_stride[0]);
		}
		int64_t t2 = hrt_time_micro();
		time_ssse3 = (t2 - t1) / run_size;
	}
#endif

	// print result
	QString in_size = QString("%1x%2").arg(in_w).arg(in_h);
	QString out_size = QString("%1x%2").arg(out_w).arg(out_h);
	Logger::LogInfo("[BenchmarkScale] " + Logger::tr("BGRA %1 to BGRA %2  |  SWScale %3 us  |  Fallback %4 us (%5%)  |  SSSE3 %6 us (%7%)")
					.arg(in_size, 9).arg(out_size, 9)
					.arg(time_swscale, 6)
					.arg(time_fallback, 6).arg(100 * time_fallback / time_swscale, 3)
					.arg(time_ssse3, 6).arg(100 * time_ssse3 / time_fallback, 3));

}

void BenchmarkConvert(unsigned int w, unsigned int h, AVPixelFormat in_format, AVPixelFormat out_format, const QString& in_format_name, const QString& out_format_name, NewImageFunc in_image, NewImageFunc out_image, ConvertFunc fallback
#if SSR_USE_X86_ASM
, ConvertFunc ssse3
#endif
) {

	std::mt19937 rng(12345);
#if SSR_USE_X86_ASM
	bool use_ssse3 = (CPUFeatures::HasMMX() && CPUFeatures::HasSSE() && CPUFeatures::HasSSE2() && CPUFeatures::HasSSE3() && CPUFeatures::HasSSSE3());
#endif

	// the queue needs to use enough memory to make sure that the CPU cache is flushed
	unsigned int pixels = w * h;
	unsigned int queue_size = 1 + 20000000 / pixels;
	unsigned int run_size = queue_size * 20;

	// create queue
	std::vector<std::unique_ptr<ImageGeneric> > queue_in(queue_size);
	std::vector<std::unique_ptr<ImageGeneric> > queue_out(queue_size);
	for(unsigned int i = 0; i < queue_size; ++i) {
		queue_in[i] = in_image(w, h, rng);
		queue_out[i] = out_image(w, h, rng);
	}

	// run test
	unsigned int time_swscale = 0, time_fallback = 0, time_ssse3 = 0;
	{
		SwsContext *sws = sws_getCachedContext(NULL,
											   w, h, in_format,
											   w, h, out_format,
											   SWS_BILINEAR, NULL, NULL, NULL);
		if(sws == NULL) {
			Logger::LogError("[BenchmarkScale] " + Logger::tr("Error: Can't get swscale context!", "Don't translate 'swscale'"));
			throw LibavException();
		}
		sws_setColorspaceDetails(sws,
								 sws_getCoefficients(SWS_CS_ITU709), 0,
								 sws_getCoefficients(SWS_CS_DEFAULT), 0,
								 0, 1 << 16, 1 << 16);
		int64_t t1 = hrt_time_micro();
		for(unsigned int i = 0; i < run_size / 2; ++i) {
			unsigned int ii = i % queue_size;
			sws_scale(sws, queue_in[ii]->m_data.data(), queue_in[ii]->m_stride.data(), 0, h, queue_out[ii]->m_data.data(), queue_out[ii]->m_stride.data());
		}
		int64_t t2 = hrt_time_micro();
		time_swscale = (t2 - t1) / (run_size / 2);
	}
	{
		int64_t t1 = hrt_time_micro();
		for(unsigned int i = 0; i < run_size; ++i) {
			unsigned int ii = i % queue_size;
			fallback(w, h, queue_in[ii]->m_data[0], queue_in[ii]->m_stride[0], queue_out[ii]->m_data.data(), queue_out[ii]->m_stride.data());
		}
		int64_t t2 = hrt_time_micro();
		time_fallback = (t2 - t1) / run_size;
	}
#if SSR_USE_X86_ASM
	if(use_ssse3) {
		int64_t t1 = hrt_time_micro();
		for(unsigned int i = 0; i < run_size; ++i) {
			unsigned int ii = i % queue_size;
			ssse3(w, h, queue_in[ii]->m_data[0], queue_in[ii]->m_stride[0], queue_out[ii]->m_data.data(), queue_out[ii]->m_stride.data());
		}
		int64_t t2 = hrt_time_micro();
		time_ssse3 = (t2 - t1) / run_size;
	}
#endif

	// print result
	QString size = QString("%1x%2").arg(w).arg(h);
	Logger::LogInfo("[BenchmarkConvert] " + Logger::tr("%1 %2 to %3 %4  |  SWScale %5 us  |  Fallback %6 us (%7%)  |  SSSE3 %8 us (%9%)")
					.arg(in_format_name).arg(size, 9).arg(out_format_name).arg(size, 9)
					.arg(time_swscale, 6)
					.arg(time_fallback, 6).arg(100 * time_fallback / time_swscale, 3)
					.arg(time_ssse3, 6).arg(100 * time_ssse3 / time_fallback, 3));

}

void Benchmark() {

	Logger::LogInfo("[Benchmark] " + Logger::tr("Starting scaler benchmark ..."));
	BenchmarkScale(1920, 1080, 1920, 1080); // direct copy
	BenchmarkScale(1280, 720, 1920, 1080); // upscaling
	BenchmarkScale(1920, 1080, 1280, 720); // downscaling
	BenchmarkScale(1920, 1080, 960, 540); // pure mipmap
	BenchmarkScale(1920, 1080, 640, 360); // mipmap + downscaling

	Logger::LogInfo("[Benchmark] " + Logger::tr("Starting converter benchmark ..."));
#if SSR_USE_X86_ASM
	BenchmarkConvert(1920, 1080, AV_PIX_FMT_BGRA, AV_PIX_FMT_YUV444P, "BGRA", "YUV444", NewImageBGRA, NewImageYUV444, Convert_BGRA_YUV444_Fallback           , Convert_BGRA_YUV444_SSSE3           );
	BenchmarkConvert(1920, 1080, AV_PIX_FMT_BGRA, AV_PIX_FMT_YUV422P, "BGRA", "YUV422", NewImageBGRA, NewImageYUV422, Convert_BGRA_YUV422_Fallback           , Convert_BGRA_YUV422_SSSE3           );
	BenchmarkConvert(1920, 1080, AV_PIX_FMT_BGRA, AV_PIX_FMT_YUV420P, "BGRA", "YUV420", NewImageBGRA, NewImageYUV420, Convert_BGRA_YUV420_Fallback           , Convert_BGRA_YUV420_SSSE3           );
	BenchmarkConvert(1920, 1080, AV_PIX_FMT_BGRA, AV_PIX_FMT_NV12   , "BGRA", "NV12  ", NewImageBGRA, NewImageNV12  , Convert_BGRA_NV12_Fallback             , Convert_BGRA_NV12_SSSE3             );
	BenchmarkConvert(1920, 1080, AV_PIX_FMT_BGRA, AV_PIX_FMT_BGR24  , "BGRA", "BGR   ", NewImageBGRA, NewImageBGR   , PlaneWrapper<Convert_BGRA_BGR_Fallback>, PlaneWrapper<Convert_BGRA_BGR_SSSE3>);
#else
	BenchmarkConvert(1920, 1080, AV_PIX_FMT_BGRA, AV_PIX_FMT_YUV444P, "BGRA", "YUV444", NewImageBGRA, NewImageYUV444, Convert_BGRA_YUV444_Fallback           );
	BenchmarkConvert(1920, 1080, AV_PIX_FMT_BGRA, AV_PIX_FMT_YUV422P, "BGRA", "YUV422", NewImageBGRA, NewImageYUV422, Convert_BGRA_YUV422_Fallback           );
	BenchmarkConvert(1920, 1080, AV_PIX_FMT_BGRA, AV_PIX_FMT_YUV420P, "BGRA", "YUV420", NewImageBGRA, NewImageYUV420, Convert_BGRA_YUV420_Fallback           );
	BenchmarkConvert(1920, 1080, AV_PIX_FMT_BGRA, AV_PIX_FMT_NV12   , "BGRA", "NV12  ", NewImageBGRA, NewImageNV12  , Convert_BGRA_NV12_Fallback             );
	BenchmarkConvert(1920, 1080, AV_PIX_FMT_BGRA, AV_PIX_FMT_BGR24  , "BGRA", "BGR   ", NewImageBGRA, NewImageBGR   , PlaneWrapper<Convert_BGRA_BGR_Fallback>);
#endif

}
