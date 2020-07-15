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

#include "PageOutput.h"

#include "Dialogs.h"
#include "EnumStrings.h"
#include "HiddenScrollArea.h"
#include "Icons.h"
#include "Logger.h"
#include "MainWindow.h"
#include "PageInput.h"

#include "AVWrapper.h"
#include "VideoEncoder.h"
#include "AudioEncoder.h"

ENUMSTRINGS(PageOutput::enum_container) = {
	{PageOutput::CONTAINER_MKV, "mkv"},
	{PageOutput::CONTAINER_MP4, "mp4"},
	{PageOutput::CONTAINER_WEBM, "webm"},
	{PageOutput::CONTAINER_OGG, "ogg"},
	{PageOutput::CONTAINER_OTHER, "other"},
};
ENUMSTRINGS(PageOutput::enum_video_codec) = {
	{PageOutput::VIDEO_CODEC_H264, "h264"},
	{PageOutput::VIDEO_CODEC_VP8, "vp8"},
	{PageOutput::VIDEO_CODEC_THEORA, "theora"},
	{PageOutput::VIDEO_CODEC_OTHER, "other"},
};
ENUMSTRINGS(PageOutput::enum_audio_codec) = {
	{PageOutput::AUDIO_CODEC_VORBIS, "vorbis"},
	{PageOutput::AUDIO_CODEC_MP3, "mp3"},
	{PageOutput::AUDIO_CODEC_AAC, "aac"},
	{PageOutput::AUDIO_CODEC_UNCOMPRESSED, "uncompressed"},
	{PageOutput::AUDIO_CODEC_OTHER, "other"},
};
ENUMSTRINGS(PageOutput::enum_h264_preset) = {
	{PageOutput::H264_PRESET_ULTRAFAST, "ultrafast"},
	{PageOutput::H264_PRESET_SUPERFAST, "superfast"},
	{PageOutput::H264_PRESET_VERYFAST, "veryfast"},
	{PageOutput::H264_PRESET_FASTER, "faster"},
	{PageOutput::H264_PRESET_FAST, "fast"},
	{PageOutput::H264_PRESET_MEDIUM, "medium"},
	{PageOutput::H264_PRESET_SLOW, "slow"},
	{PageOutput::H264_PRESET_SLOWER, "slower"},
	{PageOutput::H264_PRESET_VERYSLOW, "veryslow"},
	{PageOutput::H264_PRESET_PLACEBO, "placebo"},
};

static bool MatchSuffix(const QString& suffix, const QStringList& suffixes) {
	return ((suffix.isEmpty() && suffixes.isEmpty()) || suffixes.contains(suffix, Qt::CaseInsensitive));
}

PageOutput::PageOutput(MainWindow* main_window)
	: QWidget(main_window->centralWidget()) {

	m_main_window = main_window;

	m_old_container = (enum_container) 0;
	m_old_container_av = 0;

	// main codecs
	// (initializer lists should use explicit types for Clang)
	m_containers = {
		ContainerData({"Matroska (MKV)", "matroska", QStringList({"mkv"}), tr("%1 files", "This appears in the file dialog, e.g. 'MP4 files'").arg("Matroska") + " (*.mkv)",
			{VIDEO_CODEC_H264, VIDEO_CODEC_VP8, VIDEO_CODEC_THEORA},
			{AUDIO_CODEC_VORBIS, AUDIO_CODEC_MP3, AUDIO_CODEC_AAC, AUDIO_CODEC_UNCOMPRESSED}}),
		ContainerData({"MP4", "mp4", QStringList({"mp4"}), tr("%1 files", "This appears in the file dialog, e.g. 'MP4 files'").arg("MP4") + " (*.mp4)",
			{VIDEO_CODEC_H264},
			{AUDIO_CODEC_VORBIS, AUDIO_CODEC_MP3, AUDIO_CODEC_AAC}}),
		ContainerData({"WebM", "webm", QStringList({"webm"}), tr("%1 files", "This appears in the file dialog, e.g. 'MP4 files'").arg("WebM") + " (*.webm)",
			{VIDEO_CODEC_VP8},
			{AUDIO_CODEC_VORBIS}}),
		ContainerData({"OGG", "ogg", QStringList({"ogg"}), tr("%1 files", "This appears in the file dialog, e.g. 'MP4 files'").arg("OGG") + " (*.ogg)",
			{VIDEO_CODEC_THEORA},
			{AUDIO_CODEC_VORBIS}}),
		ContainerData({tr("Other..."), "other", QStringList(), "", std::set<enum_video_codec>({}), std::set<enum_audio_codec>({})}),
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
#if SSR_USE_AV_MUXER_ITERATE
	const AVOutputFormat *format;
	void *format_opaque = NULL;
	while((format = av_muxer_iterate(&format_opaque)) != NULL) {
#else
	for(AVOutputFormat *format = av_oformat_next(NULL); format != NULL; format = av_oformat_next(format)) {
#endif
		if(format->video_codec == AV_CODEC_ID_NONE)
			continue;
		ContainerData c;
		c.name = format->long_name;
		c.avname = format->name;
		c.suffixes = SplitSkipEmptyParts(format->extensions, ',');
		if(c.suffixes.isEmpty()) {
			c.filter = "";
		} else {
			c.filter = tr("%1 files", "This appears in the file dialog, e.g. 'MP4 files'").arg(c.avname) + " (*." + c.suffixes[0];
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
#if SSR_USE_AV_MUXER_ITERATE
	const AVCodec *codec;
	void *codec_opaque = NULL;
	while((codec = av_codec_iterate(&codec_opaque)) != NULL) {
#else
	for(AVCodec *codec = av_codec_next(NULL); codec != NULL; codec = av_codec_next(codec)) {
#endif
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

	HiddenScrollArea *scrollarea = new HiddenScrollArea(this);
	QWidget *scrollarea_contents = new QWidget(scrollarea);
	scrollarea->setWidget(scrollarea_contents);
	{
		m_profile_box = new ProfileBox(tr("Output profile"), scrollarea_contents, "output-profiles", &LoadProfileSettingsCallback, &SaveProfileSettingsCallback, this);

		QGroupBox *groupbox_file = new QGroupBox(tr("File"), scrollarea_contents);
		{
			QLabel *label_file = new QLabel(tr("Save as:"), groupbox_file);
			m_lineedit_file = new QLineEdit(groupbox_file);
			m_lineedit_file->setToolTip(tr("The recording will be saved to this location."));
			QPushButton *button_browse = new QPushButton(tr("Browse..."), groupbox_file);
			m_checkbox_separate_files = new QCheckBox(tr("Separate file per segment"), groupbox_file);
			m_checkbox_separate_files->setToolTip(tr("If checked, a separate video file will be created every time you pause and resume the recording."
													 "If unchecked, all recorded segments will be combined into a single video file."));
			m_checkbox_add_timestamp = new QCheckBox(tr("Add timestamp"), groupbox_file);
			m_checkbox_add_timestamp->setToolTip(tr("If checked, the current date and time will be appended to the file name automatically.\n"
													"If the original file name is 'test.mkv', the video will be saved as 'test-YYYY-MM-DD_HH.MM.SS.mkv'."));
			QLabel *label_container = new QLabel(tr("Container:"), groupbox_file);
			m_combobox_container = new QComboBox(groupbox_file);
			for(unsigned int i = 0; i < CONTAINER_COUNT; ++i) {
				QString name = "\u200e" + m_containers[i].name + "\u200e";
				if(i != CONTAINER_OTHER && !AVFormatIsInstalled(m_containers[i].avname))
					name += " \u200e" + tr("(not installed)") + "\u200e";
				m_combobox_container->addItem(name);
			}
			m_combobox_container->setToolTip(tr("The container (file format) that will be used to save the recording.\n"
												"Note that not all codecs are supported by all containers, and that not all media players can read all file formats.\n"
												"- Matroska (MKV) supports all the codecs, but is less well-known.\n"
												"- MP4 is the most well-known format and will play on almost any modern media player, but supports only H.264 video\n"
												"   (and many media players only support AAC audio).\n"
												"- WebM is intended for embedding video into websites (with the HTML5 <video> tag). The format was created by Google.\n"
												"   WebM is supported by default in Firefox, Chrome and Opera, and plugins are available for Internet Explorer and Safari.\n"
												"   It supports only VP8 and Vorbis.\n"
												"- OGG supports only Theora and Vorbis."));
			m_label_container_av = new QLabel(tr("Container name:"), groupbox_file);
			m_combobox_container_av = new QComboBox(groupbox_file);
			for(unsigned int i = 0; i < m_containers_av.size(); ++i) {
				ContainerData &c = m_containers_av[i];
				m_combobox_container_av->addItem(c.avname);
			}
			m_combobox_container_av->setToolTip(tr("For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work."));
			m_label_container_warning = new QLabel(tr("Warning: This format will produce unreadable files if the recording is interrupted! Consider using MKV instead."), groupbox_file);
			m_label_container_warning->setWordWrap(true);

			connect(m_combobox_container, SIGNAL(activated(int)), this, SLOT(OnUpdateSuffixAndContainerFields()));
			connect(m_combobox_container_av, SIGNAL(activated(int)), this, SLOT(OnUpdateSuffixAndContainerFields()));
			connect(button_browse, SIGNAL(clicked()), this, SLOT(OnBrowse()));

			QGridLayout *layout = new QGridLayout(groupbox_file);
			layout->addWidget(label_file, 0, 0);
			layout->addWidget(m_lineedit_file, 0, 1);
			layout->addWidget(button_browse, 0, 2);
			{
				QHBoxLayout *layout2 = new QHBoxLayout();
				layout->addLayout(layout2, 1, 0, 1, 3);
				layout2->addWidget(m_checkbox_separate_files);
				layout2->addWidget(m_checkbox_add_timestamp);
			}
			layout->addWidget(label_container, 2, 0);
			layout->addWidget(m_combobox_container, 2, 1, 1, 2);
			layout->addWidget(m_label_container_av, 3, 0);
			layout->addWidget(m_combobox_container_av, 3, 1, 1, 2);
			layout->addWidget(m_label_container_warning, 4, 0, 1, 3);
		}
		QGroupBox *groupbox_video = new QGroupBox(tr("Video"), scrollarea_contents);
		{
			QLabel *label_video_codec = new QLabel(tr("Codec:"), groupbox_video);
			m_combobox_video_codec = new QComboBox(groupbox_video);
			for(unsigned int i = 0; i < VIDEO_CODEC_COUNT; ++i) {
				m_combobox_video_codec->addItem(m_video_codecs[i].name);
			}
			m_combobox_video_codec->setToolTip(tr("The codec that will be used to compress the video stream.\n"
												  "- H.264 (libx264) is by far the best codec - high quality and very fast.\n"
												  "- VP8 (libvpx) is quite good but also quite slow.\n"
												  "- Theora (libtheora) isn't really recommended because the quality isn't very good."));
			m_label_video_codec_av = new QLabel(tr("Codec name:"), groupbox_video);
			m_combobox_video_codec_av = new QComboBox(groupbox_video);
			for(unsigned int i = 0; i < m_video_codecs_av.size(); ++i) {
				VideoCodecData &c = m_video_codecs_av[i];
				m_combobox_video_codec_av->addItem(c.avname);
			}
			m_combobox_video_codec_av->setToolTip(tr("For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work."));
			m_label_video_kbit_rate = new QLabel(tr("Bit rate (in kbit/s):"), groupbox_video);
			m_lineedit_video_kbit_rate = new QLineEdit(groupbox_video);
			m_lineedit_video_kbit_rate->setToolTip(tr("The video bit rate (in kilobit per second). A higher value means a higher quality."
													  "\nIf you have no idea where to start, try 5000 and change it if needed."));
			m_label_h264_crf = new QLabel(tr("Constant rate factor:", "libx264 setting: don't translate this unless you can come up with something sensible"), groupbox_video);
			m_slider_h264_crf = new QSlider(Qt::Horizontal, groupbox_video);
			m_slider_h264_crf->setRange(0, 51);
			m_slider_h264_crf->setSingleStep(1);
			m_slider_h264_crf->setPageStep(5);
			m_slider_h264_crf->setToolTip(tr("This setting changes the video quality. A lower value means a higher quality.\n"
											 "The allowed range is 0-51 (0 means lossless, the default is 23)."));
			m_label_h264_crf_value = new QLabel(groupbox_video);
			m_label_h264_crf_value->setNum(m_slider_h264_crf->value());
			m_label_h264_crf_value->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
			m_label_h264_crf_value->setMinimumWidth(GetTextWidth(m_label_h264_crf_value->font(), "99") + 2);
			m_label_h264_preset = new QLabel(tr("Preset:", "libx264 setting: don't translate this unless you can come up with something sensible"), groupbox_video);
			m_combobox_h264_preset = new QComboBox(groupbox_video);
			for(unsigned int i = 0; i < H264_PRESET_COUNT; ++i) {
				m_combobox_h264_preset->addItem(EnumToString((enum_h264_preset) i));
			}
			m_combobox_h264_preset->setToolTip(tr("The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),\n"
												  "but results in larger files. The quality shouldn't be affected too much."));
			m_label_vp8_cpu_used = new QLabel(tr("CPU used:", "libvpx setting: don't translate this unless you can come up with something sensible"), groupbox_video);
			m_combobox_vp8_cpu_used = new QComboBox(groupbox_video);
			m_combobox_vp8_cpu_used->addItem("5 (" + tr("fastest") + ")");
			m_combobox_vp8_cpu_used->addItem("4");
			m_combobox_vp8_cpu_used->addItem("3");
			m_combobox_vp8_cpu_used->addItem("2");
			m_combobox_vp8_cpu_used->addItem("1");
			m_combobox_vp8_cpu_used->addItem("0 (" + tr("slowest") + ")");
			m_combobox_vp8_cpu_used->setToolTip(tr("The encoding speed. A higher value uses *less* CPU time. (I didn't choose the name, this is the name\n"
												   "used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too."));
			m_label_video_options = new QLabel(tr("Custom options:"), groupbox_video);
			m_lineedit_video_options = new QLineEdit(groupbox_video);
			m_lineedit_video_options->setToolTip(tr("Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)"));
			m_checkbox_video_allow_frame_skipping = new QCheckBox(tr("Allow frame skipping"), groupbox_video);
			m_checkbox_video_allow_frame_skipping->setToolTip(tr("If checked, the video encoder will be allowed to skip frames if the input frame rate is\n"
																 "lower than the output frame rate. If not checked, input frames will be duplicated to fill the holes.\n"
																 "This increases the file size and CPU usage, but reduces the latency for live streams in some cases.\n"
																 "It shouldn't affect the appearance of the video."));

			connect(m_combobox_video_codec, SIGNAL(activated(int)), this, SLOT(OnUpdateVideoCodecFields()));
			connect(m_slider_h264_crf, SIGNAL(valueChanged(int)), m_label_h264_crf_value, SLOT(setNum(int)));

			QGridLayout *layout = new QGridLayout(groupbox_video);
			layout->addWidget(label_video_codec, 0, 0);
			layout->addWidget(m_combobox_video_codec, 0, 1, 1, 2);
			layout->addWidget(m_label_video_codec_av, 1, 0);
			layout->addWidget(m_combobox_video_codec_av, 1, 1, 1, 2);
			layout->addWidget(m_label_video_kbit_rate, 2, 0);
			layout->addWidget(m_lineedit_video_kbit_rate, 2, 1, 1, 2);
			layout->addWidget(m_label_h264_crf, 3, 0);
			layout->addWidget(m_slider_h264_crf, 3, 1);
			layout->addWidget(m_label_h264_crf_value, 3, 2);
			layout->addWidget(m_label_h264_preset, 4, 0);
			layout->addWidget(m_combobox_h264_preset, 4, 1, 1, 2);
			layout->addWidget(m_label_vp8_cpu_used, 5, 0);
			layout->addWidget(m_combobox_vp8_cpu_used, 5, 1, 1, 2);
			layout->addWidget(m_label_video_options, 6, 0);
			layout->addWidget(m_lineedit_video_options, 6, 1, 1, 2);
			layout->addWidget(m_checkbox_video_allow_frame_skipping, 7, 0, 1, 3);
		}
		m_groupbox_audio = new QGroupBox(tr("Audio"), scrollarea_contents);
		{
			QLabel *label_audio_codec = new QLabel(tr("Codec:"), m_groupbox_audio);
			m_combobox_audio_codec = new QComboBox(m_groupbox_audio);
			for(unsigned int i = 0; i < AUDIO_CODEC_COUNT; ++i) {
				m_combobox_audio_codec->addItem(m_audio_codecs[i].name);
			}
			m_combobox_audio_codec->setToolTip(tr("The codec that will be used to compress the audio stream. You shouldn't worry too much about\n"
												  "this, because the size of the audio data is usually negligible compared to the size of the video data.\n"
												  "And if you're only recording your own voice (i.e. no music), the quality won't matter that much anyway.\n"
												  "- Vorbis (libvorbis) is great, this is the recommended codec.\n"
												  "- MP3 (libmp3lame) is reasonably good.\n"
												  "- AAC is a good codec, but the implementations used here (libvo_aacenc or the experimental ffmpeg aac encoder)\n"
												  "   are pretty bad. Only use it if you have no other choice.\n"
												  "- Uncompressed will simply store the sound data without compressing it. The file will be quite large, but it's very fast."));
			m_label_audio_codec_av = new QLabel(tr("Codec name:"), m_groupbox_audio);
			m_combobox_audio_codec_av = new QComboBox(m_groupbox_audio);
			for(unsigned int i = 0; i < m_audio_codecs_av.size(); ++i) {
				AudioCodecData &c = m_audio_codecs_av[i];
				m_combobox_audio_codec_av->addItem(c.avname);
			}
			m_combobox_audio_codec_av->setToolTip(tr("For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work."));
			m_label_audio_kbit_rate = new QLabel(tr("Bit rate (in kbit/s):"), m_groupbox_audio);
			m_lineedit_audio_kbit_rate = new QLineEdit(m_groupbox_audio);
			m_lineedit_audio_kbit_rate->setToolTip(tr("The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128."));
			m_label_audio_options = new QLabel(tr("Custom options:"), m_groupbox_audio);
			m_lineedit_audio_options = new QLineEdit(m_groupbox_audio);
			m_lineedit_audio_options->setToolTip(tr("Custom codec options separated by commas (e.g. option1=value1,option2=value2,option3=value3)"));

			connect(m_combobox_audio_codec, SIGNAL(activated(int)), this, SLOT(OnUpdateAudioCodecFields()));

			QGridLayout *layout = new QGridLayout(m_groupbox_audio);
			layout->addWidget(label_audio_codec, 0, 0);
			layout->addWidget(m_combobox_audio_codec, 0, 1);
			layout->addWidget(m_label_audio_codec_av, 1, 0);
			layout->addWidget(m_combobox_audio_codec_av, 1, 1);
			layout->addWidget(m_label_audio_kbit_rate, 2, 0);
			layout->addWidget(m_lineedit_audio_kbit_rate, 2, 1);
			layout->addWidget(m_label_audio_options, 3, 0);
			layout->addWidget(m_lineedit_audio_options, 3, 1);
		}

		QVBoxLayout *layout = new QVBoxLayout(scrollarea_contents);
		layout->addWidget(m_profile_box);
		layout->addWidget(groupbox_file);
		layout->addWidget(groupbox_video);
		layout->addWidget(m_groupbox_audio);
		layout->addStretch();
	}
	QPushButton *button_back = new QPushButton(g_icon_go_previous, tr("Back"), this);
	QPushButton *button_continue = new QPushButton(g_icon_go_next, tr("Continue"), this);

	connect(button_back, SIGNAL(clicked()), m_main_window, SLOT(GoPageInput()));
	connect(button_continue, SIGNAL(clicked()), this, SLOT(OnContinue()));

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(scrollarea);
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addSpacing(style()->pixelMetric(QStyle::PM_LayoutLeftMargin));
		layout2->addWidget(button_back);
		layout2->addWidget(button_continue);
		layout2->addSpacing(style()->pixelMetric(QStyle::PM_LayoutRightMargin));
	}
	layout->addSpacing(style()->pixelMetric(QStyle::PM_LayoutBottomMargin));

	// temporary settings to calculate the worst-case size
	SetContainer(CONTAINER_OTHER);
	SetVideoCodec(VIDEO_CODEC_OTHER);
	SetAudioCodec(AUDIO_CODEC_OTHER);

	OnUpdateContainerFields();
	OnUpdateVideoCodecFields();
	OnUpdateAudioCodecFields();

}

void PageOutput::LoadSettings(QSettings* settings) {
	SetProfile(m_profile_box->FindProfile(settings->value("output/profile", QString()).toString()));
	LoadProfileSettings(settings);
}

void PageOutput::SaveSettings(QSettings* settings) {
	settings->setValue("output/profile", m_profile_box->GetProfileName());
	SaveProfileSettings(settings);
}

void PageOutput::LoadProfileSettingsCallback(QSettings* settings, void* userdata) {
	PageOutput *page = (PageOutput*) userdata;
	page->LoadProfileSettings(settings);
}

void PageOutput::SaveProfileSettingsCallback(QSettings* settings, void* userdata) {
	PageOutput *page = (PageOutput*) userdata;
	page->SaveProfileSettings(settings);
}

void PageOutput::LoadProfileSettings(QSettings* settings) {

	// choose default container and codecs
	enum_container default_container = (enum_container) 0;
	for(unsigned int i = 0; i < CONTAINER_OTHER; ++i) {
		if(AVFormatIsInstalled(m_containers[i].avname)) {
			default_container = (enum_container) i;
			break;
		}
	}
	enum_video_codec default_video_codec = (enum_video_codec) 0;
	for(unsigned int i = 0; i < VIDEO_CODEC_OTHER; ++i) {
		if(AVCodecIsInstalled(m_video_codecs[i].avname) && m_containers[default_container].supported_video_codecs.count((enum_video_codec) i)) {
			default_video_codec = (enum_video_codec) i;
			break;
		}
	}
	enum_audio_codec default_audio_codec = (enum_audio_codec) 0;
	for(unsigned int i = 0; i < VIDEO_CODEC_OTHER; ++i) {
		if(AVCodecIsInstalled(m_audio_codecs[i].avname) && m_containers[default_container].supported_audio_codecs.count((enum_audio_codec) i)) {
			default_audio_codec = (enum_audio_codec) i;
			break;
		}
	}

	// choose default file name
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
	QString dir_videos = QStandardPaths::writableLocation(QStandardPaths::MoviesLocation);
	QString dir_documents = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
#else
	QString dir_videos = QDesktopServices::storageLocation(QDesktopServices::MoviesLocation);
	QString dir_documents = QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation);
#endif
	QString dir_home = QDir::homePath();
	QString best_dir = (QDir(dir_videos).exists())? dir_videos : (QDir(dir_documents).exists())? dir_documents : dir_home;
	QString default_file = best_dir + "/simplescreenrecorder." + m_containers[default_container].suffixes[0];

	// load settings
	SetFile(settings->value("output/file", default_file).toString());
	SetSeparateFiles(settings->value("output/separate_files", false).toBool());
	SetAddTimestamp(settings->value("output/add_timestamp", true).toBool());
	SetContainer(StringToEnum(settings->value("output/container", QString()).toString(), default_container));
	SetContainerAV(FindContainerAV(settings->value("output/container_av", QString()).toString()));

	SetVideoCodec(StringToEnum(settings->value("output/video_codec", QString()).toString(), default_video_codec));
	SetVideoCodecAV(FindVideoCodecAV(settings->value("output/video_codec_av", QString()).toString()));
	SetVideoKBitRate(settings->value("output/video_kbit_rate", 5000).toUInt());
	SetH264CRF(settings->value("output/video_h264_crf", 23).toUInt());
	SetH264Preset((enum_h264_preset) settings->value("output/video_h264_preset", H264_PRESET_SUPERFAST).toUInt());
	SetVP8CPUUsed(settings->value("output/video_vp8_cpu_used", 5).toUInt());
	SetVideoOptions(settings->value("output/video_options", "").toString());
	SetVideoAllowFrameSkipping(settings->value("output/video_allow_frame_skipping", true).toBool());

	SetAudioCodec(StringToEnum(settings->value("output/audio_codec", QString()).toString(), default_audio_codec));
	SetAudioCodecAV(FindAudioCodecAV(settings->value("output/audio_codec_av", QString()).toString()));
	SetAudioKBitRate(settings->value("output/audio_kbit_rate", 128).toUInt());
	SetAudioOptions(settings->value("output/audio_options", "").toString());

	// update things
	OnUpdateContainerFields();
	OnUpdateVideoCodecFields();
	OnUpdateAudioCodecFields();

}

void PageOutput::SaveProfileSettings(QSettings* settings) {

	settings->setValue("output/file", GetFile());
	settings->setValue("output/separate_files", GetSeparateFiles());
	settings->setValue("output/add_timestamp", GetAddTimestamp());
	settings->setValue("output/container", EnumToString(GetContainer()));
	settings->setValue("output/container_av", m_containers_av[GetContainerAV()].avname);

	settings->setValue("output/video_codec", EnumToString(GetVideoCodec()));
	settings->setValue("output/video_codec_av", m_video_codecs_av[GetVideoCodecAV()].avname);
	settings->setValue("output/video_kbit_rate", GetVideoKBitRate());
	settings->setValue("output/video_h264_crf", GetH264CRF());
	settings->setValue("output/video_h264_preset", GetH264Preset());
	settings->setValue("output/video_vp8_cpu_used", GetVP8CPUUsed());
	settings->setValue("output/video_options", GetVideoOptions());
	settings->setValue("output/video_allow_frame_skipping", GetVideoAllowFrameSkipping());

	settings->setValue("output/audio_codec", EnumToString(GetAudioCodec()));
	settings->setValue("output/audio_codec_av", m_audio_codecs_av[GetAudioCodecAV()].avname);
	settings->setValue("output/audio_kbit_rate", GetAudioKBitRate());
	settings->setValue("output/audio_options", GetAudioOptions());

}

void PageOutput::StartPage() {

	// only show audio settings if audio is enabled
	m_groupbox_audio->setVisible(m_main_window->GetPageInput()->GetAudioEnabled());

}

bool PageOutput::Validate() {
	QString file = GetFile();
	if(file.isEmpty()) {
		MessageBox(QMessageBox::Critical, this, MainWindow::WINDOW_CAPTION, tr("You did not select an output file!"), BUTTON_OK, BUTTON_OK);
		return false;
	}
	/*if(GetFileProtocol().isNull() && !GetSeparateFiles() && QFileInfo(file).exists()) {
		if(MessageBox(QMessageBox::Warning, this, MainWindow::WINDOW_CAPTION,
					  tr("The file '%1' already exists. Are you sure that you want to overwrite it?").arg(QFileInfo(file).fileName()),
					  BUTTON_YES | BUTTON_NO, BUTTON_YES) != BUTTON_YES) {
			return false;
		}
	}*/
	return true;
}

QString PageOutput::GetFileProtocol() {
	QRegExp protocol_regex("^([a-z0-9]+)://", Qt::CaseInsensitive, QRegExp::RegExp);
	if(protocol_regex.indexIn(GetFile()) < 0) {
		return QString();
	}
	return protocol_regex.cap(1);
}

QString PageOutput::GetContainerAVName() {
	enum_container container = GetContainer();
	if(container != CONTAINER_OTHER)
		return m_containers[container].avname;
	else
		return m_containers_av[GetContainerAV()].avname;
}

QString PageOutput::GetVideoCodecAVName() {
	enum_video_codec video_codec = GetVideoCodec();
	if(video_codec != VIDEO_CODEC_OTHER)
		return m_video_codecs[video_codec].avname;
	else
		return m_video_codecs_av[GetVideoCodecAV()].avname;
}

QString PageOutput::GetAudioCodecAVName() {
	enum_audio_codec audio_codec = GetAudioCodec();
	if(audio_codec != AUDIO_CODEC_OTHER)
		return m_audio_codecs[audio_codec].avname;
	else
		return m_audio_codecs_av[GetAudioCodecAV()].avname;
}

unsigned int PageOutput::FindContainerAV(const QString& name) {
	for(unsigned int i = 0; i < m_containers_av.size(); ++i) {
		if(m_containers_av[i].avname == name)
			return i;
	}
	return 0;
}

unsigned int PageOutput::FindVideoCodecAV(const QString& name) {
	for(unsigned int i = 0; i < m_video_codecs_av.size(); ++i) {
		if(m_video_codecs_av[i].avname == name)
			return i;
	}
	return 0;
}

unsigned int PageOutput::FindAudioCodecAV(const QString& name) {
	for(unsigned int i = 0; i < m_audio_codecs_av.size(); ++i) {
		if(m_audio_codecs_av[i].avname == name)
			return i;
	}
	return 0;
}

void PageOutput::OnUpdateSuffixAndContainerFields() {

	// change file extension
	enum_container new_container = GetContainer();
	unsigned int new_container_av = GetContainerAV();
	if(GetFileProtocol().isNull()) {
		QStringList old_suffixes = (m_old_container == CONTAINER_OTHER)? m_containers_av[m_old_container_av].suffixes : m_containers[m_old_container].suffixes;
		QStringList new_suffixes = (new_container == CONTAINER_OTHER)? m_containers_av[new_container_av].suffixes : m_containers[new_container].suffixes;
		QString file = GetFile();
		if(!file.isEmpty()) {
			QFileInfo fi(file);
			if(MatchSuffix(fi.suffix(), old_suffixes) && !MatchSuffix(fi.suffix(), new_suffixes)) {
				if(new_suffixes.isEmpty())
					m_lineedit_file->setText(fi.path() + "/" + fi.completeBaseName());
				else
					m_lineedit_file->setText(fi.path() + "/" + fi.completeBaseName() + "." + new_suffixes[0]);
			}
		}
	}

	// update fields
	OnUpdateContainerFields();

}

void PageOutput::OnUpdateContainerFields() {

	enum_container container = GetContainer();
	unsigned int container_av = GetContainerAV();

	// show/hide fields
	GroupVisible({m_label_container_av, m_combobox_container_av}, (container == CONTAINER_OTHER));

	// show/hide warning
	m_label_container_warning->setVisible(GetContainerAVName() == "mp4");

	// mark uninstalled or unsupported codecs
	for(unsigned int i = 0; i < VIDEO_CODEC_OTHER; ++i) {
		QString name = m_video_codecs[i].name;
		if(!AVCodecIsInstalled(m_video_codecs[i].avname))
			name += " (" + tr("not installed") + ")";
		else if(container != CONTAINER_OTHER && !m_containers[container].supported_video_codecs.count((enum_video_codec) i))
			name += " (" + tr("not supported by container") + ")";
		m_combobox_video_codec->setItemText(i, name);
	}
	for(unsigned int i = 0; i < AUDIO_CODEC_OTHER; ++i) {
		QString name = m_audio_codecs[i].name;
		if(!AVCodecIsInstalled(m_audio_codecs[i].avname))
			name += " (" + tr("not installed") + ")";
		else if(container != CONTAINER_OTHER && !m_containers[container].supported_audio_codecs.count((enum_audio_codec) i))
			name += " (" + tr("not supported by container") + ")";
		m_combobox_audio_codec->setItemText(i, name);
	}

	m_old_container = container;
	m_old_container_av = container_av;

}

void PageOutput::OnUpdateVideoCodecFields() {
	enum_video_codec codec = GetVideoCodec();
	MultiGroupVisible({
		{{m_label_video_kbit_rate, m_lineedit_video_kbit_rate}, (codec != VIDEO_CODEC_H264)},
		{{m_label_h264_crf, m_slider_h264_crf, m_label_h264_crf_value, m_label_h264_preset, m_combobox_h264_preset}, (codec == VIDEO_CODEC_H264)},
		{{m_label_vp8_cpu_used, m_combobox_vp8_cpu_used}, (codec == VIDEO_CODEC_VP8)},
		{{m_label_video_codec_av, m_combobox_video_codec_av, m_label_video_options, m_lineedit_video_options}, (codec == VIDEO_CODEC_OTHER)},
	});
}

void PageOutput::OnUpdateAudioCodecFields() {
	enum_audio_codec codec = GetAudioCodec();
	MultiGroupVisible({
		{{m_label_audio_kbit_rate, m_lineedit_audio_kbit_rate}, (codec != AUDIO_CODEC_UNCOMPRESSED)},
		{{m_label_audio_codec_av, m_combobox_audio_codec_av, m_label_audio_options, m_lineedit_audio_options}, (codec == AUDIO_CODEC_OTHER)},
	});
}

void PageOutput::OnBrowse() {

	QString filters;
	for(int i = 0; i < CONTAINER_OTHER; ++i) {
		if(i != 0)
			filters += ";;";
		filters += m_containers[i].filter;
	}
	for(unsigned int i = 0; i < m_containers_av.size(); ++i) {
		if(!m_containers_av[i].filter.isEmpty())
			filters += ";;" + m_containers_av[i].filter;
	}

	enum_container container = GetContainer();
	unsigned int container_av = GetContainerAV();
	QString selected_filter = (container == CONTAINER_OTHER)? m_containers_av[container_av].filter : m_containers[container].filter;
	QString selected_file = QFileDialog::getSaveFileName(this, tr("Save recording as"),
		GetFile(), filters, &selected_filter, QFileDialog::DontConfirmOverwrite);

	if(selected_file.isNull())
		return;

	m_lineedit_file->clear();
	QFileInfo fi(selected_file);
	if(fi.suffix().isEmpty()) {
		QStringList suffixes = (container == CONTAINER_OTHER)? m_containers_av[container_av].suffixes : m_containers[container].suffixes;
		if(!suffixes.isEmpty())
			selected_file += "." + suffixes[0];
	} else {
		bool found = false;
		for(int i = 0; i < CONTAINER_OTHER; ++i) {
			if(m_containers[i].suffixes.contains(fi.suffix(), Qt::CaseInsensitive)) {
				SetContainer((enum_container) i);
				found = true;
				break;
			}
		}
		if(!found) {
			for(unsigned int i = 0; i < m_containers_av.size(); ++i) {
				if(m_containers_av[i].suffixes.contains(fi.suffix(), Qt::CaseInsensitive)) {
					SetContainer(CONTAINER_OTHER);
					SetContainerAV(i);
					break;
				}
			}
		}
	}
	SetFile(selected_file);

	OnUpdateContainerFields();

}

void PageOutput::OnContinue() {
	if(!Validate())
		return;
	m_main_window->GoPageRecord();
}
