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

#include "OutputSettings.h"

#include "EnumTranslator.h"
#include "Logger.h"

void OutputSettings::Defaults() {

	m_file = "";
	m_separate_files = false;
	m_container = CONTAINER_MKV;
	m_container_avname = "";

	//TODO// check whether codec is available
	m_video_codec = VIDEO_CODEC_H264;
	m_video_codec_avname = "";
	m_video_kbit_rate = 5000;
	m_video_options = {
		{"crf", "23"},
		{"preset", "superfast"},
	};
	m_video_allow_frame_skipping = true;

	//TODO// check whether codec is available
	m_audio_codec = AUDIO_CODEC_VORBIS;
	m_audio_codec_avname = "";
	m_audio_kbit_rate = 128;
	m_audio_options = {};

}

void OutputSettings::FromJSON(const SimpleJSON& json) {
	try {

		m_file = json["file"].ToString(m_file);
		m_separate_files = json["separate_files"].ToBool(m_separate_files);
		m_container = StringToEnum(json["container"].ToString(""), m_container);
		m_container_avname = json["container_avname"].ToString(m_container_avname);

		m_video_codec = StringToEnum(json["video"]["codec"].ToString(""), m_video_codec);
		m_video_codec_avname = json["video"]["codec_avname"].ToString(m_video_codec_avname);
		m_video_kbit_rate = json["video"]["kbit_rate"].ToUint32(m_video_kbit_rate);
		const SimpleJSON &video_options = json["video"]["options"];
		m_video_options.resize(video_options.GetElementCount());
		for(size_t i = 0; i < video_options.GetElementCount(); ++i) {
			auto &p = m_video_options[i];
			p.first = video_options[i]["name"].ToString(p.first);
			p.second = video_options[i]["value"].ToString(p.second);
		}
		m_video_allow_frame_skipping = json["video"]["allow_frame_skipping"].ToBool(m_video_allow_frame_skipping);

		m_audio_codec = StringToEnum(json["audio"]["codec"].ToString(""), m_audio_codec);
		m_audio_codec_avname = json["audio"]["codec_avname"].ToString(m_audio_codec_avname);
		m_audio_kbit_rate = json["audio"]["kbit_rate"].ToUint32(m_audio_kbit_rate);
		const SimpleJSON &audio_options = json["audio"]["options"];
		m_audio_options.resize(audio_options.GetMemberCount());
		for(size_t i = 0; i < audio_options.GetMemberCount(); ++i) {
			auto &p = m_audio_options[i];
			p.first = audio_options.GetMemberKey(i);
			p.second = audio_options.GetMemberValue(i).ToString("");
		}

	} catch(const JSONException&) {
		Logger::LogError("[RecordSettings::FromJSON] " + Logger::tr("Error: Invalid JSON data."));
	}
}

void OutputSettings::ToJSON(SimpleJSON& json) {

	json("file") = m_file;
	json("separate_files") = m_separate_files;
	json("container") = EnumToString(m_container);
	json("container_avname") = m_container_avname;

	json("video")("codec") = EnumToString(m_video_codec);
	json("video")("codec_avname") = m_video_codec_avname;
	json("video")("kbit_rate") = m_video_kbit_rate;
	json("video")("options").ResetArray();
	for(auto &p : m_video_options) {
		SimpleJSON &option = json("video")("options").AddElement();
		option("name") = p.first;
		option("value") = p.second;
	}
	json("video")("allow_frame_skipping") = m_video_allow_frame_skipping;

	json("audio")("codec") = EnumToString(m_video_codec);
	json("audio")("codec_avname") = m_video_codec_avname;
	json("audio")("kbit_rate") = m_video_kbit_rate;
	json("audio")("options").ResetObject();
	for(auto &p : m_video_options) {
		json("audio")("options")(p.first) = p.second;
	}

}
