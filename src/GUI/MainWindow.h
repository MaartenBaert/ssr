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

class PageWelcome;
class PageInput;
class PageOutput;
class PageRecord;
class PageDone;

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	enum enum_nvidia_disable_flipping {
		NVIDIA_DISABLE_FLIPPING_ASK,
		NVIDIA_DISABLE_FLIPPING_YES,
		NVIDIA_DISABLE_FLIPPING_NO,
		NVIDIA_DISABLE_FLIPPING_COUNT // must be last
	};

public:
	static const QString WINDOW_CAPTION;

private:
	enum_nvidia_disable_flipping m_nvidia_disable_flipping;
	bool m_nvidia_reenable_flipping;

	QRect m_old_geometry;

	QStackedLayout *m_stacked_layout;
	PageWelcome *m_page_welcome;
	PageInput *m_page_input;
	PageOutput *m_page_output;
	PageRecord *m_page_record;
	PageDone *m_page_done;

public:
	MainWindow();
	~MainWindow();

	void LoadSettings();
	void SaveSettings();

	bool IsBusy();
	bool Validate();
	void Quit();

protected:
	virtual void closeEvent(QCloseEvent* event) override;

public:
	inline PageInput* GetPageInput() { return m_page_input; }
	inline PageOutput* GetPageOutput() { return m_page_output; }

	inline enum_nvidia_disable_flipping GetNVidiaDisableFlipping() { return m_nvidia_disable_flipping; }

	inline void SetNVidiaDisableFlipping(enum_nvidia_disable_flipping flipping) { m_nvidia_disable_flipping = (enum_nvidia_disable_flipping) clamp((unsigned int) flipping, 0u, (unsigned int) NVIDIA_DISABLE_FLIPPING_COUNT - 1); }

public slots:
	void GoPageStart();
	void GoPageWelcome();
	void GoPageInput();
	void GoPageOutput();
	void GoPageRecord();
	void GoPageDone();

	void OnShow();
	void OnHide();
	void OnShowHide();
	void OnSysTrayActivated(QSystemTrayIcon::ActivationReason reason);

};
