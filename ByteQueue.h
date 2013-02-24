#pragma once
#include "StdAfx.h"

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
