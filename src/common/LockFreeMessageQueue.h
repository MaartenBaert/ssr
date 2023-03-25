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

inline bool IncreaseWritePos(unsigned int r, unsigned int& w, unsigned int inc, unsigned int buffer_size) {
	if(w + inc > buffer_size) {
		if(r > w || r <= inc)
			return false;
		w = inc;
	} else {
		if(r > w && r <= w + inc)
			return false;
		w += inc;
	}
	return true;
}
inline bool IncreaseReadPos(unsigned int& r, unsigned int w, unsigned int inc, unsigned int buffer_size) {
	if(r + inc > buffer_size) {
		if(w >= r || w < inc)
			return false;
		r = inc;
	} else {
		if(w >= r && w < r + inc)
			return false;
		r += inc;
	}
	return true;
}

class LockFreeMessageQueue {

private:
	char *m_buffer;
	unsigned int m_buffer_size, m_read_pos, m_write_pos, m_read_pos_next, m_write_pos_next;

public:
	inline LockFreeMessageQueue() {
		m_buffer = NULL;
		m_buffer_size = 0;
		m_read_pos = 0;
		m_write_pos = 0;
	}
	inline ~LockFreeMessageQueue() {
		free(m_buffer);
	}
	inline void Reset(unsigned int size) {
		free(m_buffer);
		m_buffer_size = 0;
		m_read_pos = 0;
		m_write_pos = 0;
		m_buffer = (char*) malloc(size);
		if(m_buffer == NULL)
			throw std::bad_alloc();
		m_buffer_size = size;
	}

	inline char* PrepareWriteMessage(unsigned int size) {
		std::atomic_thread_fence(std::memory_order_acquire);
		unsigned int r = m_read_pos, w = m_write_pos;
		//fprintf(stderr, "PrepareWriteMessage (1) r=%10u w=%10u\n", r, w);
		if(!IncreaseWritePos(r, w, sizeof(unsigned int), m_buffer_size))
			return NULL;
		//fprintf(stderr, "PrepareWriteMessage (2) r=%10u w=%10u\n", r, w);
		*((unsigned int*) (m_buffer + w - sizeof(unsigned int))) = size;
		if(!IncreaseWritePos(r, w, size, m_buffer_size))
			return NULL;
		//fprintf(stderr, "PrepareWriteMessage (3) r=%10u w=%10u\n", r, w);
		m_write_pos_next = w;
		return m_buffer + w - size;
	}
	inline void WriteMessage() {
		std::atomic_thread_fence(std::memory_order_release);
		m_write_pos = m_write_pos_next;
		std::atomic_thread_fence(std::memory_order_release);
	}

	inline char* PrepareReadMessage(unsigned int* size) {
		std::atomic_thread_fence(std::memory_order_acquire);
		unsigned int r = m_read_pos, w = m_write_pos;
		//fprintf(stderr, "PrepareReadMessage (1) r=%10u w=%10u\n", r, w);
		if(!IncreaseReadPos(r, w, sizeof(unsigned int), m_buffer_size))
			return NULL;
		//fprintf(stderr, "PrepareReadMessage (2) r=%10u w=%10u\n", r, w);
		std::atomic_thread_fence(std::memory_order_acquire);
		*size = *((unsigned int*) (m_buffer + r - sizeof(unsigned int)));
		if(!IncreaseReadPos(r, w, *size, m_buffer_size))
			assert(false);
		//fprintf(stderr, "PrepareReadMessage (3) r=%10u w=%10u\n", r, w);
		m_read_pos_next = r;
		return m_buffer + r - *size;
	}
	inline void ReadMessage() {
		std::atomic_thread_fence(std::memory_order_acq_rel);
		m_read_pos = m_read_pos_next;
		std::atomic_thread_fence(std::memory_order_release);
	}

};
