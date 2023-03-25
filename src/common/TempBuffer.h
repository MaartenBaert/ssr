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

// This is a simple class that allocates temporary buffers efficiently by reusing memory to avoid new memory allocations.
// It is more efficient than std::vector because it doesn't copy data or initialize it to zero.
// The amount of allocated memory will only grow, not shrink (i.e. like std::vector).
// The 'GetSize' function will always report the actual size, which can be larger than the requested size.

#define TEMPBUFFER_ALIGN 16

template<typename T>
class TempBuffer {

private:
	T *m_data;
	size_t m_size;

public:
	inline TempBuffer() {
		m_data = NULL;
		m_size = 0;
	}
	inline ~TempBuffer() {
		free(m_data);
	}
	inline void Alloc(size_t size, bool copy = false) {
		if(size > m_size) {
			if(m_size != 0)
				size += size / 4;
			void *temp;
			if(posix_memalign(&temp, TEMPBUFFER_ALIGN, sizeof(T) * size) != 0)
				throw std::bad_alloc();
			if(copy)
				memcpy(temp, m_data, sizeof(T) * m_size);
			free(m_data);
			m_data = (T*) temp;
			m_size = size;
		}
	}

public:
	inline T* GetData() { return m_data; }
	inline size_t GetSize() { return m_size; }
	inline T& operator[](size_t i) { return m_data[i]; }

	// noncopyable
	TempBuffer(const TempBuffer&) = delete;
	TempBuffer& operator=(const TempBuffer&) = delete;

};
