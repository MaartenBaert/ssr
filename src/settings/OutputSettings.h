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

enum enum_container {
	CONTAINER_MKV,
	CONTAINER_MP4,
	CONTAINER_WEBM,
	CONTAINER_OGG,
	CONTAINER_OTHER,
	CONTAINER_COUNT // must be last
};
enum enum_video_codec {
	VIDEO_CODEC_H264,
	VIDEO_CODEC_VP8,
	VIDEO_CODEC_THEORA,
	VIDEO_CODEC_OTHER,
	VIDEO_CODEC_COUNT // must be last
};
enum enum_audio_codec {
	AUDIO_CODEC_VORBIS,
	AUDIO_CODEC_MP3,
	AUDIO_CODEC_AAC,
	AUDIO_CODEC_UNCOMPRESSED,
	AUDIO_CODEC_OTHER,
	AUDIO_CODEC_COUNT // must be last
};

class CodecInfo {

public:
	struct ContainerData {
		QString name, avname;
		QStringList suffixes;
		QString filter;
		std::set<enum_video_codec> supported_video_codecs;
		std::set<enum_audio_codec> supported_audio_codecs;
		inline bool operator<(const ContainerData& other) const { return (avname < other.avname); }
	};
	struct VideoCodecData {
		QString name, avname;
		inline bool operator<(const VideoCodecData& other) const { return (avname < other.avname); }
	};
	struct AudioCodecData {
		QString name, avname;
		inline bool operator<(const AudioCodecData& other) const { return (avname < other.avname); }
	};

private:
	static CodecInfo *s_instance;

private:
	std::vector<ContainerData> m_containers, m_containers_av;
	std::vector<VideoCodecData> m_video_codecs, m_video_codecs_av;
	std::vector<AudioCodecData> m_audio_codecs, m_audio_codecs_av;

public:
	CodecInfo();
	~CodecInfo();

	inline static std::vector<ContainerData>& GetContainers() { return GetInstance()->m_containers; }
	inline static std::vector<ContainerData>& GetContainersAV() { return GetInstance()->m_containers_av; }
	inline static std::vector<VideoCodecData>& GetVideoCodecs() { return GetInstance()->m_video_codecs; }
	inline static std::vector<VideoCodecData>& GetVideoCodecsAV() { return GetInstance()->m_video_codecs_av; }
	inline static std::vector<AudioCodecData>& GetAudioCodecs() { return GetInstance()->m_audio_codecs; }
	inline static std::vector<AudioCodecData>& GetAudioCodecsAV() { return GetInstance()->m_audio_codecs_av; }

	inline static CodecInfo* GetInstance() { assert(s_instance != NULL); return s_instance; }

};

struct OutputSettings {

	std::string m_file;
	bool m_separate_files;
	enum_container m_container;
	std::string m_container_avname;

	enum_video_codec m_video_codec;
	std::string m_video_codec_avname;
	unsigned int m_video_kbit_rate;
	std::vector<std::pair<std::string, std::string> > m_video_options;
	bool m_video_allow_frame_skipping;

	enum_audio_codec m_audio_codec;
	std::string m_audio_codec_avname;
	unsigned int m_audio_kbit_rate;
	std::vector<std::pair<std::string, std::string> > m_audio_options;

	inline OutputSettings() { Defaults(); }
	void Defaults();
	void FromJSON(const SimpleJSON& json);
	void ToJSON(SimpleJSON& json);

};

void StringToOptions(const std::string& str);
std::string OptionsToString(const std::vector<std::pair<std::string, std::string> >& options);

