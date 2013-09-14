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

// A trivial class that holds (aligned) frame data. This makes it easy to implement reference counting through std::shared_ptr.
class AVFrameData {
private:
	uint8_t *m_data;
public:
	inline AVFrameData(size_t size) {
		m_data = (uint8_t*) av_malloc(size);
		if(m_data == NULL)
			throw std::bad_alloc();
	}
	inline ~AVFrameData() {
		av_free(m_data);
	}
	inline uint8_t* GetData() {
		return m_data;
	}
};

// A wrapper around AVFrame to manage memory allocation and reference counting.
// Note: This reference counting mechanism is unrelated to the mechanism added in later versions of ffmpeg/libav.
class AVFrameWrapper {

private:
	AVFrame *m_frame;
	std::shared_ptr<AVFrameData> m_refcounted_data;

public:
	AVFrameWrapper(const std::shared_ptr<AVFrameData>& refcounted_data);
	~AVFrameWrapper();

	AVFrameWrapper(const AVFrameWrapper&) = delete;
	AVFrameWrapper& operator=(const AVFrameWrapper&) = delete;

public:
	inline AVFrame* GetFrame() { return m_frame; }
	inline uint8_t* GetRawData() { return m_refcounted_data->GetData(); }
	inline std::shared_ptr<AVFrameData> GetFrameData() { return m_refcounted_data; }

};

// A wrapper around AVPacket to manage memory allocation. There is no copying or reference counting in this case.
class AVPacketWrapper {

private:
	AVPacket m_packet;
	bool m_free_on_destruct;

public:
	AVPacketWrapper();
	AVPacketWrapper(size_t size);
	~AVPacketWrapper();

	AVPacketWrapper(const AVPacketWrapper&) = delete;
	AVPacketWrapper& operator=(const AVPacketWrapper&) = delete;

public:
	inline AVPacket* GetPacket() { return &m_packet; }
	inline void SetFreeOnDestruct(bool free_on_destruct) { m_free_on_destruct = free_on_destruct; }

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
