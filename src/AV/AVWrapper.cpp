/*
Copyright (c) 2012-2014 Maarten Baert <maarten-baert@hotmail.com>

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

#include "Global.h"
#include "AVWrapper.h"

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

class AVGlobal {
public:
	AVGlobal() {
		av_register_all();
		av_lockmgr_register(&lock_manager);
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
#if SSR_USE_AV_FRAME_FREE
	av_frame_free(&m_frame);
#elif SSR_USE_AVCODEC_FREE_FRAME
	avcodec_free_frame(&m_frame);
#else
	av_free(m_frame);
#endif
}

AVPacketWrapper::AVPacketWrapper() {
	m_free_on_destruct = true;
	av_init_packet(&m_packet);
	m_packet.data = NULL;
	m_packet.size = 0;
}

AVPacketWrapper::AVPacketWrapper(size_t size) {
	m_free_on_destruct = true;
	if(av_new_packet(&m_packet, size) != 0)
		throw std::bad_alloc();
}

AVPacketWrapper::~AVPacketWrapper() {
	if(m_free_on_destruct)
		av_free_packet(&m_packet);
}

bool AVFormatIsInstalled(const QString& format_name) {
	return (av_guess_format(format_name.toUtf8().constData(), NULL, NULL) != NULL);
}

bool AVCodecIsInstalled(const QString& codec_name) {
	return (avcodec_find_encoder_by_name(codec_name.toUtf8().constData()) != NULL);
}

bool AVCodecSupportsPixelFormat(const AVCodec* codec, PixelFormat pixel_fmt) {
	const PixelFormat *p = codec->pix_fmts;
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
