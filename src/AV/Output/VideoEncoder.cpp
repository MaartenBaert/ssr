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
#include "VideoEncoder.h"

#include "Logger.h"
#include "AVWrapper.h"
#include "Muxer.h"
#include "X264Presets.h"

const size_t VideoEncoder::THROTTLE_THRESHOLD_FRAMES = 20;
const size_t VideoEncoder::THROTTLE_THRESHOLD_PACKETS = 100;
const std::vector<VideoEncoder::PixelFormatData> VideoEncoder::SUPPORTED_PIXEL_FORMATS = {
	{"yuv420", AV_PIX_FMT_YUV420P, true},
	{"yuv422", AV_PIX_FMT_YUV422P, true},
	{"yuv444", AV_PIX_FMT_YUV444P, true},
	{"nv12", AV_PIX_FMT_NV12, true},
	{"bgra", AV_PIX_FMT_BGRA, false},
	{"bgr", AV_PIX_FMT_BGR24, false},
};

VideoEncoder::VideoEncoder(Muxer* muxer, AVStream* stream, AVCodec* codec, AVDictionary** options)
	: BaseEncoder(muxer, stream, codec, options) {

#if !SSR_USE_AVCODEC_ENCODE_VIDEO2
	// allocate a temporary buffer
	// Apparently libav/ffmpeg completely ignores the size of the buffer, and if it's too small it just crashes.
	// Originally it was 256k, which is large enough for about 99.9% of the packets, but it still occasionally crashes.
	// So now I'm using a buffer that's always at least large enough to hold a 256k header and *two* completely uncompressed frames.
	// (one YUV frame takes w * h * 1.5 bytes)
	// Newer versions of libav/ffmpeg have deprecated avcodec_encode_video and added a new function which does the allocation
	// automatically, just like avcodec_encode_audio2, but that function isn't available in Ubuntu 12.04/12.10 yet.
	m_temp_buffer.resize(std::max<unsigned int>(FF_MIN_BUFFER_SIZE, 256 * 1024 + GetStream()->codec->width * GetStream()->codec->height * 3));
#endif

	StartThread();
}

VideoEncoder::~VideoEncoder() {
	StopThread();
}

PixelFormat VideoEncoder::GetPixelFormat() {
	return GetStream()->codec->pix_fmt;
}

unsigned int VideoEncoder::GetWidth() {
	return GetStream()->codec->width;
}

unsigned int VideoEncoder::GetHeight() {
	return GetStream()->codec->height;
}

unsigned int VideoEncoder::GetFrameRate() {
	assert(GetStream()->codec->time_base.num == 1);
	return GetStream()->codec->time_base.den;
}

int64_t VideoEncoder::GetFrameDelay() {
	int64_t interval = 0;
	size_t frames = GetQueuedFrameCount();
	if(frames > THROTTLE_THRESHOLD_FRAMES) {
		int64_t n = (frames - THROTTLE_THRESHOLD_FRAMES) * 200 / THROTTLE_THRESHOLD_FRAMES;
		interval += n * n;
	}
	size_t packets = GetMuxer()->GetQueuedPacketCount(GetStream()->index);
	if(packets > THROTTLE_THRESHOLD_PACKETS) {
		int64_t n = (packets - THROTTLE_THRESHOLD_PACKETS) * 200 / THROTTLE_THRESHOLD_PACKETS;
		interval += n * n;
	}
	if(interval > 1000000)
		interval = 1000000;
	return interval;
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
		if(AVCodecSupportsPixelFormat(codec, SUPPORTED_PIXEL_FORMATS[i].m_format))
			return true;
	}
	return false;
}

void VideoEncoder::PrepareStream(AVStream* stream, AVCodec* codec, AVDictionary** options, const std::vector<std::pair<QString, QString> >& codec_options,
								 unsigned int bit_rate, unsigned int width, unsigned int height, unsigned int frame_rate) {

	if(width == 0 || height == 0) {
		Logger::LogError("[VideoEncoder::PrepareStream] " + Logger::tr("Error: Width or height is zero!"));
		throw LibavException();
	}
	if(width > 10000 || height > 10000) {
		Logger::LogError("[VideoEncoder::PrepareStream] " + Logger::tr("Error: Width or height is too large, the maximum width and height is %1!").arg(10000));
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
	stream->codec->bit_rate = bit_rate;
	stream->codec->width = width;
	stream->codec->height = height;
	stream->codec->time_base.num = 1;
	stream->codec->time_base.den = frame_rate;
#if SSR_USE_AVSTREAM_TIME_BASE
	stream->time_base = stream->codec->time_base;
#endif
	stream->codec->sample_aspect_ratio.num = 1;
	stream->codec->sample_aspect_ratio.den = 1;
	stream->sample_aspect_ratio = stream->codec->sample_aspect_ratio;
	stream->codec->thread_count = std::max(1, (int) std::thread::hardware_concurrency());

	// parse options
	QString pixel_format_name;
	for(unsigned int i = 0; i < codec_options.size(); ++i) {
		const QString &key = codec_options[i].first, &value = codec_options[i].second;
		if(key == "threads") {
			stream->codec->thread_count = ParseCodecOptionInt(key, value, 1, 100);
		} else if(key == "qscale") {
			stream->codec->flags |= CODEC_FLAG_QSCALE;
			stream->codec->global_quality = lrint(ParseCodecOptionDouble(key, value, -1.0e6, 1.0e6, FF_QP2LAMBDA));
		} else if(key == "minrate") {
			stream->codec->rc_min_rate = ParseCodecOptionInt(key, value, 1, 1000000, 1024); // kbps
		} else if(key == "maxrate") {
			stream->codec->rc_max_rate = ParseCodecOptionInt(key, value, 1, 1000000, 1024); // kbps
		} else if(key == "bufsize") {
			stream->codec->rc_buffer_size = ParseCodecOptionInt(key, value, 1, 1000000, 1024); // kbps
		} else if(key == "keyint") {
			stream->codec->gop_size = ParseCodecOptionInt(key, value, 1, 1000000);
		} else if(key == "pixelformat") {
			pixel_format_name = value;
#if !SSR_USE_AVCODEC_PRIVATE_PRESET
		} else if(key == "crf") {
			stream->codec->crf = ParseCodecOptionInt(key, value, 0, 51);
#endif
#if !SSR_USE_AVCODEC_PRIVATE_PRESET
		} else if(key == "preset") {
			X264Preset(stream->codec, value.toUtf8().constData());
#endif
		} else {
			av_dict_set(options, key.toUtf8().constData(), value.toUtf8().constData(), 0);
		}
	}

	// choose the pixel format
	stream->codec->pix_fmt = AV_PIX_FMT_NONE;
	for(unsigned int i = 0; i < SUPPORTED_PIXEL_FORMATS.size(); ++i) {
		if(!pixel_format_name.isEmpty() && pixel_format_name != SUPPORTED_PIXEL_FORMATS[i].m_name)
			continue;
		if(!AVCodecSupportsPixelFormat(codec, SUPPORTED_PIXEL_FORMATS[i].m_format))
			continue;
		Logger::LogInfo("[VideoEncoder::PrepareStream] " + Logger::tr("Using pixel format %1.").arg(SUPPORTED_PIXEL_FORMATS[i].m_name));
		stream->codec->pix_fmt = SUPPORTED_PIXEL_FORMATS[i].m_format;
		if(SUPPORTED_PIXEL_FORMATS[i].m_is_yuv) {
			stream->codec->color_primaries = AVCOL_PRI_BT709;
			stream->codec->color_trc = AVCOL_TRC_BT709;
			stream->codec->colorspace = AVCOL_SPC_BT709;
			stream->codec->color_range = AVCOL_RANGE_MPEG;
			stream->codec->chroma_sample_location = AVCHROMA_LOC_CENTER;
		} else {
			stream->codec->colorspace = AVCOL_SPC_RGB;
		}
		break;
	}
	if(stream->codec->pix_fmt == AV_PIX_FMT_NONE) {
		Logger::LogError("[VideoEncoder::PrepareStream] " + Logger::tr("Error: The pixel format is not supported by the codec!"));
		throw LibavException();
	}

}

bool VideoEncoder::EncodeFrame(AVFrame* frame) {

	if(frame != NULL) {
#if SSR_USE_AVFRAME_WIDTH_HEIGHT
		assert(frame->width == GetStream()->codec->width);
		assert(frame->height == GetStream()->codec->height);
#endif
#if SSR_USE_AVFRAME_FORMAT
		assert(frame->format == GetStream()->codec->pix_fmt);
#endif
#if SSR_USE_AVFRAME_SAR
		assert(frame->sample_aspect_ratio.num == GetStream()->codec->sample_aspect_ratio.num);
		assert(frame->sample_aspect_ratio.den == GetStream()->codec->sample_aspect_ratio.den);
#endif
	}

#if SSR_USE_AVCODEC_ENCODE_VIDEO2

	// allocate a packet
	std::unique_ptr<AVPacketWrapper> packet(new AVPacketWrapper());

	// encode the frame
	int got_packet;
	if(avcodec_encode_video2(GetStream()->codec, packet->GetPacket(), frame, &got_packet) < 0) {
		Logger::LogError("[VideoEncoder::EncodeFrame] " + Logger::tr("Error: Encoding of video frame failed!"));
		throw LibavException();
	}

	// do we have a packet?
	if(got_packet) {

		// send the packet to the muxer
		GetMuxer()->AddPacket(GetStream()->index, std::move(packet));
		return true;

	} else {
		return false;
	}

#else

	// encode the frame
	int bytes_encoded = avcodec_encode_video(GetStream()->codec, m_temp_buffer.data(), m_temp_buffer.size(), frame);
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
		if(GetStream()->codec->coded_frame != NULL && GetStream()->codec->coded_frame->pts != (int64_t) AV_NOPTS_VALUE)
			packet->GetPacket()->pts = GetStream()->codec->coded_frame->pts;

		// set the keyframe flag
		if(GetStream()->codec->coded_frame->key_frame)
			packet->GetPacket()->flags |= AV_PKT_FLAG_KEY;

		// send the packet to the muxer
		GetMuxer()->AddPacket(GetStream()->index, std::move(packet));
		return true;

	} else {
		return false;
	}

#endif

}
