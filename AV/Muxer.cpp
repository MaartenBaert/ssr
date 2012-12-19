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
#include "Muxer.h"

#include "Logger.h"
#include "AVWrapper.h"

static const unsigned int INVALID_STREAM = std::numeric_limits<unsigned int>::max();

Muxer::Muxer(Logger* logger, const QString& container_name, const QString& output_file) {

	m_logger = logger;

	m_container_name = container_name;
	m_output_file = output_file;

	m_format_context = NULL;
	m_started = false;

	// initialize stream data
	for(int i = 0; i < MUXER_MAX_STREAMS; ++i) {
		StreamLock lock(&m_stream_data[i]);
		lock->m_is_done = false;
	}

	// initialize shared data
	{
		SharedLock lock(&m_shared_data);
		lock->m_total_bytes = 0;
	}

	// initialize thread signals
	m_should_stop = false;
	m_is_done = false;
	m_error_occurred = false;

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

Muxer::~Muxer() {

	// tell the thread to stop
	if(isRunning()) {
		m_logger->LogInfo("[Muxer::~Muxer] Telling muxer thread to stop ...");
		m_should_stop = true;
		wait();
	}

	// free everything
	Free();

}

void Muxer::Start() {
	Q_ASSERT(!m_started);
	m_started = true;
	start();
}

bool Muxer::IsStarted() {
	return m_started;
}

uint64_t Muxer::GetTotalBytes() {
	SharedLock lock(&m_shared_data);
	return lock->m_total_bytes;
}

bool Muxer::IsDone() {
	return m_is_done;
}

AVStream* Muxer::CreateStream(AVCodec* codec) {
	Q_ASSERT(!m_started);
	Q_ASSERT(m_format_context->nb_streams < MUXER_MAX_STREAMS);

	// create a new stream
#if SSR_USE_AVFORMAT_NEW_STREAM
	AVStream *stream = avformat_new_stream(m_format_context, codec);
#else
	AVStream *stream = av_new_stream(m_format_context, m_format_context->nb_streams);
	avcodec_get_context_defaults3(stream->codec, codec);
	stream->codec->codec = codec;
	stream->codec->codec_id = codec->id;
	stream->codec->codec_type = codec->type;
#endif
	if(stream == NULL) {
		m_logger->LogError("[Muxer::AddStream] Error: Can't create new stream!");
		throw LibavException();
	}

	// not sure why this is needed, but it's in the example code and it doesn't work without this
	if(m_format_context->oformat->flags & AVFMT_GLOBALHEADER)
		stream->codec->flags |= CODEC_FLAG_GLOBAL_HEADER;

	return stream;
}

void Muxer::EndStream(unsigned int stream_index) {
	StreamLock lock(&m_stream_data[stream_index]);
	lock->m_is_done = true;
}

void Muxer::AddPacket(unsigned int stream_index, std::unique_ptr<AVPacketWrapper> packet) {
	StreamLock lock(&m_stream_data[stream_index]);
	lock->m_packet_queue.push_back(std::move(packet));
}

void Muxer::Init() {

	// get the format we want (this is just a pointer, we don't have to free this)
	AVOutputFormat *format = av_guess_format(qPrintable(m_container_name), NULL, NULL);
	if(format == NULL) {
		m_logger->LogError("[Muxer::Init] Error: Can't find chosen output format!");
		throw LibavException();
	}

	// allocate format context
	m_format_context = avformat_alloc_context();
	if(m_format_context == NULL) {
		m_logger->LogError("[Muxer::Init] Error: Can't allocate format context!");
		throw LibavException();
	}
	m_format_context->oformat = format;

	// open file
	if(avio_open(&m_format_context->pb, qPrintable(m_output_file), AVIO_FLAG_WRITE) < 0) {
		m_logger->LogError("[Muxer::Init] Error: Can't open output file!");
		throw LibavException();
	}

}

void Muxer::Free() {
	if(m_format_context != NULL) {
		for(unsigned int i = 0; i < m_format_context->nb_streams; ++i) {
			av_freep(&m_format_context->streams[i]->codec);
			av_freep(&m_format_context->streams[i]);
		}
		avio_close(m_format_context->pb);
		av_free(m_format_context);
		m_format_context = NULL;
	}
}

void Muxer::run() {
	try {

		m_logger->LogInfo("[Muxer::run] Muxer thread started.");

		// write header
		if(avformat_write_header(m_format_context, NULL) != 0) {
			m_logger->LogError("[Muxer::run] Error: Can't write header!");
			throw LibavException();
		}

		// start muxing
		while(!m_should_stop) {

			// find the oldest packet
			bool shouldwait = false;
			unsigned int oldest_stream = INVALID_STREAM;
			double oldest_pts = std::numeric_limits<double>::max();
			for(unsigned int i = 0; i < m_format_context->nb_streams; ++i) {
				StreamLock lock(&m_stream_data[i]);
				if(lock->m_packet_queue.empty()) {
					if(!lock->m_is_done) {
						shouldwait = true;
						break;
					}
				} else {
					double pts = ToDouble(m_format_context->streams[i]->pts) * ToDouble(m_format_context->streams[i]->time_base);
					if(pts < oldest_pts) {
						oldest_stream = i;
						oldest_pts = pts;
					}
				}
			}

			// should we wait for more packets?
			if(shouldwait) {
				usleep(10000);
				continue;
			}

			// if there are no packets left and we don't have to wait for more, we're done
			if(oldest_stream == INVALID_STREAM) {

				m_logger->LogInfo("[Muxer::run] Finished muxing, writing trailer ...");

				// write trailer and tell the others that we're done
				if(av_write_trailer(m_format_context) != 0) {
					m_logger->LogError("[Muxer::run] Error: Can't write trailer!");
					throw LibavException();
				}
				m_is_done = true;

				break;

			}

			// get the packet
			std::unique_ptr<AVPacketWrapper> packet;
			{
				StreamLock lock(&m_stream_data[oldest_stream]);
				packet = std::move(lock->m_packet_queue.front());
				lock->m_packet_queue.pop_front();
			}
			AVStream *st = m_format_context->streams[oldest_stream];
			packet->stream_index = oldest_stream;
			if(packet->pts != (int64_t) AV_NOPTS_VALUE) {
				//packet->pts =  (int64_t) ((double) packet->pts * ToDouble(st->codec->time_base) / ToDouble(st->time_base) + 0.5);
				packet->pts = av_rescale_q(packet->pts, st->codec->time_base, st->time_base);
			}

			// write the packet (again, why does libav call this a frame?)
			// The packet should already be interleaved now, but containers can have custom interleaving specifications,
			// so it's a good idea to call av_interleaved_write_frame anyway.
			if(av_interleaved_write_frame(m_format_context, packet.get()) != 0) {
				m_logger->LogError("[Muxer::run] Error: Can't write frame to muxer!");
				throw LibavException();
			}

			// the data is now owned by libav, so don't free it
			packet->m_free_on_destruct = false;

			// update the byte counter
			{
				SharedLock lock(&m_shared_data);
				lock->m_total_bytes = m_format_context->pb->pos + (m_format_context->pb->buf_ptr - m_format_context->pb->buffer);
			}

		}

		m_logger->LogInfo("[Muxer::run] Muxer thread stopped.");

	} catch(const std::exception& e) {
		m_error_occurred = true;
		m_logger->LogError(QString("[Muxer::run] Exception '") + e.what() + "' in muxer thread.");
	} catch(...) {
		m_error_occurred = true;
		m_logger->LogError("[Muxer::run] Unknown exception in muxer thread.");
	}
}
