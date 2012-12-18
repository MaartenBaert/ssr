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
	std::unique_ptr<QRubberBand> m_rubber_band;
	QRect m_rubber_band_rect;

	QString m_glinject_command;
	bool m_glinject_run_command;
	unsigned int m_glinject_max_megapixels;

	QButtonGroup *m_buttongroup_video_area;
	QComboBox *m_combobox_screens;
	QPushButton *m_pushbutton_video_select_rectangle, *m_pushbutton_video_select_window, *m_pushbutton_video_select_program;
	QLineEdit *m_lineedit_video_x, *m_lineedit_video_y, *m_lineedit_video_w, *m_lineedit_video_h;
	QLineEdit *m_lineedit_video_frame_rate;
	QCheckBox *m_checkbox_scale;
	QLineEdit *m_lineedit_video_scaled_w, *m_lineedit_video_scaled_h;
	QCheckBox *m_checkbox_show_cursor;

	QCheckBox *m_checkbox_audio_enable;
	QLineEdit *m_lineedit_audio_source;

public:
	PageInput(MainWindow* main_window);

	void LoadSettings(QSettings* settings);
	void SaveSettings(QSettings* settings);

public:
	inline enum_video_area GetVideoArea() { return (enum_video_area) clamp(0, VIDEO_AREA_COUNT - 1, m_buttongroup_video_area->checkedId()); }
	inline unsigned int GetVideoAreaScreen() { return m_combobox_screens->currentIndex(); }
	inline unsigned int GetVideoX() { return m_lineedit_video_x->text().toUInt(); }
	inline unsigned int GetVideoY() { return m_lineedit_video_y->text().toUInt(); }
	inline unsigned int GetVideoW() { return m_lineedit_video_w->text().toUInt(); }
	inline unsigned int GetVideoH() { return m_lineedit_video_h->text().toUInt(); }
	inline unsigned int GetVideoFrameRate() { return m_lineedit_video_frame_rate->text().toUInt(); }
	inline bool GetVideoScalingEnabled() { return m_checkbox_scale->isChecked(); }
	inline unsigned int GetVideoScaledW() { return m_lineedit_video_scaled_w->text().toUInt(); }
	inline unsigned int GetVideoScaledH() { return m_lineedit_video_scaled_h->text().toUInt(); }
	inline bool GetVideoShowCursor() { return m_checkbox_show_cursor->isChecked(); }
	inline bool GetAudioEnabled() { return m_checkbox_audio_enable->isChecked(); }
	inline QString GetAudioSource() { return m_lineedit_audio_source->text(); }
	inline QString GetGLInjectCommand() { return m_glinject_command; }
	inline bool GetGLInjectRunCommand() { return m_glinject_run_command; }
	inline unsigned int GetGLInjectMaxMegaPixels() { return m_glinject_max_megapixels; }

	inline void SetVideoArea(enum_video_area area) { QAbstractButton *b = m_buttongroup_video_area->button(area); if(b != NULL) b->setChecked(true); }
	inline void SetVideoAreaScreen(unsigned int screen) { m_combobox_screens->setCurrentIndex(clamp<unsigned int>(0, m_combobox_screens->count() - 1, screen)); }
	inline void SetVideoX(unsigned int x) { m_lineedit_video_x->setText(QString::number(x)); }
	inline void SetVideoY(unsigned int y) { m_lineedit_video_y->setText(QString::number(y)); }
	inline void SetVideoW(unsigned int w) { m_lineedit_video_w->setText(QString::number(w)); }
	inline void SetVideoH(unsigned int h) { m_lineedit_video_h->setText(QString::number(h)); }
	inline void SetVideoFrameRate(unsigned int frame_rate) { m_lineedit_video_frame_rate->setText(QString::number(frame_rate)); }
	inline void SetVideoScalingEnabled(bool enable) { m_checkbox_scale->setChecked(enable); }
	inline void SetVideoScaledW(unsigned int scaled_w) { m_lineedit_video_scaled_w->setText(QString::number(scaled_w)); }
	inline void SetVideoScaledH(unsigned int scaled_h) { m_lineedit_video_scaled_h->setText(QString::number(scaled_h)); }
	inline void SetVideoShowCursor(bool show) { m_checkbox_show_cursor->setChecked(show); }
	inline void SetAudioEnabled(bool enable) { m_checkbox_audio_enable->setChecked(enable); }
	inline void SetAudioSource(const QString& source) { m_lineedit_audio_source->setText(source); }
	inline void SetGLInjectCommand(const QString& command) { m_glinject_command = command; }
	inline void SetGLInjectRunCommand(bool run_command) { m_glinject_run_command = run_command; }
	inline void SetGLInjectMaxMegaPixels(unsigned int max_megapixels) { m_glinject_max_megapixels = max_megapixels; }

protected:
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseReleaseEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);
	virtual void keyPressEvent(QKeyEvent* event);

private:
	void StartGrabbing();
	void StopGrabbing();
	void SetVideoAreaFromRubberBand();

public slots:
	void UpdateVideoAreaFields();
	void UpdateVideoScaleFields();
	void UpdateAudioFields();

private slots:
	void UpdateScreenConfiguration();
	void StartSelectRectangle();
	void StartSelectWindow();
	void SelectProgramDialog();
	void Continue();

};

class DialogGLInject : public QDialog {
	Q_OBJECT

private:
	PageInput *m_parent;

	QLineEdit *m_lineedit_command;
	QCheckBox *m_checkbox_run_command;
	QLineEdit *m_lineedit_max_megapixels;

public:
	DialogGLInject(PageInput* parent);

private slots:
	void OnAccept();

};
