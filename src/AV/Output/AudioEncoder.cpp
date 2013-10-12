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
#include "AudioEncoder.h"

#include "Logger.h"
#include "AVWrapper.h"
#include "Muxer.h"

const std::vector<AVSampleFormat> AudioEncoder::SUPPORTED_SAMPLE_FORMATS = {
	AV_SAMPLE_FMT_S16, AV_SAMPLE_FMT_FLT,
#if SSR_USE_AVUTIL_PLANAR_SAMPLE_FMT
	AV_SAMPLE_FMT_S16P, AV_SAMPLE_FMT_FLTP,
#endif
};

AudioEncoder::AudioEncoder(Muxer* muxer, const QString& codec_name, const std::vector<std::pair<QString, QString> >& codec_options,
						   unsigned int bit_rate, unsigned int sample_rate)
	: BaseEncoder(muxer) {
	try {

		m_bit_rate = bit_rate;
		m_sample_rate = sample_rate;

		m_opt_threads = 1;

		if(m_sample_rate == 0) {
			Logger::LogError("[AudioEncoder::Init] Error: Sample rate it zero.");
			throw LibavException();
		}

		// start the encoder
		AVDictionary *options = NULL;
		try {
			for(unsigned int i = 0; i < codec_options.size(); ++i) {
				if(codec_options[i].first == "threads")
					m_opt_threads = codec_options[i].second.toUInt();
				av_dict_set(&options, codec_options[i].first.toAscii().constData(), codec_options[i].second.toAscii().constData(), 0);
			}
			CreateCodec(codec_name, &options);
			av_dict_free(&options);
		} catch(...) {
			av_dict_free(&options);
			throw;
		}

	#if !SSR_USE_AVCODEC_ENCODE_AUDIO2
		// allocate a temporary buffer
		if(GetCodecContext()->frame_size <= 1) {
			// This is really weird, the old API uses the size of the *output* buffer to determine the number of
			// input samples if the number of input samples (i.e. frame_size) is not fixed (i.e. frame_size <= 1).
			m_temp_buffer.resize(1024 * GetCodecContext()->channels * av_get_bits_per_sample(GetCodecContext()->codec_id) / 8);
		} else {
			m_temp_buffer.resize(std::max(FF_MIN_BUFFER_SIZE, 256 * 1024));
		}
	#endif

		GetMuxer()->RegisterEncoder(GetStreamIndex(), this);

	} catch(...) {
		Destruct();
		throw;
	}
}

AudioEncoder::~AudioEncoder() {
	Destruct(); // destruct the base class first
}

unsigned int AudioEncoder::GetRequiredFrameSamples() {
#if SSR_USE_AVCODEC_ENCODE_AUDIO2
	return (GetCodecContext()->codec->capabilities & CODEC_CAP_VARIABLE_FRAME_SIZE)? 1024 : GetCodecContext()->frame_size;
#else
	return (GetCodecContext()->frame_size <= 1)? 1024 : GetCodecContext()->frame_size;
#endif
}

AVSampleFormat AudioEncoder::GetRequiredSampleFormat() {
	return GetCodecContext()->sample_fmt;
}

bool AudioEncoder::AVCodecIsSupported(const QString& codec_name) {
	AVCodec *codec = avcodec_find_encoder_by_name(codec_name.toAscii().constData());
	if(codec == NULL)
		return false;
	for(unsigned int i = 0; i < SUPPORTED_SAMPLE_FORMATS.size(); ++i) {
		if(AVCodecSupportsSampleFormat(codec, SUPPORTED_SAMPLE_FORMATS[i]))
			return true;
	}
	return false;
}

void AudioEncoder::FillCodecContext(AVCodec* codec) {
	Q_UNUSED(codec);

	GetCodecContext()->time_base.num = 1;
	GetCodecContext()->time_base.den = m_sample_rate;
	GetCodecContext()->bit_rate = m_bit_rate;
	GetCodecContext()->sample_rate = m_sample_rate;
	GetCodecContext()->channels = 2;
	GetCodecContext()->sample_fmt = AV_SAMPLE_FMT_NONE;
	for(unsigned int i = 0; i < SUPPORTED_SAMPLE_FORMATS.size(); ++i) {
		if(AVCodecSupportsSampleFormat(codec, SUPPORTED_SAMPLE_FORMATS[i])) {
			GetCodecContext()->sample_fmt = SUPPORTED_SAMPLE_FORMATS[i];
			break;
		}
	}
	if(GetCodecContext()->sample_fmt == AV_SAMPLE_FMT_NONE) {
		Logger::LogError("[AudioEncoder::FillCodecContext] Error: Encoder requires an unsupported sample format!");
		throw LibavException();
	}
	GetCodecContext()->thread_count = m_opt_threads;

}

bool AudioEncoder::EncodeFrame(AVFrame* frame) {

#if SSR_USE_AVFRAME_FORMAT
	if(frame != NULL) {
		Q_ASSERT(frame->format == GetCodecContext()->sample_fmt);
	}
#endif

#if SSR_USE_AVCODEC_ENCODE_AUDIO2

	// allocate a packet
	std::unique_ptr<AVPacketWrapper> packet(new AVPacketWrapper());

	// encode the frame
	int got_packet;
	if(avcodec_encode_audio2(GetCodecContext(), packet->GetPacket(), frame, &got_packet) < 0) {
		Logger::LogError("[AudioEncoder::EncodeFrame] Error: Encoding of audio frame failed!");
		throw LibavException();
	}

	// do we have a packet?
	if(got_packet) {

		// send the packet to the muxer
		GetMuxer()->AddPacket(GetStreamIndex(), std::move(packet));
		return true;

	} else {
		return false;
	}

#else

	// encode the frame
	short *data = (frame == NULL)? NULL : (short*) frame->data[0];
	int bytes_encoded = avcodec_encode_audio(GetCodecContext(), m_temp_buffer.data(), m_temp_buffer.size(), data);
	if(bytes_encoded < 0) {
		Logger::LogError("[AudioEncoder::EncodeFrame] Error: Encoding of audio frame failed!");
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

		// send the packet to the muxer
		GetMuxer()->AddPacket(GetStreamIndex(), std::move(packet));
		return true;

	} else {
		return false;
	}

#endif

}

