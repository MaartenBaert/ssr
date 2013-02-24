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

#pragma once
#include "StdAfx.h"

#include "BaseEncoder.h"

class AudioEncoder : public BaseEncoder {

private:
	unsigned int m_bit_rate;
	unsigned int m_sample_rate;

#if !SSR_USE_AVCODEC_ENCODE_AUDIO2
	std::vector<uint8_t> m_temp_buffer;
#endif

public:
	AudioEncoder(Muxer* muxer, const QString& codec_name, const std::vector<std::pair<QString, QString> >& codec_options,
				 unsigned int bit_rate, unsigned int sample_rate);

	// Returns the required frame size, i.e. the number of samples (for each channel).
	unsigned int GetRequiredFrameSize();

	// Returns the required sample format.
	AVSampleFormat GetRequiredSampleFormat();

	inline unsigned int GetSampleRate() { return m_sample_rate; }

private:
	virtual void FillCodecContext(AVCodec* codec);
	virtual bool EncodeFrame(AVFrameWrapper* frame);

};
