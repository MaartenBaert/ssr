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

#include "AudioPreviewer.h"

#include "SampleCast.h"
#include "Logger.h"

AudioPreviewer::AudioPreviewer(QWidget* parent)
	: QWidget(parent) {

	{
		SharedLock lock(&m_shared_data);
		lock->m_channel_data.resize(1);
		lock->m_next_samples = 0;
		lock->m_next_frame_time = hrt_time_micro();
		lock->m_frame_rate = 20;
	}

	setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);

	connect(this, SIGNAL(NeedsUpdate()), this, SLOT(update()), Qt::QueuedConnection);

}

AudioPreviewer::~AudioPreviewer() {

	// disconnect
	ConnectAudioSource(NULL);

}

void AudioPreviewer::Reset() {
	SharedLock lock(&m_shared_data);
	lock->m_channel_data.clear();
	lock->m_channel_data.resize(1);
	lock->m_next_samples = 0;
	emit NeedsUpdate();
}

void AudioPreviewer::SetFrameRate(unsigned int frame_rate) {
	SharedLock lock(&m_shared_data);
	lock->m_frame_rate = std::max(1u, frame_rate);
}

void AudioPreviewer::ReadAudioSamples(unsigned int channels, unsigned int sample_rate, AVSampleFormat format, unsigned int sample_count, const uint8_t* data, int64_t timestamp) {
	Q_UNUSED(sample_rate);
	Q_UNUSED(timestamp);
	SharedLock lock(&m_shared_data);

	if(sample_count == 0)
		return;

	// save the samples
	lock->m_channel_data.resize(channels);
	switch(format) {
		case AV_SAMPLE_FMT_S16: {
			const int16_t *data_in = (const int16_t*) data;
			for(size_t i = 0; i < sample_count; ++i) {
				for(unsigned int c = 0; c < channels; ++c) {
					lock->m_channel_data[c].Analyze(*(data_in++));
				}
			}
			break;
		}
		case AV_SAMPLE_FMT_S32: {
			const int32_t *data_in = (const int32_t*) data;
			for(size_t i = 0; i < sample_count; ++i) {
				for(unsigned int c = 0; c < channels; ++c) {
					lock->m_channel_data[c].Analyze(*(data_in++));
				}
			}
			break;
		}
		case AV_SAMPLE_FMT_FLT: {
			const float *data_in = (const float*) data;
			for(size_t i = 0; i < sample_count; ++i) {
				for(unsigned int c = 0; c < channels; ++c) {
					lock->m_channel_data[c].Analyze(*(data_in++));
				}
			}
			break;
		}
		default: {
			assert(false); // unsupported sample format
			break;
		}
	}
	lock->m_next_samples += sample_count;

	// check the time
	int64_t time = hrt_time_micro();
	if(time < lock->m_next_frame_time)
		return;
	lock->m_next_frame_time = std::max(lock->m_next_frame_time + 1000000 / lock->m_frame_rate, time);

	// move the low/high values from 'next' to 'current'
	for(unsigned int c = 0; c < channels; ++c) {
		lock->m_channel_data[c].m_current_peak = lock->m_channel_data[c].m_next_peak;
		lock->m_channel_data[c].m_current_rms = sqrt(lock->m_channel_data[c].m_next_rms / (float) lock->m_next_samples);
		lock->m_channel_data[c].m_next_peak = 0.0f;
		lock->m_channel_data[c].m_next_rms = 0.0f;
	}
	lock->m_next_samples = 0;

	emit NeedsUpdate();

}

void AudioPreviewer::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	QPainter painter(this);

	std::vector<ChannelData> channel_data;
	{
		SharedLock lock(&m_shared_data);
		channel_data = lock->m_channel_data;
	}

	painter.fillRect(rect(), QColor(200, 200, 200));

	int w = width() - 1, h = height() - 1;

	QLinearGradient grad1(0.0, 0.0, (double) width(), 0.0);
	grad1.setColorAt(0.0, QColor(0, 255, 0));
	grad1.setColorAt(0.5, QColor(255, 255, 0));
	grad1.setColorAt(1.0, QColor(255, 0, 0));
	QLinearGradient grad2(0.0, 0.0, (double) width(), 0.0);
	grad2.setColorAt(0.0, QColor(0, 150, 0));
	grad2.setColorAt(0.5, QColor(150, 150, 0));
	grad2.setColorAt(1.0, QColor(150, 0, 0));
	painter.setPen(Qt::NoPen);
	unsigned int n = channel_data.size();
	for(unsigned int c = 0; c < n; ++c) {
		// the scale goes down to 80dB which corresponds to 1.0e-4 (for sound pressure, 20dB = 10x)
		float val_peak = log10(fmax(1.0e-4f, channel_data[c].m_current_peak)) / 4.0f + 1.0f;
		float val_rms = log10(fmax(1.0e-4f, channel_data[c].m_current_rms)) / 4.0f + 1.0f;
		int x1 = 0, x2 = (int) round((float) w * val_rms), x3 = (int) round((float) w * val_peak);
		int y1 = h * c / n, y2 = h * (c + 1) / n;
		painter.setBrush(grad1);
		painter.drawRect(x1, y1, x2 - x1, y2 - y1);
		painter.setBrush(grad2);
		painter.drawRect(x2, y1, x3 - x2, y2 - y1);
	}

	painter.setPen(QColor(0, 0, 0));
	painter.setBrush(Qt::NoBrush);
	painter.setRenderHint(QPainter::Antialiasing);
	for(unsigned int c = 0; c < n; ++c) {
		int y1 = h * c / n, y2 = h * (c + 1) / n;
		painter.drawRect(QRectF(0.5, (qreal) y1 + 0.5, (qreal) w, (qreal) (y2 - y1)));
	}

}
