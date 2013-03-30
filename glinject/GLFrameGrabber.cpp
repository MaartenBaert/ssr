/*
Copyright (c) 2012-2013 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "StdAfx.h"
#include "GLFrameGrabber.h"

#include "ShmStructs.h"

#include <X11/extensions/Xfixes.h>

#define CGLE(code) \
	code; \
	CheckGLError(#code);

static void CheckGLError(const char* at) {
	GLenum error = glGetError();
	if(error != GL_NO_ERROR) {
		fprintf(stderr, "[SSR-GLInject] Warning: OpenGL error in %s: %s\n", at, gluErrorString(error));
	}
}

static size_t shmsize(int shmid) {
	shmid_ds buf;
	if(shmctl(shmid, IPC_STAT, &buf) < 0)
		return 0;
	return buf.shm_segsz;
}

static void GLImageDrawCursor(Display* dpy, uint8_t* image_data, size_t image_stride, int image_width, int image_height, int recording_area_x, int recording_area_y) {

	// get the cursor
	XFixesCursorImage *xcim = XFixesGetCursorImage(dpy);
	if(xcim == NULL)
		return;

	// calculate the position of the cursor
	int x = xcim->x - xcim->xhot - recording_area_x;
	int y = xcim->y - xcim->yhot - recording_area_y;

	// calculate the part of the cursor that's visible
	int cursor_left = std::max(0, -x), cursor_right = std::min((int) xcim->width, image_width - x);
	int cursor_top = std::max(0, -y), cursor_bottom = std::min((int) xcim->height, image_height - y);

	// draw the cursor
	// XFixesCursorImage uses 'long' instead of 'int' to store the cursor images, which is a bit weird since
	// 'long' is 64-bit on 64-bit systems and only 32 bits are actually used. The image uses premultiplied alpha.
	for(int j = cursor_top; j < cursor_bottom; ++j) {
		unsigned long *cursor_row = xcim->pixels + xcim->width * j;
		uint8_t *image_row = image_data + image_stride * (image_height - 1 - y - j);
		for(int i = cursor_left; i < cursor_right; ++i) {
			unsigned long cursor_pixel = cursor_row[i];
			uint8_t *image_pixel = image_row + 4 * (x + i);
			int cursor_a = (uint8_t) (cursor_pixel >> 24);
			int cursor_r = (uint8_t) (cursor_pixel >> 16);
			int cursor_g = (uint8_t) (cursor_pixel >> 8);
			int cursor_b = (uint8_t) (cursor_pixel >> 0);
			if(cursor_a == 255) {
				image_pixel[2] = cursor_r;
				image_pixel[1] = cursor_g;
				image_pixel[0] = cursor_b;
			} else {
				image_pixel[2] = (image_pixel[2] * (255 - cursor_a) + 127) / 255 + cursor_r;
				image_pixel[1] = (image_pixel[1] * (255 - cursor_a) + 127) / 255 + cursor_g;
				image_pixel[0] = (image_pixel[0] * (255 - cursor_a) + 127) / 255 + cursor_b;
			}
		}
	}

	// free the cursor
	XFree(xcim);

}

GLFrameGrabber::GLFrameGrabber(Display* display, Window window, GLXDrawable drawable) {

	m_x11_display = display;
	m_x11_window = window;
	m_glx_drawable = drawable;
	m_width = 0;
	m_height = 0;

	m_shm_main_ptr = (char*) -1;

	m_next_frame_time = hrt_time_micro();

	m_warn_too_small = true;
	m_warn_too_large = true;

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
	size_t shm_main_size = shmsize(shm_main_id);
	if(shm_main_size < sizeof(GLInjectHeader)) {
		fprintf(stderr, "[SSR-GLInject] Error: Main shared memory is too small!\n");
		exit(-181818181);
	}
	GLInjectHeader header = *(GLInjectHeader*) m_shm_main_ptr;
	m_cbuffer_size = header.cbuffer_size;
	m_max_bytes = header.max_bytes;
	m_target_fps = header.target_fps;
	m_flags = header.flags;
	if(m_cbuffer_size <= 0 || m_cbuffer_size > 1000000) {
		fprintf(stderr, "[SSR-GLInject] Error: Circular buffer size %u is invalid!\n", m_cbuffer_size);
		exit(-181818181);
	}
	if(m_max_bytes > 1024 * 1024 * 1024) {
		fprintf(stderr, "[SSR-GLInject] Error: Maximum byte count %u is invalid!\n", m_max_bytes);
		exit(-181818181);
	}
	if(shm_main_size < sizeof(GLInjectHeader) + sizeof(GLInjectFrameInfo) * m_cbuffer_size) {
		fprintf(stderr, "[SSR-GLInject] Error: Main shared memory is too small to contain %u frames!\n", m_cbuffer_size);
		exit(-181818181);
	}

	// get frame shared memory
	for(unsigned int i = 0; i < m_cbuffer_size; ++i) {
		m_shm_frame_ptrs.push_back((char*) -1);
		GLInjectFrameInfo *frameinfo = (GLInjectFrameInfo*) (m_shm_main_ptr + sizeof(GLInjectHeader) + sizeof(GLInjectFrameInfo) * i);
		int shm_frame_id = frameinfo->shm_id;
		m_shm_frame_ptrs.back() = (char*) shmat(shm_frame_id, NULL, SHM_RND);
		if(m_shm_frame_ptrs.back() == (char*) -1) {
			fprintf(stderr, "[GLInjectLauncher::Init] Error: Can't attach to frame shared memory (id = %d)!\n", shm_frame_id);
			exit(-181818181);
		}
		size_t shm_frame_size = shmsize(shm_frame_id);
		if(shm_frame_size != m_max_bytes) {
			fprintf(stderr, "[SSR-GLInject] Error: Frame shared memory is too small!\n");
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
	Window unused_window;
	int unused;
	unsigned int old_width = m_width, old_height = m_height;
	XGetGeometry(m_x11_display, m_x11_window, &unused_window, &unused, &unused, &m_width, &m_height, (unsigned int*) &unused, (unsigned int*) &unused);
	if(m_width != old_width || m_height != old_height) {
		fprintf(stderr, "[SSR-GLInject] GLFrameGrabber for [%p-0x%lx-0x%lx] frame size = %ux%u\n", m_x11_display, m_x11_window, m_glx_drawable, m_width, m_height);
	}

	// check image size
	unsigned int image_stride = grow_align16(m_width * 4);
	if(m_width < 2 || m_height < 2) {
		if(m_warn_too_small) {
			m_warn_too_small = false;
			fprintf(stderr, "[SSR-GLInject] GLFrameGrabber for [%p-0x%lx-0x%lx] frame is too small!\n", m_x11_display, m_x11_window, m_glx_drawable);
		}
		return;
	}
	if(m_width > 10000 || m_height > 10000 || image_stride * m_height > m_max_bytes) {
		if(m_warn_too_large) {
			m_warn_too_large = false;
			fprintf(stderr, "[SSR-GLInject] GLFrameGrabber for [%p-0x%lx-0x%lx] frame is too large to capture!\n", m_x11_display, m_x11_window, m_glx_drawable);
		}
		return;
	}

	// write the current size to shared memory
	((GLInjectHeader*) m_shm_main_ptr)->current_width = m_width;
	((GLInjectHeader*) m_shm_main_ptr)->current_height = m_height;

	// is there space in the circular buffer?
	GLInjectHeader header = *(GLInjectHeader*) m_shm_main_ptr;
	unsigned int frames_ready = positive_mod((int) header.write_pos - (int) header.read_pos, (int) m_cbuffer_size * 2);
	if(frames_ready >= m_cbuffer_size)
		return;

	// get the timestamp
	int64_t timestamp = hrt_time_micro();
	if(m_target_fps > 0) {
		int64_t delay = 1000000 / m_target_fps;
		if(m_flags & GLINJECT_FLAG_LIMIT_FPS) {
			if(timestamp < m_next_frame_time) {
				usleep(m_next_frame_time - timestamp);
				timestamp = hrt_time_micro();
			}
		} else {
			if(timestamp < m_next_frame_time)
				return;
		}
		m_next_frame_time = std::max(m_next_frame_time + delay, timestamp);
	}

	CheckGLError("<external code>");

	// save settings
	CGLE(glPushAttrib(GL_PIXEL_MODE_BIT));
	CGLE(glPushClientAttrib(GL_CLIENT_PIXEL_STORE_BIT));
	int old_pbo, old_fbo_draw, old_fbo_read;
	CGLE(glGetIntegerv(GL_PIXEL_PACK_BUFFER_BINDING, &old_pbo));
	CGLE(glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &old_fbo_draw));
	CGLE(glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &old_fbo_read));

	// change settings
	CGLE(glBindBuffer(GL_PIXEL_PACK_BUFFER, 0));
	CGLE(glBindFramebuffer(GL_FRAMEBUFFER, 0));
	CGLE(glPixelStorei(GL_PACK_SWAP_BYTES, 0));
	CGLE(glPixelStorei(GL_PACK_ROW_LENGTH, image_stride / 4));
	CGLE(glPixelStorei(GL_PACK_IMAGE_HEIGHT, 0));
	CGLE(glPixelStorei(GL_PACK_SKIP_PIXELS, 0));
	CGLE(glPixelStorei(GL_PACK_SKIP_ROWS, 0));
	CGLE(glPixelStorei(GL_PACK_SKIP_IMAGES, 0));
	CGLE(glPixelStorei(GL_PACK_ALIGNMENT, 8));
	CGLE(glReadBuffer((m_flags & GLINJECT_FLAG_CAPTURE_FRONT)? GL_FRONT : GL_BACK));

	// initialize the frame
	unsigned int current_frame = header.write_pos % m_cbuffer_size;
	GLInjectFrameInfo *frameinfo = (GLInjectFrameInfo*) (m_shm_main_ptr + sizeof(GLInjectHeader) + sizeof(GLInjectFrameInfo) * current_frame);
	frameinfo->timestamp = timestamp;
	frameinfo->width = m_width;
	frameinfo->height = m_height;
	uint8_t *image_data = (uint8_t*) m_shm_frame_ptrs[current_frame];

	// capture the frame
	CGLE(glReadPixels(0, 0, m_width, m_height, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, image_data));

	// draw the cursor
	if(m_flags & GLINJECT_FLAG_RECORD_CURSOR) {
		int inner_x, inner_y;
		if(XTranslateCoordinates(m_x11_display, m_x11_window, DefaultRootWindow(m_x11_display), 0, 0, &inner_x, &inner_y, &unused_window)) {
			GLImageDrawCursor(m_x11_display, image_data, image_stride, m_width, m_height, inner_x, inner_y);
		}
	}

	// go to the next frame
	((GLInjectHeader*) m_shm_main_ptr)->write_pos = (header.write_pos + 1) % (m_cbuffer_size * 2);

	// restore settings
	CGLE(glBindBuffer(GL_PIXEL_PACK_BUFFER, old_pbo));
	CGLE(glBindFramebuffer(GL_DRAW_FRAMEBUFFER, old_fbo_draw));
	CGLE(glBindFramebuffer(GL_READ_FRAMEBUFFER, old_fbo_read));
	CGLE(glPopClientAttrib());
	CGLE(glPopAttrib());

}
