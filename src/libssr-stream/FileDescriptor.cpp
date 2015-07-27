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

#include "FileDescriptor.h"

#include "Common.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

FileDescriptor::FileDescriptor() {
	m_fd = -1;
}

FileDescriptor::FileDescriptor(FileDescriptor&& other) {
	m_fd = other.m_fd;
	other.m_fd = -1;
}

FileDescriptor::FileDescriptor(int fd) {
	m_fd = fd;
}

FileDescriptor::~FileDescriptor() {
	if(m_fd != -1) {
		close(m_fd);
	}
}

FileDescriptor& FileDescriptor::operator=(FileDescriptor&& other) {
	if(m_fd != -1) {
		close(m_fd);
	}
	m_fd = other.m_fd;
	other.m_fd = -1;
	return *this;
}

int FileDescriptor::Get() {
	return m_fd;
}

void FileDescriptor::Reset(int fd) {
	if(m_fd != -1) {
		close(m_fd);
	}
	m_fd = fd;
}

int FileDescriptor::Release() {
	int fd = m_fd;
	if(m_fd != -1) {
		close(m_fd);
		m_fd = -1;
	}
	return fd;
}

FileDescriptor CreateSharedMemoryFile() {
	const char *hextable = "0123456789abcdef";
	char filename[] = "/dev/shm/ssrstream-################";
	for( ; ; ) {
		uint64_t num = RandomUInt64();
		for(uint32_t i = 0; i < 16; ++i) {
			filename[sizeof(filename) - 2 - i] = hextable[(num >> (4 * i)) & 0xf];
		}
		FileDescriptor fd(open(filename, O_RDWR | O_CREAT | O_EXCL | O_CLOEXEC, 0600));
		if(fd.Get() == -1) {
			if(errno != EEXIST)
				throw std::runtime_error("Can't create shared memory file! Reason: " + ErrorString());
		} else {
			unlink(filename);
			return fd;
		}
	}
}
