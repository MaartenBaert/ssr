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

class Logger;
class VideoEncoder;
class AudioEncoder;
class AVFrameWrapper;

class Synchronizer {

private:
	struct SharedData {
		int64_t m_time_offset;
		int64_t m_segment_begin_time, m_last_video_pts;
		uint64_t m_sample_count;
		double m_time_correction_factor, m_correction_speed;
	};
	typedef VPair<SharedData>::Lock SharedLock;

private:
	static const double CORRECTION_SPEED;

private:
	Logger *m_logger;
	VideoEncoder *m_video_encoder;
	AudioEncoder *m_audio_encoder;

	unsigned int m_frame_rate;
	unsigned int m_required_frame_size, m_sample_rate;

	VPair<SharedData> m_shared_data;

public:
	// The arguments 'video_encoder' and 'audio_encoder' can be NULL to disable video or audio.
	Synchronizer(Logger* logger, VideoEncoder* video_encoder, AudioEncoder* audio_encoder);

	// This function tells the synchronizer to end the current segment and reset the synchronization system
	// in preparation for a new segment. This is required for pausing and continuing a recording.
	// This function has no effect if there are no frames in the current segment, so it is safe to call this multiple times.
	// This function is thread-safe, but for best results you should still make sure that no input is running
	// while this function is called, because otherwise frames may end up in the wrong segment.
	void NewSegment();

	// Returns the total recording time (in microseconds).
	// This function is thread-safe.
	int64_t GetTotalTime();

	inline VideoEncoder* GetVideoEncoder() { return m_video_encoder; }
	inline AudioEncoder* GetAudioEncoder() { return m_audio_encoder; }

public: // internal

	// Adds a frame to the video frame queue. Called by the input.
	// pkt_dts should contain the actual recording timestamp.
	// This function is thread-safe.
	void AddVideoFrame(std::unique_ptr<AVFrameWrapper> frame);

	// Adds a frame to the audio frame queue. Called by the input.
	// pkt_dts should contain the actual recording timestamp (of the first sample).
	// This function is thread-safe.
	void AddAudioFrame(std::unique_ptr<AVFrameWrapper> frame);

};
