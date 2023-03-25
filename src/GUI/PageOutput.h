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

#pragma once
#include "Global.h"

#include "ProfileBox.h"

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

private:
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
	MainWindow *m_main_window;

	enum_container m_old_container;
	unsigned int m_old_container_av;

	std::vector<ContainerData> m_containers, m_containers_av;
	std::vector<VideoCodecData> m_video_codecs, m_video_codecs_av;
	std::vector<AudioCodecData> m_audio_codecs, m_audio_codecs_av;

	ProfileBox *m_profile_box;

	QComboBox *m_combobox_profiles;
	QPushButton *m_pushbutton_profile_save, *m_pushbutton_profile_new, *m_pushbutton_profile_delete;

	QLineEdit *m_lineedit_file;
	QCheckBox *m_checkbox_separate_files, *m_checkbox_add_timestamp;
	QComboBox *m_combobox_container;
	QLabel *m_label_container_av;
	QComboBox *m_combobox_container_av;
	QLabel *m_label_container_warning;

	QComboBox *m_combobox_video_codec;
	QLabel *m_label_video_codec_av;
	QComboBox *m_combobox_video_codec_av;
	QLabel *m_label_video_kbit_rate;
	QLineEdit *m_lineedit_video_kbit_rate;
	QLabel *m_label_h264_crf;
	QSlider *m_slider_h264_crf;
	QLabel *m_label_h264_crf_value;
	QLabel *m_label_h264_preset;
	QComboBox *m_combobox_h264_preset;
	QLabel *m_label_vp8_cpu_used;
	QComboBox *m_combobox_vp8_cpu_used;
	QLabel *m_label_video_options;
	QLineEdit *m_lineedit_video_options;
	QCheckBox *m_checkbox_video_allow_frame_skipping;

	QGroupBox *m_groupbox_audio;
	QComboBox *m_combobox_audio_codec;
	QLabel *m_label_audio_codec_av;
	QComboBox *m_combobox_audio_codec_av;
	QLabel *m_label_audio_kbit_rate;
	QLineEdit *m_lineedit_audio_kbit_rate;
	QLabel *m_label_audio_options;
	QLineEdit *m_lineedit_audio_options;

public:
	PageOutput(MainWindow* main_window);

	void LoadSettings(QSettings* settings);
	void SaveSettings(QSettings* settings);

private:
	static void LoadProfileSettingsCallback(QSettings* settings, void* userdata);
	static void SaveProfileSettingsCallback(QSettings* settings, void* userdata);
	void LoadProfileSettings(QSettings* settings);
	void SaveProfileSettings(QSettings* settings);

public:
	void StartPage();
	bool Validate();

	QString GetFileProtocol();
	QString GetContainerAVName();
	QString GetVideoCodecAVName();
	QString GetAudioCodecAVName();

private:
	unsigned int FindContainerAV(const QString& name);
	unsigned int FindVideoCodecAV(const QString& name);
	unsigned int FindAudioCodecAV(const QString& name);

private:
	void LoadProfiles();
	void LoadProfilesFromDir(const QString& path, bool can_delete);
	void UpdateProfileFields();

public slots:
	void OnUpdateSuffixAndContainerFields();
	void OnUpdateContainerFields();
	void OnUpdateVideoCodecFields();
	void OnUpdateAudioCodecFields();

private slots:
	void OnBrowse();
	void OnContinue();

public:
	inline unsigned int GetProfile() { return m_profile_box->GetProfile(); }
	inline QString GetFile() { return m_lineedit_file->text(); }
	inline bool GetSeparateFiles() { return m_checkbox_separate_files->isChecked(); }
	inline bool GetAddTimestamp() { return m_checkbox_add_timestamp->isChecked(); }
	inline enum_container GetContainer() { return (enum_container) clamp(m_combobox_container->currentIndex(), 0, CONTAINER_COUNT - 1); }
	inline unsigned int GetContainerAV() { return clamp(m_combobox_container_av->currentIndex(), 0, (int) m_containers_av.size() - 1); }
	inline enum_video_codec GetVideoCodec() { return (enum_video_codec) clamp(m_combobox_video_codec->currentIndex(), 0, VIDEO_CODEC_COUNT - 1); }
	inline unsigned int GetVideoCodecAV() { return clamp(m_combobox_video_codec_av->currentIndex(), 0, (int) m_video_codecs_av.size() - 1); }
	inline unsigned int GetVideoKBitRate() { return m_lineedit_video_kbit_rate->text().toUInt(); }
	inline unsigned int GetH264CRF() { return m_slider_h264_crf->value(); }
	inline enum_h264_preset GetH264Preset() { return (enum_h264_preset) clamp(m_combobox_h264_preset->currentIndex(), 0, H264_PRESET_COUNT - 1); }
	inline unsigned int GetVP8CPUUsed() { return clamp(5 - m_combobox_vp8_cpu_used->currentIndex(), 0, 5); }
	inline QString GetVideoOptions() { return m_lineedit_video_options->text(); }
	inline bool GetVideoAllowFrameSkipping() { return m_checkbox_video_allow_frame_skipping->isChecked(); }
	inline enum_audio_codec GetAudioCodec() { return (enum_audio_codec) clamp(m_combobox_audio_codec->currentIndex(), 0, AUDIO_CODEC_COUNT - 1); }
	inline unsigned int GetAudioCodecAV() { return clamp(m_combobox_audio_codec_av->currentIndex(), 0, (int) m_audio_codecs_av.size() - 1); }
	inline unsigned int GetAudioKBitRate() { return m_lineedit_audio_kbit_rate->text().toUInt(); }
	inline QString GetAudioOptions() { return m_lineedit_audio_options->text(); }

	inline void SetProfile(unsigned int profile) { m_profile_box->SetProfile(profile); }
	inline void SetContainer(enum_container container) { m_combobox_container->setCurrentIndex(clamp((unsigned int) container, 0u, (unsigned int) CONTAINER_COUNT - 1)); }
	inline void SetContainerAV(unsigned int container) { m_combobox_container_av->setCurrentIndex(clamp(container, 0u, (unsigned int) m_containers_av.size() - 1)); }
	inline void SetFile(const QString& file) { m_lineedit_file->setText(file); }
	inline void SetSeparateFiles(bool separate_files) { m_checkbox_separate_files->setChecked(separate_files); }
	inline void SetAddTimestamp(bool add_timestamp) { m_checkbox_add_timestamp->setChecked(add_timestamp); }
	inline void SetVideoCodec(enum_video_codec video_codec) { m_combobox_video_codec->setCurrentIndex(clamp((unsigned int) video_codec, 0u, (unsigned int) VIDEO_CODEC_COUNT - 1)); }
	inline void SetVideoCodecAV(unsigned int video_codec_av) { m_combobox_video_codec_av->setCurrentIndex(clamp(video_codec_av, 0u, (unsigned int) m_video_codecs_av.size() - 1)); }
	inline void SetVideoKBitRate(unsigned int kbit_rate) { m_lineedit_video_kbit_rate->setText(QString::number(kbit_rate)); }
	inline void SetH264CRF(unsigned int crf) { m_slider_h264_crf->setValue(crf); }
	inline void SetH264Preset(enum_h264_preset preset) { m_combobox_h264_preset->setCurrentIndex(clamp((unsigned int) preset, 0u, (unsigned int) H264_PRESET_COUNT - 1)); }
	inline void SetVP8CPUUsed(unsigned int cpu_used) { m_combobox_vp8_cpu_used->setCurrentIndex(clamp(5 - (int) cpu_used, 0, 5)); }
	inline void SetVideoOptions(const QString& options) { m_lineedit_video_options->setText(options); }
	inline void SetVideoAllowFrameSkipping(bool allow_frame_skipping) { return m_checkbox_video_allow_frame_skipping->setChecked(allow_frame_skipping); }
	inline void SetAudioCodec(enum_audio_codec audio_codec) { m_combobox_audio_codec->setCurrentIndex(clamp((unsigned int) audio_codec, 0u, (unsigned int) AUDIO_CODEC_COUNT - 1)); }
	inline void SetAudioCodecAV(unsigned int audio_codec_av) { m_combobox_audio_codec_av->setCurrentIndex(clamp(audio_codec_av, 0u, (unsigned int) m_audio_codecs_av.size() - 1)); }
	inline void SetAudioKBitRate(unsigned int kbit_rate) { m_lineedit_audio_kbit_rate->setText(QString::number(kbit_rate)); }
	inline void SetAudioOptions(const QString& options) { m_lineedit_audio_options->setText(options); }

};
