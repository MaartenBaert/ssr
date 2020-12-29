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

#include "SSRVideoStreamReader.h"

#include "Logger.h"

#include <fcntl.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

SSRVideoStreamReader::SSRVideoStreamReader(const std::string& channel, const SSRVideoStream& stream) {

	m_stream = stream;
	m_channel_directory = "/dev/shm/ssr-" + ((channel.empty())? "channel-" + GetUserName() : channel);
	m_filename_main = m_channel_directory + "/video-" + stream.m_stream_name;
	m_page_size = sysconf(_SC_PAGE_SIZE);

	m_fd_main = -1;
	m_mmap_ptr_main = MAP_FAILED;
	m_mmap_size_main = 0;

	for(unsigned int i = 0; i < GLINJECT_RING_BUFFER_SIZE; ++i) {
		FrameData &fd = m_frame_data[i];
		fd.m_filename_frame = m_channel_directory + "/videoframe" + NumToString(i) + "-" + stream.m_stream_name;
		fd.m_fd_frame = -1;
		fd.m_mmap_ptr_frame = MAP_FAILED;
		fd.m_mmap_size_frame = 0;
	}

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

SSRVideoStreamReader::~SSRVideoStreamReader() {
	Free();
}

void SSRVideoStreamReader::Init() {

	Logger::LogInfo("[SSRVideoStreamReader::Init] " + Logger::tr("Created video stream reader."));

	// open main file
	m_fd_main = open(m_filename_main.c_str(), O_RDWR | O_CLOEXEC);
	if(m_fd_main == -1) {
		Logger::LogError("[SSRVideoStreamReader::Init] " + Logger::tr("Error: Can't open video stream file!"));
		throw SSRStreamException();
	}

	// resize main file
	m_mmap_size_main = (sizeof(GLInjectHeader) + GLINJECT_RING_BUFFER_SIZE * sizeof(GLInjectFrameInfo) + m_page_size - 1) / m_page_size * m_page_size;
	if(ftruncate(m_fd_main, m_mmap_size_main) == -1) {
		Logger::LogError("[SSRVideoStreamReader::Init] " + Logger::tr("Error: Can't resize video stream file!"));
		throw SSRStreamException();
	}

	// map main file
	m_mmap_ptr_main = mmap(NULL, m_mmap_size_main, PROT_READ | PROT_WRITE, MAP_SHARED, m_fd_main, 0);
	if(m_mmap_ptr_main == MAP_FAILED) {
		Logger::LogError("[SSRVideoStreamReader::Init] " + Logger::tr("Error: Can't memory-map video stream file!"));
		throw SSRStreamException();
	}

	// open frame files
	for(unsigned int i = 0; i < GLINJECT_RING_BUFFER_SIZE; ++i) {
		FrameData &fd = m_frame_data[i];
		fd.m_fd_frame = open(fd.m_filename_frame.c_str(), O_RDWR | O_CLOEXEC);
		if(fd.m_fd_frame == -1) {
			Logger::LogError("[SSRVideoStreamReader::Init] " + Logger::tr("Error: Can't open video frame file!"));
			throw SSRStreamException();
		}
	}

	// initialize header
	GLInjectHeader *header = GetGLInjectHeader();
	header->capture_flags = 0;
	header->capture_target_fps = 0;
	std::atomic_thread_fence(std::memory_order_release);

	// initialize frame counter
	std::atomic_thread_fence(std::memory_order_acquire);
	m_fps_last_timestamp = hrt_time_micro();
	m_fps_last_counter = header->frame_counter;
	m_fps_current = 0.0;

}

void SSRVideoStreamReader::Free() {

	for(unsigned int i = 0; i < GLINJECT_RING_BUFFER_SIZE; ++i) {
		FrameData &fd = m_frame_data[i];

		// unmap frame file
		if(fd.m_mmap_ptr_frame != MAP_FAILED) {
			munmap(fd.m_mmap_ptr_frame, fd.m_mmap_size_frame);
			fd.m_mmap_ptr_frame = MAP_FAILED;
		}

		// close frame file
		if(fd.m_fd_frame != -1) {
			close(fd.m_fd_frame);
			fd.m_fd_frame = -1;
		}

	}

	// unmap main file
	if(m_mmap_ptr_main != MAP_FAILED) {
		munmap(m_mmap_ptr_main, m_mmap_size_main);
		m_mmap_ptr_main = MAP_FAILED;
	}

	// close main file
	if(m_fd_main != -1) {
		close(m_fd_main);
		m_fd_main = -1;
	}

	Logger::LogInfo("[SSRVideoStreamReader::Init] " + Logger::tr("Destroyed video stream reader."));

}

void SSRVideoStreamReader::GetCurrentSize(unsigned int* width, unsigned int* height) {
	GLInjectHeader *header = GetGLInjectHeader();
	std::atomic_thread_fence(std::memory_order_acquire);
	if(header->identifier != GLINJECT_IDENTIFIER) {
		*width = 0;
		*height = 0;
		return;
	}
	std::atomic_thread_fence(std::memory_order_acquire);
	*width = header->current_width;
	*height = header->current_height;
}

double SSRVideoStreamReader::GetFPS() {
	GLInjectHeader *header = GetGLInjectHeader();
	int64_t timestamp = hrt_time_micro();
	std::atomic_thread_fence(std::memory_order_acquire);
	uint32_t frame_counter = header->frame_counter;
	unsigned int time = timestamp - m_fps_last_timestamp;
	if(time > 500000) {
		unsigned int frames = frame_counter - m_fps_last_counter;
		m_fps_last_timestamp = timestamp;
		m_fps_last_counter = frame_counter;
		m_fps_current = (double) frames / ((double) time * 1.0e-6);
	}
	return m_fps_current;
}

void SSRVideoStreamReader::ChangeCaptureParameters(unsigned int flags, unsigned int target_fps) {
	GLInjectHeader *header = GetGLInjectHeader();
	header->capture_flags = flags;
	header->capture_target_fps = target_fps;
	std::atomic_thread_fence(std::memory_order_release);
}

void SSRVideoStreamReader::Clear() {
	GLInjectHeader *header = GetGLInjectHeader();
	std::atomic_thread_fence(std::memory_order_acquire);
	header->ring_buffer_read_pos = header->ring_buffer_write_pos;
	std::atomic_thread_fence(std::memory_order_release);
}

void* SSRVideoStreamReader::GetFrame(int64_t* timestamp, unsigned int* width, unsigned int* height, int* stride) {

	// make sure that the stream has been initialized
	GLInjectHeader *header = GetGLInjectHeader();
	std::atomic_thread_fence(std::memory_order_acquire);
	if(header->identifier != GLINJECT_IDENTIFIER)
		return NULL;

	// make sure that at least one frame is available
	std::atomic_thread_fence(std::memory_order_acquire);
	unsigned int read_pos = header->ring_buffer_read_pos;
	unsigned int write_pos = header->ring_buffer_write_pos;
	if(read_pos == write_pos)
		return NULL;

	// read frame info
	GLInjectFrameInfo *frameinfo = GetGLInjectFrameInfo(read_pos % GLINJECT_RING_BUFFER_SIZE);
	std::atomic_thread_fence(std::memory_order_acquire);
	*timestamp = frameinfo->timestamp;
	*width = frameinfo->width;
	*height = frameinfo->height;
	*stride = frameinfo->stride;

	// verify the size (should never happen unless someone is messing with the files)
	if(*width < 2 || *height < 2)
		return NULL;
	if(*width > SSR_MAX_IMAGE_SIZE || *height > SSR_MAX_IMAGE_SIZE)
		return NULL;
	if(abs(*stride) > SSR_MAX_IMAGE_SIZE * 4)
		return NULL;

	// read frame
	FrameData &fd = m_frame_data[read_pos % GLINJECT_RING_BUFFER_SIZE];
	size_t required_size = (size_t) abs(*stride) * (size_t) *height;
	if(required_size > fd.m_mmap_size_frame) {

		// calculate new size
		required_size = (required_size + m_page_size - 1) / m_page_size * m_page_size;

		// unmap frame file
		if(fd.m_mmap_ptr_frame != MAP_FAILED) {
			munmap(fd.m_mmap_ptr_frame, fd.m_mmap_size_frame);
			fd.m_mmap_ptr_frame = MAP_FAILED;
			fd.m_mmap_size_frame = 0;
		}

		// check frame file size
		{
			struct stat statinfo;
			if(fstat(fd.m_fd_frame, &statinfo) == -1 || (size_t) statinfo.st_size < required_size) {
				Logger::LogError("[SSRVideoStreamReader::GetFrame] " + Logger::tr("Error: Size of video frame file is incorrect!"));
				throw SSRStreamException();
			}
			required_size = statinfo.st_size / m_page_size * m_page_size;
		}

		// map frame file
		fd.m_mmap_ptr_frame = mmap(NULL, required_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd.m_fd_frame, 0);
		if(fd.m_mmap_ptr_frame == MAP_FAILED) {
			Logger::LogError("[SSRVideoStreamReader::GetFrame] " + Logger::tr("Error: Can't memory-map video frame file!"));
			throw SSRStreamException();
		}
		fd.m_mmap_size_frame = required_size;

	}

	return fd.m_mmap_ptr_frame;
}

void SSRVideoStreamReader::NextFrame() {

	// tell the compiler that it should read the entire frame before continuing
	// This is essentially a 'load-store' fence, which should be provided by both acquire and release fences,
	// but I'm not completely sure so let's use both just to be safe.
	std::atomic_thread_fence(std::memory_order_acq_rel);

	// go to the next frame
	GLInjectHeader *header = GetGLInjectHeader();
	header->ring_buffer_read_pos = (header->ring_buffer_read_pos + 1) % (GLINJECT_RING_BUFFER_SIZE * 2);
	std::atomic_thread_fence(std::memory_order_release);

}
