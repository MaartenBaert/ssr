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
#include "VideoConnection.h"

VideoSource::VideoSource() {

}

VideoSource::~VideoSource() {
	SharedLock lock(&m_shared_data);
	for(VideoSink *s : lock->m_sinks) {
		s->m_source = NULL;
	}
}

int64_t VideoSource::CalculateVideoFrameInterval(unsigned int frame_rate) {
	SharedLock lock(&m_shared_data);
	int64_t max_interval = 1000000 / frame_rate;
	for(VideoSink *s : lock->m_sinks) {
		int64_t interval = s->GetVideoFrameInterval();
		if(interval > max_interval)
			max_interval = interval;
	}
	return max_interval;
}

void VideoSource::PushVideoFrame(unsigned int width, unsigned int height, uint8_t* data, int stride, PixelFormat format, int64_t timestamp) {
	SharedLock lock(&m_shared_data);
	for(VideoSink *s : lock->m_sinks) {
		s->ReadVideoFrame(width, height, data, stride, format, timestamp);
	}
}

VideoSink::VideoSink() {
	m_source = NULL;
}

VideoSink::~VideoSink() {
	Q_ASSERT(m_source == NULL);
}

void VideoSink::ConnectVideoSource(VideoSource* source) {
	if(m_source != NULL) {
		VideoSource::SharedLock lock(&m_source->m_shared_data);
		for(auto it = lock->m_sinks.begin(); it != lock->m_sinks.end(); ++it) {
			if(*it == this) {
				lock->m_sinks.erase(it);
				break;
			}
		}
	}
	m_source = source;
	if(m_source != NULL) {
		VideoSource::SharedLock lock(&m_source->m_shared_data);
		lock->m_sinks.push_back(this);
	}
}
