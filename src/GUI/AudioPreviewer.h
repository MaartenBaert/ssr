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

#include "VPair.h"
#include "ByteQueue.h"

class AudioPreviewer : public QWidget {

private:
	struct SharedData {
		double m_current_low[2], m_current_high[2];
		double m_next_low[2], m_next_high[2];
		int64_t m_next_frame_time;
		unsigned int m_frame_rate;
	};
	typedef VPair<SharedData>::Lock SharedLock;

private:
	VPair<SharedData> m_shared_data;
	volatile bool m_should_repaint;

public:
	AudioPreviewer(QWidget* parent);
	~AudioPreviewer();

	void Reset();
	void SetFrameRate(unsigned int frame_rate);
	void ReadSamples(const char* samples, size_t samplecount);
	void UpdateIfNeeded();

	virtual QSize minimumSizeHint() const { return QSize(100, 21); }
	virtual QSize sizeHint() const { return QSize(100, 21); }

protected:
	virtual void paintEvent(QPaintEvent* event);

};
