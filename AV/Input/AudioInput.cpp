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
#include "AudioInput.h"

#include "Logger.h"
#include "AVWrapper.h"
#include "Synchronizer.h"
#include "AudioEncoder.h"

AudioInput::AudioInput(Logger* logger, Synchronizer* synchronizer, const QString& alsa_device)
	: BaseInput(logger, synchronizer) {
	Q_ASSERT(GetSynchronizer()->GetAudioEncoder() != NULL);

	m_sample_rate = GetSynchronizer()->GetAudioEncoder()->GetSampleRate();
	m_required_frame_size = GetSynchronizer()->GetAudioEncoder()->GetRequiredFrameSize();

	// get alsa device
	// options: alsa-audio-dec.c line 153
	AVInputFormat *format = av_find_input_format("alsa");
	AVDictionary *options = NULL;
	try {
		QString str_sample_rate = QString::number(m_sample_rate);
		av_dict_set(&options, "sample_rate", qPrintable(str_sample_rate), 0);
		av_dict_set(&options, "channels", "2", 0);
		Start(qPrintable(alsa_device), format, &options, AVMEDIA_TYPE_AUDIO);
		av_dict_free(&options);
	} catch(...) {
		av_dict_free(&options);
		throw;
	}

}

AudioInput::~AudioInput() {

	Stop();

	// is there a partial frame?
	if(m_partial_frame != NULL) {
		int samples_left = m_required_frame_size - m_partial_frame->nb_samples;
		memset(m_partial_frame->data[0] + m_partial_frame->nb_samples * 4, 0, samples_left * 4);
		m_partial_frame->nb_samples = m_required_frame_size;
		GetSynchronizer()->AddAudioFrame(std::move(m_partial_frame));
	}

}

void AudioInput::ReadFrame(AVFrame* frame) {

	// sanity check
	if(frame->nb_samples == 0)
		return;

	// check the format
	if(frame->format != AV_SAMPLE_FMT_S16) {
		GetLogger()->LogError("[AudioInput::ReadFrame] Error: Audio frame uses format " + QString::number(frame->format) + " instead of " + QString::number(AV_SAMPLE_FMT_S16) + " (AV_SAMPLE_FMT_S16)!");
		throw LibavException();
	}

	// fill partial frame
	unsigned int current_position = 0;
	while(current_position < (unsigned int) frame->nb_samples) {

		// create a frame if it doesn't exist already
		if(m_partial_frame == NULL) {
			unsigned int frame_samples_left = (unsigned int) frame->nb_samples - current_position;
			m_partial_frame.reset(new AVFrameWrapper(m_required_frame_size * 4));
			m_partial_frame->linesize[0] = m_required_frame_size * 4;
			m_partial_frame->nb_samples = 0;
			m_partial_frame->pkt_dts = frame->pkt_dts - (int64_t) frame_samples_left * (int64_t) 1000000 / (int64_t) m_sample_rate;
		}

		// read samples until either the partial frame is full or the recorded frame is empty
		unsigned int samples_left = std::min((unsigned int) frame->nb_samples - current_position, m_required_frame_size - (unsigned int) m_partial_frame->nb_samples);
		memcpy(m_partial_frame->data[0] + (unsigned int) m_partial_frame->nb_samples * 4, frame->data[0] + current_position * 4, samples_left * 4);
		current_position += samples_left;
		m_partial_frame->nb_samples += samples_left;

		// is the partial frame full?
		if((unsigned int) m_partial_frame->nb_samples == m_required_frame_size) {
			GetSynchronizer()->AddAudioFrame(std::move(m_partial_frame));
		}

	}

}
