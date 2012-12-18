/*
Copyright (c) 2012 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "StdAfx.h"
#include "GLInject.h"

#include "GLFrameGrabber.h"
#include "elfhacks.h"

GLInject g_glinject;

GLInject::GLInject() {

#ifdef __x86_64__
	fprintf(stderr, "[SSR-GLInject] Library loaded (64-bit).\n");
#else
	fprintf(stderr, "[SSR-GLInject] Library loaded (32-bit).\n");
#endif

	eh_obj_t libdl;
	if(eh_find_obj(&libdl, "*/libdl.so*")) {
		fprintf(stderr, "[SSR-GLInject] Can't open libdl.so!\n");
		throw 0;
	}
	if(eh_find_sym(&libdl, "dlsym", (void **) &m_real_dlsym)) {
		fprintf(stderr, "[SSR-GLInject] Can't get dlsym address!\n");
		eh_destroy_obj(&libdl);
		throw 0;
	}
	if(eh_find_sym(&libdl, "dlvsym", (void **) &m_real_dlvsym)) {
		fprintf(stderr, "[SSR-GLInject] Can't get dlvsym address!\n");
		eh_destroy_obj(&libdl);
		throw 0;
	}
	eh_destroy_obj(&libdl);

	//void *libgl_handle = dlopen("libGL.so.1", RTLD_LAZY);
	m_real_glXCreateWindow = (GLXWindow (*)(Display*, GLXFBConfig, Window, const int*)) m_real_dlsym(RTLD_NEXT, "glXCreateWindow");
	if(m_real_glXCreateWindow == NULL) {
		fprintf(stderr, "[SSR-GLInject] Can't get glXCreateWindow address!\n");
		throw 0;
	}
	m_real_glXSwapBuffers = (void (*)(Display*, GLXDrawable)) m_real_dlsym(RTLD_NEXT, "glXSwapBuffers");
	if(m_real_glXSwapBuffers == NULL) {
		fprintf(stderr, "[SSR-GLInject] Can't get glXSwapBuffers address!\n");
		throw 0;
	}
	m_real_glXGetProcAddressARB = (GLXextFuncPtr (*)(const GLubyte*)) m_real_dlsym(RTLD_NEXT, "glXGetProcAddressARB");
	if(m_real_glXGetProcAddressARB == NULL) {
		fprintf(stderr, "[SSR-GLInject] Can't get glXGetProcAddressARB address!\n");
		throw 0;
	}

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
	GLFrameGrabber *fg = FindGrabber(display, drawable);
	if(fg != NULL)
		return fg;
	m_frame_grabbers.push_back(NULL);
	m_frame_grabbers.back() = new GLFrameGrabber(display, window, drawable);
	return m_frame_grabbers.back();
}

GLFrameGrabber* GLInject::FindGrabber(Display* display, GLXDrawable drawable) {
	for(unsigned int i = 0; i < m_frame_grabbers.size(); ++i) {
		if(m_frame_grabbers[i]->GetX11Display() == display && m_frame_grabbers[i]->GetGLXDrawable() == drawable)
			return m_frame_grabbers[i];
	}
	return NULL;
}
