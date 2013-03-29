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

#include "StdAfx.h"
#include "ByteQueue.h"

const size_t ByteQueue::MIN_BLOCK_SIZE = 1024 * 10;

ByteQueue::ByteQueue() {
	m_unused_front = 0;
	m_unused_back = 0;
	m_total_size = 0;
}

ByteQueue::~ByteQueue() {
	Clear();
}

void ByteQueue::Clear() {
	for(auto it = m_queue.begin(); it != m_queue.end(); ++it) {
		free(it->m_data);
	}
	m_queue.clear();
	m_unused_front = 0;
	m_unused_back = 0;
	m_total_size = 0;
}

void ByteQueue::Write(const char* data, size_t size) {
	while(size > 0) {
		if(m_unused_back == 0) {
			size_t blocksize = (size_t) (MIN_BLOCK_SIZE + (GetSize() + size) / 8) & ~((size_t) 15);
			char *blockdata = (char*) malloc(blocksize);
			if(blockdata == NULL)
				throw std::bad_alloc();
			try {
				m_queue.push_back(Block(blockdata, blocksize));
				m_unused_back += blocksize;
				m_total_size += blocksize;
			} catch(...) {
				free(blockdata);
				throw;
			}
		}
		Block &b = m_queue.back();
		size_t n = std::min(m_unused_back, size);
		memcpy(b.m_data + b.m_size - m_unused_back, data, n);
		data += n;
		size -= n;
		m_unused_back -= n;
	}
}

void ByteQueue::Read(char* data, size_t size) {
	Q_ASSERT(GetSize() >= size);
	while(size > 0) {
		Block &b = m_queue.front();
		size_t n = std::min(b.m_size - m_unused_front, size);
		memcpy(data, b.m_data + m_unused_front, n);
		data += n;
		size -= n;
		m_unused_front += n;
		if(m_unused_front == b.m_size) {
			m_unused_front = 0;
			m_total_size -= b.m_size;
			free(b.m_data);
			m_queue.pop_front();
		}
	}
}

void ByteQueue::Drop(size_t size) {
	Q_ASSERT(GetSize() >= size);
	while(size > 0) {
		Block &b = m_queue.front();
		size_t n = std::min(b.m_size - m_unused_front, size);
		size -= n;
		m_unused_front += n;
		if(m_unused_front == b.m_size) {
			m_unused_front = 0;
			m_total_size -= b.m_size;
			free(b.m_data);
			m_queue.pop_front();
		}
	}
}
