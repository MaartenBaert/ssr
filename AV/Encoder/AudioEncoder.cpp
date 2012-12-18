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
#include "AudioEncoder.h"

#include "Logger.h"
#include "AVWrapper.h"
#include "Muxer.h"

AudioEncoder::AudioEncoder(Logger* logger, Muxer* muxer, const QString& codec_name, const std::vector<std::pair<QString, QString> >& codec_options,
						   unsigned int bit_rate, unsigned int sample_rate)
	: BaseEncoder(logger, muxer) {

	m_bit_rate = bit_rate;
	m_sample_rate = sample_rate;

	// start the encoder
	AVDictionary *options = NULL;
	try {
		for(unsigned int i = 0; i < codec_options.size(); ++i) {
			av_dict_set(&options, qPrintable(codec_options[i].first), qPrintable(codec_options[i].second), 0);
		}
		CreateCodec(qPrintable(codec_name), &options);
		av_dict_free(&options);
	} catch(...) {
		av_dict_free(&options);
		throw;
	}

}

unsigned int AudioEncoder::GetRequiredFrameSize() {
	return (GetCodecContext()->codec->capabilities & CODEC_CAP_VARIABLE_FRAME_SIZE)? 1024 : GetCodecContext()->frame_size;
}

void AudioEncoder::FillCodecContext() {

	GetCodecContext()->bit_rate = m_bit_rate;
	GetCodecContext()->sample_rate = m_sample_rate;
	GetCodecContext()->channels = 2;
	GetCodecContext()->sample_fmt = AV_SAMPLE_FMT_S16;

}

bool AudioEncoder::EncodeFrame(AVFrame* frame) {

	// allocate a packet
	std::unique_ptr<AVPacketWrapper> packet(new AVPacketWrapper());

	// encode the frame
	int got_packet;
	if(avcodec_encode_audio2(GetCodecContext(), packet.get(), frame, &got_packet) < 0) {
		GetLogger()->LogError("[AudioEncoder::EncodeFrame] Error: Encoding of audio frame failed!");
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

}

