/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "Global.h"

#include "GLInject.h"
#include "GLXFrameGrabber.h"
#include "plthook.h"

#include <dlfcn.h>
#include <link.h>

#include <GL/glx.h>
#include <X11/X.h>

// global variable from the standard library that holds all environment variables
extern char **environ;

// return type of glXGetProcAddressARB
typedef void (*GLXextFuncPtr)(void);

// hook replacement function prototypes
void*         glinject_hook_dlsym(void* handle, const char* symbol);
void*         glinject_hook_dlvsym(void* handle, const char* symbol, const char* version);
int           glinject_hook_execl(const char* filename, const char* arg, ...);
int           glinject_hook_execlp(const char* filename, const char* arg, ...);
int           glinject_hook_execle(const char* filename, const char* arg, ...);
int           glinject_hook_execv(const char* filename, char* const argv[]);
int           glinject_hook_execve(const char* filename, char* const argv[], char* const envp[]);
int           glinject_hook_execvp(const char* filename, char* const argv[]);
int           glinject_hook_execvpe(const char* filename, char* const argv[], char* const envp[]);
GLXWindow     glinject_hook_glXCreateWindow(Display* dpy, GLXFBConfig config, Window win, const int* attrib_list);
void          glinject_hook_glXDestroyWindow(Display* dpy, GLXWindow win);
int           glinject_hook_XDestroyWindow(Display* dpy, Window win);
void          glinject_hook_glXSwapBuffers(Display* dpy, GLXDrawable drawable);
GLXextFuncPtr glinject_hook_glXGetProcAddressARB(const GLubyte *proc_name);

// hook table
struct GLInjectHook {
	const char *name;
	void *address;
};
std::initializer_list<GLInjectHook> glinject_hook_table = {
	{"dlsym"               , (void*) &glinject_hook_dlsym},
	{"dlvsym"              , (void*) &glinject_hook_dlvsym},
	{"execl"               , (void*) &glinject_hook_execl},
	{"execlp"              , (void*) &glinject_hook_execlp},
	{"execle"              , (void*) &glinject_hook_execle},
	{"execv"               , (void*) &glinject_hook_execv},
	{"execve"              , (void*) &glinject_hook_execve},
	{"execvp"              , (void*) &glinject_hook_execvp},
	{"execvpe"             , (void*) &glinject_hook_execvpe},
	{"glXCreateWindow"     , (void*) &glinject_hook_glXCreateWindow},
	{"glXDestroyWindow"    , (void*) &glinject_hook_glXDestroyWindow},
	{"XDestroyWindow"      , (void*) &glinject_hook_XDestroyWindow},
	{"glXSwapBuffers"      , (void*) &glinject_hook_glXSwapBuffers},
	{"glXGetProcAddressARB", (void*) &glinject_hook_glXGetProcAddressARB},
};

// main glinject object and mutex
static GLInject *g_glinject = NULL;
static std::mutex g_glinject_mutex;

// hook initializer
static struct GLInjectHooksInitializer {
	GLInjectHooksInitializer() {

		// get the link table of the glinject library (we can use any global variable for this)
		Dl_info glinject_dlinfo;
		struct link_map *glinject_lmap = NULL;
		if(dladdr1((void*) &glinject_hook_table, &glinject_dlinfo, (void**) &glinject_lmap, RTLD_DL_LINKMAP) == 0) {
			GLINJECT_PRINT("Error: Failed to get link map of glinject library!");
			return;
		}

		// replace PLT entries everywhere except in the glinject library
		void *mainhandle = dlopen(NULL, RTLD_NOW);
		if(mainhandle == NULL) {
			GLINJECT_PRINT("Error: Failed to get main program handle!");
			return;
		}
		struct link_map *lmap = NULL;
		if(dlinfo(mainhandle, RTLD_DI_LINKMAP, &lmap) != 0) {
			GLINJECT_PRINT("Error: Failed to get link map of main program!");
			return;
		}
		while(lmap) {
			if(lmap != glinject_lmap) {
				plthook_t *plthook;
				if(plthook_open_by_linkmap(&plthook, lmap) == 0) {
					for(const GLInjectHook &hook : glinject_hook_table) {
						void *oldfunc;
						if(plthook_replace(plthook, hook.name, hook.address, &oldfunc) == 0) {
							GLINJECT_PRINT("Hooked " << hook.name << " PLT entry in '" << lmap->l_name << "'.");
						}
					}
					plthook_close(plthook);
				}
			}
			lmap = lmap->l_next;
		}
		dlclose(mainhandle);

	}
} glinject_hooks_initializer;

void GLInjectInit();
void GLInjectFree();

void GLInjectInit() {
	if(g_glinject != NULL)
		return;
	g_glinject = new GLInject();
	atexit(GLInjectFree);
}

void GLInjectFree() {
	if(g_glinject != NULL) {
		delete g_glinject;
		g_glinject = NULL;
	}
}

void FilterEnviron(const char* filename, std::vector<char*>* out, char* const* in) {
	const char* exec_blacklist[] = {
		"ping",
		"/bin/ping",
		"/usr/bin/ping",
	};
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

void* glinject_hook_dlsym(void* handle, const char* symbol) {
	const char *str = "(In glinject_hook_dlsym)\n";
	write(2, str, strlen(str));
	for(const GLInjectHook &hook : glinject_hook_table) {
		if(strcmp(hook.name, symbol) == 0) {
			std::lock_guard<std::mutex> lock(g_glinject_mutex);
			GLINJECT_PRINT("Hooked dlsym(" << symbol << ").");
			return hook.address;
		}
	}
	return dlsym(handle, symbol);
}

void* glinject_hook_dlvsym(void* handle, const char* symbol, const char* version) {
	const char *str = "(In glinject_hook_dlvsym)\n";
	write(2, str, strlen(str));
	for(const GLInjectHook &hook : glinject_hook_table) {
		if(strcmp(hook.name, symbol) == 0) {
			std::lock_guard<std::mutex> lock(g_glinject_mutex);
			GLINJECT_PRINT("Hooked dlvsym(" << symbol << ").");
			return hook.address;
		}
	}
	return dlvsym(handle, symbol, version);
}

int glinject_hook_execl(const char* filename, const char* arg, ...) {
	const char *str = "(In glinject_hook_execl)\n";
	write(2, str, strlen(str));
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
	return execve(filename, args.data(), filtered_environ.data());
}

int glinject_hook_execlp(const char* filename, const char* arg, ...) {
	const char *str = "(In glinject_hook_execlp)\n";
	write(2, str, strlen(str));
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
	return execvpe(filename, args.data(), filtered_environ.data());
}

int glinject_hook_execle(const char* filename, const char* arg, ...) {
	const char *str = "(In glinject_hook_execle)\n";
	write(2, str, strlen(str));
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
	return execvpe(filename, args.data(), filtered_environ.data());
}

int glinject_hook_execv(const char* filename, char* const argv[]) {
	const char *str = "(In glinject_hook_execv)\n";
	write(2, str, strlen(str));
	std::vector<char*> filtered_environ;
	FilterEnviron(filename, &filtered_environ, environ);
	return execve(filename, argv, filtered_environ.data());
}

int glinject_hook_execve(const char* filename, char* const argv[], char* const envp[]) {
	const char *str = "(In glinject_hook_execve)\n";
	write(2, str, strlen(str));
	std::vector<char*> filtered_environ;
	FilterEnviron(filename, &filtered_environ, envp);
	return execve(filename, argv, filtered_environ.data());
}

int glinject_hook_execvp(const char* filename, char* const argv[]) {
	const char *str = "(In glinject_hook_execvp)\n";
	write(2, str, strlen(str));
	std::vector<char*> filtered_environ;
	FilterEnviron(filename, &filtered_environ, environ);
	return execvpe(filename, argv, filtered_environ.data());
}

int glinject_hook_execvpe(const char* filename, char* const argv[], char* const envp[]) {
	const char *str = "(In glinject_hook_execvpe)\n";
	write(2, str, strlen(str));
	std::vector<char*> filtered_environ;
	FilterEnviron(filename, &filtered_environ, envp);
	return execvpe(filename, argv, filtered_environ.data());
}

GLXWindow glinject_hook_glXCreateWindow(Display* dpy, GLXFBConfig config, Window win, const int* attrib_list) {
	const char *str = "(In glinject_hook_glXCreateWindow)\n";
	write(2, str, strlen(str));
	GLXWindow res = glXCreateWindow(dpy, config, win, attrib_list);
	if(res == 0)
		return 0;
	{
		std::lock_guard<std::mutex> lock(g_glinject_mutex);
		GLInjectInit();
		g_glinject->NewGLXFrameGrabber(dpy, win, res);
	}
	return res;
}

void glinject_hook_glXDestroyWindow(Display* dpy, GLXWindow win) {
	const char *str = "(In glinject_hook_glXDestroyWindow)\n";
	write(2, str, strlen(str));
	glXDestroyWindow(dpy, win);
	{
		std::lock_guard<std::mutex> lock(g_glinject_mutex);
		GLInjectInit();
		g_glinject->DeleteGLXFrameGrabberByDrawable(dpy, win);
	}
}

int glinject_hook_XDestroyWindow(Display* dpy, Window win) {
	const char *str = "(In glinject_hook_XDestroyWindow)\n";
	write(2, str, strlen(str));
	int res = XDestroyWindow(dpy, win);
	{
		std::lock_guard<std::mutex> lock(g_glinject_mutex);
		GLInjectInit();
		g_glinject->DeleteGLXFrameGrabberByWindow(dpy, win);
	}
	return res;
}

void glinject_hook_glXSwapBuffers(Display* dpy, GLXDrawable drawable) {
	const char *str = "(In glinject_hook_glXSwapBuffers)\n";
	write(2, str, strlen(str));
	{
		std::lock_guard<std::mutex> lock(g_glinject_mutex);
		GLInjectInit();
		GLXFrameGrabber *fg = g_glinject->FindGLXFrameGrabber(dpy, drawable);
		if(fg == NULL) {
			GLINJECT_PRINT("Warning: glXSwapBuffers called without existing frame grabber, creating one assuming window == drawable.");
			fg = g_glinject->NewGLXFrameGrabber(dpy, drawable, drawable);
		}
		fg->GrabFrame();
	}
	glXSwapBuffers(dpy, drawable);
}

GLXextFuncPtr glinject_hook_glXGetProcAddressARB(const GLubyte *proc_name) {
	const char *str = "(In glinject_hook_glXGetProcAddressARB)\n";
	write(2, str, strlen(str));
	for(const GLInjectHook &hook : glinject_hook_table) {
		if(strcmp(hook.name, (const char*) proc_name) == 0) {
			std::lock_guard<std::mutex> lock(g_glinject_mutex);
			GLINJECT_PRINT("Hooked glXGetProcAddressARB(" << proc_name << ").");
			return (GLXextFuncPtr) hook.address;
		}
	}
	return glXGetProcAddressARB(proc_name);
}
