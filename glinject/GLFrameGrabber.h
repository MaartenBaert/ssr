/*
Copyright (c) 2012 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#pragma once
#include "StdAfx.h"

#define BUFFER_COUNT 2

class GLFrameGrabber {

private:
	struct ShmFrame {
		int id;
		volatile char *ptr;
		inline ShmFrame() : id(-1), ptr((char*) -1) {}
	};

private:
	Display *m_x11_display;
	Window m_x11_window;
	GLXDrawable m_glx_drawable;
	unsigned int m_width, m_height;
	
	unsigned int m_cbuffer_size, m_max_pixels;
	volatile char *m_shm_main_ptr;
	std::vector<volatile char*> m_shm_frame_ptrs;
	
	bool m_warn_max_pixels;

	//bool m_first_frame;
	//unsigned int m_current_buffer;
	//unsigned int m_buffers[BUFFER_COUNT];

	FILE *m_log;

public:
	GLFrameGrabber(Display* display, Window window, GLXDrawable drawable);
	~GLFrameGrabber();
	void Init();
	void Free();

	void GrabFrame();

public:
	inline Display* GetX11Display() { return m_x11_display; }
	inline Window GetX11Window() { return m_x11_window; }
	inline GLXDrawable GetGLXDrawable() { return m_glx_drawable; }

};
