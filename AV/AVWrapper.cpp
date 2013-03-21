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
#include "AVWrapper.h"

int lock_manager(void** m, AVLockOp op) {
	QMutex *&mutex = *(QMutex**) m;
	switch(op) {
		case AV_LOCK_CREATE: mutex = new QMutex(); break;
		case AV_LOCK_DESTROY: delete mutex; break;
		case AV_LOCK_OBTAIN: mutex->lock(); break;
		case AV_LOCK_RELEASE: mutex->unlock(); break;
	}
	return 0;
}

class AVGlobal {
public:
	AVGlobal() {
		av_register_all();
		av_lockmgr_register(&lock_manager);
	}
} g_av_global;

AVFrameWrapper::AVFrameWrapper() {
	m_free_on_destruct = true;
	avcodec_get_frame_defaults(this);
}

AVFrameWrapper::AVFrameWrapper(size_t size) {
	m_free_on_destruct = true;
	avcodec_get_frame_defaults(this);
	data[0] = (uint8_t*) av_malloc(size);
	if(data[0] == NULL) {
		throw std::bad_alloc();
	}
}

AVFrameWrapper::~AVFrameWrapper() {
	if(m_free_on_destruct)
		av_free(data[0]);
}

AVPacketWrapper::AVPacketWrapper() {
	m_free_on_destruct = true;
	av_init_packet(this);
	data = NULL;
	size = 0;
}

AVPacketWrapper::AVPacketWrapper(size_t size) {
	m_free_on_destruct = true;
	if(av_new_packet(this, size) != 0) {
		throw std::bad_alloc();
	}
}

AVPacketWrapper::~AVPacketWrapper() {
	if(m_free_on_destruct)
		av_free_packet(this);
}

