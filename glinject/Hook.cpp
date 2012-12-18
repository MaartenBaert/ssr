/*
Copyright (c) 2012 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "StdAfx.h"

#include "GLInject.h"
#include "GLFrameGrabber.h"

GLXWindow my_glXCreateWindow(Display* dpy, GLXFBConfig config, Window win, const int* attrib_list);
void my_glXSwapBuffers(Display* dpy, GLXDrawable drawable);
GLXextFuncPtr my_glXGetProcAddressARB(const GLubyte *proc_name);

struct Hook {
	const char* name;
	void* address;
};
Hook hook_table[] = {
	{"glXCreateWindow", (void*) &my_glXCreateWindow},
	{"glXSwapBuffers", (void*) &my_glXSwapBuffers},
	{"glXGetProcAddressARB", (void*) &my_glXGetProcAddressARB},
};

GLXWindow my_glXCreateWindow(Display* dpy, GLXFBConfig config, Window win, const int* attrib_list) {
	GLXWindow res = g_glinject.m_real_glXCreateWindow(dpy, config, win, attrib_list);
	if(res == 0)
		return 0;
	g_glinject.NewGrabber(dpy, win, res);
	return res;
}

void my_glXSwapBuffers(Display* dpy, GLXDrawable drawable) {
	GLFrameGrabber *fg = g_glinject.FindGrabber(dpy, drawable);
	if(fg == NULL) {
		fprintf(stderr, "[SSR-GLInject] Warning: glXSwapBuffers called without existing frame grabber, creating one assuming window == drawable.\n");
		fg = g_glinject.NewGrabber(dpy, drawable, drawable);
	}
	fg->GrabFrame();
	g_glinject.m_real_glXSwapBuffers(dpy, drawable);
}

GLXextFuncPtr my_glXGetProcAddressARB(const GLubyte *proc_name) {
	for(unsigned int i = 0; i < sizeof(hook_table) / sizeof(Hook); ++i) {
		if(strcmp(hook_table[i].name, (const char*) proc_name) == 0) {
			fprintf(stderr, "[SSR-GLInject] Hooked: glXGetProcAddressARB(%s).\n", proc_name);
			return (GLXextFuncPtr) hook_table[i].address;
		}
	}
	return g_glinject.m_real_glXGetProcAddressARB(proc_name);
}

// override existing functions

extern "C" GLXWindow glXCreateWindow(Display* dpy, GLXFBConfig config, Window win, const int* attrib_list) {
	return my_glXCreateWindow(dpy, config, win, attrib_list);
}

extern "C" void glXSwapBuffers(Display* dpy, GLXDrawable drawable) {
	my_glXSwapBuffers(dpy, drawable);
}

extern "C" GLXextFuncPtr glXGetProcAddressARB(const GLubyte *proc_name) {
	return my_glXGetProcAddressARB(proc_name);
}

extern "C" void* dlsym(void* handle, const char* symbol) {
	for(unsigned int i = 0; i < sizeof(hook_table) / sizeof(Hook); ++i) {
		if(strcmp(hook_table[i].name, symbol) == 0) {
			fprintf(stderr, "[SSR-GLInject] Hooked: dlsym(%s).\n", symbol);
			return hook_table[i].address;
		}
	}
	return g_glinject.m_real_dlsym(handle, symbol);
}

extern "C" void* dlvsym(void* handle, const char* symbol, const char* version) {
	for(unsigned int i = 0; i < sizeof(hook_table) / sizeof(Hook); ++i) {
		if(strcmp(hook_table[i].name, symbol) == 0) {
			fprintf(stderr, "[SSR-GLInject] Hooked: dlvsym(%s,%s).\n", symbol, version);
			return hook_table[i].address;
		}
	}
	return g_glinject.m_real_dlvsym(handle, symbol, version);
}
