/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "SSRVideoStreamWriter.h"

#include <fcntl.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

// Returns the program name (i.e. filename of the binary)
static std::string GetProgramName() {
	std::vector<char> temp(10000);
	ssize_t size = readlink("/proc/self/exe", temp.data(), temp.size());
	if(size < 0)
		return std::string();
	std::string path(temp.data(), size);
	size_t p = path.find_last_of('/');
	if(p == std::string::npos)
		return path;
	return path.substr(p + 1);
}

SSRVideoStreamWriter::SSRVideoStreamWriter(const std::string& channel, const std::string& source) {

	std::string stream_name = NumToString(hrt_time_micro()) + "-" + NumToString(getpid()) + "-" + source + "-" + GetProgramName();

	m_channel_directory = "/dev/shm/ssr-" + ((channel.empty())? "channel-" + GetUserName() : channel);
	m_filename_main = m_channel_directory + "/video-" + stream_name;
	m_page_size = sysconf(_SC_PAGE_SIZE);
	m_width = 0;
	m_height = 0;
	m_stride = 0;
	m_next_frame_time = hrt_time_micro();

	m_fd_main = -1;
	m_mmap_ptr_main = MAP_FAILED;
	m_mmap_size_main = 0;

	for(unsigned int i = 0; i < GLINJECT_RING_BUFFER_SIZE; ++i) {
		FrameData &fd = m_frame_data[i];
		fd.m_filename_frame = m_channel_directory + "/videoframe" + NumToString(i) + "-" + stream_name;
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

SSRVideoStreamWriter::~SSRVideoStreamWriter() {
	Free();
}

void SSRVideoStreamWriter::Init() {

	GLINJECT_PRINT("[" << m_filename_main << "] Created video stream.");

	bool relax_permissions = false;
	{
		char *ssr_stream_relax_permissions = getenv("SSR_STREAM_RELAX_PERMISSIONS");
		if(ssr_stream_relax_permissions != NULL && atoi(ssr_stream_relax_permissions) > 0) {
			GLINJECT_PRINT("Warning: Using relaxed file permissions, any user on this machine will be able to read or manipulate the stream!");
			relax_permissions = true;
		}
	}

	// create channel directory (permissions may be wrong because of umask, fix this later)
	if(mkdir(m_channel_directory.c_str(), (relax_permissions)? 0777 : 0700) == -1) {
		if(errno != EEXIST) { // does the directory already exist?
			GLINJECT_PRINT("Error: Can't create channel directory!");
			throw SSRStreamException();
		}
	}

	// check ownership and permissions
	struct stat statinfo;
	if(lstat(m_channel_directory.c_str(), &statinfo) == -1) {
		GLINJECT_PRINT("Error: Can't stat channel directory!");
		throw SSRStreamException();
	}
	if(!S_ISDIR(statinfo.st_mode) || S_ISLNK(statinfo.st_mode)) {
		GLINJECT_PRINT("Error: Channel directory is not a regular directory!");
		throw SSRStreamException();
	}
	if(statinfo.st_uid == geteuid()) {
		if(chmod(m_channel_directory.c_str(), (relax_permissions)? 0777 : 0700) == -1) {
			GLINJECT_PRINT("Error: Can't set channel directory mode!");
			throw SSRStreamException();
		}
	} else {
		if(!relax_permissions) {
			GLINJECT_PRINT("Error: Channel directory is owned by a different user! "
							"Choose a different channel name, or enable relaxed file permissions to use it anyway.");
			throw SSRStreamException();
		}
	}

	// open frame files
	for(unsigned int i = 0; i < GLINJECT_RING_BUFFER_SIZE; ++i) {
		FrameData &fd = m_frame_data[i];
		fd.m_fd_frame = open(fd.m_filename_frame.c_str(), O_RDWR | O_CREAT | O_EXCL | O_CLOEXEC, (relax_permissions)? 0666 : 0600);
		if(fd.m_fd_frame == -1) {
			GLINJECT_PRINT("Error: Can't open video frame file!");
			throw SSRStreamException();
		}
		if(fchmod(fd.m_fd_frame, (relax_permissions)? 0666 : 0600) == -1) {
			GLINJECT_PRINT("Error: Can't set video frame file mode!");
			throw SSRStreamException();
		}
	}

	// open main file
	m_fd_main = open(m_filename_main.c_str(), O_RDWR | O_CREAT | O_EXCL | O_CLOEXEC, (relax_permissions)? 0666 : 0600);
	if(m_fd_main == -1) {
		GLINJECT_PRINT("Error: Can't open video stream file!");
		throw SSRStreamException();
	}
	if(fchmod(m_fd_main, (relax_permissions)? 0666 : 0600) == -1) {
			GLINJECT_PRINT("Error: Can't set video stream file mode!");
		throw SSRStreamException();
	}

	// resize main file
	m_mmap_size_main = (sizeof(GLInjectHeader) + GLINJECT_RING_BUFFER_SIZE * sizeof(GLInjectFrameInfo) + m_page_size - 1) / m_page_size * m_page_size;
	if(ftruncate(m_fd_main, m_mmap_size_main) == -1) {
		GLINJECT_PRINT("Error: Can't resize video stream file!");
		throw SSRStreamException();
	}

	// map main file
	m_mmap_ptr_main = mmap(NULL, m_mmap_size_main, PROT_READ | PROT_WRITE, MAP_SHARED, m_fd_main, 0);
	if(m_mmap_ptr_main == MAP_FAILED) {
		GLINJECT_PRINT("Error: Can't memory-map video stream file!");
		throw SSRStreamException();
	}

	// initialize header
	GLInjectHeader *header = GetGLInjectHeader();
	header->identifier = 0; // will be set later
	header->ring_buffer_read_pos = 0;
	header->ring_buffer_write_pos = 0;
	header->current_width = m_width;
	header->current_height = m_height;
	header->frame_counter = 0;

	// initialize frame info
	for(unsigned int i = 0; i < GLINJECT_RING_BUFFER_SIZE; ++i) {
		GLInjectFrameInfo *frameinfo = GetGLInjectFrameInfo(i);
		frameinfo->timestamp = 0;
		frameinfo->width = 0;
		frameinfo->height = 0;
		frameinfo->stride = 0;
	}

	// set the identifier to indicate that initialization is complete
	std::atomic_thread_fence(std::memory_order_release);
	header->identifier = GLINJECT_IDENTIFIER;
	std::atomic_thread_fence(std::memory_order_release);

}

void SSRVideoStreamWriter::Free() {

	for(unsigned int i = 0; i < GLINJECT_RING_BUFFER_SIZE; ++i) {
		FrameData &fd = m_frame_data[i];

		// unmap frame file
		if(fd.m_mmap_ptr_frame != MAP_FAILED) {
			munmap(fd.m_mmap_ptr_frame, fd.m_mmap_size_frame);
			fd.m_mmap_ptr_frame = MAP_FAILED;
		}

		// close and unlink frame file
		if(fd.m_fd_frame != -1) {
			close(fd.m_fd_frame);
			fd.m_fd_frame = -1;
			unlink(fd.m_filename_frame.c_str());
		}

	}

	// unmap main file
	if(m_mmap_ptr_main != MAP_FAILED) {
		munmap(m_mmap_ptr_main, m_mmap_size_main);
		m_mmap_ptr_main = MAP_FAILED;
	}

	// close and unlink main file
	if(m_fd_main != -1) {
		close(m_fd_main);
		m_fd_main = -1;
		unlink(m_filename_main.c_str());
	}

	GLINJECT_PRINT("[" << m_filename_main << "] Destroyed video stream.");

}

GLInjectHeader* SSRVideoStreamWriter::GetGLInjectHeader() {
	return (GLInjectHeader*) m_mmap_ptr_main;
}

GLInjectFrameInfo* SSRVideoStreamWriter::GetGLInjectFrameInfo(unsigned int frame) {
	return (GLInjectFrameInfo*) ((char*) m_mmap_ptr_main + sizeof(GLInjectHeader) + frame * sizeof(GLInjectFrameInfo));
}

void SSRVideoStreamWriter::UpdateSize(unsigned int width, unsigned int height, int stride) {
	if(m_width != width || m_height != height) {
		GLINJECT_PRINT("[" << m_filename_main << "] frame size = " << width << "x" << height << ".");
		m_width = width;
		m_height = height;
		GLInjectHeader *header = GetGLInjectHeader();
		header->current_width = m_width;
		header->current_height = m_height;
		std::atomic_thread_fence(std::memory_order_release);
	}
	m_stride = stride;
}

void* SSRVideoStreamWriter::NewFrame(unsigned int* flags) {

	// increment the frame counter
	GLInjectHeader *header = GetGLInjectHeader();
	++header->frame_counter;
	std::atomic_thread_fence(std::memory_order_release);

	// get capture parameters
	std::atomic_thread_fence(std::memory_order_acquire);
	*flags = header->capture_flags;
	if(!(*flags & GLINJECT_FLAG_CAPTURE_ENABLED))
		return NULL;

	// check the timestamp and maybe limit the fps
	unsigned int target_fps = header->capture_target_fps;
	int64_t timestamp = hrt_time_micro();
	if(target_fps > 0) {
		int64_t interval = 1000000 / target_fps;
		if(*flags & GLINJECT_FLAG_LIMIT_FPS) {
			if(timestamp < m_next_frame_time) {
				usleep(m_next_frame_time - timestamp);
				timestamp = hrt_time_micro();
			}
		} else {
			if(timestamp < m_next_frame_time - interval)
				return NULL;
		}
		m_next_frame_time = std::max(m_next_frame_time + interval, timestamp);
	}

	// make sure that at least one frame is available
	unsigned int read_pos = header->ring_buffer_read_pos;
	unsigned int write_pos = header->ring_buffer_write_pos;
	unsigned int frames_used = positive_mod((int) write_pos - (int) read_pos, GLINJECT_RING_BUFFER_SIZE * 2);
	if(frames_used >= GLINJECT_RING_BUFFER_SIZE)
		return NULL;

	// write frame info
	GLInjectFrameInfo *frameinfo = GetGLInjectFrameInfo(write_pos % GLINJECT_RING_BUFFER_SIZE);
	frameinfo->timestamp = timestamp;
	frameinfo->width = m_width;
	frameinfo->height = m_height;
	frameinfo->stride = m_stride;

	// prepare the frame file
	FrameData &fd = m_frame_data[write_pos % GLINJECT_RING_BUFFER_SIZE];
	size_t required_size = (size_t) abs(m_stride) * (size_t) m_height;
	if(required_size > fd.m_mmap_size_frame) {

		// calculate new size
		required_size = (required_size + required_size / 4 + m_page_size - 1) / m_page_size * m_page_size;

		// unmap frame file
		if(fd.m_mmap_ptr_frame != MAP_FAILED) {
			munmap(fd.m_mmap_ptr_frame, fd.m_mmap_size_frame);
			fd.m_mmap_ptr_frame = MAP_FAILED;
			fd.m_mmap_size_frame = 0;
		}

		// resize frame file
		if(ftruncate(fd.m_fd_frame, required_size) == -1) {
			GLINJECT_PRINT("Error: Can't resize video frame file!");
			throw SSRStreamException();
		}

		// map frame file
		fd.m_mmap_ptr_frame = mmap(NULL, required_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd.m_fd_frame, 0);
		if(fd.m_mmap_ptr_frame == MAP_FAILED) {
			GLINJECT_PRINT("Error: Can't memory-map video frame file!");
			throw SSRStreamException();
		}
		fd.m_mmap_size_frame = required_size;

	}

	return fd.m_mmap_ptr_frame;
}

void SSRVideoStreamWriter::NextFrame() {

	// make sure all changes are visible
	std::atomic_thread_fence(std::memory_order_release);

	// go to the next frame
	GLInjectHeader *header = GetGLInjectHeader();
	header->ring_buffer_write_pos = (header->ring_buffer_write_pos + 1) % (GLINJECT_RING_BUFFER_SIZE * 2);
	std::atomic_thread_fence(std::memory_order_release);

}
