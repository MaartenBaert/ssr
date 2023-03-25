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

#include "MutexDataPair.h"

#define MUXER_MAX_STREAMS 2

class AVPacketWrapper;
class BaseEncoder;
class VideoEncoder;
class AudioEncoder;

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
		double m_stats_previous_time;
		uint64_t m_stats_previous_bytes;
	};
	typedef MutexDataPair<SharedData>::Lock SharedLock;

	static constexpr unsigned int INVALID_STREAM = std::numeric_limits<unsigned int>::max();
	static constexpr double NOPTS_DOUBLE = -std::numeric_limits<double>::max();

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

	// Adds a video or audio encoder.
	VideoEncoder* AddVideoEncoder(const QString& codec_name, const std::vector<std::pair<QString, QString> >& codec_options, unsigned int bit_rate,
								  unsigned int width, unsigned int height, unsigned int frame_rate);
	AudioEncoder* AddAudioEncoder(const QString& codec_name, const std::vector<std::pair<QString, QString> >& codec_options, unsigned int bit_rate,
								  unsigned int channels, unsigned int sample_rate);

	// Starts the muxer. You can't create new encoders after calling this function.
	void Start();

	// Tells the muxer to stop. It can take some time before the muxer really stops.
	void Finish();

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

	AVCodec* FindCodec(const QString& codec_name);
	AVStream* AddStream(AVCodec* codec, AVCodecContext** codec_context);

	void MuxerThread();

};
