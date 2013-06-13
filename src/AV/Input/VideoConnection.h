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

#include "VPair.h"

// The video source/sink system keeps track of connections between video inputs and outputs.
// It decides where new frames should be sent. Using these connections is thread-safe,
// however only ONE thread should ever create or destroy connections (this includes destroying sources or sinks).

class VideoSource;
class VideoSink;

class VideoSource {

	friend class VideoSink;

private:
	struct SharedData {
		std::vector<VideoSink*> m_sinks;
	};
	typedef VPair<SharedData>::Lock SharedLock;

private:
	VPair<SharedData> m_shared_data;

protected:
	VideoSource();
	~VideoSource();

protected:
	int64_t CalculateVideoFrameInterval(unsigned int frame_rate);
	void PushVideoFrame(unsigned int width, unsigned int height, uint8_t* data, int stride, PixelFormat format, int64_t timestamp);

};

class VideoSink {

	friend class VideoSource;

private:
	VideoSource* m_source;

protected:
	VideoSink();
	~VideoSink();

public:
	// Connects the sink to a source. source can be NULL to disconnect the sink.
	void ConnectVideoSource(VideoSource* source);

public:
	virtual int64_t GetVideoFrameInterval() { return 0; }
	virtual void ReadVideoFrame(unsigned int width, unsigned int height, uint8_t* data, int stride, PixelFormat format, int64_t timestamp) = 0;

};
