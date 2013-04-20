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
#include "StdAfx.h"

#include "VPair.h"

class VideoPreviewer : public QWidget {

private:
	struct SharedData {
		QImage m_image;
		int64_t m_next_frame_time;
		QSize m_size;
		unsigned int m_frame_rate;
	};
	typedef VPair<SharedData>::Lock SharedLock;

private:
	SwsContext *m_sws_context;

	VPair<SharedData> m_shared_data;
	volatile bool m_should_repaint;

public:
	VideoPreviewer(QWidget* parent);
	~VideoPreviewer();

	void Reset();
	void SetFrameRate(unsigned int frame_rate);
	void ReadFrame(unsigned int width, unsigned int height, uint8_t* in_data, int in_stride, AVPixelFormat format);
	void CheckFrame();

	virtual QSize minimumSizeHint() const { return QSize(100, 100); }
	virtual QSize sizeHint() const { return QSize(100, 100); }

protected:
	virtual void resizeEvent(QResizeEvent* event);
	virtual void paintEvent(QPaintEvent* event);

};
