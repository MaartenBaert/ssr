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

#include "StdAfx.h"
#include "AudioPreviewer.h"

#include "Logger.h"

AudioPreviewer::AudioPreviewer(QWidget* parent)
	: QWidget(parent) {

	m_should_repaint = false;

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

}

AudioPreviewer::~AudioPreviewer() {

}

void AudioPreviewer::Reset() {
	SharedLock lock(&m_shared_data);
	for(unsigned int channel = 0; channel < 2; ++channel) {
		lock->m_current_low[channel] = 0.0;
		lock->m_current_high[channel] = 0.0;
		lock->m_next_low[channel] = std::numeric_limits<double>::max();
		lock->m_next_high[channel] = -std::numeric_limits<double>::max();
	}
	m_should_repaint = true;
}

void AudioPreviewer::SetFrameRate(unsigned int frame_rate) {
	SharedLock lock(&m_shared_data);
	lock->m_frame_rate = std::max(1u, frame_rate);
}

void AudioPreviewer::ReadSamples(const char* samples, size_t samplecount) {
	SharedLock lock(&m_shared_data);

	if(samplecount == 0)
		return;

	// save the samples
	int16_t *data_in = (int16_t*) samples;
	for(size_t i = 0; i < samplecount; ++i) {
		for(unsigned int channel = 0; channel < 2; ++channel) {
			double val = (double) *(data_in++) / 32768.0;
			if(val < lock->m_next_low[channel])
				lock->m_next_low[channel] = val;
			if(val > lock->m_next_high[channel])
				lock->m_next_high[channel] = val;
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

	m_should_repaint = true;

}

void AudioPreviewer::UpdateIfNeeded() {
	if(m_should_repaint) {
		update();
	}
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
		double val = log10(std::max(1.0e-3, (lock->m_current_high[channel] - lock->m_current_low[channel]) / 2.0)) / 3.0 + 1.0;
		painter.drawRect(0, h * channel / 2, (int) round((double) w * val), h * (channel + 1) / 2 - h * channel / 2);
	}

	painter.setPen(QColor(0, 0, 0));
	painter.setBrush(Qt::NoBrush);
	for(unsigned int channel = 0; channel < 2; ++channel) {
		painter.drawRect(0, h * channel / 2, w, h * (channel + 1) / 2 - h * channel / 2);
	}

	m_should_repaint = false;

}
