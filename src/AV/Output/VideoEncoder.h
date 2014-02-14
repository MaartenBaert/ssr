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

#pragma once
#include "Global.h"

#include "BaseEncoder.h"

class VideoEncoder : public BaseEncoder {

private:
	static const size_t THROTTLE_THRESHOLD_FRAMES, THROTTLE_THRESHOLD_PACKETS;
	static const std::vector<PixelFormat> SUPPORTED_PIXEL_FORMATS;

private:
	unsigned int m_bit_rate;
	unsigned int m_width, m_height, m_frame_rate;

	unsigned int m_opt_threads;
	unsigned int m_opt_minrate, m_opt_maxrate, m_opt_bufsize;

#if !SSR_USE_AVCODEC_PRIVATE_CRF
	unsigned int m_opt_crf;
#endif
#if !SSR_USE_AVCODEC_PRIVATE_PRESET
	QString m_opt_preset;
#endif

#if !SSR_USE_AVCODEC_ENCODE_VIDEO2
	std::vector<uint8_t> m_temp_buffer;
#endif

public:
	VideoEncoder(Muxer* muxer, const QString& codec_name, const std::vector<std::pair<QString, QString> >& codec_options,
				 unsigned int bit_rate, unsigned int width, unsigned int height, unsigned int frame_rate);
	~VideoEncoder();

	// Returns an additional delay (in us) between frames, based on the queue size, to avoid memory problems.
	// As long as the queues are relatively small, this function will just return 0.
	// This function is thread-safe.
	int64_t GetFrameDelay();

	inline unsigned int GetWidth() { return m_width; }
	inline unsigned int GetHeight() { return m_height; }
	inline unsigned int GetFrameRate() { return m_frame_rate; }

public:
	static bool AVCodecIsSupported(const QString& codec_name);

private:
	virtual void FillCodecContext(AVCodec* codec) override;
	virtual bool EncodeFrame(AVFrame* frame) override;

};
