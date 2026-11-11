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

#include "MqttClientInterface.h"

// Workaround for QtMqtt header bugs in some Qt versions
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

class PageRecord;

class MqttClient : public QObject, public MqttClientInterface {
	Q_OBJECT

private:
	static constexpr int RECONNECT_INTERVAL_MS = 5000;
	static constexpr int KEEPALIVE_INTERVAL_MS = 30000;

private:
	PageRecord* m_page_record;
	QMqttClient* m_client;
	QTimer* m_reconnect_timer;
	QTimer* m_keepalive_timer;
	bool m_connected;
	QString m_client_id;
	QString m_broker_host;
	int m_broker_port;
	QString m_username;
	QString m_password;
	bool m_use_tls;
	QString m_ca_cert;
	QString m_client_cert;
	QString m_client_key;

	// Subscriptions
	QMqttSubscription* m_sub_recording_start;
	QMqttSubscription* m_sub_recording_stop;
	QMqttSubscription* m_sub_recording_toggle;
	QMqttSubscription* m_sub_topic_change;
	QMqttSubscription* m_sub_button_recording;
	QMqttSubscription* m_sub_button_onair;
	QMqttSubscription* m_sub_status_get;
	QMqttSubscription* m_sub_client_connected;
	QMqttSubscription* m_sub_client_disconnected;
	QMqttSubscription* m_sub_client_status;

	// Configuration
	QString m_topic_root;
	QString m_instance_id;
	QString m_topic_architecture;

	// Last published values
	QString m_last_status;
	QString m_last_session_id;
	QString m_last_topic;
	bool m_last_recording_state;

public:
	MqttClient(PageRecord* page_record);
	~MqttClient();

	void LoadSettings(QSettings* settings);
	void SaveSettings(QSettings* settings);

	bool IsEnabled() const;
	bool IsConnected() const;

	void Connect();
	void Disconnect();

	void PublishStatus(const QString& status, const QString& session_id = QString(), const QString& topic = QString());
	void PublishRecordingState(bool recording);
	void PublishRecordingEvent(const QString& event, const QString& session_id = QString(), const QString& topic = QString());
	void PublishLedState(const QString& led, bool state);
	void PublishError(const QString& error);
	void PublishFullStatus(bool recording, const QString& session_id = QString(), const QString& topic = QString());
	void PublishClientConnected();
	void PublishClientDisconnected();



private:
	void SetupClient();
	void SubscribeToTopics();
	void SubscribeToTopicsByRecorder();
	void SubscribeToTopicsByClient();
	void UnsubscribeFromTopics();
	void PublishConnectionState(bool connected);

	QString GenerateClientId() const;
	QString GetBaseTopic() const;
	QString GetCentralizedTopic(const QString& path) const;
	QString GetFullTopic(const QString& path, bool centralized = false) const;

private slots:
	void OnClientConnected();
	void OnClientDisconnected();
	void OnClientError(QMqttClient::ClientError error);
	void OnStateChanged(QMqttClient::ClientState state);
	void OnClientMessageReceived(const QByteArray& message, const QMqttTopicName& topic);
	void OnReconnectTimer();
	void OnKeepaliveTimer();

signals:
	void RecordingStartRequested();
	void RecordingStopRequested();
	void RecordingToggleRequested();
	void RecordingPauseRequested();
	void RecordingResumeRequested();
	void TopicChangeRequested(const QString& topic);
	void ButtonRecordingPressed();
	void ButtonRecordingReleased();
	void ButtonOnAirPressed();
	void ButtonOnAirReleased();
	void StatusGetRequested();
};
