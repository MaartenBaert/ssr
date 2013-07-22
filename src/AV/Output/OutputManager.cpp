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
#include "OutputManager.h"

OutputManager::OutputManager(const OutputSettings& output_settings) {

	m_output_settings = output_settings;

	m_muxer = NULL;
	m_video_encoder = NULL;
	m_audio_encoder = NULL;
	m_synchronizer = NULL;

	try {
		Init();
	} catch(...) {
		Free(false);
		throw;
	}

}

OutputManager::~OutputManager() {
	Free(false);
}

void OutputManager::Finish() {
	Free(true);
}

void OutputManager::Init() {
	m_muxer = new Muxer(m_output_settings.container_avname, m_output_settings.file);
	if(!m_output_settings.video_codec_avname.isEmpty())
		m_video_encoder = new VideoEncoder(m_muxer, m_output_settings.video_codec_avname, m_output_settings.video_options, m_output_settings.video_kbit_rate * 1024,
										   m_output_settings.video_width, m_output_settings.video_height, m_output_settings.video_frame_rate);
	if(!m_output_settings.audio_codec_avname.isEmpty())
		m_audio_encoder = new AudioEncoder(m_muxer, m_output_settings.audio_codec_avname, m_output_settings.audio_options, m_output_settings.audio_kbit_rate * 1024,
										   m_output_settings.audio_sample_rate);
	m_muxer->Start();
	m_synchronizer = new Synchronizer(m_video_encoder, m_audio_encoder);
}

void OutputManager::Free(bool save) {

	// stop the synchronizer
	if(m_synchronizer != NULL) {
		delete m_synchronizer;
		m_synchronizer = NULL;
	}

	// If we want to save the file, we have to wait for the encoders and mixer to finish or else the file will be corrupted.
	if(save && m_muxer != NULL && m_muxer->IsStarted()) {
		m_muxer->Finish();
		while(!m_muxer->IsDone() && !m_muxer->HasErrorOccurred()) {
			usleep(10000);
		}
	}

	// stop the encoders and muxers
	m_video_encoder = NULL; // deleted by muxer
	m_audio_encoder = NULL; // deleted by muxer
	if(m_muxer != NULL) {
		delete m_muxer;
		m_muxer = NULL;
	}

}
