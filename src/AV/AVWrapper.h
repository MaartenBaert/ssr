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

#if !SSR_USE_AV_CODEC_ID
#define AV_CODEC_ID_NONE CODEC_ID_NONE
#endif

#if !SSR_USE_AV_PIX_FMT
#define AVPixelFormat PixelFormat
#define AV_PIX_FMT_NONE PIX_FMT_NONE
#define AV_PIX_FMT_PAL8 PIX_FMT_PAL8
#define AV_PIX_FMT_RGB565 PIX_FMT_RGB565
#define AV_PIX_FMT_RGB555 PIX_FMT_RGB555
#define AV_PIX_FMT_BGR24 PIX_FMT_BGR24
#define AV_PIX_FMT_RGB24 PIX_FMT_RGB24
#define AV_PIX_FMT_BGRA PIX_FMT_BGRA
#define AV_PIX_FMT_RGBA PIX_FMT_RGBA
#define AV_PIX_FMT_ABGR PIX_FMT_ABGR
#define AV_PIX_FMT_ARGB PIX_FMT_ARGB
#define AV_PIX_FMT_YUV420P PIX_FMT_YUV420P
#define AV_PIX_FMT_YUV422P PIX_FMT_YUV422P
#define AV_PIX_FMT_YUV444P PIX_FMT_YUV444P
#define AV_PIX_FMT_NV12 PIX_FMT_NV12
#define AV_PIX_FMT_YUYV422 PIX_FMT_YUYV422
#endif

#if !SSR_USE_AV_CODEC_CAP
#define AV_CODEC_CAP_DELAY CODEC_CAP_DELAY
#define AV_CODEC_CAP_EXPERIMENTAL CODEC_CAP_EXPERIMENTAL
#define AV_CODEC_CAP_VARIABLE_FRAME_SIZE CODEC_CAP_VARIABLE_FRAME_SIZE
#endif

#if !SSR_USE_AV_CODEC_FLAG
#define AV_CODEC_FLAG_GLOBAL_HEADER CODEC_FLAG_GLOBAL_HEADER
#define AV_CODEC_FLAG_QSCALE CODEC_FLAG_QSCALE
#endif

// A trivial class that holds (aligned) frame data. This makes it easy to implement reference counting through std::shared_ptr.
class AVFrameData {
private:
	uint8_t *m_data;
	size_t m_size;
public:
	inline AVFrameData(size_t size) {
		m_data = (uint8_t*) av_malloc(size);
		if(m_data == NULL)
			throw std::bad_alloc();
		m_size = size;
	}
	inline ~AVFrameData() {
		av_free(m_data);
	}
	inline uint8_t* GetData() {
		return m_data;
	}
	inline size_t GetSize() {
		return m_size;
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

#if SSR_USE_AVCODEC_SEND_RECEIVE
	// This function transfers ownership of the data to the AVFrame, and then releases ownership of the AVFrame itself.
	// This turns the AVFrame into a stand-alone object which relies on the ffmpeg/libav reference counting mechanism to free the data.
	// The returned frame should be freed with av_frame_free.
	AVFrame* Release();
#endif

public:
	inline AVFrame* GetFrame() { return m_frame; }
	inline uint8_t* GetRawData() { return m_refcounted_data->GetData(); }
	inline std::shared_ptr<AVFrameData> GetFrameData() { return m_refcounted_data; }

};

// A wrapper around AVPacket to manage memory allocation. There is no copying or reference counting in this case.
class AVPacketWrapper {

private:
	AVPacket *m_packet;
#if !SSR_USE_AV_PACKET_ALLOC
	bool m_free_on_destruct;
#endif

public:
	AVPacketWrapper();
	AVPacketWrapper(size_t size);
	~AVPacketWrapper();

	AVPacketWrapper(const AVPacketWrapper&) = delete;
	AVPacketWrapper& operator=(const AVPacketWrapper&) = delete;

public:
	inline AVPacket* GetPacket() { return m_packet; }
	inline void SetFreeOnDestruct(bool free_on_destruct) {
#if !SSR_USE_AV_PACKET_ALLOC
		m_free_on_destruct = free_on_destruct;
#endif
	}

};

bool AVFormatIsInstalled(const QString& format_name);
bool AVCodecIsInstalled(const QString& codec_name);
bool AVCodecSupportsPixelFormat(const AVCodec* codec, AVPixelFormat pixel_fmt);
bool AVCodecSupportsSampleFormat(const AVCodec* codec, AVSampleFormat sample_fmt);

#if !SSR_USE_AV_CODEC_IS_ENCODER
inline int av_codec_is_encoder(const AVCodec* codec) {
	return (codec != NULL && (codec->encode != NULL || codec->encode2 != NULL));
}
#endif
