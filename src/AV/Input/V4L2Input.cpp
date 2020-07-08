/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

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

#include "V4L2Input.h"

#if SSR_USE_V4L2

#include "Logger.h"
#include "AVWrapper.h"
#include "Synchronizer.h"
#include "VideoEncoder.h"

V4L2Input::V4L2Input(const QString& device, unsigned int width, unsigned int height) {

	m_device = device;
	m_width = width;
	m_height = height;
	m_colorspace = SWS_CS_DEFAULT;
	m_buffers = 4;

	m_v4l2_device = -1;
	m_v4l2_buffers.resize(m_buffers, V4L2Buffer{MAP_FAILED, 0});

	if(m_width == 0 || m_height == 0) {
		Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: Width or height is zero!"));
		throw V4L2Exception();
	}
	if(m_width > SSR_MAX_IMAGE_SIZE || m_height > SSR_MAX_IMAGE_SIZE) {
		Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: Width or height is too large, the maximum width and height is %1!").arg(SSR_MAX_IMAGE_SIZE));
		throw V4L2Exception();
	}
	if(m_width % 2 != 0 || m_height % 2 != 0) {
		Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: Width or height is not an even number!"));
		throw V4L2Exception();
	}

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

V4L2Input::~V4L2Input() {

	// tell the thread to stop
	if(m_thread.joinable()) {
		Logger::LogInfo("[V4L2Input::~V4L2Input] " + Logger::tr("Stopping input thread ..."));
		m_should_stop = true;
		m_thread.join();
	}

	// free everything
	Free();

}

void V4L2Input::GetCurrentSize(unsigned int *width, unsigned int *height) {
	*width = m_width;
	*height = m_height;
}

double V4L2Input::GetFPS() {
	int64_t timestamp = hrt_time_micro();
	uint32_t frame_counter = m_frame_counter;
	unsigned int time = timestamp - m_fps_last_timestamp;
	if(time > 500000) {
		unsigned int frames = frame_counter - m_fps_last_counter;
		m_fps_last_timestamp = timestamp;
		m_fps_last_counter = frame_counter;
		m_fps_current = (double) frames / ((double) time * 1.0e-6);
	}
	return m_fps_current;
}

void V4L2Input::Init() {

	// open device
	m_v4l2_device = v4l2_open(QFile::encodeName(m_device).constData(), O_RDWR);
	if(m_v4l2_device == -1) {
		Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: Can't open V4L2 device!"));
		throw V4L2Exception();
	}

	// check capabilities
	v4l2_capability caps;
	memset(&caps, 0, sizeof(caps));
	if(v4l2_ioctl(m_v4l2_device, VIDIOC_QUERYCAP, &caps) < 0) {
		Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: Can't read capabilities of V4L2 device!"));
		throw V4L2Exception();
	}
	if((caps.capabilities & V4L2_CAP_VIDEO_CAPTURE) == 0) {
		Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: V4L2 device does not support video capture!"));
		throw V4L2Exception();
	}
	if((caps.capabilities & V4L2_CAP_STREAMING) == 0) {
		Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: V4L2 device does not support streaming io!"));
		throw V4L2Exception();
	}
	/*if((caps.capabilities & V4L2_CAP_READWRITE) == 0) {
		Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: V4L2 device does not support read io!"));
		throw V4L2Exception();
	}*/

	// set format
	v4l2_format format;
	memset(&format, 0, sizeof(format));
	format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	format.fmt.pix.width = m_width;
	format.fmt.pix.height = m_height;
	format.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
	format.fmt.pix.field = V4L2_FIELD_ANY;
	if(v4l2_ioctl(m_v4l2_device, VIDIOC_S_FMT, &format) < 0) {
		Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: Can't set capture format!"));
		throw V4L2Exception();
	}
	if(format.fmt.pix.pixelformat != V4L2_PIX_FMT_YUYV) {
		Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: V4L2 device does not support YUYV pixel format!"));
		throw V4L2Exception();
	}
	if(format.fmt.pix.width != m_width || format.fmt.pix.height != m_height) {
		Logger::LogWarning("[V4L2Input::Init] " + Logger::tr("Warning: Resolution %1x%2 is not supported, using %3x%4 instead. "
															 "The video will be scaled.")
						   .arg(m_width).arg(m_height).arg(format.fmt.pix.width).arg(format.fmt.pix.height));
		m_width = format.fmt.pix.width;
		m_height = format.fmt.pix.height;
	}
	const char *colorspace_str = NULL;
	switch(format.fmt.pix.colorspace) {
		case V4L2_COLORSPACE_SMPTE170M: {
			m_colorspace = SWS_CS_SMPTE170M;
			colorspace_str = "smpte170m";
			break;
		}
		case V4L2_COLORSPACE_SMPTE240M: {
			m_colorspace = SWS_CS_SMPTE240M;
			colorspace_str = "smpte240m";
			break;
		}
		case V4L2_COLORSPACE_REC709: {
			m_colorspace = SWS_CS_ITU709;
			colorspace_str = "itu709";
			break;
		}
		case V4L2_COLORSPACE_470_SYSTEM_M:
		case V4L2_COLORSPACE_470_SYSTEM_BG:
		case V4L2_COLORSPACE_JPEG: {
			m_colorspace = SWS_CS_ITU601;
			colorspace_str = "itu601";
			break;
		}
#ifdef SWS_CS_BT2020
		case V4L2_COLORSPACE_BT2020: {
			m_colorspace = SWS_CS_BT2020;
			colorspace_str = "bt2020";
			break;
		}
#endif	
		default: {
			m_colorspace = SWS_CS_DEFAULT;
			colorspace_str = "default";
			break;
		}
	}
	Logger::LogInfo("[V4L2Input::Init] " + Logger::tr("Using color space %1.").arg(colorspace_str));
	m_v4l2_bytes_per_line = (format.fmt.pix.bytesperline == 0)? 2 * format.fmt.pix.width : format.fmt.pix.bytesperline;

	// request buffers
	v4l2_requestbuffers reqbufs;
	memset(&reqbufs, 0, sizeof(reqbufs));
	reqbufs.count = m_buffers;
	reqbufs.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	reqbufs.memory = V4L2_MEMORY_MMAP;
	if(v4l2_ioctl(m_v4l2_device, VIDIOC_REQBUFS, &reqbufs) < 0) {
		Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: Buffer request failed!"));
		throw V4L2Exception();
	}
	for(unsigned int i = 0; i < m_buffers; ++i) {
		v4l2_buffer buf;
		memset(&buf, 0, sizeof(buf));
		buf.index = i;
		buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		buf.memory = V4L2_MEMORY_MMAP;
		if(v4l2_ioctl(m_v4l2_device, VIDIOC_QUERYBUF, &buf) < 0) {
			Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: Buffer query failed!"));
			throw V4L2Exception();
		}
		m_v4l2_buffers[i].m_size = buf.length;
		m_v4l2_buffers[i].m_data = mmap(0, buf.length, PROT_READ, MAP_SHARED, m_v4l2_device, buf.m.offset);
		if(m_v4l2_buffers[i].m_data == MAP_FAILED) {
			Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: Buffer mmap failed!"));
			throw V4L2Exception();
		}
	}

	// queue the buffers
	for(unsigned int i = 0; i < m_buffers; ++i) {
		v4l2_buffer buf;
		memset(&buf, 0, sizeof(buf));
		buf.index = i;
		buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		buf.memory = V4L2_MEMORY_MMAP;
		if(v4l2_ioctl(m_v4l2_device, VIDIOC_QBUF, &buf) < 0) {
			Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: Buffer queue failed!"));
			throw V4L2Exception();
		}
	}

	// start stream
	int type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	if(v4l2_ioctl(m_v4l2_device, VIDIOC_STREAMON, &type) < 0) {
		Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: Failed to start stream!"));
		throw V4L2Exception();
	}

	// initialize frame counter
	m_frame_counter = 0;
	m_fps_last_timestamp = hrt_time_micro();
	m_fps_last_counter = 0;
	m_fps_current = 0.0;

	// start input thread
	m_should_stop = false;
	m_error_occurred = false;
	m_thread = std::thread(&V4L2Input::InputThread, this);

}

void V4L2Input::Free() {
	for(unsigned int i = 0; i < m_buffers; ++i) {
		if(m_v4l2_buffers[i].m_data != MAP_FAILED) {
			munmap(m_v4l2_buffers[i].m_data, m_v4l2_buffers[i].m_size);
			m_v4l2_buffers[i].m_data = MAP_FAILED;
		}
	}
	if(m_v4l2_device != -1) {
		v4l2_close(m_v4l2_device);
		m_v4l2_device = -1;
	}
}

void V4L2Input::InputThread() {
	try {

		Logger::LogInfo("[V4L2Input::InputThread] " + Logger::tr("Input thread started."));

		while(!m_should_stop) {

			// dequeue a buffer
			v4l2_buffer buf;
			memset(&buf, 0, sizeof(buf));
			buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
			buf.memory = V4L2_MEMORY_MMAP;
			if(ioctl(m_v4l2_device, VIDIOC_DQBUF, &buf) < 0) {
				Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: Buffer dequeue failed!"));
				throw V4L2Exception();
			}

			// record the timestamp
			int64_t timestamp = hrt_time_micro();

			// increase the frame counter
			++m_frame_counter;

			// push the frame
			PushVideoFrame(m_width, m_height, (uint8_t*) m_v4l2_buffers[buf.index].m_data, m_v4l2_bytes_per_line, AV_PIX_FMT_YUYV422, m_colorspace, timestamp);

			// requeue the buffer
			if(v4l2_ioctl(m_v4l2_device, VIDIOC_QBUF, &buf) < 0) {
				Logger::LogError("[V4L2Input::Init] " + Logger::tr("Error: Buffer requeue failed!"));
				throw V4L2Exception();
			}

		}

		Logger::LogInfo("[V4L2Input::InputThread] " + Logger::tr("Input thread stopped."));

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError("[V4L2Input::InputThread] " + Logger::tr("Exception '%1' in input thread.").arg(e.what()));
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[V4L2Input::InputThread] " + Logger::tr("Unknown exception in input thread."));
	}
}

#endif
