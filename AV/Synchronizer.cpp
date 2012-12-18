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

#include "StdAfx.h"
#include "Synchronizer.h"

#include "Logger.h"
#include "AVWrapper.h"
#include "VideoEncoder.h"
#include "AudioEncoder.h"

// It should be a value between 0 and 1. The value changes how fast the synchronizer adjusts the time correction factor.
// If this value is too low, the error will not be corrected fast enough. But if the value is too high, the video
// may get weird frame rate fluctuations caused by the limited accuracy of the recording timestamps.
const double Synchronizer::CORRECTION_SPEED = 0.1;

Synchronizer::Synchronizer(Logger* logger, VideoEncoder* video_encoder, AudioEncoder* audio_encoder) {
	Q_ASSERT(video_encoder != NULL || audio_encoder != NULL);

	m_logger = logger;
	m_video_encoder = video_encoder;
	m_audio_encoder = audio_encoder;

	if(m_video_encoder != NULL) {
		m_frame_rate = m_video_encoder->GetFrameRate();
	}
	if(m_audio_encoder != NULL) {
		m_required_frame_size = m_audio_encoder->GetRequiredFrameSize();
		m_sample_rate = m_audio_encoder->GetSampleRate();
	}

	{
		SharedLock lock(&m_shared_data);
		lock->m_time_offset = 0;
		lock->m_segment_begin_time = AV_NOPTS_VALUE;
		lock->m_last_video_pts = AV_NOPTS_VALUE;
		lock->m_sample_count = 0;
		lock->m_time_correction_factor = 1.0;
		double audio_frame_interval = (double) m_required_frame_size / (double) m_sample_rate;
		lock->m_correction_speed = 1.0 - pow(1.0 - CORRECTION_SPEED, audio_frame_interval);
	}

}

void Synchronizer::NewSegment() {
	SharedLock lock(&m_shared_data);

	// do we need to synchronize?
	if(m_audio_encoder != NULL) {

		if(lock->m_last_video_pts != (int64_t) AV_NOPTS_VALUE) {
			for( ; ; ) {

				// compare the length of the video and audio segment
				int64_t video_time = (lock->m_last_video_pts + 1) * (int64_t) 1000000 / (int64_t) m_frame_rate;
				int64_t audio_time = lock->m_time_offset + (int64_t) lock->m_sample_count * (int64_t) 1000000 / (int64_t) m_sample_rate;
				if(video_time < audio_time)
					break;

				//m_logger->LogInfo("[Synchronizer::NewSegment] Inserting audio frame (size = " + QString::number(m_required_frame_size) + ").");

				// if the audio segment is shorter, add an empty frame
				std::unique_ptr<AVFrameWrapper> frame(new AVFrameWrapper(m_required_frame_size * 4));
				frame->linesize[0] = m_required_frame_size * 4;
				frame->nb_samples = m_required_frame_size;
				memset(frame->data[0], 0, m_required_frame_size * 4);

				// increase the sample count
				//frame->pts = lock->m_pts_offset + (int64_t) lock->m_sample_count * (int64_t) 1000000 / (int64_t) m_sample_rate;
				lock->m_sample_count += frame->nb_samples;

				// send the frame to the encoder
				m_audio_encoder->AddFrame(std::move(frame));

			}
		}

		// set the new offset
		lock->m_time_offset += (int64_t) lock->m_sample_count * (int64_t) 1000000 / (int64_t) m_sample_rate;

	} else {

		// set the new offset
		lock->m_time_offset = (lock->m_last_video_pts + 1) * (int64_t) 1000000 / (int64_t) m_frame_rate;

	}

	// reset the counters
	lock->m_segment_begin_time = AV_NOPTS_VALUE;
	lock->m_sample_count = 0;

}

int64_t Synchronizer::GetTotalTime() {
	SharedLock lock(&m_shared_data);
	int64_t audio_time = lock->m_time_offset + (int64_t) lock->m_sample_count * (int64_t) 1000000 / (int64_t) m_sample_rate;;
	if(lock->m_last_video_pts != (int64_t) AV_NOPTS_VALUE) {
		int64_t video_time = (lock->m_last_video_pts + 1) * (int64_t) 1000000 / (int64_t) m_frame_rate;
		return std::max(video_time, audio_time);
	}
	return audio_time;
}

void Synchronizer::AddVideoFrame(std::unique_ptr<AVFrameWrapper> frame) {
	Q_ASSERT(m_video_encoder != NULL);
	SharedLock lock(&m_shared_data);
	//m_logger->LogInfo("1 " + QString::number(frame->pkt_dts));

	// if this is the first frame, use this as the start time,
	// or drop the frame when synchronizing with audio
	if(lock->m_segment_begin_time == (int64_t) AV_NOPTS_VALUE) {
		if(m_audio_encoder != NULL)
			return;
		lock->m_segment_begin_time = frame->pkt_dts;
	}

	// set the timestamp
	if(lock->m_last_video_pts == (int64_t) AV_NOPTS_VALUE) {
		frame->pts = 0;
	} else {
		int64_t time = lock->m_time_offset + (int64_t)((double) (frame->pkt_dts - lock->m_segment_begin_time) * lock->m_time_correction_factor);
		int64_t pts = time * (int64_t) m_frame_rate / (int64_t) 1000000;
		if(pts < lock->m_last_video_pts)
			return;
		frame->pts = std::max(pts, lock->m_last_video_pts + 1);
	}
	lock->m_last_video_pts = frame->pts;

	// send the frame to the encoder
	//m_logger->LogInfo("[Synchronizer::AddVideoFrame] Video pts = " + QString::number(frame->pts));
	m_video_encoder->AddFrame(std::move(frame));

}

void Synchronizer::AddAudioFrame(std::unique_ptr<AVFrameWrapper> frame) {
	Q_ASSERT(m_audio_encoder != NULL);
	SharedLock lock(&m_shared_data);
	//m_logger->LogInfo("2 " + QString::number(frame->pkt_dts));

	// if this is the first frame, use this as the start time
	if(lock->m_segment_begin_time == (int64_t) AV_NOPTS_VALUE)
		lock->m_segment_begin_time = frame->pkt_dts;

	// do speed correction (i.e. do the calculations so the video can synchronize to it)
	// The point of speed correction is to keep video and audio in sync even when the clocks are not running at exactly the same speed.
	// This can happen because the sample rate of the sound card is not always 100% accurate. Even a 0.1% error will result in audio that is
	// seconds too early or too late at the end of a one hour video. This problem doesn't occur on all computer though (I'm not sure why).
	// Speed correction only starts after at least 5 seconds of audio have been recorded, because otherwise the timestamps are too inaccurate.
	// The speed correction factor is also clamped to 95% .. 105% to limit the potential damage if this code produces wrong results :).
	double sample_length = (double) lock->m_sample_count / (double) m_sample_rate;
	double time_length = (double)(frame->pkt_dts - lock->m_segment_begin_time) * 0.000001;
	if(time_length > 5.0) {
		double time_correction_factor = sample_length / time_length;
		lock->m_time_correction_factor = clamp(0.95, 1.05, lock->m_time_correction_factor
				+ (time_correction_factor - lock->m_time_correction_factor) * lock->m_correction_speed);
	}

	// increase the sample count
	//frame->pts = lock->m_pts_offset + (int64_t) lock->m_sample_count * (int64_t) 1000000 / (int64_t) m_sample_rate;
	lock->m_sample_count += frame->nb_samples;

	// send the frame to the encoder
	//m_logger->LogInfo("[Synchronizer::AddAudioFrame] Audio pts = " + QString::number(frame->pts));
	m_audio_encoder->AddFrame(std::move(frame));

}
