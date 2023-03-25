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

#pragma once

#include "Global.h"

#include "AVWrapper.h"
#include "MutexDataPair.h"

// The video source/sink system keeps track of connections between video inputs and outputs.
// It decides where new frames should be sent. Using these connections is thread-safe,
// however only ONE thread should ever create or destroy connections (this includes destroying sources or sinks).

#define SINK_TIMESTAMP_NONE  ((int64_t) 0x8000000000000000ull)  // the sink doesn't want any new frames at the moment
#define SINK_TIMESTAMP_ASAP  ((int64_t) 0x8000000000000001ull)  // the sink wants a new frame as soon as possible

class BaseSource;
class BaseSink;

class BaseSource {
public:
	struct SinkData {
		BaseSink *sink;
		int priority;
		inline SinkData() {}
		inline SinkData(BaseSink *sink, int priority) : sink(sink), priority(priority) {}
		inline bool operator<(const SinkData& other) const {
			return (priority > other.priority); // sort in reverse order (high priority first)
		}
	};
	struct SharedData {
		std::vector<SinkData> m_sinks;
	};
	typedef MutexDataPair<SharedData>::Lock SharedLock;
public:
	MutexDataPair<SharedData> m_shared_data;
public:
	BaseSource();
	virtual ~BaseSource();
};

class BaseSink {
public:
	// variables are not protected by a lock because they should only be read when connections change
	BaseSource *m_source;
	int m_priority;
public:
	BaseSink();
	virtual ~BaseSink();
	void ConnectBaseSource(BaseSource* source, int priority);
};

class VideoSource : private BaseSource {
	friend class VideoSink;
protected:
	VideoSource() {}
	int64_t CalculateNextVideoTimestamp();
	void PushVideoFrame(unsigned int width, unsigned int height, const uint8_t* data, int stride, AVPixelFormat format, int colorspace, int64_t timestamp);
	void PushVideoPing(int64_t timestamp);
};

class VideoSink : private BaseSink {
	friend class VideoSource;
protected:
	VideoSink() {}
public:
	inline void ConnectVideoSource(VideoSource* source, int priority = 0) { ConnectBaseSource(source, priority); }
public:
	virtual int64_t GetNextVideoTimestamp() { return SINK_TIMESTAMP_NONE; }
	virtual void ReadVideoFrame(unsigned int width, unsigned int height, const uint8_t* data, int stride, AVPixelFormat format, int colorspace, int64_t timestamp) = 0;
	virtual void ReadVideoPing(int64_t timestamp) {}
};

class AudioSource : private BaseSource {
	friend class AudioSink;
protected:
	AudioSource() {}
	void PushAudioSamples(unsigned int channels, unsigned int sample_rate, AVSampleFormat format, unsigned int sample_count, const uint8_t* data, int64_t timestamp);
	void PushAudioHole();
};

class AudioSink : private BaseSink {
	friend class AudioSource;
protected:
	AudioSink() {}
public:
	inline void ConnectAudioSource(AudioSource* source, int priority = 0) { ConnectBaseSource(source, priority); }
public:
	virtual void ReadAudioSamples(unsigned int channels, unsigned int sample_rate, AVSampleFormat format, unsigned int sample_count, const uint8_t* data, int64_t timestamp) = 0;
	virtual void ReadAudioHole() {}
};
