/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "Global.h"
#include "GLXFrameGrabber.h"
#include "ShmStructs.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <X11/extensions/Xfixes.h>

#define CGLE(code) \
	code; \
	if(m_debug) CheckGLError(#code);

static unsigned int g_glx_frame_grabber_counter = 0;

// Print the last OpenGL error if there was one.
static void CheckGLError(const char* at) {
	GLenum error = glGetError();
	if(error != GL_NO_ERROR) {
		GLINJECT_PRINT("Warning: OpenGL error in " << at << ": " << gluErrorString(error));
	}
}

// Returns the OpenGL version as (major * 1000 + minor). So OpenGL 2.1 would be '2001'.
static unsigned int GetGLVersion() {

	// get version string
	const char *str = (const char*) glGetString(GL_VERSION);
	if(str == NULL) {
		GLINJECT_PRINT("Error: Could not get OpenGL version, version string is NULL!");
		exit(1);
	}

	// read major version
	unsigned int dot1 = strspn(str, "0123456789");
	if(str[dot1] != '.') {
		GLINJECT_PRINT("Error: Could not get OpenGL version, version string is '" << str << "'!");
		exit(1);
	}
	unsigned int major = atoi(str);

	// read minor version
	unsigned int dot2 = strspn(str + dot1 + 1, "0123456789") + dot1 + 1;
	if(str[dot2] != '.' && str[dot2] != ' ' && str[dot2] != '\0') {
		GLINJECT_PRINT("Error: Could not get OpenGL version, version string is '" << str << "'!");
		exit(1);
	}
	unsigned int minor = atoi(str + dot1 + 1);

	GLINJECT_PRINT("OpenGL version = " << major << "." << minor << " (" << str << ").");
	return major * 1000 + minor;
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

GLXFrameGrabber::GLXFrameGrabber(Display* display, Window window, GLXDrawable drawable) {

	m_id = ++g_glx_frame_grabber_counter;
	m_x11_display = display;
	m_x11_window = window;
	m_glx_drawable = drawable;

	m_gl_version = (unsigned int) -1; // get it later, when the OpenGL context has been selected
	m_warn_too_small = true;
	m_warn_too_large = true;

	m_stream_writer = NULL; // will be created when we get the first frame

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

GLXFrameGrabber::~GLXFrameGrabber() {
	Free();
}

void GLXFrameGrabber::Init() {

	GLINJECT_PRINT("[GLXFrameGrabber " << m_id << "] Created GLX frame grabber.");

	// enable debugging?
	{
		const char *ssr_glx_debug = getenv("SSR_GLX_DEBUG");
		if(ssr_glx_debug != NULL && atoi(ssr_glx_debug) > 0) {
			GLINJECT_PRINT("[GLXFrameGrabber " << m_id << "] GLX debugging enabled.");
			m_debug = true;
		} else {
			m_debug = false;
		}
	}

	// showing the cursor requires XFixes (which should be supported on any modern X server, but let's check it anyway)
	{
		int event, error;
		if(XFixesQueryExtension(m_x11_display, &event, &error)) {
			m_has_xfixes = true;
		} else {
			GLINJECT_PRINT("[GLXFrameGrabber " << m_id << "] Warning: XFixes is not supported by server, the cursor will not be recorded.");
			m_has_xfixes = false;
		}
	}

}

void GLXFrameGrabber::Free() {

	// destroy stream writer
	if(m_stream_writer != NULL) {
		delete m_stream_writer;
		m_stream_writer = NULL;
	}

	GLINJECT_PRINT("[GLXFrameGrabber " << m_id << "] Destroyed GLX frame grabber.");

}

void GLXFrameGrabber::GrabFrame() {

	// create stream writer
	if(m_stream_writer == NULL) {
		std::string channel;
		const char *ssr_channel = getenv("SSR_CHANNEL");
		if(ssr_channel != NULL)
			channel = ssr_channel;
		std::ostringstream source;
		source << "glx" << std::setw(4) << std::setfill('0') << m_id;
		m_stream_writer = new SSRVideoStreamWriter(channel, source.str());
	}

	// get the OpenGL version
	if(m_gl_version == (unsigned int) -1)
		m_gl_version = GetGLVersion();

	// get the size of the window
	// glXQueryDrawable is buggy, use XGetGeometry instead
	unsigned int width, height, stride;
	{
		Window unused_window;
		int unused;
		XGetGeometry(m_x11_display, m_x11_window, &unused_window, &unused, &unused, &width, &height, (unsigned int*) &unused, (unsigned int*) &unused);
		stride = grow_align16(width * 4);
		m_stream_writer->UpdateSize(width, height, -(int) stride);
	}

	// ignore frames that are too small or too large
	if(width < 2 || height < 2) {
		if(m_warn_too_small) {
			m_warn_too_small = false;
			GLINJECT_PRINT("[GLXFrameGrabber " << m_id << "] Error: Frame is too small!");
		}
		return;
	}
	if(width > SSR_MAX_IMAGE_SIZE || height > SSR_MAX_IMAGE_SIZE) {
		if(m_warn_too_large) {
			m_warn_too_large = false;
			GLINJECT_PRINT("[GLXFrameGrabber " << m_id << "] Error: Frame is too large!");
		}
		return;
	}

	// should we capture this frame?
	unsigned int flags;
	void *image_data = m_stream_writer->NewFrame(&flags);
	if(image_data == NULL)
		return;

	// detect errors in external code so it won't look like it's my fault :)
	if(m_debug) CheckGLError("<external code>");

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
	CGLE(glPixelStorei(GL_PACK_ROW_LENGTH, stride / 4));
	CGLE(glPixelStorei(GL_PACK_IMAGE_HEIGHT, 0));
	CGLE(glPixelStorei(GL_PACK_SKIP_PIXELS, 0));
	CGLE(glPixelStorei(GL_PACK_SKIP_ROWS, 0));
	CGLE(glPixelStorei(GL_PACK_SKIP_IMAGES, 0));
	CGLE(glPixelStorei(GL_PACK_ALIGNMENT, 8));
	CGLE(glReadBuffer(GL_BACK));

	// capture the frame
	CGLE(glReadPixels(0, 0, width, height, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, image_data));

	// draw the cursor
	if((flags & GLINJECT_FLAG_RECORD_CURSOR) && m_has_xfixes) {
		int inner_x, inner_y;
		Window unused_window;
		if(XTranslateCoordinates(m_x11_display, m_x11_window, DefaultRootWindow(m_x11_display), 0, 0, &inner_x, &inner_y, &unused_window)) {
			GLImageDrawCursor(m_x11_display, (uint8_t*) image_data, stride, width, height, inner_x, inner_y);
		}
	}

	// write the frame
	m_stream_writer->NextFrame();

	// restore settings
	CGLE(glBindBuffer(GL_PIXEL_PACK_BUFFER, old_pbo));
	CGLE(glBindFramebuffer(GL_DRAW_FRAMEBUFFER, old_fbo_draw));
	CGLE(glBindFramebuffer(GL_READ_FRAMEBUFFER, old_fbo_read));
	CGLE(glPopClientAttrib());
	CGLE(glPopAttrib());

}
