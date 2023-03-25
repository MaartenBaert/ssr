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

int ParseCodecOptionInt(const QString& key, const QString& value, int min, int max, int multiply = 1);
double ParseCodecOptionDouble(const QString& key, const QString& value, double min, double max, double multiply = 1.0);

class Muxer;

class BaseEncoder {

private:
	struct SharedData {
		std::deque<std::unique_ptr<AVFrameWrapper> > m_frame_queue;
		uint64_t m_total_frames, m_total_packets;
		double m_stats_actual_frame_rate;
		int64_t m_stats_previous_pts;
		uint64_t m_stats_previous_frames;
	};
	typedef MutexDataPair<SharedData>::Lock SharedLock;

private:
	Muxer *m_muxer;
	AVStream *m_stream;
	AVCodecContext *m_codec_context;
	bool m_codec_opened;

	std::thread m_thread;
	MutexDataPair<SharedData> m_shared_data;
	std::atomic<bool> m_should_stop, m_should_finish, m_is_done, m_error_occurred;

protected:
	BaseEncoder(Muxer* muxer, AVStream* stream, AVCodecContext* codec_context, AVCodec* codec, AVDictionary** options);

public:
	virtual ~BaseEncoder(); // encoders will be deleted by Muxer, don't delete them yourself!

protected:
	void StartThread();
	void StopThread(); // important: call this in the destructor of the derived class

public:
	// Returns the frame rate of the output stream.
	// This function is thread-safe.
	double GetActualFrameRate();

	// Returns the total number of added frames.
	// This function is thread-safe.
	uint64_t GetTotalFrames();

	// Returns the current input-to-output latency of the encoder (in frames).
	// This function is thread-safe.
	unsigned int GetFrameLatency();

	// Returns the total number of frames in the queue.
	// This function is thread-safe.
	unsigned int GetQueuedFrameCount();

	unsigned int GetQueuedPacketCount();

public: // internal

	// Adds a frame to the frame queue. Called by the synchronizer.
	// This function is thread-safe.
	void AddFrame(std::unique_ptr<AVFrameWrapper> frame);

	// Tells the encoder to stop. It can still take some time before the encoder is actually done. Called by the muxer.
	// After calling this function, the muxer will wait until either IsDone or HasErrorOccurred returns true.
	// This function is thread-safe.
	void Finish();

	// Same as finish, except that queued frames will be dropped and the encoder won't be flushed. Called by the muxer.
	// This function is thread-safe.
	void Stop();

	// Returns whether the encoding is done. If this returns true, the object can be deleted. Called by the muxer.
	// Note: If an error occurred during encoding, this function will return false.
	// This function is thread-safe and lock-free.
	inline bool IsDone() { return m_is_done; }

	// Returns whether an error has occurred in the input thread. Called by the muxer.
	// This function is thread-safe and lock-free.
	inline bool HasErrorOccurred() { return m_error_occurred; }

	inline Muxer* GetMuxer() { return m_muxer; }
	inline AVStream* GetStream() { return m_stream; }
	inline AVCodecContext* GetCodecContext() { return m_codec_context; }

protected:

	// Called by the encoder thread to encode a single frame. Frame can be NULL if the encoder uses delayed packets.
	// Returns whether a packet was created.
	virtual bool EncodeFrame(AVFrameWrapper* frame) = 0;

	// Called to increment the packet counter.
	void IncrementPacketCounter();

private:
	void Init(AVCodec* codec, AVDictionary** options);
	void Free();

	void EncoderThread();

};
