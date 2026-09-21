/*
Copyright (c) 2012-2024 Maarten Baert <maarten-baert@hotmail.com>

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

#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QSettings>
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>
#include <QTimer>

#include "common/Logger.h"
#include "ssr-rc-window.h"

#include <csignal>
#include <cstdlib>

// Global pointer to QApplication for signal handler
static QApplication* g_app = nullptr;

// Signal handler for graceful shutdown
static void signalHandler(int signal)
{
    const char* signalName = "";
    switch(signal) {
        case SIGINT: signalName = "SIGINT"; break;
        case SIGTERM: signalName = "SIGTERM"; break;
        default: signalName = "UNKNOWN"; break;
    }

    // Write directly to stderr since Logger might not be safe in signal context
    fprintf(stderr, "\nReceived signal %s (%d), initiating shutdown...\n", signalName, signal);

    // Use QTimer to safely quit the application from main thread
    if(g_app) {
        // This is safe because QTimer::singleShot uses the event loop
        QTimer::singleShot(0, g_app, &QCoreApplication::quit);
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    g_app = &app;

    // Set up signal handlers for graceful shutdown
    std::signal(SIGINT, signalHandler);
    std::signal(SIGTERM, signalHandler);
    QApplication::setApplicationName("SimpleScreenRecorder Remote Control");
    QApplication::setApplicationVersion("0.1.0");
    QApplication::setOrganizationName("SimpleScreenRecorder");
    QApplication::setOrganizationDomain("maartenbaert.github.io/simplescreenrecorder");

    QCommandLineParser parser;
    parser.setApplicationDescription("SimpleScreenRecorder Remote Control allows you to control SimpleScreenRecorder using other PC or screen. It provides a simple interface to start, stop, and monitoring capabilities remotely.");
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption configOption("config", "Configuration file", "file",
        QDir::homePath() + "/.config/simplescreenrecorder/ssr-rc.conf");
    parser.addOption(configOption);

    QCommandLineOption mqttConfigOption("mqtt-config", "SSR MQTT Configuration file", "file",
        QDir::homePath() + "/.config/simplescreenrecorder/mqtt.yaml");
    parser.addOption(mqttConfigOption);

    QCommandLineOption logFileOption("log-file", "Log file", "file", "");
    parser.addOption(logFileOption);

    QCommandLineOption redirectStderrOption("redirect-stderr", "Redirect stderr to logger");
    parser.addOption(redirectStderrOption);

    QCommandLineOption minimalOption("minimal", "Start minimized to system tray");
    parser.addOption(minimalOption);

    parser.process(app);

    QString configFile = parser.value(configOption);
    QString mqttConfigFile = parser.value(mqttConfigOption);
    QString logFile = parser.value(logFileOption);

    // Create logger
    Logger logger;
    Q_UNUSED(logger);

    // Configure logger
    if(!logFile.isEmpty()) {
        logger.SetLogFile(logFile);
    }
    if(parser.isSet(redirectStderrOption)) {
        logger.RedirectStderr();
    }

    // Log startup
    Logger::LogInfo("==================== SSR Remote Control started ====================");
    Logger::LogInfo(QString("Version: %1").arg(QApplication::applicationVersion()));

    // Create config directory if it doesn't exist
    QFileInfo configInfo(configFile);
    if(!configInfo.dir().exists()) {
        configInfo.dir().mkpath(".");
        Logger::LogInfo(QString("Created config directory: %1").arg(configInfo.dir().absolutePath()));
    }

    QSettings settings(configFile, QSettings::IniFormat);

    SSRRCWindow window(&settings, mqttConfigFile);

    if(parser.isSet(minimalOption)) {
        window.showMinimized();
        Logger::LogInfo("Started minimized to system tray");
    } else {
        window.show();
        Logger::LogInfo("Started with main window visible");
    }

    // Connect to aboutToQuit signal to ensure proper cleanup
    QObject::connect(&app, &QApplication::aboutToQuit, []() {
        Logger::LogInfo("Application about to quit, performing cleanup...");
    });

    int ret = app.exec();

    // Log shutdown
    Logger::LogInfo("==================== SSR Remote Control stopped ====================");

    return ret;
}
