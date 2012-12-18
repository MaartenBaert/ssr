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

class VideoEncoder : public BaseEncoder {

private:
	unsigned int m_bit_rate;
	unsigned int m_width, m_height, m_frame_rate;

	std::vector<uint8_t> m_temp_buffer;

public:
	VideoEncoder(Logger* logger, Muxer* muxer, const QString& codec_name, const std::vector<std::pair<QString, QString> >& codec_options,
				 unsigned int bit_rate, unsigned int width, unsigned int height, unsigned int frame_rate);

	inline unsigned int GetWidth() { return m_width; }
	inline unsigned int GetHeight() { return m_height; }
	inline unsigned int GetFrameRate() { return m_frame_rate; }

private:
	virtual void FillCodecContext();
	virtual bool EncodeFrame(AVFrame* frame);

};
