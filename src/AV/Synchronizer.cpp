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

	// free everything
	Free();

}

void Synchronizer::Init() {

	if(m_video_encoder != NULL) {
		m_video_frame_rate = m_video_encoder->GetFrameRate();
	}
	if(m_audio_encoder != NULL) {
		m_audio_sample_rate = m_audio_encoder->GetSampleRate();
		m_audio_sample_size = 4; //TODO// support channel counts other than 2
		m_audio_required_frame_size = m_audio_encoder->GetRequiredFrameSize();
		m_audio_required_sample_format = m_audio_encoder->GetRequiredSampleFormat();
		switch(m_audio_required_sample_format) {
			case AV_SAMPLE_FMT_S16:
#if SSR_USE_AVUTIL_PLANAR_SAMPLE_FMT
			case AV_SAMPLE_FMT_S16P:
#endif
				m_audio_required_sample_size = 4; break;
			case AV_SAMPLE_FMT_FLT:
#if SSR_USE_AVUTIL_PLANAR_SAMPLE_FMT
			case AV_SAMPLE_FMT_FLTP:
#endif
				m_audio_required_sample_size = 8; break;
			default: Q_ASSERT(false); break;
		}
		if(m_audio_required_sample_format != AV_SAMPLE_FMT_S16) {
			m_temp_audio_buffer.resize(m_audio_required_frame_size * m_audio_sample_size);
		}
	}

	m_sws_context = NULL;

	{
		SharedLock lock(&m_shared_data);
		lock->m_video_pts = 0;
		lock->m_audio_samples = 0;
		lock->m_time_correction_factor = 1.0;
		lock->m_time_offset = 0;
		lock->m_segment_video_started = (m_video_encoder == NULL);
		lock->m_segment_audio_started = (m_audio_encoder == NULL);
		lock->m_segment_audio_samples_read = 0;
		lock->m_warn_swscale = true;
		lock->m_warn_drop_video = true;
		lock->m_warn_drop_audio = true;
		lock->m_warn_desync = true;
	}

}

void Synchronizer::Free() {
	if(m_sws_context != NULL) {
		sws_freeContext(m_sws_context);
		m_sws_context = NULL;
	}
}

void Synchronizer::NewSegment() {
	SharedLock lock(&m_shared_data);

	if(lock->m_segment_video_started && lock->m_segment_audio_started) {
		int64_t segment_start_time, segment_stop_time;
		GetSegmentStartStop(lock.get(), &segment_start_time, &segment_stop_time);
		lock->m_time_offset += (int64_t) ((double) (segment_stop_time - segment_start_time) * lock->m_time_correction_factor);
	}

	lock->m_video_buffer.clear();
	lock->m_audio_buffer.Clear();
	lock->m_segment_video_started = (m_video_encoder == NULL);
	lock->m_segment_audio_started = (m_audio_encoder == NULL);
	lock->m_segment_audio_samples_read = 0;

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

void Synchronizer::ReadVideoFrame(unsigned int width, unsigned int height, uint8_t* data, int stride, PixelFormat format, int64_t timestamp) {
	Q_ASSERT(m_video_encoder != NULL);
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

	// convert the frame to YUV420P
	bool scaling = (width != m_video_width || height != m_video_height);
	if(format == PIX_FMT_BGRA && !scaling) {

		// use my faster converter
		m_yuv_converter.Convert(width, height, data, stride, converted_frame->data, converted_frame->linesize);

	} else {

		if(m_warn_swscale) {
			m_warn_swscale = false;
			if(scaling)
				Logger::LogInfo("[X11Input::run] Using swscale for scaling.");
			else
				Logger::LogWarning("[X11Input::run] Warning: Pixel format is " + QString::number(x11_image_format) + " instead of "
									 + QString::number(PIX_FMT_BGRA) + " (PIX_FMT_BGRA), falling back to swscale. This is not a problem but performance will be worse.");
		}

		// get sws context
		m_sws_context = sws_getCachedContext(m_sws_context,
											 width, height, format,
											 m_video_width, m_video_height, PIX_FMT_YUV420P,
											 SWS_BILINEAR, NULL, NULL, NULL);
		if(m_sws_context == NULL) {
			Logger::LogError("[X11Input::run] Error: Can't get swscale context!");
			throw LibavException();
		}
		sws_scale(m_sws_context, &image_data, &image_stride, 0, m_height, converted_frame->data, converted_frame->linesize);

	}

	// store the frame
	frame->pkt_dts = timestamp;
	lock->m_video_buffer.push_back(std::move(converted_frame));

	// increase segment stop time
	lock->m_segment_video_stop_time = timestamp + (int64_t) 1000000 / (int64_t) m_video_frame_rate;

	//Logger::LogInfo("[Synchronizer::AddVideoFrame] Added video frame at " + QString::number(timestamp) + ".");

	// flush buffers
	if(lock->m_segment_audio_started)
		FlushBuffers(lock.get());

}

void Synchronizer::AddAudioSamples(const char* samples, size_t samplecount, int64_t timestamp) {
	Q_ASSERT(m_audio_encoder != NULL);
	SharedLock lock(&m_shared_data);

	if(samplecount == 0)
		return;

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

	// start audio
	if(!lock->m_segment_audio_started) {
		lock->m_segment_audio_started = true;
		lock->m_segment_audio_start_time = timestamp;
	}

	// do speed correction (i.e. do the calculations so the video can synchronize to it)
	// The point of speed correction is to keep video and audio in sync even when the clocks are not running at exactly the same speed.
	// This can happen because the sample rate of the sound card is not always 100% accurate. Even a 0.1% error will result in audio that is
	// seconds too early or too late at the end of a one hour video. This problem doesn't occur on all computers though (I'm not sure why).
	// Speed correction only starts after at least 5 seconds of audio have been recorded, because otherwise the timestamps are too inaccurate.
	// The speed correction factor is also clamped to 95% .. 105% to limit the potential damage if this code produces wrong results :).
	double sample_length = (double) (lock->m_segment_audio_samples_read + lock->m_audio_buffer.GetSize() / m_audio_sample_size) / (double) m_audio_sample_rate;
	double time_length = (double)(timestamp - lock->m_segment_audio_start_time) * 1.0e-6;
	if(time_length > 5.0) {
		double time_correction_factor = sample_length / time_length;
		lock->m_time_correction_factor = lock->m_time_correction_factor + (time_correction_factor - lock->m_time_correction_factor) * CORRECTION_SPEED;
		if(lock->m_time_correction_factor < 0.95) {
			lock->m_time_correction_factor = 0.95;
			if(lock->m_warn_desync) {
				lock->m_warn_desync = false;
				Logger::LogWarning("[Synchronizer::AddAudioSamples] Warning: Audio input is more than 5% too slow, video and audio will be out of sync.");
			}
		}
		if(lock->m_time_correction_factor > 1.05) {
			lock->m_time_correction_factor = 1.05;
			if(lock->m_warn_desync) {
				lock->m_warn_desync = false;
				Logger::LogWarning("[Synchronizer::AddAudioSamples] Warning: Audio input is more than 5% too fast, video and audio will be out of sync.");
			}
		}
	}

	// store the samples
	lock->m_audio_buffer.Write(samples, samplecount * m_audio_sample_size);

	// increase segment stop time
	sample_length = (double) (lock->m_segment_audio_samples_read + lock->m_audio_buffer.GetSize() / m_audio_sample_size) / (double) m_audio_sample_rate;
	lock->m_segment_audio_stop_time = lock->m_segment_audio_start_time + (int64_t) (sample_length / lock->m_time_correction_factor * 1.0e6);

	//Logger::LogInfo("[Synchronizer::AddAudioSamples] Added audio samples at " + QString::number(timestamp) + ".");

	// flush buffers
	if(lock->m_segment_video_started)
		FlushBuffers(lock.get());

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
	Q_ASSERT(lock->m_segment_video_started && lock->m_segment_audio_started);

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

			// create a partial frame if it doesn't exist already
			if(lock->m_partial_audio_frame == NULL) {
				lock->m_partial_audio_frame.reset(new AVFrameWrapper(m_audio_required_frame_size * m_audio_required_sample_size));
				switch(m_audio_required_sample_format) {
					case AV_SAMPLE_FMT_S16:
					case AV_SAMPLE_FMT_FLT: {
						lock->m_partial_audio_frame->linesize[0] = m_audio_required_frame_size * m_audio_required_sample_size;
						break;
					}
#if SSR_USE_AVUTIL_PLANAR_SAMPLE_FMT
					case AV_SAMPLE_FMT_S16P:
					case AV_SAMPLE_FMT_FLTP: {
						lock->m_partial_audio_frame->linesize[0] = m_audio_required_frame_size * m_audio_required_sample_size / 2;
						lock->m_partial_audio_frame->linesize[1] = m_audio_required_frame_size * m_audio_required_sample_size / 2;
						lock->m_partial_audio_frame->data[1] = lock->m_partial_audio_frame->data[0] + lock->m_partial_audio_frame->linesize[0];
						break;
					}
#endif
					default: {
						Q_ASSERT(false);
						break;
					}
				}
				lock->m_partial_audio_frame->nb_samples = 0;
				lock->m_partial_audio_frame->pts = lock->m_audio_samples;
#if SSR_USE_AVFRAME_FORMAT
				lock->m_partial_audio_frame->format = m_audio_required_sample_format;
#endif
			}

			// copy samples until either the partial frame is full or there are no samples left
			int64_t n = std::min((int64_t) m_audio_required_frame_size - lock->m_partial_audio_frame->nb_samples, samples_left);
			if(m_audio_required_sample_format == AV_SAMPLE_FMT_S16) {
				lock->m_audio_buffer.Read((char*) lock->m_partial_audio_frame->data[0] + lock->m_partial_audio_frame->nb_samples * m_audio_sample_size, n * m_audio_sample_size);
			} else {
				lock->m_audio_buffer.Read(m_temp_audio_buffer.data() + lock->m_partial_audio_frame->nb_samples * m_audio_sample_size, n * m_audio_sample_size);
			}
			lock->m_segment_audio_samples_read += n;
			lock->m_partial_audio_frame->nb_samples += n;
			lock->m_audio_samples += n;
			samples_left -= n;

			// is the partial frame full?
			if(lock->m_partial_audio_frame->nb_samples == (int) m_audio_required_frame_size) {
				 //TODO// support channel counts other than 2
				int16_t *data_in = (int16_t*) m_temp_audio_buffer.data();
				switch(m_audio_required_sample_format) {
					case AV_SAMPLE_FMT_S16: {
						break;
					}
					case AV_SAMPLE_FMT_FLT: {
						float *data_out = (float*) lock->m_partial_audio_frame->data[0];
						for(unsigned int i = 0; i < m_audio_required_frame_size * 2; ++i) {
							*(data_out++) = (double) *(data_in++) / 32768.0;
						}
						break;
					}
#if SSR_USE_AVUTIL_PLANAR_SAMPLE_FMT
					case AV_SAMPLE_FMT_S16P: {
						int16_t *data_out1 = (int16_t*) lock->m_partial_audio_frame->data[0];
						int16_t *data_out2 = (int16_t*) lock->m_partial_audio_frame->data[1];
						for(unsigned int i = 0; i < m_audio_required_frame_size; ++i) {
							*(data_out1++) = *(data_in++);
							*(data_out2++) = *(data_in++);
						}
						break;
					}
					case AV_SAMPLE_FMT_FLTP: {
						float *data_out1 = (float*) lock->m_partial_audio_frame->data[0];
						float *data_out2 = (float*) lock->m_partial_audio_frame->data[1];
						for(unsigned int i = 0; i < m_audio_required_frame_size; ++i) {
							*(data_out1++) = (double) *(data_in++) / 32768.0;
							*(data_out2++) = (double) *(data_in++) / 32768.0;
						}
						break;
					}
#endif
					default: {
						Q_ASSERT(false);
						break;
					}
				}
				//Logger::LogInfo("[Synchronizer::FlushBuffers] Encoded audio frame [" + QString::number(lock->m_partial_audio_frame->pts) + "].");
				m_audio_encoder->AddFrame(std::move(lock->m_partial_audio_frame));
			}

		}

	}

}

void Synchronizer::ClearBuffers(SharedData* lock) {
	lock->m_video_buffer.clear();
	lock->m_audio_buffer.Clear();
}
