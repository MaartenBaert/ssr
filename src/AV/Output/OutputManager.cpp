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

#include "OutputManager.h"

#include "Logger.h"

const size_t OutputManager::THROTTLE_THRESHOLD_FRAMES = 20;
const size_t OutputManager::THROTTLE_THRESHOLD_PACKETS = 100;

static QString GetNewFragmentFile(const QString& file, unsigned int fragment_number) {
	QFileInfo fi(file);
	QString newfile;
	newfile = fi.path() + "/" + fi.completeBaseName() + QString("-%1").arg(fragment_number, 8, 10, QLatin1Char('0'));
	if(!fi.suffix().isEmpty())
		newfile += "." + fi.suffix();
	return newfile;
}

OutputManager::OutputManager(const OutputSettings& output_settings) {

	m_output_settings = output_settings;

	m_fragmented = false;
	m_fragment_length = 5;

	// initialize shared data
	{
		SharedLock lock(&m_shared_data);
		lock->m_fragment_number = 0;
		lock->m_video_encoder = NULL;
		lock->m_audio_encoder = NULL;
	}

	// initialize thread signals
	m_should_stop = false;
	m_should_finish = false;
	m_is_done = false;
	m_error_occurred = false;

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

OutputManager::~OutputManager() {

	// tell the thread to stop
	if(m_thread.joinable()) {
		Logger::LogInfo("[OutputManager::~OutputManager] " + Logger::tr("Stopping fragment thread ..."));
		m_should_stop = true;
		m_thread.join();
	}

	// free everything
	Free();

}

void OutputManager::Finish() {

	// stop the synchronizer
	if(m_synchronizer != NULL) {
		m_synchronizer->NewSegment(); // needed to make sure that all data is sent to the encoders
		m_synchronizer.reset();
	}

	// after this, we still have to wait until IsFinished() returns true or else the file will be corrupted.
	if(m_fragmented) {
		m_should_finish = true;
	} else {
		SharedLock lock(&m_shared_data);
		assert(lock->m_muxer != NULL);
		lock->m_muxer->Finish();
	}

}

bool OutputManager::IsFinished() {
	SharedLock lock(&m_shared_data);
	if(m_fragmented) {
		return (m_is_done || m_error_occurred);
	} else {
		assert(lock->m_muxer != NULL);
		return (lock->m_muxer->IsDone() || lock->m_muxer->HasErrorOccurred());
	}
}

void OutputManager::AddVideoFrame(std::unique_ptr<AVFrameWrapper> frame) {
	assert(frame->GetFrame()->pts != (int64_t) AV_NOPTS_VALUE);
	SharedLock lock(&m_shared_data);
	if(m_fragmented) {
		int64_t fragment_begin = m_fragment_length * m_output_format.m_video_frame_rate * (lock->m_fragment_number - 1);
		int64_t fragment_end = m_fragment_length * m_output_format.m_video_frame_rate * lock->m_fragment_number;
		if(frame->GetFrame()->pts < fragment_end) {
			frame->GetFrame()->pts -= fragment_begin;
			assert(lock->m_video_encoder != NULL);
			lock->m_video_encoder->AddFrame(std::move(frame));
		} else {
			lock->m_video_frame_queue.push_back(std::move(frame));
		}
	} else {
		assert(lock->m_video_encoder != NULL);
		lock->m_video_encoder->AddFrame(std::move(frame));
	}
}

void OutputManager::AddAudioFrame(std::unique_ptr<AVFrameWrapper> frame) {
	assert(frame->GetFrame()->pts != (int64_t) AV_NOPTS_VALUE);
	SharedLock lock(&m_shared_data);
	if(m_fragmented) {
		int64_t fragment_begin = m_fragment_length * m_output_format.m_audio_sample_rate * (lock->m_fragment_number - 1);
		int64_t fragment_end = m_fragment_length * m_output_format.m_audio_sample_rate * lock->m_fragment_number;
		if(frame->GetFrame()->pts < fragment_end) {
			frame->GetFrame()->pts -= fragment_begin;
			assert(lock->m_audio_encoder != NULL);
			lock->m_audio_encoder->AddFrame(std::move(frame));
		} else {
			lock->m_audio_frame_queue.push_back(std::move(frame));
		}
	} else {
		assert(lock->m_audio_encoder != NULL);
		lock->m_audio_encoder->AddFrame(std::move(frame));
	}
}

int64_t OutputManager::GetVideoFrameDelay() {
	unsigned int frames = 0, packets = 0;
	{
		SharedLock lock(&m_shared_data);
		frames += lock->m_video_frame_queue.size();
		if(lock->m_video_encoder != NULL) {
			frames += lock->m_video_encoder->GetQueuedFrameCount();
			packets += lock->m_video_encoder->GetQueuedPacketCount();
		}
	}
	int64_t interval = 0;
	if(frames > THROTTLE_THRESHOLD_FRAMES) {
		int64_t n = (frames - THROTTLE_THRESHOLD_FRAMES) * 200 / THROTTLE_THRESHOLD_FRAMES;
		interval += n * n;
	}
	if(packets > THROTTLE_THRESHOLD_PACKETS) {
		int64_t n = (packets - THROTTLE_THRESHOLD_PACKETS) * 200 / THROTTLE_THRESHOLD_PACKETS;
		interval += n * n;
	}
	if(interval > 1000000)
		interval = 1000000;
	return interval;
}

unsigned int OutputManager::GetTotalQueuedFrameCount() {
	SharedLock lock(&m_shared_data);
	unsigned int frames = lock->m_video_frame_queue.size();
	if(lock->m_video_encoder != NULL)
		frames += lock->m_video_encoder->GetQueuedFrameCount() + lock->m_video_encoder->GetFrameLatency();
	return frames;
}

double OutputManager::GetActualFrameRate() {
	SharedLock lock(&m_shared_data);
	if(lock->m_video_encoder == NULL)
		return 0.0;
	return lock->m_video_encoder->GetActualFrameRate();
}

double OutputManager::GetActualBitRate() {
	SharedLock lock(&m_shared_data);
	if(lock->m_muxer == NULL)
		return 0.0;
	return lock->m_muxer->GetActualBitRate();
}

uint64_t OutputManager::GetTotalBytes() {
	SharedLock lock(&m_shared_data);
	if(lock->m_muxer == NULL)
		return 0;
	return lock->m_muxer->GetTotalBytes();
}

void OutputManager::Init() {

	// start muxer and encoders
	StartFragment();

	// save output format for synchronizer (we assume that this will always be the same)
	{
		SharedLock lock(&m_shared_data);
		if(lock->m_video_encoder != NULL) {
			m_output_format.m_video_enabled = true;
			m_output_format.m_video_width = lock->m_video_encoder->GetWidth();
			m_output_format.m_video_height = lock->m_video_encoder->GetHeight();
			m_output_format.m_video_frame_rate = lock->m_video_encoder->GetFrameRate();
			m_output_format.m_video_pixel_format = lock->m_video_encoder->GetPixelFormat();
			m_output_format.m_video_colorspace = lock->m_video_encoder->GetColorSpace();
		} else {
			m_output_format.m_video_enabled = false;
		}
		if(lock->m_audio_encoder != NULL) {
			m_output_format.m_audio_enabled = true;
			m_output_format.m_audio_channels = lock->m_audio_encoder->GetChannels(); //TODO// never larger than AV_NUM_DATA_POINTERS
			assert(m_output_format.m_audio_channels <= AV_NUM_DATA_POINTERS);
			m_output_format.m_audio_sample_rate = lock->m_audio_encoder->GetSampleRate();
			m_output_format.m_audio_frame_size = lock->m_audio_encoder->GetFrameSize();
			m_output_format.m_audio_sample_format = lock->m_audio_encoder->GetSampleFormat();
		} else {
			m_output_format.m_audio_enabled = false;
		}
	}

	// start synchronizer
	m_synchronizer.reset(new Synchronizer(this));

	// start fragment thread
	if(m_fragmented) {
		m_thread = std::thread(&OutputManager::FragmentThread, this);
	}

}

void OutputManager::Free() {

	// stop the synchronizer
	m_synchronizer.reset();

	// stop the encoders and muxers
	{
		SharedLock lock(&m_shared_data);
		lock->m_video_encoder = NULL; // deleted by muxer
		lock->m_audio_encoder = NULL; // deleted by muxer
		lock->m_muxer.reset();
	}

}

void OutputManager::StartFragment() {

	// get fragment number
	unsigned int fragment_number = 0;
	if(m_fragmented) {
		SharedLock lock(&m_shared_data);
		fragment_number = lock->m_fragment_number;
	}

	// create new muxer and encoders
	// we can't hold the lock while doing this because this could take some time
	QString filename;
	if(m_fragmented) {
		filename = GetNewFragmentFile(m_output_settings.file, fragment_number);
	} else {
		filename = m_output_settings.file;
	}
	std::unique_ptr<Muxer> muxer(new Muxer(m_output_settings.container_avname, filename));
	VideoEncoder *video_encoder = NULL;
	AudioEncoder *audio_encoder = NULL;
	if(!m_output_settings.video_codec_avname.isEmpty())
		video_encoder = muxer->AddVideoEncoder(m_output_settings.video_codec_avname, m_output_settings.video_options, m_output_settings.video_kbit_rate * 1000,
											   m_output_settings.video_width, m_output_settings.video_height, m_output_settings.video_frame_rate);
	if(!m_output_settings.audio_codec_avname.isEmpty())
		audio_encoder = muxer->AddAudioEncoder(m_output_settings.audio_codec_avname, m_output_settings.audio_options, m_output_settings.audio_kbit_rate * 1000,
											   m_output_settings.audio_channels, m_output_settings.audio_sample_rate);
	muxer->Start();

	// acquire lock and share the muxer and encoders
	SharedLock lock(&m_shared_data);
	lock->m_muxer = std::move(muxer);
	lock->m_video_encoder = video_encoder;
	lock->m_audio_encoder = audio_encoder;

	// increment fragment number
	// It's important that this is done here (i.e. after the encoders have been set up), because the fragment number
	// acts as a signal to AddVideoFrame/AddAudioFrame that they can pass frames to the encoders.
	++lock->m_fragment_number;

	// push queued frames to the new encoders
	if(m_fragmented) {
		while(!lock->m_video_frame_queue.empty()) {
			int64_t fragment_begin = m_fragment_length * m_output_format.m_video_frame_rate * (lock->m_fragment_number - 1);
			int64_t fragment_end = m_fragment_length * m_output_format.m_video_frame_rate * lock->m_fragment_number;
			if(lock->m_video_frame_queue.front()->GetFrame()->pts >= fragment_end)
				break;
			std::unique_ptr<AVFrameWrapper> frame = std::move(lock->m_video_frame_queue.front());
			lock->m_video_frame_queue.pop_front();
			frame->GetFrame()->pts -= fragment_begin;
			video_encoder->AddFrame(std::move(frame));
		}
		while(!lock->m_audio_frame_queue.empty()) {
			int64_t fragment_begin = m_fragment_length * m_output_format.m_audio_sample_rate * (lock->m_fragment_number - 1);
			int64_t fragment_end = m_fragment_length * m_output_format.m_audio_sample_rate * lock->m_fragment_number;
			if(lock->m_audio_frame_queue.front()->GetFrame()->pts >= fragment_end)
				break;
			std::unique_ptr<AVFrameWrapper> frame = std::move(lock->m_audio_frame_queue.front());
			lock->m_audio_frame_queue.pop_front();
			frame->GetFrame()->pts -= fragment_begin;
			audio_encoder->AddFrame(std::move(frame));
		}
	}

}

void OutputManager::StopFragment() {

	// acquire lock and steal the muxer
	std::unique_ptr<Muxer> muxer;
	{
		SharedLock lock(&m_shared_data);
		muxer = std::move(lock->m_muxer);
		lock->m_video_encoder = NULL; // deleted by muxer
		lock->m_audio_encoder = NULL; // deleted by muxer
	}

	// wait until the muxer is finished
	// we can't hold the lock while doing this because this could take some time
	assert(muxer != NULL);
	muxer->Finish();
	while(!muxer->IsDone() && !muxer->HasErrorOccurred()) {
		usleep(200000);
	}

	// delete everything
	muxer.reset();

}

void OutputManager::FragmentThread() {
	try {

		Logger::LogInfo("[OutputManager::FragmentThread] " + Logger::tr("Fragment thread started."));

		while(!m_should_stop) {

			// should we start a new fragment?
			bool finishing = m_should_finish, next_fragment = false;
			{
				SharedLock lock(&m_shared_data);
				//TODO// this delays the creation of a new fragment by one frame, this could be improved
				if(finishing) {
					next_fragment = (!lock->m_video_frame_queue.empty() || !lock->m_audio_frame_queue.empty());
				} else {
					next_fragment = (!lock->m_video_frame_queue.empty() && !lock->m_audio_frame_queue.empty());
				}
			}

			// do what needs to be done
			if(next_fragment) {
				Logger::LogInfo("[OutputManager::FragmentThread] " + Logger::tr("Next fragment ..."));
				StopFragment();
				StartFragment();
			} else if(finishing) {
				Logger::LogInfo("[OutputManager::FragmentThread] " + Logger::tr("Finishing ..."));
				StopFragment();
				break;
			} else {
				usleep(200000);
			}

		}

		// tell the others that we're done
		m_is_done = true;

		Logger::LogInfo("[OutputManager::FragmentThread] " + Logger::tr("Fragment thread stopped."));

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError("[OutputManager::FragmentThread] " + Logger::tr("Exception '%1' in fragment thread.").arg(e.what()));
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[OutputManager::FragmentThread] " + Logger::tr("Unknown exception in fragment thread."));
	}
}
