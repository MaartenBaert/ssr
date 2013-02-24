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

AudioInput::AudioInput(Synchronizer* synchronizer, const QString& alsa_device)
	: BaseInput(synchronizer) {
	Q_ASSERT(GetSynchronizer()->GetAudioEncoder() != NULL);

	m_sample_rate = GetSynchronizer()->GetAudioEncoder()->GetSampleRate();

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

}

void AudioInput::ReadFrame(AVFrameWrapper* frame) {

	// sanity check
	if(frame->nb_samples == 0)
		return;

#if SSR_USE_AVFRAME_FORMAT
	// check the format
	if(frame->format != AV_SAMPLE_FMT_S16) {
		Logger::LogError("[AudioInput::ReadFrame] Error: Audio frame uses format " + QString::number(frame->format) + " instead of " + QString::number(AV_SAMPLE_FMT_S16) + " (AV_SAMPLE_FMT_S16)!");
		throw LibavException();
	}
#endif

	GetSynchronizer()->AddAudioSamples((char*) frame->data[0], frame->nb_samples, frame->pkt_dts - (int64_t) frame->nb_samples * (int64_t) 1000000 / (int64_t) m_sample_rate);

}
