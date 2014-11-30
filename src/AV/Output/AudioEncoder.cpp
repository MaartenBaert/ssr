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
#include "AudioEncoder.h"

#include "Logger.h"
#include "AVWrapper.h"
#include "Muxer.h"

const std::vector<AudioEncoder::SampleFormatData> AudioEncoder::SUPPORTED_SAMPLE_FORMATS = {
	{"f32i", AV_SAMPLE_FMT_FLT},
	{"s16i", AV_SAMPLE_FMT_S16},
#if SSR_USE_AVUTIL_PLANAR_SAMPLE_FMT
	{"f32p", AV_SAMPLE_FMT_FLTP},
	{"s16p", AV_SAMPLE_FMT_S16P},
#endif
};

const unsigned int AudioEncoder::DEFAULT_FRAME_SAMPLES = 1024;

AudioEncoder::AudioEncoder(Muxer* muxer, AVStream* stream, AVCodec* codec, AVDictionary** options)
	: BaseEncoder(muxer, stream, codec, options) {

#if !SSR_USE_AVCODEC_ENCODE_AUDIO2
	// allocate a temporary buffer
	if(GetStream()->codec->frame_size <= 1) {
		// This is really weird, the old API uses the size of the *output* buffer to determine the number of
		// input samples if the number of input samples (i.e. frame_size) is not fixed (i.e. frame_size <= 1).
		m_temp_buffer.resize(DEFAULT_FRAME_SAMPLES * GetStream()->codec->channels * av_get_bits_per_sample(GetStream()->codec->codec_id) / 8);
	} else {
		m_temp_buffer.resize(std::max(FF_MIN_BUFFER_SIZE, 256 * 1024));
	}
#endif

	StartThread();

}

AudioEncoder::~AudioEncoder() {
	StopThread();
}

unsigned int AudioEncoder::GetFrameSize() {
#if SSR_USE_AVCODEC_ENCODE_AUDIO2
	return (GetStream()->codec->codec->capabilities & CODEC_CAP_VARIABLE_FRAME_SIZE)? DEFAULT_FRAME_SAMPLES : GetStream()->codec->frame_size;
#else
	return (GetStream()->codec->frame_size <= 1)? DEFAULT_FRAME_SAMPLES : GetStream()->codec->frame_size;
#endif
}

AVSampleFormat AudioEncoder::GetSampleFormat() {
	return GetStream()->codec->sample_fmt;
}

unsigned int AudioEncoder::GetChannels() {
	return GetStream()->codec->channels;
}

unsigned int AudioEncoder::GetSampleRate() {
	return GetStream()->codec->sample_rate;
}

bool AudioEncoder::AVCodecIsSupported(const QString& codec_name) {
	AVCodec *codec = avcodec_find_encoder_by_name(codec_name.toUtf8().constData());
	if(codec == NULL)
		return false;
	if(!av_codec_is_encoder(codec))
		return false;
	if(codec->type != AVMEDIA_TYPE_AUDIO)
		return false;
	for(unsigned int i = 0; i < SUPPORTED_SAMPLE_FORMATS.size(); ++i) {
		if(AVCodecSupportsSampleFormat(codec, SUPPORTED_SAMPLE_FORMATS[i].m_format))
			return true;
	}
	return false;
}

void AudioEncoder::PrepareStream(AVStream* stream, AVCodec* codec, AVDictionary** options, const std::vector<std::pair<QString, QString> >& codec_options,
								 unsigned int bit_rate, unsigned int channels, unsigned int sample_rate) {

	if(channels == 0) {
		Logger::LogError("[AudioEncoder::PrepareStream] " + Logger::tr("Error: Channel count is zero."));
		throw LibavException();
	}
	if(sample_rate == 0) {
		Logger::LogError("[AudioEncoder::PrepareStream] " + Logger::tr("Error: Sample rate is zero."));
		throw LibavException();
	}

	stream->codec->bit_rate = bit_rate;
	stream->codec->channels = channels;
	stream->codec->sample_rate = sample_rate;
	stream->codec->time_base.num = 1;
	stream->codec->time_base.den = sample_rate;
#if SSR_USE_AVSTREAM_TIME_BASE
	stream->time_base = stream->codec->time_base;
#endif
	stream->codec->thread_count = 1;

	// parse options
	QString sample_format_name;
	for(unsigned int i = 0; i < codec_options.size(); ++i) {
		const QString &key = codec_options[i].first, &value = codec_options[i].second;
		if(key == "threads") {
			stream->codec->thread_count = ParseCodecOptionInt(key, value, 1, 100);
		} else if(key == "qscale") {
			stream->codec->flags |= CODEC_FLAG_QSCALE;
			stream->codec->global_quality = lrint(ParseCodecOptionDouble(key, value, -1.0e6, 1.0e6, FF_QP2LAMBDA));
		} else if(key == "sampleformat") {
			sample_format_name = value;
		} else {
			av_dict_set(options, key.toUtf8().constData(), value.toUtf8().constData(), 0);
		}
	}

	// choose the sample format
	stream->codec->sample_fmt = AV_SAMPLE_FMT_NONE;
	for(unsigned int i = 0; i < SUPPORTED_SAMPLE_FORMATS.size(); ++i) {
		if(!sample_format_name.isEmpty() && sample_format_name != SUPPORTED_SAMPLE_FORMATS[i].m_name)
			continue;
		if(!AVCodecSupportsSampleFormat(codec, SUPPORTED_SAMPLE_FORMATS[i].m_format))
			continue;
		Logger::LogInfo("[AudioEncoder::PrepareStream] " + Logger::tr("Using sample format %1.").arg(SUPPORTED_SAMPLE_FORMATS[i].m_name));
		stream->codec->sample_fmt = SUPPORTED_SAMPLE_FORMATS[i].m_format;
		break;
	}
	if(stream->codec->sample_fmt == AV_SAMPLE_FMT_NONE) {
		Logger::LogError("[AudioEncoder::PrepareStream] " + Logger::tr("Error: Encoder requires an unsupported sample format!"));
		throw LibavException();
	}

}

bool AudioEncoder::EncodeFrame(AVFrame* frame) {

	if(frame != NULL) {
#if SSR_USE_AVFRAME_NB_SAMPLES
		assert((unsigned int) frame->nb_samples == GetFrameSize());
#endif
#if SSR_USE_AVFRAME_CHANNELS
		assert(frame->channels == GetStream()->codec->channels);
#endif
#if SSR_USE_AVFRAME_SAMPLE_RATE
		assert(frame->sample_rate == GetStream()->codec->sample_rate);
#endif
#if SSR_USE_AVFRAME_FORMAT
		assert(frame->format == GetStream()->codec->sample_fmt);
#endif
	}

#if SSR_USE_AVCODEC_ENCODE_AUDIO2

	// allocate a packet
	std::unique_ptr<AVPacketWrapper> packet(new AVPacketWrapper());

	// encode the frame
	int got_packet;
	if(avcodec_encode_audio2(GetStream()->codec, packet->GetPacket(), frame, &got_packet) < 0) {
		Logger::LogError("[AudioEncoder::EncodeFrame] " + Logger::tr("Error: Encoding of audio frame failed!"));
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
	short *data = (frame == NULL)? NULL : (short*) frame->data[0];
	int bytes_encoded = avcodec_encode_audio(GetStream()->codec, m_temp_buffer.data(), m_temp_buffer.size(), data);
	if(bytes_encoded < 0) {
		Logger::LogError("[AudioEncoder::EncodeFrame] " + Logger::tr("Error: Encoding of audio frame failed!"));
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

		// send the packet to the muxer
		GetMuxer()->AddPacket(GetStream()->index, std::move(packet));
		return true;

	} else {
		return false;
	}

#endif

}
