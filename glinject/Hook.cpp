/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "Global.h"

#include "GLInject.h"
#include "GLXFrameGrabber.h"
#include "VKFrameGrabber.h"
#include "plthook.h"

#include <dlfcn.h>
#include <link.h>
#include <map>

#include <GL/glx.h>
#include <X11/Xlib.h>
#include <X11/X.h>
#include <xcb/xcb.h>

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_xlib.h>
#include <vulkan/vulkan_xcb.h>

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

VkResult           glinject_hook_vkCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
VkResult           glinject_hook_vkCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice);
void               glinject_hook_vkDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator);
VkResult           glinject_hook_vkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);
void               glinject_hook_vkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator);
VkResult           glinject_hook_vkQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo);
PFN_vkVoidFunction glinject_hook_vkGetInstanceProcAddr(VkInstance instance, const char* pName);
PFN_vkVoidFunction glinject_hook_vkGetDeviceProcAddr(VkDevice device, const char* pName);
VkResult           glinject_hook_vkCreateXlibSurfaceKHR(VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
VkResult           glinject_hook_vkCreateXcbSurfaceKHR(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

// hook table
struct GLInjectHook {
	const char *name;
	void *address;
};
std::initializer_list<GLInjectHook> glinject_hook_table = {
	{"dlopen"                , (void*) &glinject_hook_dlopen},
	{"dlmopen"               , (void*) &glinject_hook_dlmopen},
	{"dlsym"                 , (void*) &glinject_hook_dlsym},
	{"dlvsym"                , (void*) &glinject_hook_dlvsym},
	{"execl"                 , (void*) &glinject_hook_execl},
	{"execlp"                , (void*) &glinject_hook_execlp},
	{"execle"                , (void*) &glinject_hook_execle},
	{"execv"                 , (void*) &glinject_hook_execv},
	{"execvp"                , (void*) &glinject_hook_execvp},
	{"execve"                , (void*) &glinject_hook_execve},
	{"execvpe"               , (void*) &glinject_hook_execvpe},
	{"glXCreateWindow"       , (void*) &glinject_hook_glXCreateWindow},
	{"glXDestroyWindow"      , (void*) &glinject_hook_glXDestroyWindow},
	{"XDestroyWindow"        , (void*) &glinject_hook_XDestroyWindow},
	{"glXSwapBuffers"        , (void*) &glinject_hook_glXSwapBuffers},
	{"glXGetProcAddress"     , (void*) &glinject_hook_glXGetProcAddress},
	{"glXGetProcAddressARB"  , (void*) &glinject_hook_glXGetProcAddressARB},
	{"vkCreateInstance"      , (void*) &glinject_hook_vkCreateInstance},
	{"vkCreateDevice"        , (void*) &glinject_hook_vkCreateDevice},
	{"vkDestroyDevice"       , (void*) &glinject_hook_vkDestroyDevice},
	{"vkCreateSwapchainKHR"  , (void*) &glinject_hook_vkCreateSwapchainKHR},
	{"vkDestroySwapchainKHR" , (void*) &glinject_hook_vkDestroySwapchainKHR},
	{"vkQueuePresentKHR"     , (void*) &glinject_hook_vkQueuePresentKHR},
	{"vkGetInstanceProcAddr" , (void*) &glinject_hook_vkGetInstanceProcAddr},
	{"vkGetDeviceProcAddr"   , (void*) &glinject_hook_vkGetDeviceProcAddr},
	{"vkCreateXlibSurfaceKHR", (void*) &glinject_hook_vkCreateXlibSurfaceKHR},
	{"vkCreateXcbSurfaceKHR" , (void*) &glinject_hook_vkCreateXcbSurfaceKHR},
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
	"libvulkan.so",
	"libvulkan_",
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

static thread_local bool g_in_real_resolve = false;

void* glinject_hook_dlopen(const char* filename, int flags) {
	if(GLInjectHookDebug())
		GLINJECT_PRINT("Captured glinject_hook_dlopen(" << filename << ")");
	void *res = dlopen(filename, flags);
	if(res != NULL) {
		if(GLInjectHookDebug())
			GLINJECT_PRINT("Refreshing hooks ...");
		std::lock_guard<std::mutex> lock(g_hook_mutex);
		GLInjectHookAll();
	}
	return res;
}

void* glinject_hook_dlmopen(Lmid_t lmid, const char* filename, int flags) {
	if(GLInjectHookDebug())
		GLINJECT_PRINT("Captured glinject_hook_dlmopen(" << filename << ")");
	void *res = dlmopen(lmid, filename, flags);
	if(res != NULL) {
		if(GLInjectHookDebug())
			GLINJECT_PRINT("Refreshing hooks ...");
		std::lock_guard<std::mutex> lock(g_hook_mutex);
		GLInjectHookAll();
	}
	return res;
}

void* glinject_hook_dlsym(void* handle, const char* symbol) {
	if(!g_in_real_resolve) {
		for(const GLInjectHook &hook : glinject_hook_table) {
			if(strcmp(hook.name, symbol) == 0) {
				if(GLInjectHookDebug())
					GLINJECT_PRINT("Hooked dlsym(" << symbol << ").");
				return hook.address;
			}
		}
	}
	return dlsym(handle, symbol);
}

void* glinject_hook_dlvsym(void* handle, const char* symbol, const char* version) {
	if(!g_in_real_resolve) {
		for(const GLInjectHook &hook : glinject_hook_table) {
			if(strcmp(hook.name, symbol) == 0) {
				if(GLInjectHookDebug())
					GLINJECT_PRINT("Hooked dlvsym(" << symbol << ").");
				return hook.address;
			}
		}
	}
	return dlvsym(handle, symbol, version);
}

int glinject_hook_execl(const char* filename, const char* arg, ...) {
	va_list args;
	va_start(args, arg);
	std::vector<const char*> argv;
	argv.push_back(arg);
	while(argv.back() != NULL) {
		argv.push_back(va_arg(args, const char*));
	}
	va_end(args);
	return glinject_hook_execv(filename, (char* const*) argv.data());
}

int glinject_hook_execlp(const char* filename, const char* arg, ...) {
	va_list args;
	va_start(args, arg);
	std::vector<const char*> argv;
	argv.push_back(arg);
	while(argv.back() != NULL) {
		argv.push_back(va_arg(args, const char*));
	}
	va_end(args);
	return glinject_hook_execvp(filename, (char* const*) argv.data());
}

int glinject_hook_execle(const char* filename, const char* arg, ...) {
	va_list args;
	va_start(args, arg);
	std::vector<const char*> argv;
	argv.push_back(arg);
	while(argv.back() != NULL) {
		argv.push_back(va_arg(args, const char*));
	}
	char* const* envp = va_arg(args, char* const*);
	va_end(args);
	return glinject_hook_execve(filename, (char* const*) argv.data(), envp);
}

int glinject_hook_execv(const char* filename, char* const argv[]) {
	if(GLInjectShouldFilterExec(filename)) {
		std::vector<char*> filtered_env = GLInjectFilterEnv(environ);
		return execve(filename, argv, filtered_env.data());
	} else {
		return execv(filename, argv);
	}
}

int glinject_hook_execvp(const char* filename, char* const argv[]) {
	if(GLInjectShouldFilterExec(filename)) {
		std::vector<char*> filtered_env = GLInjectFilterEnv(environ);
		return execvpe(filename, argv, filtered_env.data());
	} else {
		return execvp(filename, argv);
	}
}

int glinject_hook_execve(const char* filename, char* const argv[], char* const envp[]) {
	if(GLInjectShouldFilterExec(filename)) {
		std::vector<char*> filtered_env = GLInjectFilterEnv(envp);
		return execve(filename, argv, filtered_env.data());
	} else {
		return execve(filename, argv, envp);
	}
}

int glinject_hook_execvpe(const char* filename, char* const argv[], char* const envp[]) {
	if(GLInjectShouldFilterExec(filename)) {
		std::vector<char*> filtered_env = GLInjectFilterEnv(envp);
		return execvpe(filename, argv, filtered_env.data());
	} else {
		return execvpe(filename, argv, envp);
	}
}

GLXWindow glinject_hook_glXCreateWindow(Display* dpy, GLXFBConfig config, Window win, const int* attrib_list) {
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
	glXDestroyWindow(dpy, win);
	{
		std::lock_guard<std::mutex> lock(g_glinject_mutex);
		GLInjectInit();
		g_glinject->DeleteGLXFrameGrabberByDrawable(dpy, win);
	}
}

int glinject_hook_XDestroyWindow(Display* dpy, Window win) {
	int res = XDestroyWindow(dpy, win);
	{
		std::lock_guard<std::mutex> lock(g_glinject_mutex);
		GLInjectInit();
		g_glinject->DeleteGLXFrameGrabberByWindow(dpy, win);
	}
	return res;
}

void glinject_hook_glXSwapBuffers(Display* dpy, GLXDrawable drawable) {
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

// -----------------------------------------------------------------------------
// Vulkan Hooks
// -----------------------------------------------------------------------------

static void* g_vulkan_handle = NULL;
static PFN_vkGetInstanceProcAddr g_real_vkGetInstanceProcAddr = NULL;
static PFN_vkGetDeviceProcAddr   g_real_vkGetDeviceProcAddr = NULL;
static PFN_vkCreateInstance      g_real_vkCreateInstance = NULL;
static PFN_vkCreateDevice        g_real_vkCreateDevice = NULL;
static PFN_vkDestroyDevice       g_real_vkDestroyDevice = NULL;
static PFN_vkCreateSwapchainKHR  g_real_vkCreateSwapchainKHR = NULL;
static PFN_vkDestroySwapchainKHR g_real_vkDestroySwapchainKHR = NULL;
static PFN_vkQueuePresentKHR     g_real_vkQueuePresentKHR = NULL;
static PFN_vkCreateXlibSurfaceKHR g_real_vkCreateXlibSurfaceKHR = NULL;
static PFN_vkCreateXcbSurfaceKHR  g_real_vkCreateXcbSurfaceKHR = NULL;

static void VulkanInitPointers() {
	if(g_vulkan_handle == NULL) {
		g_vulkan_handle = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
		if(!g_vulkan_handle)
			g_vulkan_handle = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL);
	}
	g_in_real_resolve = true;
#define RESOLVE_REAL_VK(name) \
	if(!g_real_##name) { \
		if(g_vulkan_handle) g_real_##name = (PFN_##name) dlsym(g_vulkan_handle, #name); \
		if(!g_real_##name) g_real_##name = (PFN_##name) dlsym(RTLD_NEXT, #name); \
	}

	RESOLVE_REAL_VK(vkGetInstanceProcAddr);
	RESOLVE_REAL_VK(vkGetDeviceProcAddr);
	RESOLVE_REAL_VK(vkCreateInstance);
	RESOLVE_REAL_VK(vkCreateDevice);
	RESOLVE_REAL_VK(vkDestroyDevice);
	RESOLVE_REAL_VK(vkCreateSwapchainKHR);
	RESOLVE_REAL_VK(vkDestroySwapchainKHR);
	RESOLVE_REAL_VK(vkQueuePresentKHR);
	RESOLVE_REAL_VK(vkCreateXlibSurfaceKHR);
	RESOLVE_REAL_VK(vkCreateXcbSurfaceKHR);
	g_in_real_resolve = false;
}

struct VKDeviceInfo {
	VkPhysicalDevice physical_device;
	uint32_t queue_family_index;
	VKDeviceInfo(VkPhysicalDevice pd = VK_NULL_HANDLE, uint32_t q = 0) : physical_device(pd), queue_family_index(q) {}
};
static std::map<VkDevice, VKDeviceInfo> g_vk_devices;
static std::mutex g_vk_mutex;

struct VKSurfaceInfo {
	Display *display;
	Window window;
	VKSurfaceInfo(Display *d = NULL, Window w = 0) : display(d), window(w) {}
};
static std::map<VkSurfaceKHR, VKSurfaceInfo> g_vk_surfaces;
static Display *g_x11_shared_display = NULL;

VkResult glinject_hook_vkCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) {
	VulkanInitPointers();
	if(!g_real_vkCreateInstance)
		return VK_ERROR_INITIALIZATION_FAILED;
	return g_real_vkCreateInstance(pCreateInfo, pAllocator, pInstance);
}

VkResult glinject_hook_vkCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) {
	VulkanInitPointers();
	PFN_vkCreateDevice real_fn = g_real_vkCreateDevice;
	if(!real_fn) {
		g_in_real_resolve = true;
		real_fn = (PFN_vkCreateDevice) dlsym(RTLD_NEXT, "vkCreateDevice");
		g_in_real_resolve = false;
	}
	if(!real_fn)
		return VK_ERROR_INITIALIZATION_FAILED;

	VkResult res = real_fn(physicalDevice, pCreateInfo, pAllocator, pDevice);
	if(res == VK_SUCCESS && pDevice != NULL) {
		uint32_t qfam = 0;
		if(pCreateInfo != NULL && pCreateInfo->queueCreateInfoCount > 0 && pCreateInfo->pQueueCreateInfos != NULL)
			qfam = pCreateInfo->pQueueCreateInfos[0].queueFamilyIndex;
		std::lock_guard<std::mutex> lock(g_vk_mutex);
		g_vk_devices[*pDevice] = VKDeviceInfo(physicalDevice, qfam);
	}
	return res;
}

void glinject_hook_vkDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {
	VulkanInitPointers();
	{
		std::lock_guard<std::mutex> lock(g_vk_mutex);
		g_vk_devices.erase(device);
	}
	{
		std::lock_guard<std::mutex> lock(g_glinject_mutex);
		if(g_glinject != NULL)
			g_glinject->DeleteVKFrameGrabberByDevice(device);
	}
	if(g_real_vkDestroyDevice)
		g_real_vkDestroyDevice(device, pAllocator);
}

VkResult glinject_hook_vkCreateXlibSurfaceKHR(VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	VulkanInitPointers();
	PFN_vkCreateXlibSurfaceKHR real_fn = g_real_vkCreateXlibSurfaceKHR;
	if(!real_fn && g_real_vkGetInstanceProcAddr)
		real_fn = (PFN_vkCreateXlibSurfaceKHR) g_real_vkGetInstanceProcAddr(instance, "vkCreateXlibSurfaceKHR");
	if(!real_fn)
		return VK_ERROR_INITIALIZATION_FAILED;

	VkResult res = real_fn(instance, pCreateInfo, pAllocator, pSurface);
	if(res == VK_SUCCESS && pSurface != NULL && pCreateInfo != NULL) {
		std::lock_guard<std::mutex> lock(g_vk_mutex);
		g_vk_surfaces[*pSurface] = VKSurfaceInfo(pCreateInfo->dpy, pCreateInfo->window);
	}
	return res;
}

VkResult glinject_hook_vkCreateXcbSurfaceKHR(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	VulkanInitPointers();
	PFN_vkCreateXcbSurfaceKHR real_fn = g_real_vkCreateXcbSurfaceKHR;
	if(!real_fn && g_real_vkGetInstanceProcAddr)
		real_fn = (PFN_vkCreateXcbSurfaceKHR) g_real_vkGetInstanceProcAddr(instance, "vkCreateXcbSurfaceKHR");
	if(!real_fn)
		return VK_ERROR_INITIALIZATION_FAILED;

	VkResult res = real_fn(instance, pCreateInfo, pAllocator, pSurface);
	if(res == VK_SUCCESS && pSurface != NULL && pCreateInfo != NULL) {
		std::lock_guard<std::mutex> lock(g_vk_mutex);
		if(g_x11_shared_display == NULL)
			g_x11_shared_display = XOpenDisplay(NULL);
		g_vk_surfaces[*pSurface] = VKSurfaceInfo(g_x11_shared_display, (Window) pCreateInfo->window);
	}
	return res;
}

VkResult glinject_hook_vkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) {
	VulkanInitPointers();
	PFN_vkCreateSwapchainKHR real_fn = g_real_vkCreateSwapchainKHR;
	if(!real_fn && g_real_vkGetDeviceProcAddr)
		real_fn = (PFN_vkCreateSwapchainKHR) g_real_vkGetDeviceProcAddr(device, "vkCreateSwapchainKHR");
	if(!real_fn)
		return VK_ERROR_INITIALIZATION_FAILED;

	VkSwapchainCreateInfoKHR modified = *pCreateInfo;
	modified.imageUsage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
	VkResult res = real_fn(device, &modified, pAllocator, pSwapchain);
	if(res != VK_SUCCESS) {
		// Fallback to original createInfo if driver rejected modified imageUsage
		res = real_fn(device, pCreateInfo, pAllocator, pSwapchain);
	}

	if(res == VK_SUCCESS && pSwapchain != NULL) {
		VKDeviceInfo devInfo;
		VKSurfaceInfo surfInfo;
		{
			std::lock_guard<std::mutex> lock(g_vk_mutex);
			auto it_dev = g_vk_devices.find(device);
			if(it_dev != g_vk_devices.end())
				devInfo = it_dev->second;
			auto it_surf = g_vk_surfaces.find(pCreateInfo->surface);
			if(it_surf != g_vk_surfaces.end())
				surfInfo = it_surf->second;
		}
		std::lock_guard<std::mutex> lock(g_glinject_mutex);
		GLInjectInit();
		g_glinject->NewVKFrameGrabber(device, devInfo.physical_device, devInfo.queue_family_index, *pSwapchain, pCreateInfo->imageFormat, pCreateInfo->imageExtent.width, pCreateInfo->imageExtent.height, surfInfo.display, surfInfo.window);
	}
	return res;
}

void glinject_hook_vkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) {
	VulkanInitPointers();
	{
		std::lock_guard<std::mutex> lock(g_glinject_mutex);
		if(g_glinject != NULL)
			g_glinject->DeleteVKFrameGrabberBySwapchain(swapchain);
	}
	PFN_vkDestroySwapchainKHR real_fn = g_real_vkDestroySwapchainKHR;
	if(!real_fn && g_real_vkGetDeviceProcAddr)
		real_fn = (PFN_vkDestroySwapchainKHR) g_real_vkGetDeviceProcAddr(device, "vkDestroySwapchainKHR");
	if(real_fn)
		real_fn(device, swapchain, pAllocator);
}

VkResult glinject_hook_vkQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) {
	VulkanInitPointers();
	if(pPresentInfo != NULL && pPresentInfo->pSwapchains != NULL && pPresentInfo->pImageIndices != NULL) {
		std::lock_guard<std::mutex> lock(g_glinject_mutex);
		GLInjectInit();
		for(uint32_t i = 0; i < pPresentInfo->swapchainCount; ++i) {
			VKFrameGrabber *fg = g_glinject->FindVKFrameGrabber(pPresentInfo->pSwapchains[i]);
			if(fg != NULL) {
				fg->GrabFrame(queue, pPresentInfo->pImageIndices[i]);
			}
		}
	}
	PFN_vkQueuePresentKHR real_fn = g_real_vkQueuePresentKHR;
	if(!real_fn) {
		g_in_real_resolve = true;
		real_fn = (PFN_vkQueuePresentKHR) dlsym(RTLD_NEXT, "vkQueuePresentKHR");
		g_in_real_resolve = false;
	}
	if(!real_fn)
		return VK_ERROR_INITIALIZATION_FAILED;
	return real_fn(queue, pPresentInfo);
}

PFN_vkVoidFunction glinject_hook_vkGetInstanceProcAddr(VkInstance instance, const char* pName) {
	VulkanInitPointers();
	if(pName != NULL) {
		if(strcmp(pName, "vkGetInstanceProcAddr") == 0) return (PFN_vkVoidFunction) &glinject_hook_vkGetInstanceProcAddr;
		if(strcmp(pName, "vkGetDeviceProcAddr") == 0) return (PFN_vkVoidFunction) &glinject_hook_vkGetDeviceProcAddr;
		if(strcmp(pName, "vkCreateInstance") == 0) return (PFN_vkVoidFunction) &glinject_hook_vkCreateInstance;
		if(strcmp(pName, "vkCreateDevice") == 0) return (PFN_vkVoidFunction) &glinject_hook_vkCreateDevice;
		if(strcmp(pName, "vkDestroyDevice") == 0) return (PFN_vkVoidFunction) &glinject_hook_vkDestroyDevice;
		if(strcmp(pName, "vkCreateSwapchainKHR") == 0) return (PFN_vkVoidFunction) &glinject_hook_vkCreateSwapchainKHR;
		if(strcmp(pName, "vkDestroySwapchainKHR") == 0) return (PFN_vkVoidFunction) &glinject_hook_vkDestroySwapchainKHR;
		if(strcmp(pName, "vkQueuePresentKHR") == 0) return (PFN_vkVoidFunction) &glinject_hook_vkQueuePresentKHR;
		if(strcmp(pName, "vkCreateXlibSurfaceKHR") == 0) return (PFN_vkVoidFunction) &glinject_hook_vkCreateXlibSurfaceKHR;
		if(strcmp(pName, "vkCreateXcbSurfaceKHR") == 0) return (PFN_vkVoidFunction) &glinject_hook_vkCreateXcbSurfaceKHR;
	}
	if(g_real_vkGetInstanceProcAddr)
		return g_real_vkGetInstanceProcAddr(instance, pName);
	return NULL;
}

PFN_vkVoidFunction glinject_hook_vkGetDeviceProcAddr(VkDevice device, const char* pName) {
	VulkanInitPointers();
	if(pName != NULL) {
		if(strcmp(pName, "vkGetDeviceProcAddr") == 0) return (PFN_vkVoidFunction) &glinject_hook_vkGetDeviceProcAddr;
		if(strcmp(pName, "vkDestroyDevice") == 0) return (PFN_vkVoidFunction) &glinject_hook_vkDestroyDevice;
		if(strcmp(pName, "vkCreateSwapchainKHR") == 0) return (PFN_vkVoidFunction) &glinject_hook_vkCreateSwapchainKHR;
		if(strcmp(pName, "vkDestroySwapchainKHR") == 0) return (PFN_vkVoidFunction) &glinject_hook_vkDestroySwapchainKHR;
		if(strcmp(pName, "vkQueuePresentKHR") == 0) return (PFN_vkVoidFunction) &glinject_hook_vkQueuePresentKHR;
	}
	if(g_real_vkGetDeviceProcAddr)
		return g_real_vkGetDeviceProcAddr(device, pName);
	return NULL;
}

// Export functions for direct linking / LD_PRELOAD
extern "C" {

VKAPI_ATTR VkResult VKAPI_CALL vkCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) {
	return glinject_hook_vkCreateInstance(pCreateInfo, pAllocator, pInstance);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) {
	return glinject_hook_vkCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {
	glinject_hook_vkDestroyDevice(device, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) {
	return glinject_hook_vkCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
}
VKAPI_ATTR void VKAPI_CALL vkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) {
	glinject_hook_vkDestroySwapchainKHR(device, swapchain, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) {
	return glinject_hook_vkQueuePresentKHR(queue, pPresentInfo);
}
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(VkInstance instance, const char* pName) {
	return glinject_hook_vkGetInstanceProcAddr(instance, pName);
}
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetDeviceProcAddr(VkDevice device, const char* pName) {
	return glinject_hook_vkGetDeviceProcAddr(device, pName);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateXlibSurfaceKHR(VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	return glinject_hook_vkCreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateXcbSurfaceKHR(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
	return glinject_hook_vkCreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}

}
