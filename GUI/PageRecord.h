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

#include "PageOutput.h"
#include "Logger.h"

class MainWindow;

class Muxer;
class VideoEncoder;
class AudioEncoder;
class Synchronizer;
class X11Input;
class GLInjectLauncher;
class GLInjectInput;
class AudioInput;

class PageRecord : public QWidget {
	Q_OBJECT

private:
	MainWindow *m_main_window;

	Logger m_logger;

	bool m_started, m_encoders_started, m_recording;
	bool m_video_show_cursor, m_video_follow_cursor, m_video_glinject;
	unsigned int m_video_x, m_video_y, m_video_width, m_video_height;
	bool m_video_scaling;
	unsigned int m_video_out_width, m_video_out_height;
	unsigned int m_video_frame_rate, m_audio_sample_rate;
	bool m_audio_enabled;
	QString m_audio_source;

	QString m_file;
	PageOutput::enum_container m_container;
	PageOutput::enum_video_codec m_video_codec;
	PageOutput::enum_audio_codec m_audio_codec;
	const char *m_container_avname, *m_video_avname, *m_audio_avname;
	unsigned int m_video_kbit_rate, m_audio_kbit_rate;
	std::vector<std::pair<QString, QString> > m_video_options, m_audio_options;

	QTimer *m_info_timer, *m_log_timer;
	bool m_info_first_time;
	int64_t m_info_last_time;
	unsigned int m_info_last_frames;
	uint64_t m_info_last_bytes;

	std::unique_ptr<Muxer> m_muxer;
	std::unique_ptr<VideoEncoder> m_video_encoder;
	std::unique_ptr<AudioEncoder> m_audio_encoder;
	std::unique_ptr<Synchronizer> m_synchronizer;
	std::unique_ptr<X11Input> m_x11_input;
	std::unique_ptr<GLInjectLauncher> m_gl_inject_launcher;
	std::unique_ptr<GLInjectInput> m_gl_inject_input;
	std::unique_ptr<AudioInput> m_audio_input;

	QPushButton *m_pushbutton_start_pause;

	QCheckBox *m_checkbox_hotkey_enable;
	QCheckBox *m_checkbox_hotkey_ctrl, *m_checkbox_hotkey_shift, *m_checkbox_hotkey_alt, *m_checkbox_hotkey_super;
	QComboBox *m_combobox_hotkey_key;

	QLabel *m_label_total_time, *m_label_video_frame_rate, *m_label_video_size;
	QLabel *m_label_file_name, *m_label_file_size, *m_label_file_bit_rate;
	QTextEdit *m_textedit_log;

public:
	PageRecord(MainWindow* main_window);
	~PageRecord();

	// Called when the user tries to close the program. If this function returns true, the command will be blocked.
	// This is used to
	bool ShouldBlockClose();

	void LoadSettings(QSettings* settings);
	void SaveSettings(QSettings* settings);

	void Start();
	void Stop(bool save);
	void RecordStart();
	void RecordPause();

public:
	inline bool IsHotkeyEnabled() { return m_checkbox_hotkey_enable->isChecked(); }
	inline bool IsHotkeyCtrlEnabled() { return m_checkbox_hotkey_ctrl->isChecked(); }
	inline bool IsHotkeyShiftEnabled() { return m_checkbox_hotkey_shift->isChecked(); }
	inline bool IsHotkeyAltEnabled() { return m_checkbox_hotkey_alt->isChecked(); }
	inline bool IsHotkeySuperEnabled() { return m_checkbox_hotkey_super->isChecked(); }
	inline unsigned int GetHotkeyKey() { return m_combobox_hotkey_key->currentIndex(); }

	inline void SetHotkeyEnabled(bool enable) { m_checkbox_hotkey_enable->setChecked(enable); }
	inline void SetHotkeyCtrlEnabled(bool enable) { m_checkbox_hotkey_ctrl->setChecked(enable); }
	inline void SetHotkeyShiftEnabled(bool enable) { m_checkbox_hotkey_shift->setChecked(enable); }
	inline void SetHotkeyAltEnabled(bool enable) { m_checkbox_hotkey_alt->setChecked(enable); }
	inline void SetHotkeySuperEnabled(bool enable) { m_checkbox_hotkey_super->setChecked(enable); }
	inline void SetHotkeyKey(unsigned int key) { m_combobox_hotkey_key->setCurrentIndex(clamp<unsigned int>(0, 25, key)); }

public slots:
	void UpdateHotkeyFields();
	void UpdateHotkey();

private slots:
	void RecordStartPause();
	void Cancel();
	void Save();
	void UpdateInformation();
	void UpdateLog();

};
