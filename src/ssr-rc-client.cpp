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

#include "ssr-rc-client.h"
#include "common/Logger.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDateTime>
#include <QUuid>
#include <QEventLoop>
#include <QTimer>

SSRRCClient::SSRRCClient(QObject* parent)
    : QObject(parent)
    , m_client(new QMqttClient(this))
    , m_reconnectTimer(new QTimer(this))
    , m_connected(false)
    , m_brokerHost("localhost")
    , m_brokerPort(1883)
    , m_topicRoot("/ssr/")
    , m_autoConnect(false)
    , m_subStatus(nullptr)
    , m_subRecordingState(nullptr)
    , m_subRecordingEvent(nullptr)
    , m_subLedState(nullptr)
    , m_subError(nullptr)
    , m_lastRecordingState(false)
{
    // Connect client signals
    connect(m_client, &QMqttClient::connected, this, &SSRRCClient::onConnected);
    connect(m_client, &QMqttClient::disconnected, this, &SSRRCClient::onDisconnected);
    connect(m_client, &QMqttClient::errorChanged, this, &SSRRCClient::onErrorChanged);
    connect(m_client, &QMqttClient::stateChanged, this, &SSRRCClient::onStateChanged);
    connect(m_client, &QMqttClient::messageReceived, this, &SSRRCClient::onMessageReceived);

    // Setup reconnect timer
    m_reconnectTimer->setInterval(5000);
    m_reconnectTimer->setSingleShot(true);
    connect(m_reconnectTimer, &QTimer::timeout, this, &SSRRCClient::onReconnectTimer);

    // Generate instance ID if not set
    if(m_instanceId.isEmpty()) {
        m_instanceId = QUuid::createUuid().toString(QUuid::WithoutBraces).left(8);
    }
}

SSRRCClient::~SSRRCClient()
{
    Logger::LogInfo("SSRRCClient destructor called, disconnecting from broker...");
    disconnectFromBroker();
}

void SSRRCClient::checkTopicRoot()
{
    if(m_topicRoot.isEmpty() || m_topicRoot.at(m_topicRoot.length() - 1) != '/') {
        m_topicRoot += '/';
    }
    // check if topic root ends with a slash
    if (!m_topicRoot.endsWith('/')) {
        m_topicRoot += '/';
    }
    // check if topic contains redundant slashes
    if (m_topicRoot.contains("//")) {
        m_topicRoot = m_topicRoot.replace("//", "/");
    }
}

void SSRRCClient::loadSettings(QSettings* settings)
{
    settings->beginGroup("MQTT");
    m_brokerHost = settings->value("host", "localhost").toString();
    m_brokerPort = settings->value("port", 1883).toInt();
    m_username = settings->value("username").toString();
    m_password = settings->value("password").toString();
    m_topicRoot = settings->value("topic_root", "/ssr/").toString();
    checkTopicRoot();
    m_instanceId = settings->value("instance_id", m_instanceId).toString();
    m_autoConnect = settings->value("auto_connect", false).toBool();
    settings->endGroup();

    // Generate instance ID if still empty
    if(m_instanceId.isEmpty()) {
        m_instanceId = QUuid::createUuid().toString(QUuid::WithoutBraces).left(8);
    }
}

void SSRRCClient::saveSettings(QSettings* settings)
{
    settings->beginGroup("MQTT");
    settings->setValue("host", m_brokerHost);
    settings->setValue("port", m_brokerPort);
    settings->setValue("username", m_username);
    settings->setValue("password", m_password);
    checkTopicRoot();
    settings->setValue("topic_root", m_topicRoot);
    settings->setValue("instance_id", m_instanceId);
    settings->setValue("auto_connect", m_autoConnect);
    settings->endGroup();
}

void SSRRCClient::connectToBroker()
{
    if(m_connected) {
        return;
    }

    checkTopicRoot();

    m_client->setHostname(m_brokerHost);
    m_client->setPort(m_brokerPort);
    m_client->setClientId("ssr-rc-" + m_instanceId);

    if(!m_username.isEmpty()) {
        m_client->setUsername(m_username);
        if(!m_password.isEmpty()) {
            m_client->setPassword(m_password);
        }
    }

    Logger::LogInfo(QString("Connecting to MQTT broker at %1:%2...").arg(m_brokerHost).arg(m_brokerPort));
    m_client->connectToHost();
}

void SSRRCClient::disconnectFromBroker()
{
    m_reconnectTimer->stop();

    if(m_client->state() != QMqttClient::Disconnected) {
        Logger::LogInfo("Disconnecting from MQTT broker...");
        m_client->disconnectFromHost();

        // Wait for disconnection with timeout
        QEventLoop loop;
        QTimer timeoutTimer;
        timeoutTimer.setSingleShot(true);

        auto connection = QObject::connect(m_client, &QMqttClient::stateChanged,
            [&loop](QMqttClient::ClientState state) {
                if(state == QMqttClient::Disconnected) {
                    loop.quit();
                }
            });

        QObject::connect(&timeoutTimer, &QTimer::timeout, &loop, &QEventLoop::quit);

        timeoutTimer.start(5000); // 5 second timeout
        loop.exec();

        QObject::disconnect(connection);

        if(timeoutTimer.isActive()) {
            Logger::LogInfo("Successfully disconnected from MQTT broker");
        } else {
            Logger::LogWarning("Timeout waiting for MQTT disconnection");
        }
    } else {
        Logger::LogInfo("MQTT client already disconnected");
    }
}

bool SSRRCClient::isConnected() const
{
    return m_connected;
}

void SSRRCClient::startRecording()
{
    // Publish to centralized control topic (matching what MqttClient::SubscribeToTopicsByRecorder() expects)
    QJsonObject json;
    json["session"] = m_instanceId.isEmpty() ? "main" : m_instanceId;
    QJsonDocument doc(json);
    publishCommand("control/recording/start", doc.toJson());
}

void SSRRCClient::stopRecording()
{
    // Publish to centralized control topic (matching what MqttClient::SubscribeToTopicsByRecorder() expects)
    QJsonObject json;
    json["session"] = m_instanceId.isEmpty() ? "main" : m_instanceId;
    QJsonDocument doc(json);
    publishCommand("control/recording/stop", doc.toJson());
}

void SSRRCClient::toggleRecording()
{
    // Publish to centralized control topic (matching what MqttClient::SubscribeToTopicsByRecorder() expects)
    QJsonObject json;
    json["session"] = m_instanceId.isEmpty() ? "main" : m_instanceId;
    QJsonDocument doc(json);
    publishCommand("control/recording/toggle", doc.toJson());
}

void SSRRCClient::requestStatus()
{
    QJsonObject json;
    json["session"] = m_instanceId.isEmpty() ? "main" : m_instanceId;
    QJsonDocument doc(json);
    publishCommand("control/client/status/request", doc.toJson());
}

void SSRRCClient::changeTopic(const QString& topic)
{
    QJsonObject json;
    json["session"] = m_instanceId.isEmpty() ? "main" : m_instanceId;
    json["topic"] = topic;
    QJsonDocument doc(json);
    publishCommand("control/topic/change", doc.toJson());
}

void SSRRCClient::pressButtonRecording()
{
    QJsonObject json;
    json["session"] = m_instanceId.isEmpty() ? "main" : m_instanceId;
    json["action"] = "press";
    QJsonDocument doc(json);
    publishCommand("device/button/recording", doc.toJson());
}

void SSRRCClient::releaseButtonRecording()
{
    QJsonObject json;
    json["session"] = m_instanceId.isEmpty() ? "main" : m_instanceId;
    json["action"] = "release";
    QJsonDocument doc(json);
    publishCommand("device/button/recording", doc.toJson());
}

void SSRRCClient::pressButtonOnAir()
{
    QJsonObject json;
    json["session"] = m_instanceId.isEmpty() ? "main" : m_instanceId;
    json["action"] = "press";
    QJsonDocument doc(json);
    publishCommand("device/button/onair", doc.toJson());
}

void SSRRCClient::releaseButtonOnAir()
{
    QJsonObject json;
    json["session"] = m_instanceId.isEmpty() ? "main" : m_instanceId;
    json["action"] = "release";
    QJsonDocument doc(json);
    publishCommand("device/button/onair", doc.toJson());
}

void SSRRCClient::onConnected()
{
    m_connected = true;
    m_reconnectTimer->stop();

    setupSubscriptions();

    // Request initial status
    requestStatus();

    Logger::LogInfo(QString("Connected to MQTT broker at %1:%2").arg(m_brokerHost).arg(m_brokerPort));
    emit connectionStateChanged(true);
}

void SSRRCClient::onDisconnected()
{
    m_connected = false;

    // Clear subscriptions
    m_subStatus = nullptr;
    m_subRecordingState = nullptr;
    m_subRecordingEvent = nullptr;
    m_subLedState = nullptr;
    m_subError = nullptr;

    Logger::LogInfo("Disconnected from MQTT broker");

    // Try to reconnect if auto-connect is enabled
    if(m_autoConnect) {
        m_reconnectTimer->start();
    }

    emit connectionStateChanged(false);
}

void SSRRCClient::onErrorChanged(QMqttClient::ClientError error)
{
    if(error != QMqttClient::NoError) {
        QString errorStr;
        switch(error) {
            case QMqttClient::InvalidProtocolVersion: errorStr = "Invalid protocol version"; break;
            case QMqttClient::IdRejected: errorStr = "Client ID rejected"; break;
            case QMqttClient::ServerUnavailable: errorStr = "Server unavailable"; break;
            case QMqttClient::BadUsernameOrPassword: errorStr = "Bad username or password"; break;
            case QMqttClient::NotAuthorized: errorStr = "Not authorized"; break;
            case QMqttClient::TransportInvalid: errorStr = "Transport invalid"; break;
            case QMqttClient::ProtocolViolation: errorStr = "Protocol violation"; break;
            case QMqttClient::UnknownError: errorStr = "Unknown error"; break;
            case QMqttClient::NoError: errorStr = "No error"; break;
            case QMqttClient::Mqtt5SpecificError: errorStr = "MQTT 5.0 specific error"; break;
            default: errorStr = QString("Unknown error code: %1").arg((int)error); break;
        }

        Logger::LogError(QString("MQTT client error: %1").arg(errorStr));
        emit errorOccurred(errorStr);
    }
}

void SSRRCClient::onStateChanged(QMqttClient::ClientState state)
{
    // Можно добавить логирование состояния, если нужно
    Q_UNUSED(state);
}

void SSRRCClient::onMessageReceived(const QByteArray& message, const QMqttTopicName& topic)
{
    QString topicStr = topic.name();
    QString msgStr = QString::fromUtf8(message);

    // Parse JSON if possible
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(message, &parseError);

    // Check which topic the message is from
    if(topicStr.endsWith("/status")) {
        if(parseError.error == QJsonParseError::NoError && doc.isObject()) {
            QJsonObject obj = doc.object();
            m_lastStatus = obj.value("status").toString();
            m_lastSessionId = obj.value("session_id").toString();
            m_lastTopic = obj.value("topic").toString();

            emit statusUpdated(m_lastStatus, m_lastSessionId, m_lastTopic);
        } else {
            // Fallback to plain text
            m_lastStatus = msgStr;
            emit statusUpdated(m_lastStatus, QString(), QString());
        }
    }
    else if(topicStr.endsWith("/recording/state")) {
        bool recording = (msgStr.toLower() == "true" || msgStr == "1" || msgStr.toLower() == "recording");
        if(m_lastRecordingState != recording) {
            m_lastRecordingState = recording;
            emit recordingStateChanged(recording);
        }
    }
    else if(topicStr.endsWith("/recording/event")) {
        // Можно обрабатывать события записи (start, stop, pause, resume)
        // Пока просто логируем
        Logger::LogInfo(QString("Recording event: %1").arg(msgStr));
    }
    else if(topicStr.endsWith("/led/state")) {
        // Обработка состояния LED (если нужно)
        // Формат: "led_name:state" например "recording:on"
        QStringList parts = msgStr.split(':');
        if(parts.size() >= 2) {
            QString led = parts[0].trimmed();
            bool state = (parts[1].trimmed().toLower() == "on" || parts[1].trimmed() == "1");
            // Можно эмитировать сигнал для обновления UI
        }
    }
    else if(topicStr.endsWith("/error")) {
        emit errorOccurred(msgStr);
    }
}

void SSRRCClient::onReconnectTimer()
{
    if(m_autoConnect && !m_connected) {
        Logger::LogInfo("Attempting to reconnect to MQTT broker...");
        connectToBroker();
    }
}

void SSRRCClient::setupSubscriptions()
{
    // Subscribe to centralized status topics (matching MqttClient::SubscribeToTopicsByClient())
    m_subStatus = m_client->subscribe(getFullTopic("status"), 1);
    if(m_subStatus) {
        connect(m_subStatus, &QMqttSubscription::messageReceived,
                this, [this](const QMqttMessage& msg) {
                    onMessageReceived(msg.payload(), msg.topic());
                });
    }

    // Also subscribe to status/response topic for compatibility
    QMqttSubscription* subStatusResponse = m_client->subscribe(getFullTopic("status/response"), 1);
    if(subStatusResponse) {
        connect(subStatusResponse, &QMqttSubscription::messageReceived,
                this, [this](const QMqttMessage& msg) {
                    onMessageReceived(msg.payload(), msg.topic());
                });
    }

    m_subRecordingState = m_client->subscribe(getFullTopic("status/recording/started"), 1);
    if(m_subRecordingState) {
        connect(m_subRecordingState, &QMqttSubscription::messageReceived,
                this, [this](const QMqttMessage& msg) {
                    onMessageReceived(msg.payload(), msg.topic());
                });
    }

    m_subRecordingEvent = m_client->subscribe(getFullTopic("status/recording/stopped"), 1);
    if(m_subRecordingEvent) {
        connect(m_subRecordingEvent, &QMqttSubscription::messageReceived,
                this, [this](const QMqttMessage& msg) {
                    onMessageReceived(msg.payload(), msg.topic());
                });
    }

    // Additional status topics from centralized architecture
    QMqttSubscription* subRecordingPaused = m_client->subscribe(getFullTopic("status/recording/paused"), 1);
    if(subRecordingPaused) {
        connect(subRecordingPaused, &QMqttSubscription::messageReceived,
                this, [this](const QMqttMessage& msg) {
                    onMessageReceived(msg.payload(), msg.topic());
                });
    }

    QMqttSubscription* subSessionStarted = m_client->subscribe(getFullTopic("status/session/started"), 1);
    if(subSessionStarted) {
        connect(subSessionStarted, &QMqttSubscription::messageReceived,
                this, [this](const QMqttMessage& msg) {
                    onMessageReceived(msg.payload(), msg.topic());
                });
    }

    QMqttSubscription* subSessionFinished = m_client->subscribe(getFullTopic("status/session/finished"), 1);
    if(subSessionFinished) {
        connect(subSessionFinished, &QMqttSubscription::messageReceived,
                this, [this](const QMqttMessage& msg) {
                    onMessageReceived(msg.payload(), msg.topic());
                });
    }

    m_subError = m_client->subscribe(getFullTopic("events/error"), 1);
    if(m_subError) {
        connect(m_subError, &QMqttSubscription::messageReceived,
                this, [this](const QMqttMessage& msg) {
                    onMessageReceived(msg.payload(), msg.topic());
                });
    }
}

void SSRRCClient::publishCommand(const QString& command, const QString& payload)
{
    if(!m_connected) {
        Logger::LogError("Not connected to MQTT broker");
        emit errorOccurred("Not connected to MQTT broker");
        return;
    }

    QMqttTopicName topic = getFullTopic(command);
    QString topicStr = topic.name();
    if(m_client->publish(topic, payload.toUtf8(), 1, false) == -1) {
        Logger::LogError(QString("Failed to publish command: %1").arg(topicStr));
        emit errorOccurred(QString("Failed to publish command: %1").arg(topicStr));
    } else {
        Logger::LogInfo(QString("Published command: %1, payload: %2").arg(topicStr).arg(payload.isEmpty() ? "[empty]" : payload));
    }
}

QString SSRRCClient::getFullTopic(const QString& path)
{
    QString topic;

    topic = m_topicRoot;
    checkTopicRoot();
    topic += path;

    // Убедимся, что топик начинается с /
    if(!topic.startsWith('/')) {
        topic = '/' + topic;
    }

    return topic;
}

void SSRRCClient::clientDisconnected()
{
    // Publish to centralized control topic (matching what MqttClient::SubscribeToTopicsByRecorder() expects)
    QJsonObject json;
    json["session"] = m_instanceId.isEmpty() ? "main" : m_instanceId;
    json["status"] = "disconnected";
    QJsonDocument doc(json);
    publishCommand("control/client/disconnected", doc.toJson());
    Logger::LogInfo("Client disconnected");
    emit connectionStateChanged(false);
}

void SSRRCClient::clientConnected()
{
    // Publish to centralized control topic (matching what MqttClient::SubscribeToTopicsByRecorder() expects)
    QJsonObject json;
    json["session"] = m_instanceId.isEmpty() ? "main" : m_instanceId;
    json["status"] = "connected";
    QJsonDocument doc(json);
    publishCommand("control/client/connected", doc.toJson());
    Logger::LogInfo("Client connected");
    emit connectionStateChanged(true);
}
