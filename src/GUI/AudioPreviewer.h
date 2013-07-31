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

#pragma once
#include "Global.h"

#include "SourceSink.h"
#include "VPair.h"

class AudioPreviewer : public QWidget, public AudioSink {
	Q_OBJECT

private:
	struct SharedData {
		double m_current_low[2], m_current_high[2];
		double m_next_low[2], m_next_high[2];
		int64_t m_next_frame_time;
		bool m_is_visible;
		unsigned int m_frame_rate;
	};
	typedef VPair<SharedData>::Lock SharedLock;

private:
	VPair<SharedData> m_shared_data;

public:
	AudioPreviewer(QWidget* parent);
	~AudioPreviewer();

	// Resets the preview.
	// This function is thread-safe.
	void Reset();

	// Changes the preview frame rate.
	// This function is thread-safe.
	void SetFrameRate(unsigned int frame_rate);

	// Reads audio samples from the audio source.
	// This function is thread-safe.
	virtual void ReadAudioSamples(unsigned int sample_rate, unsigned int channels, unsigned int sample_count, const uint8_t* data, AVSampleFormat format, int64_t timestamp) override;

	virtual QSize minimumSizeHint() const override { return QSize(100, 17); }
	virtual QSize sizeHint() const override { return QSize(100, 17); }

protected:
	virtual void showEvent(QShowEvent* event) override;
	virtual void hideEvent(QHideEvent* event) override;
	virtual void paintEvent(QPaintEvent* event) override;

signals:
	void NeedsUpdate();

};
