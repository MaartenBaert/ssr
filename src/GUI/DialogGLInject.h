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

#if SSR_USE_OPENGL_RECORDING

class PageInput;

class DialogGLInject : public QDialog {
	Q_OBJECT

private:
	PageInput *m_parent;

	QLineEdit *m_lineedit_channel;
	QCheckBox *m_checkbox_relax_permissions;

	QLineEdit *m_lineedit_command, *m_lineedit_working_directory;
	QCheckBox *m_checkbox_auto_launch;

	QCheckBox *m_checkbox_limit_fps;

public:
	DialogGLInject(PageInput* parent);
	~DialogGLInject();

private slots:
	void OnWriteBack();
	void OnLaunchNow();

};

#endif
