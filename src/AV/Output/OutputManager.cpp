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

#include "Global.h"
#include "OutputManager.h"

OutputManager::OutputManager(const OutputSettings& output_settings) {

	m_output_settings = output_settings;

	m_video_encoder = NULL;
	m_audio_encoder = NULL;

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

OutputManager::~OutputManager() {
	Free();
}

void OutputManager::Finish() {

	// stop the synchronizer
	if(m_synchronizer != NULL) {
		m_synchronizer->NewSegment(); // needed to make sure that all data is sent to the encoders
		m_synchronizer.reset();
	}

	// we have to wait for the encoders and muxer to finish or else the file will be corrupted.
	m_muxer->Finish();

}

bool OutputManager::IsFinished() {
	return (m_muxer->IsDone() || m_muxer->HasErrorOccurred());
}

void OutputManager::Init() {
	m_muxer.reset(new Muxer(m_output_settings.container_avname, m_output_settings.file));
	if(!m_output_settings.video_codec_avname.isEmpty())
		m_video_encoder = m_muxer->AddVideoEncoder(m_output_settings.video_codec_avname, m_output_settings.video_options, m_output_settings.video_kbit_rate * 1024,
												   m_output_settings.video_width, m_output_settings.video_height, m_output_settings.video_frame_rate);
	if(!m_output_settings.audio_codec_avname.isEmpty())
		m_audio_encoder = m_muxer->AddAudioEncoder(m_output_settings.audio_codec_avname, m_output_settings.audio_options, m_output_settings.audio_kbit_rate * 1024,
												   m_output_settings.audio_channels, m_output_settings.audio_sample_rate);
	m_muxer->Start();
	m_synchronizer.reset(new Synchronizer(m_video_encoder, m_audio_encoder, m_output_settings.video_allow_frame_skipping));
}

void OutputManager::Free() {

	// stop the synchronizer
	m_synchronizer.reset();

	// stop the encoders and muxers
	m_video_encoder = NULL; // deleted by muxer
	m_audio_encoder = NULL; // deleted by muxer
	m_muxer.reset();

}
