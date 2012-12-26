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

#define MUXER_MAX_STREAMS 2

class AVPacketWrapper;

class Muxer : private QThread {

private:
	struct StreamData {
		std::deque<std::unique_ptr<AVPacketWrapper> > m_packet_queue;
		bool m_is_done;
	};
	typedef VPair<StreamData>::Lock StreamLock;
	struct SharedData {
		uint64_t m_total_bytes;
	};
	typedef VPair<SharedData>::Lock SharedLock;

private:
	QString m_container_name, m_output_file;

	AVFormatContext *m_format_context;
	bool m_started;

	VPair<StreamData> m_stream_data[MUXER_MAX_STREAMS];
	VPair<SharedData> m_shared_data;
	volatile bool m_should_stop, m_is_done, m_error_occurred;

public:
	Muxer(const QString& container_name, const QString& output_file);
	~Muxer();

	// Starts the muxer. You can't create new encoders after calling this function.
	void Start();

	// Returns whether the muxer is running.
	bool IsStarted();

	// Returns the total number of bytes written to the output file.
	// This function is thread-safe.
	uint64_t GetTotalBytes();

	// Returns whether the muxing is done. If this returns true, the object can be deleted.
	// Note: If an error occurred in one of the encoders or the muxer itself, this function will return false.
	// This function is thread-safe.
	bool IsDone();

	// Returns whether an error has occurred in the input thread.
	// This function is thread-safe.
	inline bool HasErrorOccurred() { return m_error_occurred; }

public:
	inline QString GetOutputFile() { return m_output_file; }

public: // internal

	// Adds a new stream to the muxer. Called by the encoder.
	AVStream* CreateStream(AVCodec* codec);

	// Ends the stream. Called by the encoder.
	// This function is thread-safe.
	void EndStream(unsigned int stream_index);

	// Adds a packet to the packet queue of a stream. Called by the encoder.
	// This function is thread-safe.
	void AddPacket(unsigned int stream_index, std::unique_ptr<AVPacketWrapper> packet);

private:
	void Init();
	void Free();

	virtual void run();

};
