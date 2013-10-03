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

#include "Icons.h"
#include "Logger.h"
#include "MainWindow.h"

#include "Version.h"

bool g_option_logfile;
QString g_option_statsfile;
bool g_option_syncdiagram;

int main(int argc, char* argv[]) {

	XInitThreads();

	QApplication application(argc, argv);

	// SSR uses two separate character encodings:
	// - UTF-8: Used for all internal strings.
	//   Used by QString::fromAscii and QString::toAscii, and all implicit conversions from C-strings to QString.
	// - Local character encoding: Used for file names and logs. In practice this will almost always be UTF-8 as well.
	//   Used by QString::fromLocal8Bit and QString::toLocal8Bit.
	// If it is not clear what encoding an external library uses, I use UTF-8 except when it is a file name.
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

	QCoreApplication::setOrganizationName("SimpleScreenRecorder");
	QCoreApplication::setApplicationName("SimpleScreenRecorder");

	// Qt doesn't count hidden windows, so if the main window is hidden and a dialog box is closed, Qt thinks the application should quit.
	// That's not what we want, so disable this and do it manually.
	QApplication::setQuitOnLastWindowClosed(false);

	Logger logger;
	Q_UNUSED(logger);

	// load icons
	LoadIcons();

	// initialize default command-line options
	g_option_logfile = false;
	g_option_statsfile = QString();
	g_option_syncdiagram = false;

	// read command-line arguments
	QStringList args = QCoreApplication::arguments();
	for(int i = 1; i < args.count(); ++i) {
		QString arg = args[i];
		if(arg.startsWith("--")) {

			// split into option and value
			QString option, value;
			int p = arg.indexOf('=');
			if(p < 0) {
				option = arg.mid(2);
			} else {
				option = arg.mid(2, p - 2);
				value = arg.mid(p + 1);
			}

			// handle options
			if(option == "logfile") {
				if(!value.isNull()) {
					Logger::LogError("[main] Error: Option 'logfile' does not take a value!");
					return 1;
				}
				g_option_logfile = true;
			} else if(option == "statsfile") {
				if(value.isNull()) {
					g_option_statsfile = "/dev/shm/simplescreenrecorder-stats-" + QString::number(QCoreApplication::applicationPid());
				} else {
					g_option_statsfile = value;
				}
			} else if(option == "syncdiagram") {
				if(!value.isNull()) {
					Logger::LogError("[main] Error: Option 'syncdiagram' does not take a value!");
					return 1;
				}
				g_option_syncdiagram = true;
			} else {
				Logger::LogError("[main] Error: Unknown command-line option '" + option + "'!");
				return 1;
			}

		} else {

			// handle other arguments
			Logger::LogError("[main] Error: Unknown command-line argument '" + arg + "'!");
			return 1;

		}
	}

	// redirect stdout and stderr to a log file
	if(g_option_logfile) {
		QDateTime now = QDateTime::currentDateTime();
		QDir dir(GetApplicationUserDir());
		dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
		dir.setNameFilters(QStringList("log-*.txt"));
		for(QString oldfile : dir.entryList()) {
			if(QFileInfo(dir.path() + "/" + oldfile).lastModified().daysTo(now) > 30) {
				QFile(dir.path() + "/" + oldfile).remove();
			}
		}
		QString file = dir.path() + "/log-" + now.toString(Qt::ISODate) + ".txt";
		FILE *f = fopen(file.toLocal8Bit().constData(), "w");
		dup2(fileno(f), 1); // redirect stdout
		dup2(fileno(f), 2); // redirect stderr
	}

	// warning for glitch with proprietary NVIDIA drivers
	if(DetectNVIDIAFlipping()) {
		if(QMessageBox::warning(NULL, MainWindow::WINDOW_CAPTION,
								"SimpleScreenRecorder has detected that you are using the proprietary NVIDIA driver with flipping enabled. "
								"This is known to cause glitches during recording. It is recommended to disable flipping. Do you want me to do this for you?",
								QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
			if(!DisableNVIDIAFlipping()) {
				QMessageBox::warning(NULL, MainWindow::WINDOW_CAPTION, "I couldn't disable flipping for some reason - sorry! Try disabling it from the NVIDIA control panel.", QMessageBox::Ok);
			}
		}
	}

	Logger::LogInfo("==================== Starting SSR ====================");
	Logger::LogInfo(GetVersionInfo());

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

// see definition of AV_VERSION_INT() in libavutil/version.h
inline QString av_version(unsigned int ver) {
	return QString::number((ver >> 16) & 0xff) + "." + QString::number((ver >> 8) & 0xff) + "." + QString::number(ver & 0xff);
}

QString GetVersionInfo() {
	return QString() +
			"SimpleScreenRecorder: " + SSR_VERSION + "\n"
			"Qt: header " + QT_VERSION_STR + ", lib " + qVersion() + "\n"
			"libavformat: header " + av_version(LIBAVFORMAT_VERSION_INT) + ", lib " + av_version(avformat_version()) + "\n"
			"libavcodec: header " + av_version(LIBAVCODEC_VERSION_INT) + ", lib " + av_version(avcodec_version()) + "\n"
			"libavutil: header " + av_version(LIBAVUTIL_VERSION_INT) + ", lib " + av_version(avutil_version()) + "\n"
			"libswscale: header " + av_version(LIBSWSCALE_VERSION_INT) + ", lib " + av_version(swscale_version());
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
