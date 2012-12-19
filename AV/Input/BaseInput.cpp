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
#include "BaseInput.h"

#include "Logger.h"
#include "AVWrapper.h"

static const unsigned int INVALID_STREAM = std::numeric_limits<unsigned int>::max();

BaseInput::BaseInput(Logger* logger, Synchronizer* synchronizer) {

	m_logger = logger;
	m_synchronizer = synchronizer;

	m_format_context = NULL;
	m_codec_context = NULL;

}

BaseInput::~BaseInput() {
	Q_ASSERT(!isRunning());

	// close everything
	if(m_codec_context != NULL) {
		avcodec_close(m_codec_context);
		m_codec_context = NULL;
	}
	if(m_format_context != NULL) {
#if SSR_USE_AVFORMAT_CLOSE_INPUT
		avformat_close_input(&m_format_context);
#else
		av_close_input_file(m_format_context);
#endif
		m_format_context = NULL;
	}

}

void BaseInput::Start(const char* name, AVInputFormat* format, AVDictionary** options, AVMediaType stream_type) {
	Q_ASSERT(!isRunning());

	// open device
	m_format_context = NULL;
	if(avformat_open_input(&m_format_context, name, format, options) < 0) {
		m_logger->LogError("[BaseInput::Start] Error: Can't open input!");
		throw LibavException();
	}

	// find the right stream
	m_stream_type = stream_type;
	m_stream_index = INVALID_STREAM;
	for(unsigned int i = 0; i < m_format_context->nb_streams; ++i) {
		if(m_format_context->streams[i]->codec->codec_type == m_stream_type) {
			m_stream_index = i;
			break;
		}
	}
	if(m_stream_index == INVALID_STREAM) {
		m_logger->LogError("[BaseInput::Start] Error: Can't find a stream of the right type!");
		throw LibavException();
	}

	// get the codec for the stream
	m_codec_context = m_format_context->streams[m_stream_index]->codec;
	AVCodec *codec = avcodec_find_decoder(m_codec_context->codec_id);
	if(codec == NULL) {
		m_logger->LogError("[BaseInput::Start] Error: Can't find codec!");
		throw LibavException();
	}
	if(codec->capabilities & CODEC_CAP_TRUNCATED)
		m_codec_context->flags |= CODEC_FLAG_TRUNCATED;

	// open codec
	if(avcodec_open2(m_codec_context, codec, NULL) < 0) {
		m_logger->LogError("[BaseInput::Start] Error: Can't open codec!");
		throw LibavException();
	}

	m_logger->LogInfo(QString("[BaseInput::Start] Using codec ") + codec->name + " (" + codec->long_name + ").");

	// start input thread
	m_should_stop = false;
	m_error_occurred = false;
	start();

}

void BaseInput::Stop() {

	// tell the thread to stop
	if(isRunning()) {
		m_logger->LogInfo("[BaseInput::~BaseInput] Telling input thread to stop ...");
		m_should_stop = true;
		wait();
	}

}

int64_t BaseInput::GetReadDelay() {
	return 0;
}

void BaseInput::run() {
	try {

		m_logger->LogInfo("[BaseInput::run] Input thread started.");

		int64_t last_packet_time = hrt_time_micro();

		while(!m_should_stop) {

			// artificial delay
			int64_t delay = GetReadDelay();
			if(delay != 0) {
				int64_t wait = last_packet_time + delay - hrt_time_micro();
				if(wait > 10000) {
					// we can't sleep too long because we still have to check the m_should_stop flag periodically
					usleep(10000);
					continue;
				} else if(wait > 0) {
					usleep(wait);
				}
			}

			// read a packet (not sure why libav calls it a frame)
			AVPacketWrapper packet;
			if(av_read_frame(m_format_context, &packet) < 0) {
				m_logger->LogError("[BaseInput::run] Error: Can't read packet!");
				throw LibavException();
			}

			// is this the stream we want?
			if(packet.stream_index == (int) m_stream_index) {

				// save the current time
				last_packet_time = hrt_time_micro();

				// read the packet
				int current_position = 0;
				while(current_position < packet.size) {

					// get a temporary frame
					AVFrameWrapper temp_frame;

					// decode
					AVPacket temp_packet = packet;
					temp_packet.data += current_position;
					temp_packet.size -= current_position;
					int got_frame, bytes_decoded;
					if(m_stream_type == AVMEDIA_TYPE_VIDEO) {
						temp_frame.m_free_on_destruct = false;
						bytes_decoded = avcodec_decode_video2(m_codec_context, &temp_frame, &got_frame, &temp_packet);
					} else {
#if SSR_USE_AVCODEC_DECODE_AUDIO4
						temp_frame.m_free_on_destruct = false;
						bytes_decoded = avcodec_decode_audio4(m_codec_context, &temp_frame, &got_frame, &temp_packet);
#else
						int temp_frame_size = AVCODEC_MAX_AUDIO_FRAME_SIZE;
						temp_frame.data[0] = (uint8_t*) av_malloc(temp_frame_size);
						if(temp_frame.data[0] == NULL) {
							throw std::bad_alloc();
						}
						bytes_decoded = avcodec_decode_audio3(m_codec_context, (short*) temp_frame.data[0], &temp_frame_size, &temp_packet);
						got_frame = (temp_frame_size > 0)? 1 : 0;
						temp_frame.nb_samples = temp_frame_size / (2 * m_codec_context->channels);
#if SSR_USE_AVFRAME_FORMAT
						temp_frame.format = AV_SAMPLE_FMT_S16;
#endif
#endif
					}
					if(bytes_decoded < 0) {
						m_logger->LogError("[BaseInput::run] Error: Decoding of packet failed!");
						throw LibavException();
					}
					current_position += bytes_decoded;

					// do we have a frame?
					if(got_frame != 0) {

						// set timestamp and save the time so we have an absolute time reference
						// the pkt_dts field isn't needed here AFAIK
						temp_frame.pts = temp_packet.pts;
						temp_frame.pkt_dts = last_packet_time;

						// read the frame
						ReadFrame(&temp_frame);

					}

				}

			}

		}

		m_logger->LogInfo("[BaseInput::run] Input thread stopped.");

	} catch(const std::exception& e) {
		m_error_occurred = true;
		m_logger->LogError(QString("[BaseInput::run] Exception '") + e.what() + "' in input thread.");
	} catch(...) {
		m_error_occurred = true;
		m_logger->LogError("[BaseInput::run] Unknown exception in input thread.");
	}
}
