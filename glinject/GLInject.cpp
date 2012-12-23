/*
Copyright (c) 2012 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "StdAfx.h"
#include "GLInject.h"

#include "GLFrameGrabber.h"

GLInject g_glinject;
int g_glinject_ready = 0;

GLInject::GLInject() {

#ifdef __x86_64__
	fprintf(stderr, "[SSR-GLInject] Library loaded (64-bit).\n");
#else
	fprintf(stderr, "[SSR-GLInject] Library loaded (32-bit).\n");
#endif

	g_glinject_ready = 1;
	fprintf(stderr, "[SSR-GLInject] Library successfully initialized.\n");

}

GLInject::~GLInject() {

	while(!m_frame_grabbers.empty()) {
		delete m_frame_grabbers.back();
		m_frame_grabbers.pop_back();
	}

	fprintf(stderr, "[SSR-GLInject] Library unloaded.\n");

}

GLFrameGrabber* GLInject::NewGrabber(Display* display, Window window, GLXDrawable drawable) {
	if(!g_glinject_ready) {
		fprintf(stderr, "[SSR-GLInject] Error: NewGrabber called before GLInject was initialized.\n");
		exit(-181818181);
	}
	GLFrameGrabber *fg = FindGrabber(display, drawable);
	if(fg != NULL)
		return fg;
	m_frame_grabbers.push_back(NULL);
	m_frame_grabbers.back() = new GLFrameGrabber(display, window, drawable);
	return m_frame_grabbers.back();
}

GLFrameGrabber* GLInject::FindGrabber(Display* display, GLXDrawable drawable) {
	if(!g_glinject_ready) {
		fprintf(stderr, "[SSR-GLInject] Error: FindGrabber called before GLInject was initialized.\n");
		exit(-181818181);
	}
	for(unsigned int i = 0; i < m_frame_grabbers.size(); ++i) {
		if(m_frame_grabbers[i]->GetX11Display() == display && m_frame_grabbers[i]->GetGLXDrawable() == drawable)
			return m_frame_grabbers[i];
	}
	return NULL;
}
