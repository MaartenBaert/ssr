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

#include "Global.h"
#include "Main.h"

#include "Benchmark.h"
#include "CPUFeatures.h"
#include "HotkeyListener.h"
#include "Icons.h"
#include "Logger.h"
#include "MainWindow.h"

bool g_option_logfile = false;
QString g_option_statsfile = QString();
bool g_option_syncdiagram = false;
bool g_option_systray = true;
bool g_option_start_hidden = false;
bool g_option_benchmark = false;

void PrintOptionHelp() {
	Logger::LogInfo(
				"Usage: simplescreenrecorder [OPTIONS]\n"
				"\n"
				"Options:\n"
				"  --help              Show this help message.\n"
				"  --logfile           Write log to ~/.ssr/log-DATE_TIME.txt instead of stdout.\n"
				"  --statsfile[=FILE]  Write recording statistics to FILE. If FILE is omitted,\n"
				"                      /dev/shm/simplescreenrecorder-stats-PID is used. It will\n"
				"                      be updated continuously and deleted when the recording\n"
				"                      page is closed.\n"
				"  --syncdiagram       Show synchronization diagram (for debugging).\n"
				"  --no-systray        Don't show the system tray icon.\n"
				"  --start-hidden      Start the application in hidden form.\n"
	);
}

int main(int argc, char* argv[]) {

	XInitThreads();

	QApplication application(argc, argv);

	// SSR uses two separate character encodings:
	// - UTF-8: Used for all internal strings.
	//   Used by QString::fromAscii and QString::toAscii, and all implicit conversions from C-strings to QString. Also used for translations.
	// - Local character encoding: Used for file names and logs. In practice this will almost always be UTF-8 as well.
	//   Used by QString::fromLocal8Bit and QString::toLocal8Bit.
	// If it is not clear what encoding an external library uses, I use the local encoding for file names and UTF-8 for everything else.
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
#endif

	// set the application name
	QCoreApplication::setOrganizationName("SimpleScreenRecorder");
	QCoreApplication::setApplicationName("SimpleScreenRecorder");

	// load Qt translations
	QTranslator translator_qt;
	if(!translator_qt.load(QLocale::system(), "qt", "_", QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
	//if(!translator_qt.load("qt_" + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
		qDebug() << "Could not load system translator.";
	QApplication::installTranslator(&translator_qt);

	// load SSR translations
	QTranslator translator_ssr;
	if(!translator_ssr.load(QLocale::system(), "simplescreenrecorder", "_", QCoreApplication::applicationDirPath()))
		translator_ssr.load(QLocale::system(), "simplescreenrecorder", "_", GetApplicationSystemDir("translations"));
	QApplication::installTranslator(&translator_ssr);

	// Qt doesn't count hidden windows, so if the main window is hidden and a dialog box is closed, Qt thinks the application should quit.
	// That's not what we want, so disable this and do it manually.
	QApplication::setQuitOnLastWindowClosed(false);

	// create logger
	Logger logger;
	Q_UNUSED(logger);

	// load icons
	LoadIcons();

	// read command-line arguments
	QStringList args = QCoreApplication::arguments();
	for(int i = 1; i < args.count(); ++i) {
		QString arg = args[i];
		if(arg.startsWith("-")) {

			// split into option and value
			QString option, value;
			int p = arg.indexOf('=');
			if(p < 0) {
				option = arg;
			} else {
				option = arg.mid(0, p);
				value = arg.mid(p + 1);
				if(value.isNull())
					value = "";
			}

#define NOVALUE \
			if(!value.isNull()) { \
				Logger::LogError("[main] " + Logger::tr("Error: Command-line option '%1' does not take a value!").arg(option)); \
				PrintOptionHelp(); \
				return 1; \
			}

			// handle options
			if(option == "--help") {
				PrintOptionHelp();
				return 0;
			} else if(option == "--logfile") {
				NOVALUE
				g_option_logfile = true;
			} else if(option == "--statsfile") {
				if(value.isNull()) {
					g_option_statsfile = "/dev/shm/simplescreenrecorder-stats-" + QString::number(QCoreApplication::applicationPid());
				} else {
					g_option_statsfile = value;
				}
			} else if(option == "--syncdiagram") {
				NOVALUE
				g_option_syncdiagram = true;
			} else if(option == "--no-systray") {
				NOVALUE
				g_option_systray = false;
			} else if(option == "--start-hidden") {
				NOVALUE
				g_option_start_hidden = true;
			} else if(option == "--benchmark") {
				NOVALUE
				g_option_benchmark = true;
			} else {
				Logger::LogError("[main] " + Logger::tr("Error: Unknown command-line option '%1'!").arg(option));
				PrintOptionHelp();
				return 1;
			}

#undef NOVALUE

		} else {

			// handle other arguments
			Logger::LogError("[main] " + Logger::tr("Error: Unknown command-line argument '%1'!").arg(arg));
			PrintOptionHelp();
			return 1;

		}
	}

	// redirect stdout and stderr to a log file
	if(g_option_logfile) {

		// delete logs from versions < 0.2.3 (should be removed at some point in the future)
		{
			QDir dir(GetApplicationUserDir());
			dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
			dir.setNameFilters(QStringList("log-*.txt"));
			for(QFileInfo fileinfo : dir.entryInfoList()) {
				QFile(fileinfo.filePath()).remove();
			}
		}

		// delete old logs
		QDateTime now = QDateTime::currentDateTime();
		QDir dir(GetApplicationUserDir("logs"));
		dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
		dir.setNameFilters(QStringList("log-*.txt"));
		for(QFileInfo fileinfo : dir.entryInfoList()) {
			if(fileinfo.lastModified().daysTo(now) > 30) {
				QFile(fileinfo.filePath()).remove();
			}
		}

		// open new log
		QString file = dir.path() + "/log-" + now.toString("yyyy-MM-dd_hh.mm.ss") + ".txt";
		FILE *f = fopen(file.toLocal8Bit().constData(), "a");
		dup2(fileno(f), 1); // redirect stdout
		dup2(fileno(f), 2); // redirect stderr

	}

	// start logging
	Logger::LogInfo("==================== " + Logger::tr("SSR started") + " ====================");
	Logger::LogInfo(GetVersionInfo());

#if SSR_USE_X86_ASM
	// detect CPU features
	CPUFeatures::Detect();
#endif

	// start the GUI
	int ret;
	if(g_option_benchmark) {
		Benchmark();
		ret = 0;
	} else {

		// create hotkey listener
		HotkeyListener hotkey_listener;
		Q_UNUSED(hotkey_listener);

		// create main window
		MainWindow mainwindow;

		// run application
		ret = application.exec();

	}

	// stop logging
	Logger::LogInfo("==================== " + Logger::tr("SSR stopped") + " ====================");

	return ret;
}

QString GetApplicationSystemDir(const QString& subdir) {
	QString dir = SSR_SYSTEM_DIR;
	if(!subdir.isEmpty())
		dir += "/" + subdir;
	return dir;
}

QString GetApplicationUserDir(const QString& subdir) {
	QString dir = QDir::homePath() + "/.ssr";
	if(!subdir.isEmpty())
		dir += "/" + subdir;
	if(!QDir::root().mkpath(dir)) {
		Logger::LogError("[GetApplicationUserDir] " + Logger::tr("Error: Can't create .ssr directory!"));
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
			"SimpleScreenRecorder " + PACKAGE_VERSION + "\n"
#ifdef __clang__
			"Compiled with Clang " + QString::number(__clang_major__) + "." + QString::number(__clang_minor__) + "." + QString::number(__clang_patchlevel__) + "\n"
#else
			"Compiled with GCC " + QString::number(__GNUC__) + "." + QString::number(__GNUC_MINOR__) + "." + QString::number(__GNUC_PATCHLEVEL__) + "\n"
#endif
			"Qt: header " + QT_VERSION_STR + ", lib " + qVersion() + "\n"
			"libavformat: header " + av_version(LIBAVFORMAT_VERSION_INT) + ", lib " + av_version(avformat_version()) + "\n"
			"libavcodec: header " + av_version(LIBAVCODEC_VERSION_INT) + ", lib " + av_version(avcodec_version()) + "\n"
			"libavutil: header " + av_version(LIBAVUTIL_VERSION_INT) + ", lib " + av_version(avutil_version()) + "\n"
			"libswscale: header " + av_version(LIBSWSCALE_VERSION_INT) + ", lib " + av_version(swscale_version());
}
