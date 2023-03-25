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

#include "SourceSink.h"
#include "MutexDataPair.h"
#include "FastScaler.h"
#include "TempBuffer.h"

class VideoPreviewer : public QWidget, public VideoSink {
	Q_OBJECT

private:
	struct SharedData {

		// current image
		std::shared_ptr<TempBuffer<uint8_t> > m_image_buffer;
		int m_image_stride;
		QSize m_image_size;

		// frame rate control
		unsigned int m_frame_rate;
		int64_t m_next_frame_time;

		// widget properties
		bool m_is_visible;
		QSize m_source_size, m_widget_size;

	};
	typedef MutexDataPair<SharedData>::Lock SharedLock;

private:
	FastScaler m_fast_scaler;

	MutexDataPair<SharedData> m_shared_data;

public:
	VideoPreviewer(QWidget* parent);
	~VideoPreviewer();

	// Resets the preview.
	// This function is thread-safe.
	void Reset();

	// Changes the preview frame rate.
	// This function is thread-safe.
	void SetFrameRate(unsigned int frame_rate);

	// Returns the preferred next video timestamp.
	// This function is thread-safe.
	virtual int64_t GetNextVideoTimestamp() override;

	// Reads a video frame from the video source.
	// This function is thread-safe.
	virtual void ReadVideoFrame(unsigned int width, unsigned int height, const uint8_t* data, int stride, AVPixelFormat format, int colorspace, int64_t timestamp) override;

	virtual QSize sizeHint() const override { return QSize(100, 100); }

protected:
	virtual void showEvent(QShowEvent* event) override;
	virtual void hideEvent(QHideEvent* event) override;
	virtual void resizeEvent(QResizeEvent* event) override;
	virtual void paintEvent(QPaintEvent* event) override;

signals:
	void NeedsUpdate();

};
