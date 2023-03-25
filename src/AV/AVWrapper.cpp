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

#include "AVWrapper.h"

#if !SSR_USE_AV_LOCKMGR_REGISTER_DEPRECATED
int lock_manager(void** m, AVLockOp op) {
	std::mutex *&mutex = *(std::mutex**) m;
	switch(op) {
		case AV_LOCK_CREATE: mutex = new std::mutex(); break;
		case AV_LOCK_DESTROY: delete mutex; break;
		case AV_LOCK_OBTAIN: mutex->lock(); break;
		case AV_LOCK_RELEASE: mutex->unlock(); break;
	}
	return 0;
}
#endif

void DeleteFrameDataPointer(void* opaque, uint8_t* data) {
	Q_UNUSED(data);
	std::shared_ptr<AVFrameData> *ptr = (std::shared_ptr<AVFrameData>*) opaque;
	delete ptr;
}

class AVGlobal {
public:
	AVGlobal() {
#if !SSR_USE_AV_REGISTER_ALL_DEPRECATED
		av_register_all();
#endif
#if !SSR_USE_AV_LOCKMGR_REGISTER_DEPRECATED
		av_lockmgr_register(&lock_manager);
#endif
#if SSR_USE_AVFORMAT_NETWORK_INIT
		avformat_network_init();
#endif
	}
} g_av_global;

AVFrameWrapper::AVFrameWrapper(const std::shared_ptr<AVFrameData>& refcounted_data) {
	m_refcounted_data = refcounted_data;
#if SSR_USE_AV_FRAME_ALLOC
	m_frame = av_frame_alloc();
#else
	m_frame = avcodec_alloc_frame();
#endif
	if(m_frame == NULL)
		std::bad_alloc();
#if SSR_USE_AVFRAME_EXTENDED_DATA
	// ffmpeg docs say that extended_data should point to data if it isn't used
	m_frame->extended_data = m_frame->data;
#endif
}

AVFrameWrapper::~AVFrameWrapper() {
	if(m_frame != NULL) {
#if SSR_USE_AV_FRAME_FREE
		av_frame_free(&m_frame);
#elif SSR_USE_AVCODEC_FREE_FRAME
		avcodec_free_frame(&m_frame);
#else
		av_free(m_frame);
#endif
	}
}

#if SSR_USE_AVCODEC_SEND_RECEIVE
AVFrame* AVFrameWrapper::Release() {
	assert(m_frame != NULL);
	std::shared_ptr<AVFrameData> *ptr = new std::shared_ptr<AVFrameData>(m_refcounted_data);
	m_frame->buf[0] = av_buffer_create(m_refcounted_data->GetData(), m_refcounted_data->GetSize(), &DeleteFrameDataPointer, ptr, AV_BUFFER_FLAG_READONLY);
	if(m_frame->buf[0] == NULL) {
		delete ptr;
		throw std::bad_alloc();
	}
	AVFrame *frame = m_frame;
	m_frame = NULL;
	return frame;
}
#endif

AVPacketWrapper::AVPacketWrapper() {
#if SSR_USE_AV_PACKET_ALLOC
	m_packet = av_packet_alloc();
	if(m_packet == NULL)
		std::bad_alloc();
#else
	m_packet = new AVPacket;
	m_free_on_destruct = true;
	av_init_packet(m_packet);
	m_packet->data = NULL;
	m_packet->size = 0;
#endif
}

AVPacketWrapper::AVPacketWrapper(size_t size) {
#if SSR_USE_AV_PACKET_ALLOC
	m_packet = av_packet_alloc();
	if(m_packet == NULL)
		std::bad_alloc();
#else
	m_packet = new AVPacket;
	m_free_on_destruct = true;
#endif
	if(av_new_packet(m_packet, size) != 0)
		throw std::bad_alloc();
}

AVPacketWrapper::~AVPacketWrapper() {
#if SSR_USE_AV_PACKET_ALLOC
	// This isn't documented anywhere (as usual) and the FFmpeg examples haven't been updated to their latest API yet,
	// but my guess is that it is safe to call this function even if the data has also been sent to the muxer,
	// because the internal reference counting in FFmpeg should ensure that the data is not deleted when it is still needed.
	// This wasn't the case with their old API which didn't do reference counting yet.
	av_packet_free(&m_packet);
#else
	if(m_free_on_destruct)
		av_free_packet(m_packet);
	delete m_packet;
#endif
}

bool AVFormatIsInstalled(const QString& format_name) {
	return (av_guess_format(format_name.toUtf8().constData(), NULL, NULL) != NULL);
}

bool AVCodecIsInstalled(const QString& codec_name) {
	return (avcodec_find_encoder_by_name(codec_name.toUtf8().constData()) != NULL);
}

bool AVCodecSupportsPixelFormat(const AVCodec* codec, AVPixelFormat pixel_fmt) {
	const AVPixelFormat *p = codec->pix_fmts;
	if(p == NULL)
		return true; // NULL means 'unknown' or 'any', assume it is supported
	while(*p != AV_PIX_FMT_NONE) {
		if(*p == pixel_fmt)
			return true;
		++p;
	}
	return false;
}

bool AVCodecSupportsSampleFormat(const AVCodec* codec, AVSampleFormat sample_fmt) {
	const AVSampleFormat *p = codec->sample_fmts;
	if(p == NULL)
		return true; // NULL means 'unknown' or 'any', assume it is supported
	while(*p != AV_SAMPLE_FMT_NONE) {
		if(*p == sample_fmt)
			return true;
		++p;
	}
	return false;
}
