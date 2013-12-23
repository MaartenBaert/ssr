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
#include "GLInjectInput.h"

#include "Logger.h"
#include "SSRVideoStreamReader.h"

#include "../glinject/ShmStructs.h"

// The highest expected latency between GLInject and the input thread.
const int64_t GLInjectInput::MAX_COMMUNICATION_LATENCY = 100000;

GLInjectInput::GLInjectInput(const QString& pid, const QString& source, const QString& program_name, bool record_cursor, bool limit_fps, unsigned int target_fps) {

	m_pid = pid;
	m_source = source;
	m_program_name = program_name;
	m_flags = ((record_cursor)? GLINJECT_FLAG_RECORD_CURSOR : 0) | ((limit_fps)? GLINJECT_FLAG_LIMIT_FPS : 0);
	m_target_fps = target_fps;

	m_stream_reader = NULL;

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

GLInjectInput::~GLInjectInput() {

	// tell the thread to stop
	if(m_thread.joinable()) {
		Logger::LogInfo("[GLInjectInput::~GLInjectInput] " + QObject::tr("Stopping input thread ..."));
		m_should_stop = true;
		m_thread.join();
	}

	// free everything
	Free();

}

void GLInjectInput::GetCurrentSize(unsigned int* width, unsigned int* height) {
	m_stream_reader->GetCurrentSize(width, height);
}

double GLInjectInput::GetFPS() {
	return m_stream_reader->GetFPS();
}

void GLInjectInput::Start() {
	m_stream_reader->ChangeCaptureParameters(m_flags | GLINJECT_FLAG_CAPTURE_ENABLED, m_target_fps);
}

void GLInjectInput::Stop() {
	m_stream_reader->ChangeCaptureParameters(m_flags, m_target_fps);
}

void GLInjectInput::Init() {

	// create the stream reader
	m_stream_reader = new SSRVideoStreamReader(m_pid.toStdString(), m_source.toStdString(), m_program_name.toStdString());

	// start the stream
	m_stream_reader->ChangeCaptureParameters(m_flags, m_target_fps);
	m_stream_reader->Clear();

	// start input thread
	m_should_stop = false;
	m_error_occurred = false;
	m_thread = std::thread(&GLInjectInput::InputThread, this);

}

void GLInjectInput::Free() {
	if(m_stream_reader != NULL) {
		m_stream_reader->ChangeCaptureParameters(0, 0);
		delete m_stream_reader;
		m_stream_reader = NULL;
	}
}

void GLInjectInput::InputThread() {
	try {

		Logger::LogInfo("[GLInjectInput::InputThread] " + QObject::tr("Input thread started."));

		//int64_t next_frame_time = hrt_time_micro();
		while(!m_should_stop) {

			// is a frame ready?
			int64_t timestamp;
			unsigned int width, height;
			int stride;
			void *data = m_stream_reader->GetFrame(&timestamp, &width, &height, &stride);
			if(data == NULL) {
				PushVideoPing(hrt_time_micro() - MAX_COMMUNICATION_LATENCY);
				usleep(10000);
				continue;
			}

			// if the stride is negative, change the pointer
			// this is needed because OpenGL stores frames upside-down
			if(stride < 0) {
				data = (char*) data + (size_t) (-stride) * (size_t) (height - 1);
			}

			// push the frame
			PushVideoFrame(width, height, (uint8_t*) data, stride, PIX_FMT_BGRA, timestamp);

			// go to the next frame
			m_stream_reader->NextFrame();

		}

		Logger::LogInfo("[GLInjectInput::InputThread] " + QObject::tr("Input thread stopped."));

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError("[GLInjectInput::InputThread] " + QObject::tr("Exception '%1' in input thread.").arg(e.what()));
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[GLInjectInput::InputThread] " + QObject::tr("Unknown exception in input thread."));
	}
}
