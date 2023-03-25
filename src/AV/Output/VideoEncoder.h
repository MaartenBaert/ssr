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

#include "BaseEncoder.h"

class VideoEncoder : public BaseEncoder {

private:
	struct PixelFormatData {
		QString m_name;
		AVPixelFormat m_format;
		bool m_is_yuv;
	};

private:
	static const std::vector<PixelFormatData> SUPPORTED_PIXEL_FORMATS;

private:
#if !SSR_USE_AVCODEC_ENCODE_VIDEO2
	std::vector<uint8_t> m_temp_buffer;
#endif

public:
	VideoEncoder(Muxer* muxer, AVStream* stream, AVCodecContext* codec_context, AVCodec* codec, AVDictionary** options);
	~VideoEncoder();

	// Returns the required pixel format.
	AVPixelFormat GetPixelFormat();
	
	// Returns the required color space.
	int GetColorSpace();

	unsigned int GetWidth();
	unsigned int GetHeight();
	unsigned int GetFrameRate();

public:
	static bool AVCodecIsSupported(const QString& codec_name);
	static void PrepareStream(AVStream* stream, AVCodecContext* codec_context, AVCodec* codec, AVDictionary** options, const std::vector<std::pair<QString, QString> >& codec_options,
							  unsigned int bit_rate, unsigned int width, unsigned int height, unsigned int frame_rate);

private:
	virtual bool EncodeFrame(AVFrameWrapper* frame) override;

};
