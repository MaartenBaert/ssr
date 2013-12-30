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

#include "Global.h"
#include "BaseEncoder.h"

#include "Logger.h"
#include "AVWrapper.h"
#include "Muxer.h"

int ParseCodecOptionInt(const QString& key, const QString& value, int min, int max, int multiply, int fail) {
	bool parse_int;
	int value_int = value.toInt(&parse_int);
	if(parse_int) {
		return clamp(value_int, min, max) * multiply;
	} else {
		Logger::LogWarning("[ParseCodecOptionInt] " + QObject::tr("Error: Option '%1' could not be parsed!").arg(key));
		return fail;
	}
}

BaseEncoder::BaseEncoder(Muxer* muxer) {

	m_destructed = false;
	m_muxer = muxer;

	m_codec_context = NULL;

	// initialize thread signals
	m_should_stop = false;
	m_should_finish = false;
	m_is_done = false;
	m_error_occurred = false;

	{
		SharedLock lock(&m_shared_data);
		lock->m_total_frames = 0;
		lock->m_stats_actual_frame_rate = 0.0;
		lock->m_stats_previous_pts = AV_NOPTS_VALUE;
		lock->m_stats_previous_frames = 0;
	}

}

BaseEncoder::~BaseEncoder() {
	Q_ASSERT(m_destructed);
}

// Why not a real destructor? The problem is that a real destructor gets called *after* the derived class has already been destructed.
// This means virtual function calls, like EncodeFrame, will fail. This is a problem since the encoder thread doesn't know that the derived class is gone.
// To fix this, the derived class should call Destruct() in its destructor.
void BaseEncoder::Destruct() {

	// tell the thread to stop
	// normally the muxer should have stopped the thread already, unless the muxer wasn't actually started
	if(m_thread.joinable()) {
		Logger::LogInfo("[BaseEncoder::Stop] " + QObject::tr("Stopping encoder thread ..."));
		m_should_stop = true;
		m_thread.join();
	}

	// free everything
	if(m_codec_context != NULL) {
		avcodec_close(m_codec_context);
		m_codec_context = NULL;
	}

	m_destructed = true;

}

void BaseEncoder::CreateCodec(const QString& codec_name, AVDictionary **options) {

	// get the codec we want
	AVCodec *codec = avcodec_find_encoder_by_name(codec_name.toAscii().constData());
	if(codec == NULL) {
		Logger::LogError("[BaseEncoder::CreateCodec] " + QObject::tr("Error: Can't find codec!"));
		throw LibavException();
	}
	m_delayed_packets = ((codec->capabilities & CODEC_CAP_DELAY) != 0);

	Logger::LogInfo("[BaseEncoder::CreateCodec] " + QObject::tr("Using codec %1 (%2).").arg(codec->name).arg(codec->long_name));

	// create stream and get codec context
	AVStream *stream = m_muxer->CreateStream(codec);
	m_codec_context = stream->codec;
	m_stream_index = stream->index;

	// if the codec is experimental, allow it
	if(codec->capabilities & CODEC_CAP_EXPERIMENTAL) {
		Logger::LogWarning("[BaseEncoder::CreateCodec] " + QObject::tr("Warning: This codec is considered experimental by libav/ffmpeg."));
		m_codec_context->strict_std_compliance = FF_COMPLIANCE_EXPERIMENTAL;
	}

	// set things like image size, frame rate, sample rate, bit rate ...
	FillCodecContext(codec);
	stream->sample_aspect_ratio = m_codec_context->sample_aspect_ratio;

	// open codec
	if(avcodec_open2(m_codec_context, codec, options) < 0) {
		Logger::LogError("[BaseEncoder::CreateCodec] " + QObject::tr("Error: Can't open codec!"));
		throw LibavException();
	}

	// start encoder thread
	m_thread = std::thread(&BaseEncoder::EncoderThread, this);

}

double BaseEncoder::GetActualFrameRate() {
	SharedLock lock(&m_shared_data);
	return lock->m_stats_actual_frame_rate;
}

uint64_t BaseEncoder::GetTotalFrames() {
	SharedLock lock(&m_shared_data);
	return lock->m_total_frames;
}

unsigned int BaseEncoder::GetQueuedFrameCount() {
	SharedLock lock(&m_shared_data);
	return lock->m_frame_queue.size();
}

void BaseEncoder::AddFrame(std::unique_ptr<AVFrameWrapper> frame) {
	Q_ASSERT(m_muxer->IsStarted());
	Q_ASSERT(frame->GetFrame()->pts != (int64_t) AV_NOPTS_VALUE);
	SharedLock lock(&m_shared_data);
	++lock->m_total_frames;
	if(lock->m_stats_previous_pts == (int64_t) AV_NOPTS_VALUE) {
		lock->m_stats_previous_pts = frame->GetFrame()->pts;
		lock->m_stats_previous_frames = lock->m_total_frames;
	}
	double timedelta = (double) (frame->GetFrame()->pts - lock->m_stats_previous_pts) * ToDouble(m_codec_context->time_base);
	if(timedelta > 0.999999) {
		lock->m_stats_actual_frame_rate = (double) (lock->m_total_frames - lock->m_stats_previous_frames) / timedelta;
		lock->m_stats_previous_pts = frame->GetFrame()->pts;
		lock->m_stats_previous_frames = lock->m_total_frames;
	}
	lock->m_frame_queue.push_back(std::move(frame));
}

void BaseEncoder::Finish() {
	m_should_finish = true;
}

void BaseEncoder::Stop() {
	m_should_stop = true;
}

void BaseEncoder::EncoderThread() {

	try {

		Logger::LogInfo("[BaseEncoder::EncoderThread] " + QObject::tr("Encoder thread started."));

		// normal encoding
		while(!m_should_stop) {

			// get a frame
			std::unique_ptr<AVFrameWrapper> frame;
			{
				SharedLock lock(&m_shared_data);
				if(!lock->m_frame_queue.empty()) {
					frame = std::move(lock->m_frame_queue.front());
					lock->m_frame_queue.pop_front();
				}
			}
			if(frame == NULL) {
				if(m_should_finish) {
					break;
				}
				usleep(10000);
				continue;
			}

			// encode the frame
			EncodeFrame(frame->GetFrame());

		}

		// flush the encoder
		if(!m_should_stop && m_delayed_packets) {
			Logger::LogInfo("[BaseEncoder::EncoderThread] " + QObject::tr("Flushing encoder ..."));
			while(!m_should_stop && EncodeFrame(NULL));
		}

		// tell the others that we're done
		m_is_done = true;

		Logger::LogInfo("[BaseEncoder::EncoderThread] " + QObject::tr("Encoder thread stopped."));

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError("[BaseEncoder::EncoderThread] " + QObject::tr("Exception '%1' in encoder thread.").arg(e.what()));
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[BaseEncoder::EncoderThread] " + QObject::tr("Unknown exception in encoder thread."));
	}

	// always end the stream, even if there was an error, otherwise the muxer will wait forever
	m_muxer->EndStream(m_stream_index);

}
