/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#pragma once
#include "Global.h"

#include "SSRVideoStreamWriter.h"

#include <X11/Xlib.h>
#include <X11/X.h>
#include <vulkan/vulkan.h>
#include <vector>

class VKFrameGrabber {

private:
	unsigned int m_id;
	VkDevice m_device;
	VkPhysicalDevice m_physical_device;
	VkSwapchainKHR m_swapchain;
	VkFormat m_format;
	uint32_t m_width;
	uint32_t m_height;
	uint32_t m_queue_family_index;

	SSRVideoStreamWriter *m_stream_writer;

	// Vulkan resources
	VkBuffer m_staging_buffer;
	VkDeviceMemory m_staging_memory;
	size_t m_buffer_size;
	uint32_t m_stride;

	VkCommandPool m_command_pool;
	VkCommandBuffer m_cmd_buffer;

	std::vector<VkImage> m_swapchain_images;

	// Optional X11 info for cursor drawing
	Display *m_x11_display;
	Window m_x11_window;
	bool m_has_xfixes;

	// Device function pointers
	PFN_vkGetSwapchainImagesKHR m_vkGetSwapchainImagesKHR;
	PFN_vkCreateBuffer m_vkCreateBuffer;
	PFN_vkDestroyBuffer m_vkDestroyBuffer;
	PFN_vkGetBufferMemoryRequirements m_vkGetBufferMemoryRequirements;
	PFN_vkAllocateMemory m_vkAllocateMemory;
	PFN_vkFreeMemory m_vkFreeMemory;
	PFN_vkBindBufferMemory m_vkBindBufferMemory;
	PFN_vkMapMemory m_vkMapMemory;
	PFN_vkUnmapMemory m_vkUnmapMemory;
	PFN_vkCreateCommandPool m_vkCreateCommandPool;
	PFN_vkDestroyCommandPool m_vkDestroyCommandPool;
	PFN_vkAllocateCommandBuffers m_vkAllocateCommandBuffers;
	PFN_vkFreeCommandBuffers m_vkFreeCommandBuffers;
	PFN_vkBeginCommandBuffer m_vkBeginCommandBuffer;
	PFN_vkEndCommandBuffer m_vkEndCommandBuffer;
	PFN_vkCmdPipelineBarrier m_vkCmdPipelineBarrier;
	PFN_vkCmdCopyImageToBuffer m_vkCmdCopyImageToBuffer;
	PFN_vkQueueSubmit m_vkQueueSubmit;
	PFN_vkQueueWaitIdle m_vkQueueWaitIdle;
	PFN_vkGetPhysicalDeviceMemoryProperties m_vkGetPhysicalDeviceMemoryProperties;

public:
	VKFrameGrabber(VkDevice device, VkPhysicalDevice physical_device, uint32_t queue_family, VkSwapchainKHR swapchain, VkFormat format, uint32_t width, uint32_t height, Display* x11_display = NULL, Window x11_window = 0);
	~VKFrameGrabber();

private:
	void Init();
	void Free();

public:
	void GrabFrame(VkQueue queue, uint32_t image_index);

public:
	inline VkDevice GetDevice() { return m_device; }
	inline VkSwapchainKHR GetSwapchain() { return m_swapchain; }

};
