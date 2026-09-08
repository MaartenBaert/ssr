/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "Global.h"
#include "VKFrameGrabber.h"
#include "ShmStructs.h"

#include <X11/extensions/Xfixes.h>

static unsigned int g_vk_frame_grabber_counter = 0;

static void VKImageDrawCursor(Display* dpy, uint8_t* image_data, size_t image_stride, int image_width, int image_height, int recording_area_x, int recording_area_y) {
	XFixesCursorImage *xcim = XFixesGetCursorImage(dpy);
	if(xcim == NULL)
		return;

	int x = xcim->x - xcim->xhot - recording_area_x;
	int y = xcim->y - xcim->yhot - recording_area_y;

	int cursor_left = std::max(0, -x), cursor_right = std::min((int) xcim->width, image_width - x);
	int cursor_top = std::max(0, -y), cursor_bottom = std::min((int) xcim->height, image_height - y);

	for(int j = cursor_top; j < cursor_bottom; ++j) {
		unsigned long *cursor_row = xcim->pixels + xcim->width * j;
		uint8_t *image_row = image_data + image_stride * (y + j);
		for(int i = cursor_left; i < cursor_right; ++i) {
			unsigned long cursor_pixel = cursor_row[i];
			uint8_t *image_pixel = image_row + 4 * (x + i);
			int cursor_a = (uint8_t) (cursor_pixel >> 24);
			int cursor_r = (uint8_t) (cursor_pixel >> 16);
			int cursor_g = (uint8_t) (cursor_pixel >> 8);
			int cursor_b = (uint8_t) (cursor_pixel >> 0);
			if(cursor_a == 255) {
				image_pixel[2] = cursor_r;
				image_pixel[1] = cursor_g;
				image_pixel[0] = cursor_b;
			} else {
				image_pixel[2] = (image_pixel[2] * (255 - cursor_a) + 127) / 255 + cursor_r;
				image_pixel[1] = (image_pixel[1] * (255 - cursor_a) + 127) / 255 + cursor_g;
				image_pixel[0] = (image_pixel[0] * (255 - cursor_a) + 127) / 255 + cursor_b;
			}
		}
	}

	XFree(xcim);
}

VKFrameGrabber::VKFrameGrabber(VkDevice device, VkPhysicalDevice physical_device, uint32_t queue_family, VkSwapchainKHR swapchain, VkFormat format, uint32_t width, uint32_t height, Display* x11_display, Window x11_window) {
	m_id = ++g_vk_frame_grabber_counter;
	m_device = device;
	m_physical_device = physical_device;
	m_queue_family_index = queue_family;
	m_swapchain = swapchain;
	m_format = format;
	m_width = width;
	m_height = height;

	m_stream_writer = NULL;
	m_staging_buffer = VK_NULL_HANDLE;
	m_staging_memory = VK_NULL_HANDLE;
	m_command_pool = VK_NULL_HANDLE;
	m_cmd_buffer = VK_NULL_HANDLE;
	m_buffer_size = 0;
	m_stride = 0;

	m_x11_display = x11_display;
	m_x11_window = x11_window;
	m_has_xfixes = false;

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}
}

VKFrameGrabber::~VKFrameGrabber() {
	Free();
}

void VKFrameGrabber::Init() {
	GLINJECT_PRINT("[VKFrameGrabber " << m_id << "] Created Vulkan frame grabber (" << m_width << "x" << m_height << ", format=" << m_format << ").");

	// Resolve function pointers
	PFN_vkGetDeviceProcAddr fpGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr) dlsym(RTLD_DEFAULT, "vkGetDeviceProcAddr");
	if(!fpGetDeviceProcAddr) {
		void *vk_lib = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
		if(vk_lib)
			fpGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr) dlsym(vk_lib, "vkGetDeviceProcAddr");
	}

#define LOAD_VK_FN(name) \
	m_##name = fpGetDeviceProcAddr ? (PFN_##name) fpGetDeviceProcAddr(m_device, #name) : NULL; \
	if(!m_##name) m_##name = (PFN_##name) dlsym(RTLD_DEFAULT, #name);

	LOAD_VK_FN(vkGetSwapchainImagesKHR);
	LOAD_VK_FN(vkCreateBuffer);
	LOAD_VK_FN(vkDestroyBuffer);
	LOAD_VK_FN(vkGetBufferMemoryRequirements);
	LOAD_VK_FN(vkAllocateMemory);
	LOAD_VK_FN(vkFreeMemory);
	LOAD_VK_FN(vkBindBufferMemory);
	LOAD_VK_FN(vkMapMemory);
	LOAD_VK_FN(vkUnmapMemory);
	LOAD_VK_FN(vkCreateCommandPool);
	LOAD_VK_FN(vkDestroyCommandPool);
	LOAD_VK_FN(vkAllocateCommandBuffers);
	LOAD_VK_FN(vkFreeCommandBuffers);
	LOAD_VK_FN(vkBeginCommandBuffer);
	LOAD_VK_FN(vkEndCommandBuffer);
	LOAD_VK_FN(vkCmdPipelineBarrier);
	LOAD_VK_FN(vkCmdCopyImageToBuffer);
	LOAD_VK_FN(vkQueueSubmit);
	LOAD_VK_FN(vkQueueWaitIdle);

	m_vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties) dlsym(RTLD_DEFAULT, "vkGetPhysicalDeviceMemoryProperties");
	if(!m_vkGetPhysicalDeviceMemoryProperties) {
		void *vk_lib = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
		if(vk_lib)
			m_vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties) dlsym(vk_lib, "vkGetPhysicalDeviceMemoryProperties");
	}

	if(!m_vkGetSwapchainImagesKHR || !m_vkCreateBuffer || !m_vkAllocateMemory || !m_vkCmdCopyImageToBuffer) {
		GLINJECT_PRINT("[VKFrameGrabber " << m_id << "] Error: Failed to resolve essential Vulkan functions!");
		return;
	}

	// Retrieve swapchain images
	uint32_t image_count = 0;
	if(m_vkGetSwapchainImagesKHR(m_device, m_swapchain, &image_count, NULL) == VK_SUCCESS && image_count > 0) {
		m_swapchain_images.resize(image_count);
		m_vkGetSwapchainImagesKHR(m_device, m_swapchain, &image_count, m_swapchain_images.data());
	}

	// Compute stride and buffer size
	m_stride = grow_align16(m_width * 4);
	m_buffer_size = (size_t) m_stride * m_height;

	// Create staging buffer
	VkBufferCreateInfo buffer_info = {};
	buffer_info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
	buffer_info.size = m_buffer_size;
	buffer_info.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
	buffer_info.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
	if(m_vkCreateBuffer(m_device, &buffer_info, NULL, &m_staging_buffer) != VK_SUCCESS) {
		GLINJECT_PRINT("[VKFrameGrabber " << m_id << "] Error: Failed to create staging buffer!");
		return;
	}

	VkMemoryRequirements mem_reqs;
	m_vkGetBufferMemoryRequirements(m_device, m_staging_buffer, &mem_reqs);

	uint32_t mem_type_index = 0;
	if(m_physical_device && m_vkGetPhysicalDeviceMemoryProperties) {
		VkPhysicalDeviceMemoryProperties mem_props;
		m_vkGetPhysicalDeviceMemoryProperties(m_physical_device, &mem_props);
		bool found = false;
		for(uint32_t i = 0; i < mem_props.memoryTypeCount; ++i) {
			if((mem_reqs.memoryTypeBits & (1 << i)) &&
			   (mem_props.memoryTypes[i].propertyFlags & (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)) ==
			   (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)) {
				mem_type_index = i;
				found = true;
				break;
			}
		}
		if(!found) {
			for(uint32_t i = 0; i < mem_props.memoryTypeCount; ++i) {
				if((mem_reqs.memoryTypeBits & (1 << i)) &&
				   (mem_props.memoryTypes[i].propertyFlags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)) {
					mem_type_index = i;
					break;
				}
			}
		}
	}

	VkMemoryAllocateInfo alloc_info = {};
	alloc_info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
	alloc_info.allocationSize = mem_reqs.size;
	alloc_info.memoryTypeIndex = mem_type_index;
	if(m_vkAllocateMemory(m_device, &alloc_info, NULL, &m_staging_memory) != VK_SUCCESS) {
		GLINJECT_PRINT("[VKFrameGrabber " << m_id << "] Error: Failed to allocate staging memory!");
		return;
	}
	m_vkBindBufferMemory(m_device, m_staging_buffer, m_staging_memory, 0);

	// Command pool and command buffer
	VkCommandPoolCreateInfo pool_info = {};
	pool_info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
	pool_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
	pool_info.queueFamilyIndex = m_queue_family_index;
	if(m_vkCreateCommandPool(m_device, &pool_info, NULL, &m_command_pool) != VK_SUCCESS) {
		GLINJECT_PRINT("[VKFrameGrabber " << m_id << "] Error: Failed to create command pool!");
		return;
	}

	VkCommandBufferAllocateInfo cmd_alloc = {};
	cmd_alloc.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	cmd_alloc.commandPool = m_command_pool;
	cmd_alloc.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
	cmd_alloc.commandBufferCount = 1;
	m_vkAllocateCommandBuffers(m_device, &cmd_alloc, &m_cmd_buffer);

	// XFixes cursor check
	if(m_x11_display != NULL) {
		int event, error;
		if(XFixesQueryExtension(m_x11_display, &event, &error))
			m_has_xfixes = true;
	}
}

void VKFrameGrabber::Free() {
	if(m_device) {
		if(m_cmd_buffer && m_command_pool && m_vkFreeCommandBuffers) {
			m_vkFreeCommandBuffers(m_device, m_command_pool, 1, &m_cmd_buffer);
			m_cmd_buffer = VK_NULL_HANDLE;
		}
		if(m_command_pool && m_vkDestroyCommandPool) {
			m_vkDestroyCommandPool(m_device, m_command_pool, NULL);
			m_command_pool = VK_NULL_HANDLE;
		}
		if(m_staging_buffer && m_vkDestroyBuffer) {
			m_vkDestroyBuffer(m_device, m_staging_buffer, NULL);
			m_staging_buffer = VK_NULL_HANDLE;
		}
		if(m_staging_memory && m_vkFreeMemory) {
			m_vkFreeMemory(m_device, m_staging_memory, NULL);
			m_staging_memory = VK_NULL_HANDLE;
		}
	}

	if(m_stream_writer != NULL) {
		delete m_stream_writer;
		m_stream_writer = NULL;
	}

	GLINJECT_PRINT("[VKFrameGrabber " << m_id << "] Destroyed Vulkan frame grabber.");
}

void VKFrameGrabber::GrabFrame(VkQueue queue, uint32_t image_index) {
	if(m_staging_buffer == VK_NULL_HANDLE || m_cmd_buffer == VK_NULL_HANDLE)
		return;
	if(image_index >= m_swapchain_images.size())
		return;

	// Lazy creation of SSR stream writer
	if(m_stream_writer == NULL) {
		std::string channel;
		const char *ssr_channel = getenv("SSR_CHANNEL");
		if(ssr_channel != NULL)
			channel = ssr_channel;
		std::ostringstream source;
		source << "vk" << std::setw(4) << std::setfill('0') << m_id;
		m_stream_writer = new SSRVideoStreamWriter(channel, source.str());
		m_stream_writer->UpdateSize(m_width, m_height, m_stride);
	}

	unsigned int flags = 0;
	void *image_data = m_stream_writer->NewFrame(&flags);
	if(image_data == NULL)
		return;

	VkImage image = m_swapchain_images[image_index];

	// Wait for queue rendering to complete before reading the frame
	if(m_vkQueueWaitIdle)
		m_vkQueueWaitIdle(queue);

	// Record command buffer to copy image to buffer
	VkCommandBufferBeginInfo begin_info = {};
	begin_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
	begin_info.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
	m_vkBeginCommandBuffer(m_cmd_buffer, &begin_info);

	// Barrier: transition swapchain image to TRANSFER_SRC_OPTIMAL
	VkImageMemoryBarrier barrier1 = {};
	barrier1.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
	barrier1.oldLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
	barrier1.newLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
	barrier1.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
	barrier1.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
	barrier1.image = image;
	barrier1.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	barrier1.subresourceRange.baseMipLevel = 0;
	barrier1.subresourceRange.levelCount = 1;
	barrier1.subresourceRange.baseArrayLayer = 0;
	barrier1.subresourceRange.layerCount = 1;
	barrier1.srcAccessMask = VK_ACCESS_MEMORY_READ_BIT;
	barrier1.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;

	m_vkCmdPipelineBarrier(m_cmd_buffer,
		VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
		VK_PIPELINE_STAGE_TRANSFER_BIT,
		0, 0, NULL, 0, NULL, 1, &barrier1);

	VkBufferImageCopy copy_region = {};
	copy_region.bufferOffset = 0;
	copy_region.bufferRowLength = m_stride / 4;
	copy_region.bufferImageHeight = m_height;
	copy_region.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	copy_region.imageSubresource.mipLevel = 0;
	copy_region.imageSubresource.baseArrayLayer = 0;
	copy_region.imageSubresource.layerCount = 1;
	copy_region.imageOffset = {0, 0, 0};
	copy_region.imageExtent = {m_width, m_height, 1};

	m_vkCmdCopyImageToBuffer(m_cmd_buffer, image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, m_staging_buffer, 1, &copy_region);

	// Barrier: transition swapchain image back to PRESENT_SRC_KHR
	VkImageMemoryBarrier barrier2 = barrier1;
	barrier2.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
	barrier2.newLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
	barrier2.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
	barrier2.dstAccessMask = VK_ACCESS_MEMORY_READ_BIT;

	m_vkCmdPipelineBarrier(m_cmd_buffer,
		VK_PIPELINE_STAGE_TRANSFER_BIT,
		VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
		0, 0, NULL, 0, NULL, 1, &barrier2);

	m_vkEndCommandBuffer(m_cmd_buffer);

	// Submit copy command
	VkSubmitInfo submit_info = {};
	submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
	submit_info.commandBufferCount = 1;
	submit_info.pCommandBuffers = &m_cmd_buffer;

	m_vkQueueSubmit(queue, 1, &submit_info, VK_NULL_HANDLE);
	m_vkQueueWaitIdle(queue);

	// Read staging buffer memory
	void *mapped = NULL;
	if(m_vkMapMemory(m_device, m_staging_memory, 0, m_buffer_size, 0, &mapped) == VK_SUCCESS && mapped != NULL) {
		if(m_format == VK_FORMAT_B8G8R8A8_UNORM || m_format == VK_FORMAT_B8G8R8A8_SRGB) {
			memcpy(image_data, mapped, m_stride * m_height);
		} else if(m_format == VK_FORMAT_R8G8B8A8_UNORM || m_format == VK_FORMAT_R8G8B8A8_SRGB) {
			const uint32_t *src = (const uint32_t*) mapped;
			uint32_t *dst = (uint32_t*) image_data;
			uint32_t count = (m_stride / 4) * m_height;
			for(uint32_t i = 0; i < count; ++i) {
				uint32_t c = src[i];
				dst[i] = (c & 0xFF00FF00) | ((c & 0x00FF0000) >> 16) | ((c & 0x000000FF) << 16);
			}
		} else {
			memcpy(image_data, mapped, m_stride * m_height);
		}
		m_vkUnmapMemory(m_device, m_staging_memory);
	}

	// Draw cursor if requested and window is known
	if((flags & GLINJECT_FLAG_RECORD_CURSOR) && m_has_xfixes && m_x11_display && m_x11_window) {
		int inner_x, inner_y;
		Window unused_window;
		if(XTranslateCoordinates(m_x11_display, m_x11_window, DefaultRootWindow(m_x11_display), 0, 0, &inner_x, &inner_y, &unused_window)) {
			VKImageDrawCursor(m_x11_display, (uint8_t*) image_data, m_stride, m_width, m_height, inner_x, inner_y);
		}
	}

	m_stream_writer->NextFrame();
}
