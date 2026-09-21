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

#include "MqttClient.h"
#include "PageRecord.h"
#include "Logger.h"
#include "CommandLineOptions.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>
#include <QHostInfo>
#include <QSslConfiguration>
#include <QSslCertificate>
#include <QSslKey>
#include <QSslSocket>
#include <QTcpSocket>
#include <QFile>
#include <QNetworkProxy>

MqttClient::MqttClient(PageRecord* page_record)
	: m_page_record(page_record),
	  m_client(nullptr),
	  m_reconnect_timer(nullptr),
	  m_keepalive_timer(nullptr),
	  m_connected(false),
	  m_broker_host("localhost"),
	  m_broker_port(1883),
	  m_use_tls(false),
	  m_topic_root("/ssr/"),
	  m_instance_id("main"),
	  m_topic_architecture("legacy"),
	  m_last_recording_state(false),
	  m_sub_recording_start(nullptr),
	  m_sub_recording_stop(nullptr),
	  m_sub_recording_toggle(nullptr),
	  m_sub_topic_change(nullptr),
	  m_sub_button_recording(nullptr),
	  m_sub_button_onair(nullptr),
	  m_sub_status_get(nullptr),
	  m_sub_client_connected(nullptr),
	  m_sub_client_disconnected(nullptr),
	  m_sub_client_status(nullptr) {

	m_client_id = GenerateClientId();

	m_client = new QMqttClient(this);
	m_reconnect_timer = new QTimer(this);
	m_keepalive_timer = new QTimer(this);

	connect(m_client, &QMqttClient::connected, this, &MqttClient::OnClientConnected);
	connect(m_client, &QMqttClient::disconnected, this, &MqttClient::OnClientDisconnected);
	connect(m_client, &QMqttClient::errorChanged, this, &MqttClient::OnClientError);
	connect(m_client, &QMqttClient::messageReceived, this, &MqttClient::OnClientMessageReceived);
	connect(m_client, &QMqttClient::stateChanged, this, &MqttClient::OnStateChanged);

	connect(m_reconnect_timer, &QTimer::timeout, this, &MqttClient::OnReconnectTimer);
	connect(m_keepalive_timer, &QTimer::timeout, this, &MqttClient::OnKeepaliveTimer);

	m_reconnect_timer->setInterval(RECONNECT_INTERVAL_MS);
	m_keepalive_timer->setInterval(KEEPALIVE_INTERVAL_MS);
}

MqttClient::~MqttClient() {
	Disconnect();
}

void MqttClient::LoadSettings(QSettings* settings) {
	settings->beginGroup("MQTT");

	// Load from settings file
	m_broker_host = settings->value("broker_host", "localhost").toString();
	m_broker_port = settings->value("broker_port", 1883).toInt();
	m_username = settings->value("username", "").toString();
	m_password = settings->value("password", "").toString();
	m_use_tls = settings->value("use_tls", false).toBool();
	m_ca_cert = settings->value("ca_cert", "").toString();
	m_client_cert = settings->value("client_cert", "").toString();
	m_client_key = settings->value("client_key", "").toString();
	m_topic_root = settings->value("topic_root", "/ssr/").toString();
	m_instance_id = settings->value("instance_id", "main").toString();
	m_topic_architecture = settings->value("topic_architecture", "legacy").toString();

	bool auto_connect = settings->value("auto_connect", false).toBool();
	settings->endGroup();

	// Override with command line options if provided
	CommandLineOptions* cmd = CommandLineOptions::GetInstance();
	if (!cmd->GetMqttBroker().isEmpty()) {
		m_broker_host = cmd->GetMqttBroker();
	}
	if (cmd->GetMqttPort() != 1883) {
		m_broker_port = cmd->GetMqttPort();
	}
	if (!cmd->GetMqttUsername().isEmpty()) {
		m_username = cmd->GetMqttUsername();
	}
	if (!cmd->GetMqttPassword().isEmpty()) {
		m_password = cmd->GetMqttPassword();
	}
	if (cmd->GetMqttTls()) {
		m_use_tls = true;
	}

	// Auto-connect if enabled
	if (auto_connect && cmd->GetMqttAutoConnect() && !m_broker_host.isEmpty()) {
		Connect();
	}
}

void MqttClient::SaveSettings(QSettings* settings) {
	settings->beginGroup("MQTT");

	// Don't save command line overrides
	CommandLineOptions* cmd = CommandLineOptions::GetInstance();

	// Only save values that weren't overridden by command line
	if (cmd->GetMqttBroker().isEmpty()) {
		settings->setValue("broker_host", m_broker_host);
	}
	if (cmd->GetMqttPort() == 1883) {
		settings->setValue("broker_port", m_broker_port);
	}
	if (cmd->GetMqttUsername().isEmpty()) {
		settings->setValue("username", m_username);
	}
	if (cmd->GetMqttPassword().isEmpty()) {
		settings->setValue("password", m_password);
	}
	if (!cmd->GetMqttTls()) {
		settings->setValue("use_tls", m_use_tls);
	}

	// Always save certificate paths
	settings->setValue("ca_cert", m_ca_cert);
	settings->setValue("client_cert", m_client_cert);
	settings->setValue("client_key", m_client_key);

	// Save topic configuration
	settings->setValue("topic_root", m_topic_root);
	settings->setValue("instance_id", m_instance_id);
	settings->setValue("topic_architecture", m_topic_architecture);

	settings->setValue("auto_connect", IsConnected() || m_reconnect_timer->isActive());

	settings->endGroup();
}

bool MqttClient::IsEnabled() const {
	return !m_broker_host.isEmpty();
}

bool MqttClient::IsConnected() const {
	return m_connected;
}

void MqttClient::Connect() {
	if (m_broker_host.isEmpty()) {
		Logger::LogError("[MQTT] Cannot connect: broker host not specified");
		return;
	}

	// Reset any existing connection
	if (m_client->state() != QMqttClient::Disconnected) {
		m_client->disconnectFromHost();
	}

	SetupClient();

	Logger::LogInfo("[MQTT] Connecting to " + m_broker_host + ":" + QString::number(m_broker_port) + "...");

	// Connection is initiated in SetupClient()
	// For SSL: connectToHostEncrypted is called in SetupClient()
	// For non-SSL: connectToHost is called in SetupClient()
}

void MqttClient::Disconnect() {
	m_reconnect_timer->stop();
	m_keepalive_timer->stop();

	if (m_client->state() != QMqttClient::Disconnected) {
		Logger::LogInfo("[MQTT] Disconnecting...");
		m_client->disconnectFromHost();
	}

	m_connected = false;
}

void MqttClient::PublishStatus(const QString& status, const QString& session_id, const QString& topic) {
	if (!m_connected) return;

	QJsonObject json;
	json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODateWithMs);
	json["status"] = status;
	if (!session_id.isEmpty()) {
		json["session_id"] = session_id;
	}
	if (!topic.isEmpty()) {
		json["topic"] = topic;
	}
	json["client_id"] = m_client_id;

	QJsonDocument doc(json);
	QString base_topic = GetBaseTopic();
	QString full_topic = base_topic + "status";
	QByteArray payload = doc.toJson();

	Logger::LogInfo("[MQTT] Publishing status to: " + full_topic + " payload: " + payload);

	if (m_client->publish(full_topic, payload, 1, false) == -1) {
		Logger::LogError("[MQTT] Failed to publish status");
	} else {
		Logger::LogInfo(QString("[MQTT] Status published successfully: %1").arg(full_topic));
	}

	m_last_status = status;
	m_last_session_id = session_id;
	m_last_topic = topic;
}

void MqttClient::PublishRecordingState(bool recording) {
	if (!m_connected) return;

	if (m_last_recording_state == recording) {
		return;
	}

	m_last_recording_state = recording;

	QJsonObject json;
	json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODateWithMs);
	json["recording"] = recording;
	json["client_id"] = m_client_id;

	QJsonDocument doc(json);
	QString base_topic = GetBaseTopic();
	QString full_topic = base_topic + "recording/state";
	m_client->publish(full_topic, doc.toJson(), 1, true);
	Logger::LogInfo(QString("[MQTT] Recording state published successfully: %1").arg(full_topic));

	// Also publish LED state for compatibility with existing systems
	PublishLedState("recording", recording);
}

void MqttClient::PublishRecordingEvent(const QString& event, const QString& session_id, const QString& topic) {
	if (!m_connected) return;

	QJsonObject json;
	json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODateWithMs);
	json["event"] = event;
	if (!session_id.isEmpty()) {
		json["session_id"] = session_id;
	}
	if (!topic.isEmpty()) {
		json["topic"] = topic;
	}
	json["client_id"] = m_client_id;

	QJsonDocument doc(json);

	// Publish to centralized events topic
	if (m_topic_architecture == "centralized" || m_topic_architecture == "both") {
		QString event_topic = GetCentralizedTopic("events/recording/" + event);
		m_client->publish(event_topic, doc.toJson(), 1, false);
		Logger::LogInfo(QString("[MQTT] Recording event published successfully: %1").arg(event_topic));
	}
}

void MqttClient::PublishLedState(const QString& led, bool state) {
	if (!m_connected) return;

	QJsonObject json;
	json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODateWithMs);
	json["led"] = led;
	json["state"] = state;
	json["client_id"] = m_client_id;

	QJsonDocument doc(json);
	QString base_topic = GetBaseTopic();
	QString full_topic = base_topic + "device/led/" + led;
	m_client->publish(full_topic, doc.toJson(), 1, true);
	Logger::LogInfo(QString("[MQTT] LED state published successfully: %1").arg(full_topic));
}

void MqttClient::PublishError(const QString& error) {
	if (!m_connected) return;

	QJsonObject json;
	json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODateWithMs);
	json["error"] = error;
	json["client_id"] = m_client_id;

	QJsonDocument doc(json);

	// Publish to centralized error topic
	if (m_topic_architecture == "centralized" || m_topic_architecture == "both") {
		QString error_topic = GetCentralizedTopic("events/error");
		m_client->publish(error_topic, doc.toJson(), 1, false);
		Logger::LogInfo(QString("[MQTT] Error event published successfully: %1").arg(error_topic));
	}

	// Also publish to legacy topic for compatibility
	if (m_topic_architecture == "legacy" || m_topic_architecture == "both") {
		QString base_topic = GetBaseTopic();
		m_client->publish(base_topic + "error", doc.toJson(), 1, false);
		Logger::LogInfo(QString("[MQTT] Error event published successfully: %1").arg(base_topic + "error"));
	}
}

void MqttClient::PublishFullStatus(bool recording, const QString& session_id, const QString& topic) {
	if (!m_connected) return;

	QJsonObject json;
	json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODateWithMs);
	json["status"] = recording ? "recording" : "idle";
	json["recording"] = recording;
	json["client_id"] = m_client_id;
	json["instance_id"] = m_instance_id;
	json["version"] = "0.4.4";

	if (!session_id.isEmpty()) {
		json["session_id"] = session_id;
	}
	if (!topic.isEmpty()) {
		json["topic"] = topic;
	}

	// Add recording-specific info if recording
	if (recording) {
		json["duration_seconds"] = 0; // TODO: Get actual duration
		json["file_size_mb"] = 0; // TODO: Get actual file size
		json["paused"] = false; // TODO: Get actual paused state
	}

	// Add system info
	json["system_time"] = QDateTime::currentDateTime().toString(Qt::ISODateWithMs);
	json["hostname"] = QHostInfo::localHostName();

	QJsonDocument doc(json);

	// Publish to centralized status topic (retained)
	if (m_topic_architecture == "centralized" || m_topic_architecture == "both") {
		QString status_topic = GetCentralizedTopic("status");
		m_client->publish(status_topic, doc.toJson(), 1, true);
		Logger::LogInfo(QString("[MQTT] Status event published successfully: %1").arg(status_topic));
	}

	// Also publish to legacy topic for compatibility
	if (m_topic_architecture == "legacy" || m_topic_architecture == "both") {
		QString base_topic = GetBaseTopic();
		m_client->publish(base_topic + "status", doc.toJson(), 1, true);
		Logger::LogInfo(QString("[MQTT] Status event published successfully: %1").arg(base_topic + "status"));
	}
}

void MqttClient::PublishClientConnected() {
	if (m_client->state() == QMqttClient::Disconnected) {
		QString topic = GetBaseTopic() + "client/connected";
		m_client->publish(topic, "{\"status\": \"connected\"}", 1, true);
		Logger::LogInfo("[MQTT] Client connected event published successfully");
	}
}

void MqttClient::PublishClientDisconnected() {
	if (m_client->state() == QMqttClient::Connected) {
		QString topic = GetBaseTopic() + "client/disconnected";
		m_client->publish(topic, "{\"status\": \"disconnected\"}", 1, true);
		Logger::LogInfo("[MQTT] Client disconnected event published successfully");
	}
}

void MqttClient::SetupClient() {
	// Disable proxy at application level for MQTT connections
	// This is needed because Qt uses system proxy settings which interfere with MQTT
	// Save current proxy to restore it later if needed
	static QNetworkProxy previousProxy = QNetworkProxy::applicationProxy();
	QNetworkProxy::setApplicationProxy(QNetworkProxy::NoProxy);

	m_client->setHostname(m_broker_host);
	m_client->setPort(m_broker_port);
	m_client->setClientId(m_client_id);
	m_client->setKeepAlive(60);
	// Note: setConnectTimeout is not available in Qt5 MQTT

	if (!m_username.isEmpty()) {
		m_client->setUsername(m_username);
		if (!m_password.isEmpty()) {
			m_client->setPassword(m_password);
		}
	}

	if (m_use_tls) {
		QSslConfiguration sslConfig;
		sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);

		if (!m_ca_cert.isEmpty() && QFile::exists(m_ca_cert)) {
			QFile caFile(m_ca_cert);
			if (caFile.open(QIODevice::ReadOnly)) {
				QSslCertificate caCert(&caFile, QSsl::Pem);
				sslConfig.addCaCertificate(caCert);
				caFile.close();
			}
		}

		if (!m_client_cert.isEmpty() && QFile::exists(m_client_cert) &&
			!m_client_key.isEmpty() && QFile::exists(m_client_key)) {
			QFile certFile(m_client_cert);
			QFile keyFile(m_client_key);
			if (certFile.open(QIODevice::ReadOnly) && keyFile.open(QIODevice::ReadOnly)) {
				QSslCertificate clientCert(&certFile, QSsl::Pem);
				QSslKey clientKey(&keyFile, QSsl::Rsa, QSsl::Pem);
				sslConfig.setLocalCertificate(clientCert);
				sslConfig.setPrivateKey(clientKey);
				certFile.close();
				keyFile.close();
			}
		}

		// Set SSL configuration on the client
		// Note: connectToHostEncrypted is deprecated but works in Qt5
		// and handles SSL internally without needing setTransport
		// First set the SSL configuration, then connect
		m_client->connectToHostEncrypted(sslConfig);
	} else {
		// For non-SSL connections, call connectToHost
		// Try to work around proxy issues by also setting socket option
		// before connecting
		m_client->connectToHost();
	}
	// Don't use setTransport - let QMqttClient handle socket creation
}

QString MqttClient::GetBaseTopic() const {
	return GetFullTopic("");
}

void MqttClient::SubscribeToTopics() {
	// Default implementation for recorder application
	SubscribeToTopicsByRecorder();
}

void MqttClient::SubscribeToTopicsByRecorder() {
	if (!m_connected) return;

	// Subscribe to additional centralized control topics
	m_client->subscribe(GetCentralizedTopic("control/recording/start"), 1);
	m_client->subscribe(GetCentralizedTopic("control/recording/stop"), 1);
	m_client->subscribe(GetCentralizedTopic("control/recording/toggle"), 1);
	m_client->subscribe(GetCentralizedTopic("control/client/connected"), 1);
	m_client->subscribe(GetCentralizedTopic("control/client/disconnected"), 1);
	m_client->subscribe(GetCentralizedTopic("control/client/status/request"), 1);
}

void MqttClient::SubscribeToTopicsByClient() {
	if (!m_connected) return;

	m_client->subscribe(GetCentralizedTopic("status/response"), 1);
	m_client->subscribe(GetCentralizedTopic("status/recording/started"), 1);
	m_client->subscribe(GetCentralizedTopic("status/recording/stopped"), 1);
	m_client->subscribe(GetCentralizedTopic("status/recording/paused"), 1);
	m_client->subscribe(GetCentralizedTopic("status/session/finished"), 1);
	m_client->subscribe(GetCentralizedTopic("status/session/started"), 1);

}

void MqttClient::UnsubscribeFromTopics() {
	if (m_sub_recording_start) {
		m_sub_recording_start->unsubscribe();
		m_sub_recording_start = nullptr;
	}
	if (m_sub_recording_stop) {
		m_sub_recording_stop->unsubscribe();
		m_sub_recording_stop = nullptr;
	}
	if (m_sub_recording_toggle) {
		m_sub_recording_toggle->unsubscribe();
		m_sub_recording_toggle = nullptr;
	}
	if (m_sub_topic_change) {
		m_sub_topic_change->unsubscribe();
		m_sub_topic_change = nullptr;
	}
	if (m_sub_button_recording) {
		m_sub_button_recording->unsubscribe();
		m_sub_button_recording = nullptr;
	}
	if (m_sub_button_onair) {
		m_sub_button_onair->unsubscribe();
		m_sub_button_onair = nullptr;
	}
	if (m_sub_status_get) {
		m_sub_status_get->unsubscribe();
		m_sub_status_get = nullptr;
	}
}

void MqttClient::PublishConnectionState(bool connected) {
	QJsonObject json;
	json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODateWithMs);
	json["connected"] = connected;
	json["client_id"] = m_client_id;
	json["broker"] = m_broker_host + ":" + QString::number(m_broker_port);

	QJsonDocument doc(json);
	QString base_topic = GetBaseTopic();
	m_client->publish(base_topic + "connection", doc.toJson(), 1, true);
}

QString MqttClient::GenerateClientId() const {
	QString hostname = QHostInfo::localHostName();
	QString username = qgetenv("USER");
	if (username.isEmpty()) {
		username = qgetenv("USERNAME");
	}

	QString client_id = "ssr_";
	if (!hostname.isEmpty()) {
		client_id += hostname + "_";
	}
	if (!username.isEmpty()) {
		client_id += username + "_";
	}
	client_id += QString::number(QDateTime::currentSecsSinceEpoch() % 1000000);

	return client_id;
}



QString MqttClient::GetCentralizedTopic(const QString& path) const {
	QString topic = m_topic_root;
	if (!topic.endsWith('/')) {
		topic += '/';
	}
	if (!m_instance_id.isEmpty() && m_instance_id != "main") {
		topic += m_instance_id + "/";
	}
	topic += path;
	if (!topic.startsWith('/')) {
		topic = '/' + topic;
	}
	return topic;
}

QString MqttClient::GetFullTopic(const QString& path, bool centralized) const {
    return GetCentralizedTopic(path);
}

void MqttClient::OnClientConnected() {
	m_connected = true;
	m_reconnect_timer->stop();
	m_keepalive_timer->start();

	Logger::LogInfo("[MQTT] Connected to broker");

	PublishConnectionState(true);
	SubscribeToTopics();

	// Publish initial status
	PublishStatus("connected");
	PublishRecordingState(false);
}

void MqttClient::OnClientDisconnected() {
	m_connected = false;
	m_keepalive_timer->stop();

	UnsubscribeFromTopics();

	Logger::LogWarning("[MQTT] Disconnected from broker");

	// Start reconnect timer
	m_reconnect_timer->start();
}

void MqttClient::OnStateChanged(QMqttClient::ClientState state) {
	QString state_str;
	switch (state) {
		case QMqttClient::Disconnected: state_str = "Disconnected"; break;
		case QMqttClient::Connecting: state_str = "Connecting"; break;
		case QMqttClient::Connected: state_str = "Connected"; break;
		default: state_str = "Unknown"; break;
	}

	Logger::LogInfo("[MQTT] State changed to: " + state_str);

	// Log additional debug info for connection issues
	if (state == QMqttClient::Connecting) {
		Logger::LogInfo("[MQTT] Connecting to " + m_broker_host + ":" + QString::number(m_broker_port));
	} else if (state == QMqttClient::Disconnected) {
		Logger::LogInfo("[MQTT] Disconnected, error: " + QString::number(static_cast<int>(m_client->error())));
	}
}

void MqttClient::OnClientError(QMqttClient::ClientError error) {
	QString error_str;
	switch (error) {
		case QMqttClient::NoError: error_str = "NoError"; break;
		case QMqttClient::InvalidProtocolVersion: error_str = "InvalidProtocolVersion"; break;
		case QMqttClient::IdRejected: error_str = "IdRejected"; break;
		case QMqttClient::ServerUnavailable: error_str = "ServerUnavailable"; break;
		case QMqttClient::BadUsernameOrPassword: error_str = "BadUsernameOrPassword"; break;
		case QMqttClient::NotAuthorized: error_str = "NotAuthorized"; break;
		case QMqttClient::TransportInvalid: error_str = "TransportInvalid"; break;
		case QMqttClient::ProtocolViolation: error_str = "ProtocolViolation"; break;
		case QMqttClient::UnknownError: error_str = "UnknownError"; break;
		case QMqttClient::Mqtt5SpecificError: error_str = "Mqtt5SpecificError"; break;
		default: error_str = "UnknownErrorCode"; break;
	}

	Logger::LogError("[MQTT] Error: " + error_str + " (code: " + QString::number(static_cast<int>(error)) + ")");
	Logger::LogError("[MQTT] Current state: " + QString::number(static_cast<int>(m_client->state())));
	Logger::LogError("[MQTT] Host: " + m_broker_host + ":" + QString::number(m_broker_port));

	// For TransportInvalid error, provide more specific debugging info
	if (error == QMqttClient::TransportInvalid) {
		Logger::LogError("[MQTT] TransportInvalid - Possible causes:");
		Logger::LogError("[MQTT] 1. Proxy interference (even with NoProxy set)");
		Logger::LogError("[MQTT] 2. Socket creation failure");
		Logger::LogError("[MQTT] 3. Network permissions issue");
		Logger::LogError("[MQTT] 4. QtMqtt library bug with system proxy");
	}

	PublishError("Connection error: " + error_str);
}


void MqttClient::OnClientMessageReceived(const QByteArray& message, const QMqttTopicName& topic) {
	QString topic_str = topic.name();
	QString payload = QString::fromUtf8(message);

	Logger::LogInfo("[MQTT] Received message on topic: " + topic_str + " payload: " + payload);

	// Check if it's a centralized topic
	QString centralized_root = GetCentralizedTopic("");
	if (topic_str.startsWith(centralized_root)) {
		QString relative_topic = topic_str.mid(centralized_root.length());

		try {
			QJsonDocument doc = QJsonDocument::fromJson(payload.toUtf8());
			QJsonObject json;
			if (!doc.isNull() && doc.isObject()) {
				json = doc.object();
			}
			// Check session ID if provided
			QString session_id = json.value("session").toString();
			Logger::LogInfo("[MQTT] Session check: session_id=" + session_id + ", m_instance_id=" + m_instance_id);
			if (!session_id.isEmpty() && session_id != m_instance_id && session_id != "main") {
				Logger::LogInfo("[MQTT] Ignoring message for different session: " + session_id + " (our session: " + m_instance_id + ")");
				return;
			}

			if (relative_topic == "status/state/get") {
				emit StatusGetRequested();
			} else if (relative_topic == "status/start") {
				emit RecordingStartRequested();
			} else if (relative_topic == "status/stop") {
				emit RecordingStopRequested();
			} else if (relative_topic == "status/toggle") {
				emit RecordingToggleRequested();
			} else if (relative_topic == "status/pause") {
				emit RecordingPauseRequested();
			} else if (relative_topic == "status/resume") {
				emit RecordingResumeRequested();
			} else if (relative_topic == "control/recording/start") {
				Logger::LogInfo("[MQTT] Received control/recording/start command");
				emit RecordingStartRequested();
			} else if (relative_topic == "control/recording/stop") {
				Logger::LogInfo("[MQTT] Received control/recording/stop command");
				emit RecordingStopRequested();
			} else if (relative_topic == "control/recording/toggle") {
				Logger::LogInfo("[MQTT] Received control/recording/toggle command");
				emit RecordingToggleRequested();
			} else if (relative_topic == "control/client/connected") {
				// Client connection notification, just log it
				Logger::LogInfo("[MQTT] Remote client connected: " + json.value("status").toString());
			} else if (relative_topic == "control/client/disconnected") {
				// Client disconnection notification, just log it
				Logger::LogInfo("[MQTT] Remote client disconnected: " + json.value("status").toString());
			} else if (relative_topic == "control/client/status/request") {
				emit StatusGetRequested();
			} else if (relative_topic == "control/topic/set") {
				QString new_topic = json.value("topic").toString();
				if (new_topic.isEmpty()) {
					new_topic = json.value("new_topic").toString();
				}
				if (new_topic.isEmpty()) {
					new_topic = payload.trimmed();
				}
				if (!new_topic.isEmpty()) {
					emit TopicChangeRequested(new_topic);
				}
			}
		} catch (const std::exception& e) {
			Logger::LogError("[MQTT] Error processing centralized message: " + QString(e.what()));
			PublishError("Error processing centralized message: " + QString(e.what()));
		}
		return;
	}

	// Legacy topic handling
	QString base_topic = GetBaseTopic();
	QString relative_topic = topic_str;
	if (topic_str.startsWith(base_topic)) {
		relative_topic = topic_str.mid(base_topic.length());
	}

	try {
		QJsonDocument doc = QJsonDocument::fromJson(payload.toUtf8());
		QJsonObject json;
		if (!doc.isNull() && doc.isObject()) {
			json = doc.object();
		}

		// Check session ID if provided
		QString session_id = json.value("session").toString();
		Logger::LogInfo("[MQTT] Session check (legacy): session_id=" + session_id + ", m_instance_id=" + m_instance_id);
		if (!session_id.isEmpty() && session_id != m_instance_id && session_id != "main") {
			Logger::LogInfo("[MQTT] Ignoring message for different session: " + session_id + " (our session: " + m_instance_id + ")");
			return;
		}

		if (relative_topic == "control/recording/start") {
			Logger::LogInfo("[MQTT] Received control/recording/start command (legacy)");
			emit RecordingStartRequested();
		} else if (relative_topic == "control/recording/stop") {
			Logger::LogInfo("[MQTT] Received control/recording/stop command (legacy)");
			emit RecordingStopRequested();
		} else if (relative_topic == "control/recording/toggle") {
			Logger::LogInfo("[MQTT] Received control/recording/toggle command (legacy)");
			emit RecordingToggleRequested();
		} else if (relative_topic == "control/topic/change") {
			QString new_topic = json.value("topic").toString();
			if (new_topic.isEmpty()) {
				new_topic = json.value("new_topic").toString();
			}
			if (new_topic.isEmpty()) {
				new_topic = payload.trimmed();
			}
			if (!new_topic.isEmpty()) {
				emit TopicChangeRequested(new_topic);
			}
		} else if (relative_topic == "device/button/recording") {
			QString action = json.value("action").toString();
			if (action.isEmpty()) {
				action = payload.trimmed().toLower();
			}

			if (action == "pressed" || action == "down" || action == "1" || action == "true") {
				emit ButtonRecordingPressed();
			} else if (action == "released" || action == "up" || action == "0" || action == "false") {
				emit ButtonRecordingReleased();
			} else if (action == "toggle") {
				emit RecordingToggleRequested();
			}
		} else if (relative_topic == "device/button/onair") {
			QString action = json.value("action").toString();
			if (action.isEmpty()) {
				action = payload.trimmed().toLower();
			}

			if (action == "pressed" || action == "down" || action == "1" || action == "true") {
				emit ButtonOnAirPressed();
			} else if (action == "released" || action == "up" || action == "0" || action == "false") {
				emit ButtonOnAirReleased();
			}
		}
	} catch (const std::exception& e) {
		Logger::LogError("[MQTT] Error processing message: " + QString(e.what()));
		PublishError("Error processing message: " + QString(e.what()));
	}
}

void MqttClient::OnReconnectTimer() {
	if (!m_connected && !m_broker_host.isEmpty()) {
		Logger::LogInfo("[MQTT] Attempting to reconnect...");
		m_client->connectToHost();
	}
}

void MqttClient::OnKeepaliveTimer() {
	if (m_connected) {
		// Publish a keepalive message
		QJsonObject json;
		json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODateWithMs);
		json["type"] = "keepalive";
		json["client_id"] = m_client_id;

		QJsonDocument doc(json);
		QString base_topic = GetBaseTopic();
		m_client->publish(base_topic + "keepalive", doc.toJson(), 0, false);
	}
}
