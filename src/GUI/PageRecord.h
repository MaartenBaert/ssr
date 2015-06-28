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

#include "Logger.h"
#include "PageInput.h"
#include "OutputSettings.h"
#include "OutputManager.h"
#include "ElidedLabel.h"
#include "HotkeyListener.h"

class MainWindow;

class Muxer;
class VideoEncoder;
class AudioEncoder;
class Synchronizer;
class X11Input;
class GLInjectLauncher;
class GLInjectInput;
class ALSAInput;
#if SSR_USE_PULSEAUDIO
class PulseAudioInput;
#endif
#if SSR_USE_JACK
class JACKInput;
#endif
class SimpleSynth;
class VideoPreviewer;
class AudioPreviewer;

class PageRecord : public QWidget {
	Q_OBJECT

private:
	static const int PRIORITY_RECORD, PRIORITY_PREVIEW;

private:
	MainWindow *m_main_window;

	bool m_page_started, m_input_started, m_output_started, m_previewing;
	bool m_recorded_something, m_wait_saving;

	PageInput::enum_video_area m_video_area;
	unsigned int m_video_x, m_video_y, m_video_in_width, m_video_in_height;
	unsigned int m_video_frame_rate;
	bool m_video_scaling;
	unsigned int m_video_scaled_width, m_video_scaled_height;
	bool m_video_record_cursor;
	bool m_audio_enabled;
	unsigned int m_audio_channels, m_audio_sample_rate;
	PageInput::enum_audio_backend m_audio_backend;
	QString m_alsa_source;
#if SSR_USE_PULSEAUDIO
	QString m_pulseaudio_source;
#endif

	OutputSettings m_output_settings;
	std::unique_ptr<OutputManager> m_output_manager;

	QString m_file_base;
	QString m_file_protocol;
	bool m_separate_files;

	std::unique_ptr<X11Input> m_x11_input;
	std::unique_ptr<GLInjectInput> m_gl_inject_input;
	std::unique_ptr<ALSAInput> m_alsa_input;
#if SSR_USE_PULSEAUDIO
	std::unique_ptr<PulseAudioInput> m_pulseaudio_input;
#endif
#if SSR_USE_JACK
	std::unique_ptr<JACKInput> m_jack_input;
#endif

	std::unique_ptr<SimpleSynth> m_simple_synth;
	int64_t m_last_error_sound;

	HotkeyCallback m_hotkey_start_pause;

	QPushButton *m_pushbutton_start_pause;

	QCheckBox *m_checkbox_hotkey_enable, *m_checkbox_sound_notifications_enable;
	QCheckBox *m_checkbox_hotkey_ctrl, *m_checkbox_hotkey_shift, *m_checkbox_hotkey_alt, *m_checkbox_hotkey_super;
	QComboBox *m_combobox_hotkey_key;

	QLabel *m_label_info_total_time, *m_label_info_frame_rate_in, *m_label_info_frame_rate_out, *m_label_info_size_in, *m_label_info_size_out;
	ElidedLabel *m_label_info_file_name;
	QLabel *m_label_info_file_size, *m_label_info_bit_rate;

	QStackedLayout *m_stacked_layout_preview;
	QWidget *m_preview_page1, *m_preview_page2;
	QSpinBox *m_spinbox_preview_frame_rate;
	VideoPreviewer *m_video_previewer;
	QLabel *m_label_mic_icon;
	AudioPreviewer *m_audio_previewer;
	QPushButton *m_pushbutton_preview_start_stop;

	QTextEdit *m_textedit_log;

	QSystemTrayIcon *m_systray_icon;
	QAction *m_systray_action_start_pause, *m_systray_action_cancel, *m_systray_action_save;
	QAction *m_systray_action_show_hide, *m_systray_action_quit;

	QTimer *m_timer_update_info;

public:
	PageRecord(MainWindow* main_window);
	~PageRecord();

	// Called when the user tries to close the program. If this function returns true, the command will be blocked.
	// This is used to display a warning if the user is about to close the program during a recording.
	bool ShouldBlockClose();

	// Called when the main window is shown/hidden (to update the system tray).
	void UpdateShowHide();

	void LoadSettings(QSettings* settings);
	void SaveSettings(QSettings* settings);

	bool TryStartPage();
	void StartPage();
	void StopPage(bool save);
	void StartOutput();
	void StopOutput(bool final);
	void StartInput();
	void StopInput();

private:
	void FinishOutput();
	void UpdateInput();
	void UpdateSysTray();
	void UpdateRecordPauseButton();
	void UpdatePreview();

public:
	inline bool IsHotkeyEnabled() { return m_checkbox_hotkey_enable->isChecked(); }
	inline bool IsHotkeyCtrlEnabled() { return m_checkbox_hotkey_ctrl->isChecked(); }
	inline bool IsHotkeyShiftEnabled() { return m_checkbox_hotkey_shift->isChecked(); }
	inline bool IsHotkeyAltEnabled() { return m_checkbox_hotkey_alt->isChecked(); }
	inline bool IsHotkeySuperEnabled() { return m_checkbox_hotkey_super->isChecked(); }
	inline unsigned int GetHotkeyKey() { return m_combobox_hotkey_key->currentIndex(); }
	inline bool AreSoundNotificationsEnabled() { return m_checkbox_sound_notifications_enable->isChecked(); }
	inline unsigned int GetPreviewFrameRate() { return m_spinbox_preview_frame_rate->value(); }

	inline void SetHotkeyEnabled(bool enable) { m_checkbox_hotkey_enable->setChecked(enable); }
	inline void SetHotkeyCtrlEnabled(bool enable) { m_checkbox_hotkey_ctrl->setChecked(enable); }
	inline void SetHotkeyShiftEnabled(bool enable) { m_checkbox_hotkey_shift->setChecked(enable); }
	inline void SetHotkeyAltEnabled(bool enable) { m_checkbox_hotkey_alt->setChecked(enable); }
	inline void SetHotkeySuperEnabled(bool enable) { m_checkbox_hotkey_super->setChecked(enable); }
	inline void SetHotkeyKey(unsigned int key) { m_combobox_hotkey_key->setCurrentIndex(clamp(key, 0u, 25u)); }
	inline void SetSoundNotificationsEnabled(bool enable) { m_checkbox_sound_notifications_enable->setChecked(enable); }
	inline void SetPreviewFrameRate(unsigned int frame_rate) { m_spinbox_preview_frame_rate->setValue(frame_rate); }

public slots:
	void OnUpdateHotkeyFields();
	void OnUpdateHotkey();
	void OnUpdateSoundNotifications();

private slots:
	void OnRecordStartPause();
	void OnPreviewStartStop();
	void OnCancel();
	void OnSave();

	void OnUpdateInformation();
	void OnNewLogLine(Logger::enum_type type, QString string);

};
