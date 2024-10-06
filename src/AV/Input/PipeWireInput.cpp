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

#include "PipeWireInput.h"

#if SSR_USE_V4L2

#include "Logger.h"
#include "AVWrapper.h"
#include "Synchronizer.h"
#include "VideoEncoder.h"

#include <spa/pod/builder.h>
#include <spa/utils/result.h>

PipeWireInput::PipeWireInput(const QString& node_id, unsigned int width, unsigned int height, unsigned int frame_rate) {

	m_node_id = node_id;
	m_width = width;
	m_height = height;
	m_frame_rate = frame_rate;
	m_pixel_format = AV_PIX_FMT_NONE;
	m_colorspace = SWS_CS_DEFAULT;
	m_buffers = 4;

	m_loop = nullptr;
	m_stream = nullptr;

	if(m_width == 0 || m_height == 0) {
		Logger::LogError("[PipeWireInput::Init] " + Logger::tr("Error: Width or height is zero!"));
		throw PipeWireException();
	}
	if(m_width > SSR_MAX_IMAGE_SIZE || m_height > SSR_MAX_IMAGE_SIZE) {
		Logger::LogError("[PipeWireInput::Init] " + Logger::tr("Error: Width or height is too large, the maximum width and height is %1!").arg(SSR_MAX_IMAGE_SIZE));
		throw PipeWireException();
	}
	if(m_width % 2 != 0 || m_height % 2 != 0) {
		Logger::LogError("[PipeWireInput::Init] " + Logger::tr("Error: Width or height is not an even number!"));
		throw PipeWireException();
	}

	try {
		Init();
	} catch(...) {
		Free();
		throw;
	}

}

PipeWireInput::~PipeWireInput() {

	// tell the thread to stop
	if(m_thread.joinable()) {
		Logger::LogInfo("[PipeWireInput::~PipeWireInput] " + Logger::tr("Stopping input thread ..."));
		m_should_stop = true;
		m_thread.join();
	}

	// free everything
	Free();

}

void PipeWireInput::GetCurrentSize(unsigned int *width, unsigned int *height) {
	*width = m_width;
	*height = m_height;
}

double PipeWireInput::GetFPS() {
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

void PipeWireInput::Init() {

	pw_init(nullptr, nullptr);

	m_loop = pw_main_loop_new(nullptr);
	if(!m_loop) {
		Logger::LogError("[PipeWireInput::Init] " + Logger::tr("Error: Failed to create main loop!"));
		throw PipeWireException();
	}

	memset(&m_stream_events, 0, sizeof(m_stream_events));
	m_stream_events.version = PW_VERSION_STREAM_EVENTS;
	m_stream_events.process = &PipeWireInput::OnProcess;
	m_stream_events.param_changed = &PipeWireInput::OnParamChange;

	m_stream = pw_stream_new_simple(
		pw_main_loop_get_loop(m_loop),
		"SimpleScreenRecorder",
		pw_properties_new(
			PW_KEY_MEDIA_TYPE, "Video",
			PW_KEY_MEDIA_CATEGORY, "Capture",
			nullptr), // TODO memory leak?
		&m_stream_events,
		this);

	if(!m_stream) {
		Logger::LogError("[PipeWireInput::Init] " + Logger::tr("Error: Failed to create stream!"));
		throw PipeWireException();
	}

	// pw_properties_set(props, PW_KEY_TARGET_OBJECT, argv[1]); // TODO

	uint8_t buffer[1024];
	spa_pod_builder b = SPA_POD_BUILDER_INIT(buffer, sizeof(buffer));

	struct spa_rectangle temp_size = SPA_RECTANGLE(m_width, m_height);
	struct spa_rectangle temp_size_min = SPA_RECTANGLE(2, 2);
	struct spa_rectangle temp_size_max = SPA_RECTANGLE(SSR_MAX_IMAGE_SIZE, SSR_MAX_IMAGE_SIZE);
	struct spa_fraction temp_framerate = SPA_FRACTION(m_frame_rate, 1);
	struct spa_fraction temp_framerate_min = SPA_FRACTION(0, 1);
	struct spa_fraction temp_framerate_max = SPA_FRACTION(1000, 1);

	const struct spa_pod *params[1];
	params[0] = (const struct spa_pod*) spa_pod_builder_add_object(&b,
		SPA_TYPE_OBJECT_Format, SPA_PARAM_EnumFormat,
		SPA_FORMAT_mediaType, SPA_POD_Id(SPA_MEDIA_TYPE_video),
		SPA_FORMAT_mediaSubtype, SPA_POD_Id(SPA_MEDIA_SUBTYPE_raw),
		SPA_FORMAT_VIDEO_format, SPA_POD_CHOICE_ENUM_Id(12,
			SPA_VIDEO_FORMAT_BGRx,
			SPA_VIDEO_FORMAT_BGRx,
			SPA_VIDEO_FORMAT_RGBx,
			SPA_VIDEO_FORMAT_BGRA,
			SPA_VIDEO_FORMAT_RGBA,
			SPA_VIDEO_FORMAT_BGR,
			SPA_VIDEO_FORMAT_RGB,
			SPA_VIDEO_FORMAT_Y444,
			SPA_VIDEO_FORMAT_Y42B,
			SPA_VIDEO_FORMAT_I420,
			SPA_VIDEO_FORMAT_YUY2,
			SPA_VIDEO_FORMAT_NV12),
		SPA_FORMAT_VIDEO_size, SPA_POD_CHOICE_RANGE_Rectangle(&temp_size, &temp_size_min, &temp_size_max),
		SPA_FORMAT_VIDEO_framerate, SPA_POD_CHOICE_RANGE_Fraction(&temp_framerate, &temp_framerate_min, &temp_framerate_max));

	int res = pw_stream_connect(m_stream,
		PW_DIRECTION_INPUT,
		pw_properties_parse_int(m_node_id.toUtf8().constData()),
		(pw_stream_flags) (PW_STREAM_FLAG_AUTOCONNECT | PW_STREAM_FLAG_MAP_BUFFERS),
		params, 1);
	if(res != 0) {
		Logger::LogError("[PipeWireInput::Init] " + Logger::tr("Error: Failed to connect stream!"));
		throw PipeWireException();
	}

	// initialize frame counter
	m_frame_counter = 0;
	m_fps_last_timestamp = hrt_time_micro();
	m_fps_last_counter = 0;
	m_fps_current = 0.0;

	// start input thread
	m_should_stop = false;
	m_error_occurred = false;
	m_thread = std::thread(&PipeWireInput::InputThread, this);

}

void PipeWireInput::Free() {
	if(m_stream) {
		pw_stream_destroy(m_stream);
		m_stream = nullptr;
	}
	if(m_loop) {
		pw_main_loop_destroy(m_loop);
		m_loop = nullptr;
	}
	pw_deinit();
}

void PipeWireInput::InputThread() {
	try {
		Logger::LogInfo("[PipeWireInput::InputThread] " + Logger::tr("Input thread started."));

		struct pw_loop *loop = pw_main_loop_get_loop(m_loop);

		while (!m_should_stop) {
			int result = pw_loop_iterate(loop, 100);
			if (result < 0) {
				Logger::LogError("[PipewireInput::InputThread] " + Logger::tr("Error in main loop: %1").arg(spa_strerror(result)));
				break;
			}
		}

		Logger::LogInfo("[PipeWireInput::InputThread] " + Logger::tr("Input thread stopped."));

	} catch(const std::exception& e) {
		m_error_occurred = true;
		Logger::LogError("[PipeWireInput::InputThread] " + Logger::tr("Exception '%1' in input thread.").arg(e.what()));
	} catch(...) {
		m_error_occurred = true;
		Logger::LogError("[PipeWireInput::InputThread] " + Logger::tr("Unknown exception in input thread."));
	}
}

void PipeWireInput::OnProcess(void *userdata) {
	PipeWireInput *input = static_cast<PipeWireInput*>(userdata);
	pw_buffer *b;
	struct spa_buffer *buf;

	if((b = pw_stream_dequeue_buffer(input->m_stream)) == nullptr) {
		pw_log_warn("out of buffers: %m");
		return;
	}

	buf = b->buffer;
	if(buf->datas[0].data == nullptr)
		return;

	int64_t timestamp = hrt_time_micro();
	++input->m_frame_counter;

	if(input->m_pixel_format == AV_PIX_FMT_NONE) {
		Logger::LogError("[PipeWireInput::OnProcess] " + Logger::tr("Error: Unknown pixel format!"));
	} else {
		if(buf->n_datas == 1) {
			input->PushVideoFrame(
				input->m_width, input->m_height,
				static_cast<uint8_t*>(buf->datas[0].data), // TODO planes
				buf->datas[0].chunk->stride,
				input->m_pixel_format, input->m_colorspace, timestamp);
		} else {
			Logger::LogError("[PipeWireInput::OnProcess] " + Logger::tr("Error: Planar data is not supported yet!"));
		}
	}

	pw_stream_queue_buffer(input->m_stream, b);
}

void PipeWireInput::OnParamChange(void *userdata, uint32_t id, const struct spa_pod *param) {
	PipeWireInput *input = static_cast<PipeWireInput*>(userdata);
	struct spa_video_info info;

	if(id != SPA_PARAM_Format || param == nullptr) {
		// Logger::LogError("[PipeWireInput::OnParamChange] " + Logger::tr("Error: Not a format change!"));
		return;
	}

	if(spa_format_parse(param, &info.media_type, &info.media_subtype) < 0) {
		Logger::LogError("[PipeWireInput::OnParamChange] " + Logger::tr("Error: Failed to parse format!"));
		return;
	}

	if(info.media_type != SPA_MEDIA_TYPE_video || info.media_subtype != SPA_MEDIA_SUBTYPE_raw) {
		Logger::LogError("[PipeWireInput::OnParamChange] " + Logger::tr("Error: Invalid media type!"));
		return;
	}

	if(spa_format_video_raw_parse(param, &info.info.raw) < 0) {
		Logger::LogError("[PipeWireInput::OnParamChange] " + Logger::tr("Error: Failed to parse video format!"));
		return;
	}

	input->m_width = info.info.raw.size.width;
	input->m_height = info.info.raw.size.height;
	switch(info.info.raw.format) {
		case SPA_VIDEO_FORMAT_BGRx: input->m_pixel_format = AV_PIX_FMT_BGRA; break;
		case SPA_VIDEO_FORMAT_RGBx: input->m_pixel_format = AV_PIX_FMT_RGBA; break;
		case SPA_VIDEO_FORMAT_BGRA: input->m_pixel_format = AV_PIX_FMT_BGRA; break;
		case SPA_VIDEO_FORMAT_RGBA: input->m_pixel_format = AV_PIX_FMT_RGBA; break;
		case SPA_VIDEO_FORMAT_BGR: input->m_pixel_format = AV_PIX_FMT_BGR24; break;
		case SPA_VIDEO_FORMAT_RGB: input->m_pixel_format = AV_PIX_FMT_RGB24; break;
		case SPA_VIDEO_FORMAT_Y444: input->m_pixel_format = AV_PIX_FMT_YUV444P; break;
		case SPA_VIDEO_FORMAT_Y42B: input->m_pixel_format = AV_PIX_FMT_YUV422P; break;
		case SPA_VIDEO_FORMAT_I420: input->m_pixel_format = AV_PIX_FMT_YUV420P; break;
		case SPA_VIDEO_FORMAT_YUY2: input->m_pixel_format = AV_PIX_FMT_YUYV422; break;
		case SPA_VIDEO_FORMAT_NV12: input->m_pixel_format = AV_PIX_FMT_NV12; break;
		default: Logger::LogError("[PipeWireInput::OnParamChange] " + Logger::tr("Error: Unknown pixel format!"));
	}

	Logger::LogInfo("[PipeWireInput::OnParamChange] " + Logger::tr("Video format: %1x%2 %3")
		.arg(info.info.raw.size.width)
		.arg(info.info.raw.size.height)
		.arg(spa_debug_type_find_name(spa_type_video_format, info.info.raw.format)));

}

#endif
