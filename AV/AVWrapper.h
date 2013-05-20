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
#include "StdAfx.h"

class AVFrameWrapper : public AVFrame {
public:
	bool m_free_on_destruct;
#if !SSR_USE_AVFRAME_NB_SAMPLES
	int nb_samples; // we need this even if libav doesn't use it
#endif
public:
	AVFrameWrapper();
	AVFrameWrapper(size_t size);
	AVFrameWrapper(const AVFrameWrapper& other) = delete;
	AVFrameWrapper* operator=(const AVFrameWrapper& other) = delete;
	~AVFrameWrapper();
};

class AVPacketWrapper : public AVPacket {
public:
	bool m_free_on_destruct;
public:
	AVPacketWrapper();
	AVPacketWrapper(size_t size);
	AVPacketWrapper(const AVPacketWrapper& other) = delete;
	AVPacketWrapper* operator=(const AVPacketWrapper& other) = delete;
	~AVPacketWrapper();
};

bool AVFormatIsInstalled(const QString& format_name);
bool AVCodecIsInstalled(const QString& codec_name);
bool AVCodecSupportsPixelFormat(AVCodec* codec, PixelFormat pixel_fmt);
bool AVCodecSupportsSampleFormat(AVCodec* codec, AVSampleFormat sample_fmt);

#if !SSR_USE_AV_CODEC_IS_ENCODER
inline int av_codec_is_encoder(const AVCodec* codec) {
	return (codec != NULL && (codec->encode != NULL || codec->encode2 != NULL));
}
#endif
