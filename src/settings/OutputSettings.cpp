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

#include "AVWrapper.h"
#include "EnumTranslator.h"
#include "Logger.h"

CodecInfo *CodecInfo::s_instance = NULL;

CodecInfo::CodecInfo() {
	assert(s_instance == NULL);
	s_instance = this;

	// main codecs
	QString diagfiles = tr("%1 files", "This appears in the file dialog, e.g. 'MP4 files'");
	m_containers = {
		{"Matroska (MKV)", "matroska", {"mkv"}, diagfiles.arg("Matroska") + " (*.mkv)",
			{VIDEO_CODEC_H264, VIDEO_CODEC_VP8, VIDEO_CODEC_THEORA},
			{AUDIO_CODEC_VORBIS, AUDIO_CODEC_MP3, AUDIO_CODEC_AAC, AUDIO_CODEC_UNCOMPRESSED}},
		{"MP4", "mp4", {"mp4"}, diagfiles.arg("MP4") + " (*.mp4)",
			{VIDEO_CODEC_H264},
			{AUDIO_CODEC_VORBIS, AUDIO_CODEC_MP3, AUDIO_CODEC_AAC}},
		{"WebM", "webm", {"webm"}, diagfiles.arg("WebM") + " (*.webm)",
			{VIDEO_CODEC_VP8},
			{AUDIO_CODEC_VORBIS}},
		{"OGG", "ogg", {"ogg"}, diagfiles.arg("OGG") + " (*.ogg)",
			{VIDEO_CODEC_THEORA},
			{AUDIO_CODEC_VORBIS}},
		{tr("Other..."), "other", {}, "", {}, {}},
	};
	m_video_codecs = {
		{"H.264"       , "libx264"  },
		{"VP8"         , "libvpx"   },
		{"Theora"      , "libtheora"},
		{tr("Other..."), "other"    },
	};
	m_audio_codecs = {
		{"Vorbis"          , "libvorbis"   },
		{"MP3"             , "libmp3lame"  },
		{"AAC"             , "libvo_aacenc"},
		{tr("Uncompressed"), "pcm_s16le"   },
		{tr("Other...")    , "other"       },
	};

	// alternative aac codec
	if(!AVCodecIsInstalled(m_audio_codecs[AUDIO_CODEC_AAC].avname)) {
		m_audio_codecs[AUDIO_CODEC_AAC].avname = "aac";
	}

	// load AV container list
	m_containers_av.clear();
	for(AVOutputFormat *format = av_oformat_next(NULL); format != NULL; format = av_oformat_next(format)) {
		if(format->video_codec == AV_CODEC_ID_NONE)
			continue;
		ContainerData c;
		c.name = format->long_name;
		c.avname = format->name;
		c.suffixes = QString(format->extensions).split(',', QString::SkipEmptyParts);
		if(c.suffixes.isEmpty()) {
			c.filter = "";
		} else {
			c.filter = diagfiles.arg(c.avname) + " (*." + c.suffixes[0];
			for(int i = 1; i < c.suffixes.size(); ++i) {
				c.suffixes[i] = c.suffixes[i].trimmed(); // needed because libav/ffmpeg isn't very consistent when they say 'comma-separated'
				c.filter += " *." + c.suffixes[i];
			}
			c.filter += ")";
		}
		m_containers_av.push_back(c);
	}
	std::sort(m_containers_av.begin(), m_containers_av.end());

	// load AV codec list
	m_video_codecs_av.clear();
	m_audio_codecs_av.clear();
	for(AVCodec *codec = av_codec_next(NULL); codec != NULL; codec = av_codec_next(codec)) {
		if(!av_codec_is_encoder(codec))
			continue;
		if(codec->type == AVMEDIA_TYPE_VIDEO && VideoEncoder::AVCodecIsSupported(codec->name)) {
			VideoCodecData c;
			c.name = codec->long_name;
			c.avname = codec->name;
			m_video_codecs_av.push_back(c);
		}
		if(codec->type == AVMEDIA_TYPE_AUDIO && AudioEncoder::AVCodecIsSupported(codec->name)) {
			AudioCodecData c;
			c.name = codec->long_name;
			c.avname = codec->name;
			m_audio_codecs_av.push_back(c);
		}
	}
	std::sort(m_video_codecs_av.begin(), m_video_codecs_av.end());
	std::sort(m_audio_codecs_av.begin(), m_audio_codecs_av.end());

	if(m_containers_av.empty()) {
		Logger::LogError("[PageOutput::PageOutput] " + tr("Error: Could not find any suitable container in libavformat!"));
		throw LibavException();
	}
	if(m_video_codecs_av.empty()) {
		Logger::LogError("[PageOutput::PageOutput] " + tr("Error: Could not find any suitable video codec in libavcodec!"));
		throw LibavException();
	}
	if(m_audio_codecs_av.empty()) {
		Logger::LogError("[PageOutput::PageOutput] " + tr("Error: Could not find any suitable audio codec in libavcodec!"));
		throw LibavException();
	}

}

CodecInfo::~CodecInfo() {
	assert(s_instance == this);
	s_instance = NULL;
}

void OutputSettings::Defaults() {

	// choose default container and codecs
	enum_container default_container = (enum_container) 0;
	for(unsigned int i = 0; i < VIDEO_CODEC_COUNT; ++i) {
		if(AVFormatIsInstalled(m_containers[i].avname)) {
			default_container = (enum_container) i;
			break;
		}
	}
	enum_video_codec default_video_codec = (enum_video_codec) 0;
	for(unsigned int i = 0; i < VIDEO_CODEC_COUNT; ++i) {
		if(AVCodecIsInstalled(m_video_codecs[i].avname) && m_containers[default_container].supported_video_codecs.count((enum_video_codec) i)) {
			default_video_codec = (enum_video_codec) i;
			break;
		}
	}
	enum_audio_codec default_audio_codec = (enum_audio_codec) 0;
	for(unsigned int i = 0; i < AUDIO_CODEC_COUNT; ++i) {
		if(AVCodecIsInstalled(m_audio_codecs[i].avname) && m_containers[default_container].supported_audio_codecs.count((enum_audio_codec) i)) {
			default_audio_codec = (enum_audio_codec) i;
			break;
		}
	}

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

		json["file"].GetString(m_file);
		json["separate_files"].GetBool(m_separate_files);
		json["container"].GetEnum(m_container);
		json["container_avname"].GetString(m_container_avname);

		json["video"]["codec"].GetEnum(m_video_codec);
		json["video"]["codec_avname"].GetString(m_video_codec_avname);
		json["video"]["kbit_rate"].GetNumber(m_video_kbit_rate);
		const SimpleJSON &video_options = json["video"]["options"];
		m_video_options.resize(video_options.GetMemberCount());
		for(size_t i = 0; i < video_options.GetMemberCount(); ++i) {
			video_options.GetMemberKey(i, m_video_options[i].first);
			video_options.GetMemberValue(i).GetString(m_video_options[i].second);
		}
		json["video"]["allow_frame_skipping"].GetBool(m_video_allow_frame_skipping);

		json["audio"]["codec"].GetEnum(m_audio_codec);
		json["audio"]["codec_avname"].GetString(m_audio_codec_avname);
		json["audio"]["kbit_rate"].GetNumber(m_audio_kbit_rate);
		const SimpleJSON &audio_options = json["audio"]["options"];
		m_audio_options.resize(audio_options.GetMemberCount());
		for(size_t i = 0; i < audio_options.GetMemberCount(); ++i) {
			audio_options.GetMemberKey(i, m_audio_options[i].first);
			audio_options.GetMemberValue(i).GetString(m_audio_options[i].second);
		}

	} catch(const JSONException&) {
		Logger::LogError("[OutputSettings::FromJSON] " + Logger::tr("Error: Invalid JSON data."));
	}
}

void OutputSettings::ToJSON(SimpleJSON& json) {

	json("file").SetString(m_file);
	json("separate_files").SetBool(m_separate_files);
	json("container").SetEnum(m_container);
	json("container_avname").SetString(m_container_avname);

	json("video")("codec").SetEnum(m_video_codec);
	json("video")("codec_avname").SetString(m_video_codec_avname);
	json("video")("kbit_rate").SetNumber(m_video_kbit_rate);
	const SimpleJSON &video_options = json("video")("options");
	video_options.ResetArray();
	for(auto &p : m_video_options) {
		video_options(p.first).SetString(p.second);
	}
	json("video")("allow_frame_skipping").SetBool(m_video_allow_frame_skipping);

	json("audio")("codec").SetEnum(m_video_codec);
	json("audio")("codec_avname").SetString(m_video_codec_avname);
	json("audio")("kbit_rate").SetNumber(m_video_kbit_rate);
	const SimpleJSON &audio_options = json("audio")("options");
	audio_options.ResetArray();
	for(auto &p : m_audio_options) {
		audio_options(p.first).SetString(p.second);
	}

}

void StringToOptions(const std::string& str) {
	std::vector<std::pair<std::string, std::string> > options;
	size_t p = 0;
	while(p < str.length()) {
		size_t q = str.find_first_of(',', p);
		if(q == std::string::npos)
			q = str.length();
		size_t r = str.find_first_of('=', p);
		if(r == std::string::npos || r >= q) {
			options.push_back(std::make_pair(Trim(str.substr(p, q - p)), std::string()));
		} else {
			options.push_back(std::make_pair(Trim(str.substr(p, r - p)), Trim(str.substr(r + 1, q - r - 1))));
		}
		p = q + 1;
	}
	return options;
}

std::string OptionsToString(const std::vector<std::pair<std::string, std::string> >& options) {
	std::string str;
	for(auto &p : options) {
		if(!str.empty())
			str += ',';
		str += p.first;
		str += '=';
		str += p.second;
	}
	return str;
}
