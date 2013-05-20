/*
Copyright (c) 2012-2013 Maarten Baert <maarten-baert@hotmail.com>

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

#include "AVWrapper.h"
#include "VideoEncoder.h"
#include "AudioEncoder.h"

QString PageOutput::H264_PRESET_STRINGS[PageOutput::H264_PRESET_COUNT] = {
	"ultrafast",
	"superfast",
	"veryfast",
	"faster",
	"fast",
	"medium",
	"slow",
	"slower",
	"veryslow",
	"placebo",
};

PageOutput::PageOutput(MainWindow* main_window)
	: QWidget(main_window->centralWidget()) {

	m_main_window = main_window;

	m_old_container = (enum_container) 0;
	m_old_container_av = 0;

	// main codecs
	m_containers = {
		{"Matroska (MKV)", "matroska", {"mkv"}, "Matroska files (*.mkv)",
			{VIDEO_CODEC_H264, VIDEO_CODEC_VP8, VIDEO_CODEC_THEORA},
			{AUDIO_CODEC_VORBIS, AUDIO_CODEC_MP3, AUDIO_CODEC_AAC, AUDIO_CODEC_UNCOMPRESSED}},
		{"MP4", "mp4", {"mp4"}, "MP4 files (*.mp4)"     ,
			{VIDEO_CODEC_H264},
			{AUDIO_CODEC_VORBIS, AUDIO_CODEC_MP3, AUDIO_CODEC_AAC}},
		{"WebM", "webm", {"webm"}, "WebM files (*.webm)"   ,
			{VIDEO_CODEC_VP8},
			{AUDIO_CODEC_VORBIS,}},
		{"OGG", "ogg", {"ogg"}, "OGG files (*.ogg)"     ,
			{VIDEO_CODEC_THEORA},
			{AUDIO_CODEC_VORBIS}},
		{"Other...", "", {}, "", {}, {}},
	};
	m_video_codecs = {
		{"H.264"   , "libx264"  },
		{"VP8"     , "libvpx"   },
		{"Theora"  , "libtheora"},
		{"Other...", ""         },
	};
	m_audio_codecs = {
		{"Vorbis"      , "libvorbis"   },
		{"MP3"         , "libmp3lame"  },
		{"AAC"         , "libvo_aacenc"},
		{"Uncompressed", "pcm_s16le"   },
		{"Other..."    , ""            },
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
			c.filter = c.avname + " files (*." + c.suffixes[0];
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

	QGroupBox *groupbox_file = new QGroupBox("File", this);
	{
		QLabel *label_container = new QLabel("Container:", groupbox_file);
		m_combobox_container = new QComboBox(groupbox_file);
		for(unsigned int i = 0; i < CONTAINER_COUNT; ++i) {
			QString name = m_containers[i].name;
			if(i != CONTAINER_OTHER && !AVFormatIsInstalled(m_containers[i].avname))
				name += " (not installed)";
			m_combobox_container->addItem(name);
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
		m_label_container_av = new QLabel("Container name:", groupbox_file);
		m_combobox_container_av = new QComboBox(groupbox_file);
		for(unsigned int i = 0; i < m_containers_av.size(); ++i) {
			ContainerData &c = m_containers_av[i];
			//qDebug() << c.avname << c.suffixes << c.filter;
			m_combobox_container_av->addItem(c.avname);
		}
		m_combobox_container_av->setToolTip("For advanced users. You can use any libav/ffmpeg format, but many of them are not useful or may not work.");
		m_combobox_container_av->setVisible(false);
		QLabel *label_file = new QLabel("Save as:", groupbox_file);
		m_lineedit_file = new QLineEdit(groupbox_file);
		m_lineedit_file->setToolTip("The recording will be saved to this location.");
		QPushButton *button_browse = new QPushButton("Browse...", groupbox_file);

		connect(m_combobox_container, SIGNAL(activated(int)), this, SLOT(UpdateContainerFields()));
		connect(m_combobox_container_av, SIGNAL(activated(int)), this, SLOT(UpdateContainerFields()));
		connect(button_browse, SIGNAL(clicked()), this, SLOT(Browse()));

		QGridLayout *layout = new QGridLayout(groupbox_file);
		layout->addWidget(label_container, 0, 0);
		layout->addWidget(m_combobox_container, 0, 1, 1, 2);
		layout->addWidget(m_label_container_av, 1, 0);
		layout->addWidget(m_combobox_container_av, 1, 1, 1, 2);
		layout->addWidget(label_file, 2, 0);
		layout->addWidget(m_lineedit_file, 2, 1);
		layout->addWidget(button_browse, 2, 2);
	}
	QGroupBox *groupbox_video = new QGroupBox("Video", this);
	{
		QLabel *label_video_codec = new QLabel("Codec:", groupbox_video);
		m_combobox_video_codec = new QComboBox(groupbox_video);
		for(unsigned int i = 0; i < VIDEO_CODEC_COUNT; ++i) {
			m_combobox_video_codec->addItem(m_video_codecs[i].name);
		}
		m_combobox_video_codec->setToolTip("The codec that will be used to compress the video stream.\n"
										   "- H.264 (libx264) is by far the best codec - high quality and very fast.\n"
										   "- VP8 (libvpx) is quite good but also quite slow.\n"
										   "- Theora (libtheora) isn't really recommended because the quality isn't very good.");
		m_label_video_codec_av = new QLabel("Codec name:", groupbox_video);
		m_combobox_video_codec_av = new QComboBox(groupbox_video);
		for(unsigned int i = 0; i < m_video_codecs_av.size(); ++i) {
			VideoCodecData &c = m_video_codecs_av[i];
			m_combobox_video_codec_av->addItem(c.avname);
		}
		m_combobox_video_codec_av->setToolTip("For advanced users. You can use any libav/ffmpeg video codec, but many of them are not useful or may not work.");
		m_combobox_video_codec_av->setVisible(false);
		m_label_video_bitrate = new QLabel("Bit rate (in kbps):", groupbox_video);
		m_lineedit_video_kbit_rate = new QLineEdit(groupbox_video);
		m_lineedit_video_kbit_rate->setToolTip("The video bit rate (in kilobit per second). A higher value means a higher quality."
											 "\nIf you have no idea where to start, try 5000 and change it if needed.");
		m_label_h264_crf = new QLabel("Constant rate factor:", groupbox_video);
		m_label_h264_crf->setVisible(false);
		m_lineedit_h264_crf = new QLineEdit(groupbox_video);
		m_lineedit_h264_crf->setToolTip("This setting changes the video quality. A lower value means a higher quality.\n"
										"The allowed range is 0-51 (0 means lossless, the default is 23).");
		m_lineedit_h264_crf->setVisible(false);
		m_label_h264_preset = new QLabel("Preset:", groupbox_video);
		m_label_h264_preset->setVisible(false);
		m_combobox_h264_preset = new QComboBox(groupbox_video);
		for(unsigned int i = 0; i < H264_PRESET_COUNT; ++i) {
			m_combobox_h264_preset->addItem(H264_PRESET_STRINGS[i]);
		}
		m_combobox_h264_preset->setToolTip("The encoding speed. A higher speed uses less CPU (making higher recording frame rates possible),\n"
										   "but results in larger files. The quality shouldn't be affected too much.");
		m_combobox_h264_preset->setVisible(false);
		m_label_vp8_cpu_used = new QLabel("CPU used:", groupbox_video);
		m_label_vp8_cpu_used->setVisible(false);
		m_combobox_vp8_cpu_used = new QComboBox(groupbox_video);
		m_combobox_vp8_cpu_used->addItem("5 (fastest)");
		m_combobox_vp8_cpu_used->addItem("4");
		m_combobox_vp8_cpu_used->addItem("3");
		m_combobox_vp8_cpu_used->addItem("2");
		m_combobox_vp8_cpu_used->addItem("1 (slowest)");
		m_combobox_vp8_cpu_used->setToolTip("The encoding speed. A higher value uses *less* CPU  (I didn't choose the name, this is the name\n"
											"used by the VP8 encoder). Higher values result in lower quality video, unless you increase the bit rate too.");
		m_combobox_vp8_cpu_used->setVisible(false);

		connect(m_combobox_video_codec, SIGNAL(activated(int)), this, SLOT(UpdateVideoCodecFields()));

		QGridLayout *layout = new QGridLayout(groupbox_video);
		layout->addWidget(label_video_codec, 0, 0);
		layout->addWidget(m_combobox_video_codec, 0, 1);
		layout->addWidget(m_label_video_codec_av, 1, 0);
		layout->addWidget(m_combobox_video_codec_av, 1, 1);
		layout->addWidget(m_label_video_bitrate, 2, 0);
		layout->addWidget(m_lineedit_video_kbit_rate, 2, 1);
		layout->addWidget(m_label_h264_crf, 3, 0);
		layout->addWidget(m_lineedit_h264_crf, 3, 1);
		layout->addWidget(m_label_h264_preset, 4, 0);
		layout->addWidget(m_combobox_h264_preset, 4, 1);
		layout->addWidget(m_label_vp8_cpu_used, 5, 0);
		layout->addWidget(m_combobox_vp8_cpu_used, 5, 1);
	}
	m_groupbox_audio = new QGroupBox("Audio");
	{
		QLabel *label_audio_codec = new QLabel("Codec:", m_groupbox_audio);
		m_combobox_audio_codec = new QComboBox(m_groupbox_audio);
		for(unsigned int i = 0; i < AUDIO_CODEC_COUNT; ++i) {
			m_combobox_audio_codec->addItem(m_audio_codecs[i].name);
		}
		m_combobox_audio_codec->setToolTip("The codec that will be used to compress the audio stream. You shouldn't worry too much about\n"
										   "this, because the size of the audio data is usually negligible compared to the size of the video data.\n"
										   "And if you're only recording your own voice (i.e. no music), the quality won't matter that much anyway.\n"
										   "- Vorbis (libvorbis) is great, this is the recommended codec.\n"
										   "- MP3 (libmp3lame) is reasonably good.\n"
										   "- AAC is a good codec, but the implementations used here (libvo_aacenc or the experimental ffmpeg aac encoder)\n"
										   "   are pretty bad. Only use it if you have no other choice.\n"
										   "- Uncompressed will simply store the sound data without compressing it. The file will be quite large, but it's very fast.");
		m_label_audio_codec_av = new QLabel("Codec name:", m_groupbox_audio);
		m_combobox_audio_codec_av = new QComboBox(m_groupbox_audio);
		for(unsigned int i = 0; i < m_audio_codecs_av.size(); ++i) {
			AudioCodecData &c = m_audio_codecs_av[i];
			m_combobox_audio_codec_av->addItem(c.avname);
		}
		m_combobox_audio_codec_av->setToolTip("For advanced users. You can use any libav/ffmpeg audio codec, but many of them are not useful or may not work.");
		m_combobox_audio_codec_av->setVisible(false);
		m_label_audio_kbit_rate = new QLabel("Bit rate (in kbps):", m_groupbox_audio);
		m_lineedit_audio_kbit_rate = new QLineEdit(m_groupbox_audio);
		m_lineedit_audio_kbit_rate->setToolTip("The audio bit rate (in kilobit per second). A higher value means a higher quality. The typical value is 128.");

		connect(m_combobox_audio_codec, SIGNAL(activated(int)), this, SLOT(UpdateAudioCodecFields()));

		QGridLayout *layout = new QGridLayout(m_groupbox_audio);
		layout->addWidget(label_audio_codec, 0, 0);
		layout->addWidget(m_combobox_audio_codec, 0, 1);
		layout->addWidget(m_label_audio_codec_av, 1, 0);
		layout->addWidget(m_combobox_audio_codec_av, 1, 1);
		layout->addWidget(m_label_audio_kbit_rate, 2, 0);
		layout->addWidget(m_lineedit_audio_kbit_rate, 2, 1);
	}
	QPushButton *button_back = new QPushButton(QIcon::fromTheme("go-previous"), "Back", this);
	QPushButton *button_continue = new QPushButton(QIcon::fromTheme("go-next"), "Continue", this);

	connect(button_back, SIGNAL(clicked()), m_main_window, SLOT(GoPageInput()));
	connect(button_continue, SIGNAL(clicked()), this, SLOT(Continue()));

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(groupbox_file);
	layout->addWidget(groupbox_video);
	layout->addWidget(m_groupbox_audio);
	layout->addStretch();
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addWidget(button_back);
		layout2->addWidget(button_continue);
	}

}

void PageOutput::PageStart() {

	// only show audio settings if audio is enabled
	m_groupbox_audio->setVisible(m_main_window->GetPageInput()->GetAudioEnabled());

}

void PageOutput::LoadSettings(QSettings* settings) {

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

	// load settings
	SetContainer((enum_container) settings->value("output/container", default_container).toUInt());
	SetContainerAV(settings->value("output/container_av", default_container).toUInt());
	SetFile(settings->value("output/file", "").toString());
	SetVideoCodec((enum_video_codec) settings->value("output/video/codec", default_video_codec).toUInt());
	SetVideoCodecAV(settings->value("output/video/codec_av", default_video_codec).toUInt());
	SetVideoKBitRate(settings->value("output/video/kbit_rate", 5000).toUInt());
	SetH264CRF(settings->value("output/video/h264/crf", 23).toUInt());
	SetH264Preset((enum_h264_preset) settings->value("output/video/h264/preset", H264_PRESET_SUPERFAST).toUInt());
	SetVP8CPUUsed(settings->value("output/video/vp8/cpu_used", 5).toUInt());
	SetAudioCodec((enum_audio_codec) settings->value("output/audio/codec", default_audio_codec).toUInt());
	SetAudioCodecAV(settings->value("output/audio/codec_av", default_audio_codec).toUInt());
	SetAudioKBitRate(settings->value("output/audio/kbit_rate", 128).toUInt());

	// update things
	UpdateContainerFields();
	UpdateVideoCodecFields();
	UpdateAudioCodecFields();

}

void PageOutput::SaveSettings(QSettings* settings) {
	settings->setValue("output/container", GetContainer());
	settings->setValue("output/container_av", GetContainerAV());
	settings->setValue("output/file", GetFile());
	settings->setValue("output/video/codec", GetVideoCodec());
	settings->setValue("output/video/codec_av", GetVideoCodecAV());
	settings->setValue("output/video/kbit_rate", GetVideoKBitRate());
	settings->setValue("output/video/h264/crf", GetH264CRF());
	settings->setValue("output/video/h264/preset", GetH264Preset());
	settings->setValue("output/video/vp8/cpu_used", GetVP8CPUUsed());
	settings->setValue("output/audio/codec", GetAudioCodec());
	settings->setValue("output/audio/codec_av", GetAudioCodecAV());
	settings->setValue("output/audio/kbit_rate", GetAudioKBitRate());
}

/*static QString FirstStringFromList(const QStringList& list) {
	if(list.isEmpty())
		return "";
	else
		return list[0];
}*/

static bool MatchSuffix(const QString& suffix, const QStringList& suffixes) {
	return ((suffix.isEmpty() && suffixes.isEmpty()) || suffixes.contains(suffix, Qt::CaseInsensitive));
}

void PageOutput::UpdateContainerFields() {

	// change file extension
	enum_container new_container = GetContainer();
	unsigned int new_container_av = GetContainerAV();
	QStringList old_suffixes = (m_old_container == CONTAINER_OTHER)? m_containers_av[m_old_container_av].suffixes : m_containers[m_old_container].suffixes;
	QStringList new_suffixes = (new_container == CONTAINER_OTHER)? m_containers_av[new_container_av].suffixes : m_containers[new_container].suffixes;
	QString file = m_lineedit_file->text();
	if(!file.isEmpty()) {
		QFileInfo fi(file);
		if(MatchSuffix(fi.suffix(), old_suffixes) && !MatchSuffix(fi.suffix(), new_suffixes)) {
			if(new_suffixes.isEmpty())
				m_lineedit_file->setText(fi.path() + "/" + fi.completeBaseName());
			else
				m_lineedit_file->setText(fi.path() + "/" + fi.completeBaseName() + "." + new_suffixes[0]);
		}
	}
	m_old_container = new_container;
	m_old_container_av = new_container_av;

	// show/hide fields
	m_label_container_av->setVisible(new_container == CONTAINER_OTHER);
	m_combobox_container_av->setVisible(new_container == CONTAINER_OTHER);

	// mark uninstalled or unsupported codecs
	for(unsigned int i = 0; i < VIDEO_CODEC_OTHER; ++i) {
		QString name = m_video_codecs[i].name;
		if(!AVCodecIsInstalled(m_video_codecs[i].avname))
			name += " (not installed)";
		else if(!m_containers[new_container].supported_video_codecs.count((enum_video_codec) i))
			name += " (not supported by container)";
		m_combobox_video_codec->setItemText(i, name);
	}
	for(unsigned int i = 0; i < AUDIO_CODEC_OTHER; ++i) {
		QString name = m_audio_codecs[i].name;
		if(!AVCodecIsInstalled(m_audio_codecs[i].avname))
			name += " (not installed)";
		else if(!m_containers[new_container].supported_audio_codecs.count((enum_audio_codec) i))
			name += " (not supported by container)";
		m_combobox_audio_codec->setItemText(i, name);
	}

}

void PageOutput::UpdateVideoCodecFields() {
	enum_video_codec codec = GetVideoCodec();
	m_label_video_codec_av->setVisible(codec == VIDEO_CODEC_OTHER);
	m_combobox_video_codec_av->setVisible(codec == VIDEO_CODEC_OTHER);
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
	m_label_audio_codec_av->setVisible(codec == AUDIO_CODEC_OTHER);
	m_combobox_audio_codec_av->setVisible(codec == AUDIO_CODEC_OTHER);
	m_label_audio_kbit_rate->setVisible(codec != AUDIO_CODEC_UNCOMPRESSED);
	m_lineedit_audio_kbit_rate->setVisible(codec != AUDIO_CODEC_UNCOMPRESSED);
}

void PageOutput::Browse() {

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
	qDebug() << "---- selected filter:" << selected_filter;
	QString selected_file = QFileDialog::getSaveFileName(this, "Save recording as",
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

	UpdateContainerFields();

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
