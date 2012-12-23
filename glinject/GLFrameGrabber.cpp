/*
Copyright (c) 2012 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "StdAfx.h"
#include "GLFrameGrabber.h"

// Explicit padding is needed here to keep the 32-bit and 64-bit code compatible.
// I could also disable padding of course, but this is easier :)
struct GLInjectHeader {
	uint32_t cbuffer_size, max_pixels;
	uint32_t read_pos, write_pos;
	uint32_t current_width, current_height;
};
struct GLInjectFrameInfo {
	int32_t shm_id, padding1;
	int64_t timestamp;
	uint32_t width, height;
};

GLFrameGrabber::GLFrameGrabber(Display* display, Window window, GLXDrawable drawable) {

	m_x11_display = display;
	m_x11_window = window;
	m_glx_drawable = drawable;
	m_width = 0;
	m_height = 0;

	m_shm_main_ptr = (char*) -1;

	m_warn_max_pixels = true;

	fprintf(stderr, "[SSR-GLInject] GLFrameGrabber for [%p-0x%lx-0x%lx] created.\n", m_x11_display, m_x11_window, m_glx_drawable);

	const char *id_str = getenv("SSR_GLINJECT_SHM");
	if(id_str == NULL) {
		fprintf(stderr, "[SSR-GLInject] Error: Shared memory id is missing!\n");
		exit(-181818181);
	}
	
	// get main shared memory
	int shm_main_id = atoi(id_str);
	m_shm_main_ptr = (char*) shmat(shm_main_id, NULL, SHM_RND);
	if(m_shm_main_ptr == (char*) -1) {
		fprintf(stderr, "[SSR-GLInject] Error: Can't attach to main shared memory (id = %d)!\n", shm_main_id);
		exit(-181818181);
	}
	GLInjectHeader header = *(GLInjectHeader*) m_shm_main_ptr;
	
	m_cbuffer_size = header.cbuffer_size;
	m_max_pixels = header.max_pixels;

	// get frame shared memory
	m_cbuffer_size = header.cbuffer_size;
	m_cbuffer_size = header.cbuffer_size;
	for(unsigned int i = 0; i < header.cbuffer_size; ++i) {
		m_shm_frame_ptrs.push_back((char*) -1);
		int id = ((GLInjectFrameInfo*) (m_shm_main_ptr + sizeof(GLInjectHeader) + sizeof(GLInjectFrameInfo) * i))->shm_id;
		m_shm_frame_ptrs.back() = (char*) shmat(id, NULL, SHM_RND);
		if(m_shm_frame_ptrs.back() == (char*) -1) {
			fprintf(stderr, "[GLInjectLauncher::Init] Error: Can't attach to frame shared memory!\n");
			exit(-181818181);
		}
	}

}

GLFrameGrabber::~GLFrameGrabber() {

	// release frame shared memory
	while(!m_shm_frame_ptrs.empty()) {
		if(m_shm_frame_ptrs.back() != (char*) -1) {
			shmdt((void*) m_shm_frame_ptrs.back());
		}
		m_shm_frame_ptrs.pop_back();
	}

	// release main shared memory
	if(m_shm_main_ptr != (char*) -1) {
		shmdt((void*) m_shm_main_ptr);
		m_shm_main_ptr = (char*) -1;
	}

	fprintf(stderr, "[SSR-GLInject] GLFrameGrabber for [%p-0x%lx-0x%lx] destroyed.\n", m_x11_display, m_x11_window, m_glx_drawable);

}

void GLFrameGrabber::GrabFrame() {

	// get size
	Window window;
	int unused;
	unsigned int old_width = m_width, old_height = m_height;
	XGetGeometry(m_x11_display, m_x11_window, &window, &unused, &unused, &m_width, &m_height, (unsigned int*) &unused, (unsigned int*) &unused);
	if(m_width != old_width || m_height != old_height) {
		fprintf(stderr, "[SSR-GLInject] GLFrameGrabber for [%p-0x%lx-0x%lx] frame size = %ux%u\n", m_x11_display, m_x11_window, m_glx_drawable, m_width, m_height);
	}
	if(m_width > 10000 || m_height > 10000 || m_width * m_height > m_max_pixels) {
		if(m_warn_max_pixels) {
			m_warn_max_pixels = false;
			fprintf(stderr, "[SSR-GLInject] GLFrameGrabber for [%p-0x%lx-0x%lx] frame is too large to capture!\n", m_x11_display, m_x11_window, m_glx_drawable);
		}
		return;
	}

	// save settings
	glPushAttrib(GL_PIXEL_MODE_BIT);
	glPushClientAttrib(GL_CLIENT_PIXEL_STORE_BIT);
	glReadBuffer(GL_BACK);
	glPixelStorei(GL_PACK_ALIGNMENT, 8);

	// write the current size to shared memory
	((GLInjectHeader*) m_shm_main_ptr)->current_width = m_width;
	((GLInjectHeader*) m_shm_main_ptr)->current_height = m_height;

	// is there space in the circular buffer?
	GLInjectHeader header = *(GLInjectHeader*) m_shm_main_ptr;
	unsigned int frames_ready = positive_mod((int) header.write_pos - (int) header.read_pos, (int) m_cbuffer_size * 2);
	if(frames_ready < m_cbuffer_size) {

		// initialize the frame
		unsigned int current_frame = header.write_pos % m_cbuffer_size;
		GLInjectFrameInfo *frameinfo = (GLInjectFrameInfo*) (m_shm_main_ptr + sizeof(GLInjectHeader) + sizeof(GLInjectFrameInfo) * current_frame);
		frameinfo->timestamp = hrt_time_micro();
		frameinfo->width = m_width;
		frameinfo->height = m_height;
		uint8_t *image_data = (uint8_t*) m_shm_frame_ptrs[current_frame];

		// capture the frame
		glReadPixels(0, 0, m_width, m_height, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, image_data);

		// go to the next frame
		((GLInjectHeader*) m_shm_main_ptr)->write_pos = (header.write_pos + 1) % (m_cbuffer_size * 2);

	}

	// restore settings
	glPopClientAttrib();
	glPopAttrib();

	//fprintf(m_log, "%" PRIu64 "\t%" PRIu64 "\t%" PRIu64 "\t%" PRIu64 "\n", t2 - t1, t3 - t2, t4 - t3, t5 - t4);

}
