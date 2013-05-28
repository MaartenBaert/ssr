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

#include "Global.h"
#include "Main.h"

#include "MainWindow.h"
#include "Logger.h"

int main(int argc, char* argv[]) {
	Logger logger;
	Q_UNUSED(logger);

	XInitThreads();

	QApplication application(argc, argv);
	QCoreApplication::setOrganizationName("SimpleScreenRecorder");
	QCoreApplication::setApplicationName("SimpleScreenRecorder");

	bool logfile = false;

	QStringList args = QCoreApplication::arguments();
	for(int i = 1; i < args.count(); ++i) {
		QString cmd = args[i];
		if(cmd == "--logfile") {
			logfile = true;
		} else {
			Logger::LogError("[main] Error: Unknown command-line option '" + cmd + "'!");
			return -1;
		}
	}

	if(logfile) {
		QString dir = GetApplicationUserDir();
		QString file1 = dir + "/log1.txt";
		QString file2 = dir + "/log2.txt";
		QString file3 = dir + "/log3.txt";
		rename(qPrintable(file2), qPrintable(file3));
		rename(qPrintable(file1), qPrintable(file2));
		FILE *f = freopen(qPrintable(file1), "w", stderr);
		Q_UNUSED(f);
		dup2(2, 1); // this redirects stdout to stderr
	}

	// warning for glitch with proprietary NVIDIA drivers
	if(DetectNVIDIAFlipping()) {
		if(QMessageBox::warning(NULL, MainWindow::WINDOW_CAPTION, "SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?",
								QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
			if(!DisableNVIDIAFlipping()) {
				QMessageBox::warning(NULL, MainWindow::WINDOW_CAPTION, "I couldn't disable flipping for some reason - sorry! Try disabling it from the NVIDIA control panel.", QMessageBox::Ok);
			}
		}
	}

	Logger::LogInfo("==================== Starting SSR ====================");

	MainWindow mainwindow;
	mainwindow.show();
	int ret = application.exec();

	Logger::LogInfo("==================== Stopping SSR ====================");

	return ret;
}

QString GetApplicationUserDir() {
	QString dir = QDir::homePath() + "/.ssr";
	if(!QDir::root().mkpath(dir)) {
		Logger::LogError("[GetApplicationUserDir] Error: Can't create .ssr directory!");
		throw 0;
	}
	return dir;
}

bool DetectNVIDIAFlipping() {
	QString program = "nvidia-settings";
	QStringList args;
	args << "-tq" << "AllowFlipping";
	QProcess p;
	p.start(program, args);
	p.waitForFinished();
	if(p.exitCode() != 0)
		return false;
	QString result = p.readAll();
	return (result.trimmed() == "1");
}

bool DisableNVIDIAFlipping() {
	QString program = "nvidia-settings";
	QStringList args;
	args << "-a" << "AllowFlipping=0";
	QProcess p;
	p.start(program, args);
	p.waitForFinished();
	if(p.exitCode() != 0)
		return false;
	return !DetectNVIDIAFlipping();
}
