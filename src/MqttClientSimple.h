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

#include "MqttClientInterface.h"

#include <QTimer>
#include <memory>
#include <mosquitto.h>

class PageRecord;

class MqttClientSimple : public MqttClientInterface {
	Q_OBJECT

private:
	static constexpr int RECONNECT_INTERVAL_MS = 5000;
	static constexpr int KEEPALIVE_INTERVAL_MS = 30000;

private:
	PageRecord* m_page_record;
	struct mosquitto* m_mosquitto;
	QTimer* m_reconnect_timer;
	QTimer* m_keepalive_timer;
	bool m_connected;
	bool m_should_reconnect;
	QString m_client_id;
	QString m_broker_host;
	int m_broker_port;
	QString m_username;
	QString m_password;
	bool m_use_tls;
	QString m_ca_cert;
	QString m_client_cert;
	QString m_client_key;

	// Last published values
	QString m_last_status;
	QString m_last_session_id;
	QString m_last_topic;
	bool m_last_recording_state;

public:
	MqttClientSimple(PageRecord* page_record);
	~MqttClientSimple();

	// MqttClientInterface implementation
	void LoadSettings(QSettings* settings) override;
	void SaveSettings(QSettings* settings) override;
	
	bool IsEnabled() const override;
	bool IsConnected() const override;
	void Connect() override;
	void Disconnect() override;
	
	void PublishStatus(const QString& status, const QString& session_id = QString(), const QString& topic = QString()) override;
	void PublishRecordingState(bool recording) override;
	void PublishRecordingEvent(const QString& event, const QString& session_id = QString(), const QString& topic = QString()) override;
	void PublishLedState(const QString& led, bool state) override;
	void PublishError(const QString& error) override;

private:
	void SetupMosquitto();
	void SubscribeToTopics();
	void UnsubscribeFromTopics();
	void PublishConnectionState(bool connected);

	QString GenerateClientId() const;
	QString GetBaseTopic() const;
	
	// Static callback functions
	static void OnConnectCallback(struct mosquitto* mosq, void* userdata, int rc);
	static void OnDisconnectCallback(struct mosquitto* mosq, void* userdata, int rc);
	static void OnMessageCallback(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* msg);
	static void OnLogCallback(struct mosquitto* mosq, void* userdata, int level, const char* str);

	// Instance callback handlers
	void OnConnect(int rc);
	void OnDisconnect(int rc);
	void OnMessage(const struct mosquitto_message* msg);
	void OnLog(int level, const char* str);

private slots:
	void OnReconnectTimer();
	void OnKeepaliveTimer();
	void ProcessMessage(const QString& topic, const QString& payload);
};