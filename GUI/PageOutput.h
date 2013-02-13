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

#pragma once
#include "StdAfx.h"

class MainWindow;

class PageOutput : public QWidget {
	Q_OBJECT

public:
	enum enum_container {
		CONTAINER_MKV,
		CONTAINER_MP4,
		CONTAINER_WEBM,
		CONTAINER_OGG,
		CONTAINER_COUNT // must be last
	};
	enum enum_video_codec {
		VIDEO_CODEC_H264,
		VIDEO_CODEC_VP8,
		VIDEO_CODEC_THEORA,
		VIDEO_CODEC_COUNT // must be last
	};
	enum enum_audio_codec {
		AUDIO_CODEC_VORBIS,
		AUDIO_CODEC_MP3,
		AUDIO_CODEC_AAC,
		AUDIO_CODEC_UNCOMPRESSED,
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
		const char *name, *suffix, *filter, *avname;
		bool installed;
		unsigned char video_codec[PageOutput::VIDEO_CODEC_COUNT], audio_codec[PageOutput::AUDIO_CODEC_COUNT];
	};
	struct VideoCodecData {
		const char *name, *avname;
		bool installed;
	};
	struct AudioCodecData {
		const char *name, *avname;
		bool installed;
	};

private:
	static ContainerData s_container_data[PageOutput::CONTAINER_COUNT];
	static VideoCodecData s_video_codec_data[PageOutput::VIDEO_CODEC_COUNT];
	static AudioCodecData s_audio_codec_data[PageOutput::AUDIO_CODEC_COUNT];
	static const char* s_h264_preset_strings[PageOutput::H264_PRESET_COUNT];

private:
	MainWindow *m_main_window;

	QGroupBox *m_group_audio;
	enum_container m_old_container;
	QComboBox *m_combobox_container;
	QLineEdit *m_lineedit_file;
	QComboBox *m_combobox_video_codec;
	QLabel *m_label_video_bitrate, *m_label_h264_crf, *m_label_h264_preset, *m_label_vp8_cpu_used;
	QLineEdit *m_lineedit_video_kbit_rate;
	QLineEdit *m_lineedit_h264_crf;
	QComboBox *m_combobox_h264_preset;
	QComboBox *m_combobox_vp8_cpu_used;
	QComboBox *m_combobox_audio_codec;
    QLabel *m_label_audio_kbit_rate;
	QLineEdit *m_lineedit_audio_kbit_rate;

public:
	PageOutput(MainWindow* main_window);

	void UpdateStreams();

	void LoadSettings(QSettings* settings);
	void SaveSettings(QSettings* settings);

public:
	inline enum_container GetContainer() { return (enum_container) clamp(0, CONTAINER_COUNT - 1, m_combobox_container->currentIndex()); }
	inline QString GetFile() { return m_lineedit_file->text(); }
	inline enum_video_codec GetVideoCodec() { return (enum_video_codec) clamp(0, VIDEO_CODEC_COUNT - 1, m_combobox_video_codec->currentIndex()); }
	inline unsigned int GetVideoKBitRate() { return m_lineedit_video_kbit_rate->text().toUInt(); }
	inline unsigned int GetH264CRF() { return m_lineedit_h264_crf->text().toUInt(); }
	inline enum_h264_preset GetH264Preset() { return (enum_h264_preset) clamp(0, H264_PRESET_COUNT - 1, m_combobox_h264_preset->currentIndex()); }
	inline unsigned int GetVP8CPUUsed() { return 5 - m_combobox_vp8_cpu_used->currentIndex(); }
	inline enum_audio_codec GetAudioCodec() { return (enum_audio_codec) clamp(0, AUDIO_CODEC_COUNT - 1, m_combobox_audio_codec->currentIndex()); }
	inline unsigned int GetAudioKBitRate() { return m_lineedit_audio_kbit_rate->text().toUInt(); }

	inline void SetContainer(enum_container container) { m_combobox_container->setCurrentIndex(clamp<unsigned int>(0, CONTAINER_COUNT - 1, container)); }
	inline void SetFile(const QString& file) { m_lineedit_file->setText(file); }
	inline void SetVideoCodec(enum_video_codec video_codec) { m_combobox_video_codec->setCurrentIndex(clamp<unsigned int>(0, VIDEO_CODEC_COUNT - 1, video_codec)); }
	inline void SetVideoKBitRate(unsigned int kbit_rate) { m_lineedit_video_kbit_rate->setText(QString::number(kbit_rate)); }
	inline void SetH264CRF(unsigned int crf) { m_lineedit_h264_crf->setText(QString::number(crf)); }
	inline void SetH264Preset(enum_h264_preset preset) { m_combobox_h264_preset->setCurrentIndex(clamp<unsigned int>(0, H264_PRESET_COUNT - 1, preset)); }
	inline void SetVP8CPUUsed(unsigned int cpu_used) { m_combobox_vp8_cpu_used->setCurrentIndex(clamp<unsigned int>(0, 4, 5 - cpu_used)); }
	inline void SetAudioCodec(enum_audio_codec audio_codec) { m_combobox_audio_codec->setCurrentIndex(clamp<unsigned int>(0, AUDIO_CODEC_COUNT - 1, audio_codec)); }
	inline void SetAudioKBitRate(unsigned int kbit_rate) { m_lineedit_audio_kbit_rate->setText(QString::number(kbit_rate)); }

public:
	inline static const char* GetContainerAVName(enum_container container) { return s_container_data[container].avname; }
	inline static const char* GetVideoCodecAVName(enum_video_codec codec) { return s_video_codec_data[codec].avname; }
	inline static const char* GetAudioCodecAVName(enum_audio_codec codec) { return s_audio_codec_data[codec].avname; }
	inline static const char* GetH264PresetName(enum_h264_preset preset) { return s_h264_preset_strings[preset]; }

public slots:
	void UpdateContainerSupport();
	void UpdateVideoCodecFields();
	void UpdateAudioCodecFields();

private slots:
	void Browse();
	void Continue();

};
