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

#include "CommandLineOptions.h"

#include "Logger.h"

CommandLineOptions *CommandLineOptions::s_instance = NULL;

void PrintOptionHelp() {
	Logger::LogInfo(
		"Usage: simplescreenrecorder [OPTIONS]\n"
		"\n"
		"Options:\n"
		"  --help                Show this help message.\n"
		"  --version             Show version information.\n"
		"  --settingsfile=FILE   Load and save program settings to FILE. If omitted,\n"
		"                        ~/.ssr/settings.conf is used.\n"
		"  --logfile[=FILE]      Write log messages to FILE. If FILE is omitted,\n"
		"                        ~/.ssr/log-DATE_TIME.txt is used.\n"
		"  --statsfile[=FILE]    Write recording statistics to FILE. If FILE is omitted,\n"
		"                        /dev/shm/simplescreenrecorder-stats-PID is used. It will\n"
		"                        be updated continuously and deleted when the recording\n"
		"                        page is closed.\n"
		"  --no-redirect-stderr  Don't redirect stderr to the log.\n"
		"  --no-systray          Don't show the system tray icon.\n"
		"  --start-hidden        Start the application in hidden form.\n"
		"  --start-recording     Start the recording immediately.\n"
		"  --activate-schedule   Activate the recording schedule immediately.\n"
		"  --syncdiagram         Show synchronization diagram (for debugging).\n"
		"  --benchmark           Run the internal benchmark.\n"
		"\n"
		"Commands accepted through stdin:\n"
		"  record-start          Start the recording.\n"
		"  record-pause          Pause the recording.\n"
		"  record-cancel         Cancel the recording and delete the output file.\n"
		"  record-save           Finish the recording and save the output file.\n"
		"  schedule-activate     Activate the recording schedule.\n"
		"  schedule-deactivate   Deactivate the recording schedule.\n"
		"  window-show           Show the application window.\n"
		"  window-hide           Hide the application window.\n"
		"  quit                  Quit the application.\n"
	);
}

QString DefaultSettingsFile() {
	return GetApplicationUserDir() + "/settings.conf";
}

QString DefaultLogFile() {

	// delete old log files
	QDateTime now = QDateTime::currentDateTime();
	QDir dir(GetApplicationUserDir("logs"));
	dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
	dir.setNameFilters(QStringList("log-*.txt"));
	for(QFileInfo fileinfo : dir.entryInfoList()) {
		if(fileinfo.lastModified().daysTo(now) > 30) {
			QFile(fileinfo.filePath()).remove();
		}
	}

	// create new log file
	return dir.path() + "/log-" + now.toString("yyyy-MM-dd_hh.mm.ss") + ".txt";

}

QString DefaultStatsFile() {
	return "/dev/shm/simplescreenrecorder-stats-" + QString::number(QCoreApplication::applicationPid());
}

void CheckOptionHasValue(const QString &option, const QString &value) {
	if(value.isNull()) {
		Logger::LogError("[CommandLineOptions::Parse] " + Logger::tr("Error: Command-line option '%1' requires a value!").arg(option));
		PrintOptionHelp();
		throw CommandLineException();
	}
}

void CheckOptionHasNoValue(const QString &option, const QString &value) {
	if(!value.isNull()) {
		Logger::LogError("[CommandLineOptions::Parse] " + Logger::tr("Error: Command-line option '%1' does not take a value!").arg(option));
		PrintOptionHelp();
		throw CommandLineException();
	}
}

CommandLineOptions::CommandLineOptions() {
	assert(s_instance == NULL);

	// default values
	m_settings_file = DefaultSettingsFile();
	m_log_file = QString();
	m_stats_file = QString();
	m_redirect_stderr = true;
	m_systray = true;
	m_start_hidden = false;
	m_start_recording = false;
	m_activate_schedule = false;
	m_sync_diagram = false;
	m_benchmark = false;
	m_gui = true;

	s_instance = this;
}

CommandLineOptions::~CommandLineOptions() {
	assert(s_instance == this);
	s_instance = NULL;
}

void CommandLineOptions::Parse() {

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

			// handle options
			if(option == "--help") {
				CheckOptionHasNoValue(option, value);
				PrintOptionHelp();
				m_gui = false;
			} else if(option == "--version") {
				CheckOptionHasNoValue(option, value);
				Logger::LogInfo(GetVersionInfo());
				m_gui = false;
			} else if(option == "--settingsfile") {
				CheckOptionHasValue(option, value);
				m_settings_file = value;
			} else if(option == "--logfile") {
				if(value.isNull()) {
					m_log_file = DefaultLogFile();
				} else {
					m_log_file = value;
				}
			} else if(option == "--statsfile") {
				if(value.isNull()) {
					m_stats_file = DefaultStatsFile();
				} else {
					m_stats_file = value;
				}
			} else if(option == "--no-redirect-stderr") {
				CheckOptionHasNoValue(option, value);
				m_redirect_stderr = false;
			} else if(option == "--no-systray") {
				CheckOptionHasNoValue(option, value);
				m_systray = false;
			} else if(option == "--start-hidden") {
				CheckOptionHasNoValue(option, value);
				m_start_hidden = true;
			} else if(option == "--start-recording") {
				CheckOptionHasNoValue(option, value);
				m_start_recording = true;
			} else if(option == "--activate-schedule") {
				CheckOptionHasNoValue(option, value);
				m_activate_schedule = true;
			} else if(option == "--syncdiagram") {
				CheckOptionHasNoValue(option, value);
				m_sync_diagram = true;
			} else if(option == "--benchmark") {
				CheckOptionHasNoValue(option, value);
				m_benchmark = true;
				m_gui = false;
			} else {
				Logger::LogError("[CommandLineOptions::Parse] " + Logger::tr("Error: Unknown command-line option '%1'!").arg(option));
				PrintOptionHelp();
				throw CommandLineException();
			}

		} else {

			// handle other arguments
			Logger::LogError("[CommandLineOptions::Parse] " + Logger::tr("Error: Unknown command-line argument '%1'!").arg(arg));
			PrintOptionHelp();
			throw CommandLineException();

		}
	}

}

// see definition of AV_VERSION_INT() in libavutil/version.h
inline QString av_version(unsigned int ver) {
	return QString::number((ver >> 16) & 0xff) + "." + QString::number((ver >> 8) & 0xff) + "." + QString::number(ver & 0xff);
}

QString GetVersionInfo() {
	return QString() +
			"SimpleScreenRecorder " + SSR_VERSION + "\n"
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

QString GetApplicationSystemDir(const QString& subdir) {
	QString dir = SSR_SYSTEM_DIR;
	if(!subdir.isEmpty())
		dir += "/" + subdir;
	return dir;
}

QString GetApplicationUserDir(const QString& subdir) {
	QString dir = QDir::homePath() + "/.ssr";
	if(!QDir(dir).exists()) {
		QString xdg_config_home = getenv("XDG_CONFIG_HOME");
		if(xdg_config_home.isEmpty())
			xdg_config_home = QDir::homePath() + "/.config";

		QString dir2 = xdg_config_home + "/simplescreenrecorder";
		if(QDir(dir2).exists())
			dir = dir2;
	}
	if(!subdir.isEmpty())
		dir += "/" + subdir;
	if(!QDir::root().mkpath(dir)) {
		Logger::LogError("[GetApplicationUserDir] " + Logger::tr("Error: Can't create configuration directory!"));
		throw 0;
	}
	return dir;
}
