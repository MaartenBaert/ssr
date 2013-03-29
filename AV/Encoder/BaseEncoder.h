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
#include "StdAfx.h"

#include "VPair.h"

class Muxer;
class AVFrameWrapper;

class BaseEncoder : private QThread {

private:
	struct SharedData {
		std::deque<std::unique_ptr<AVFrameWrapper> > m_frame_queue;
		unsigned int m_total_frames;
	};
	typedef VPair<SharedData>::Lock SharedLock;

private:
	bool m_destructed;
	Muxer *m_muxer;

	AVCodecContext *m_codec_context;
	unsigned int m_stream_index;
	bool m_delayed_packets;

	VPair<SharedData> m_shared_data;
	volatile bool m_should_stop, m_should_finish, m_is_done, m_error_occurred;

protected:
	BaseEncoder(Muxer* muxer);
	void Destruct(); // important: call this in the destructor of the derived class

public:
	virtual ~BaseEncoder(); // encoders will be deleted by Muxer, don't delete them yourself!

protected:

	// Called by the constructor of derived classes to create the codec.
	void CreateCodec(const QString& codec_name, AVDictionary** options);

	// Called by CreateCodec after the codec context has been created but before the codec is opened.
	virtual void FillCodecContext(AVCodec* codec) = 0;

	// Called by the encoder thread to encode a single frame. Frame can be NULL if the encoder uses delayed packets.
	// Returns whether a packet was received.
	virtual bool EncodeFrame(AVFrameWrapper* frame) = 0;

	inline Muxer* GetMuxer() { return m_muxer; }
	inline AVCodecContext* GetCodecContext() { return m_codec_context; }
	inline unsigned int GetStreamIndex() { return m_stream_index; }

public:

	// Returns the total number of added frames.
	// This function is thread-safe.
	unsigned int GetTotalFrames();

	// Returns the total number of frames in the queue.
	// This function is thread-safe.
	unsigned int GetQueuedFrameCount();

public: // internal

	// Adds a frame to the frame queue. Called by the synchronizer.
	// This function is thread-safe.
	void AddFrame(std::unique_ptr<AVFrameWrapper> frame);

	// Tells the encoder to stop. It can still take some time before the encoder is actually done. Called by the mixer.
	// After calling this function, the mixer will wait until either IsDone or HasErrorOccurred returns true.
	// This function is thread-safe.
	void Finish();

	// Same as finish, except that queued frames will be dropped and the encoder won't be flushed. Called by the mixer.
	// This function is thread-safe.
	void Stop();

	// Returns whether the encoding is done. If this returns true, the object can be deleted. Called by the mixer.
	// Note: If an error occurred during encoding, this function will return false.
	// This function is thread-safe and lock-free.
	inline bool IsDone() { return m_is_done; }

	// Returns whether an error has occurred in the input thread. Called by the mixer.
	// This function is thread-safe and lock-free.
	inline bool HasErrorOccurred() { return m_error_occurred; }

private:
	virtual void run();

};
