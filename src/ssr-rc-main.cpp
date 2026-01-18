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

#include "ssr-rc-window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
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

    QCommandLineOption minimalOption("minimal", "Start minimized to system tray");
    parser.addOption(minimalOption);

    parser.process(app);

    QString configFile = parser.value(configOption);
    QString mqttConfigFile = parser.value(mqttConfigOption);

    // Create config directory if it doesn't exist
    QFileInfo configInfo(configFile);
    if(!configInfo.dir().exists()) {
        configInfo.dir().mkpath(".");
    }

    QSettings settings(configFile, QSettings::IniFormat);

    SSRRCWindow window(&settings);

    if(parser.isSet(minimalOption)) {
        window.showMinimized();
    } else {
        window.show();
    }

    return app.exec();
}
