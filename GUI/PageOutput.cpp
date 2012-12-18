/*
Copyright (c) 2012 Maarten Baert <maarten-baert@hotmail.com>

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

#include "StdAfx.h"
#include "PageOutput.h"

#include "MainWindow.h"
#include "PageInput.h"

PageOutput::ContainerData PageOutput::s_container_data[PageOutput::CONTAINER_COUNT] = {
	{"Matroska (MKV)", "mkv" , "Matroska files (*.mkv)", "matroska", false, {1, 1, 1}, {1, 1, 1, 1}},
	{"MP4"           , "mp4" , "MP4 files (*.mp4)"     , "mp4"     , false, {1, 0, 0}, {1, 1, 1, 0}},
	{"WebM"          , "webm", "WebM files (*.webm)"   , "webm"    , false, {0, 1, 0}, {1, 0, 0, 0}},
	{"OGG"           , "ogg" , "OGG files (*.ogg)"     , "ogg"     , false, {0, 0, 1}, {1, 0, 0, 0}},
};
PageOutput::VideoCodecData PageOutput::s_video_codec_data[PageOutput::VIDEO_CODEC_COUNT] = {
	{"H.264" , "libx264"  , false},
	{"VP8"   , "libvpx"   , false},
	{"Theora", "libtheora", false},
};
PageOutput::AudioCodecData PageOutput::s_audio_codec_data[PageOutput::AUDIO_CODEC_COUNT] = {
	{"Vorbis"      , "libvorbis"   , false},
	{"MP3"         , "libmp3lame"  , false},
	{"AAC"         , "libvo_aacenc", false},
	{"Uncompressed", "pcm_s16le"   , false},
};
const char* PageOutput::s_h264_preset_strings[PageOutput::H264_PRESET_COUNT] = {
	"ultrafast", "superfast", "veryfast", "faster", "fast",
	"medium", "slow", "slower", "veryslow", "placebo",
};

PageOutput::PageOutput(MainWindow* main_window)
	: QWidget(main_window->centralWidget()) {

	m_main_window = main_window;

	// find out what containers and codecs are available
	for(unsigned int i = 0; i < CONTAINER_COUNT; ++i) {
		s_container_data[i].installed = (av_guess_format(s_container_data[i].avname, NULL, NULL) != NULL);
	}
	for(unsigned int i = 0; i < VIDEO_CODEC_COUNT; ++i) {
		s_video_codec_data[i].installed = (avcodec_find_encoder_by_name(s_video_codec_data[i].avname) != NULL);
	}
	for(unsigned int i = 0; i < AUDIO_CODEC_COUNT; ++i) {
		s_audio_codec_data[i].installed = (avcodec_find_encoder_by_name(s_audio_codec_data[i].avname) != NULL);
	}

	QGroupBox *groupbox_file = new QGroupBox("File", this);
	{
		m_old_container = (enum_container) 0;
		QLabel *label_container = new QLabel("Container:", groupbox_file);
		m_combobox_container = new QComboBox(groupbox_file);
		for(unsigned int i = 0; i < CONTAINER_COUNT; ++i) {
			m_combobox_container->addItem(s_container_data[i].name);
		}
		m_combobox_container->setToolTip("The container (file format) that will be used to save the recording.\n"
										 "Note that not all codecs are supported by all containers, and that not all media players can read all file formats.\n"
										 "- Matroska (MKV) supports all the codecs, but is less well-known.\n"
										 "- MP4 is the most well-known format and will play on almost any modern media player, but supports only H.264 video\n"
										 "   (and many media players only support AAC audio).\n"
										 "- WebM is intended for embedding video into websites (with the HTML5 <video> tag). The format was created by Google.\n"
										 "   WebM is supported by default in Firefox, Chrome and Opera, and plugins are available for Internet Explorer and Safari.\n"
										 "   It supports only VP8 and Vorbis.\n"
										 "- OGG supports only Theora and Vorbis.");
		QLabel *label_file = new QLabel("Save as:", groupbox_file);
		m_lineedit_file = new QLineEdit(groupbox_file);
		m_lineedit_file->setToolTip("The recording will be saved to this location.");
		QPushButton *button_browse = new QPushButton("Browse...", groupbox_file);

		connect(m_combobox_container, SIGNAL(activated(int)), this, SLOT(UpdateContainerSupport()));
		connect(button_browse, SIGNAL(clicked()), this, SLOT(Browse()));

		QGridLayout *layout = new QGridLayout(groupbox_file);
		layout->addWidget(label_container, 0, 0);
		layout->addWidget(m_combobox_container, 0, 1, 1, 2);
		layout->addWidget(label_file, 1, 0);
		layout->addWidget(m_lineedit_file, 1, 1);
		layout->addWidget(button_browse, 1, 2);
	}
	QGroupBox *groupbox_video = new QGroupBox("Video", this);
	{
		QLabel *label_videocodec = new QLabel("Codec:", groupbox_video);
		m_combobox_video_codec = new QComboBox(groupbox_video);
		for(unsigned int i = 0; i < VIDEO_CODEC_COUNT; ++i) {
			m_combobox_video_codec->addItem(s_video_codec_data[i].name);
		}
		m_combobox_video_codec->setToolTip("The codec that will be used to compress the video stream.\n"
										   "- H.264 (libx264) is by far the best codec - high quality and very fast.\n"
										   "- VP8 (libvpx) is quite good but also quite slow.\n"
										   "- Theora (libtheora) isn't really recommended because the quality isn't very good.");
		m_label_video_bitrate = new QLabel("Bit rate (in kbps):", groupbox_video);
		m_lineedit_video_kbit_rate = new QLineEdit(groupbox_video);
		m_lineedit_video_kbit_rate->setToolTip("The video bit rate (in kilobit per second). A higher value means a higher quality."
											 "\nIf you have no idea where to start, try 5000 and change it if needed.");
		m_label_h264_crf = new QLabel("Constant rate factor:", groupbox_video);
		m_lineedit_h264_crf = new QLineEdit(groupbox_video);
		m_lineedit_h264_crf->setToolTip("This setting changes the video quality. A lower value means a higher quality.\n"
										"The allowed range is 0-51 (0 means lossless, the default is 23).");
		m_label_h264_preset = new QLabel("Preset:", groupbox_video);
		m_combobox_h264_preset = new QComboBox(groupbox_video);
		for(unsigned int i = 0; i < H264_PRESET_COUNT; ++i) {
			m_combobox_h264_preset->addItem(s_h264_preset_strings[i]);
		}
		m_combobox_h264_preset->setToolTip("The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),\n"
										   "but results in larger files. The quality shouldn't be affected too much.");
		m_label_vp8_cpu_used = new QLabel("CPU used:", groupbox_video);
		m_combobox_vp8_cpu_used = new QComboBox(groupbox_video);
		m_combobox_vp8_cpu_used->addItem("5 (fastest)");
		m_combobox_vp8_cpu_used->addItem("4");
		m_combobox_vp8_cpu_used->addItem("3");
		m_combobox_vp8_cpu_used->addItem("2");
		m_combobox_vp8_cpu_used->addItem("1 (slowest)");
		m_combobox_vp8_cpu_used->setToolTip("The encoding speed. A higher value uses less CPU, confusingly (I didn't invent the name, this is the name\n"
											"used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.");

		connect(m_combobox_video_codec, SIGNAL(activated(int)), this, SLOT(UpdateVideoCodecFields()));

		QGridLayout *layout = new QGridLayout(groupbox_video);
		layout->addWidget(label_videocodec, 0, 0);
		layout->addWidget(m_combobox_video_codec, 0, 1);
		layout->addWidget(m_label_video_bitrate, 1, 0);
		layout->addWidget(m_lineedit_video_kbit_rate, 1, 1);
		layout->addWidget(m_label_h264_crf, 2, 0);
		layout->addWidget(m_lineedit_h264_crf, 2, 1);
		layout->addWidget(m_label_h264_preset, 3, 0);
		layout->addWidget(m_combobox_h264_preset, 3, 1);
		layout->addWidget(m_label_vp8_cpu_used, 4, 0);
		layout->addWidget(m_combobox_vp8_cpu_used, 4, 1);
	}
	m_group_audio = new QGroupBox("Audio");
	{
		QLabel *label_audiocodec = new QLabel("Codec:", m_group_audio);
		m_combobox_audio_codec = new QComboBox(m_group_audio);
		for(unsigned int i = 0; i < AUDIO_CODEC_COUNT; ++i) {
			m_combobox_audio_codec->addItem(s_audio_codec_data[i].name);
		}
		m_combobox_audio_codec->setToolTip("The codec that will be used to compress the audio stream. You shouldn't worry too much about\n"
										   "this, because the size of the audio data is usually negligible compared to the size of the video data.\n"
										   "And if you're only recording your own voice (i.e. no music), the quality won't matter that much anyway.\n"
										   "- Vorbis (libvorbis) is great, this is the recommended codec.\n"
										   "- MP3 (libmp3lame) is reasonably good.\n"
										   "- AAC is a good codec, but the implementation used here (libvo_aacenc) is pretty bad. Only use it if you\n"
										   "  have no other choice.\n"
										   "- Uncompressed will simply store the sound data without compressing it. The file will be quite large, but it's very fast.");
		QLabel *label_audio_bitrate = new QLabel("Bit rate (in kbps):", m_group_audio);
		m_lineedit_audio_kbit_rate = new QLineEdit(m_group_audio);
		m_lineedit_audio_kbit_rate->setToolTip("The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.");

		connect(m_combobox_audio_codec, SIGNAL(activated(int)), this, SLOT(UpdateAudioCodecFields()));

		QGridLayout *layout = new QGridLayout(m_group_audio);
		layout->addWidget(label_audiocodec, 0, 0);
		layout->addWidget(m_combobox_audio_codec, 0, 1);
		layout->addWidget(label_audio_bitrate, 1, 0);
		layout->addWidget(m_lineedit_audio_kbit_rate, 1, 1);
	}
	QPushButton *button_back = new QPushButton("Back", this);
	QPushButton *button_continue = new QPushButton("Continue", this);

	connect(button_back, SIGNAL(clicked()), m_main_window, SLOT(GoPageInput()));
	connect(button_continue, SIGNAL(clicked()), this, SLOT(Continue()));

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(groupbox_file);
	layout->addWidget(groupbox_video);
	layout->addWidget(m_group_audio);
	layout->addStretch();
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addWidget(button_back);
		layout2->addWidget(button_continue);
	}

}

void PageOutput::UpdateStreams() {
	m_group_audio->setVisible(m_main_window->GetPageInput()->GetAudioEnabled());
}

void PageOutput::LoadSettings(QSettings* settings) {
	enum_video_codec default_video_codec = (enum_video_codec) 0;
	for(unsigned int i = 0; i < VIDEO_CODEC_COUNT; ++i) {
		if(s_video_codec_data[i].installed) {
			default_video_codec = (enum_video_codec) i;
			break;
		}
	}
	enum_audio_codec default_audio_codec = (enum_audio_codec) 0;
	for(unsigned int i = 0; i < AUDIO_CODEC_COUNT; ++i) {
		if(s_audio_codec_data[i].installed) {
			default_audio_codec = (enum_audio_codec) i;
			break;
		}
	}
	SetContainer((enum_container) settings->value("output/container", CONTAINER_MKV).toUInt());
	SetFile(settings->value("output/file", "").toString());
	SetVideoCodec((enum_video_codec) settings->value("output/video/codec", default_video_codec).toUInt());
	SetVideoKBitRate(settings->value("output/video/kbit_rate", 5000).toUInt());
	SetH264CRF(settings->value("output/video/h264/crf", 23).toUInt());
	SetH264Preset((enum_h264_preset) settings->value("output/video/h264/preset", H264_PRESET_SUPERFAST).toUInt());
	SetVP8CPUUsed(settings->value("output/video/vp8/cpu_used", 5).toUInt());
	SetAudioCodec((enum_audio_codec) settings->value("output/audio/codec", default_audio_codec).toUInt());
	SetAudioKBitRate(settings->value("output/audio/kbit_rate", 128).toUInt());
	UpdateContainerSupport();
	UpdateVideoCodecFields();
	UpdateAudioCodecFields();
}

void PageOutput::SaveSettings(QSettings* settings) {
	settings->setValue("output/container", GetContainer());
	settings->setValue("output/file", GetFile());
	settings->setValue("output/video/codec", GetVideoCodec());
	settings->setValue("output/video/kbit_rate", GetVideoKBitRate());
	settings->setValue("output/video/h264/crf", GetH264CRF());
	settings->setValue("output/video/h264/preset", GetH264Preset());
	settings->setValue("output/video/vp8/cpu_used", GetVP8CPUUsed());
	settings->setValue("output/audio/codec", GetAudioCodec());
	settings->setValue("output/audio/kbit_rate", GetAudioKBitRate());
}

void PageOutput::UpdateContainerSupport() {
	enum_container container = GetContainer();
	QString file = m_lineedit_file->text();
	if(!file.isEmpty()) {
		QFileInfo fi(file);
		if(fi.suffix().compare(s_container_data[m_old_container].suffix, Qt::CaseInsensitive) == 0)
			m_lineedit_file->setText(fi.path() + "/" + fi.completeBaseName() + "." + s_container_data[container].suffix);
	}
	m_old_container = container;
	for(unsigned int i = 0; i < VIDEO_CODEC_COUNT; ++i) {
		QString name = s_video_codec_data[i].name;
		if(!s_container_data[container].video_codec[i])
			name += " (not supported by container)";
		else if(!s_video_codec_data[i].installed)
			name += " (not installed)";
		m_combobox_video_codec->setItemText(i, name);
	}
	for(unsigned int i = 0; i < AUDIO_CODEC_COUNT; ++i) {
		QString name = s_audio_codec_data[i].name;
		if(!s_container_data[container].audio_codec[i])
			name += " (not supported by container)";
		else if(!s_audio_codec_data[i].installed)
			name += " (not installed)";
		m_combobox_audio_codec->setItemText(i, name);
	}
}

void PageOutput::UpdateVideoCodecFields() {
	enum_video_codec codec = GetVideoCodec();
	m_label_video_bitrate->setVisible(codec != VIDEO_CODEC_H264);
	m_lineedit_video_kbit_rate->setVisible(codec != VIDEO_CODEC_H264);
	m_label_h264_crf->setVisible(codec == VIDEO_CODEC_H264);
	m_lineedit_h264_crf->setVisible(codec == VIDEO_CODEC_H264);
	m_label_h264_preset->setVisible(codec == VIDEO_CODEC_H264);
	m_combobox_h264_preset->setVisible(codec == VIDEO_CODEC_H264);
	m_label_vp8_cpu_used->setVisible(codec == VIDEO_CODEC_VP8);
	m_combobox_vp8_cpu_used->setVisible(codec == VIDEO_CODEC_VP8);
}

void PageOutput::UpdateAudioCodecFields() {
	enum_audio_codec codec = GetAudioCodec();
	m_lineedit_audio_kbit_rate->setEnabled(codec != AUDIO_CODEC_UNCOMPRESSED);
}

void PageOutput::Browse() {
	int container_index = clamp(0, CONTAINER_COUNT - 1, m_combobox_container->currentIndex());
	QString filters;
	for(int i = 0; i < CONTAINER_COUNT; ++i) {
		if(i != 0)
			filters += ";;";
		filters += s_container_data[i].filter;
	}
	QString selected_filter = s_container_data[container_index].filter;
	QString selected_file = QFileDialog::getSaveFileName(this, "Save recording as",
		m_lineedit_file->text(), filters, &selected_filter, QFileDialog::DontConfirmOverwrite);
	if(!selected_file.isNull()) {
		m_lineedit_file->clear();
		QFileInfo fi(selected_file);
		for(int i = 0; i < CONTAINER_COUNT; ++i) {
			if(fi.suffix().compare(s_container_data[i].suffix, Qt::CaseInsensitive) == 0) {
				container_index = i;
				m_combobox_container->setCurrentIndex(i);
				break;
			}
		}
		if(fi.suffix().isEmpty())
			selected_file += QString(".") + s_container_data[container_index].suffix;
		m_lineedit_file->setText(selected_file);
	}
}

void PageOutput::Continue() {
	QString file = GetFile();
	if(file.isEmpty()) {
		QMessageBox::critical(this, MainWindow::WINDOW_CAPTION, "You did not select an output file!", QMessageBox::Ok);
		return;
	}
	if(QFileInfo(file).exists()) {
		if(QMessageBox::warning(this, MainWindow::WINDOW_CAPTION, "The file '" + QFileInfo(file).fileName() + "' already exists. Are you sure you want to overwrite it?",
								QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
			return;
		}
	}
	m_main_window->GoPageRecord();
}
