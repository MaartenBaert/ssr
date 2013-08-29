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

#pragma once
#include "Global.h"

class MainWindow;

class PageOutput : public QWidget {
	Q_OBJECT

public:
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
	enum enum_h264_preset {
		H264_PRESET_ULTRAFAST,
		H264_PRESET_SUPERFAST,
		H264_PRESET_VERYFAST,
		H264_PRESET_FASTER,
		H264_PRESET_FAST,
		H264_PRESET_MEDIUM,
		H264_PRESET_SLOW,
		H264_PRESET_SLOWER,
		H264_PRESET_VERYSLOW,
		H264_PRESET_PLACEBO,
		H264_PRESET_COUNT // must be last
	};

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
	static QString H264_PRESET_STRINGS[PageOutput::H264_PRESET_COUNT];

private:
	MainWindow *m_main_window;

	QGroupBox *m_groupbox_audio;
	QComboBox *m_combobox_container;
	QLabel *m_label_container_av;
	QComboBox *m_combobox_container_av;
	QLineEdit *m_lineedit_file;
	QCheckBox *m_checkbox_hide;
	QComboBox *m_combobox_video_codec;
	QLabel *m_label_video_codec_av;
	QComboBox *m_combobox_video_codec_av;
	QLabel *m_label_video_bitrate, *m_label_h264_crf, *m_label_h264_preset, *m_label_vp8_cpu_used;
	QLineEdit *m_lineedit_video_kbit_rate;
	QLineEdit *m_lineedit_h264_crf;
	QComboBox *m_combobox_h264_preset;
	QComboBox *m_combobox_vp8_cpu_used;
	QLabel *m_label_video_options;
	QLineEdit *m_lineedit_video_options;
	QComboBox *m_combobox_audio_codec;
	QLabel *m_label_audio_codec_av;
	QComboBox *m_combobox_audio_codec_av;
	QLabel *m_label_audio_kbit_rate;
	QLineEdit *m_lineedit_audio_kbit_rate;
	QLabel *m_label_audio_options;
	QLineEdit *m_lineedit_audio_options;

	std::vector<ContainerData> m_containers, m_containers_av;
	std::vector<VideoCodecData> m_video_codecs, m_video_codecs_av;
	std::vector<AudioCodecData> m_audio_codecs, m_audio_codecs_av;

	enum_container m_old_container;
	unsigned int m_old_container_av;

public:
	PageOutput(MainWindow* main_window);

	void LoadSettings(QSettings* settings);
	void SaveSettings(QSettings* settings);

	void PageStart();

public:
	inline enum_container GetContainer() { return (enum_container) clamp(0, CONTAINER_COUNT - 1, m_combobox_container->currentIndex()); }
	inline unsigned int GetContainerAV() { return clamp<unsigned int>(0, m_containers_av.size() - 1, m_combobox_container_av->currentIndex()); }
	inline QString GetFile() { return m_lineedit_file->text(); }
	inline bool GetHideFilename() { return m_checkbox_hide->isChecked(); }
	inline enum_video_codec GetVideoCodec() { return (enum_video_codec) clamp(0, VIDEO_CODEC_COUNT - 1, m_combobox_video_codec->currentIndex()); }
	inline unsigned int GetVideoCodecAV() { return clamp<unsigned int>(0, m_video_codecs_av.size() - 1, m_combobox_video_codec_av->currentIndex()); }
	inline unsigned int GetVideoKBitRate() { return m_lineedit_video_kbit_rate->text().toUInt(); }
	inline unsigned int GetH264CRF() { return m_lineedit_h264_crf->text().toUInt(); }
	inline enum_h264_preset GetH264Preset() { return (enum_h264_preset) clamp(0, H264_PRESET_COUNT - 1, m_combobox_h264_preset->currentIndex()); }
	inline unsigned int GetVP8CPUUsed() { return 5 - m_combobox_vp8_cpu_used->currentIndex(); }
	inline QString GetVideoOptions() { return m_lineedit_video_options->text(); }
	inline enum_audio_codec GetAudioCodec() { return (enum_audio_codec) clamp(0, AUDIO_CODEC_COUNT - 1, m_combobox_audio_codec->currentIndex()); }
	inline unsigned int GetAudioCodecAV() { return clamp<unsigned int>(0, m_audio_codecs_av.size() - 1, m_combobox_audio_codec_av->currentIndex()); }
	inline unsigned int GetAudioKBitRate() { return m_lineedit_audio_kbit_rate->text().toUInt(); }
	inline QString GetAudioOptions() { return m_lineedit_audio_options->text(); }

	inline void SetContainer(enum_container container) { m_combobox_container->setCurrentIndex(clamp<unsigned int>(0, CONTAINER_COUNT - 1, container)); }
	inline void SetContainerAV(unsigned int container) { m_combobox_container_av->setCurrentIndex(clamp<unsigned int>(0, m_containers_av.size() - 1, container)); }
	inline void SetFile(const QString& file) { m_lineedit_file->setText(file); }
	inline void SetHideFilename(bool show) { m_checkbox_hide->setChecked(show); }
	inline void SetVideoCodec(enum_video_codec video_codec) { m_combobox_video_codec->setCurrentIndex(clamp<unsigned int>(0, VIDEO_CODEC_COUNT - 1, video_codec)); }
	inline void SetVideoCodecAV(unsigned int video_codec) { m_combobox_video_codec_av->setCurrentIndex(clamp<unsigned int>(0, m_video_codecs_av.size() - 1, video_codec)); }
	inline void SetVideoKBitRate(unsigned int kbit_rate) { m_lineedit_video_kbit_rate->setText(QString::number(kbit_rate)); }
	inline void SetH264CRF(unsigned int crf) { m_lineedit_h264_crf->setText(QString::number(crf)); }
	inline void SetH264Preset(enum_h264_preset preset) { m_combobox_h264_preset->setCurrentIndex(clamp<unsigned int>(0, H264_PRESET_COUNT - 1, preset)); }
	inline void SetVP8CPUUsed(unsigned int cpu_used) { m_combobox_vp8_cpu_used->setCurrentIndex(clamp<unsigned int>(0, 4, 5 - cpu_used)); }
	inline void SetVideoOptions(const QString& options) { m_lineedit_video_options->setText(options); }
	inline void SetAudioCodec(enum_audio_codec audio_codec) { m_combobox_audio_codec->setCurrentIndex(clamp<unsigned int>(0, AUDIO_CODEC_COUNT - 1, audio_codec)); }
	inline void SetAudioCodecAV(unsigned int audio_codec) { m_combobox_audio_codec_av->setCurrentIndex(clamp<unsigned int>(0, m_audio_codecs_av.size() - 1, audio_codec)); }
	inline void SetAudioKBitRate(unsigned int kbit_rate) { m_lineedit_audio_kbit_rate->setText(QString::number(kbit_rate)); }
	inline void SetAudioOptions(const QString& options) { m_lineedit_audio_options->setText(options); }

public:
	inline QString GetContainerAVName() {
		enum_container container = GetContainer();
		if(container != CONTAINER_OTHER)
			return m_containers[container].avname;
		else
			return m_containers_av[GetContainerAV()].avname;
	}
	inline QString GetVideoCodecAVName() {
		enum_video_codec video_codec = GetVideoCodec();
		if(video_codec != VIDEO_CODEC_OTHER)
			return m_video_codecs[video_codec].avname;
		else
			return m_video_codecs_av[GetVideoCodecAV()].avname;
	}
	inline QString GetAudioCodecAVName() {
		enum_audio_codec audio_codec = GetAudioCodec();
		if(audio_codec != AUDIO_CODEC_OTHER)
			return m_audio_codecs[audio_codec].avname;
		else
			return m_audio_codecs_av[GetAudioCodecAV()].avname;
	}
	inline QString GetH264PresetName() {
		return H264_PRESET_STRINGS[GetH264Preset()];
	}

public slots:
	void UpdateContainerFields();
	void UpdateVideoCodecFields();
	void UpdateAudioCodecFields();

private slots:
	void Browse();
	void Continue();

};
