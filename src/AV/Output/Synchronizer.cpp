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

#include "Synchronizer.h"

#include "Logger.h"
#include "CommandLineOptions.h"
#include "OutputManager.h"
#include "OutputSettings.h"
#include "VideoEncoder.h"
#include "AudioEncoder.h"
#include "SampleCast.h"
#include "SyncDiagram.h"

// The amount of filtering applied to audio timestamps to reduce noise. Higher values reduce timestamp noise (and associated drift correction),
// but if the value is too high, it will take more time to detect gaps.
const int64_t Synchronizer::AUDIO_TIMESTAMP_FILTER = 20;

// These values change how fast the synchronizer does drift correction.
// If this value is too low, the error will not be corrected fast enough. But if the value is too high, the audio
// may get weird speed fluctuations caused by the limited accuracy of the recording timestamps.
// The difference between sample length and time length has a lot of noise and can't be used directly,
// so it is averaged out using exponential smoothing. However, since the difference tends to increase gradually over time,
// exponential smoothing would constantly lag behind, so instead of simple proportional feedback, I use a PI controller.
// For critical damping, choose I = P*P/4.
const double Synchronizer::DRIFT_CORRECTION_P = 0.3;
const double Synchronizer::DRIFT_CORRECTION_I = 0.3 * 0.3 / 4.0;

// The maximum audio/video desynchronization allowed, in seconds. If the error is greater than this value, the synchronizer will insert zeros
// rather than relying on normal drift correction. This is something that should be avoided since it will result in noticeable interruptions,
// so it should only be triggered when something is really wrong. If the error is smaller, the synchronizer will do nothing and the
// drift correction system will take care of it (eventually).
const double Synchronizer::DRIFT_ERROR_THRESHOLD = 0.05;

// The maximum block size for drift correction, in seconds. This is needed to avoid numerical problems in the feedback system.
const double Synchronizer::DRIFT_MAX_BLOCK = 0.5;

// The maximum number of video frames and audio samples that will be buffered. This should be enough to cope with the fact that video and
// audio don't arrive at the same time, but not too high because that would cause memory problems if one of the inputs fails.
// The limit for audio can be set very high, because audio uses almost no memory.
const size_t Synchronizer::MAX_VIDEO_FRAMES_BUFFERED = 30;
const size_t Synchronizer::MAX_AUDIO_SAMPLES_BUFFERED = 1000000;

// The maximum delay between video frames, in microseconds. If the delay is longer, duplicates will be inserted.
// This is needed because some video codecs/players can't handle long delays.
const int64_t Synchronizer::MAX_FRAME_DELAY = 200000;

static std::unique_ptr<AVFrameWrapper> CreateVideoFrame(unsigned int width, unsigned int height, AVPixelFormat pixel_format, const std::shared_ptr<AVFrameData>& reuse_data) {

	// get required planes
	unsigned int planes = 0;
	size_t linesize[3] = {0}, planesize[3] = {0};
	switch(pixel_format) {
		case AV_PIX_FMT_YUV444P: {
			// Y/U/V = 1 byte per pixel
			planes = 3;
			linesize[0]  = grow_align16(width); planesize[0] = linesize[0] * height;
			linesize[1]  = grow_align16(width); planesize[1] = linesize[1] * height;
			linesize[2]  = grow_align16(width); planesize[2] = linesize[2] * height;
			break;
		}
		case AV_PIX_FMT_YUV422P: {
			// Y = 1 byte per pixel, U/V = 1 byte per 2x1 pixels
			assert(width % 2 == 0);
			planes = 3;
			linesize[0]  = grow_align16(width    ); planesize[0] = linesize[0] * height;
			linesize[1]  = grow_align16(width / 2); planesize[1] = linesize[1] * height;
			linesize[2]  = grow_align16(width / 2); planesize[2] = linesize[2] * height;
			break;
		}
		case AV_PIX_FMT_YUV420P: {
			// Y = 1 byte per pixel, U/V = 1 byte per 2x2 pixels
			assert(width % 2 == 0);
			assert(height % 2 == 0);
			planes = 3;
			linesize[0]  = grow_align16(width    ); planesize[0] = linesize[0] * height    ;
			linesize[1]  = grow_align16(width / 2); planesize[1] = linesize[1] * height / 2;
			linesize[2]  = grow_align16(width / 2); planesize[2] = linesize[2] * height / 2;
			break;
		}
		case AV_PIX_FMT_NV12: {
			assert(width % 2 == 0);
			assert(height % 2 == 0);
			// planar YUV 4:2:0, 12bpp, 1 plane for Y and 1 plane for the UV components, which are interleaved
			// Y = 1 byte per pixel, U/V = 1 byte per 2x2 pixels
			planes = 2;
			linesize[0]  = grow_align16(width); planesize[0] = linesize[0] * height    ;
			linesize[1]  = grow_align16(width); planesize[1] = linesize[1] * height / 2;
			break;
		}
		case AV_PIX_FMT_BGRA: {
			// BGRA = 4 bytes per pixel
			planes = 1;
			linesize[0] = grow_align16(width * 4); planesize[0] = linesize[0] * height;
			break;
		}
		case AV_PIX_FMT_BGR24:
		case AV_PIX_FMT_RGB24: {
			// BGR/RGB = 3 bytes per pixel
			planes = 1;
			linesize[0] = grow_align16(width * 3); planesize[0] = linesize[0] * height;
			break;
		}
		default: assert(false); break;
	}

	// create the frame
	size_t totalsize = 0;
	for(unsigned int p = 0; p < planes; ++p) {
		totalsize += planesize[p];
	}
	std::shared_ptr<AVFrameData> frame_data = (reuse_data == NULL)? std::make_shared<AVFrameData>(totalsize) : reuse_data;
	std::unique_ptr<AVFrameWrapper> frame(new AVFrameWrapper(frame_data));
	uint8_t *data = frame->GetRawData();
	for(unsigned int p = 0; p < planes; ++p) {
		frame->GetFrame()->data[p] = data;
		frame->GetFrame()->linesize[p] = linesize[p];
		data += planesize[p];
	}
#if SSR_USE_AVFRAME_WIDTH_HEIGHT
	frame->GetFrame()->width = width;
	frame->GetFrame()->height = height;
#endif
#if SSR_USE_AVFRAME_FORMAT
	frame->GetFrame()->format = pixel_format;
#endif
#if SSR_USE_AVFRAME_SAR
	frame->GetFrame()->sample_aspect_ratio.num = 1;
	frame->GetFrame()->sample_aspect_ratio.den = 1;
#endif

	return frame;

}

static std::unique_ptr<AVFrameWrapper> CreateAudioFrame(unsigned int channels, unsigned int sample_rate, unsigned int samples, unsigned int planes, AVSampleFormat sample_format) {

	// get required sample size
	// note: sample_size = sizeof(sampletype) * channels
	unsigned int sample_size = 0; // to keep GCC happy
	switch(sample_format) {
		case AV_SAMPLE_FMT_S16:
#if SSR_USE_AVUTIL_PLANAR_SAMPLE_FMT
		case AV_SAMPLE_FMT_S16P:
#endif
			sample_size = channels * sizeof(int16_t); break;
		case AV_SAMPLE_FMT_FLT:
#if SSR_USE_AVUTIL_PLANAR_SAMPLE_FMT
		case AV_SAMPLE_FMT_FLTP:
#endif
			sample_size = channels * sizeof(float); break;
		default: assert(false); break;
	}

	// create the frame
	size_t plane_size = grow_align16(samples * sample_size / planes);
	std::shared_ptr<AVFrameData> frame_data = std::make_shared<AVFrameData>(plane_size * planes);
	std::unique_ptr<AVFrameWrapper> frame(new AVFrameWrapper(frame_data));
	for(unsigned int p = 0; p < planes; ++p) {
		frame->GetFrame()->data[p] = frame->GetRawData() + plane_size * p;
		frame->GetFrame()->linesize[p] = samples * sample_size / planes;
	}
#if SSR_USE_AVFRAME_NB_SAMPLES
	frame->GetFrame()->nb_samples = samples;
#endif
#if SSR_USE_AVFRAME_CHANNELS
	frame->GetFrame()->channels = channels;
#endif
#if SSR_USE_AVFRAME_SAMPLE_RATE
	frame->GetFrame()->sample_rate = sample_rate;
#endif
#if SSR_USE_AVFRAME_FORMAT
	frame->GetFrame()->format = sample_format;
#endif

	return frame;

}

Synchronizer::Synchronizer(OutputManager *output_manager) {

	m_output_manager = output_manager;
	m_output_settings = m_output_manager->GetOutputSettings();
	m_output_format = m_output_manager->GetOutputFormat();
	assert(m_output_format->m_video_enabled || m_output_format->m_audio_enabled);

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

Synchronizer::~Synchronizer() {

	// disconnect
	ConnectVideoSource(NULL);
	ConnectAudioSource(NULL);

	// tell the thread to stop
	if(m_thread.joinable()) {
		Logger::LogInfo("[Synchronizer::~Synchronizer] " + Logger::tr("Stopping synchronizer thread ..."));
		m_should_stop = true;
		m_thread.join();
	}

	// flush one more time
	{
		SharedLock lock(&m_shared_data);
		FlushBuffers(lock.get());
	}

	// free everything
	Free();

}

void Synchronizer::Init() {

	// initialize video
	if(m_output_format->m_video_enabled) {
		m_max_frames_skipped = (m_output_settings->video_allow_frame_skipping)? (MAX_FRAME_DELAY * m_output_format->m_video_frame_rate + 500000) / 1000000 : 0;
		VideoLock videolock(&m_video_data);
		videolock->m_last_timestamp = std::numeric_limits<int64_t>::min();
		videolock->m_next_timestamp = SINK_TIMESTAMP_ASAP;
	}

	// initialize audio
	if(m_output_format->m_audio_enabled) {
		AudioLock audiolock(&m_audio_data);
		audiolock->m_fast_resampler.reset(new FastResampler(m_output_format->m_audio_channels, 0.9f));
		InitAudioSegment(audiolock.get());
		audiolock->m_warn_desync = true;
	}

	// create sync diagram
	if(CommandLineOptions::GetSyncDiagram()) {
		m_sync_diagram.reset(new SyncDiagram(4));
		m_sync_diagram->SetChannelName(0, SyncDiagram::tr("Video in"));
		m_sync_diagram->SetChannelName(1, SyncDiagram::tr("Audio in"));
		m_sync_diagram->SetChannelName(2, SyncDiagram::tr("Video out"));
		m_sync_diagram->SetChannelName(3, SyncDiagram::tr("Audio out"));
		m_sync_diagram->show();
	}

	// initialize shared data
	{
		SharedLock lock(&m_shared_data);

		if(m_output_format->m_audio_enabled) {
			lock->m_partial_audio_frame.Alloc(m_output_format->m_audio_frame_size * m_output_format->m_audio_channels);
			lock->m_partial_audio_frame_samples = 0;
		}
		lock->m_video_pts = 0;
		lock->m_audio_samples = 0;
		lock->m_time_offset = 0;

		InitSegment(lock.get());

		lock->m_warn_drop_video = true;

	}

	// start synchronizer thread
	m_should_stop = false;
	m_error_occurred = false;
	m_thread = std::thread(&Synchronizer::SynchronizerThread, this);

}

void Synchronizer::Free() {

}

void Synchronizer::NewSegment() {

	if(m_output_format->m_audio_enabled) {
		AudioLock audiolock(&m_audio_data);
		InitAudioSegment(audiolock.get());
	}

	SharedLock lock(&m_shared_data);
	NewSegment(lock.get());

}

int64_t Synchronizer::GetTotalTime() {
	SharedLock lock(&m_shared_data);
	return GetTotalTime(lock.get());
}

int64_t Synchronizer::GetNextVideoTimestamp() {
	assert(m_output_format->m_video_enabled);
	VideoLock videolock(&m_video_data);
	return videolock->m_next_timestamp;
}

void Synchronizer::ReadVideoFrame(unsigned int width, unsigned int height, const uint8_t* data, int stride, AVPixelFormat format, int colorspace, int64_t timestamp) {
	assert(m_output_format->m_video_enabled);

	// add new block to sync diagram
	if(m_sync_diagram != NULL)
		m_sync_diagram->AddBlock(0, (double) timestamp * 1.0e-6, (double) timestamp * 1.0e-6 + 1.0 / (double) m_output_format->m_video_frame_rate, QColor(255, 0, 0));

	VideoLock videolock(&m_video_data);

	// check the timestamp
	if(timestamp < videolock->m_last_timestamp) {
		if(timestamp < videolock->m_last_timestamp - 10000)
			Logger::LogWarning("[Synchronizer::ReadVideoFrame] " + Logger::tr("Warning: Received video frame with non-monotonic timestamp."));
		timestamp = videolock->m_last_timestamp;
	}

	// drop the frame if it is too early (before converting it)
	if(videolock->m_next_timestamp != SINK_TIMESTAMP_ASAP && timestamp < videolock->m_next_timestamp - (int64_t) (1000000 / m_output_format->m_video_frame_rate))
		return;

	// update the timestamps
	videolock->m_last_timestamp = timestamp;
	videolock->m_next_timestamp = std::max(videolock->m_next_timestamp + (int64_t) (1000000 / m_output_format->m_video_frame_rate), timestamp);

	// create the converted frame
	std::unique_ptr<AVFrameWrapper> converted_frame = CreateVideoFrame(m_output_format->m_video_width, m_output_format->m_video_height, m_output_format->m_video_pixel_format, NULL);

	// scale and convert the frame to the right format
	videolock->m_fast_scaler.Scale(width, height, format, colorspace, &data, &stride,
			m_output_format->m_video_width, m_output_format->m_video_height, m_output_format->m_video_pixel_format, m_output_format->m_video_colorspace,
			converted_frame->GetFrame()->data, converted_frame->GetFrame()->linesize);

	SharedLock lock(&m_shared_data);

	// avoid memory problems by limiting the video buffer size
	if(lock->m_video_buffer.size() >= MAX_VIDEO_FRAMES_BUFFERED) {
		if(lock->m_segment_audio_started) {
			if(lock->m_warn_drop_video) {
				lock->m_warn_drop_video = false;
				Logger::LogWarning("[Synchronizer::ReadVideoFrame] " + Logger::tr("Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow."));
			}
			return;
		} else {
			// if the audio hasn't started yet, it makes more sense to drop the oldest frames
			lock->m_video_buffer.pop_front();
			assert(lock->m_video_buffer.size() > 0);
			lock->m_segment_video_start_time = lock->m_video_buffer.front()->GetFrame()->pts;
		}
	}

	// start video
	if(!lock->m_segment_video_started) {
		lock->m_segment_video_started = true;
		lock->m_segment_video_start_time = timestamp;
		lock->m_segment_video_stop_time = timestamp;
	}

	// store the frame
	converted_frame->GetFrame()->pts = timestamp;
	lock->m_video_buffer.push_back(std::move(converted_frame));

	// increase the segment stop time
	lock->m_segment_video_stop_time = timestamp + (int64_t) (1000000 / m_output_format->m_video_frame_rate);

}

void Synchronizer::ReadVideoPing(int64_t timestamp) {
	assert(m_output_format->m_video_enabled);

	SharedLock lock(&m_shared_data);

	// if the video has not been started, ignore it
	if(!lock->m_segment_video_started)
		return;

	// increase the segment stop time
	lock->m_segment_video_stop_time = std::max(lock->m_segment_video_stop_time, timestamp + (int64_t) (1000000 / m_output_format->m_video_frame_rate));

}

void Synchronizer::ReadAudioSamples(unsigned int channels, unsigned int sample_rate, AVSampleFormat format, unsigned int sample_count, const uint8_t* data, int64_t timestamp) {
	assert(m_output_format->m_audio_enabled);

	// sanity check
	if(sample_count == 0)
		return;

	// add new block to sync diagram
	if(m_sync_diagram != NULL)
		m_sync_diagram->AddBlock(1, (double) timestamp * 1.0e-6, (double) timestamp * 1.0e-6 + (double) sample_count / (double) sample_rate, QColor(0, 255, 0));

	AudioLock audiolock(&m_audio_data);

	// check the timestamp
	if(timestamp < audiolock->m_last_timestamp) {
		if(timestamp < audiolock->m_last_timestamp - 10000)
			Logger::LogWarning("[Synchronizer::ReadAudioSamples] " + Logger::tr("Warning: Received audio samples with non-monotonic timestamp."));
		timestamp = audiolock->m_last_timestamp;
	}

	// update the timestamps
	int64_t previous_timestamp;
	if(audiolock->m_first_timestamp == (int64_t) AV_NOPTS_VALUE) {
		audiolock->m_filtered_timestamp = timestamp;
		audiolock->m_first_timestamp = timestamp;
		previous_timestamp = timestamp;
	} else {
		previous_timestamp = audiolock->m_last_timestamp;
	}
	audiolock->m_last_timestamp = timestamp;

	// filter the timestamp
	int64_t timestamp_delta = (int64_t) sample_count * (int64_t) 1000000 / (int64_t) sample_rate;
	audiolock->m_filtered_timestamp += (timestamp - audiolock->m_filtered_timestamp) / AUDIO_TIMESTAMP_FILTER;

	// calculate drift
	double current_drift = GetAudioDrift(audiolock.get());

	// if there are too many audio samples, drop some of them (unlikely unless you use PulseAudio)
	if(current_drift > DRIFT_ERROR_THRESHOLD && !audiolock->m_drop_samples) {
		audiolock->m_drop_samples = true;
		Logger::LogWarning("[Synchronizer::ReadAudioSamples] " + Logger::tr("Warning: Too many audio samples, dropping samples to keep the audio in sync with the video."));
	}

	// if there are not enough audio samples, insert zeros
	if(current_drift < -DRIFT_ERROR_THRESHOLD && !audiolock->m_insert_samples) {
		audiolock->m_insert_samples = true;
		Logger::LogWarning("[Synchronizer::ReadAudioSamples] " + Logger::tr("Warning: Not enough audio samples, inserting silence to keep the audio in sync with the video."));
	}

	// reset filter and recalculate drift if necessary
	if(audiolock->m_drop_samples || audiolock->m_insert_samples) {
		audiolock->m_filtered_timestamp = timestamp;
		current_drift = GetAudioDrift(audiolock.get());
	}

	// drop samples
	if(audiolock->m_drop_samples) {
		audiolock->m_drop_samples = false;

		// drop samples
		int n = (int) round(current_drift * (double) sample_rate);
		if(n > 0) {
			if(n >= (int) sample_count) {
				audiolock->m_drop_samples = true;
				return; // drop all samples
			}
			if(format == AV_SAMPLE_FMT_FLT) {
				data += n * channels * sizeof(float);
			} else if(format == AV_SAMPLE_FMT_S16) {
				data += n * channels * sizeof(int16_t);
			} else if(format == AV_SAMPLE_FMT_S32) {
				data += n * channels * sizeof(int32_t);
			} else {
				assert(false);
			}
			sample_count -= n;
		}

	}

	// insert zeros
	unsigned int sample_count_out = 0;
	if(audiolock->m_insert_samples) {
		audiolock->m_insert_samples = false;

		// how many samples should be inserted?
		int n = (int) round(-current_drift * (double) sample_rate);
		if(n > 0) {

			// insert zeros
			audiolock->m_temp_input_buffer.Alloc(n * m_output_format->m_audio_channels);
			std::fill_n(audiolock->m_temp_input_buffer.GetData(), n * m_output_format->m_audio_channels, 0.0f);
			sample_count_out = audiolock->m_fast_resampler->Resample((double) sample_rate / (double) m_output_format->m_audio_sample_rate, 1.0,
																	 audiolock->m_temp_input_buffer.GetData(), n, &audiolock->m_temp_output_buffer, sample_count_out);

			// recalculate drift
			current_drift = GetAudioDrift(audiolock.get(), sample_count_out);

		}

	}

	// increase filtered timestamp
	audiolock->m_filtered_timestamp += timestamp_delta;

	// do drift correction
	// The point of drift correction is to keep video and audio in sync even when the clocks are not running at exactly the same speed.
	// This can happen because the sample rate of the sound card is not always 100% accurate. Even a 0.1% error will result in audio that is
	// seconds too early or too late at the end of a one hour video. This problem doesn't occur on all computers though (I'm not sure why).
	// Another cause of desynchronization is problems/glitches with PulseAudio (e.g. jumps in time when switching between sources).
	double drift_correction_dt = fmin((double) (timestamp - previous_timestamp) * 1.0e-6, DRIFT_MAX_BLOCK);
	audiolock->m_average_drift = clamp(audiolock->m_average_drift + DRIFT_CORRECTION_I * current_drift * drift_correction_dt, -0.5, 0.5);
	if(audiolock->m_average_drift < -0.02 && audiolock->m_warn_desync) {
		audiolock->m_warn_desync = false;
		Logger::LogWarning("[Synchronizer::ReadAudioSamples] " + Logger::tr("Warning: Audio input is more than 2% too slow!"));
	}
	if(audiolock->m_average_drift > 0.02 && audiolock->m_warn_desync) {
		audiolock->m_warn_desync = false;
		Logger::LogWarning("[Synchronizer::ReadAudioSamples] " + Logger::tr("Warning: Audio input is more than 2% too fast!"));
	}
	double length = (double) sample_count / (double) sample_rate;
	double drift_correction = clamp(DRIFT_CORRECTION_P * current_drift + audiolock->m_average_drift, -0.5, 0.5) * fmin(1.0, DRIFT_MAX_BLOCK / length);

	//qDebug() << "current_drift" << current_drift << "average_drift" << audiolock->m_average_drift << "drift_correction" << drift_correction;

	// convert the samples
	const float *data_float = NULL; // to keep GCC happy
	if(format == AV_SAMPLE_FMT_FLT) {
		if(channels == m_output_format->m_audio_channels) {
			data_float = (const float*) data;
		} else {
			audiolock->m_temp_input_buffer.Alloc(sample_count * m_output_format->m_audio_channels);
			data_float = audiolock->m_temp_input_buffer.GetData();
			SampleChannelRemap(sample_count, (const float*) data, channels, audiolock->m_temp_input_buffer.GetData(), m_output_format->m_audio_channels);
		}
	} else if(format == AV_SAMPLE_FMT_S16) {
		audiolock->m_temp_input_buffer.Alloc(sample_count * m_output_format->m_audio_channels);
		data_float = audiolock->m_temp_input_buffer.GetData();
		SampleChannelRemap(sample_count, (const int16_t*) data, channels, audiolock->m_temp_input_buffer.GetData(), m_output_format->m_audio_channels);
	} else if(format == AV_SAMPLE_FMT_S32) {
		audiolock->m_temp_input_buffer.Alloc(sample_count * m_output_format->m_audio_channels);
		data_float = audiolock->m_temp_input_buffer.GetData();
		SampleChannelRemap(sample_count, (const int32_t*) data, channels, audiolock->m_temp_input_buffer.GetData(), m_output_format->m_audio_channels);
	} else {
		assert(false);
	}

	// resample
	sample_count_out = audiolock->m_fast_resampler->Resample((double) sample_rate / (double) m_output_format->m_audio_sample_rate, 1.0 / (1.0 - drift_correction),
															 data_float, sample_count, &audiolock->m_temp_output_buffer, sample_count_out);
	audiolock->m_samples_written += sample_count_out;

	SharedLock lock(&m_shared_data);

	// avoid memory problems by limiting the audio buffer size
	if(lock->m_audio_buffer.GetSize() / m_output_format->m_audio_channels >= MAX_AUDIO_SAMPLES_BUFFERED) {
		if(lock->m_segment_video_started) {
			Logger::LogWarning("[Synchronizer::ReadAudioSamples] " + Logger::tr("Warning: Audio buffer overflow, starting new segment to keep the audio in sync with the video "
																				"(some video and/or audio may be lost). The video input seems to be too slow."));
			NewSegment(lock.get());
		} else {
			// If the video hasn't started yet, it makes more sense to drop the oldest samples.
			// Shifting the start time like this isn't completely accurate, but this shouldn't happen often anyway.
			// The number of samples dropped is calculated so that the buffer will be 90% full after this.
			size_t n = lock->m_audio_buffer.GetSize() / m_output_format->m_audio_channels - MAX_AUDIO_SAMPLES_BUFFERED * 9 / 10;
			lock->m_audio_buffer.Pop(n * m_output_format->m_audio_channels);
			lock->m_segment_audio_start_time += (int64_t) round((double) n / (double) m_output_format->m_audio_sample_rate * 1.0e6);
		}
	}

	// start audio
	if(!lock->m_segment_audio_started) {
		lock->m_segment_audio_started = true;
		lock->m_segment_audio_start_time = timestamp;
		lock->m_segment_audio_stop_time = timestamp;
	}

	// store the samples
	lock->m_audio_buffer.Push(audiolock->m_temp_output_buffer.GetData(), sample_count_out * m_output_format->m_audio_channels);

	// increase segment stop time
	double new_sample_length = (double) (lock->m_segment_audio_samples_read + lock->m_audio_buffer.GetSize() / m_output_format->m_audio_channels) / (double) m_output_format->m_audio_sample_rate;
	lock->m_segment_audio_stop_time = lock->m_segment_audio_start_time + (int64_t) round(new_sample_length * 1.0e6);

}

void Synchronizer::ReadAudioHole() {
	assert(m_output_format->m_audio_enabled);

	AudioLock audiolock(&m_audio_data);
	if(audiolock->m_first_timestamp != (int64_t) AV_NOPTS_VALUE) {
		audiolock->m_average_drift = 0.0;
		if(!audiolock->m_drop_samples || !audiolock->m_insert_samples) {
			Logger::LogWarning("[Synchronizer::ReadAudioHole] " + Logger::tr("Warning: Received hole in audio stream, inserting silence to keep the audio in sync with the video."));
			audiolock->m_drop_samples = true; // because PulseAudio is weird
			audiolock->m_insert_samples = true;
		}
	}

}

void Synchronizer::InitAudioSegment(AudioData* audiolock) {
	audiolock->m_last_timestamp = std::numeric_limits<int64_t>::min();
	audiolock->m_first_timestamp = AV_NOPTS_VALUE;
	audiolock->m_samples_written = 0;
	audiolock->m_average_drift = 0.0;
	audiolock->m_drop_samples = false;
	audiolock->m_insert_samples = false;
}

double Synchronizer::GetAudioDrift(AudioData* audiolock, unsigned int extra_samples) {
	double sample_length = ((double) (audiolock->m_samples_written + extra_samples) + audiolock->m_fast_resampler->GetOutputLatency()) / (double) m_output_format->m_audio_sample_rate;
	double time_length = (double) (audiolock->m_filtered_timestamp - audiolock->m_first_timestamp) * 1.0e-6;
	return sample_length - time_length;
}

void Synchronizer::NewSegment(SharedData* lock) {
	FlushBuffers(lock);
	if(lock->m_segment_video_started && lock->m_segment_audio_started) {
		int64_t segment_start_time, segment_stop_time;
		GetSegmentStartStop(lock, &segment_start_time, &segment_stop_time);
		lock->m_time_offset += std::max((int64_t) 0, segment_stop_time - segment_start_time);
	}
	lock->m_video_buffer.clear();
	lock->m_audio_buffer.Clear();
	InitSegment(lock);
}

void Synchronizer::InitSegment(SharedData* lock) {
	lock->m_segment_video_started = !m_output_format->m_video_enabled;
	lock->m_segment_audio_started = !m_output_format->m_audio_enabled;
	lock->m_segment_video_start_time = AV_NOPTS_VALUE;
	lock->m_segment_audio_start_time = AV_NOPTS_VALUE;
	lock->m_segment_video_stop_time = AV_NOPTS_VALUE;
	lock->m_segment_audio_stop_time = AV_NOPTS_VALUE;
	lock->m_segment_audio_can_drop = true;
	lock->m_segment_audio_samples_read = 0;
	lock->m_segment_video_accumulated_delay = 0;
}

int64_t Synchronizer::GetTotalTime(Synchronizer::SharedData* lock) {
	if(lock->m_segment_video_started && lock->m_segment_audio_started) {
		int64_t segment_start_time, segment_stop_time;
		GetSegmentStartStop(lock, &segment_start_time, &segment_stop_time);
		return lock->m_time_offset + std::max((int64_t) 0, segment_stop_time - segment_start_time);
	} else {
		return lock->m_time_offset;
	}
}

void Synchronizer::GetSegmentStartStop(SharedData* lock, int64_t* segment_start_time, int64_t* segment_stop_time) {
	if(!m_output_format->m_audio_enabled) {
		*segment_start_time = lock->m_segment_video_start_time;
		*segment_stop_time = lock->m_segment_video_stop_time;
	} else if(!m_output_format->m_video_enabled) {
		*segment_start_time = lock->m_segment_audio_start_time;
		*segment_stop_time = lock->m_segment_audio_stop_time;
	} else {
		*segment_start_time = std::max(lock->m_segment_video_start_time, lock->m_segment_audio_start_time);
		*segment_stop_time = std::min(lock->m_segment_video_stop_time, lock->m_segment_audio_stop_time);
	}
}

void Synchronizer::FlushBuffers(SharedData* lock) {
	if(!lock->m_segment_video_started || !lock->m_segment_audio_started)
		return;

	int64_t segment_start_time, segment_stop_time;
	GetSegmentStartStop(lock, &segment_start_time, &segment_stop_time);

	// flush video
	if(m_output_format->m_video_enabled)
		FlushVideoBuffer(lock, segment_start_time, segment_stop_time);

	// flush audio
	if(m_output_format->m_audio_enabled)
		FlushAudioBuffer(lock, segment_start_time, segment_stop_time);

}

void Synchronizer::FlushVideoBuffer(Synchronizer::SharedData* lock, int64_t segment_start_time, int64_t segment_stop_time) {

	// Sometimes long delays between video frames can occur, e.g. when a game is showing a loading screen.
	// Not all codecs/players can handle that. It's also a problem for streaming. To fix this, long delays should be avoided by
	// duplicating the previous frame a few times when needed. Whenever a video frame is sent to the encoder, it is also copied,
	// with reference counting for the actual image to minimize overhead. When there is a gap, duplicate frames are inserted.
	// Duplicate frames are always inserted with a timestamp in the past, because we don't want to drop a real frame if it is captured
	// right after the duplicate was inserted. MAX_INPUT_LATENCY simulates the latency from the capturing of a frame to the synchronizer,
	// i.e. any new frame is assumed to have a timestamp higher than the current time minus MAX_INPUT_LATENCY. The duplicate
	// frame will have a timestamp that's one frame earlier than that time, so it will never interfere with the real frame.
	// There are two situations where duplicate frames can be inserted:
	// (1) The queue is not empty, but there is a gap between frames that is too large.
	// (2) The queue is empty and the last timestamp is too long ago (relative to the end of the video segment).
	// It is perfectly possible that *both* happen, each possibly multiple times, in just one function call.

	int64_t segment_stop_video_pts = (lock->m_time_offset + (segment_stop_time - segment_start_time)) * (int64_t) m_output_format->m_video_frame_rate / (int64_t) 1000000;
	int64_t delay_time_per_frame = 1000000 / m_output_format->m_video_frame_rate;
	for( ; ; ) {

		// get/predict the timestamp of the next frame
		int64_t next_timestamp = (lock->m_video_buffer.empty())? lock->m_segment_video_stop_time - (int64_t) (1000000 / m_output_format->m_video_frame_rate) : lock->m_video_buffer.front()->GetFrame()->pts;
		int64_t next_pts = (lock->m_time_offset + (next_timestamp - segment_start_time)) * (int64_t) m_output_format->m_video_frame_rate / (int64_t) 1000000;

		// if the frame is too late, decrease the pts by one to avoid gaps
		if(next_pts > lock->m_video_pts)
			--next_pts;

		// insert delays if needed, up to the segment end
		while(lock->m_segment_video_accumulated_delay >= delay_time_per_frame && lock->m_video_pts < segment_stop_video_pts) {
			lock->m_segment_video_accumulated_delay -= delay_time_per_frame;
			lock->m_video_pts += 1;
			//Logger::LogInfo("[Synchronizer::FlushVideoBuffer] Delay [" + QString::number(lock->m_video_pts - 1) + "] acc " + QString::number(lock->m_segment_video_accumulated_delay) + ".");
		}

		// insert duplicate frames if needed, up to either the next frame or the segment end
		if(lock->m_last_video_frame_data != NULL) {
			while(lock->m_video_pts + m_max_frames_skipped < std::min(next_pts, segment_stop_video_pts)) {

				// create duplicate frame
				std::unique_ptr<AVFrameWrapper> duplicate_frame = CreateVideoFrame(m_output_format->m_video_width, m_output_format->m_video_height, m_output_format->m_video_pixel_format, lock->m_last_video_frame_data);
				duplicate_frame->GetFrame()->pts = lock->m_video_pts + m_max_frames_skipped;

				// add new block to sync diagram
				if(m_sync_diagram != NULL) {
					double t = (double) duplicate_frame->GetFrame()->pts / (double) m_output_format->m_video_frame_rate;
					m_sync_diagram->AddBlock(2, t, t + 1.0 / (double) m_output_format->m_video_frame_rate, QColor(255, 196, 0));
				}

				// send the frame to the encoder
				lock->m_segment_video_accumulated_delay = std::max((int64_t) 0, lock->m_segment_video_accumulated_delay - m_max_frames_skipped * delay_time_per_frame);
				lock->m_video_pts = duplicate_frame->GetFrame()->pts + 1;
				//Logger::LogInfo("[Synchronizer::FlushVideoBuffer] Encoded video frame [" + QString::number(duplicate_frame->GetFrame()->pts) + "] (duplicate) acc " + QString::number(lock->m_segment_video_accumulated_delay) + ".");
				m_output_manager->AddVideoFrame(std::move(duplicate_frame));
				lock->m_segment_video_accumulated_delay += m_output_manager->GetVideoFrameDelay();

			}
		}

		// if there are no frames, or they are beyond the segment end, stop
		if(lock->m_video_buffer.empty() || next_pts >= segment_stop_video_pts)
			break;

		// get the frame
		std::unique_ptr<AVFrameWrapper> frame = std::move(lock->m_video_buffer.front());
		lock->m_video_buffer.pop_front();
		frame->GetFrame()->pts = next_pts;
		lock->m_last_video_frame_data = frame->GetFrameData();

		// if the frame is too early, drop it
		if(frame->GetFrame()->pts < lock->m_video_pts) {
			//Logger::LogInfo("[Synchronizer::FlushVideoBuffer] Dropped video frame [" + QString::number(frame->GetFrame()->pts) + "] acc " + QString::number(lock->m_segment_video_accumulated_delay) + ".");
			continue;
		}

		// if this is the first video frame, always set the pts to zero
		if(lock->m_video_pts == 0)
			frame->GetFrame()->pts = 0;

		// add new block to sync diagram
		if(m_sync_diagram != NULL) {
			double t = (double) frame->GetFrame()->pts / (double) m_output_format->m_video_frame_rate;
			m_sync_diagram->AddBlock(2, t, t + 1.0 / (double) m_output_format->m_video_frame_rate, QColor(255, 0, 0));
		}

		// send the frame to the encoder
		lock->m_segment_video_accumulated_delay = std::max((int64_t) 0, lock->m_segment_video_accumulated_delay - (frame->GetFrame()->pts - lock->m_video_pts) * delay_time_per_frame);
		lock->m_video_pts = frame->GetFrame()->pts + 1;
		//Logger::LogInfo("[Synchronizer::FlushBuffers] Encoded video frame [" + QString::number(frame->GetFrame()->pts) + "].");
		m_output_manager->AddVideoFrame(std::move(frame));
		lock->m_segment_video_accumulated_delay += m_output_manager->GetVideoFrameDelay();

	}

}

void Synchronizer::FlushAudioBuffer(Synchronizer::SharedData* lock, int64_t segment_start_time, int64_t segment_stop_time) {

	double sample_length = (double) (segment_stop_time - lock->m_segment_audio_start_time) * 1.0e-6;
	int64_t samples_max = (int64_t) ceil(sample_length * (double) m_output_format->m_audio_sample_rate) - lock->m_segment_audio_samples_read;
	if(lock->m_audio_buffer.GetSize() > 0) {

		// Normally, the correct way to calculate the position of the first sample would be:
		//     int64_t timestamp = lock->m_segment_audio_start_time + (int64_t) round((double) lock->m_segment_audio_samples_read / (double) m_audio_sample_rate * 1.0e6);
		//     int64_t pos = (int64_t) round((double) (lock->m_time_offset + (timestamp - segment_start_time)) * 1.0e-6 * (double) m_audio_sample_rate);
		// Simplified:
		//     int64_t pos = (int64_t) round((double) (lock->m_time_offset + (lock->m_segment_audio_start_time - segment_start_time)) * 1.0e-6 * (double) m_audio_sample_rate)
		//                   + lock->m_segment_audio_samples_read;
		// The first part of the expression is constant, so it only has to be calculated at the start of the segment. After that the increase in position is always
		// equal to the number of samples written. Samples are only dropped at the start of the segment, so actually
		// the position doesn't have to be calculated anymore after that, since it is assumed to be equal to lock->m_audio_samples.

		if(lock->m_segment_audio_can_drop) {

			// calculate the offset of the first sample
			int64_t pos = (int64_t) round((double) (lock->m_time_offset + (lock->m_segment_audio_start_time - segment_start_time)) * 1.0e-6 * (double) m_output_format->m_audio_sample_rate)
						  + lock->m_segment_audio_samples_read;

			// drop samples that are too early
			if(pos < lock->m_audio_samples) {
				int64_t n = std::min(lock->m_audio_samples - pos, (int64_t) lock->m_audio_buffer.GetSize() / m_output_format->m_audio_channels);
				lock->m_audio_buffer.Pop(n * m_output_format->m_audio_channels);
				lock->m_segment_audio_samples_read += n;
			}

		}

		int64_t samples_left = std::min(samples_max, (int64_t) lock->m_audio_buffer.GetSize() / m_output_format->m_audio_channels);

		// add new block to sync diagram
		if(m_sync_diagram != NULL && samples_left > 0) {
			double t = (double) lock->m_audio_samples / (double) m_output_format->m_audio_sample_rate;
			m_sync_diagram->AddBlock(3, t, t + (double) samples_left / (double) m_output_format->m_audio_sample_rate, QColor(0, 255, 0));
		}

		// send the samples to the encoder
		while(samples_left > 0) {

			lock->m_segment_audio_can_drop = false;

			// copy samples until either the partial frame is full or there are no samples left
			//TODO// do direct copy/conversion to new audio frame?
			int64_t n = std::min((int64_t) (m_output_format->m_audio_frame_size - lock->m_partial_audio_frame_samples), samples_left);
			lock->m_audio_buffer.Pop(lock->m_partial_audio_frame.GetData() + lock->m_partial_audio_frame_samples * m_output_format->m_audio_channels, n * m_output_format->m_audio_channels);
			lock->m_segment_audio_samples_read += n;
			lock->m_partial_audio_frame_samples += n;
			lock->m_audio_samples += n;
			samples_left -= n;

			// is the partial frame full?
			if(lock->m_partial_audio_frame_samples == m_output_format->m_audio_frame_size) {

				// allocate a frame
#if SSR_USE_AVUTIL_PLANAR_SAMPLE_FMT
				unsigned int planes = (m_output_format->m_audio_sample_format == AV_SAMPLE_FMT_S16P ||
									   m_output_format->m_audio_sample_format == AV_SAMPLE_FMT_FLTP)? m_output_format->m_audio_channels : 1;
#else
				unsigned int planes = 1;
#endif
				std::unique_ptr<AVFrameWrapper> audio_frame = CreateAudioFrame(m_output_format->m_audio_channels, m_output_format->m_audio_sample_rate,
																			   m_output_format->m_audio_frame_size, planes, m_output_format->m_audio_sample_format);
				audio_frame->GetFrame()->pts = lock->m_audio_samples;

				// copy/convert the samples
				switch(m_output_format->m_audio_sample_format) {
					case AV_SAMPLE_FMT_S16: {
						float *data_in = (float*) lock->m_partial_audio_frame.GetData();
						int16_t *data_out = (int16_t*) audio_frame->GetFrame()->data[0];
						SampleCopy(m_output_format->m_audio_frame_size * m_output_format->m_audio_channels, data_in, 1, data_out, 1);
						break;
					}
					case AV_SAMPLE_FMT_FLT: {
						float *data_in = (float*) lock->m_partial_audio_frame.GetData();
						float *data_out = (float*) audio_frame->GetFrame()->data[0];
						memcpy(data_out, data_in, m_output_format->m_audio_frame_size * m_output_format->m_audio_channels * sizeof(float));
						break;
					}
#if SSR_USE_AVUTIL_PLANAR_SAMPLE_FMT
					case AV_SAMPLE_FMT_S16P: {
						for(unsigned int p = 0; p < planes; ++p) {
							float *data_in = (float*) lock->m_partial_audio_frame.GetData() + p;
							int16_t *data_out = (int16_t*) audio_frame->GetFrame()->data[p];
							SampleCopy(m_output_format->m_audio_frame_size, data_in, planes, data_out, 1);
						}
						break;
					}
					case AV_SAMPLE_FMT_FLTP: {
						for(unsigned int p = 0; p < planes; ++p) {
							float *data_in = (float*) lock->m_partial_audio_frame.GetData() + p;
							float *data_out = (float*) audio_frame->GetFrame()->data[p];
							SampleCopy(m_output_format->m_audio_frame_size, data_in, planes, data_out, 1);
						}
						break;
					}
#endif
					default: {
						assert(false);
						break;
					}
				}
				lock->m_partial_audio_frame_samples = 0;

				//Logger::LogInfo("[Synchronizer::FlushAudioBuffer] Encoded audio frame [" + QString::number(lock->m_partial_audio_frame->pts) + "].");
				m_output_manager->AddAudioFrame(std::move(audio_frame));
			}

		}

	}

}

void Synchronizer::SynchronizerThread() {
	try {

		Logger::LogInfo("[Synchronizer::SynchronizerThread] " + Logger::tr("Synchronizer thread started."));

		while(!m_should_stop) {

			{
				SharedLock lock(&m_shared_data);
				FlushBuffers(lock.get());
				if(m_sync_diagram != NULL) {
					double time_in = (double) hrt_time_micro() * 1.0e-6;
					double time_out = (double) GetTotalTime(lock.get()) * 1.0e-6;
					m_sync_diagram->SetCurrentTime(0, time_in);
					m_sync_diagram->SetCurrentTime(1, time_in);
					m_sync_diagram->SetCurrentTime(2, time_out);
					m_sync_diagram->SetCurrentTime(3, time_out);
					m_sync_diagram->Update();
				}
			}

			usleep(20000);

		}

		Logger::LogInfo("[Synchronizer::SynchronizerThread] " + Logger::tr("Synchronizer thread stopped."));

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError("[Synchronizer::SynchronizerThread] " + Logger::tr("Exception '%1' in synchronizer thread.").arg(e.what()));
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[Synchronizer::SynchronizerThread] " + Logger::tr("Unknown exception in synchronizer thread."));
	}
}
