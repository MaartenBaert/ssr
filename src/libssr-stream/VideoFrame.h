/*
Copyright (c) 2012-2015 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose
with or without fee is hereby granted, provided that the above copyright notice
and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
THIS SOFTWARE.
*/

#pragma once

#include "FileDescriptor.h"

#include <memory>

class VideoFrame {

private:
	uint32_t m_width, m_height;
	int32_t m_stride;
	std::shared_ptr<FileDescriptor> m_fd;

	uint8_t *m_mmap_data;
	size_t m_mmap_size;

public:
	// Create a new video frame.
	// If the file descriptor is NULL, then a new shared memory file is created. Otherwise the given file descriptor is used.
	// If the file descriptor is not used by anything except this object, then it is deleted when this object is destroyed.
	VideoFrame(uint32_t width, uint32_t height, int32_t stride, const std::shared_ptr<FileDescriptor>& fd = NULL);

	// Destroy the video frame.
	// This unmaps the shared memory file.
	// If the file descriptor is not used by anything except this object, then it is closed as well.
	~VideoFrame();

private:
	void Init();
	void Free();

public:
	// Returns the width of the frame.
	inline uint32_t GetWidth() {
		return m_width;
	}

	// Returns the height of the frame.
	inline uint32_t GetHeight() {
		return m_height;
	}

	// Returns the stride (bytes per row) of the frame.
	// A negative number indicates that the frame is stored upside-down (common for OpenGL).
	int32_t GetStride() { return m_stride; }

	// Returns the file descriptor object linked to this frame.
	const std::shared_ptr<FileDescriptor>& GetFD() { return m_fd; }

	// Returns a pointer to the frame data.
	uint8_t* GetData() { return m_mmap_data; }

	// noncopyable
	VideoFrame(const VideoFrame&) = delete;
	VideoFrame& operator=(const VideoFrame&) = delete;

};
