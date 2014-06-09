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

#include "InputSettings.h"

#include "EnumTranslator.h"
#include "Logger.h"

void InputSettings::Defaults() {

	m_video_area = VIDEO_AREA_SCREEN;
	m_video_area_screen = 0;
	m_video_x = 0;
	m_video_y = 0;
	m_video_w = 800;
	m_video_h = 600;
	m_video_frame_rate = 30;
	m_video_scaling_enabled = false;
	m_video_scaled_w = 854;
	m_video_scaled_h = 480;
	m_video_record_cursor = true;

	//TODO// check whether PulseAudio is available
	m_audio_enabled = true;
#if SSR_USE_PULSEAUDIO
	m_audio_backend = (m_pulseaudio_available)? AUDIO_BACKEND_PULSEAUDIO : AUDIO_BACKEND_ALSA;
#else
	m_audio_backend = AUDIO_BACKEND_ALSA;
#endif
	m_audio_alsa_source = "";
	m_audio_pulseaudio_source = "";
	m_audio_jack_connect_system_capture = true;
	m_audio_jack_connect_system_playback = false;

	m_glinject_channel = "channel-" + GetUserName();
	m_glinject_relax_permissions = false;
	m_glinject_command = "";
	m_glinject_working_directory = "";
	m_glinject_auto_launch = false;
	m_glinject_limit_fps = false;

}

void InputSettings::FromJSON(const SimpleJSON& json) {
	try {

		m_video_area = StringToEnum(json["video"]["area"].ToString(""), m_video_area);
		m_video_area_screen = json["video"]["area_screen"].ToUint32(m_video_area_screen);
		m_video_x = json["video"]["x"].ToUint32(m_video_x);
		m_video_y = json["video"]["y"].ToUint32(m_video_y);
		m_video_w = json["video"]["w"].ToUint32(m_video_w);
		m_video_h = json["video"]["h"].ToUint32(m_video_h);
		m_video_frame_rate = json["video"]["frame_rate"].ToUint32(m_video_frame_rate);
		m_video_scaling_enabled = json["video"]["scale"].ToBool(m_video_scaling_enabled);
		m_video_scaled_w = json["video"]["scaled_w"].ToUint32(m_video_scaled_w);
		m_video_scaled_h = json["video"]["scaled_h"].ToUint32(m_video_scaled_h);
		m_video_record_cursor = json["video"]["record_cursor"].ToBool(m_video_record_cursor);

		m_audio_enabled = json["audio"]["enable"].ToBool(m_audio_enabled);
		m_audio_backend = StringToEnum(json["audio"]["backend"].ToString(""), m_audio_backend);
		m_audio_alsa_source = json["audio"]["alsa_source"].ToString(m_audio_alsa_source);
		m_audio_pulseaudio_source = json["audio"]["pulseaudio_source"].ToString(m_audio_pulseaudio_source);
		m_audio_jack_connect_system_capture = json["audio"]["jack_connect_system_capture"].ToBool(m_audio_jack_connect_system_capture);
		m_audio_jack_connect_system_playback = json["audio"]["jack_connect_system_playback"].ToBool(m_audio_jack_connect_system_playback);

		m_glinject_channel = json["glinject"]["channel"].ToString(m_glinject_channel);
		m_glinject_relax_permissions = json["glinject"]["relax_permissions"].ToBool(m_glinject_relax_permissions);
		m_glinject_command = json["glinject"]["command"].ToString(m_glinject_command);
		m_glinject_working_directory = json["glinject"]["working_directory"].ToString(m_glinject_working_directory);
		m_glinject_auto_launch = json["glinject"]["auto_launch"].ToBool(m_glinject_auto_launch);
		m_glinject_limit_fps = json["glinject"]["limit_fps"].ToBool(m_glinject_limit_fps);

	} catch(const JSONException&) {
		Logger::LogError("[InputSettings::FromJSON] " + Logger::tr("Error: Invalid JSON data."));
	}
}

void InputSettings::ToJSON(SimpleJSON& json) {

	json("video")("area") = EnumToString(m_video_area);
	json("video")("area_screen") = m_video_area_screen;
	json("video")("x") = m_video_x;
	json("video")("y") = m_video_y;
	json("video")("w") = m_video_w;
	json("video")("h") = m_video_h;
	json("video")("frame_rate") = m_video_frame_rate;
	json("video")("scale") = m_video_scaling_enabled;
	json("video")("scaled_w") = m_video_scaled_w;
	json("video")("scaled_h") = m_video_scaled_h;
	json("video")("record_cursor") = m_video_record_cursor;

	json("audio")("enable") = m_audio_enabled;
	json("audio")("backend") = EnumToString(m_audio_backend);
	json("audio")("alsa_source") = m_audio_alsa_source;
	json("audio")("pulseaudio_source") = m_audio_pulseaudio_source;
	json("audio")("jack_connect_system_capture") = m_audio_jack_connect_system_capture;
	json("audio")("jack_connect_system_playback") = m_audio_jack_connect_system_playback;

	json("glinject")("channel") = m_glinject_channel;
	json("glinject")("relax_permissions") = m_glinject_relax_permissions;
	json("glinject")("command") = m_glinject_command;
	json("glinject")("working_directory") = m_glinject_working_directory;
	json("glinject")("auto_launch") = m_glinject_auto_launch;
	json("glinject")("limit_fps") = m_glinject_limit_fps;

}
