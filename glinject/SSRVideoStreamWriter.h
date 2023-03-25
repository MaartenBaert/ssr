/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#pragma once
#include "Global.h"

#include "ShmStructs.h"

class SSRVideoStreamWriter {

private:
	struct FrameData {
		std::string m_filename_frame;
		int m_fd_frame;
		void *m_mmap_ptr_frame;
		size_t m_mmap_size_frame;
	};

private:
	std::string m_channel_directory, m_filename_main;
	size_t m_page_size;
	unsigned int m_width, m_height;
	int m_stride;

	int64_t m_next_frame_time;

	int m_fd_main, m_file_lock;
	void *m_mmap_ptr_main;
	size_t m_mmap_size_main;

	FrameData m_frame_data[GLINJECT_RING_BUFFER_SIZE];

public:
	SSRVideoStreamWriter(const std::string& channel, const std::string& source);
	~SSRVideoStreamWriter();

private:
	void Init();
	void Free();

	GLInjectHeader* GetGLInjectHeader();
	GLInjectFrameInfo* GetGLInjectFrameInfo(unsigned int frame);

public:
	// Updates the size of the video stream.
	void UpdateSize(unsigned int width, unsigned int height, int stride);

	// Should be called for every new frame. It will determine whether the frame should be captured.
	// If it should be captured, it will allocate shared memory for the frame and return a pointer. Otherwise it returns NULL.
	void* NewFrame(unsigned int* flags);

	// Writes the allocated frame to the ring buffer after it has been captured.
	void NextFrame();

};
