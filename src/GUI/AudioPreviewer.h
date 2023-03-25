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

#pragma once
#include "Global.h"

#include "SampleCast.h"
#include "SourceSink.h"
#include "MutexDataPair.h"

class AudioPreviewer : public QWidget, public AudioSink {
	Q_OBJECT

private:
	struct ChannelData {
		float m_current_peak, m_current_rms;
		float m_next_peak, m_next_rms;
		inline ChannelData() { m_current_peak = m_current_rms = m_next_peak = m_next_rms = 0.0f; }
		template<typename IN>
		inline void Analyze(IN sample) {
			float val = fabs(SampleCast<IN, float>(sample));
			m_next_peak = fmax(m_next_peak, val);
			m_next_rms += val * val;
		}
	};
	struct SharedData {
		std::vector<ChannelData> m_channel_data;
		unsigned int m_next_samples;
		int64_t m_next_frame_time;
		unsigned int m_frame_rate;
	};
	typedef MutexDataPair<SharedData>::Lock SharedLock;

private:
	MutexDataPair<SharedData> m_shared_data;

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
	virtual void ReadAudioSamples(unsigned int channels, unsigned int sample_rate, AVSampleFormat format, unsigned int sample_count, const uint8_t* data, int64_t timestamp) override;

	virtual QSize minimumSizeHint() const override { return QSize(100, 21); }
	virtual QSize sizeHint() const override { return QSize(100, 21); }

protected:
	virtual void paintEvent(QPaintEvent* event) override;

signals:
	void NeedsUpdate();

};
