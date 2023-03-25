/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#pragma once
#include "Global.h"

#include <GL/glx.h>
#include <X11/X.h>

class GLXFrameGrabber;

class GLInject {

public:

private:
	std::vector<GLXFrameGrabber*> m_glx_frame_grabbers;

public:
	GLInject();
	~GLInject();

	GLXFrameGrabber* NewGLXFrameGrabber(Display* display, Window window, GLXDrawable drawable);
	GLXFrameGrabber* FindGLXFrameGrabber(Display* display, GLXDrawable drawable);
	void DeleteGLXFrameGrabberByWindow(Display* display, Window window);
	void DeleteGLXFrameGrabberByDrawable(Display* display, GLXDrawable drawable);

};
