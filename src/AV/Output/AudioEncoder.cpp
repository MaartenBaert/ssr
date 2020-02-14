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

AudioEncoder::AudioEncoder(Muxer* muxer, AVStream* stream, AVCodecContext *codec_context, AVCodec* codec, AVDictionary** options)
	: BaseEncoder(muxer, stream, codec_context, codec, options) {

#if !SSR_USE_AVCODEC_ENCODE_AUDIO2
	// allocate a temporary buffer
	if(GetCodecContext()->frame_size <= 1) {
		// This is really weird, the old API uses the size of the *output* buffer to determine the number of
		// input samples if the number of input samples (i.e. frame_size) is not fixed (i.e. frame_size <= 1).
		m_temp_buffer.resize(DEFAULT_FRAME_SAMPLES * GetCodecContext()->channels * av_get_bits_per_sample(GetCodecContext()->codec_id) / 8);
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
	return (GetCodecContext()->codec->capabilities & AV_CODEC_CAP_VARIABLE_FRAME_SIZE)? DEFAULT_FRAME_SAMPLES : GetCodecContext()->frame_size;
#else
	return (GetCodecContext()->frame_size <= 1)? DEFAULT_FRAME_SAMPLES : GetCodecContext()->frame_size;
#endif
}

AVSampleFormat AudioEncoder::GetSampleFormat() {
	return GetCodecContext()->sample_fmt;
}

unsigned int AudioEncoder::GetChannels() {
	return GetCodecContext()->channels;
}

unsigned int AudioEncoder::GetSampleRate() {
	return GetCodecContext()->sample_rate;
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
		if(AVCodecSupportsSampleFormat(codec, SUPPORTED_SAMPLE_FORMATS[i].m_format)) {
			//qDebug() << codec_name << "supported by" << SUPPORTED_SAMPLE_FORMATS[i].m_name;
			return true;
		}
	}
	return false;
}

void AudioEncoder::PrepareStream(AVStream* stream, AVCodecContext* codec_context, AVCodec* codec, AVDictionary** options, const std::vector<std::pair<QString, QString> >& codec_options,
								 unsigned int bit_rate, unsigned int channels, unsigned int sample_rate) {

	if(channels == 0) {
		Logger::LogError("[AudioEncoder::PrepareStream] " + Logger::tr("Error: Channel count is zero."));
		throw LibavException();
	}
	if(sample_rate == 0) {
		Logger::LogError("[AudioEncoder::PrepareStream] " + Logger::tr("Error: Sample rate is zero."));
		throw LibavException();
	}

	codec_context->bit_rate = bit_rate;
	codec_context->channels = channels;
	codec_context->channel_layout = (channels == 1)? AV_CH_LAYOUT_MONO : AV_CH_LAYOUT_STEREO;
	codec_context->sample_rate = sample_rate;
	codec_context->time_base.num = 1;
	codec_context->time_base.den = sample_rate;
#if SSR_USE_AVSTREAM_TIME_BASE
	stream->time_base = codec_context->time_base;
#endif
	codec_context->thread_count = 1;

	// parse options
	QString sample_format_name;
	for(unsigned int i = 0; i < codec_options.size(); ++i) {
		const QString &key = codec_options[i].first, &value = codec_options[i].second;
		if(key == "threads") {
			codec_context->thread_count = ParseCodecOptionInt(key, value, 1, 100);
		} else if(key == "qscale") {
			codec_context->flags |= AV_CODEC_FLAG_QSCALE;
			codec_context->global_quality = lrint(ParseCodecOptionDouble(key, value, -1.0e6, 1.0e6, FF_QP2LAMBDA));
		} else if(key == "sampleformat") {
			sample_format_name = value;
		} else {
			av_dict_set(options, key.toUtf8().constData(), value.toUtf8().constData(), 0);
		}
	}

	// choose the sample format
	codec_context->sample_fmt = AV_SAMPLE_FMT_NONE;
	for(unsigned int i = 0; i < SUPPORTED_SAMPLE_FORMATS.size(); ++i) {
		if(!sample_format_name.isEmpty() && sample_format_name != SUPPORTED_SAMPLE_FORMATS[i].m_name)
			continue;
		if(!AVCodecSupportsSampleFormat(codec, SUPPORTED_SAMPLE_FORMATS[i].m_format))
			continue;
		Logger::LogInfo("[AudioEncoder::PrepareStream] " + Logger::tr("Using sample format %1.").arg(SUPPORTED_SAMPLE_FORMATS[i].m_name));
		codec_context->sample_fmt = SUPPORTED_SAMPLE_FORMATS[i].m_format;
		break;
	}
	if(codec_context->sample_fmt == AV_SAMPLE_FMT_NONE) {
		Logger::LogError("[AudioEncoder::PrepareStream] " + Logger::tr("Error: Encoder requires an unsupported sample format!"));
		throw LibavException();
	}

}

bool AudioEncoder::EncodeFrame(AVFrameWrapper* frame) {

	if(frame != NULL) {
#if SSR_USE_AVFRAME_NB_SAMPLES
		assert((unsigned int) frame->GetFrame()->nb_samples == GetFrameSize());
#endif
#if SSR_USE_AVFRAME_CHANNELS
		assert(frame->GetFrame()->channels == GetCodecContext()->channels);
#endif
#if SSR_USE_AVFRAME_SAMPLE_RATE
		assert(frame->GetFrame()->sample_rate == GetCodecContext()->sample_rate);
#endif
#if SSR_USE_AVFRAME_FORMAT
		assert(frame->GetFrame()->format == GetCodecContext()->sample_fmt);
#endif
	}

#if SSR_USE_AVCODEC_SEND_RECEIVE

	// send a frame
	AVFrame *avframe = (frame == NULL)? NULL : frame->Release();
	try {
		if(avcodec_send_frame(GetCodecContext(), avframe) < 0) {
			Logger::LogError("[AudioEncoder::EncodeFrame] " + Logger::tr("Error: Sending of audio frame failed!"));
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
			Logger::LogError("[AudioEncoder::EncodeFrame] " + Logger::tr("Error: Receiving of audio packet failed!"));
			throw LibavException();
		}
	}

#elif SSR_USE_AVCODEC_ENCODE_AUDIO2

	// allocate a packet
	std::unique_ptr<AVPacketWrapper> packet(new AVPacketWrapper());

	// encode the frame
	int got_packet;
	if(avcodec_encode_audio2(GetCodecContext(), packet->GetPacket(), (frame == NULL)? NULL : frame->GetFrame(), &got_packet) < 0) {
		Logger::LogError("[AudioEncoder::EncodeFrame] " + Logger::tr("Error: Encoding of audio frame failed!"));
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
	short *data = (frame == NULL)? NULL : (short*) frame->GetFrame()->data[0];
	int bytes_encoded = avcodec_encode_audio(GetCodecContext(), m_temp_buffer.data(), m_temp_buffer.size(), data);
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
		if(GetCodecContext()->coded_frame != NULL && GetCodecContext()->coded_frame->pts != (int64_t) AV_NOPTS_VALUE)
			packet->GetPacket()->pts = GetCodecContext()->coded_frame->pts;

		// send the packet to the muxer
		GetMuxer()->AddPacket(GetStream()->index, std::move(packet));
		IncrementPacketCounter();
		return true;

	} else {
		return false;
	}

#endif

}
