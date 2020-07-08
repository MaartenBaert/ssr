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

#include "VideoEncoder.h"

#include "Logger.h"
#include "AVWrapper.h"
#include "Muxer.h"
#include "X264Presets.h"

const std::vector<VideoEncoder::PixelFormatData> VideoEncoder::SUPPORTED_PIXEL_FORMATS = {
	{"nv12", AV_PIX_FMT_NV12, true},
	{"yuv420", AV_PIX_FMT_YUV420P, true},
	{"yuv422", AV_PIX_FMT_YUV422P, true},
	{"yuv444", AV_PIX_FMT_YUV444P, true},
	{"bgra", AV_PIX_FMT_BGRA, false},
	{"bgr", AV_PIX_FMT_BGR24, false},
	{"rgb", AV_PIX_FMT_RGB24, false},
};

VideoEncoder::VideoEncoder(Muxer* muxer, AVStream* stream, AVCodecContext* codec_context, AVCodec* codec, AVDictionary** options)
	: BaseEncoder(muxer, stream, codec_context, codec, options) {

#if !SSR_USE_AVCODEC_ENCODE_VIDEO2
	// allocate a temporary buffer
	// Apparently libav/ffmpeg completely ignores the size of the buffer, and if it's too small it just crashes.
	// Originally it was 256k, which is large enough for about 99.9% of the packets, but it still occasionally crashes.
	// So now I'm using a buffer that's always at least large enough to hold a 256k header and *two* completely uncompressed frames.
	// (one YUV frame takes w * h * 1.5 bytes)
	// Newer versions of libav/ffmpeg have deprecated avcodec_encode_video and added a new function which does the allocation
	// automatically, just like avcodec_encode_audio2, but that function isn't available in Ubuntu 12.04/12.10 yet.
	m_temp_buffer.resize(std::max<unsigned int>(FF_MIN_BUFFER_SIZE, 256 * 1024 + GetCodecContext()->width * GetCodecContext()->height * 3));
#endif

	StartThread();
}

VideoEncoder::~VideoEncoder() {
	StopThread();
}

AVPixelFormat VideoEncoder::GetPixelFormat() {
	return GetCodecContext()->pix_fmt;
}

int VideoEncoder::GetColorSpace() {
	switch(GetCodecContext()->colorspace) {
		case AVCOL_SPC_BT709:
			return SWS_CS_ITU709;
		case AVCOL_SPC_FCC:
			return SWS_CS_FCC;
		case AVCOL_SPC_BT470BG:
			return SWS_CS_ITU601;
		case AVCOL_SPC_SMPTE170M:
			return SWS_CS_SMPTE170M;
		case AVCOL_SPC_SMPTE240M:
			return SWS_CS_SMPTE240M;
#ifdef SWS_CS_BT2020
		case AVCOL_SPC_BT2020_NCL:
		case AVCOL_SPC_BT2020_CL:
			return SWS_CS_BT2020;
#endif
		default:
			return SWS_CS_DEFAULT;
	}
}

unsigned int VideoEncoder::GetWidth() {
	return GetCodecContext()->width;
}

unsigned int VideoEncoder::GetHeight() {
	return GetCodecContext()->height;
}

unsigned int VideoEncoder::GetFrameRate() {
	assert(GetCodecContext()->time_base.num == 1);
	return GetCodecContext()->time_base.den;
}

bool VideoEncoder::AVCodecIsSupported(const QString& codec_name) {
	AVCodec *codec = avcodec_find_encoder_by_name(codec_name.toUtf8().constData());
	if(codec == NULL)
		return false;
	if(!av_codec_is_encoder(codec))
		return false;
	if(codec->type != AVMEDIA_TYPE_VIDEO)
		return false;
	for(unsigned int i = 0; i < SUPPORTED_PIXEL_FORMATS.size(); ++i) {
		if(AVCodecSupportsPixelFormat(codec, SUPPORTED_PIXEL_FORMATS[i].m_format)) {
			//qDebug() << codec_name << "supported by" << SUPPORTED_PIXEL_FORMATS[i].m_name;
			return true;
		}
	}
	return false;
}

void VideoEncoder::PrepareStream(AVStream* stream, AVCodecContext* codec_context, AVCodec* codec, AVDictionary** options, const std::vector<std::pair<QString, QString> >& codec_options,
								 unsigned int bit_rate, unsigned int width, unsigned int height, unsigned int frame_rate) {

	if(width == 0 || height == 0) {
		Logger::LogError("[VideoEncoder::PrepareStream] " + Logger::tr("Error: Width or height is zero!"));
		throw LibavException();
	}
	if(width > SSR_MAX_IMAGE_SIZE || height > SSR_MAX_IMAGE_SIZE) {
		Logger::LogError("[VideoEncoder::PrepareStream] " + Logger::tr("Error: Width or height is too large, the maximum width and height is %1!").arg(SSR_MAX_IMAGE_SIZE));
		throw LibavException();
	}
	if(width % 2 != 0 || height % 2 != 0) {
		Logger::LogError("[VideoEncoder::PrepareStream] " + Logger::tr("Error: Width or height is not an even number!"));
		throw LibavException();
	}
	if(frame_rate == 0) {
		Logger::LogError("[VideoEncoder::PrepareStream] " + Logger::tr("Error: Frame rate is zero!"));
		throw LibavException();
	}

	// initialize codec context
	codec_context->bit_rate = bit_rate;
	codec_context->width = width;
	codec_context->height = height;
	codec_context->time_base.num = 1;
	codec_context->time_base.den = frame_rate;
#if SSR_USE_AVSTREAM_TIME_BASE
	stream->time_base = codec_context->time_base;
#endif
	codec_context->sample_aspect_ratio.num = 1;
	codec_context->sample_aspect_ratio.den = 1;
	stream->sample_aspect_ratio = codec_context->sample_aspect_ratio;
	codec_context->thread_count = std::max(1, (int) std::thread::hardware_concurrency());

	// parse options
	QString pixel_format_name;
	for(unsigned int i = 0; i < codec_options.size(); ++i) {
		const QString &key = codec_options[i].first, &value = codec_options[i].second;
		if(key == "threads") {
			codec_context->thread_count = ParseCodecOptionInt(key, value, 1, 100);
		} else if(key == "qscale") {
			codec_context->flags |= AV_CODEC_FLAG_QSCALE;
			codec_context->global_quality = lrint(ParseCodecOptionDouble(key, value, -1.0e6, 1.0e6, FF_QP2LAMBDA));
		} else if(key == "minrate") {
			codec_context->rc_min_rate = ParseCodecOptionInt(key, value, 1, 1000000, 1000); // kbit/s
		} else if(key == "maxrate") {
			codec_context->rc_max_rate = ParseCodecOptionInt(key, value, 1, 1000000, 1000); // kbit/s
		} else if(key == "bufsize") {
			codec_context->rc_buffer_size = ParseCodecOptionInt(key, value, 1, 1000000, 1000); // kbit/s
		} else if(key == "keyint") {
			codec_context->gop_size = ParseCodecOptionInt(key, value, 1, 1000000);
		} else if(key == "pixelformat") {
			pixel_format_name = value;
#if !SSR_USE_AVCODEC_PRIVATE_PRESET
		} else if(key == "crf") {
			codec_context->crf = ParseCodecOptionInt(key, value, 0, 51);
#endif
#if !SSR_USE_AVCODEC_PRIVATE_PRESET
		} else if(key == "preset") {
			X264Preset(codec_context, value.toUtf8().constData());
#endif
		} else {
			av_dict_set(options, key.toUtf8().constData(), value.toUtf8().constData(), 0);
		}
	}

	// choose the pixel format
	codec_context->pix_fmt = AV_PIX_FMT_NONE;
	for(unsigned int i = 0; i < SUPPORTED_PIXEL_FORMATS.size(); ++i) {
		if(!pixel_format_name.isEmpty() && pixel_format_name != SUPPORTED_PIXEL_FORMATS[i].m_name)
			continue;
		if(!AVCodecSupportsPixelFormat(codec, SUPPORTED_PIXEL_FORMATS[i].m_format))
			continue;
		Logger::LogInfo("[VideoEncoder::PrepareStream] " + Logger::tr("Using pixel format %1.").arg(SUPPORTED_PIXEL_FORMATS[i].m_name));
		codec_context->pix_fmt = SUPPORTED_PIXEL_FORMATS[i].m_format;
		if(SUPPORTED_PIXEL_FORMATS[i].m_is_yuv) {
			codec_context->color_primaries = AVCOL_PRI_BT709;
			codec_context->color_trc = AVCOL_TRC_BT709;
			codec_context->colorspace = AVCOL_SPC_BT709;
			codec_context->color_range = AVCOL_RANGE_MPEG;
			codec_context->chroma_sample_location = AVCHROMA_LOC_CENTER;
		} else {
			codec_context->colorspace = AVCOL_SPC_RGB;
		}
		break;
	}
	if(codec_context->pix_fmt == AV_PIX_FMT_NONE) {
		Logger::LogError("[VideoEncoder::PrepareStream] " + Logger::tr("Error: The pixel format is not supported by the codec!"));
		throw LibavException();
	}

}

bool VideoEncoder::EncodeFrame(AVFrameWrapper* frame) {

	if(frame != NULL) {
#if SSR_USE_AVFRAME_WIDTH_HEIGHT
		assert(frame->GetFrame()->width == GetCodecContext()->width);
		assert(frame->GetFrame()->height == GetCodecContext()->height);
#endif
#if SSR_USE_AVFRAME_FORMAT
		assert(frame->GetFrame()->format == GetCodecContext()->pix_fmt);
#endif
#if SSR_USE_AVFRAME_SAR
		assert(frame->GetFrame()->sample_aspect_ratio.num == GetCodecContext()->sample_aspect_ratio.num);
		assert(frame->GetFrame()->sample_aspect_ratio.den == GetCodecContext()->sample_aspect_ratio.den);
#endif
	}

#if SSR_USE_AVCODEC_SEND_RECEIVE

	// send a frame
	AVFrame *avframe = (frame == NULL)? NULL : frame->Release();
	try {
		if(avcodec_send_frame(GetCodecContext(), avframe) < 0) {
			Logger::LogError("[VideoEncoder::EncodeFrame] " + Logger::tr("Error: Sending of video frame failed!"));
			throw LibavException();
		}
	} catch(...) {
		av_frame_free(&avframe);
		throw;
	}
	av_frame_free(&avframe);

	// try to receive a packet
	for( ; ; ) {
		std::unique_ptr<AVPacketWrapper> packet(new AVPacketWrapper());
		int res = avcodec_receive_packet(GetCodecContext(), packet->GetPacket());
		if(res == 0) { // we have a packet, send the packet to the muxer
			GetMuxer()->AddPacket(GetStream()->index, std::move(packet));
			IncrementPacketCounter();
		} else if(res == AVERROR(EAGAIN)) { // we have no packet
			return true;
		} else if(res == AVERROR_EOF) { // this is the end of the stream
			return false;
		} else {
			Logger::LogError("[VideoEncoder::EncodeFrame] " + Logger::tr("Error: Receiving of video packet failed!"));
			throw LibavException();
		}
	}

#elif SSR_USE_AVCODEC_ENCODE_VIDEO2

	// allocate a packet
	std::unique_ptr<AVPacketWrapper> packet(new AVPacketWrapper());

	// encode the frame
	int got_packet;
	if(avcodec_encode_video2(GetCodecContext(), packet->GetPacket(), (frame == NULL)? NULL : frame->GetFrame(), &got_packet) < 0) {
		Logger::LogError("[VideoEncoder::EncodeFrame] " + Logger::tr("Error: Encoding of video frame failed!"));
		throw LibavException();
	}

	// do we have a packet?
	if(got_packet) {

		// send the packet to the muxer
		GetMuxer()->AddPacket(GetStream()->index, std::move(packet));
		IncrementPacketCounter();
		return true;

	} else {
		return false;
	}

#else

	// encode the frame
	int bytes_encoded = avcodec_encode_video(GetCodecContext(), m_temp_buffer.data(), m_temp_buffer.size(), (frame == NULL)? NULL : frame->GetFrame());
	if(bytes_encoded < 0) {
		Logger::LogError("[VideoEncoder::EncodeFrame] " + Logger::tr("Error: Encoding of video frame failed!"));
		throw LibavException();
	}

	// do we have a packet?
	if(bytes_encoded > 0) {

		// allocate a packet
		std::unique_ptr<AVPacketWrapper> packet(new AVPacketWrapper(bytes_encoded));

		// copy the data
		memcpy(packet->GetPacket()->data, m_temp_buffer.data(), bytes_encoded);

		// set the timestamp
		// note: pts will be rescaled and stream_index will be set by Muxer
		if(GetCodecContext()->coded_frame != NULL && GetCodecContext()->coded_frame->pts != (int64_t) AV_NOPTS_VALUE)
			packet->GetPacket()->pts = GetCodecContext()->coded_frame->pts;

		// set the keyframe flag
		if(GetCodecContext()->coded_frame->key_frame)
			packet->GetPacket()->flags |= AV_PKT_FLAG_KEY;

		// send the packet to the muxer
		GetMuxer()->AddPacket(GetStream()->index, std::move(packet));
		IncrementPacketCounter();
		return true;

	} else {
		return false;
	}

#endif

}
