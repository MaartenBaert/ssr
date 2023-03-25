/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "Global.h"
#include "GLInject.h"

#include "GLXFrameGrabber.h"

GLInject::GLInject() {

#ifdef __x86_64__
	fprintf(stderr, "[SSR-GLInject] Library loaded (64-bit).\n");
#else
	fprintf(stderr, "[SSR-GLInject] Library loaded (32-bit).\n");
#endif

}

GLInject::~GLInject() {

	while(!m_glx_frame_grabbers.empty()) {
		delete m_glx_frame_grabbers.back();
		m_glx_frame_grabbers.pop_back();
	}

	fprintf(stderr, "[SSR-GLInject] Library unloaded.\n");

}

GLXFrameGrabber* GLInject::NewGLXFrameGrabber(Display* display, Window window, GLXDrawable drawable) {
	GLXFrameGrabber *fg = FindGLXFrameGrabber(display, drawable);
	if(fg == NULL) {
		fg = new GLXFrameGrabber(display, window, drawable);
		m_glx_frame_grabbers.push_back(fg);
	}
	return fg;
}

GLXFrameGrabber* GLInject::FindGLXFrameGrabber(Display* display, GLXDrawable drawable) {
	for(unsigned int i = 0; i < m_glx_frame_grabbers.size(); ++i) {
		if(m_glx_frame_grabbers[i]->GetX11Display() == display && m_glx_frame_grabbers[i]->GetGLXDrawable() == drawable)
			return m_glx_frame_grabbers[i];
	}
	return NULL;
}

void GLInject::DeleteGLXFrameGrabberByWindow(Display* display, Window window) {
	for(unsigned int i = m_glx_frame_grabbers.size(); i > 0; ) {
		--i;
		if(m_glx_frame_grabbers[i]->GetX11Display() == display && m_glx_frame_grabbers[i]->GetX11Window() == window) {
			delete m_glx_frame_grabbers[i];
			m_glx_frame_grabbers[i] = m_glx_frame_grabbers.back();
			m_glx_frame_grabbers.pop_back();
		}
	}
}

void GLInject::DeleteGLXFrameGrabberByDrawable(Display* display, GLXDrawable drawable) {
	for(unsigned int i = m_glx_frame_grabbers.size(); i > 0; ) {
		--i;
		if(m_glx_frame_grabbers[i]->GetX11Display() == display && m_glx_frame_grabbers[i]->GetGLXDrawable() == drawable) {
			delete m_glx_frame_grabbers[i];
			m_glx_frame_grabbers[i] = m_glx_frame_grabbers.back();
			m_glx_frame_grabbers.pop_back();
		}
	}
}
