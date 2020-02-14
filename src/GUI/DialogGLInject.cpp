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

#include "DialogGLInject.h"

#if SSR_USE_OPENGL_RECORDING

#include "Logger.h"
#include "MainWindow.h"
#include "PageInput.h"

#include "GLInjectInput.h"

DialogGLInject::DialogGLInject(PageInput* parent)
	: QDialog(parent) {

	m_parent = parent;

	setWindowTitle(tr("OpenGL Settings"));

	QLabel *label_info = new QLabel(this);
	label_info->setText(tr("<p>Warning: OpenGL recording works by injecting a library into the program that will be recorded. "
						   "This library will override some system functions in order to capture the frames before they are "
						   "displayed on the screen. If you are trying to record a game that tries to detect hacking attempts "
						   "on the client side, it's (theoretically) possible that the game will consider this a hack. This "
						   "might even get you banned, so it's a good idea to make sure that the program you want to record "
						   "won't ban you, *before* you try to record it. You've been warned :).</p>\n\n"
						   "<p>Another warning: OpenGL recording is experimental, it may not work or even crash the program you "
						   "are recording. If you are worried about losing program data, make a backup first!</p>\n\n"
						   "<p>If you want to record Steam games, <a href=\"http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/\">read this first</a>.</p>"));
	label_info->setWordWrap(true);
	label_info->setTextFormat(Qt::RichText);
	label_info->setTextInteractionFlags(Qt::TextBrowserInteraction);
	label_info->setOpenExternalLinks(true);

	QGroupBox *groupbox_channel = new QGroupBox(tr("Choose channel"), this);
	{
		QLabel *label_channel = new QLabel(tr("Channel name:"), groupbox_channel);
		m_lineedit_channel = new QLineEdit(m_parent->GetGLInjectChannel(), groupbox_channel);
		m_lineedit_channel->setToolTip(tr("Channel names are used to identify applications. You only need to use this if you want to record multiple applications at the same time.\n"
										  "If you leave this empty, the default name 'channel-YOURUSERNAME' will be used."));
		m_checkbox_relax_permissions = new QCheckBox(tr("Relax shared memory permissions (insecure)"), groupbox_channel);
		m_checkbox_relax_permissions->setToolTip(tr("If checked, other users on the same machine will be able to attach to the shared memory that's used for communication with the OpenGL program.\n"
													"This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.\n"
													"This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user."));
		m_checkbox_relax_permissions->setChecked(m_parent->GetGLInjectRelaxPermissions());

		QVBoxLayout *layout = new QVBoxLayout(groupbox_channel);
		{
			QGridLayout *layout2 = new QGridLayout();
			layout->addLayout(layout2);
			layout2->addWidget(label_channel, 0, 0);
			layout2->addWidget(m_lineedit_channel, 0, 1);
		}
		layout->addWidget(m_checkbox_relax_permissions);
	}

	QGroupBox *groupbox_launch = new QGroupBox(tr("Launch application"), this);
	{
		QLabel *label_command = new QLabel(tr("Command:"), groupbox_launch);
		m_lineedit_command = new QLineEdit(m_parent->GetGLInjectCommand(), groupbox_launch);
		m_lineedit_command->setToolTip(tr("This command will be executed to start the program that should be recorded."));
		m_lineedit_command->setMinimumWidth(300);
		QLabel *label_working_directory = new QLabel(tr("Working directory:"), groupbox_launch);
		m_lineedit_working_directory = new QLineEdit(m_parent->GetGLInjectWorkingDirectory(), groupbox_launch);
		m_lineedit_working_directory->setToolTip(tr("The command will be executed in this directory. If you leave this empty, the working directory won't be changed."));
		m_lineedit_working_directory->setMinimumWidth(300);
		m_checkbox_auto_launch = new QCheckBox(tr("Launch automatically"), this);
		m_checkbox_auto_launch->setToolTip(tr("If checked, the application will be launched automatically once you go to the recording page. If not checked, you have to start it manually."));
		m_checkbox_auto_launch->setChecked(m_parent->GetGLInjectAutoLaunch());
		QPushButton *pushbutton_launch = new QPushButton(tr("Launch now"), this);

		connect(pushbutton_launch, SIGNAL(clicked()), this, SLOT(OnLaunchNow()));

		QVBoxLayout *layout = new QVBoxLayout(groupbox_launch);
		{
			QGridLayout *layout2 = new QGridLayout();
			layout->addLayout(layout2);
			layout2->addWidget(label_command, 0, 0);
			layout2->addWidget(m_lineedit_command, 0, 1);
			layout2->addWidget(label_working_directory, 1, 0);
			layout2->addWidget(m_lineedit_working_directory, 1, 1);
		}
		{
			QHBoxLayout *layout2 = new QHBoxLayout();
			layout->addLayout(layout2);
			layout2->addWidget(m_checkbox_auto_launch);
			layout2->addWidget(pushbutton_launch);
		}
	}

	QGroupBox *groupbox_stream = new QGroupBox(tr("Stream settings"), this);
	{
		m_checkbox_limit_fps = new QCheckBox(tr("Limit application frame rate"), this);
		m_checkbox_limit_fps->setToolTip(tr("If checked, the injected library will slow down the application so the frame rate doesn't become higher than the recording frame rate.\n"
											"This stops the application from wasting CPU time for frames that won't be recorded, and sometimes results in smoother video\n"
											"(this depends on the application)."));
		m_checkbox_limit_fps->setChecked(m_parent->GetGLInjectLimitFPS());

		QVBoxLayout *layout = new QVBoxLayout(groupbox_stream);
		layout->addWidget(m_checkbox_limit_fps);
	}

	QPushButton *pushbutton_close = new QPushButton(tr("Close"), this);
	pushbutton_close->setDefault(true);

	connect(pushbutton_close, SIGNAL(clicked()), this, SLOT(accept()));
	connect(this, SIGNAL(accepted()), this, SLOT(OnWriteBack()));
	connect(this, SIGNAL(rejected()), this, SLOT(OnWriteBack()));

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(label_info);
	layout->addWidget(groupbox_channel);
	layout->addWidget(groupbox_launch);
	layout->addWidget(groupbox_stream);
	layout->addStretch();
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addStretch();
		layout2->addWidget(pushbutton_close);
		layout2->addStretch();
	}

	setMinimumSize(minimumSizeHint()); // workaround for Qt bug

}

DialogGLInject::~DialogGLInject() {

}

void DialogGLInject::OnWriteBack() {
	m_parent->SetGLInjectChannel(m_lineedit_channel->text());
	m_parent->SetGLInjectRelaxPermissions(m_checkbox_relax_permissions->isChecked());
	m_parent->SetGLInjectCommand(m_lineedit_command->text());
	m_parent->SetGLInjectWorkingDirectory(m_lineedit_working_directory->text());
	m_parent->SetGLInjectAutoLaunch(m_checkbox_auto_launch->isChecked());
	m_parent->SetGLInjectLimitFPS(m_checkbox_limit_fps->isChecked());
}

void DialogGLInject::OnLaunchNow() {
	if(!GLInjectInput::LaunchApplication(m_lineedit_channel->text(), m_checkbox_relax_permissions->isChecked(), m_lineedit_command->text(), m_lineedit_working_directory->text())) {
		QMessageBox::critical(NULL, MainWindow::WINDOW_CAPTION, Logger::tr("The application could not be launched."), QMessageBox::Ok);
	}
}

#endif
