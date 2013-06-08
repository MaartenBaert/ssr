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
#include "VideoInput.h"

VideoSourceOrSink::VideoSourceOrSink() {

}

VideoSourceOrSink::~VideoSourceOrSink() {
	while(!m_connections.empty()) {
		delete m_connections.back();
	}
}

void VideoSourceOrSink::AddConnection(VideoConnection* connection) {
	m_connections.push_back(connection);
}

void VideoSourceOrSink::RemoveConnection(VideoConnection* connection) {
	for(auto it = m_connections.rbegin(); it != m_connections.rend(); ++it) {
		if(*it == connection) {
			m_connections.erase(it);
			return;
		}
	}
	Q_ASSERT(false);
}

VideoSource::VideoSource() {

}

void VideoSource::PushFrame(unsigned int width, unsigned int height, uint8_t* in_data, int in_stride, PixelFormat format, int64_t timestamp) {
	for(VideoConnection *c : m_connections) {
		c->GetSink()->ReadFrame(width, height, in_data, in_stride, format, timestamp);
	}
}

VideoSink::VideoSink() {

}

VideoConnection::VideoConnection(VideoSource* source, VideoSink* sink) {
	m_source = source;
	m_sink = sink;
	m_source->AddConnection(this);
	m_sink->AddConnection(this);
}

VideoConnection::~VideoConnection() {
	m_source->RemoveConnection(this);
	m_sink->RemoveConnection(this);
}
