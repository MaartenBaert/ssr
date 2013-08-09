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

class MainWindow;
class WidgetScreenLabel;

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

private:
	MainWindow *m_main_window;

	bool m_grabbing, m_selecting_window;
	std::unique_ptr<QRubberBand> m_rubber_band, m_recording_frame;
	QRect m_rubber_band_rect, m_select_window_outer_rect, m_select_window_inner_rect;

	QString m_glinject_command;
	bool m_glinject_run_command, m_glinject_relax_permissions;
	unsigned int m_glinject_max_megapixels;
	bool m_glinject_capture_front, m_glinject_limit_fps;

	std::vector<WidgetScreenLabel*> m_screen_labels;

	QButtonGroup *m_buttongroup_video_area;
	QComboBoxWithSignal *m_combobox_screens;
	QPushButton *m_pushbutton_video_select_rectangle, *m_pushbutton_video_select_window, *m_pushbutton_video_opengl_settings;
	QSpinBoxWithSignal *m_spinbox_video_x, *m_spinbox_video_y, *m_spinbox_video_w, *m_spinbox_video_h;
	QSpinBox *m_spinbox_video_frame_rate;
	QCheckBox *m_checkbox_scale;
	QSpinBox *m_spinbox_video_scaled_w, *m_spinbox_video_scaled_h;
	QCheckBox *m_checkbox_record_cursor;

	QCheckBox *m_checkbox_audio_enable;
	QLineEdit *m_lineedit_alsa_device;

public:
	PageInput(MainWindow* main_window);

	void LoadSettings(QSettings* settings);
	void SaveSettings(QSettings* settings);

public:
	inline enum_video_area GetVideoArea() { return (enum_video_area) clamp(0, VIDEO_AREA_COUNT - 1, m_buttongroup_video_area->checkedId()); }
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
	inline QString GetALSADevice() { return m_lineedit_alsa_device->text(); }
	inline QString GetGLInjectCommand() { return m_glinject_command; }
	inline bool GetGLInjectRunCommand() { return m_glinject_run_command; }
	inline bool GetGLInjectRelaxPermissions() { return m_glinject_relax_permissions; }
	inline unsigned int GetGLInjectMaxMegaPixels() { return m_glinject_max_megapixels; }
	inline bool GetGLInjectCaptureFront() { return m_glinject_capture_front; }
	inline bool GetGLInjectLimitFPS() { return m_glinject_limit_fps; }

	inline void SetVideoArea(enum_video_area area) { QAbstractButton *b = m_buttongroup_video_area->button(area); if(b != NULL) b->setChecked(true); }
	inline void SetVideoAreaScreen(unsigned int screen) { m_combobox_screens->setCurrentIndex(clamp<unsigned int>(0, m_combobox_screens->count() - 1, screen)); }
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
	inline void SetALSADevice(const QString& source) { m_lineedit_alsa_device->setText(source); }
	inline void SetGLInjectCommand(const QString& command) { m_glinject_command = command; }
	inline void SetGLInjectRunCommand(bool run_command) { m_glinject_run_command = run_command; }
	inline void SetGLInjectRelaxPermissions(bool relax_permissions) { m_glinject_relax_permissions = relax_permissions; }
	inline void SetGLInjectMaxMegaPixels(unsigned int max_megapixels) { m_glinject_max_megapixels = clamp<unsigned int>(0, 100, max_megapixels); }
	inline void SetGLInjectCaptureFront(bool capture_front) { m_glinject_capture_front = capture_front; }
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

public slots:
	void UpdateRecordingFrame();
	void UpdateVideoAreaFields();
	void UpdateVideoScaleFields();
	void UpdateAudioFields();

private slots:
	void UpdateScreenConfiguration();
	void IdentifyScreens();
	void StopIdentifyScreens();
	void StartSelectRectangle();
	void StartSelectWindow();
	void GLInjectDialog();
	void Continue();

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

class DialogGLInject : public QDialog {
	Q_OBJECT

private:
	PageInput *m_parent;

	QLineEdit *m_lineedit_command;
	QCheckBox *m_checkbox_run_command, *m_checkbox_relax_permissions;
	QLineEdit *m_lineedit_max_megapixels;
	QCheckBox *m_checkbox_capture_front, *m_checkbox_limit_fps;

public:
	DialogGLInject(PageInput* parent);

private slots:
	void WriteBack();

};
