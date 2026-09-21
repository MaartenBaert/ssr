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

#include "ssr-rc-window.h"
#include "common/Logger.h"
#include "GUI/ssr_panel.h"
#include "MqttConfig.h"

#include <QShortcut>

#include <QCloseEvent>
#include <QMessageBox>
#include <QApplication>
#include <QIntValidator>
#include <QDir>

SSRRCWindow::SSRRCWindow(QSettings* settings, const QString& mqttConfigPath, QWidget* parent)
    : QMainWindow(parent)
    , m_settings(settings)
    , m_mqttClient(new SSRRCClient(this))
    , m_trayIcon(nullptr)
    , m_trayMenu(nullptr)
    , m_mqttConfigPath(mqttConfigPath)
{
    setupUi();
    createTrayIcon();
    loadSettings();

    // Add keyboard shortcut for quitting (Ctrl+Q)
    QShortcut *quitShortcut = new QShortcut(QKeySequence("Ctrl+Q"), this);
    connect(quitShortcut, &QShortcut::activated, qApp, &QApplication::quit);

    // Connect signals
    connect(m_mqttClient, &SSRRCClient::statusUpdated,
            this, &SSRRCWindow::onStatusUpdated);
    connect(m_mqttClient, &SSRRCClient::recordingStateChanged,
            this, &SSRRCWindow::onRecordingStateChanged);
    connect(m_mqttClient, &SSRRCClient::connectionStateChanged,
            this, &SSRRCWindow::onConnectionStateChanged);
    connect(m_mqttClient, &SSRRCClient::errorOccurred,
            this, &SSRRCWindow::onErrorOccurred);

    updateUiState();

    setWindowTitle("SSR Remote Control");
    resize(600, 400);
}

SSRRCWindow::~SSRRCWindow()
{
    Logger::LogInfo("SSRRCWindow destructor called");
    saveSettings();
}

void SSRRCWindow::setupUi()
{
    m_centralWidget = new QWidget(this);
    setCentralWidget(m_centralWidget);

    m_mainLayout = new QVBoxLayout(m_centralWidget);

    // Connection group
    m_connectionGroup = new QGroupBox("MQTT Connection", m_centralWidget);
    m_connectionLayout = new QFormLayout(m_connectionGroup);

    m_hostEdit = new QLineEdit(m_connectionGroup);
    m_hostEdit->setPlaceholderText("localhost");
    m_connectionLayout->addRow("Host:", m_hostEdit);

    m_portEdit = new QLineEdit(m_connectionGroup);
    m_portEdit->setPlaceholderText("1883");
    m_portEdit->setValidator(new QIntValidator(1, 65535, this));
    m_connectionLayout->addRow("Port:", m_portEdit);

    m_usernameEdit = new QLineEdit(m_connectionGroup);
    m_connectionLayout->addRow("Username:", m_usernameEdit);

    m_passwordEdit = new QLineEdit(m_connectionGroup);
    m_passwordEdit->setEchoMode(QLineEdit::Password);
    m_connectionLayout->addRow("Password:", m_passwordEdit);

    m_topicRootEdit = new QLineEdit(m_connectionGroup);
    m_topicRootEdit->setPlaceholderText("/ssr/");
    m_connectionLayout->addRow("Topic Root:", m_topicRootEdit);

    m_instanceIdEdit = new QLineEdit(m_connectionGroup);
    m_instanceIdEdit->setPlaceholderText("auto-generated");
    m_connectionLayout->addRow("Instance ID:", m_instanceIdEdit);

    m_autoConnectCheck = new QCheckBox("Auto-connect on startup", m_connectionGroup);
    m_connectionLayout->addRow("", m_autoConnectCheck);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    m_connectButton = new QPushButton("Connect", m_connectionGroup);
    m_disconnectButton = new QPushButton("Disconnect", m_connectionGroup);
    m_loadMQTTButton = new QPushButton("Load MQTT Settings", m_connectionGroup);
    m_disconnectButton->setEnabled(false);
    buttonLayout->addStretch();
    buttonLayout->addWidget(m_connectButton);
    buttonLayout->addWidget(m_disconnectButton);
    buttonLayout->addWidget(m_loadMQTTButton);
    buttonLayout->addStretch();
    m_connectionLayout->addRow("", buttonLayout);

    m_mainLayout->addWidget(m_connectionGroup);

    // Connect button signals
    connect(m_connectButton, &QPushButton::clicked,
            this, &SSRRCWindow::onConnectClicked);
    connect(m_disconnectButton, &QPushButton::clicked,
            this, &SSRRCWindow::onDisconnectClicked);
    connect(m_loadMQTTButton, &QPushButton::clicked,
            this, &SSRRCWindow::onLoadMQTTSettings);

    // Connect edit signals for auto-save
    connect(m_hostEdit, &QLineEdit::textChanged,
            this, &SSRRCWindow::onSettingsChanged);
    connect(m_portEdit, &QLineEdit::textChanged,
            this, &SSRRCWindow::onSettingsChanged);
    connect(m_usernameEdit, &QLineEdit::textChanged,
            this, &SSRRCWindow::onSettingsChanged);
    connect(m_passwordEdit, &QLineEdit::textChanged,
            this, &SSRRCWindow::onSettingsChanged);
    connect(m_topicRootEdit, &QLineEdit::textChanged,
            this, &SSRRCWindow::onSettingsChanged);
    connect(m_instanceIdEdit, &QLineEdit::textChanged,
            this, &SSRRCWindow::onSettingsChanged);
    connect(m_autoConnectCheck, &QCheckBox::stateChanged,
            this, &SSRRCWindow::onSettingsChanged);

    // Control group
    m_controlGroup = new QGroupBox("Recording Control", m_centralWidget);
    m_controlLayout = new QVBoxLayout(m_controlGroup);

    m_startButton = new QPushButton("Start Recording", m_controlGroup);
    m_stopButton = new QPushButton("Stop Recording", m_controlGroup);
    m_toggleButton = new QPushButton("Toggle Recording", m_controlGroup);
    m_statusButton = new QPushButton("Get Status", m_controlGroup);

    m_controlLayout->addWidget(m_startButton);
    m_controlLayout->addWidget(m_stopButton);
    m_controlLayout->addWidget(m_toggleButton);
    m_controlLayout->addWidget(m_statusButton);

    m_mainLayout->addWidget(m_controlGroup);

    // Connect control buttons
    connect(m_startButton, &QPushButton::clicked,
            this, &SSRRCWindow::onStartRecordingClicked);
    connect(m_stopButton, &QPushButton::clicked,
            this, &SSRRCWindow::onStopRecordingClicked);
    connect(m_toggleButton, &QPushButton::clicked,
            this, &SSRRCWindow::onToggleRecordingClicked);
    connect(m_statusButton, &QPushButton::clicked,
            m_mqttClient, &SSRRCClient::requestStatus);

    // Status group
    m_statusGroup = new QGroupBox("Status", m_centralWidget);
    m_statusLayout = new QFormLayout(m_statusGroup);

    m_connectionStatusLabel = new QLabel("Disconnected", m_statusGroup);
    m_recordingStatusLabel = new QLabel("Unknown", m_statusGroup);
    m_ssrStatusLabel = new QLabel("Unknown", m_statusGroup);
    m_sessionIdLabel = new QLabel("", m_statusGroup);
    m_topicLabel = new QLabel("", m_statusGroup);

    m_statusLayout->addRow("Connection:", m_connectionStatusLabel);
    m_statusLayout->addRow("Recording:", m_recordingStatusLabel);
    m_statusLayout->addRow("SSR Status:", m_ssrStatusLabel);
    m_statusLayout->addRow("Session ID:", m_sessionIdLabel);
    m_statusLayout->addRow("Topic:", m_topicLabel);

    m_mainLayout->addWidget(m_statusGroup);
    m_mainLayout->addStretch();
}

void SSRRCWindow::createTrayIcon()
{
    if(!QSystemTrayIcon::isSystemTrayAvailable()) {
        return;
    }

    m_trayIcon = new QSystemTrayIcon(this);
    m_trayMenu = new QMenu(this);

    m_trayConnectAction = new QAction("Connect", this);
    m_trayDisconnectAction = new QAction("Disconnect", this);
    m_trayStartAction = new QAction("Start Recording", this);
    m_trayStopAction = new QAction("Stop Recording", this);
    m_trayToggleAction = new QAction("Toggle Recording", this);
    m_trayShowAction = new QAction("Show Window", this);
    m_trayQuitAction = new QAction("Quit", this);

    m_trayMenu->addAction(m_trayConnectAction);
    m_trayMenu->addAction(m_trayDisconnectAction);
    m_trayMenu->addSeparator();
    m_trayMenu->addAction(m_trayStartAction);
    m_trayMenu->addAction(m_trayStopAction);
    m_trayMenu->addAction(m_trayToggleAction);
    m_trayMenu->addSeparator();
    m_trayMenu->addAction(m_trayShowAction);
    m_trayMenu->addAction(m_trayQuitAction);

    m_trayIcon->setContextMenu(m_trayMenu);
    m_trayIcon->setToolTip("SSR Remote Control");

    connect(m_trayConnectAction, &QAction::triggered,
            this, &SSRRCWindow::onConnectClicked);
    connect(m_trayDisconnectAction, &QAction::triggered,
            this, &SSRRCWindow::onDisconnectClicked);
    connect(m_trayStartAction, &QAction::triggered,
            this, &SSRRCWindow::onStartRecordingClicked);
    connect(m_trayStopAction, &QAction::triggered,
            this, &SSRRCWindow::onStopRecordingClicked);
    connect(m_trayToggleAction, &QAction::triggered,
            this, &SSRRCWindow::onToggleRecordingClicked);
    connect(m_trayShowAction, &QAction::triggered,
            this, [this]() { showNormal(); activateWindow(); });
    connect(m_trayQuitAction, &QAction::triggered,
            this, &SSRRCWindow::quitApplication);
    connect(m_trayIcon, &QSystemTrayIcon::activated,
            this, &SSRRCWindow::onTrayIconActivated);

    m_trayIcon->show();
}

void SSRRCWindow::loadSettings()
{
    m_settings->beginGroup("MQTT");
    m_hostEdit->setText(m_settings->value("host", "localhost").toString());
    m_portEdit->setText(m_settings->value("port", "1883").toString());
    m_usernameEdit->setText(m_settings->value("username").toString());
    m_passwordEdit->setText(m_settings->value("password").toString());
    m_topicRootEdit->setText(m_settings->value("topic_root", "/ssr/").toString());
    m_instanceIdEdit->setText(m_settings->value("instance_id").toString());
    m_autoConnectCheck->setChecked(m_settings->value("auto_connect", false).toBool());
    m_settings->endGroup();

    m_mqttClient->loadSettings(m_settings);

    // Window geometry
    m_settings->beginGroup("Window");
    if(m_settings->contains("geometry")) {
        restoreGeometry(m_settings->value("geometry").toByteArray());
    }
    if(m_settings->contains("state")) {
        restoreState(m_settings->value("state").toByteArray());
    }
    m_settings->endGroup();

    // Auto-connect if enabled
    if(m_autoConnectCheck->isChecked()) {
        QTimer::singleShot(300, this, &SSRRCWindow::onConnectClicked);
    }
}

void SSRRCWindow::loadSettingsFromMQTTYaml()
{
    // Использовать путь из командной строки, если передан
    QString configPath = m_mqttConfigPath;

    // Если путь не передан, использовать путь по умолчанию
    if(configPath.isEmpty()) {
        configPath = QDir::homePath() + "/.config/simplescreenrecorder/mqtt.yaml";
    }

    // Проверить существование файла
    QFileInfo configInfo(configPath);
    if(!configInfo.exists()) {
        Logger::LogWarning(QString("MQTT YAML config file not found: %1").arg(configPath));
        QMessageBox::critical(this, "Error", "MQTT YAML config file not found:'" + configPath + "'.");
        return;
    }

    // Загрузить настройки из файла
    MqttConfig mqttConfig;
    if(mqttConfig.loadConfig(configPath)) {
        MqttConfig::ConnectionConfig config = mqttConfig.getConfig();

        // Загрузить настройки в UI
        m_hostEdit->setText(config.broker_host);
        m_portEdit->setText(QString::number(config.broker_port));
        m_usernameEdit->setText(config.username);
        m_passwordEdit->setText(config.password);
        m_topicRootEdit->setText(config.topic_root);

        // Загрузить в MQTT клиент
        m_mqttClient->setBrokerHost(config.broker_host);
        m_mqttClient->setBrokerPort(config.broker_port);
        m_mqttClient->setUsername(config.username);
        m_mqttClient->setPassword(config.password);
        m_mqttClient->setTopicRoot(config.topic_root);
        m_mqttClient->setAutoConnect(config.auto_connect);
    }
}

void SSRRCWindow::saveSettings()
{
    m_settings->beginGroup("MQTT");
    m_settings->setValue("host", m_hostEdit->text());
    m_settings->setValue("port", m_portEdit->text());
    m_settings->setValue("username", m_usernameEdit->text());
    m_settings->setValue("password", m_passwordEdit->text());
    m_settings->setValue("topic_root", m_topicRootEdit->text());
    m_settings->setValue("instance_id", m_instanceIdEdit->text());
    m_settings->setValue("auto_connect", m_autoConnectCheck->isChecked());
    m_settings->endGroup();

    m_mqttClient->saveSettings(m_settings);

    // Window geometry
    m_settings->beginGroup("Window");
    m_settings->setValue("geometry", saveGeometry());
    m_settings->setValue("state", saveState());
    m_settings->endGroup();

    m_settings->sync();
}

void SSRRCWindow::updateUiState()
{
    bool connected = m_mqttClient->isConnected();

    m_connectButton->setEnabled(!connected);
    m_disconnectButton->setEnabled(connected);

    m_startButton->setEnabled(connected);
    m_stopButton->setEnabled(connected);
    m_toggleButton->setEnabled(connected);
    m_statusButton->setEnabled(connected);

    if(m_trayConnectAction) {
        m_trayConnectAction->setEnabled(!connected);
        m_trayDisconnectAction->setEnabled(connected);
        m_trayStartAction->setEnabled(connected);
        m_trayStopAction->setEnabled(connected);
        m_trayToggleAction->setEnabled(connected);
    }

    // Update status labels
    if(connected) {
        m_connectionStatusLabel->setText("Connected");
        m_connectionStatusLabel->setStyleSheet("color: green;");
    } else {
        m_connectionStatusLabel->setText("Disconnected");
        m_connectionStatusLabel->setStyleSheet("color: red;");
    }
}

void SSRRCWindow::closeEvent(QCloseEvent* event)
{
    Logger::LogInfo("Close event received");

    if(m_trayIcon && m_trayIcon->isVisible()) {
        // If tray icon is visible, ask user what to do
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("SSR Remote Control");
        msgBox.setText("What would you like to do?");
        msgBox.setIcon(QMessageBox::Question);

        QPushButton *minimizeButton = msgBox.addButton("Minimize to Tray", QMessageBox::YesRole);
        QPushButton *quitButton = msgBox.addButton("Exit Application", QMessageBox::NoRole);
        QPushButton *cancelButton = msgBox.addButton("Cancel", QMessageBox::RejectRole);

        msgBox.setDefaultButton(minimizeButton);
        msgBox.exec();

        QAbstractButton *clickedButton = msgBox.clickedButton();

        if(clickedButton == minimizeButton) {
            // Minimize to tray
            Logger::LogInfo("Minimizing to system tray");
            hide();
            event->ignore();
        } else if(clickedButton == quitButton) {
            // Quit application
            Logger::LogInfo("Quitting application");
            event->accept();
            qApp->quit();
        } else {
            // Cancel - keep window open
            Logger::LogInfo("Close cancelled by user");
            event->ignore();
        }
    } else {
        // No tray icon, just quit
        Logger::LogInfo("Quitting application (no tray icon)");
        event->accept();
    }
}

void SSRRCWindow::onConnectClicked()
{
    // Update client settings from UI
    m_mqttClient->setBrokerHost(m_hostEdit->text());
    m_mqttClient->setBrokerPort(m_portEdit->text().toInt());
    m_mqttClient->setUsername(m_usernameEdit->text());
    m_mqttClient->setPassword(m_passwordEdit->text());
    m_mqttClient->setTopicRoot(m_topicRootEdit->text());
    m_mqttClient->setInstanceId(m_instanceIdEdit->text());
    m_mqttClient->setAutoConnect(m_autoConnectCheck->isChecked());

    Logger::LogInfo(QString("Connecting to MQTT broker: %1:%2").arg(m_hostEdit->text()).arg(m_portEdit->text()));
    m_mqttClient->connectToBroker();
    m_mqttClient->clientConnected();
}

void SSRRCWindow::onDisconnectClicked()
{
    m_mqttClient->clientDisconnected();
    QTimer::singleShot(300, this, &SSRRCWindow::onDisconnectTimer);
    Logger::LogInfo("Disconnecting from MQTT broker");
}

void SSRRCWindow::onDisconnectTimer()
{
    Logger::LogInfo("Client disconnected");
    m_mqttClient->disconnectFromBroker();
    updateUiState();
}

void SSRRCWindow::onStartRecordingClicked()
{
    Logger::LogInfo("Sending start recording command");
    m_mqttClient->startRecording();
}

void SSRRCWindow::onStopRecordingClicked()
{
    Logger::LogInfo("Sending stop recording command");
    m_mqttClient->stopRecording();
}

void SSRRCWindow::onToggleRecordingClicked()
{
    Logger::LogInfo("Sending toggle recording command");
    m_mqttClient->toggleRecording();
}

void SSRRCWindow::onStatusUpdated(const QString& status, const QString& sessionId, const QString& topic)
{
    Logger::LogInfo(QString("Status updated: status=%1, sessionId=%2, topic=%3").arg(status).arg(sessionId).arg(topic));
    m_ssrStatusLabel->setText(status);
    m_sessionIdLabel->setText(sessionId);
    m_topicLabel->setText(topic);

    // Update status color
    if(status == "idle") {
        m_ssrStatusLabel->setStyleSheet("color: blue;");
    } else if(status == "recording") {
        m_ssrStatusLabel->setStyleSheet("color: green;");
    } else if(status == "paused") {
        m_ssrStatusLabel->setStyleSheet("color: orange;");
    } else if(status == "error") {
        m_ssrStatusLabel->setStyleSheet("color: red;");
    } else {
        m_ssrStatusLabel->setStyleSheet("color: black;");
    }
}

void SSRRCWindow::onRecordingStateChanged(bool recording)
{
    Logger::LogInfo(QString("Recording state changed: %1").arg(recording ? "Recording" : "Stopped"));
    if(recording) {
        m_recordingStatusLabel->setText("Recording");
        m_recordingStatusLabel->setStyleSheet("color: green;");
    } else {
        m_recordingStatusLabel->setText("Stopped");
        m_recordingStatusLabel->setStyleSheet("color: red;");
    }
}

void SSRRCWindow::onConnectionStateChanged(bool connected)
{
    Logger::LogInfo(QString("Connection state changed: %1").arg(connected ? "Connected" : "Disconnected"));
    updateUiState();

    if(connected) {
        if(m_trayIcon) {
            m_trayIcon->showMessage("SSR Remote Control",
                                   "Connected to MQTT broker",
                                   QSystemTrayIcon::Information, 3000);
        }
    }
}

void SSRRCWindow::onErrorOccurred(const QString& error)
{
    Logger::LogError(QString("Error occurred: %1").arg(error));
    QMessageBox::warning(this, "SSR Remote Control Error", error);

    if(m_trayIcon) {
        m_trayIcon->showMessage("SSR Remote Control Error",
                               error,
                               QSystemTrayIcon::Warning, 5000);
    }
}

void SSRRCWindow::onTrayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::DoubleClick) {
        if(isHidden()) {
            showNormal();
            activateWindow();
        } else if(isMinimized()) {
            showNormal();
            activateWindow();
        } else {
            hide();
        }
    }
}

void SSRRCWindow::quitApplication()
{
    Logger::LogInfo("Quit requested from tray menu");
    // Save settings before quitting
    saveSettings();
    qApp->quit();
}

void SSRRCWindow::onSettingsChanged()
{
    saveSettings();
}

void SSRRCWindow::onLoadMQTTSettings()
{
    loadSettingsFromMQTTYaml();
}
