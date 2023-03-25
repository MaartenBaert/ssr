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

#pragma once
#include "Global.h"

#include "BaseEncoder.h"

class AudioEncoder : public BaseEncoder {

private:
	struct SampleFormatData {
		QString m_name;
		AVSampleFormat m_format;
	};

private:
	static const std::vector<SampleFormatData> SUPPORTED_SAMPLE_FORMATS;
	static const unsigned int DEFAULT_FRAME_SAMPLES;

private:
#if !SSR_USE_AVCODEC_ENCODE_AUDIO2
	std::vector<uint8_t> m_temp_buffer;
#endif

public:
	AudioEncoder(Muxer* muxer, AVStream* stream, AVCodecContext* codec_context, AVCodec* codec, AVDictionary** options);
	~AudioEncoder();

	// Returns the required frame size, i.e. the number of samples (for each channel).
	unsigned int GetFrameSize();

	// Returns the required sample format.
	AVSampleFormat GetSampleFormat();

	// Returns the number of audio channels.
	unsigned int GetChannels();

	// Returns the audio sample rate.
	unsigned int GetSampleRate();

public:
	static bool AVCodecIsSupported(const QString& codec_name);
	static void PrepareStream(AVStream* stream, AVCodecContext* codec_context, AVCodec* codec, AVDictionary** options, const std::vector<std::pair<QString, QString> >& codec_options,
							  unsigned int bit_rate, unsigned int channels, unsigned int sample_rate);

private:
	virtual bool EncodeFrame(AVFrameWrapper* frame) override;

};
