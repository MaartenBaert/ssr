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

#include "AudioPreviewer.h"

#include "Logger.h"

AudioPreviewer::AudioPreviewer(QWidget* parent)
	: QWidget(parent) {

	{
		SharedLock lock(&m_shared_data);
		for(unsigned int channel = 0; channel < 2; ++channel) {
			lock->m_current_low[channel] = 0.0;
			lock->m_current_high[channel] = 0.0;
			lock->m_next_low[channel] = std::numeric_limits<double>::max();
			lock->m_next_high[channel] = -std::numeric_limits<double>::max();
		}
		lock->m_next_frame_time = hrt_time_micro();
		lock->m_frame_rate = 30;
	}

	setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

	connect(this, SIGNAL(NeedsUpdate()), this, SLOT(update()), Qt::QueuedConnection);

}

AudioPreviewer::~AudioPreviewer() {

	// disconnect
	ConnectAudioSource(NULL);

}

void AudioPreviewer::Reset() {
	SharedLock lock(&m_shared_data);
	for(unsigned int channel = 0; channel < 2; ++channel) {
		lock->m_current_low[channel] = 0.0;
		lock->m_current_high[channel] = 0.0;
		lock->m_next_low[channel] = std::numeric_limits<double>::max();
		lock->m_next_high[channel] = -std::numeric_limits<double>::max();
	}
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

	Q_ASSERT(channels == 2); // only stereo is currently supported

	// save the samples
	switch(format) {
		case AV_SAMPLE_FMT_S16: {
			int16_t *data_in = (int16_t*) data;
			for(size_t i = 0; i < sample_count; ++i) {
				for(unsigned int channel = 0; channel < 2; ++channel) {
					double val = (double) *(data_in++) / 32768.0;
					if(val < lock->m_next_low[channel])
						lock->m_next_low[channel] = val;
					if(val > lock->m_next_high[channel])
						lock->m_next_high[channel] = val;
				}
			}
			break;
		}
		case AV_SAMPLE_FMT_FLT: {
			float *data_in = (float*) data;
			for(size_t i = 0; i < sample_count; ++i) {
				for(unsigned int channel = 0; channel < 2; ++channel) {
					double val = *(data_in++);
					if(val < lock->m_next_low[channel])
						lock->m_next_low[channel] = val;
					if(val > lock->m_next_high[channel])
						lock->m_next_high[channel] = val;
				}
			}
			break;
		}
		default: {
			Q_ASSERT(false); // unsupported sample format
			break;
		}
	}

	// check the time
	int64_t time = hrt_time_micro();
	if(time < lock->m_next_frame_time)
		return;
	lock->m_next_frame_time = std::max(lock->m_next_frame_time + 1000000 / lock->m_frame_rate, time);

	// move the low/high values from 'next' to 'current'
	for(unsigned int channel = 0; channel < 2; ++channel) {
		lock->m_current_low[channel] = lock->m_next_low[channel];
		lock->m_current_high[channel] = lock->m_next_high[channel];
		lock->m_next_low[channel] = std::numeric_limits<double>::max();
		lock->m_next_high[channel] = -std::numeric_limits<double>::max();
	}

	emit NeedsUpdate();

}

void AudioPreviewer::showEvent(QShowEvent* event) {
	Q_UNUSED(event);
	SharedLock lock(&m_shared_data);
	lock->m_is_visible = true;
}

void AudioPreviewer::hideEvent(QHideEvent *event) {
	Q_UNUSED(event);
	SharedLock lock(&m_shared_data);
	lock->m_is_visible = false;
}

void AudioPreviewer::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	SharedLock lock(&m_shared_data);
	QPainter painter(this);

	int w = width() - 1, h = height() - 1;

	painter.setPen(Qt::NoPen);
	painter.setBrush(QColor(150, 150, 150));
	for(unsigned int channel = 0; channel < 2; ++channel) {
		painter.drawRect(0, 0, w, h);
	}

	QLinearGradient grad(0.0, 0.0, (double) width(), 0.0);
	grad.setColorAt(0.0, QColor(0, 200, 0));
	grad.setColorAt(0.5, QColor(255, 255, 0));
	grad.setColorAt(1.0, QColor(255, 0, 0));
	painter.setPen(Qt::NoPen);
	painter.setBrush(grad);
	for(unsigned int channel = 0; channel < 2; ++channel) {
		// the scale goes down to 60dB which corresponds to 1.0e-3 (for sound pressure, 20dB = 10x)
		double val = log10(std::max(1.0e-3, (lock->m_current_high[channel] - lock->m_current_low[channel]) / 2.0)) / 3.0 + 1.0;
		painter.drawRect(0, h * channel / 2, (int) round((double) w * val), h * (channel + 1) / 2 - h * channel / 2);
	}

	painter.setPen(QColor(0, 0, 0));
	painter.setBrush(Qt::NoBrush);
	for(unsigned int channel = 0; channel < 2; ++channel) {
		painter.drawRect(0, h * channel / 2, w, h * (channel + 1) / 2 - h * channel / 2);
	}

}
