/*
Copyright (c) 2012-2014 Maarten Baert <maarten-baert@hotmail.com>

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

#pragma once
#include "Global.h"

#include "SimpleJSON.h"

enum enum_video_area {
	VIDEO_AREA_SCREEN,
	VIDEO_AREA_FIXED,
	VIDEO_AREA_CURSOR,
	VIDEO_AREA_GLINJECT,
	VIDEO_AREA_COUNT // must be last
};
enum enum_audio_backend {
	AUDIO_BACKEND_ALSA,
#if SSR_USE_PULSEAUDIO
	AUDIO_BACKEND_PULSEAUDIO,
#endif
#if SSR_USE_JACK
	AUDIO_BACKEND_JACK,
#endif
	AUDIO_BACKEND_COUNT // must be last
};

struct InputSettings {

	enum_video_area m_video_area;
	unsigned int m_video_area_screen;
	unsigned int m_video_x, m_video_y, m_video_w, m_video_h;
	unsigned int m_video_frame_rate;
	bool m_video_scaling_enabled;
	unsigned int m_video_scaled_w, m_video_scaled_h;
	bool m_video_record_cursor;

	bool m_audio_enabled;
	enum_audio_backend m_audio_backend;
	std::string m_audio_alsa_source;
#if SSR_USE_PULSEAUDIO
	std::string m_audio_pulseaudio_source;
#endif
#if SSR_USE_JACK
	bool m_audio_jack_connect_system_capture, m_audio_jack_connect_system_playback;
#endif

	std::string m_glinject_channel;
	bool m_glinject_relax_permissions;
	std::string m_glinject_command, m_glinject_working_directory;
	bool m_glinject_auto_launch, m_glinject_limit_fps;

	inline InputSettings() { Defaults(); }
	void Defaults();
	void FromJSON(const SimpleJSON& json);
	void ToJSON(SimpleJSON& json);

};
