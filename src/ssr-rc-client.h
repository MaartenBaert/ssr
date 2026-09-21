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

#include <QObject>
#include <QString>
#include <QTimer>
#include <QSettings>

// Workaround for QtMqtt header bugs
#define QT_MQTT_STATIC

// Undefine X11 macros that conflict with QtMqtt
#ifdef Success
#undef Success
#endif
#ifdef None
#undef None
#endif

#include <QtMqtt/QMqttClient>
#include <QtMqtt/QMqttSubscription>
#include <QtMqtt/QMqttMessage>

class SSRRCClient : public QObject
{
    Q_OBJECT

public:
    SSRRCClient(QObject* parent = nullptr);
    ~SSRRCClient();

    void loadSettings(QSettings* settings);
    void saveSettings(QSettings* settings);

    void connectToBroker();
    void disconnectFromBroker();
    bool isConnected() const;

    // Control commands
    void startRecording();
    void stopRecording();
    void toggleRecording();
    void requestStatus();
    void changeTopic(const QString& topic);
    void pressButtonRecording();
    void releaseButtonRecording();
    void pressButtonOnAir();
    void releaseButtonOnAir();
    void clientConnected();
    void clientDisconnected();

    // Getters
    QString getBrokerHost() const { return m_brokerHost; }
    int getBrokerPort() const { return m_brokerPort; }
    QString getTopicRoot() const { return m_topicRoot; }
    QString getInstanceId() const { return m_instanceId; }
    bool getAutoConnect() const { return m_autoConnect; }

    // Setters
    void setBrokerHost(const QString& host) { m_brokerHost = host; }
    void setBrokerPort(int port) { m_brokerPort = port; }
    void setUsername(const QString& username) { m_username = username; }
    void setPassword(const QString& password) { m_password = password; }
    void setTopicRoot(const QString& topicRoot) { m_topicRoot = topicRoot; }
    void setInstanceId(const QString& instanceId) { m_instanceId = instanceId; }
    void setAutoConnect(bool autoConnect) { m_autoConnect = autoConnect; }

signals:
    void statusUpdated(const QString& status, const QString& sessionId, const QString& topic);
    void recordingStateChanged(bool recording);
    void connectionStateChanged(bool connected);
    void errorOccurred(const QString& error);

private slots:
    void onConnected();
    void onDisconnected();
    void onErrorChanged(QMqttClient::ClientError error);
    void onStateChanged(QMqttClient::ClientState state);
    void onMessageReceived(const QByteArray& message, const QMqttTopicName& topic);
    void onReconnectTimer();

private:
    void setupSubscriptions();
    void publishCommand(const QString& command, const QString& payload = QString());
    QString getFullTopic(const QString& path);

private:
    QMqttClient* m_client;
    QTimer* m_reconnectTimer;
    bool m_connected;

    // Configuration
    QString m_brokerHost;
    int m_brokerPort;
    QString m_username;
    QString m_password;
    QString m_topicRoot;
    QString m_instanceId;
    bool m_autoConnect;

    // Subscriptions
    QMqttSubscription* m_subStatus;
    QMqttSubscription* m_subRecordingState;
    QMqttSubscription* m_subRecordingEvent;
    QMqttSubscription* m_subLedState;
    QMqttSubscription* m_subError;

    // Last received values
    QString m_lastStatus;
    QString m_lastSessionId;
    QString m_lastTopic;
    bool m_lastRecordingState;

    void checkTopicRoot();
};
