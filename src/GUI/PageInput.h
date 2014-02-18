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

#if SSR_USE_PULSEAUDIO
#include "PulseAudioInput.h"
#endif

class QComboBoxWithSignal : public QComboBox {
	Q_OBJECT

public:
	QComboBoxWithSignal(QWidget* parent);

	virtual void showPopup() override;
	virtual void hidePopup() override;

signals:
	void popupShown();
	void popupHidden();

};

class QSpinBoxWithSignal : public QSpinBox {
	Q_OBJECT

public:
	QSpinBoxWithSignal(QWidget* parent);

	virtual void focusInEvent(QFocusEvent* event) override;
	virtual void focusOutEvent(QFocusEvent* event) override;

signals:
	void focusIn();
	void focusOut();

};

class WidgetScreenLabel : public QWidget {
	Q_OBJECT

private:
	QString m_text;

public:
	WidgetScreenLabel(QWidget* parent, const QString& text);

protected:
	virtual QSize sizeHint() const override;
	virtual void paintEvent(QPaintEvent* event) override;

};

class MainWindow;

class PageInput : public QWidget {
	Q_OBJECT

public:
	enum enum_video_area {
		VIDEO_AREA_SCREEN,
		VIDEO_AREA_FIXED,
		VIDEO_AREA_CURSOR,
		VIDEO_AREA_GLINJECT,
		VIDEO_AREA_COUNT // must be last
	};
	enum enum_audio_backend {
		AUDIO_BACKEND_ALSA,
#if SSR_USE_PULSEAUDIO
		AUDIO_BACKEND_PULSEAUDIO,
#endif
#if SSR_USE_JACK
		AUDIO_BACKEND_JACK,
#endif
		AUDIO_BACKEND_COUNT // must be last
	};

private:
	MainWindow *m_main_window;

	bool m_grabbing, m_selecting_window;
	std::unique_ptr<QRubberBand> m_rubber_band, m_recording_frame;
	QRect m_rubber_band_rect, m_select_window_outer_rect, m_select_window_inner_rect;

#if SSR_USE_PULSEAUDIO
	bool m_pulseaudio_available;
	std::vector<PulseAudioInput::Source> m_pulseaudio_sources;
#endif

	QString m_glinject_command, m_glinject_working_directory;
	bool m_glinject_relax_permissions, m_glinject_auto_launch;
	QString m_glinject_match_user, m_glinject_match_process, m_glinject_match_source, m_glinject_match_program_name;
	bool m_glinject_limit_fps;

	std::vector<WidgetScreenLabel*> m_screen_labels;

	QButtonGroup *m_buttongroup_video_area;
	QComboBoxWithSignal *m_combobox_screens;
	QPushButton *m_pushbutton_video_select_rectangle, *m_pushbutton_video_select_window, *m_pushbutton_video_opengl_settings;
	QLabel *m_label_video_x, *m_label_video_y, *m_label_video_w, *m_label_video_h;
	QSpinBoxWithSignal *m_spinbox_video_x, *m_spinbox_video_y, *m_spinbox_video_w, *m_spinbox_video_h;
	QSpinBox *m_spinbox_video_frame_rate;
	QCheckBox *m_checkbox_scale;
	QLabel *m_label_video_scaled_w, *m_label_video_scaled_h;
	QSpinBox *m_spinbox_video_scaled_w, *m_spinbox_video_scaled_h;
	QCheckBox *m_checkbox_record_cursor;

	QCheckBox *m_checkbox_audio_enable;
	QLabel *m_label_audio_backend;
	QComboBox *m_combobox_audio_backend;
	QLabel *m_label_alsa_device;
	QLineEdit *m_lineedit_alsa_device;
#if SSR_USE_PULSEAUDIO
	QLabel *m_label_pulseaudio_source;
	QComboBox *m_combobox_pulseaudio_source;
	QPushButton *m_pushbutton_pulseaudio_refresh;
#endif
#if SSR_USE_JACK
	QCheckBox *m_checkbox_jack_connect_system_capture, *m_checkbox_jack_connect_system_playback;
#endif

public:
	PageInput(MainWindow* main_window);

	void LoadSettings(QSettings* settings);
	void SaveSettings(QSettings* settings);

#if SSR_USE_PULSEAUDIO
	QString GetPulseAudioSourceName();
#endif

private:
#if SSR_USE_PULSEAUDIO
	unsigned int FindPulseAudioSource(const QString& name);
#endif

public:
	inline enum_video_area GetVideoArea() { return (enum_video_area) clamp(m_buttongroup_video_area->checkedId(), 0, VIDEO_AREA_COUNT - 1); }
	inline unsigned int GetVideoAreaScreen() { return m_combobox_screens->currentIndex(); }
	inline unsigned int GetVideoX() { return m_spinbox_video_x->value(); }
	inline unsigned int GetVideoY() { return m_spinbox_video_y->value(); }
	inline unsigned int GetVideoW() { return m_spinbox_video_w->value(); }
	inline unsigned int GetVideoH() { return m_spinbox_video_h->value(); }
	inline unsigned int GetVideoFrameRate() { return m_spinbox_video_frame_rate->value(); }
	inline bool GetVideoScalingEnabled() { return m_checkbox_scale->isChecked(); }
	inline unsigned int GetVideoScaledW() { return m_spinbox_video_scaled_w->value(); }
	inline unsigned int GetVideoScaledH() { return m_spinbox_video_scaled_h->value(); }
	inline bool GetVideoRecordCursor() { return m_checkbox_record_cursor->isChecked(); }
	inline bool GetAudioEnabled() { return m_checkbox_audio_enable->isChecked(); }
	inline enum_audio_backend GetAudioBackend() { return (enum_audio_backend) clamp(m_combobox_audio_backend->currentIndex(), 0, AUDIO_BACKEND_COUNT - 1); }
	inline QString GetALSADevice() { return m_lineedit_alsa_device->text(); }
#if SSR_USE_PULSEAUDIO
	inline unsigned int GetPulseAudioSource() { return clamp(m_combobox_pulseaudio_source->currentIndex(), 0, (int) m_pulseaudio_sources.size() - 1); }
#endif
#if SSR_USE_JACK
	inline bool GetJackConnectSystemCapture() { return m_checkbox_jack_connect_system_capture->isChecked(); }
	inline bool GetJackConnectSystemPlayback() { return m_checkbox_jack_connect_system_playback->isChecked(); }
#endif
	inline QString GetGLInjectCommand() { return m_glinject_command; }
	inline QString GetGLInjectWorkingDirectory() { return m_glinject_working_directory; }
	inline bool GetGLInjectRelaxPermissions() { return m_glinject_relax_permissions; }
	inline bool GetGLInjectAutoLaunch() { return m_glinject_auto_launch; }
	inline QString GetGLInjectMatchUser() { return m_glinject_match_user; }
	inline QString GetGLInjectMatchProcess() { return m_glinject_match_process; }
	inline QString GetGLInjectMatchSource() { return m_glinject_match_source; }
	inline QString GetGLInjectMatchProgramName() { return m_glinject_match_program_name; }
	inline bool GetGLInjectLimitFPS() { return m_glinject_limit_fps; }

	inline void SetVideoArea(enum_video_area area) { QAbstractButton *b = m_buttongroup_video_area->button(area); if(b != NULL) b->setChecked(true); }
	inline void SetVideoAreaScreen(unsigned int screen) { m_combobox_screens->setCurrentIndex(clamp(screen, 0u, (unsigned int) m_combobox_screens->count() - 1)); }
	inline void SetVideoX(unsigned int x) { m_spinbox_video_x->setValue(x); }
	inline void SetVideoY(unsigned int y) { m_spinbox_video_y->setValue(y); }
	inline void SetVideoW(unsigned int w) { m_spinbox_video_w->setValue(w); }
	inline void SetVideoH(unsigned int h) { m_spinbox_video_h->setValue(h); }
	inline void SetVideoFrameRate(unsigned int frame_rate) { m_spinbox_video_frame_rate->setValue(frame_rate); }
	inline void SetVideoScalingEnabled(bool enable) { m_checkbox_scale->setChecked(enable); }
	inline void SetVideoScaledW(unsigned int scaled_w) { m_spinbox_video_scaled_w->setValue(scaled_w); }
	inline void SetVideoScaledH(unsigned int scaled_h) { m_spinbox_video_scaled_h->setValue(scaled_h); }
	inline void SetVideoRecordCursor(bool show) { m_checkbox_record_cursor->setChecked(show); }
	inline void SetAudioEnabled(bool enable) { m_checkbox_audio_enable->setChecked(enable); }
	inline void SetAudioBackend(enum_audio_backend backend) { m_combobox_audio_backend->setCurrentIndex(clamp((int) backend, 0, AUDIO_BACKEND_COUNT - 1)); }
	inline void SetALSADevice(const QString& device) { m_lineedit_alsa_device->setText(device); }
#if SSR_USE_PULSEAUDIO
	inline void SetPulseAudioSource(unsigned int source) { m_combobox_pulseaudio_source->setCurrentIndex(clamp(source, 0u, (unsigned int) m_pulseaudio_sources.size() - 1)); }
#endif
#if SSR_USE_JACK
	inline void SetJackConnectSystemCapture(bool connect) { m_checkbox_jack_connect_system_capture->setChecked(connect); }
	inline void SetJackConnectSystemPlayback(bool connect) { m_checkbox_jack_connect_system_playback->setChecked(connect); }
#endif
	inline void SetGLInjectCommand(const QString& command) { m_glinject_command = command; }
	inline void SetGLInjectWorkingDirectory(const QString& glinject_working_directory) { m_glinject_working_directory = glinject_working_directory; }
	inline void SetGLInjectRelaxPermissions(bool relax_permissions) { m_glinject_relax_permissions = relax_permissions; }
	inline void SetGLInjectAutoLaunch(bool auto_launch) { m_glinject_auto_launch = auto_launch; }
	inline void SetGLInjectMatchUser(const QString& match_user) { m_glinject_match_user = match_user; }
	inline void SetGLInjectMatchProcess(const QString& match_process) { m_glinject_match_process = match_process; }
	inline void SetGLInjectMatchSource(const QString& match_source) { m_glinject_match_source = match_source; }
	inline void SetGLInjectMatchProgramName(const QString& program_name) { m_glinject_match_program_name = program_name; }
	inline void SetGLInjectLimitFPS(bool limit_fps) { m_glinject_limit_fps = limit_fps; }

protected:
	virtual void mousePressEvent(QMouseEvent* event) override;
	virtual void mouseReleaseEvent(QMouseEvent* event) override;
	virtual void mouseMoveEvent(QMouseEvent* event) override;
	virtual void keyPressEvent(QKeyEvent* event) override;

private:
	void StartGrabbing();
	void StopGrabbing();
	void SetVideoAreaFromRubberBand();

	void LoadScreenConfigurations();
#if SSR_USE_PULSEAUDIO
	void LoadPulseAudioSources();
#endif

public slots:
	void OnUpdateRecordingFrame();
	void OnUpdateVideoAreaFields();
	void OnUpdateVideoScaleFields();
	void OnUpdateAudioFields();

private slots:
	void OnUpdateScreenConfiguration();
	void OnUpdatePulseAudioSources(); // conditional compilation of slots is hard, so we keep the slot
	void OnIdentifyScreens();
	void OnStopIdentifyScreens();
	void OnStartSelectRectangle();
	void OnStartSelectWindow();
	void OnGLInjectDialog();
	void OnContinue();

};
