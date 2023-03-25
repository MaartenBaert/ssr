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

#include "Muxer.h"
#include "VideoEncoder.h"
#include "AudioEncoder.h"
#include "Synchronizer.h"
#include "OutputSettings.h"

class OutputManager {

private:
	struct SharedData {

		// frame queue used while switching between fragments
		std::deque<std::unique_ptr<AVFrameWrapper> > m_video_frame_queue;
		std::deque<std::unique_ptr<AVFrameWrapper> > m_audio_frame_queue;
		unsigned int m_fragment_number;

		// muxer and encoders
		std::unique_ptr<Muxer> m_muxer;
		VideoEncoder *m_video_encoder;
		AudioEncoder *m_audio_encoder;

	};
	typedef MutexDataPair<SharedData>::Lock SharedLock;

private:
	static const size_t THROTTLE_THRESHOLD_FRAMES, THROTTLE_THRESHOLD_PACKETS;

private:
	OutputSettings m_output_settings;
	OutputFormat m_output_format;

	bool m_fragmented;
	int64_t m_fragment_length;

	std::unique_ptr<Synchronizer> m_synchronizer;

	std::thread m_thread;
	MutexDataPair<SharedData> m_shared_data;
	std::atomic<bool> m_should_stop, m_should_finish, m_is_done, m_error_occurred;

public:
	OutputManager(const OutputSettings& output_settings);
	~OutputManager();

	// Tells the encoders and muxer to finish. After calling this function, you should wait until
	// IsFinished returns true before deleting the output manager.
	void Finish();

	// Returns whether the encoders and muxer have finished.
	bool IsFinished();

	// Adds a video frame to the frame queue. Called by the synchronizer.
	// This function is thread-safe.
	void AddVideoFrame(std::unique_ptr<AVFrameWrapper> frame);

	// Adds an audio frame to the frame queue. Called by the synchronizer.
	// This function is thread-safe.
	void AddAudioFrame(std::unique_ptr<AVFrameWrapper> frame);

	// Returns an additional delay (in us) between frames, based on the queue size, to avoid memory problems.
	// As long as the queues are relatively small, this function will just return 0.
	// This function is thread-safe.
	int64_t GetVideoFrameDelay();

	// Returns the total number of frames in the queue.
	// This function is thread-safe.
	unsigned int GetTotalQueuedFrameCount();

	// Returns the frame rate of the output stream.
	// This function is thread-safe.
	double GetActualFrameRate();

	// Returns the bit rate of the output stream.
	// This function is thread-safe.
	double GetActualBitRate();

	// Returns the total number of bytes written to the output file.
	// This function is thread-safe.
	uint64_t GetTotalBytes();

private:
	void Init();
	void Free();

	void StartFragment();
	void StopFragment();

	void FragmentThread();

public:
	inline const OutputSettings* GetOutputSettings() { return &m_output_settings; }
	inline const OutputFormat* GetOutputFormat() { return &m_output_format; }
	inline Synchronizer* GetSynchronizer() { return m_synchronizer.get(); }

};
