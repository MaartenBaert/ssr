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
void*         glinject_hook_dlopen(const char* filename, int flags);
void*         glinject_hook_dlmopen(Lmid_t lmid, const char* filename, int flags);
void*         glinject_hook_dlsym(void* handle, const char* symbol);
void*         glinject_hook_dlvsym(void* handle, const char* symbol, const char* version);
int           glinject_hook_execl(const char* filename, const char* arg, ...);
int           glinject_hook_execlp(const char* filename, const char* arg, ...);
int           glinject_hook_execle(const char* filename, const char* arg, ...);
int           glinject_hook_execv(const char* filename, char* const argv[]);
int           glinject_hook_execvp(const char* filename, char* const argv[]);
int           glinject_hook_execve(const char* filename, char* const argv[], char* const envp[]);
int           glinject_hook_execvpe(const char* filename, char* const argv[], char* const envp[]);
GLXWindow     glinject_hook_glXCreateWindow(Display* dpy, GLXFBConfig config, Window win, const int* attrib_list);
void          glinject_hook_glXDestroyWindow(Display* dpy, GLXWindow win);
int           glinject_hook_XDestroyWindow(Display* dpy, Window win);
void          glinject_hook_glXSwapBuffers(Display* dpy, GLXDrawable drawable);
GLXextFuncPtr glinject_hook_glXGetProcAddress(const GLubyte *proc_name);
GLXextFuncPtr glinject_hook_glXGetProcAddressARB(const GLubyte *proc_name);

// hook table
struct GLInjectHook {
	const char *name;
	void *address;
};
std::initializer_list<GLInjectHook> glinject_hook_table = {
	{"dlopen"              , (void*) &glinject_hook_dlopen},
	{"dlmopen"             , (void*) &glinject_hook_dlmopen},
	{"dlsym"               , (void*) &glinject_hook_dlsym},
	{"dlvsym"              , (void*) &glinject_hook_dlvsym},
	{"execl"               , (void*) &glinject_hook_execl},
	{"execlp"              , (void*) &glinject_hook_execlp},
	{"execle"              , (void*) &glinject_hook_execle},
	{"execv"               , (void*) &glinject_hook_execv},
	{"execvp"              , (void*) &glinject_hook_execvp},
	{"execve"              , (void*) &glinject_hook_execve},
	{"execvpe"             , (void*) &glinject_hook_execvpe},
	{"glXCreateWindow"     , (void*) &glinject_hook_glXCreateWindow},
	{"glXDestroyWindow"    , (void*) &glinject_hook_glXDestroyWindow},
	{"XDestroyWindow"      , (void*) &glinject_hook_XDestroyWindow},
	{"glXSwapBuffers"      , (void*) &glinject_hook_glXSwapBuffers},
	{"glXGetProcAddress"   , (void*) &glinject_hook_glXGetProcAddress},
	{"glXGetProcAddressARB", (void*) &glinject_hook_glXGetProcAddressARB},
};

// list of executables that should not be hooked
const char* g_glinject_filtered_execs[] = {
	"ping",
	"/bin/ping",
	"/usr/bin/ping",
};

// list of libraries that should not be hooked
const char* g_glinject_filtered_libs[] = {
	"libGL.so",
	"libGLdispatch.so",
	"libGLESv1.so",
	"libGLESv1_", // vendor-specific libraries such as libGLESv1_CM_nvidia.so
	"libGLESv2.so",
	"libGLESv2_", // vendor-specific libraries such as libGLESv2_nvidia.so
	"libGLU.so",
	"libGLX.so",
	"libGLX_", // vendor-specific libraries such as libGLX_nvidia.so
	"libnvidia-", // more nvidia libraries including libnvidia-glcore.so
	"libOpenGL.so",
	"libX11.so",
};

bool GLInjectShouldFilterExec(const char* filename) {
	for(unsigned int i = 0; i < sizeof(g_glinject_filtered_execs) / sizeof(const char*); ++i) {
		if(strcmp(g_glinject_filtered_execs[i], filename) == 0) {
			return true;
		}
	}
	return false;
}

bool GLInjectShouldFilterLib(const char* filename) {
	if(filename[0] == '\0')
		return false; // empty string means the main program
	const char *slash = strrchr(filename, '/');
	if(slash == NULL)
		return true; // not a normal library
	for(unsigned int i = 0; i < sizeof(g_glinject_filtered_libs) / sizeof(const char*); ++i) {
		if(strncmp(slash + 1, g_glinject_filtered_libs[i], strlen(g_glinject_filtered_libs[i])) == 0)
			return true;
	}
	return false;
}

std::vector<char*> GLInjectFilterEnv(char* const* envp) {
	std::vector<char*> out;
	while(*envp != NULL) {
		if(strncmp(*envp, "LD_PRELOAD=", 11) != 0)
			out.push_back(*envp);
		++envp;
	}
	out.push_back(NULL);
	return out;
}

bool GLInjectHookDebug_Init() {
	const char *ssr_hook_debug = getenv("SSR_HOOK_DEBUG");
	if(ssr_hook_debug != NULL && atoi(ssr_hook_debug) > 0) {
		GLINJECT_PRINT("Hook debugging enabled.");
		return true;
	} else {
		return false;
	}
}
bool GLInjectHookAdvanced_Init() {
	const char *ssr_hook_advanced = getenv("SSR_HOOK_ADVANCED");
	if(ssr_hook_advanced != NULL && atoi(ssr_hook_advanced) > 0) {
		return true;
	} else {
		return false;
	}
}

bool GLInjectHookDebug() {
	static bool debug = GLInjectHookDebug_Init();
	return debug;
}
bool GLInjectHookAdvanced() {
	static bool advanced = GLInjectHookAdvanced_Init();
	return advanced;
}

// PLT hooking (called once for each object)
void GLInjectHookByLinkMap(struct link_map* lmap) {
	bool advanced = GLInjectHookAdvanced();
	plthook_t *plthook;
	if(plthook_open_by_linkmap(&plthook, lmap) == 0) {
		if(GLInjectHookDebug())
			GLINJECT_PRINT("    dlsym = " << (void*) &dlsym);
		for(const GLInjectHook &hook : glinject_hook_table) {
			void *expect = dlsym(RTLD_DEFAULT, hook.name);
			if(GLInjectHookDebug())
				GLINJECT_PRINT("    dlsym(" << hook.name << ") = " << expect);

			Dl_info target_dlinfo;
			struct link_map *target_lmap = NULL;
			if(dladdr1(expect, &target_dlinfo, (void**) &target_lmap, RTLD_DL_LINKMAP) != 0) {
				if(GLInjectHookDebug())
					GLINJECT_PRINT("        -> " << target_dlinfo.dli_fname << " : " << ((target_dlinfo.dli_sname)? target_dlinfo.dli_sname : "(no symbol)"));
			}

			void *oldfunc;
			int res;
			if(advanced)
				res = plthook_replace_adv(plthook, hook.name, hook.address, &oldfunc, expect);
			else
				res = plthook_replace(plthook, hook.name, hook.address, &oldfunc);
			if(res == 0) {
				if(GLInjectHookDebug())
					GLINJECT_PRINT("        Hooked " << hook.name << " PLT entry in '" << lmap->l_name << "', was " << oldfunc << ", expected " << expect << ".");
			}
		}
		plthook_close(plthook);
	}
}
void GLInjectHookByHandle(void* handle) {
	struct link_map *lmap = NULL;
	if(dlinfo(handle, RTLD_DI_LINKMAP, &lmap) != 0) {
		GLINJECT_PRINT("Error: Failed to get link map from library handle!");
	} else {
		GLInjectHookByLinkMap(lmap);
	}
}
void GLInjectHookAll() {

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
		if(GLInjectHookDebug())
			GLINJECT_PRINT("Link map " << lmap << " = '" << lmap->l_name << "'.");
		if(lmap != glinject_lmap && !GLInjectShouldFilterLib(lmap->l_name)) {
			GLInjectHookByLinkMap(lmap);
		} else {
			if(GLInjectHookDebug())
				GLINJECT_PRINT("      (filtered)")
		}
		lmap = lmap->l_next;
	}
	dlclose(mainhandle);

}

static std::mutex g_hook_mutex;

// hook initializer
static struct GLInjectHooksInitializer {
	GLInjectHooksInitializer() {
		if(GLInjectHookDebug())
			GLINJECT_PRINT("Initializing hooks ...");
		std::lock_guard<std::mutex> lock(g_hook_mutex);
		GLInjectHookAll();
	}
	~GLInjectHooksInitializer() {
		// GLInjectHookAll();
	}
} glinject_hooks_initializer;

// main glinject object and mutex
static GLInject *g_glinject = NULL;
static std::mutex g_glinject_mutex;

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

void* glinject_hook_dlopen(const char* filename, int flags) {
	// const char *str = "(In glinject_hook_dlopen)\n";
	// write(2, str, strlen(str));
	if(GLInjectHookDebug())
		GLINJECT_PRINT("Captured glinject_hook_dlopen(" << filename << ")");
	void *res = dlopen(filename, flags);
	if(res != NULL) {
		if(GLInjectHookDebug())
			GLINJECT_PRINT("Refreshing hooks ...");
		std::lock_guard<std::mutex> lock(g_hook_mutex);
		GLInjectHookAll();
		//GLInjectHookByHandle(res);
	}
	return res;
}

void* glinject_hook_dlmopen(Lmid_t lmid, const char* filename, int flags) {
	// const char *str = "(In glinject_hook_dlmopen)\n";
	// write(2, str, strlen(str));
	if(GLInjectHookDebug())
		GLINJECT_PRINT("Captured glinject_hook_dlmopen(" << filename << ")");
	void *res = dlmopen(lmid, filename, flags);
	if(res != NULL) {
		if(GLInjectHookDebug())
			GLINJECT_PRINT("Refreshing hooks ...");
		std::lock_guard<std::mutex> lock(g_hook_mutex);
		GLInjectHookAll();
		//GLInjectHookByHandle(res);
	}
	return res;
}

void* glinject_hook_dlsym(void* handle, const char* symbol) {
	// const char *str = "(In glinject_hook_dlsym)\n";
	// write(2, str, strlen(str));
	for(const GLInjectHook &hook : glinject_hook_table) {
		if(strcmp(hook.name, symbol) == 0) {
			if(GLInjectHookDebug())
				GLINJECT_PRINT("Hooked dlsym(" << symbol << ").");
			return hook.address;
		}
	}
	return dlsym(handle, symbol);
}

void* glinject_hook_dlvsym(void* handle, const char* symbol, const char* version) {
	// const char *str = "(In glinject_hook_dlvsym)\n";
	// write(2, str, strlen(str));
	for(const GLInjectHook &hook : glinject_hook_table) {
		if(strcmp(hook.name, symbol) == 0) {
			if(GLInjectHookDebug())
				GLINJECT_PRINT("Hooked dlvsym(" << symbol << ").");
			return hook.address;
		}
	}
	return dlvsym(handle, symbol, version);
}

int glinject_hook_execl(const char* filename, const char* arg, ...) {
	// const char *str = "(In glinject_hook_execl)\n";
	// write(2, str, strlen(str));
	std::vector<char*> args;
	args.push_back((char*) arg);
	va_list vl;
	va_start(vl, arg);
	while(args.back() != NULL) {
		args.push_back(va_arg(vl, char*));
	}
	va_end(vl);
	if(GLInjectShouldFilterExec(filename)) {
		std::vector<char*> filtered_env = GLInjectFilterEnv(environ);
		return execve(filename, args.data(), filtered_env.data());
	} else {
		return execv(filename, args.data());
	}
}

int glinject_hook_execlp(const char* filename, const char* arg, ...) {
	// const char *str = "(In glinject_hook_execlp)\n";
	// write(2, str, strlen(str));
	std::vector<char*> args;
	args.push_back((char*) arg);
	va_list vl;
	va_start(vl, arg);
	while(args.back() != NULL) {
		args.push_back(va_arg(vl, char*));
	}
	va_end(vl);
	if(GLInjectShouldFilterExec(filename)) {
		std::vector<char*> filtered_env = GLInjectFilterEnv(environ);
		return execvpe(filename, args.data(), filtered_env.data());
	} else {
		return execvp(filename, args.data());
	}
}

int glinject_hook_execle(const char* filename, const char* arg, ...) {
	// const char *str = "(In glinject_hook_execle)\n";
	// write(2, str, strlen(str));
	std::vector<char*> args;
	args.push_back((char*) arg);
	va_list vl;
	va_start(vl, arg);
	while(args.back() != NULL) {
		args.push_back(va_arg(vl, char*));
	}
	char *const *envp = va_arg(vl, char* const*);
	va_end(vl);
	if(GLInjectShouldFilterExec(filename)) {
		std::vector<char*> filtered_env = GLInjectFilterEnv(envp);
		return execve(filename, args.data(), filtered_env.data());
	} else {
		return execve(filename, args.data(), envp);
	}
}

int glinject_hook_execv(const char* filename, char* const argv[]) {
	// const char *str = "(In glinject_hook_execv)\n";
	// write(2, str, strlen(str));
	if(GLInjectShouldFilterExec(filename)) {
		std::vector<char*> filtered_env = GLInjectFilterEnv(environ);
		return execve(filename, argv, filtered_env.data());
	} else {
		return execv(filename, argv);
	}
}

int glinject_hook_execvp(const char* filename, char* const argv[]) {
	// const char *str = "(In glinject_hook_execvp)\n";
	// write(2, str, strlen(str));
	if(GLInjectShouldFilterExec(filename)) {
		std::vector<char*> filtered_env = GLInjectFilterEnv(environ);
		return execvpe(filename, argv, filtered_env.data());
	} else {
		return execvp(filename, argv);
	}
}

int glinject_hook_execve(const char* filename, char* const argv[], char* const envp[]) {
	// const char *str = "(In glinject_hook_execve)\n";
	// write(2, str, strlen(str));
	if(GLInjectShouldFilterExec(filename)) {
		std::vector<char*> filtered_env = GLInjectFilterEnv(envp);
		return execve(filename, argv, filtered_env.data());
	} else {
		return execve(filename, argv, envp);
	}
}

int glinject_hook_execvpe(const char* filename, char* const argv[], char* const envp[]) {
	// const char *str = "(In glinject_hook_execvpe)\n";
	// write(2, str, strlen(str));
	if(GLInjectShouldFilterExec(filename)) {
		std::vector<char*> filtered_env = GLInjectFilterEnv(envp);
		return execvpe(filename, argv, filtered_env.data());
	} else {
		return execvpe(filename, argv, envp);
	}
}

GLXWindow glinject_hook_glXCreateWindow(Display* dpy, GLXFBConfig config, Window win, const int* attrib_list) {
	// const char *str = "(In glinject_hook_glXCreateWindow)\n";
	// write(2, str, strlen(str));
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
	// const char *str = "(In glinject_hook_glXDestroyWindow)\n";
	// write(2, str, strlen(str));
	glXDestroyWindow(dpy, win);
	{
		std::lock_guard<std::mutex> lock(g_glinject_mutex);
		GLInjectInit();
		g_glinject->DeleteGLXFrameGrabberByDrawable(dpy, win);
	}
}

int glinject_hook_XDestroyWindow(Display* dpy, Window win) {
	// const char *str = "(In glinject_hook_XDestroyWindow)\n";
	// write(2, str, strlen(str));
	int res = XDestroyWindow(dpy, win);
	{
		std::lock_guard<std::mutex> lock(g_glinject_mutex);
		GLInjectInit();
		g_glinject->DeleteGLXFrameGrabberByWindow(dpy, win);
	}
	return res;
}

void glinject_hook_glXSwapBuffers(Display* dpy, GLXDrawable drawable) {
	// const char *str = "(In glinject_hook_glXSwapBuffers)\n";
	// write(2, str, strlen(str));
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

GLXextFuncPtr glinject_hook_glXGetProcAddress(const GLubyte *proc_name) {
	// const char *str = "(In glinject_hook_glXGetProcAddress)\n";
	// write(2, str, strlen(str));
	for(const GLInjectHook &hook : glinject_hook_table) {
		if(strcmp(hook.name, (const char*) proc_name) == 0) {
			std::lock_guard<std::mutex> lock(g_glinject_mutex);
			if(GLInjectHookDebug())
				GLINJECT_PRINT("Hooked glXGetProcAddress(" << proc_name << ").");
			return (GLXextFuncPtr) hook.address;
		}
	}
	return glXGetProcAddress(proc_name);
}

GLXextFuncPtr glinject_hook_glXGetProcAddressARB(const GLubyte *proc_name) {
	// const char *str = "(In glinject_hook_glXGetProcAddressARB)\n";
	// write(2, str, strlen(str));
	for(const GLInjectHook &hook : glinject_hook_table) {
		if(strcmp(hook.name, (const char*) proc_name) == 0) {
			std::lock_guard<std::mutex> lock(g_glinject_mutex);
			if(GLInjectHookDebug())
				GLINJECT_PRINT("Hooked glXGetProcAddressARB(" << proc_name << ").");
			return (GLXextFuncPtr) hook.address;
		}
	}
	return glXGetProcAddressARB(proc_name);
}
