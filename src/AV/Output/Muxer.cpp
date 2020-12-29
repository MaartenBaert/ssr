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

#include "Muxer.h"

#include "Logger.h"
#include "AVWrapper.h"
#include "BaseEncoder.h"
#include "VideoEncoder.h"
#include "AudioEncoder.h"

Muxer::Muxer(const QString& container_name, const QString& output_file) {

	m_container_name = container_name;
	m_output_file = output_file;

	m_format_context = NULL;
	m_started = false;

	// initialize stream data
	for(int i = 0; i < MUXER_MAX_STREAMS; ++i) {
		StreamLock lock(&m_stream_data[i]);
		lock->m_is_done = false;
		m_encoders[i] = NULL;
	}

	// initialize shared data
	{
		SharedLock lock(&m_shared_data);
		lock->m_total_bytes = 0;
		lock->m_stats_actual_bit_rate = 0.0;
		lock->m_stats_previous_time = NOPTS_DOUBLE;
		lock->m_stats_previous_bytes = 0;
	}

	// initialize thread signals
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

	if(m_started) {

		// stop the encoders
		Logger::LogInfo("[Muxer::~Muxer] " + Logger::tr("Stopping encoders ..."));
		for(unsigned int i = 0; i < m_format_context->nb_streams; ++i) {
			m_encoders[i]->Stop(); // no deadlock: nothing in Muxer is locked in this thread (and BaseEncoder::Stop is lock-free, but that could change)
		}

		// wait for the thread to stop
		if(m_thread.joinable()) {
			Logger::LogInfo("[Muxer::~Muxer] " + Logger::tr("Waiting for muxer thread to stop ..."));
			m_thread.join();
		}

	}

	// free everything
	Free();

}

VideoEncoder* Muxer::AddVideoEncoder(const QString& codec_name, const std::vector<std::pair<QString, QString> >& codec_options,
									 unsigned int bit_rate, unsigned int width, unsigned int height, unsigned int frame_rate) {
	AVCodec *codec = FindCodec(codec_name);
	AVCodecContext *codec_context = NULL;
	AVStream *stream = AddStream(codec, &codec_context);
	VideoEncoder *encoder;
	AVDictionary *options = NULL;
	try {
		VideoEncoder::PrepareStream(stream, codec_context, codec, &options, codec_options, bit_rate, width, height, frame_rate);
		m_encoders[stream->index] = encoder = new VideoEncoder(this, stream, codec_context, codec, &options);
#if SSR_USE_AVSTREAM_CODECPAR
		if(avcodec_parameters_from_context(stream->codecpar, codec_context) < 0) {
			Logger::LogError("[Muxer::AddVideoEncoder] " + Logger::tr("Error: Can't copy parameters to stream!"));
			throw LibavException();
		}
#endif
		av_dict_free(&options);
	} catch(...) {
		av_dict_free(&options);
		throw;
	}
	return encoder;
}

AudioEncoder* Muxer::AddAudioEncoder(const QString& codec_name, const std::vector<std::pair<QString, QString> >& codec_options,
									 unsigned int bit_rate, unsigned int channels, unsigned int sample_rate) {
	AVCodec *codec = FindCodec(codec_name);
	AVCodecContext *codec_context = NULL;
	AVStream *stream = AddStream(codec, &codec_context);
	AudioEncoder *encoder;
	AVDictionary *options = NULL;
	try {
		AudioEncoder::PrepareStream(stream, codec_context, codec, &options, codec_options, bit_rate, channels, sample_rate);
		m_encoders[stream->index] = encoder = new AudioEncoder(this, stream, codec_context, codec, &options);
#if SSR_USE_AVSTREAM_CODECPAR
		if(avcodec_parameters_from_context(stream->codecpar, codec_context) < 0) {
			Logger::LogError("[Muxer::AddAudioEncoder] " + Logger::tr("Error: Can't copy parameters to stream!"));
			throw LibavException();
		}
#endif
		av_dict_free(&options);
	} catch(...) {
		av_dict_free(&options);
		throw;
	}
	return encoder;
}

void Muxer::Start() {
	assert(!m_started);

	// make sure all encoders were created successfully
	for(unsigned int i = 0; i < m_format_context->nb_streams; ++i) {
		assert(m_encoders[i] != NULL);
	}

	// write header
	if(avformat_write_header(m_format_context, NULL) != 0) {
		Logger::LogError("[Muxer::Start] " + Logger::tr("Error: Can't write header!", "Don't translate 'header'"));
		throw LibavException();
	}

	m_started = true;
	m_thread = std::thread(&Muxer::MuxerThread, this);

}

void Muxer::Finish() {
	assert(m_started);
	Logger::LogInfo("[Muxer::Finish] " + Logger::tr("Finishing encoders ..."));
	for(unsigned int i = 0; i < m_format_context->nb_streams; ++i) {
		assert(m_encoders[i] != NULL);
		m_encoders[i]->Finish(); // no deadlock: nothing in Muxer is locked in this thread (and BaseEncoder::Finish is lock-free, but that could change)
	}
}

double Muxer::GetActualBitRate() {
	SharedLock lock(&m_shared_data);
	return lock->m_stats_actual_bit_rate;
}

uint64_t Muxer::GetTotalBytes() {
	SharedLock lock(&m_shared_data);
	return lock->m_total_bytes;
}

void Muxer::EndStream(unsigned int stream_index) {
	assert(stream_index < m_format_context->nb_streams);
	StreamLock lock(&m_stream_data[stream_index]);
	lock->m_is_done = true;
}

void Muxer::AddPacket(unsigned int stream_index, std::unique_ptr<AVPacketWrapper> packet) {
	assert(m_started);
	assert(stream_index < m_format_context->nb_streams);
	StreamLock lock(&m_stream_data[stream_index]);
	lock->m_packet_queue.push_back(std::move(packet));
}

unsigned int Muxer::GetQueuedPacketCount(unsigned int stream_index) {
	assert(m_started);
	assert(stream_index < m_format_context->nb_streams);
	StreamLock lock(&m_stream_data[stream_index]);
	return lock->m_packet_queue.size();
}

void Muxer::Init() {

	// get the format we want (this is just a pointer, we don't have to free this)
	AVOutputFormat *format = av_guess_format(m_container_name.toUtf8().constData(), NULL, NULL);
	if(format == NULL) {
		Logger::LogError("[Muxer::Init] " + Logger::tr("Error: Can't find chosen output format!"));
		throw LibavException();
	}

	Logger::LogInfo("[Muxer::Init] " + Logger::tr("Using format %1 (%2).").arg(format->name).arg(format->long_name));

	// allocate format context
	// ffmpeg probably wants us to use avformat_alloc_output_context2 instead, but libav doesn't have it and I can't figure out why it's needed anyway
	m_format_context = avformat_alloc_context();
	if(m_format_context == NULL) {
		Logger::LogError("[Muxer::Init] " + Logger::tr("Error: Can't allocate format context!"));
		throw LibavException();
	}
	m_format_context->oformat = format;

	// open file
	if(avio_open(&m_format_context->pb, QFile::encodeName(m_output_file).constData(), AVIO_FLAG_WRITE) < 0) {
		Logger::LogError("[Muxer::Init] " + Logger::tr("Error: Can't open output file!"));
		throw LibavException();
	}

}

void Muxer::Free() {
	if(m_format_context != NULL) {

		// write trailer (needed to free private muxer data)
		if(m_started) {
			if(av_write_trailer(m_format_context) != 0) {
				// we can't throw exceptions here because this is called from the destructor
				Logger::LogError("[Muxer::Free] " + Logger::tr("Error: Can't write trailer, continuing anyway.", "Don't translate 'trailer'"));
			}
			m_started = false;
		}

		// destroy the encoders
		for(unsigned int i = 0; i < m_format_context->nb_streams; ++i) {
			if(m_encoders[i] != NULL) {
				delete m_encoders[i]; // no deadlock: nothing in Muxer is locked in this thread
				m_encoders[i] = NULL;
			}
		}

		// close file
		if(m_format_context->pb != NULL) {
			avio_close(m_format_context->pb);
			m_format_context->pb = NULL;
		}

		// free everything
#if SSR_USE_AVFORMAT_FREE_CONTEXT
		avformat_free_context(m_format_context);
		m_format_context = NULL;
#else
		for(unsigned int i = 0; i < m_format_context->nb_streams; ++i) {
			av_freep(&m_format_context->streams[i]->codec);
			av_freep(&m_format_context->streams[i]);
		}
		av_free(m_format_context);
		m_format_context = NULL;
#endif

	}
}

AVCodec* Muxer::FindCodec(const QString& codec_name) {
	AVCodec *codec = avcodec_find_encoder_by_name(codec_name.toUtf8().constData());
	if(codec == NULL) {
		Logger::LogError("[Muxer::FindCodec] " + Logger::tr("Error: Can't find codec!"));
		throw LibavException();
	}
	return codec;
}

AVStream* Muxer::AddStream(AVCodec* codec, AVCodecContext** codec_context) {
	assert(!m_started);
	assert(m_format_context->nb_streams < MUXER_MAX_STREAMS);

	Logger::LogInfo("[Muxer::AddStream] " + Logger::tr("Using codec %1 (%2).").arg(codec->name).arg(codec->long_name));

	// create a new stream
#if SSR_USE_AVSTREAM_CODECPAR
	AVStream *stream = avformat_new_stream(m_format_context, NULL);
#elif SSR_USE_AVFORMAT_NEW_STREAM
	AVStream *stream = avformat_new_stream(m_format_context, codec);
#else
	AVStream *stream = av_new_stream(m_format_context, m_format_context->nb_streams);
#endif
	if(stream == NULL) {
		Logger::LogError("[Muxer::AddStream] " + Logger::tr("Error: Can't create new stream!"));
		throw LibavException();
	}
	assert(stream->index == (int) m_format_context->nb_streams - 1);
#if SSR_USE_AVSTREAM_CODECPAR
	*codec_context = avcodec_alloc_context3(codec);
	if(*codec_context == NULL) {
		Logger::LogError("[Muxer::AddStream] " + Logger::tr("Error: Can't create new codec context!"));
		throw LibavException();
	}
#else
	assert(stream->codec != NULL);
	*codec_context = stream->codec;
#endif
	//stream->id = m_format_context->nb_streams - 1;

#if !SSR_USE_AVFORMAT_NEW_STREAM
	// initialize the codec context (only needed for old API)
	if(avcodec_get_context_defaults3(*codec_context, codec) < 0) {
		Logger::LogError("[Muxer::AddStream] " + Logger::tr("Error: Can't get codec context defaults!"));
		throw LibavException();
	}
	(*codec_context)->codec_id = codec->id;
	(*codec_context)->codec_type = codec->type;
#endif

	// not sure why this is needed, but it's in the example code and it doesn't work without this
	if(m_format_context->oformat->flags & AVFMT_GLOBALHEADER)
		(*codec_context)->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;

	// if the codec is experimental, allow it
	if(codec->capabilities & AV_CODEC_CAP_EXPERIMENTAL) {
		Logger::LogWarning("[Muxer::AddStream] " + Logger::tr("Warning: This codec is considered experimental by libav/ffmpeg."));
		(*codec_context)->strict_std_compliance = FF_COMPLIANCE_EXPERIMENTAL;
	}

#if SSR_USE_SIDE_DATA_ONLY_PACKETS && !SSR_USE_SIDE_DATA_ONLY_PACKETS_DEPRECATED
	// this option was added with the intent to deprecate it again in the next version,
	// because the ffmpeg/libav devs like deprecating things :)
	(*codec_context)->side_data_only_packets = 1;
#endif

	return stream;
}

void Muxer::MuxerThread() {
	try {

		Logger::LogInfo("[Muxer::MuxerThread] " + Logger::tr("Muxer thread started."));

		double total_time = 0.0;

		// start muxing
		for( ; ; ) {

			// get a packet from a stream that isn't done yet
			std::unique_ptr<AVPacketWrapper> packet;
			unsigned int current_stream = 0, streams_done = 0;
			for(unsigned int i = 0; i < m_format_context->nb_streams; ++i) {
				StreamLock lock(&m_stream_data[i]);
				if(lock->m_packet_queue.empty()) {
					if(lock->m_is_done)
						++streams_done;
				} else {
					current_stream = i;
					packet = std::move(lock->m_packet_queue.front());
					lock->m_packet_queue.pop_front();
					break;
				}
			}

			// if all streams are done, we can stop
			if(streams_done == m_format_context->nb_streams) {
				break;
			}

			// if there is no packet, wait and try again later
			if(packet == NULL) {
				usleep(20000);
				continue;
			}

			// try to figure out the time (the exact value is not critical, it's only used for bitrate statistics)
			AVStream *stream = m_encoders[current_stream]->GetStream();
			AVCodecContext *codec_context = m_encoders[current_stream]->GetCodecContext();
			double packet_time = 0.0;
			if(packet->GetPacket()->dts != (int64_t) AV_NOPTS_VALUE)
				packet_time = (double) packet->GetPacket()->dts * ToDouble(codec_context->time_base);
			else if(packet->GetPacket()->pts != (int64_t) AV_NOPTS_VALUE)
				packet_time = (double) packet->GetPacket()->pts * ToDouble(codec_context->time_base);
			if(packet_time > total_time)
				total_time = packet_time;

			// prepare packet
			packet->GetPacket()->stream_index = current_stream;
#if SSR_USE_AV_PACKET_RESCALE_TS
			av_packet_rescale_ts(packet->GetPacket(), codec_context->time_base, stream->time_base);
#else
			if(packet->GetPacket()->pts != (int64_t) AV_NOPTS_VALUE) {
				packet->GetPacket()->pts = av_rescale_q(packet->GetPacket()->pts, codec_context->time_base, stream->time_base);
			}
			if(packet->GetPacket()->dts != (int64_t) AV_NOPTS_VALUE) {
				packet->GetPacket()->dts = av_rescale_q(packet->GetPacket()->dts, codec_context->time_base, stream->time_base);
			}
#endif

			// write the packet (again, why does libav/ffmpeg call this a frame?)
			if(av_interleaved_write_frame(m_format_context, packet->GetPacket()) != 0) {
				Logger::LogError("[Muxer::MuxerThread] " + Logger::tr("Error: Can't write frame to muxer!"));
				throw LibavException();
			}

			// the data is now owned by libav/ffmpeg, so don't free it
			packet->SetFreeOnDestruct(false);

			// update the byte counter
			{
				SharedLock lock(&m_shared_data);
				lock->m_total_bytes = m_format_context->pb->pos + (m_format_context->pb->buf_ptr - m_format_context->pb->buffer);
				if(lock->m_stats_previous_time == NOPTS_DOUBLE) {
					lock->m_stats_previous_time = total_time;
					lock->m_stats_previous_bytes = lock->m_total_bytes;
				}
				double timedelta = total_time - lock->m_stats_previous_time;
				if(timedelta > 0.999999) {
					lock->m_stats_actual_bit_rate = (double) ((lock->m_total_bytes - lock->m_stats_previous_bytes) * 8) / timedelta;
					lock->m_stats_previous_time = total_time;
					lock->m_stats_previous_bytes = lock->m_total_bytes;
				}
			}

		}

		// tell the others that we're done
		m_is_done = true;

		Logger::LogInfo("[Muxer::MuxerThread] " + Logger::tr("Muxer thread stopped."));

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError("[Muxer::MuxerThread] " + Logger::tr("Exception '%1' in muxer thread.").arg(e.what()));
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[Muxer::MuxerThread] " + Logger::tr("Unknown exception in muxer thread."));
	}
}
