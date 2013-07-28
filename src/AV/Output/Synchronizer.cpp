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

#include "Global.h"
#include "Synchronizer.h"

#include "Logger.h"
#include "VideoEncoder.h"
#include "AudioEncoder.h"

// This value changes how fast the synchronizer adjusts the time correction factor. It should be a value between 0 and 1.
// If this value is too low, the error will not be corrected fast enough. But if the value is too high, the video
// may get weird frame rate fluctuations caused by the limited accuracy of the recording timestamps.
const double Synchronizer::CORRECTION_SPEED = 0.002;

// The maximum number of video frames and audio samples that will be buffered. This should be enough to cope with the fact that video and
// audio don't arrive at the same time, but not too high because that would cause memory problems if one of the inputs fails.
// The limit for audio can be set very high, because audio uses almost no memory.
const size_t Synchronizer::MAX_VIDEO_FRAMES_BUFFERED = 30;
const size_t Synchronizer::MAX_AUDIO_SAMPLES_BUFFERED = 1000000;

// The maximum allowed time between two audio timestamps (in microseconds). If the time difference is greater than this value,
// the synchronizer will assume that there is a gap in the audio stream and will cut the segment to avoid excessive desynchronization.
// If the difference is smaller, the synchronizer will do nothing and the speed correction system will take care of it (eventually).
// PulseAudio creates these gaps when a VT-switch or user switch occurs (it simply freezes all audio streams, this causes problems with many other applications as well).
const int64_t Synchronizer::AUDIO_GAP_THRESHOLD = 500000;

Synchronizer::Synchronizer(VideoEncoder* video_encoder, AudioEncoder* audio_encoder) {
	Q_ASSERT(video_encoder != NULL || audio_encoder != NULL);

	m_video_encoder = video_encoder;
	m_audio_encoder = audio_encoder;

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
	if(isRunning()) {
		Logger::LogInfo("[Synchronizer::~Synchronizer] Telling synchronizer thread to stop ...");
		m_should_stop = true;
		wait();
	}

	// free everything
	Free();

}

void Synchronizer::Init() {

	if(m_video_encoder != NULL) {
		m_video_width = m_video_encoder->GetWidth();
		m_video_height = m_video_encoder->GetHeight();
		m_video_frame_rate = m_video_encoder->GetFrameRate();
	}
	if(m_audio_encoder != NULL) {
		m_audio_sample_rate = m_audio_encoder->GetSampleRate();
		m_audio_channels = 2; //TODO// never larger than AV_NUM_DATA_POINTERS
		m_audio_sample_size = m_audio_channels * 2;
		m_audio_required_frame_size = m_audio_encoder->GetRequiredFrameSize();
		m_audio_required_sample_format = m_audio_encoder->GetRequiredSampleFormat();
		switch(m_audio_required_sample_format) {
			case AV_SAMPLE_FMT_S16:
#if SSR_USE_AVUTIL_PLANAR_SAMPLE_FMT
			case AV_SAMPLE_FMT_S16P:
#endif
				m_audio_required_sample_size = m_audio_channels * 2; break;
			case AV_SAMPLE_FMT_FLT:
#if SSR_USE_AVUTIL_PLANAR_SAMPLE_FMT
			case AV_SAMPLE_FMT_FLTP:
#endif
				m_audio_required_sample_size = m_audio_channels * 4; break;
			default: Q_ASSERT(false); break;
		}
	}

	{
		SharedLock lock(&m_shared_data);
		lock->m_partial_audio_frame.resize(m_audio_required_frame_size * m_audio_sample_size);
		lock->m_partial_audio_frame_samples = 0;
		lock->m_video_pts = 0;
		lock->m_audio_samples = 0;
		lock->m_time_correction_factor = 1.0;
		lock->m_time_offset = 0;
		lock->m_segment_video_started = (m_video_encoder == NULL);
		lock->m_segment_audio_started = (m_audio_encoder == NULL);
		lock->m_segment_audio_samples_read = 0;
		lock->m_warn_drop_video = true;
		lock->m_warn_drop_audio = true;
		lock->m_warn_desync = true;
	}

	// start input thread
	m_should_stop = false;
	m_error_occurred = false;
	start();

}

void Synchronizer::Free() {

}

void Synchronizer::NewSegment() {
	SharedLock lock(&m_shared_data);
	NewSegment(lock.get());
}

int64_t Synchronizer::GetTotalTime() {
	SharedLock lock(&m_shared_data);
	if(lock->m_segment_video_started && lock->m_segment_audio_started) {
		int64_t segment_start_time, segment_stop_time;
		GetSegmentStartStop(lock.get(), &segment_start_time, &segment_stop_time);
		return lock->m_time_offset + (int64_t) ((double) (segment_stop_time - segment_start_time) * lock->m_time_correction_factor);
	} else {
		return lock->m_time_offset;
	}
}

int64_t Synchronizer::GetVideoFrameInterval() {
	Q_ASSERT(m_video_encoder != NULL);
	return m_video_encoder->GetFrameInterval();
}

void Synchronizer::ReadVideoFrame(unsigned int width, unsigned int height, const uint8_t* data, int stride, PixelFormat format, int64_t timestamp) {
	Q_ASSERT(m_video_encoder != NULL);

	// allocate the converted frame, with proper alignment
	// Y = 1 byte per pixel, U or V = 1 byte per 2x2 pixels
	int l1 = grow_align16(m_video_width);
	int l2 = grow_align16(m_video_width / 2);
	int s1 = grow_align16(l1 * m_video_height);
	int s2 = grow_align16(l2 * m_video_height / 2);
	std::unique_ptr<AVFrameWrapper> converted_frame(new AVFrameWrapper(s1 + 2 * s2));
	converted_frame->data[1] = converted_frame->data[0] + s1;
	converted_frame->data[2] = converted_frame->data[1] + s2;
	converted_frame->linesize[0] = l1;
	converted_frame->linesize[1] = l2;
	converted_frame->linesize[2] = l2;

	// scale and convert the frame to YUV420P
	// the scaler has a separate lock so the audio thread is less likely to block (scaling is still slow)
	{
		FastScalerLock lock(&m_fast_scaler);
		lock->Scale(width, height, &data, &stride, format,
					m_video_width, m_video_height, converted_frame->data, converted_frame->linesize, PIX_FMT_YUV420P);
	}

	SharedLock lock(&m_shared_data);

	// avoid memory problems by limiting the video buffer size
	if(lock->m_video_buffer.size() >= MAX_VIDEO_FRAMES_BUFFERED) {
		if(lock->m_segment_audio_started) {
			if(lock->m_warn_drop_video) {
				lock->m_warn_drop_video = false;
				Logger::LogWarning("[Synchronizer::AddVideoFrame] Warning: Video buffer overflow, some frames will be lost. The audio input seems to be too slow.");
			}
			return;
		} else {
			// if the audio hasn't started yet, it makes more sense to drop the oldest frames
			lock->m_video_buffer.pop_front();
			Q_ASSERT(lock->m_video_buffer.size() > 0);
			lock->m_segment_video_start_time = lock->m_video_buffer.front()->pkt_dts;
		}
	}

	// start video
	if(!lock->m_segment_video_started) {
		lock->m_segment_video_started = true;
		lock->m_segment_video_start_time = timestamp;
	}

	// store the frame
	converted_frame->pkt_dts = timestamp;
	lock->m_video_buffer.push_back(std::move(converted_frame));

	// increase segment stop time
	lock->m_segment_video_stop_time = timestamp + (int64_t) 1000000 / (int64_t) m_video_frame_rate;

	//Logger::LogInfo("[Synchronizer::AddVideoFrame] Added video frame at " + QString::number(timestamp) + ".");

}

void Synchronizer::ReadAudioSamples(unsigned int sample_rate, unsigned int channels, unsigned int sample_count, const uint8_t* data, AVSampleFormat format, int64_t timestamp) {
	Q_ASSERT(m_audio_encoder != NULL);
	SharedLock lock(&m_shared_data);

	if(sample_count == 0)
		return;

	Q_ASSERT(sample_rate == m_audio_sample_rate); // resampling isn't supported
	Q_ASSERT(channels == m_audio_channels); // remixing isn't supported
	Q_ASSERT(format == AV_SAMPLE_FMT_S16); // only S16 is currently supported

	// avoid memory problems by limiting the audio buffer size
	if(lock->m_audio_buffer.GetSize() / m_audio_sample_size >= MAX_AUDIO_SAMPLES_BUFFERED) {
		if(lock->m_segment_video_started) {
			if(lock->m_warn_drop_audio) {
				lock->m_warn_drop_audio = false;
				Logger::LogWarning("[Synchronizer::AddAudioSamples] Warning: Audio buffer overflow, some samples will be lost. The video input seems to be too slow.");
			}
			return;
		} else {
			// If the video hasn't started yet, it makes more sense to drop the oldest samples.
			// Shifting the start time like this isn't completely accurate, but this shouldn't happen often anyway.
			size_t n = lock->m_audio_buffer.GetSize() / m_audio_sample_size - MAX_AUDIO_SAMPLES_BUFFERED + MAX_AUDIO_SAMPLES_BUFFERED / 10;
			lock->m_audio_buffer.Drop(n * m_audio_sample_size);
			lock->m_segment_audio_start_time += (int64_t) ((double) n / (double) m_audio_sample_rate / lock->m_time_correction_factor * 1.0e6);
		}
	}

	// detect audio gaps
	if(lock->m_segment_audio_started && timestamp > lock->m_segment_audio_last_timestamp + AUDIO_GAP_THRESHOLD) {
		Logger::LogWarning("[Synchronizer::AddAudioSamples] Warning: Detected gap in audio stream, starting new segment to keep the audio in sync with the video (some video may be lost).");
		NewSegment(lock.get());
	}

	// start audio
	if(!lock->m_segment_audio_started) {
		lock->m_segment_audio_started = true;
		lock->m_segment_audio_start_time = timestamp;
	}
	lock->m_segment_audio_last_timestamp = timestamp;

	// do speed correction (i.e. do the calculations so the video can synchronize to it)
	// The point of speed correction is to keep video and audio in sync even when the clocks are not running at exactly the same speed.
	// This can happen because the sample rate of the sound card is not always 100% accurate. Even a 0.1% error will result in audio that is
	// seconds too early or too late at the end of a one hour video. This problem doesn't occur on all computers though (I'm not sure why).
	// Speed correction only starts after at least 5 seconds of audio have been recorded, because otherwise the timestamps are too inaccurate.
	// I used to limit the speed correction factor to 95% .. 105% to limit potential damage, but I've removed this limit since problems with
	// PulseAudio often result in large speed correction factors. I have changed the limit to 10% .. 1000% instead, while keeping the old warnings.
	double sample_length = (double) (lock->m_segment_audio_samples_read + lock->m_audio_buffer.GetSize() / m_audio_sample_size) / (double) m_audio_sample_rate;
	double time_length = (double) (timestamp - lock->m_segment_audio_start_time) * 1.0e-6;
	if(time_length > 5.0) {
		double time_correction_factor = sample_length / time_length;
		lock->m_time_correction_factor = clamp(0.1, 10.0, lock->m_time_correction_factor + (time_correction_factor - lock->m_time_correction_factor) * CORRECTION_SPEED);
		if(lock->m_time_correction_factor < 0.95 && lock->m_warn_desync) {
			lock->m_warn_desync = false;
			Logger::LogWarning("[Synchronizer::AddAudioSamples] Warning: Audio input is more than 5% too slow!");
		}
		if(lock->m_time_correction_factor > 1.05 && lock->m_warn_desync) {
			lock->m_warn_desync = false;
			Logger::LogWarning("[Synchronizer::AddAudioSamples] Warning: Audio input is more than 5% too fast!");
		}
	}

	// store the samples
	lock->m_audio_buffer.Write((const char*) data, sample_count * m_audio_sample_size);

	// increase segment stop time
	sample_length = (double) (lock->m_segment_audio_samples_read + lock->m_audio_buffer.GetSize() / m_audio_sample_size) / (double) m_audio_sample_rate;
	lock->m_segment_audio_stop_time = lock->m_segment_audio_start_time + (int64_t) (sample_length / lock->m_time_correction_factor * 1.0e6);

	//Logger::LogInfo("[Synchronizer::AddAudioSamples] Added audio samples at " + QString::number(timestamp) + ".");

}

void Synchronizer::NewSegment(SharedData* lock) {
	FlushBuffers(lock);
	if(lock->m_segment_video_started && lock->m_segment_audio_started) {
		int64_t segment_start_time, segment_stop_time;
		GetSegmentStartStop(lock, &segment_start_time, &segment_stop_time);
		lock->m_time_offset += (int64_t) ((double) (segment_stop_time - segment_start_time) * lock->m_time_correction_factor);
	}
	lock->m_video_buffer.clear();
	lock->m_audio_buffer.Clear();
	lock->m_segment_video_started = (m_video_encoder == NULL);
	lock->m_segment_audio_started = (m_audio_encoder == NULL);
	lock->m_segment_audio_samples_read = 0;
}

void Synchronizer::GetSegmentStartStop(SharedData* lock, int64_t* segment_start_time, int64_t* segment_stop_time) {
	if(m_audio_encoder == NULL) {
		*segment_start_time = lock->m_segment_video_start_time;
		*segment_stop_time = lock->m_segment_video_stop_time;
	} else if(m_video_encoder == NULL) {
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
	while(!lock->m_video_buffer.empty() && lock->m_video_buffer.front()->pkt_dts < segment_stop_time) {

		// get the first frame and calculate the final pts
		std::unique_ptr<AVFrameWrapper> frame = std::move(lock->m_video_buffer.front());
		lock->m_video_buffer.pop_front();
		frame->pts = (int64_t) round(((double) lock->m_time_offset + (double) (frame->pkt_dts - segment_start_time) * lock->m_time_correction_factor)
									 * 1.0e-6 * (double) m_video_frame_rate);
		frame->pkt_dts = AV_NOPTS_VALUE;

		// if the frame is way too early, drop it
		if(frame->pts < lock->m_video_pts - 1)
			continue;

		// if the frame is just a little too early, move it
		if(frame->pts < lock->m_video_pts)
			frame->pts = lock->m_video_pts;

		// send the frame to the encoder
		lock->m_video_pts = frame->pts + 1;
		//Logger::LogInfo("[Synchronizer::FlushBuffers] Encoded video frame [" + QString::number(frame->pts) + "].");
		m_video_encoder->AddFrame(std::move(frame));

	}

	// flush audio
	double sample_length = (double) (segment_stop_time - lock->m_segment_audio_start_time) * 1.0e-6 * lock->m_time_correction_factor;
	int64_t samples_max = (int64_t) ceil(sample_length * (double) m_audio_sample_rate) - lock->m_segment_audio_samples_read;
	if(lock->m_audio_buffer.GetSize() > 0 && samples_max > 0) {

		// calculate the final position of the first sample
		int64_t pos = (int64_t) round((double) (lock->m_time_offset + lock->m_segment_audio_start_time - segment_start_time)
									  * 1.0e-6 * (double) m_audio_sample_rate) + lock->m_segment_audio_samples_read;

		// drop samples that are too early
		if(pos < lock->m_audio_samples) {
			int64_t n = std::min(lock->m_audio_samples - pos, (int64_t) lock->m_audio_buffer.GetSize() / m_audio_sample_size);
			lock->m_audio_buffer.Drop(n * m_audio_sample_size);
			lock->m_segment_audio_samples_read += n;
			pos += n;
		}

		// send the samples to the encoder
		int64_t samples_left = std::min(samples_max, (int64_t) lock->m_audio_buffer.GetSize() / m_audio_sample_size);
		while(samples_left > 0) {

			// copy samples until either the partial frame is full or there are no samples left
			int64_t n = std::min((int64_t) (m_audio_required_frame_size - lock->m_partial_audio_frame_samples), samples_left);
			lock->m_audio_buffer.Read(lock->m_partial_audio_frame.data() + lock->m_partial_audio_frame_samples * m_audio_sample_size, n * m_audio_sample_size);
			lock->m_segment_audio_samples_read += n;
			lock->m_partial_audio_frame_samples += n;
			lock->m_audio_samples += n;
			samples_left -= n;

			// is the partial frame full?
			if(lock->m_partial_audio_frame_samples == m_audio_required_frame_size) {

				// allocate a frame
#if SSR_USE_AVUTIL_PLANAR_SAMPLE_FMT
				unsigned int planes = (m_audio_required_sample_format == AV_SAMPLE_FMT_S16P ||
									   m_audio_required_sample_format == AV_SAMPLE_FMT_FLTP)? m_audio_channels : 1;
#else
				unsigned int planes = 1;
#endif
				size_t plane_size = grow_align16(m_audio_required_frame_size * m_audio_required_sample_size / planes);
				std::unique_ptr<AVFrameWrapper> frame(new AVFrameWrapper(plane_size * planes));
				uint8_t *data = frame->data[0];
				for(unsigned int p = 0; p < planes; ++p) {
					frame->data[p] = data + plane_size * p;
					frame->linesize[p] = m_audio_required_frame_size * m_audio_required_sample_size / planes;
				}

				frame->nb_samples = m_audio_required_frame_size;
				frame->pts = lock->m_audio_samples;
#if SSR_USE_AVFRAME_FORMAT
				frame->format = m_audio_required_sample_format;
#endif

				// copy/convert the samples
				switch(m_audio_required_sample_format) {
					case AV_SAMPLE_FMT_S16: {
						memcpy(frame->data[0], lock->m_partial_audio_frame.data(), m_audio_required_frame_size * m_audio_required_sample_size);
						break;
					}
					case AV_SAMPLE_FMT_FLT: {
						int16_t *data_in = (int16_t*) lock->m_partial_audio_frame.data();
						float *data_out = (float*) frame->data[0];
						for(unsigned int i = 0; i < m_audio_required_frame_size * m_audio_channels; ++i) {
							*(data_out++) = (float) *(data_in++) / 32768.0f;
						}
						break;
					}
#if SSR_USE_AVUTIL_PLANAR_SAMPLE_FMT
					case AV_SAMPLE_FMT_S16P: {
						for(unsigned int p = 0; p < planes; ++p) {
							int16_t *data_in = (int16_t*) lock->m_partial_audio_frame.data() + p;
							int16_t *data_out = (int16_t*) frame->data[p];
							for(unsigned int i = 0; i < m_audio_required_frame_size; ++i) {
								*data_out = *data_in;
								data_in += planes; data_out++;
							}
						}
						break;
					}
					case AV_SAMPLE_FMT_FLTP: {
						for(unsigned int p = 0; p < planes; ++p) {
							int16_t *data_in = (int16_t*) lock->m_partial_audio_frame.data() + p;
							float *data_out = (float*) frame->data[p];
							for(unsigned int i = 0; i < m_audio_required_frame_size; ++i) {
								*data_out = (float) *data_in / 32768.0f;
								data_in += planes; data_out++;
							}
						}
						break;
					}
#endif
					default: {
						Q_ASSERT(false);
						break;
					}
				}
				lock->m_partial_audio_frame_samples = 0;

				//Logger::LogInfo("[Synchronizer::FlushBuffers] Encoded audio frame [" + QString::number(lock->m_partial_audio_frame->pts) + "].");
				m_audio_encoder->AddFrame(std::move(frame));
			}

		}

	}

}

void Synchronizer::run() {
	try {

		Logger::LogInfo("[Synchronizer::run] Synchronizer thread started.");

		while(!m_should_stop) {

			{
				SharedLock lock(&m_shared_data);
				FlushBuffers(lock.get());
			}

			usleep(10000);

		}

		Logger::LogInfo("[Synchronizer::run] Synchronizer thread stopped.");

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError(QString("[Synchronizer::run] Exception '") + e.what() + "' in synchronizer thread.");
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[Synchronizer::run] Unknown exception in synchronizer thread.");
	}
}
