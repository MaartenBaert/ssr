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

		json["video"]["area"].GetEnum(m_video_area);
		json["video"]["area_screen"].GetNumber(m_video_area_screen);
		json["video"]["x"].GetNumber(m_video_x);
		json["video"]["y"].GetNumber(m_video_y);
		json["video"]["w"].GetNumber(m_video_w);
		json["video"]["h"].GetNumber(m_video_h);
		json["video"]["frame_rate"].GetNumber(m_video_frame_rate);
		json["video"]["scaling_enabled"].GetBool(m_video_scaling_enabled);
		json["video"]["scaled_w"].GetNumber(m_video_scaled_w);
		json["video"]["scaled_h"].GetNumber(m_video_scaled_h);
		json["video"]["record_cursor"].GetBool(m_video_record_cursor);

		json["audio"]["enable"].GetBool(m_audio_enabled);
		json["audio"]["backend"].GetEnum(m_audio_backend);
		json["audio"]["alsa_source"].GetString(m_audio_alsa_source);
		json["audio"]["pulseaudio_source"].GetString(m_audio_pulseaudio_source);
		json["audio"]["jack_connect_system_capture"].GetBool(m_audio_jack_connect_system_capture);
		json["audio"]["jack_connect_system_playback"].GetBool(m_audio_jack_connect_system_playback);

		json["glinject"]["channel"].GetString(m_glinject_channel);
		json["glinject"]["relax_permissions"].GetBool(m_glinject_relax_permissions);
		json["glinject"]["command"].GetString(m_glinject_command);
		json["glinject"]["working_directory"].GetString(m_glinject_working_directory);
		json["glinject"]["auto_launch"].GetBool(m_glinject_auto_launch);
		json["glinject"]["limit_fps"].GetBool(m_glinject_limit_fps);

	} catch(const JSONException&) {
		Logger::LogError("[InputSettings::FromJSON] " + Logger::tr("Error: Invalid JSON data."));
	}
}

void InputSettings::ToJSON(SimpleJSON& json) {

	json("video")("area").SetEnum(m_video_area);
	json("video")("area_screen").SetNumber(m_video_area_screen);
	json("video")("x").SetNumber(m_video_x);
	json("video")("y").SetNumber(m_video_y);
	json("video")("w").SetNumber(m_video_w);
	json("video")("h").SetNumber(m_video_h);
	json("video")("frame_rate").SetNumber(m_video_frame_rate);
	json("video")("scaling_enabled").SetBool(m_video_scaling_enabled);
	json("video")("scaled_w").SetNumber(m_video_scaled_w);
	json("video")("scaled_h").SetNumber(m_video_scaled_h);
	json("video")("record_cursor").SetBool(m_video_record_cursor);

	json("audio")("enable").SetBool(m_audio_enabled);
	json("audio")("backend").SetEnum(m_audio_backend);
	json("audio")("alsa_source").SetString(m_audio_alsa_source);
	json("audio")("pulseaudio_source").SetString(m_audio_pulseaudio_source);
	json("audio")("jack_connect_system_capture").SetBool(m_audio_jack_connect_system_capture);
	json("audio")("jack_connect_system_playback").SetBool(m_audio_jack_connect_system_playback);

	json("glinject")("channel").SetString(m_glinject_channel);
	json("glinject")("relax_permissions").SetBool(m_glinject_relax_permissions);
	json("glinject")("command").SetString(m_glinject_command);
	json("glinject")("working_directory").SetString(m_glinject_working_directory);
	json("glinject")("auto_launch").SetBool(m_glinject_auto_launch);
	json("glinject")("limit_fps").SetBool(m_glinject_limit_fps);

}
