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

#include "VPair.h"

class Logger;
class Synchronizer;

class BaseInput : private QThread {

private:
	Logger *m_logger;
	Synchronizer *m_synchronizer;

	AVFormatContext *m_format_context;
	AVCodecContext *m_codec_context;
	AVMediaType m_stream_type;
	unsigned int m_stream_index;

	volatile bool m_should_stop, m_error_occurred;

protected:
	BaseInput(Logger* logger, Synchronizer* synchronizer);
	~BaseInput();

	// Called by the constructor of derived classes to open the input and start the input thread.
	void Start(const char* name, AVInputFormat* format, AVDictionary** options, AVMediaType stream_type);

	// Called by the destructor of derived classes to stop the input thread.
	void Stop();

	// Called by the input thread to get the minimum delay betheen frames. This can be used to throttle
	// the recording speed. Only useful for video. The default implementation always returns 0.
	virtual int64_t GetReadDelay();

	// Called by the input thread for each frame that is read.
	virtual void ReadFrame(AVFrame* frame) = 0;

	inline Logger* GetLogger() { return m_logger; }
	inline Synchronizer* GetSynchronizer() { return m_synchronizer; }
	/*inline AVFormatContext* GetFormatContext() { return m_format_context; }
	inline AVCodecContext* GetCodecContext() { return m_codec_context; }
	inline unsigned int GetStreamIndex() { return m_stream_index; }*/

public:
	// Returns whether an error has occurred in the input thread.
	// This function is thread-safe.
	inline bool HasErrorOccurred() { return m_error_occurred; }

private:
	virtual void run();

};
