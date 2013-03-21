/*
Copyright (c) 2012 Maarten Baert <maarten-baert@hotmail.com>

This file contains code from x11grab.c (part of libav). The copyright information for x11grab.c is:
>> Libav integration:
>> Copyright (C) 2006 Clemens Fruhwirth <clemens@endorphin.org>
>>                    Edouard Gomez <ed.gomez@free.fr>
>>
>> This file contains code from grab.c:
>> Copyright (c) 2000-2001 Fabrice Bellard
>>
>> This file contains code from the xvidcap project:
>> Copyright (C) 1997-1998 Rasca, Berlin
>>               2003-2004 Karl H. Beckers, Frankfurt

This file is part of SimpleScreenRecorder.

SimpleScreenRecorder is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

SimpleScreenRecorder is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with SimpleScreenRecorder.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "StdAfx.h"
#include "X11Input.h"

#include "Logger.h"
#include "AVWrapper.h"
#include "Synchronizer.h"
#include "VideoEncoder.h"

#include <X11/Xlibint.h>
//#include <X11/Xproto.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xfixes.h>

// get rid of min/max macros from Xlibint.h
#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif

/*
The code in this file is based on the MIT-SHM example code and the x11grab device in libav (which is GPL):
http://www.xfree86.org/current/mit-shm.html
https://git.libav.org/?p=libav.git;a=blob;f=libavdevice/x11grab.c
I am doing the recording myself instead of just using x11grab (as I originally planned) because this is more flexible.
*/

// Converts a X11 image format to a format that libav understands.
static PixelFormat X11ImageGetPixelFormat(XImage* image) {
	switch(image->bits_per_pixel) {
		case 8: return PIX_FMT_PAL8;
		case 16: {
			if(image->red_mask == 0xf800 && image->green_mask == 0x07e0 && image->blue_mask == 0x001f) return PIX_FMT_RGB565;
			if(image->red_mask == 0x7c00 && image->green_mask == 0x03e0 && image->blue_mask == 0x001f) return PIX_FMT_RGB555;
			break;
		}
		case 24: {
			if(image->red_mask == 0xff0000 && image->green_mask == 0x00ff00 && image->blue_mask == 0x0000ff) return PIX_FMT_BGR24;
			if(image->red_mask == 0x0000ff && image->green_mask == 0x00ff00 && image->blue_mask == 0xff0000) return PIX_FMT_RGB24;
			break;
		}
		case 32: {
			return PIX_FMT_RGB32;
		}
	}
	Logger::LogError("[X11ImageGetPixelFormat] Error: Unsupported X11 image pixel format!"
					 "\n    bits_per_pixel = " + QString::number(image->bits_per_pixel) + ", red_mask = 0x" + QString::number(image->red_mask, 16)
					 + ", green_mask = 0x" + QString::number(image->green_mask, 16) + ", blue_mask = 0x" + QString::number(image->blue_mask, 16));
	throw X11Exception();
}

// Copies a part of the screen to an X11 image without shared memory. This function assumes the image has already been
// allocated and has the right size and alignment. As far as I can tell, the only reason to use this instead of XGetImage
// is to avoid an unneccesary memory reallocation. Feel free to use XGetImage instead, the difference isn't that big. In
// my test, this function took 11ms, and XGetImage took 13ms (on average). Besides, this is only a fallback in case shared
// memory can't be used, which really shouldn't happen, unless you're trying to record over a network :).
static bool X11ImageGetWithoutSHM(Display* dpy, Drawable d, XImage* image, int x, int y) {
	xGetImageReq *req;
	LockDisplay(dpy);
	GetReq(GetImage, req);

	req->drawable = d;
	req->x = x;
	req->y = y;
	req->width = image->width;
	req->height = image->height;
	req->planeMask = (unsigned int) AllPlanes;
	req->format = ZPixmap;

	xGetImageReply rep;
	if(_XReply(dpy, (xReply*) &rep, 0, xFalse) == 0 || rep.length == 0) {
		UnlockDisplay(dpy);
		SyncHandle();
		return false;
	}

	long nbytes = (long) rep.length << 2;
	_XReadPad(dpy, image->data, nbytes);

	UnlockDisplay(dpy);
	SyncHandle();
	return true;
}

// clears a rectangular area of an image (i.e. sets the memory to zero, which will most likely make the image black)
static void X11ImageClearRectangle(XImage* image, unsigned int x, unsigned int y, unsigned int w, unsigned int h) {

	// check the image format
	if(image->bits_per_pixel % 8 != 0)
		return;
	unsigned int pixel_bytes = image->bits_per_pixel / 8;

	// fill the rectangle with zeros
	for(unsigned int j = 0; j < h; ++j) {
		uint8_t *image_row = (uint8_t*) image->data + image->bytes_per_line * (y + j);
		memset(image_row + pixel_bytes * x, 0, pixel_bytes * w);
	}

}

// Draws the current cursor at the current position on the image. Requires XFixes.
// Note: In the original code from x11grab, the variables for red and blue are swapped
// (which doesn't change the result, but it's confusing).
// Note 2: This function assumes little-endianness.
// Note 3: This function only supports 24-bit and 32-bit images (it does nothing for other bit depths).
static void X11ImageDrawCursor(Display* dpy, XImage* image, int recording_area_x, int recording_area_y) {

	// check the image format
	unsigned int pixel_bytes, r_offset, g_offset, b_offset;
	if(image->bits_per_pixel == 24 && image->red_mask == 0xff0000 && image->green_mask == 0x00ff00 && image->blue_mask == 0x0000ff) {
		pixel_bytes = 3;
		r_offset = 2; g_offset = 1; b_offset = 0;
	} else if(image->bits_per_pixel == 24 && image->red_mask == 0x0000ff && image->green_mask == 0x00ff00 && image->blue_mask == 0xff0000) {
		pixel_bytes = 3;
		r_offset = 0; g_offset = 1; b_offset = 2;
	} else if(image->bits_per_pixel == 32) {
		pixel_bytes = 4;
		r_offset = 2; g_offset = 1; b_offset = 0;
	} else {
		return;
	}

	// get the cursor
	XFixesCursorImage *xcim = XFixesGetCursorImage(dpy);
	if(xcim == NULL)
		return;

	// calculate the position of the cursor
	int x = xcim->x - xcim->xhot - recording_area_x;
	int y = xcim->y - xcim->yhot - recording_area_y;

	// calculate the part of the cursor that's visible
	int cursor_left = std::max(0, -x), cursor_right = std::min((int) xcim->width, image->width - x);
	int cursor_top = std::max(0, -y), cursor_bottom = std::min((int) xcim->height, image->height - y);

	// draw the cursor
	// XFixesCursorImage uses 'long' instead of 'int' to store the cursor images, which is a bit weird since
	// 'long' is 64-bit on 64-bit systems and only 32 bits are actually used. The image uses premultiplied alpha.
	for(int j = cursor_top; j < cursor_bottom; ++j) {
		unsigned long *cursor_row = xcim->pixels + xcim->width * j;
		uint8_t *image_row = (uint8_t*) image->data + image->bytes_per_line * (y + j);
		for(int i = cursor_left; i < cursor_right; ++i) {
			unsigned long cursor_pixel = cursor_row[i];
			uint8_t *image_pixel = image_row + pixel_bytes * (x + i);
			int cursor_a = (uint8_t) (cursor_pixel >> 24);
			int cursor_r = (uint8_t) (cursor_pixel >> 16);
			int cursor_g = (uint8_t) (cursor_pixel >> 8);
			int cursor_b = (uint8_t) (cursor_pixel >> 0);
			if(cursor_a == 255) {
				image_pixel[r_offset] = cursor_r;
				image_pixel[g_offset] = cursor_g;
				image_pixel[b_offset] = cursor_b;
			} else {
				image_pixel[r_offset] = (image_pixel[r_offset] * (255 - cursor_a) + 127) / 255 + cursor_r;
				image_pixel[g_offset] = (image_pixel[g_offset] * (255 - cursor_a) + 127) / 255 + cursor_g;
				image_pixel[b_offset] = (image_pixel[b_offset] * (255 - cursor_a) + 127) / 255 + cursor_b;
			}
		}
	}

	// free the cursor
	XFree(xcim);

}

const size_t X11Input::THROTTLE_THRESHOLD = 20;

X11Input::X11Input(Synchronizer* synchronizer, unsigned int x, unsigned int y, unsigned int width, unsigned int height, bool show_cursor, bool follow_cursor) {
	Q_ASSERT(synchronizer->GetVideoEncoder() != NULL);

	m_synchronizer = synchronizer;

	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_frame_rate = m_synchronizer->GetVideoEncoder()->GetFrameRate();
	m_out_width = m_synchronizer->GetVideoEncoder()->GetWidth();
	m_out_height = m_synchronizer->GetVideoEncoder()->GetHeight();
	m_show_cursor = show_cursor;
	m_follow_cursor = follow_cursor;

	m_x11_shm_info.shmid = -1;
	m_x11_shm_info.shmaddr = (char*) -1;
	m_x11_shm_server_attached = false;
	m_x11_image = NULL;

	m_warn_swscale = true;
	m_sws_context = NULL;

	if(m_width == 0 || m_height == 0) {
		Logger::LogError("[X11Input::Init] Error: Width or height is zero.");
		throw X11Exception();
	}
	if(m_width > 10000 || m_height > 10000) {
		Logger::LogError("[X11Input::Init] Error: Width or height is too large, the maximum width and height is 10000.");
		throw X11Exception();
	}

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

X11Input::~X11Input() {

	// tell the thread to stop
	if(isRunning()) {
		Logger::LogInfo("[X11Input::~X11Input] Telling input thread to stop ...");
		m_should_stop = true;
		wait();
	}

	// free everything
	Free();

}

void X11Input::Init() {

	// do the X11 stuff
	// we need a separate display because the existing one would interfere with what Qt is doing in some cases
	m_x11_display = XOpenDisplay(NULL); //QX11Info::display();
	if(m_x11_display == NULL) {
		Logger::LogError("[X11Input::Init] Error: Can't open X display!");
		throw X11Exception();
	}
	m_x11_screen = DefaultScreen(m_x11_display); //QX11Info::appScreen();
	m_x11_root = RootWindow(m_x11_display, m_x11_screen); //QX11Info::appRootWindow(m_x11_screen);
	m_x11_visual = DefaultVisual(m_x11_display, m_x11_screen); //(Visual*) QX11Info::appVisual(m_x11_screen);
	m_x11_depth = DefaultDepth(m_x11_display, m_x11_screen); //QX11Info::appDepth(m_x11_screen);
	m_x11_use_shm = XShmQueryExtension(m_x11_display);
	if(m_x11_use_shm) {
		Logger::LogInfo("[X11Input::Init] Using X11 shared memory.");
		m_x11_image = XShmCreateImage(m_x11_display, m_x11_visual, m_x11_depth, ZPixmap, NULL, &m_x11_shm_info, m_width, m_height);
		if(m_x11_image == NULL) {
			Logger::LogError("[X11Input::Init] Error: Can't create shared image!");
			throw X11Exception();
		}
		m_x11_shm_info.shmid = shmget(IPC_PRIVATE, m_x11_image->bytes_per_line * m_x11_image->height, IPC_CREAT | 0777);
		if(m_x11_shm_info.shmid == -1) {
			Logger::LogError("[X11Input::Init] Error: Can't get shared memory!");
			throw X11Exception();
		}
		m_x11_shm_info.shmaddr = m_x11_image->data = (char*) shmat(m_x11_shm_info.shmid, NULL, SHM_RND);
		if(m_x11_shm_info.shmaddr == (char*) -1) {
			Logger::LogError("[X11Input::Init] Error: Can't attach to shared memory!");
			throw X11Exception();
		}
		m_x11_shm_info.readOnly = false;
		// the server will attach later
	} else {
		Logger::LogInfo("[X11Input::Init] Not using X11 shared memory.");
		// the simplest way to create an image with the correct format and alignment is to do a pointless normal screen grab
		m_x11_image = XGetImage(m_x11_display, m_x11_root, m_x, m_y, m_width, m_height, AllPlanes, ZPixmap);
		if(m_x11_image == NULL) {
			Logger::LogError("[X11Input::Init] Error: Can't create image!");
			throw X11Exception();
		}
	}
	m_x11_image_format = X11ImageGetPixelFormat(m_x11_image);

	// showing the cursor requires XFixes (which should be supported on any modern X server, but let's check it anyway)
	if(m_show_cursor) {
		int event, error;
		if(!XFixesQueryExtension(m_x11_display, &event, &error)) {
			Logger::LogWarning("[X11Input::Init] Warning: XFixes is not supported by server, the cursor has been hidden.");
			m_show_cursor = false;
		}
	}

	// get screen configuration information, so we can replace the unused areas with black rectangles (rather than showing random uninitialized memory)
	// this also used by the mouse following code to make sure that the rectangle stays on the screen
	connect(QApplication::desktop(), SIGNAL(screenCountChanged(int)), this, SLOT(UpdateScreenConfiguration()));
	connect(QApplication::desktop(), SIGNAL(resized(int)), this, SLOT(UpdateScreenConfiguration()));
	UpdateScreenConfiguration();

	// start input thread
	m_should_stop = false;
	m_error_occurred = false;
	start();

}

void X11Input::Free() {
	if(m_x11_shm_server_attached) {
		XShmDetach(m_x11_display, &m_x11_shm_info);
		m_x11_shm_server_attached = false;
	}
	if(m_x11_shm_info.shmaddr != (char*) -1) {
		shmdt(m_x11_shm_info.shmaddr);
		m_x11_shm_info.shmaddr = (char*) -1;
	}
	if(m_x11_shm_info.shmid != -1) {
		shmctl(m_x11_shm_info.shmid, IPC_RMID, NULL);
		m_x11_shm_info.shmid = -1;
	}
	if(m_x11_image != NULL) {
		XDestroyImage(m_x11_image);
		m_x11_image = NULL;
	}
	if(m_x11_display != NULL) {
		XCloseDisplay(m_x11_display);
		m_x11_display = NULL;
	}
	if(m_sws_context != NULL) {
		sws_freeContext(m_sws_context);
		m_sws_context = NULL;
	}
}

int64_t X11Input::GetReadDelay() {
	int64_t delay = 1000000 / m_frame_rate;
	size_t frames = m_synchronizer->GetVideoEncoder()->GetQueuedFrameCount();
	if(frames > THROTTLE_THRESHOLD) {
		int64_t n = (frames - THROTTLE_THRESHOLD) * 1000 / THROTTLE_THRESHOLD;
		delay += n * n;
	}
	return delay;
}

void X11Input::UpdateScreenConfiguration() {
	SharedLock lock(&m_shared_data);

	// get the bounding box of the screens
	QRegion region;
	for(int i = 0; i < QApplication::desktop()->screenCount(); ++i) {
		region += QApplication::desktop()->screenGeometry(i);
	}
	lock->m_screen_bbox = region.boundingRect();

	if(lock->m_screen_bbox.x() < 0 || lock->m_screen_bbox.y() < 0 || lock->m_screen_bbox.width() <= 0 || lock->m_screen_bbox.height() <= 0) {
		Logger::LogError("[X11Input::UpdateScreenConfiguration] Error: Invalid screen bounding box!\n"
						   "    x = " + QString::number(lock->m_screen_bbox.x()) + ", y = " + QString::number(lock->m_screen_bbox.y())
						   + ", width = " + QString::number(lock->m_screen_bbox.width()) + ", height = " + QString::number(lock->m_screen_bbox.height()));
		throw X11Exception();
	}

	// now get all the space that is inside the bounding box but not inside any screen
	QRegion inverted_region(lock->m_screen_bbox);
	inverted_region -= region;
	lock->m_screen_dead_space = inverted_region.rects();

}

void X11Input::run() {
	try {

		Logger::LogInfo("[X11Input::run] Input thread started.");

		unsigned int grab_x = m_x, grab_y = m_y;

		int64_t last_frame_time = hrt_time_micro();
		while(!m_should_stop) {

			// sleep
			int64_t delay = GetReadDelay();
			if(delay != 0) {
				int64_t wait = last_frame_time + delay - hrt_time_micro();
				if(wait > 11000) {
					// the thread can't sleep for too long because it still has to check the m_should_stop flag periodically
					usleep(10000);
					continue;
				} else if(wait > 0) {
					usleep(wait);
				}
			}

			// save the current time
			last_frame_time = hrt_time_micro();

			SharedLock lock(&m_shared_data);

			// follow the cursor
			if(m_follow_cursor) {
				int mouse_x, mouse_y, dummy;
				Window dummy_win;
				unsigned int dummy_mask;
				if(XQueryPointer(m_x11_display, m_x11_root, &dummy_win, &dummy_win, &dummy, &dummy, &mouse_x, &mouse_y, &dummy_mask)) {
					grab_x = clamp(lock->m_screen_bbox.x(), lock->m_screen_bbox.x() + lock->m_screen_bbox.width() - (int) m_width, mouse_x - (int) m_width / 2);
					grab_y = clamp(lock->m_screen_bbox.y(), lock->m_screen_bbox.y() + lock->m_screen_bbox.height() - (int) m_height, mouse_y - (int) m_height / 2);
				}
			}

			// get the image
			if(m_x11_use_shm) {
				if(!m_x11_shm_server_attached) {
					if(!XShmAttach(m_x11_display, &m_x11_shm_info)) {
						Logger::LogError("[X11Input::Init] Error: Can't attach server to shared memory!");
						throw X11Exception();
					}
					m_x11_shm_server_attached = true;
				}
				if(!XShmGetImage(m_x11_display, m_x11_root, m_x11_image, grab_x, grab_y, AllPlanes)) {
					Logger::LogError("[X11Input::run] Error: Can't get image (using shared memory)!"
									   "\n    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?");
					throw X11Exception();
				}
			} else {
				if(!X11ImageGetWithoutSHM(m_x11_display, m_x11_root, m_x11_image, grab_x, grab_y)) {
					Logger::LogError("[X11Input::run] Error: Can't get image (not using shared memory)!"
									   "\n    Usually this means the recording area is not completely inside the screen. Or did you change the screen resolution?");
					throw X11Exception();
				}
			}
			uint8_t *image_data = (uint8_t*) m_x11_image->data;
			int image_linesize = m_x11_image->bytes_per_line;

			// clear the dead space
			QRect clip_rect(0, 0, m_width, m_height);
			for(int i = 0; i < lock->m_screen_dead_space.size(); ++i) {
				QRect r = lock->m_screen_dead_space[i].translated(-grab_x, -grab_y).intersected(clip_rect);
				if(r.width() > 0 && r.height() > 0)
					X11ImageClearRectangle(m_x11_image, r.x(), r.y(), r.width(), r.height());
			}

			// draw the cursor
			if(m_show_cursor) {
				X11ImageDrawCursor(m_x11_display, m_x11_image, grab_x, grab_y);
			}

			// allocate the converted frame, with proper alignment
			// Y = 1 byte per pixel, U or V = 1 byte per 2x2 pixels
			int l1 = grow_align16(m_out_width);
			int l2 = grow_align16(m_out_width / 2);
			int s1 = grow_align16(l1 * m_out_height);
			int s2 = grow_align16(l2 * m_out_height / 2);
			std::unique_ptr<AVFrameWrapper> converted_frame(new AVFrameWrapper(s1 + 2 * s2));
			converted_frame->data[1] = converted_frame->data[0] + s1;
			converted_frame->data[2] = converted_frame->data[1] + s2;
			converted_frame->linesize[0] = l1;
			converted_frame->linesize[1] = l2;
			converted_frame->linesize[2] = l2;

			// convert the frame to YUV420P
			bool scaling = (m_width != m_out_width || m_height != m_out_height);
			if(m_x11_image_format == PIX_FMT_BGRA && !scaling) {

				// use my faster converter
				m_yuv_converter.Convert(m_width, m_height, image_data, image_linesize, converted_frame->data, converted_frame->linesize);

			} else {

				if(m_warn_swscale) {
					m_warn_swscale = false;
					if(scaling)
						Logger::LogInfo("[X11Input::run] Using swscale for scaling.");
					else
						Logger::LogWarning("[X11Input::run] Warning: Pixel format is " + QString::number(m_x11_image_format) + " instead of "
											 + QString::number(PIX_FMT_BGRA) + " (PIX_FMT_BGRA), falling back to swscale.");
				}

				// get sws context
				m_sws_context = sws_getCachedContext(m_sws_context,
													 m_width, m_height, m_x11_image_format,
													 m_out_width, m_out_height, PIX_FMT_YUV420P,
													 SWS_BILINEAR, NULL, NULL, NULL);
				if(m_sws_context == NULL) {
					Logger::LogError("[X11Input::run] Error: Can't get swscale context!");
					throw LibavException();
				}
				sws_scale(m_sws_context, &image_data, &image_linesize, 0, m_height, converted_frame->data, converted_frame->linesize);

			}

			// save the frame
			m_synchronizer->AddVideoFrame(std::move(converted_frame), last_frame_time);

		}

		Logger::LogInfo("[X11Input::run] Input thread stopped.");

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError(QString("[X11Input::run] Exception '") + e.what() + "' in input thread.");
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[X11Input::run] Unknown exception in input thread.");
	}
}
