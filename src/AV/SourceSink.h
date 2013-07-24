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

class BaseSource;
class BaseSink;

class BaseSource {
public:
	struct SharedData {
		std::vector<BaseSink*> m_sinks;
	};
	typedef VPair<SharedData>::Lock SharedLock;
public:
	VPair<SharedData> m_shared_data;
public:
	BaseSource();
	virtual ~BaseSource();
};

class BaseSink {
public:
	BaseSource *m_source; // not protected by a lock because it should only be read when connections change
public:
	BaseSink();
	virtual ~BaseSink();
	void ConnectBaseSource(BaseSource* source);
};

class VideoSource : private BaseSource {
	friend class VideoSink;
protected:
	VideoSource() {}
	int64_t CalculateVideoFrameInterval(unsigned int frame_rate);
	void PushVideoFrame(unsigned int width, unsigned int height, const uint8_t* data, int stride, PixelFormat format, int64_t timestamp);
};

class VideoSink : private BaseSink {
	friend class VideoSource;
protected:
	VideoSink() {}
public:
	inline void ConnectVideoSource(VideoSource* source) { ConnectBaseSource(source); }
public:
	virtual int64_t GetVideoFrameInterval() { return 0; }
	virtual void ReadVideoFrame(unsigned int width, unsigned int height, const uint8_t* data, int stride, PixelFormat format, int64_t timestamp) = 0;
};

class AudioSource : private BaseSource {
	friend class AudioSink;
protected:
	AudioSource() {}
	void PushAudioSamples(unsigned int sample_rate, unsigned int channels, unsigned int sample_count, const uint8_t* data, AVSampleFormat format, int64_t timestamp);
};

class AudioSink : private BaseSink {
	friend class AudioSource;
protected:
	AudioSink() {}
public:
	inline void ConnectAudioSource(AudioSource* source) { ConnectBaseSource(source); }
public:
	virtual void ReadAudioSamples(unsigned int sample_rate, unsigned int channels, unsigned int sample_count, const uint8_t* data, AVSampleFormat format, int64_t timestamp) = 0;
};
