/*
Copyright (c) 2012 Maarten Baert <maarten-baert@hotmail.com>

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

#include "StdAfx.h"
#include "VideoEncoder.h"

#include "Logger.h"
#include "AVWrapper.h"
#include "Muxer.h"
#include "X264Presets.h"

VideoEncoder::VideoEncoder(Muxer* muxer, const QString& codec_name, const std::vector<std::pair<QString, QString> >& codec_options,
						   unsigned int bit_rate, unsigned int width, unsigned int height, unsigned int frame_rate)
	: BaseEncoder(muxer) {

	m_bit_rate = bit_rate;
	m_width = width;
	m_height = height;
	m_frame_rate = frame_rate;

	m_opt_crf = (unsigned int) -1;
	m_opt_preset = "";

	if(m_width == 0 || m_height == 0) {
		Logger::LogError("[VideoEncoder::Init] Error: Width or height is zero.");
		throw LibavException();
	}
	if(m_width > 10000 || m_height > 10000) {
		Logger::LogError("[VideoEncoder::Init] Error: Width or height is too large, the maximum width and height is 10000.");
		throw LibavException();
	}
	if(m_width % 2 != 0 || m_height % 2 != 0) {
		Logger::LogError("[VideoEncoder::Init] Error: Width or height is not an even number.");
		throw LibavException();
	}

	// start the encoder
	AVDictionary *options = NULL;
	try {
		for(unsigned int i = 0; i < codec_options.size(); ++i) {
			if(codec_options[i].first == "crf")
				m_opt_crf = codec_options[i].second.toUInt();
			if(codec_options[i].first == "preset")
				m_opt_preset = codec_options[i].second;
			av_dict_set(&options, qPrintable(codec_options[i].first), qPrintable(codec_options[i].second), 0);
		}
		CreateCodec(qPrintable(codec_name), &options);
		av_dict_free(&options);
	} catch(...) {
		av_dict_free(&options);
		throw;
	}

#if !SSR_USE_AVCODEC_ENCODE_VIDEO2
	// allocate a temporary buffer
	// Apparently libav completely ignores the size of the buffer, and if it's too small it just crashes.
	// Originally it was 256k, which is large enough for about 99.9% of the packets, but it still occasionally crashes.
	// So now I'm using a buffer that's always at least large enough to hold a 256k header and *two* completely uncompressed frames.
	// (one YUV frame takes w * h * 1.5 bytes)
	// Newer versions of libav have deprecated avcodec_encode_video and added a new function which does the allocation
	// automatically, just like avcodec_encode_audio2, but that function isn't available in Ubuntu 12.04/12.10 yet.
	m_temp_buffer.resize(std::max<unsigned int>(FF_MIN_BUFFER_SIZE, 256 * 1024 + m_width * m_height * 3));
#endif

}

void VideoEncoder::FillCodecContext(AVCodec* codec) {

	GetCodecContext()->width = m_width;
	GetCodecContext()->height = m_height;
	GetCodecContext()->time_base.num = 1;
	GetCodecContext()->time_base.den = m_frame_rate;
	GetCodecContext()->pix_fmt = PIX_FMT_YUV420P;
	GetCodecContext()->sample_aspect_ratio.num = 1;
	GetCodecContext()->sample_aspect_ratio.den = 1;
	GetCodecContext()->flags |= CODEC_FLAG_LOOP_FILTER;
	GetCodecContext()->thread_count = std::max(1, ::QThread::idealThreadCount());

	if(strcmp(codec->name, "libx264") == 0) {
		Q_ASSERT(m_opt_crf != (unsigned int) -1);
		Q_ASSERT(m_opt_preset != "");

#if !SSR_USE_AVCODEC_OPT_CRF
		GetCodecContext()->crf = m_opt_crf;
#endif
#if !SSR_USE_AVCODEC_OPT_PRESET
		X264Preset(GetCodecContext(), qPrintable(m_opt_preset));
#endif

		/*
		The code below is needed for variable frame rate video. Variable frame rate essentially means setting the time base to 1us.
		This causes a few other problems though, not just with encoders but also with playback, so I stopped using it.
		This workaround isn't needed anymore, but I will keep the code in case I want to add variable frame rate video again later.

		// Automatic H.264 level detection fails because x264 thinks I'm recording at 1000000 fps.
		// Either I don't understand how to do variable frame rate encoding, or the x264 developers just
		// didn't think of this. Anyway, I'm detecting the correct level myself based on the size and frame rate.
		// This detection isn't perfect because I have no idea what the bit rate will be, but it's better than nothing.
		struct Level {
			int level;
			unsigned int mbps, mb;
		};
		Level levellist[] = {
			{10,   1485,    99},
			{11,   3000,   396},
			{12,   6000,   396},
			{13,  11880,   396},
			{20,  11880,   396},
			{21,  19800,   792},
			{22,  20250,  1620},
			{30,  40500,  1620},
			{31, 108000,  3600},
			{32, 216000,  5120},
			{40, 245760,  8192},
			{41, 245760,  8192},
			{42, 522240,  8704},
			{50, 589824, 22080},
			{51, 983040, 36864},
		};
		unsigned int mb = ((m_width + 15) / 16) * ((m_height + 15) / 16), mbps = mb * m_frame_rate;
		for(unsigned int i = 0; i < sizeof(levellist) / sizeof(Level); ++i) {
			GetCodecContext()->level = levellist[i].level;
			if(mbps <= levellist[i].mbps && mb <= levellist[i].mb)
				break;
		}*/
	} else {
		GetCodecContext()->bit_rate = m_bit_rate;
	}

}

bool VideoEncoder::EncodeFrame(AVFrameWrapper* frame) {

#if SSR_USE_AVCODEC_ENCODE_VIDEO2

	// allocate a packet
	std::unique_ptr<AVPacketWrapper> packet(new AVPacketWrapper());

	// encode the frame
	int got_packet;
	if(avcodec_encode_video2(GetCodecContext(), packet.get(), frame, &got_packet) < 0) {
		Logger::LogError("[VideoEncoder::EncodeFrame] Error: Encoding of video frame failed!");
		throw LibavException();
	}

	// do we have a packet?
	if(got_packet) {

		// set the keyframe flag
		if(GetCodecContext()->coded_frame->key_frame)
			packet->flags |= AV_PKT_FLAG_KEY;

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
		Logger::LogError("[VideoEncoder::EncodeFrame] Error: Encoding of video frame failed!");
		throw LibavException();
	}

	// do we have a packet?
	if(bytes_encoded > 0) {

		// allocate a packet
		std::unique_ptr<AVPacketWrapper> packet(new AVPacketWrapper(bytes_encoded));

		// copy the data
		memcpy(packet->data, m_temp_buffer.data(), bytes_encoded);

		// set the timestamp
		// note: pts will be rescaled and stream_index will be set by Muxer
		if(GetCodecContext()->coded_frame != NULL && GetCodecContext()->coded_frame->pts != (int64_t) AV_NOPTS_VALUE)
			packet->pts = GetCodecContext()->coded_frame->pts;

		// set the keyframe flag
		if(GetCodecContext()->coded_frame->key_frame)
			packet->flags |= AV_PKT_FLAG_KEY;

		// send the packet to the muxer
		GetMuxer()->AddPacket(GetStreamIndex(), std::move(packet));
		return true;

	} else {
		return false;
	}

#endif

}
