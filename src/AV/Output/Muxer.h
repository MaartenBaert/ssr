/*
Copyright (c) 2012-2014 Maarten Baert <maarten-baert@hotmail.com>

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

#include "MutexDataPair.h"

#define MUXER_MAX_STREAMS 2

class AVPacketWrapper;
class BaseEncoder;

class Muxer {

private:
	struct StreamData {
		std::deque<std::unique_ptr<AVPacketWrapper> > m_packet_queue;
		bool m_is_done;
	};
	typedef MutexDataPair<StreamData>::Lock StreamLock;
	struct SharedData {
		uint64_t m_total_bytes;
		double m_stats_actual_bit_rate;
		double m_stats_previous_pts;
		uint64_t m_stats_previous_bytes;
	};
	typedef MutexDataPair<SharedData>::Lock SharedLock;

private:
	QString m_container_name, m_output_file;

	AVFormatContext *m_format_context;
	bool m_started;
	BaseEncoder *m_encoders[MUXER_MAX_STREAMS];

	std::thread m_thread;
	MutexDataPair<StreamData> m_stream_data[MUXER_MAX_STREAMS];
	MutexDataPair<SharedData> m_shared_data;
	std::atomic<bool> m_is_done, m_error_occurred;

public:
	Muxer(const QString& container_name, const QString& output_file);
	~Muxer();

	// Starts the muxer. You can't create new encoders after calling this function.
	void Start();

	// Tells the muxer to stop. It can take some time before the muxer really stops.
	void Finish();

	// Returns whether the muxer is running.
	bool IsStarted();

	// Returns the bit rate of the output stream.
	// This function is thread-safe.
	double GetActualBitRate();

	// Returns the total number of bytes written to the output file.
	// This function is thread-safe.
	uint64_t GetTotalBytes();

	// Returns whether the muxing is done. If this returns true, the object can be deleted.
	// Note: If an error occurred in the mixing thread, this function will return false.
	// This function is thread-safe and lock-free.
	inline bool IsDone() { return m_is_done; }

	// Returns whether an error has occurred in the input thread.
	// This function is thread-safe and lock-free.
	inline bool HasErrorOccurred() { return m_error_occurred; }

public:
	inline QString GetOutputFile() { return m_output_file; }

public: // internal

	// Adds a new stream to the muxer. Called by the encoder.
	AVStream* CreateStream(AVCodec* codec);

	// Registers an encoder (so it can be stopped and deleted when the muxer is closed). Called by the encoder.
	// Unlike CreateStream, this function is called at the end of the constructor of the encoder, to make sure that the pointer stays valid.
	// If the encoder can't be opened, it won't be registered and Start can't be called, but the muxer can still be destroyed safely.
	void RegisterEncoder(unsigned int stream_index, BaseEncoder* encoder);

	// Ends the stream (i.e. tells the muxer that it shouldn't wait for more packets). Called by the encoder.
	// This function is thread-safe.
	void EndStream(unsigned int stream_index);

	// Adds a packet to the packet queue of a stream. Called by the encoder.
	// This function is thread-safe.
	void AddPacket(unsigned int stream_index, std::unique_ptr<AVPacketWrapper> packet);

	// Returns the total number of packets in the queue of a stream. Called by the encoder.
	// This function is thread-safe.
	unsigned int GetQueuedPacketCount(unsigned int stream_index);

private:
	void Init();
	void Free();

	void MuxerThread();

};
