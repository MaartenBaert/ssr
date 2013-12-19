/*
Copyright (c) 2012-2013 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "Global.h"

#include "GLInject.h"
#include "GLFrameGrabber.h"
#include "elfhacks.h"

GLXWindow glinject_my_glXCreateWindow(Display* dpy, GLXFBConfig config, Window win, const int* attrib_list);
void glinject_my_glXSwapBuffers(Display* dpy, GLXDrawable drawable);
GLXextFuncPtr glinject_my_glXGetProcAddressARB(const GLubyte *proc_name);
int glinject_my_XNextEvent(Display* display, XEvent* event_return);

void *(*g_glinject_real_dlsym)(void*, const char*) = NULL;
void *(*g_glinject_real_dlvsym)(void*, const char*, const char*) = NULL;
GLXWindow (*g_glinject_real_glXCreateWindow)(Display*, GLXFBConfig, Window, const int*) = NULL;
void (*g_glinject_real_glXSwapBuffers)(Display*, GLXDrawable) = NULL;
GLXextFuncPtr (*g_glinject_real_glXGetProcAddressARB)(const GLubyte*) = NULL;
int (*g_glinject_real_XNextEvent)(Display*, XEvent*) = NULL;

int g_glinject_hooks_initialized = 0;

GLFrameGrabber::HotkeyInfo g_hotkey_info;
bool g_hotkey_pressed = false;

void glinject_init_hooks() {

	if(g_glinject_hooks_initialized)
		return;

	// part 1: get dlsym and dlvsym
	eh_obj_t libdl;
	if(eh_find_obj(&libdl, "*/libdl.so*")) {
		fprintf(stderr, "[SSR-GLInject] Can't open libdl.so!\n");
		exit(-181818181);
	}
	if(eh_find_sym(&libdl, "dlsym", (void **) &g_glinject_real_dlsym)) {
		fprintf(stderr, "[SSR-GLInject] Can't get dlsym address!\n");
		eh_destroy_obj(&libdl);
		exit(-181818181);
	}
	if(eh_find_sym(&libdl, "dlvsym", (void **) &g_glinject_real_dlvsym)) {
		fprintf(stderr, "[SSR-GLInject] Can't get dlvsym address!\n");
		eh_destroy_obj(&libdl);
		exit(-181818181);
	}
	eh_destroy_obj(&libdl);

	// part 2: get everything else
	g_glinject_real_glXCreateWindow = (GLXWindow (*)(Display*, GLXFBConfig, Window, const int*)) g_glinject_real_dlsym(RTLD_NEXT, "glXCreateWindow");
	if(g_glinject_real_glXCreateWindow == NULL) {
		fprintf(stderr, "[SSR-GLInject] Can't get glXCreateWindow address!\n");
		exit(-181818181);
	}
	g_glinject_real_glXSwapBuffers = (void (*)(Display*, GLXDrawable)) g_glinject_real_dlsym(RTLD_NEXT, "glXSwapBuffers");
	if(g_glinject_real_glXSwapBuffers == NULL) {
		fprintf(stderr, "[SSR-GLInject] Can't get glXSwapBuffers address!\n");
		exit(-181818181);
	}
	g_glinject_real_glXGetProcAddressARB = (GLXextFuncPtr (*)(const GLubyte*)) g_glinject_real_dlsym(RTLD_NEXT, "glXGetProcAddressARB");
	if(g_glinject_real_glXGetProcAddressARB == NULL) {
		fprintf(stderr, "[SSR-GLInject] Can't get glXGetProcAddressARB address!\n");
		exit(-181818181);
	}
	g_glinject_real_XNextEvent = (int (*)(Display*, XEvent*)) g_glinject_real_dlsym(RTLD_NEXT, "XNextEvent");
	if(g_glinject_real_XNextEvent == NULL) {
		fprintf(stderr, "[SSR-GLInject] Can't get XNextEvent address!\n");
		exit(-181818181);
	}

	g_glinject_hooks_initialized = 1;
}

struct Hook {
	const char* name;
	void* address;
};
Hook hook_table[] = {
	{"glXCreateWindow", (void*) &glinject_my_glXCreateWindow},
	{"glXSwapBuffers", (void*) &glinject_my_glXSwapBuffers},
	{"glXGetProcAddressARB", (void*) &glinject_my_glXGetProcAddressARB},
	{"XNextEvent", (void*) &glinject_my_XNextEvent}
};

GLXWindow glinject_my_glXCreateWindow(Display* dpy, GLXFBConfig config, Window win, const int* attrib_list) {
	GLXWindow res = g_glinject_real_glXCreateWindow(dpy, config, win, attrib_list);
	if(res == 0)
		return 0;
	g_glinject.NewGrabber(dpy, win, res);
	return res;
}

void glinject_my_glXSwapBuffers(Display* dpy, GLXDrawable drawable) {
	GLFrameGrabber *fg = g_glinject.FindGrabber(dpy, drawable);
	if(fg == NULL) {
		fprintf(stderr, "[SSR-GLInject] Warning: glXSwapBuffers called without existing frame grabber, creating one assuming window == drawable.\n");
		fg = g_glinject.NewGrabber(dpy, drawable, drawable);
	}
	g_hotkey_info = fg->GetHotkeyInfo();
	if(g_hotkey_pressed) {
		fg->TriggerHotkey();
		g_hotkey_pressed = false;
	}
	fg->GrabFrame();
	g_glinject_real_glXSwapBuffers(dpy, drawable);
}

GLXextFuncPtr glinject_my_glXGetProcAddressARB(const GLubyte *proc_name) {
	for(unsigned int i = 0; i < sizeof(hook_table) / sizeof(Hook); ++i) {
		if(strcmp(hook_table[i].name, (const char*) proc_name) == 0) {
			fprintf(stderr, "[SSR-GLInject] Hooked: glXGetProcAddressARB(%s).\n", proc_name);
			return (GLXextFuncPtr) hook_table[i].address;
		}
	}
	return g_glinject_real_glXGetProcAddressARB(proc_name);
}

int glinject_my_XNextEvent(Display* display, XEvent* event_return) {
	int res = g_glinject_real_XNextEvent(display, event_return);
	if(g_hotkey_info.enabled && event_return->type == KeyPress && event_return->xkey.keycode == g_hotkey_info.keycode
			&& (event_return->xkey.state & ~LockMask & ~Mod2Mask) == g_hotkey_info.modifiers) {
		g_hotkey_pressed = true;
	}
	return res;
}

// override existing functions

extern "C" GLXWindow glXCreateWindow(Display* dpy, GLXFBConfig config, Window win, const int* attrib_list) {
	glinject_init_hooks();
	return glinject_my_glXCreateWindow(dpy, config, win, attrib_list);
}

extern "C" void glXSwapBuffers(Display* dpy, GLXDrawable drawable) {
	glinject_init_hooks();
	glinject_my_glXSwapBuffers(dpy, drawable);
}

extern "C" GLXextFuncPtr glXGetProcAddressARB(const GLubyte *proc_name) {
	glinject_init_hooks();
	return glinject_my_glXGetProcAddressARB(proc_name);
}

extern "C" int XNextEvent(Display* display, XEvent* event_return) {
	glinject_init_hooks();
	return glinject_my_XNextEvent(display, event_return);
}

extern "C" void* dlsym(void* handle, const char* symbol) {
	glinject_init_hooks();
	for(unsigned int i = 0; i < sizeof(hook_table) / sizeof(Hook); ++i) {
		if(strcmp(hook_table[i].name, symbol) == 0) {
			fprintf(stderr, "[SSR-GLInject] Hooked: dlsym(%s).\n", symbol);
			return hook_table[i].address;
		}
	}
	return g_glinject_real_dlsym(handle, symbol);
}

extern "C" void* dlvsym(void* handle, const char* symbol, const char* version) {
	glinject_init_hooks();
	for(unsigned int i = 0; i < sizeof(hook_table) / sizeof(Hook); ++i) {
		if(strcmp(hook_table[i].name, symbol) == 0) {
			fprintf(stderr, "[SSR-GLInject] Hooked: dlvsym(%s,%s).\n", symbol, version);
			return hook_table[i].address;
		}
	}
	return g_glinject_real_dlvsym(handle, symbol, version);
}
