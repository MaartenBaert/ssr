/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "Global.h"
#include "GLInject.h"

#include "GLXFrameGrabber.h"
#include "VKFrameGrabber.h"

GLInject::GLInject() {

#ifdef __x86_64__
	GLINJECT_PRINT("[SSR-GLInject] GLInject started (64-bit).");
#else
	GLINJECT_PRINT("[SSR-GLInject] GLInject started (32-bit).");
#endif

}

GLInject::~GLInject() {

	while(!m_glx_frame_grabbers.empty()) {
		delete m_glx_frame_grabbers.back();
		m_glx_frame_grabbers.pop_back();
	}
	while(!m_vk_frame_grabbers.empty()) {
		delete m_vk_frame_grabbers.back();
		m_vk_frame_grabbers.pop_back();
	}

	GLINJECT_PRINT("[SSR-GLInject] GLInject stopped.");

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

VKFrameGrabber* GLInject::NewVKFrameGrabber(VkDevice device, VkPhysicalDevice physical_device, uint32_t queue_family, VkSwapchainKHR swapchain, VkFormat format, uint32_t width, uint32_t height, Display* x11_display, Window x11_window) {
	VKFrameGrabber *fg = FindVKFrameGrabber(swapchain);
	if(fg == NULL) {
		fg = new VKFrameGrabber(device, physical_device, queue_family, swapchain, format, width, height, x11_display, x11_window);
		m_vk_frame_grabbers.push_back(fg);
	}
	return fg;
}

VKFrameGrabber* GLInject::FindVKFrameGrabber(VkSwapchainKHR swapchain) {
	for(unsigned int i = 0; i < m_vk_frame_grabbers.size(); ++i) {
		if(m_vk_frame_grabbers[i]->GetSwapchain() == swapchain)
			return m_vk_frame_grabbers[i];
	}
	return NULL;
}

void GLInject::DeleteVKFrameGrabberBySwapchain(VkSwapchainKHR swapchain) {
	for(unsigned int i = m_vk_frame_grabbers.size(); i > 0; ) {
		--i;
		if(m_vk_frame_grabbers[i]->GetSwapchain() == swapchain) {
			delete m_vk_frame_grabbers[i];
			m_vk_frame_grabbers[i] = m_vk_frame_grabbers.back();
			m_vk_frame_grabbers.pop_back();
		}
	}
}

void GLInject::DeleteVKFrameGrabberByDevice(VkDevice device) {
	for(unsigned int i = m_vk_frame_grabbers.size(); i > 0; ) {
		--i;
		if(m_vk_frame_grabbers[i]->GetDevice() == device) {
			delete m_vk_frame_grabbers[i];
			m_vk_frame_grabbers[i] = m_vk_frame_grabbers.back();
			m_vk_frame_grabbers.pop_back();
		}
	}
}
