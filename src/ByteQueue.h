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

// A simple byte queue optimized for reading and writing blocks of bytes at once.
class ByteQueue {

private:
	struct Block {
		char *m_data;
		size_t m_size;
		inline Block(char* data, size_t size) : m_data(data), m_size(size) {}
	};

private:
	static const size_t MIN_BLOCK_SIZE;

private:
	std::deque<Block> m_queue;
	size_t m_unused_front, m_unused_back, m_total_size;

public:
	ByteQueue();
	ByteQueue(const ByteQueue& other) = delete;
	~ByteQueue();

	ByteQueue& operator=(const ByteQueue& other) = delete;

	void Clear();
	void Write(const char* data, size_t size);
	void Read(char* data, size_t size);
	void Drop(size_t size);

public:
	inline size_t GetSize() { return m_total_size - m_unused_front - m_unused_back; }

};
