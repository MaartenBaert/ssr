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
#include "BaseEncoder.h"

#include "Logger.h"
#include "AVWrapper.h"
#include "Muxer.h"

BaseEncoder::BaseEncoder(Muxer* muxer) {

	m_muxer = muxer;

	m_codec_context = NULL;

	{
		SharedLock lock(&m_shared_data);
		lock->m_total_frames = 0;
	}

}

BaseEncoder::~BaseEncoder() {

	// tell the thread to stop
	if(isRunning()) {
		Logger::LogInfo("[BaseEncoder::~BaseEncoder] Telling encoder thread to stop ...");
		m_should_stop = true;
		wait();
	}

	// free everything
	if(m_codec_context != NULL) {
		avcodec_close(m_codec_context);
		m_codec_context = NULL;
	}

}

void BaseEncoder::CreateCodec(const QString& codec_name, AVDictionary **options) {

	// get the codec we want
	AVCodec *codec = avcodec_find_encoder_by_name(qPrintable(codec_name));
	if(codec == NULL) {
		Logger::LogError("[BaseEncoder::CreateCodec] Error: Can't find codec!");
		throw LibavException();
	}
	m_delayed_packets = ((codec->capabilities & CODEC_CAP_DELAY) != 0);

	Logger::LogInfo(QString("[BaseEncoder::CreateCodec] Using codec ") + codec->name + " (" + codec->long_name + ").");

	// create stream and get codec context
	AVStream *stream = m_muxer->CreateStream(codec);
	m_codec_context = stream->codec;
	m_stream_index = stream->index;

	// if the codec is experimental, allow it
	if(codec->capabilities & CODEC_CAP_EXPERIMENTAL)
		m_codec_context->strict_std_compliance = FF_COMPLIANCE_EXPERIMENTAL;

	// set things like image size, frame rate, sample rate, bit rate ...
	FillCodecContext(codec);
	stream->sample_aspect_ratio = m_codec_context->sample_aspect_ratio;

	// open codec
	if(avcodec_open2(m_codec_context, codec, options) < 0) {
		Logger::LogError("[BaseEncoder::CreateCodec] Error: Can't open codec!");
		throw LibavException();
	}

	// start encoder thread
	m_should_stop = false;
	m_should_finish = false;
	m_is_done = false;
	m_error_occurred = false;
	start();

}

void BaseEncoder::Finish() {
	m_should_finish = true;
}

bool BaseEncoder::IsDone() {
	return m_is_done;
}

unsigned int BaseEncoder::GetTotalFrames() {
	SharedLock lock(&m_shared_data);
	return lock->m_total_frames;
}

unsigned int BaseEncoder::GetQueuedFrameCount() {
	SharedLock lock(&m_shared_data);
	return lock->m_frame_queue.size();
}

void BaseEncoder::AddFrame(std::unique_ptr<AVFrameWrapper> frame) {
	SharedLock lock(&m_shared_data);
	lock->m_frame_queue.push_back(std::move(frame));
	++lock->m_total_frames;
}

void BaseEncoder::run() {
	try {

		Logger::LogInfo("[BaseEncoder::run] Encoder thread started.");

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
					Logger::LogInfo("[BaseEncoder::run] Flushing encoder ...");
					break;
				}
				usleep(10000);
				continue;
			}

			// encode the frame
			EncodeFrame(frame.get());

		}

		// flush the encoder
		while(!m_should_stop) {
			if(!m_delayed_packets || !EncodeFrame(NULL)) {

				// tell the others that we're done
				m_muxer->EndStream(m_stream_index);
				m_is_done = true;

				break;
			}
		}

		Logger::LogInfo("[BaseEncoder::run] Encoder thread stopped.");

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError(QString("[BaseEncoder::run] Exception '") + e.what() + "' in encoder thread.");
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[BaseEncoder::run] Unknown exception in encoder thread.");
	}
}
