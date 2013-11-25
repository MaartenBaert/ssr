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

#include "Global.h"
#include "VideoEncoder.h"

#include "Logger.h"
#include "AVWrapper.h"
#include "Muxer.h"
#include "X264Presets.h"

const size_t VideoEncoder::THROTTLE_THRESHOLD_FRAMES = 20;
const size_t VideoEncoder::THROTTLE_THRESHOLD_PACKETS = 100;
const std::vector<PixelFormat> VideoEncoder::SUPPORTED_PIXEL_FORMATS = {
	PIX_FMT_YUV420P,
};

VideoEncoder::VideoEncoder(Muxer* muxer, const QString& codec_name, const std::vector<std::pair<QString, QString> >& codec_options,
						   unsigned int bit_rate, unsigned int width, unsigned int height, unsigned int frame_rate)
	: BaseEncoder(muxer) {
	try {

		m_bit_rate = bit_rate;
		m_width = width;
		m_height = height;
		m_frame_rate = frame_rate;

		m_opt_threads = std::max(1u, std::thread::hardware_concurrency());
		m_opt_minrate = (unsigned int) -1;
		m_opt_maxrate = (unsigned int) -1;
		m_opt_bufsize = (unsigned int) -1;

#if !SSR_USE_AVCODEC_PRIVATE_CRF
		m_opt_crf = (unsigned int) -1;
#endif
#if !SSR_USE_AVCODEC_PRIVATE_PRESET
		m_opt_preset = "";
#endif

		if(m_width < 2 || m_height < 2) {
			Logger::LogError("[VideoEncoder::VideoEncoder] " + QObject::tr("Error: Width or height is too small, the minimum width and height is %1!").arg(2));
			throw LibavException();
		}
		if(m_width > 10000 || m_height > 10000) {
			Logger::LogError("[VideoEncoder::VideoEncoder] " + QObject::tr("Error: Width or height is too large, the maximum width and height is %1!").arg(10000));
			throw LibavException();
		}
		if(m_width % 2 != 0 || m_height % 2 != 0) {
			Logger::LogError("[VideoEncoder::VideoEncoder] " + QObject::tr("Error: Width or height is not an even number!"));
			throw LibavException();
		}
		if(m_frame_rate == 0) {
			Logger::LogError("[VideoEncoder::VideoEncoder] " + QObject::tr("Error: Frame rate it zero!"));
			throw LibavException();
		}

		// start the encoder
		AVDictionary *options = NULL;
		try {
			for(unsigned int i = 0; i < codec_options.size(); ++i) {
				if(codec_options[i].first == "threads")
					m_opt_threads = codec_options[i].second.toUInt();
				else if(codec_options[i].first == "minrate")
					m_opt_minrate = codec_options[i].second.toUInt() * 1024; // kbps
				else if(codec_options[i].first == "maxrate")
					m_opt_maxrate = codec_options[i].second.toUInt() * 1024; // kbps
				else if(codec_options[i].first == "bufsize")
					m_opt_bufsize = codec_options[i].second.toUInt() * 1024; // kbit
#if !SSR_USE_AVCODEC_PRIVATE_PRESET
				else if(codec_options[i].first == "crf")
					m_opt_crf = codec_options[i].second.toUInt();
#endif
#if !SSR_USE_AVCODEC_PRIVATE_PRESET
				else if(codec_options[i].first == "preset")
					m_opt_preset = codec_options[i].second;
#endif
				else
					av_dict_set(&options, codec_options[i].first.toAscii().constData(), codec_options[i].second.toAscii().constData(), 0);
			}
			CreateCodec(codec_name, &options);
			av_dict_free(&options);
		} catch(...) {
			av_dict_free(&options);
			throw;
		}

#if !SSR_USE_AVCODEC_ENCODE_VIDEO2
		// allocate a temporary buffer
		// Apparently libav/ffmpeg completely ignores the size of the buffer, and if it's too small it just crashes.
		// Originally it was 256k, which is large enough for about 99.9% of the packets, but it still occasionally crashes.
		// So now I'm using a buffer that's always at least large enough to hold a 256k header and *two* completely uncompressed frames.
		// (one YUV frame takes w * h * 1.5 bytes)
		// Newer versions of libav/ffmpeg have deprecated avcodec_encode_video and added a new function which does the allocation
		// automatically, just like avcodec_encode_audio2, but that function isn't available in Ubuntu 12.04/12.10 yet.
		m_temp_buffer.resize(std::max<unsigned int>(FF_MIN_BUFFER_SIZE, 256 * 1024 + m_width * m_height * 3));
#endif

		GetMuxer()->RegisterEncoder(GetStreamIndex(), this);

	} catch(...) {
		Destruct();
		throw;
	}
}

VideoEncoder::~VideoEncoder() {
	Destruct(); // destruct the base class first
}

int64_t VideoEncoder::GetFrameDelay() {
	int64_t interval = 0;
	size_t frames = GetQueuedFrameCount();
	if(frames > THROTTLE_THRESHOLD_FRAMES) {
		int64_t n = (frames - THROTTLE_THRESHOLD_FRAMES) * 1000 / THROTTLE_THRESHOLD_FRAMES;
		interval += n * n;
	}
	size_t packets = GetMuxer()->GetQueuedPacketCount(GetStreamIndex());
	if(packets > THROTTLE_THRESHOLD_PACKETS) {
		int64_t n = (packets - THROTTLE_THRESHOLD_PACKETS) * 1000 / THROTTLE_THRESHOLD_PACKETS;
		interval += n * n;
	}
	if(interval > 1000000)
		interval = 1000000;
	return interval;
}

bool VideoEncoder::AVCodecIsSupported(const QString& codec_name) {
	AVCodec *codec = avcodec_find_encoder_by_name(codec_name.toAscii().constData());
	if(codec == NULL)
		return false;
	for(unsigned int i = 0; i < SUPPORTED_PIXEL_FORMATS.size(); ++i) {
		if(AVCodecSupportsPixelFormat(codec, SUPPORTED_PIXEL_FORMATS[i]))
			return true;
	}
	return false;
}

void VideoEncoder::FillCodecContext(AVCodec* codec) {

	GetCodecContext()->width = m_width;
	GetCodecContext()->height = m_height;
	GetCodecContext()->time_base.num = 1;
	GetCodecContext()->time_base.den = m_frame_rate;
	GetCodecContext()->bit_rate = m_bit_rate;
	GetCodecContext()->pix_fmt = PIX_FMT_YUV420P;
	GetCodecContext()->sample_aspect_ratio.num = 1;
	GetCodecContext()->sample_aspect_ratio.den = 1;
	GetCodecContext()->flags |= CODEC_FLAG_LOOP_FILTER;
	GetCodecContext()->thread_count = m_opt_threads;


	if(m_opt_minrate != (unsigned int) -1)
		GetCodecContext()->rc_min_rate = m_opt_minrate;
	if(m_opt_maxrate != (unsigned int) -1)
		GetCodecContext()->rc_max_rate = m_opt_maxrate;
	if(m_opt_bufsize != (unsigned int) -1)
		GetCodecContext()->rc_buffer_size = m_opt_bufsize;

#if !SSR_USE_AVCODEC_PRIVATE_CRF
	if(m_opt_crf != (unsigned int) -1)
		GetCodecContext()->crf = m_opt_crf;
#endif
#if !SSR_USE_AVCODEC_PRIVATE_PRESET
	if(m_opt_preset != "")
		X264Preset(GetCodecContext(), m_opt_preset.toAscii().constData());
#endif

}

bool VideoEncoder::EncodeFrame(AVFrame* frame) {

#if SSR_USE_AVFRAME_FORMAT
	if(frame != NULL) {
		Q_ASSERT(frame->format == GetCodecContext()->pix_fmt);
	}
#endif

#if SSR_USE_AVCODEC_ENCODE_VIDEO2

	// allocate a packet
	std::unique_ptr<AVPacketWrapper> packet(new AVPacketWrapper());

	// encode the frame
	int got_packet;
	if(avcodec_encode_video2(GetCodecContext(), packet->GetPacket(), frame, &got_packet) < 0) {
		Logger::LogError("[VideoEncoder::EncodeFrame] " + QObject::tr("Error: Encoding of video frame failed!"));
		throw LibavException();
	}

	// do we have a packet?
	if(got_packet) {

		if(GetCodecContext()->coded_frame->key_frame)
			packet->GetPacket()->flags |= AV_PKT_FLAG_KEY;

		// send the packet to the muxer
		GetMuxer()->AddPacket(GetStreamIndex(), std::move(packet));
		return true;

	} else {
		return false;
	}

#else

	// encode the frame
	int bytes_encoded = avcodec_encode_video(GetCodecContext(), m_temp_buffer.data(), m_temp_buffer.size(), frame);
	if(bytes_encoded < 0) {
		Logger::LogError("[VideoEncoder::EncodeFrame] " + QObject::tr("Error: Encoding of video frame failed!"));
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
		GetMuxer()->AddPacket(GetStreamIndex(), std::move(packet));
		return true;

	} else {
		return false;
	}

#endif

}
