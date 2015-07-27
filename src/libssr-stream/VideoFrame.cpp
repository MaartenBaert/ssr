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

#include "VideoFrame.h"

#include "Common.h"

#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

VideoFrame::VideoFrame(uint32_t width, uint32_t height, int32_t stride, const std::shared_ptr<FileDescriptor>& fd) {

	m_width = width;
	m_height = height;
	m_stride = stride;
	m_fd = fd;

	m_mmap_data = (uint8_t*) MAP_FAILED;
	m_mmap_size = 0;

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

VideoFrame::~VideoFrame() {
	Free();
}

void VideoFrame::Init() {

	// calculate the required size
	size_t page_size = sysconf(_SC_PAGESIZE);
	m_mmap_size = (abs(m_stride) * m_height + page_size - 1) / page_size * page_size;

	// create the file if necessary, and check the size
	if(m_fd == NULL) {
		m_fd = std::make_shared<FileDescriptor>(CreateSharedMemoryFile());
		if(ftruncate(m_fd->Get(), m_mmap_size) == -1)
			throw std::runtime_error("Can't resize video frame file!");
	} else {
		struct stat statinfo;
		if(fstat(m_fd->Get(), &statinfo) == -1 || (size_t) statinfo.st_size != m_mmap_size)
			throw std::runtime_error("Video frame file size is incorrect!");
	}

	// map the file
	m_mmap_data = (uint8_t*) mmap(NULL, m_mmap_size, PROT_READ | PROT_WRITE, MAP_SHARED, m_fd->Get(), 0);
	if(m_mmap_data == MAP_FAILED)
		throw std::runtime_error("Can't memory-map video frame file!");

}

void VideoFrame::Free() {

	// unmap the file
	if(m_mmap_data != MAP_FAILED) {
		munmap(m_mmap_data, m_mmap_size);
		m_mmap_data = (uint8_t*) MAP_FAILED;
	}

}
