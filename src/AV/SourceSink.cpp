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

#include "SourceSink.h"

BaseSource::BaseSource() {
}
BaseSource::~BaseSource() {
	SharedLock lock(&m_shared_data);
	for(SinkData &s : lock->m_sinks) {
		s.sink->m_source = NULL;
	}
}

BaseSink::BaseSink() {
	m_source = NULL;
	m_priority = 0;
}
BaseSink::~BaseSink() {
	// Classes that inherit a sink should disconnect themselves in the destructor before doing anything else,
	// otherwise inputs may try to send data to partially destructed sinks.
	assert(m_source == NULL);
}
void BaseSink::ConnectBaseSource(BaseSource* source, int priority) {
	if(m_source == source && m_priority == priority)
		return;
	if(m_source != NULL) {
		BaseSource::SharedLock lock(&m_source->m_shared_data);
		for(auto it = lock->m_sinks.begin(); it != lock->m_sinks.end(); ++it) {
			if(it->sink == this) {
				lock->m_sinks.erase(it);
				break;
			}
		}
	}
	m_source = source;
	if(m_source != NULL) {
		BaseSource::SharedLock lock(&m_source->m_shared_data);
		BaseSource::SinkData data(this, priority);
		auto it = std::upper_bound(lock->m_sinks.begin(), lock->m_sinks.end(), data);
		lock->m_sinks.insert(it, data);
	}
}

int64_t VideoSource::CalculateNextVideoTimestamp() {
	SharedLock lock(&m_shared_data);
	for(SinkData &s : lock->m_sinks) {
		int64_t timestamp = static_cast<VideoSink*>(s.sink)->GetNextVideoTimestamp();
		if(timestamp != SINK_TIMESTAMP_NONE)
			return timestamp;
	}
	return SINK_TIMESTAMP_NONE;
}

void VideoSource::PushVideoFrame(unsigned int width, unsigned int height, const uint8_t* data, int stride, AVPixelFormat format, int colorspace, int64_t timestamp) {
	SharedLock lock(&m_shared_data);
	for(SinkData &s : lock->m_sinks) {
		static_cast<VideoSink*>(s.sink)->ReadVideoFrame(width, height, data, stride, format, colorspace, timestamp);
	}
}

void VideoSource::PushVideoPing(int64_t timestamp) {
	SharedLock lock(&m_shared_data);
	for(SinkData &s : lock->m_sinks) {
		static_cast<VideoSink*>(s.sink)->ReadVideoPing(timestamp);
	}
}

void AudioSource::PushAudioSamples(unsigned int channels, unsigned int sample_rate, AVSampleFormat format, unsigned int sample_count, const uint8_t* data, int64_t timestamp) {
	SharedLock lock(&m_shared_data);
	for(SinkData &s : lock->m_sinks) {
		static_cast<AudioSink*>(s.sink)->ReadAudioSamples(channels, sample_rate, format, sample_count, data, timestamp);
	}
}

void AudioSource::PushAudioHole() {
	SharedLock lock(&m_shared_data);
	for(SinkData &s : lock->m_sinks) {
		static_cast<AudioSink*>(s.sink)->ReadAudioHole();
	}
}
