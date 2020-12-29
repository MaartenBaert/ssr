/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "Global.h"

#include "elfhacks.h"
#include "GLInject.h"
#include "GLXFrameGrabber.h"

#include <GL/glx.h>
#include <X11/X.h>

extern char **environ;

typedef void (*GLXextFuncPtr)(void);

void InitGLInject();
void FreeGLInject();

GLXWindow glinject_my_glXCreateWindow(Display* dpy, GLXFBConfig config, Window win, const int* attrib_list);
void glinject_my_glXDestroyWindow(Display* dpy, GLXWindow win);
int glinject_my_XDestroyWindow(Display* dpy, Window win);
void glinject_my_glXSwapBuffers(Display* dpy, GLXDrawable drawable);
GLXextFuncPtr glinject_my_glXGetProcAddressARB(const GLubyte *proc_name);
int glinject_my_XNextEvent(Display* display, XEvent* event_return);

void *(*g_glinject_real_dlsym)(void*, const char*) = NULL;
void *(*g_glinject_real_dlvsym)(void*, const char*, const char*) = NULL;
int (*g_glinject_real_execv)(const char*, char* const*) = NULL;
int (*g_glinject_real_execve)(const char*, char* const*, char* const*) = NULL;
int (*g_glinject_real_execvp)(const char*, char* const*) = NULL;
int (*g_glinject_real_execvpe)(const char*, char* const*, char* const*) = NULL;
GLXWindow (*g_glinject_real_glXCreateWindow)(Display*, GLXFBConfig, Window, const int*) = NULL;
void (*g_glinject_real_glXDestroyWindow)(Display*, GLXWindow) = NULL;
int (*g_glinject_real_XDestroyWindow)(Display*, Window) = NULL;
void (*g_glinject_real_glXSwapBuffers)(Display*, GLXDrawable) = NULL;
GLXextFuncPtr (*g_glinject_real_glXGetProcAddressARB)(const GLubyte*) = NULL;
int (*g_glinject_real_XNextEvent)(Display*, XEvent*) = NULL;

static GLInject *g_glinject = NULL;
static std::mutex g_glinject_mutex;

void InitGLInject() {
	std::lock_guard<std::mutex> lock(g_glinject_mutex);

	if(g_glinject != NULL)
		return;

	// part 1: get dlsym and dlvsym
	eh_obj_t libdl;
	if(eh_find_obj(&libdl, "*/libdl.so*")) {
		GLINJECT_PRINT("Error: Can't open libdl.so!");
		exit(1);
	}
	if(eh_find_sym(&libdl, "dlsym", (void**) &g_glinject_real_dlsym)) {
		GLINJECT_PRINT("Error: Can't get dlsym address!");
		eh_destroy_obj(&libdl);
		exit(1);
	}
	if(eh_find_sym(&libdl, "dlvsym", (void**) &g_glinject_real_dlvsym)) {
		GLINJECT_PRINT("Error: Can't get dlvsym address!");
		eh_destroy_obj(&libdl);
		exit(1);
	}
	eh_destroy_obj(&libdl);

	// part 2: get everything else
	g_glinject_real_execv = (int (*)(const char*, char* const*)) g_glinject_real_dlsym(RTLD_NEXT, "execv");
	if(g_glinject_real_execv == NULL) {
		GLINJECT_PRINT("Error: Can't get execv address!");
		exit(1);
	}
	g_glinject_real_execve = (int (*)(const char*, char* const*, char* const*)) g_glinject_real_dlsym(RTLD_NEXT, "execve");
	if(g_glinject_real_execve == NULL) {
		GLINJECT_PRINT("Error: Can't get execve address!");
		exit(1);
	}
	g_glinject_real_execvp = (int (*)(const char*, char* const*)) g_glinject_real_dlsym(RTLD_NEXT, "execvp");
	if(g_glinject_real_execvp == NULL) {
		GLINJECT_PRINT("Error: Can't get execvp address!");
		exit(1);
	}
	g_glinject_real_execvpe = (int (*)(const char*, char* const*, char* const*)) g_glinject_real_dlsym(RTLD_NEXT, "execvpe");
	if(g_glinject_real_execvpe == NULL) {
		GLINJECT_PRINT("Error: Can't get execvpe address!");
		exit(1);
	}
	g_glinject_real_glXCreateWindow = (GLXWindow (*)(Display*, GLXFBConfig, Window, const int*)) g_glinject_real_dlsym(RTLD_NEXT, "glXCreateWindow");
	if(g_glinject_real_glXCreateWindow == NULL) {
		GLINJECT_PRINT("Error: Can't get glXCreateWindow address!");
		exit(1);
	}
	g_glinject_real_glXDestroyWindow = (void (*)(Display*, GLXWindow)) g_glinject_real_dlsym(RTLD_NEXT, "glXDestroyWindow");
	if(g_glinject_real_glXDestroyWindow == NULL) {
		GLINJECT_PRINT("Error: Can't get glXDestroyWindow address!");
		exit(1);
	}
	g_glinject_real_XDestroyWindow = (int (*)(Display*, Window)) g_glinject_real_dlsym(RTLD_NEXT, "XDestroyWindow");
	if(g_glinject_real_XDestroyWindow == NULL) {
		GLINJECT_PRINT("Error: Can't get XDestroyWindow address!");
		exit(1);
	}
	g_glinject_real_glXSwapBuffers = (void (*)(Display*, GLXDrawable)) g_glinject_real_dlsym(RTLD_NEXT, "glXSwapBuffers");
	if(g_glinject_real_glXSwapBuffers == NULL) {
		GLINJECT_PRINT("Error: Can't get glXSwapBuffers address!");
		exit(1);
	}
	g_glinject_real_glXGetProcAddressARB = (GLXextFuncPtr (*)(const GLubyte*)) g_glinject_real_dlsym(RTLD_NEXT, "glXGetProcAddressARB");
	if(g_glinject_real_glXGetProcAddressARB == NULL) {
		GLINJECT_PRINT("Error: Can't get glXGetProcAddressARB address!");
		exit(1);
	}
	g_glinject_real_XNextEvent = (int (*)(Display*, XEvent*)) g_glinject_real_dlsym(RTLD_NEXT, "XNextEvent");
	if(g_glinject_real_XNextEvent == NULL) {
		GLINJECT_PRINT("Error: Can't get XNextEvent address!");
		exit(1);
	}

	g_glinject = new GLInject();

	atexit(FreeGLInject);

}

void FreeGLInject() {
	std::lock_guard<std::mutex> lock(g_glinject_mutex);
	if(g_glinject != NULL) {
		delete g_glinject;
		g_glinject = NULL;
	}
}

struct Hook {
	const char *name;
	void *address;
};
static Hook hook_table[] = {
	{"glXCreateWindow"     , (void*) &glinject_my_glXCreateWindow},
	{"glXDestroyWindow"    , (void*) &glinject_my_glXDestroyWindow},
	{"XDestroyWindow"      , (void*) &glinject_my_XDestroyWindow},
	{"glXSwapBuffers"      , (void*) &glinject_my_glXSwapBuffers},
	{"glXGetProcAddressARB", (void*) &glinject_my_glXGetProcAddressARB},
	{"XNextEvent"          , (void*) &glinject_my_XNextEvent},
};
static const char* exec_blacklist[] = {
	"ping",
	"/bin/ping",
	"/usr/bin/ping",
};

void FilterEnviron(const char* filename, std::vector<char*>* out, char* const* in) {
	bool filter = false;
	for(unsigned int i = 0; i < sizeof(exec_blacklist) / sizeof(const char*); ++i) {
		if(strcmp(exec_blacklist[i], filename) == 0) {
			filter = true;
			break;
		}
	}
	while(*in != NULL) {
		if(!filter || strncmp(*in, "LD_PRELOAD=", 11) != 0)
			out->push_back(*in);
		++in;
	}
	out->push_back(NULL);
}

GLXWindow glinject_my_glXCreateWindow(Display* dpy, GLXFBConfig config, Window win, const int* attrib_list) {
	GLXWindow res = g_glinject_real_glXCreateWindow(dpy, config, win, attrib_list);
	if(res == 0)
		return 0;
	std::lock_guard<std::mutex> lock(g_glinject_mutex);
	g_glinject->NewGLXFrameGrabber(dpy, win, res);
	return res;
}

void glinject_my_glXDestroyWindow(Display* dpy, GLXWindow win) {
	g_glinject_real_glXDestroyWindow(dpy, win);
	std::lock_guard<std::mutex> lock(g_glinject_mutex);
	g_glinject->DeleteGLXFrameGrabberByDrawable(dpy, win);
}

int glinject_my_XDestroyWindow(Display* dpy, Window win) {
	int res = g_glinject_real_XDestroyWindow(dpy, win);
	std::lock_guard<std::mutex> lock(g_glinject_mutex);
	g_glinject->DeleteGLXFrameGrabberByWindow(dpy, win);
	return res;
}

void glinject_my_glXSwapBuffers(Display* dpy, GLXDrawable drawable) {
	{
		std::lock_guard<std::mutex> lock(g_glinject_mutex);
		GLXFrameGrabber *fg = g_glinject->FindGLXFrameGrabber(dpy, drawable);
		if(fg == NULL) {
			GLINJECT_PRINT("Warning: glXSwapBuffers called without existing frame grabber, creating one assuming window == drawable.");
			fg = g_glinject->NewGLXFrameGrabber(dpy, drawable, drawable);
		}
		fg->GrabFrame();
	}
	g_glinject_real_glXSwapBuffers(dpy, drawable);
}

GLXextFuncPtr glinject_my_glXGetProcAddressARB(const GLubyte *proc_name) {
	for(unsigned int i = 0; i < sizeof(hook_table) / sizeof(Hook); ++i) {
		if(strcmp(hook_table[i].name, (const char*) proc_name) == 0) {
			std::lock_guard<std::mutex> lock(g_glinject_mutex);
			GLINJECT_PRINT("Hooked: glXGetProcAddressARB(" << proc_name << ").");
			return (GLXextFuncPtr) hook_table[i].address;
		}
	}
	return g_glinject_real_glXGetProcAddressARB(proc_name);
}

int glinject_my_XNextEvent(Display* display, XEvent* event_return) {
	int res = g_glinject_real_XNextEvent(display, event_return);
	/*std::lock_guard<std::mutex> lock(g_glinject_mutex);
	if(g_hotkey_info.enabled && event_return->type == KeyPress && event_return->xkey.keycode == g_hotkey_info.keycode
			&& (event_return->xkey.state & ~LockMask & ~Mod2Mask) == g_hotkey_info.modifiers) {
		g_hotkey_pressed = true;
	}*/
	return res;
}

// override existing functions

extern "C" void* dlsym(void* handle, const char* symbol) {
	InitGLInject();
	for(unsigned int i = 0; i < sizeof(hook_table) / sizeof(Hook); ++i) {
		if(strcmp(hook_table[i].name, symbol) == 0) {
			std::lock_guard<std::mutex> lock(g_glinject_mutex);
			GLINJECT_PRINT("Hooked: dlsym(" << symbol << ").");
			return hook_table[i].address;
		}
	}
	return g_glinject_real_dlsym(handle, symbol);
}

extern "C" void* dlvsym(void* handle, const char* symbol, const char* version) {
	InitGLInject();
	for(unsigned int i = 0; i < sizeof(hook_table) / sizeof(Hook); ++i) {
		if(strcmp(hook_table[i].name, symbol) == 0) {
			std::lock_guard<std::mutex> lock(g_glinject_mutex);
			GLINJECT_PRINT("Hooked: dlvsym(" << symbol << "," << version << ").");
			return hook_table[i].address;
		}
	}
	return g_glinject_real_dlvsym(handle, symbol, version);
}

extern "C" int execl(const char* filename, const char* arg, ...) {
	InitGLInject();
	std::vector<char*> args;
	args.push_back((char*) arg);
	va_list vl;
	va_start(vl, arg);
	while(args.back() != NULL) {
		args.push_back(va_arg(vl, char*));
	}
	va_end(vl);
	std::vector<char*> filtered_environ;
	FilterEnviron(filename, &filtered_environ, environ);
	return g_glinject_real_execve(filename, args.data(), filtered_environ.data());
}

extern "C" int execlp(const char* filename, const char* arg, ...) {
	InitGLInject();
	std::vector<char*> args;
	args.push_back((char*) arg);
	va_list vl;
	va_start(vl, arg);
	while(args.back() != NULL) {
		args.push_back(va_arg(vl, char*));
	}
	va_end(vl);
	std::vector<char*> filtered_environ;
	FilterEnviron(filename, &filtered_environ, environ);
	return g_glinject_real_execvpe(filename, args.data(), filtered_environ.data());
}

extern "C" int execle(const char* filename, const char* arg, ...) {
	InitGLInject();
	std::vector<char*> args;
	args.push_back((char*) arg);
	va_list vl;
	va_start(vl, arg);
	while(args.back() != NULL) {
		args.push_back(va_arg(vl, char*));
	}
	char *const *envp = va_arg(vl, char* const*);
	va_end(vl);
	std::vector<char*> filtered_environ;
	FilterEnviron(filename, &filtered_environ, envp);
	return g_glinject_real_execvpe(filename, args.data(), filtered_environ.data());
}

extern "C" int execv(const char* filename, char* const argv[]) {
	InitGLInject();
	std::vector<char*> filtered_environ;
	FilterEnviron(filename, &filtered_environ, environ);
	return g_glinject_real_execve(filename, argv, filtered_environ.data());
}

extern "C" int execve(const char* filename, char* const argv[], char* const envp[]) {
	InitGLInject();
	std::vector<char*> filtered_environ;
	FilterEnviron(filename, &filtered_environ, envp);
	return g_glinject_real_execve(filename, argv, filtered_environ.data());
}

extern "C" int execvp(const char* filename, char* const argv[]) {
	InitGLInject();
	std::vector<char*> filtered_environ;
	FilterEnviron(filename, &filtered_environ, environ);
	return g_glinject_real_execvpe(filename, argv, filtered_environ.data());
}

extern "C" int execvpe(const char* filename, char* const argv[], char* const envp[]) {
	InitGLInject();
	std::vector<char*> filtered_environ;
	FilterEnviron(filename, &filtered_environ, envp);
	return g_glinject_real_execvpe(filename, argv, filtered_environ.data());
}

extern "C" GLXWindow glXCreateWindow(Display* dpy, GLXFBConfig config, Window win, const int* attrib_list) {
	InitGLInject();
	return glinject_my_glXCreateWindow(dpy, config, win, attrib_list);
}

extern "C" void glXDestroyWindow(Display* dpy, GLXWindow win) {
	InitGLInject();
	glinject_my_glXDestroyWindow(dpy, win);
}

extern "C" int XDestroyWindow(Display* dpy, Window win) {
	InitGLInject();
	return glinject_my_XDestroyWindow(dpy, win);
}

extern "C" void glXSwapBuffers(Display* dpy, GLXDrawable drawable) {
	InitGLInject();
	glinject_my_glXSwapBuffers(dpy, drawable);
}

extern "C" GLXextFuncPtr glXGetProcAddressARB(const GLubyte* proc_name) {
	InitGLInject();
	return glinject_my_glXGetProcAddressARB(proc_name);
}

extern "C" int XNextEvent(Display* display, XEvent* event_return) {
	InitGLInject();
	return glinject_my_XNextEvent(display, event_return);
}
