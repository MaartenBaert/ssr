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

#if SSR_USE_ALSA
#include "ALSAInput.h"
#endif
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

class ScreenLabelWindow : public QWidget {
	Q_OBJECT

private:
	QString m_text;
	QFont m_font;

public:
	ScreenLabelWindow(QWidget* parent, const QString& text);

protected:
	virtual void paintEvent(QPaintEvent* event) override;

};

class RecordingFrameWindow : public QWidget {
	Q_OBJECT

private:
	bool m_outside;
	QPixmap m_texture;

public:
	static constexpr int BORDER_WIDTH = 4;

public:
	RecordingFrameWindow(QWidget* parent, bool outside);

	void SetRectangle(const QRect& r);

private:
	void UpdateMask();

protected:
	virtual void resizeEvent(QResizeEvent* event) override;
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
#if SSR_USE_OPENGL_RECORDING
		VIDEO_AREA_GLINJECT,
#endif
#if SSR_USE_V4L2
		VIDEO_AREA_V4L2,
#endif
		VIDEO_AREA_COUNT // must be last
	};
	enum enum_audio_backend {
#if SSR_USE_ALSA
		AUDIO_BACKEND_ALSA,
#endif
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
	std::unique_ptr<RecordingFrameWindow> m_rubber_band, m_recording_frame;
	QRect m_rubber_band_rect, m_select_window_outer_rect, m_select_window_inner_rect;

#if SSR_USE_ALSA
	std::vector<ALSAInput::Source> m_alsa_sources;
#endif
#if SSR_USE_PULSEAUDIO
	bool m_pulseaudio_available;
	std::vector<PulseAudioInput::Source> m_pulseaudio_sources;
#endif

#if SSR_USE_OPENGL_RECORDING
	QString m_glinject_channel;
	bool m_glinject_relax_permissions;
	QString m_glinject_command, m_glinject_working_directory;
	bool m_glinject_auto_launch;
	bool m_glinject_limit_fps;
#endif

	std::vector<ScreenLabelWindow*> m_screen_labels;

	ProfileBox *m_profile_box;

	QButtonGroup *m_buttongroup_video_area;
	QComboBoxWithSignal *m_combobox_screens;
	QCheckBox *m_checkbox_follow_fullscreen;
	QPushButton *m_pushbutton_video_select_rectangle, *m_pushbutton_video_select_window;
#if SSR_USE_OPENGL_RECORDING
	QPushButton *m_pushbutton_video_opengl_settings;
#endif
#if SSR_USE_V4L2
	QLineEdit *m_lineedit_v4l2_device;
#endif
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
#if SSR_USE_ALSA
	QLabel *m_label_alsa_source;
	QComboBox *m_combobox_alsa_source;
	QPushButton *m_pushbutton_alsa_refresh;
#endif
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

private:
	static void LoadProfileSettingsCallback(QSettings* settings, void* userdata);
	static void SaveProfileSettingsCallback(QSettings* settings, void* userdata);
	void LoadProfileSettings(QSettings* settings);
	void SaveProfileSettings(QSettings* settings);

public:
	bool Validate();

#if SSR_USE_ALSA
	QString GetALSASourceName();
#endif
#if SSR_USE_PULSEAUDIO
	QString GetPulseAudioSourceName();
#endif

private:
#if SSR_USE_ALSA
	unsigned int FindALSASource(const QString& name);
#endif
#if SSR_USE_PULSEAUDIO
	unsigned int FindPulseAudioSource(const QString& name);
#endif

protected:
	virtual void mousePressEvent(QMouseEvent* event) override;
	virtual void mouseReleaseEvent(QMouseEvent* event) override;
	virtual void mouseMoveEvent(QMouseEvent* event) override;
	virtual void keyPressEvent(QKeyEvent* event) override;

private:
	void StartGrabbing();
	void StopGrabbing();
	void UpdateRubberBand();
	void SetVideoAreaFromRubberBand();

	void LoadScreenConfigurations();
#if SSR_USE_ALSA
	void LoadALSASources();
#endif
#if SSR_USE_PULSEAUDIO
	void LoadPulseAudioSources();
#endif

public slots:
	void OnUpdateRecordingFrame();
	void OnUpdateVideoAreaFields();
	void OnUpdateVideoScaleFields();
	void OnUpdateAudioFields();

private slots:
	void OnFocusChange(QWidget* old, QWidget* now);
#if QT_VERSION_MAJOR >= 5
	void OnScreenAdded(QScreen* screen);
#endif
	void OnUpdateScreenConfiguration();
#if SSR_USE_ALSA
	void OnUpdateALSASources();
#endif
#if SSR_USE_PULSEAUDIO
	void OnUpdatePulseAudioSources();
#endif
	void OnIdentifyScreens();
	void OnStopIdentifyScreens();
	void OnStartSelectRectangle();
	void OnStartSelectWindow();
#if SSR_USE_OPENGL_RECORDING
	void OnGLInjectDialog();
#endif
	void OnContinue();

public:
	inline unsigned int GetProfile() { return m_profile_box->GetProfile(); }
	inline enum_video_area GetVideoArea() { return (enum_video_area) clamp(m_buttongroup_video_area->checkedId(), 0, VIDEO_AREA_COUNT - 1); }
	inline unsigned int GetVideoAreaScreen() { return m_combobox_screens->currentIndex(); }
	inline bool GetVideoAreaFollowFullscreen() { return m_checkbox_follow_fullscreen->isChecked(); }
#if SSR_USE_V4L2
	inline QString GetVideoV4L2Device() { return m_lineedit_v4l2_device->text(); }
#endif
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
#if SSR_USE_ALSA
	inline unsigned int GetALSASource() { return clamp(m_combobox_alsa_source->currentIndex(), 0, (int) m_alsa_sources.size() - 1); }
#endif
#if SSR_USE_PULSEAUDIO
	inline unsigned int GetPulseAudioSource() { return clamp(m_combobox_pulseaudio_source->currentIndex(), 0, (int) m_pulseaudio_sources.size() - 1); }
#endif
#if SSR_USE_JACK
	inline bool GetJackConnectSystemCapture() { return m_checkbox_jack_connect_system_capture->isChecked(); }
	inline bool GetJackConnectSystemPlayback() { return m_checkbox_jack_connect_system_playback->isChecked(); }
#endif
#if SSR_USE_OPENGL_RECORDING
	inline QString GetGLInjectChannel() { return m_glinject_channel; }
	inline bool GetGLInjectRelaxPermissions() { return m_glinject_relax_permissions; }
	inline QString GetGLInjectCommand() { return m_glinject_command; }
	inline QString GetGLInjectWorkingDirectory() { return m_glinject_working_directory; }
	inline bool GetGLInjectAutoLaunch() { return m_glinject_auto_launch; }
	inline bool GetGLInjectLimitFPS() { return m_glinject_limit_fps; }
#endif

	inline void SetProfile(unsigned int profile) { m_profile_box->SetProfile(profile); }
	inline void SetVideoArea(enum_video_area area) { QAbstractButton *b = m_buttongroup_video_area->button(area); if(b != NULL) b->setChecked(true); }
	inline void SetVideoAreaScreen(unsigned int screen) { m_combobox_screens->setCurrentIndex(clamp(screen, 0u, (unsigned int) m_combobox_screens->count() - 1)); }
	inline void SetVideoAreaFollowFullscreen(bool follow_fulscreen) { m_checkbox_follow_fullscreen->setChecked(follow_fulscreen); }
#if SSR_USE_V4L2
	inline void SetVideoV4L2Device(const QString& device) { m_lineedit_v4l2_device->setText(device); }
#endif
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
#if SSR_USE_ALSA
	inline void SetALSASource(unsigned int source) { m_combobox_alsa_source->setCurrentIndex(clamp(source, 0u, (unsigned int) m_alsa_sources.size() - 1)); }
#endif
#if SSR_USE_PULSEAUDIO
	inline void SetPulseAudioSource(unsigned int source) { m_combobox_pulseaudio_source->setCurrentIndex(clamp(source, 0u, (unsigned int) m_pulseaudio_sources.size() - 1)); }
#endif
#if SSR_USE_JACK
	inline void SetJackConnectSystemCapture(bool connect) { m_checkbox_jack_connect_system_capture->setChecked(connect); }
	inline void SetJackConnectSystemPlayback(bool connect) { m_checkbox_jack_connect_system_playback->setChecked(connect); }
#endif
#if SSR_USE_OPENGL_RECORDING
	inline void SetGLInjectChannel(const QString& channel) { m_glinject_channel = channel; }
	inline void SetGLInjectRelaxPermissions(bool relax_permissions) { m_glinject_relax_permissions = relax_permissions; }
	inline void SetGLInjectCommand(const QString& command) { m_glinject_command = command; }
	inline void SetGLInjectWorkingDirectory(const QString& glinject_working_directory) { m_glinject_working_directory = glinject_working_directory; }
	inline void SetGLInjectAutoLaunch(bool auto_launch) { m_glinject_auto_launch = auto_launch; }
	inline void SetGLInjectLimitFPS(bool limit_fps) { m_glinject_limit_fps = limit_fps; }
#endif

};
