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

class VideoConnection;

class VideoSourceOrSink {
private:
	std::vector<VideoConnection*> m_connections;
protected:
	VideoSourceOrSink();
	~VideoSourceOrSink();
public: // internal
	void AddConnection(VideoConnection* connection);
	void RemoveConnection(VideoConnection* connection);
};

class VideoSource : public VideoSourceOrSink {
protected:
	VideoSource();
	void PushFrame(unsigned int width, unsigned int height, uint8_t* in_data, int in_stride, PixelFormat format, int64_t timestamp);
};

class VideoSink : public VideoSourceOrSink {
protected:
	VideoSink();
public:
	virtual void ReadFrame(unsigned int width, unsigned int height, uint8_t* in_data, int in_stride, PixelFormat format, int64_t timestamp);
};

class VideoConnection {

private:
	VideoSource *m_source;
	VideoSink *m_sink;

public:
	VideoConnection(VideoSource* source, VideoSink* sink);
	~VideoConnection();

public:
	inline VideoSource* GetSource() { return m_source; }
	inline VideoSink* GetSink() { return m_sink; }

};
