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

#pragma once

#include <QMainWindow>
#include <QSettings>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>

#include "ssr-rc-client.h"

class SSRRCWindow : public QMainWindow
{
    Q_OBJECT

public:
    SSRRCWindow(QSettings* settings, const QString& mqttConfigPath = QString(), QWidget* parent = nullptr);
    ~SSRRCWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void onConnectClicked();
    void onDisconnectClicked();
    void onStartRecordingClicked();
    void onStopRecordingClicked();
    void onToggleRecordingClicked();
    void onStatusUpdated(const QString& status, const QString& sessionId, const QString& topic);
    void onRecordingStateChanged(bool recording);
    void onConnectionStateChanged(bool connected);
    void onErrorOccurred(const QString& error);
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void onSettingsChanged();
    void onLoadMQTTSettings();
    void quitApplication();
    void onDisconnectTimer();

private:
    void setupUi();
    void createTrayIcon();
    void loadSettings();
    void saveSettings();
    void updateUiState();
    void loadSettingsFromMQTTYaml();

private:
    QSettings* m_settings;
    SSRRCClient* m_mqttClient;
    QSystemTrayIcon* m_trayIcon;
    QMenu* m_trayMenu;
    QString m_mqttConfigPath;

    // UI elements
    QWidget* m_centralWidget;
    QVBoxLayout* m_mainLayout;

    // Connection group
    QGroupBox* m_connectionGroup;
    QFormLayout* m_connectionLayout;
    QLineEdit* m_hostEdit;
    QLineEdit* m_portEdit;
    QLineEdit* m_usernameEdit;
    QLineEdit* m_passwordEdit;
    QLineEdit* m_topicRootEdit;
    QLineEdit* m_instanceIdEdit;
    QCheckBox* m_autoConnectCheck;
    QPushButton* m_connectButton;
    QPushButton* m_disconnectButton;
    QPushButton* m_loadMQTTButton;

    // Control group
    QGroupBox* m_controlGroup;
    QVBoxLayout* m_controlLayout;
    QPushButton* m_startButton;
    QPushButton* m_stopButton;
    QPushButton* m_toggleButton;
    QPushButton* m_statusButton;

    // Status group
    QGroupBox* m_statusGroup;
    QFormLayout* m_statusLayout;
    QLabel* m_connectionStatusLabel;
    QLabel* m_recordingStatusLabel;
    QLabel* m_ssrStatusLabel;
    QLabel* m_sessionIdLabel;
    QLabel* m_topicLabel;

    // Tray actions
    QAction* m_trayConnectAction;
    QAction* m_trayDisconnectAction;
    QAction* m_trayStartAction;
    QAction* m_trayStopAction;
    QAction* m_trayToggleAction;
    QAction* m_trayShowAction;
    QAction* m_trayQuitAction;
};
