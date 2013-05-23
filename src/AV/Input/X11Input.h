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
#include "YUVConverter.h"

class Synchronizer;
class VideoPreviewer;

class X11Input : private QThread {
	Q_OBJECT

private:
	struct SharedData {
		QRect m_screen_bbox;
		QVector<QRect> m_screen_dead_space;
		VideoPreviewer *m_video_previewer;
	};
	typedef VPair<SharedData>::Lock SharedLock;

private:
	Synchronizer *m_synchronizer;

	unsigned int m_x, m_y, m_width, m_height;
	unsigned int m_frame_rate, m_out_width, m_out_height;
	bool m_record_cursor, m_follow_cursor;

	Display *m_x11_display;
	int m_x11_screen;
	Qt::HANDLE m_x11_root;
	Visual *m_x11_visual;
	int m_x11_depth;
	bool m_x11_use_shm;
	XShmSegmentInfo m_x11_shm_info;
	bool m_x11_shm_server_attached;
	XImage *m_x11_image;
	PixelFormat m_x11_image_format;

	bool m_warn_swscale;
	YUVConverter m_yuv_converter;
	SwsContext *m_sws_context;

	VPair<SharedData> m_shared_data;
	volatile bool m_should_stop, m_error_occurred;

public:
	X11Input(Synchronizer* synchronizer, unsigned int x, unsigned int y, unsigned int width, unsigned int height, bool record_cursor, bool follow_cursor);
	~X11Input();

	// Connect the video previewer.
	// video_previewer can be NULL.
	void ConnectVideoPreviewer(VideoPreviewer* video_previewer);

	// Returns whether an error has occurred in the input thread.
	// This function is thread-safe.
	inline bool HasErrorOccurred() { return m_error_occurred; }

private:
	void Init();
	void Free();

private slots:
	void UpdateScreenConfiguration();

private:
	virtual void run();

};
