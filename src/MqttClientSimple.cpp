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

#include "MqttClientSimple.h"
#include "PageRecord.h"
#include "Logger.h"
#include "CommandLineOptions.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>
#include <QFile>
#include <QThread>
#include <unistd.h>

#include <cstring>
#include <cstdlib>

MqttClientSimple::MqttClientSimple(PageRecord* page_record)
	: m_page_record(page_record),
	  m_mosquitto(nullptr),
	  m_reconnect_timer(nullptr),
	  m_keepalive_timer(nullptr),
	  m_connected(false),
	  m_should_reconnect(false),
	  m_broker_host("localhost"),
	  m_broker_port(1883),
	  m_use_tls(false),
	  m_last_recording_state(false) {
	
	m_client_id = GenerateClientId();
	
	// Initialize mosquitto library
	mosquitto_lib_init();
	
	// Create mosquitto instance
	m_mosquitto = mosquitto_new(m_client_id.toUtf8().constData(), true, this);
	if (!m_mosquitto) {
		Logger::LogError("[MQTT] Failed to create mosquitto instance");
		return;
	}
	
	// Set callbacks
	mosquitto_connect_callback_set(m_mosquitto, OnConnectCallback);
	mosquitto_disconnect_callback_set(m_mosquitto, OnDisconnectCallback);
	mosquitto_message_callback_set(m_mosquitto, OnMessageCallback);
	mosquitto_log_callback_set(m_mosquitto, OnLogCallback);
	
	// Create timers
	m_reconnect_timer = new QTimer(this);
	m_keepalive_timer = new QTimer(this);
	
	connect(m_reconnect_timer, &QTimer::timeout, this, &MqttClientSimple::OnReconnectTimer);
	connect(m_keepalive_timer, &QTimer::timeout, this, &MqttClientSimple::OnKeepaliveTimer);
	
	m_reconnect_timer->setInterval(RECONNECT_INTERVAL_MS);
	m_keepalive_timer->setInterval(KEEPALIVE_INTERVAL_MS);
}

MqttClientSimple::~MqttClientSimple() {
	Disconnect();
	
	if (m_mosquitto) {
		mosquitto_destroy(m_mosquitto);
		m_mosquitto = nullptr;
	}
	
	mosquitto_lib_cleanup();
}

void MqttClientSimple::LoadSettings(QSettings* settings) {
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

void MqttClientSimple::SaveSettings(QSettings* settings) {
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
	settings->setValue("auto_connect", IsConnected() || m_reconnect_timer->isActive());
	
	settings->endGroup();
}

bool MqttClientSimple::IsEnabled() const {
	return !m_broker_host.isEmpty();
}

bool MqttClientSimple::IsConnected() const {
	return m_connected;
}

void MqttClientSimple::Connect() {
	if (m_broker_host.isEmpty()) {
		Logger::LogError("[MQTT] Cannot connect: broker host not specified");
		return;
	}
	
	if (!m_mosquitto) {
		Logger::LogError("[MQTT] Cannot connect: mosquitto instance not created");
		return;
	}
	
	SetupMosquitto();
	
	Logger::LogInfo("[MQTT] Connecting to " + m_broker_host + ":" + QString::number(m_broker_port) + "...");
	
	// Set username/password if provided
	if (!m_username.isEmpty()) {
		int rc = mosquitto_username_pw_set(m_mosquitto, 
			m_username.toUtf8().constData(),
			m_password.isEmpty() ? nullptr : m_password.toUtf8().constData());
		if (rc != MOSQ_ERR_SUCCESS) {
			Logger::LogError("[MQTT] Failed to set username/password: " + QString(mosquitto_strerror(rc)));
		}
	}
	
	// Set TLS options if enabled
	if (m_use_tls) {
		if (!m_ca_cert.isEmpty()) {
			int rc = mosquitto_tls_set(m_mosquitto,
				m_ca_cert.toUtf8().constData(),
				nullptr,
				m_client_cert.toUtf8().constData(),
				m_client_key.toUtf8().constData(),
				nullptr);
			if (rc != MOSQ_ERR_SUCCESS) {
				Logger::LogError("[MQTT] Failed to set TLS options: " + QString(mosquitto_strerror(rc)));
			}
		}
		
		// Disable certificate verification for self-signed certificates
		mosquitto_tls_insecure_set(m_mosquitto, true);
	}
	
	// Connect to broker
	int rc = mosquitto_connect(m_mosquitto,
		m_broker_host.toUtf8().constData(),
		m_broker_port,
		60); // Keepalive interval in seconds
	
	if (rc != MOSQ_ERR_SUCCESS) {
		Logger::LogError("[MQTT] Failed to initiate connection: " + QString(mosquitto_strerror(rc)));
		m_should_reconnect = true;
		m_reconnect_timer->start();
		return;
	}
	
	// Start network loop in a separate thread
	rc = mosquitto_loop_start(m_mosquitto);
	if (rc != MOSQ_ERR_SUCCESS) {
		Logger::LogError("[MQTT] Failed to start network loop: " + QString(mosquitto_strerror(rc)));
		mosquitto_disconnect(m_mosquitto);
		m_should_reconnect = true;
		m_reconnect_timer->start();
		return;
	}
	
	m_should_reconnect = true;
	m_reconnect_timer->start();
}

void MqttClientSimple::Disconnect() {
	m_should_reconnect = false;
	m_reconnect_timer->stop();
	m_keepalive_timer->stop();
	
	if (m_mosquitto && m_connected) {
		Logger::LogInfo("[MQTT] Disconnecting...");
		mosquitto_disconnect(m_mosquitto);
		mosquitto_loop_stop(m_mosquitto, false);
	}
	
	m_connected = false;
	emit ConnectionStateChanged(false);
}

void MqttClientSimple::PublishStatus(const QString& status, const QString& session_id, const QString& topic) {
	if (!m_connected || !m_mosquitto) return;
	
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
	QByteArray payload = doc.toJson();
	QString base_topic = GetBaseTopic();
	
	int rc = mosquitto_publish(m_mosquitto,
		nullptr,
		(base_topic + "status").toUtf8().constData(),
		payload.size(),
		payload.constData(),
		1, // QoS 1
		false); // Not retained
	
	if (rc != MOSQ_ERR_SUCCESS) {
		Logger::LogError("[MQTT] Failed to publish status: " + QString(mosquitto_strerror(rc)));
	}
	
	m_last_status = status;
	m_last_session_id = session_id;
	m_last_topic = topic;
}

void MqttClientSimple::PublishRecordingState(bool recording) {
	if (!m_connected || !m_mosquitto) return;
	
	if (m_last_recording_state == recording) {
		return;
	}
	
	m_last_recording_state = recording;
	
	QJsonObject json;
	json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODateWithMs);
	json["recording"] = recording;
	json["client_id"] = m_client_id;
	
	QJsonDocument doc(json);
	QByteArray payload = doc.toJson();
	QString base_topic = GetBaseTopic();
	
	int rc = mosquitto_publish(m_mosquitto,
		nullptr,
		(base_topic + "recording/state").toUtf8().constData(),
		payload.size(),
		payload.constData(),
		1, // QoS 1
		true); // Retained
	
	if (rc != MOSQ_ERR_SUCCESS) {
		Logger::LogError("[MQTT] Failed to publish recording state: " + QString(mosquitto_strerror(rc)));
	}
	
	// Also publish LED state for compatibility with existing systems
	PublishLedState("recording", recording);
}

void MqttClientSimple::PublishRecordingEvent(const QString& event, const QString& session_id, const QString& topic) {
	if (!m_connected || !m_mosquitto) return;
	
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
	QByteArray payload = doc.toJson();
	QString base_topic = GetBaseTopic();
	
	int rc = mosquitto_publish(m_mosquitto,
		nullptr,
		(base_topic + "recording/events").toUtf8().constData(),
		payload.size(),
		payload.constData(),
		1, // QoS 1
		false); // Not retained
	
	if (rc != MOSQ_ERR_SUCCESS) {
		Logger::LogError("[MQTT] Failed to publish recording event: " + QString(mosquitto_strerror(rc)));
	}
}

void MqttClientSimple::PublishLedState(const QString& led, bool state) {
	if (!m_connected || !m_mosquitto) return;
	
	QJsonObject json;
	json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODateWithMs);
	json["led"] = led;
	json["state"] = state;
	json["client_id"] = m_client_id;
	
	QJsonDocument doc(json);
	QByteArray payload = doc.toJson();
	QString base_topic = GetBaseTopic();
	
	int rc = mosquitto_publish(m_mosquitto,
		nullptr,
		(base_topic + "device/led/" + led).toUtf8().constData(),
		payload.size(),
		payload.constData(),
		1, // QoS 1
		true); // Retained
	
	if (rc != MOSQ_ERR_SUCCESS) {
		Logger::LogError("[MQTT] Failed to publish LED state: " + QString(mosquitto_strerror(rc)));
	}
}

void MqttClientSimple::PublishError(const QString& error) {
	if (!m_connected || !m_mosquitto) return;
	
	QJsonObject json;
	json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODateWithMs);
	json["error"] = error;
	json["client_id"] = m_client_id;
	
	QJsonDocument doc(json);
	QByteArray payload = doc.toJson();
	QString base_topic = GetBaseTopic();
	
	int rc = mosquitto_publish(m_mosquitto,
		nullptr,
		(base_topic + "error").toUtf8().constData(),
		payload.size(),
		payload.constData(),
		1, // QoS 1
		false); // Not retained
	
	if (rc != MOSQ_ERR_SUCCESS) {
		Logger::LogError("[MQTT] Failed to publish error: " + QString(mosquitto_strerror(rc)));
	}
}

void MqttClientSimple::SetupMosquitto() {
	// Nothing to do here - setup is done in Connect()
}

void MqttClientSimple::SubscribeToTopics() {
	if (!m_connected || !m_mosquitto) return;
	
	QString base_topic = GetBaseTopic();
	
	// Subscribe to control topics
	const char* topics[] = {
		"control/recording/start",
		"control/recording/stop",
		"control/recording/toggle",
		"control/topic/change",
		"device/button/recording",
		"device/button/onair"
	};
	
	int qos = 1; // QoS 1
	
	for (const char* topic : topics) {
		QString full_topic = base_topic + topic;
		int rc = mosquitto_subscribe(m_mosquitto, nullptr, full_topic.toUtf8().constData(), qos);
		if (rc != MOSQ_ERR_SUCCESS) {
			Logger::LogError("[MQTT] Failed to subscribe to " + full_topic + ": " + QString(mosquitto_strerror(rc)));
		}
	}
}

void MqttClientSimple::UnsubscribeFromTopics() {
	if (!m_mosquitto) return;
	
	// Mosquitto will automatically unsubscribe when disconnecting
}

void MqttClientSimple::PublishConnectionState(bool connected) {
	if (!m_connected || !m_mosquitto) return;
	
	QJsonObject json;
	json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODateWithMs);
	json["connected"] = connected;
	json["client_id"] = m_client_id;
	json["broker"] = m_broker_host + ":" + QString::number(m_broker_port);
	
	QJsonDocument doc(json);
	QByteArray payload = doc.toJson();
	QString base_topic = GetBaseTopic();
	
	int rc = mosquitto_publish(m_mosquitto,
		nullptr,
		(base_topic + "connection").toUtf8().constData(),
		payload.size(),
		payload.constData(),
		1, // QoS 1
		true); // Retained
	
	if (rc != MOSQ_ERR_SUCCESS) {
		Logger::LogError("[MQTT] Failed to publish connection state: " + QString(mosquitto_strerror(rc)));
	}
}

QString MqttClientSimple::GenerateClientId() const {
	char hostname[256];
	if (gethostname(hostname, sizeof(hostname)) != 0) {
		hostname[0] = '\0';
	}
	
	QString username = qgetenv("USER");
	if (username.isEmpty()) {
		username = qgetenv("USERNAME");
	}
	
	QString client_id = "ssr_";
	if (hostname[0] != '\0') {
		client_id += QString::fromLocal8Bit(hostname) + "_";
	}
	if (!username.isEmpty()) {
		client_id += username + "_";
	}
	client_id += QString::number(QDateTime::currentSecsSinceEpoch() % 1000000);
	
	return client_id;
}

QString MqttClientSimple::GetBaseTopic() const {
	return "recording/" + m_client_id + "/";
}

// Static callback functions
void MqttClientSimple::OnConnectCallback(struct mosquitto* mosq, void* userdata, int rc) {
	MqttClientSimple* client = static_cast<MqttClientSimple*>(userdata);
	if (client) {
		client->OnConnect(rc);
	}
}

void MqttClientSimple::OnDisconnectCallback(struct mosquitto* mosq, void* userdata, int rc) {
	MqttClientSimple* client = static_cast<MqttClientSimple*>(userdata);
	if (client) {
		client->OnDisconnect(rc);
	}
}

void MqttClientSimple::OnMessageCallback(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* msg) {
	MqttClientSimple* client = static_cast<MqttClientSimple*>(userdata);
	if (client && msg && msg->topic && msg->payload) {
		QString topic = QString::fromUtf8(msg->topic);
		QString payload = QString::fromUtf8(static_cast<const char*>(msg->payload), msg->payloadlen);
		// Use queued connection to process message in main thread
		QMetaObject::invokeMethod(client, "ProcessMessage", Qt::QueuedConnection,
			Q_ARG(QString, topic), Q_ARG(QString, payload));
	}
}

void MqttClientSimple::OnLogCallback(struct mosquitto* mosq, void* userdata, int level, const char* str) {
	MqttClientSimple* client = static_cast<MqttClientSimple*>(userdata);
	if (client) {
		client->OnLog(level, str);
	}
}

// Instance callback handlers
void MqttClientSimple::OnConnect(int rc) {
	if (rc == 0) {
		m_connected = true;
		m_reconnect_timer->stop();
		m_keepalive_timer->start();
		
		Logger::LogInfo("[MQTT] Connected to broker");
		
		PublishConnectionState(true);
		SubscribeToTopics();
		
		// Publish initial status
		PublishStatus("connected");
		PublishRecordingState(false);
		
		emit ConnectionStateChanged(true);
	} else {
		Logger::LogError("[MQTT] Connection failed: " + QString(mosquitto_connack_string(rc)));
		m_should_reconnect = true;
		m_reconnect_timer->start();
	}
}

void MqttClientSimple::OnDisconnect(int rc) {
	m_connected = false;
	m_keepalive_timer->stop();
	
	if (m_should_reconnect) {
		m_reconnect_timer->start();
	}
	
	Logger::LogWarning("[MQTT] Disconnected from broker: " + QString(mosquitto_strerror(rc)));
	emit ConnectionStateChanged(false);
}

void MqttClientSimple::OnMessage(const struct mosquitto_message* msg) {
	// This method is not used directly - messages are processed via ProcessMessage
	// which is called from OnMessageCallback through invokeMethod
}

void MqttClientSimple::OnLog(int level, const char* str) {
	QString log_msg = QString::fromUtf8(str);
	switch (level) {
		case MOSQ_LOG_DEBUG:
			Logger::LogInfo("[MQTT] " + log_msg);
			break;
		case MOSQ_LOG_INFO:
			Logger::LogInfo("[MQTT] " + log_msg);
			break;
		case MOSQ_LOG_NOTICE:
			Logger::LogInfo("[MQTT] " + log_msg);
			break;
		case MOSQ_LOG_WARNING:
			Logger::LogWarning("[MQTT] " + log_msg);
			break;
		case MOSQ_LOG_ERR:
			Logger::LogError("[MQTT] " + log_msg);
			break;
		default:
			Logger::LogInfo("[MQTT] " + log_msg);
			break;
	}
}

void MqttClientSimple::OnReconnectTimer() {
	if (!m_connected && m_should_reconnect && !m_broker_host.isEmpty() && m_mosquitto) {
		Logger::LogInfo("[MQTT] Attempting to reconnect...");
		Connect();
	}
}

void MqttClientSimple::OnKeepaliveTimer() {
	if (m_connected && m_mosquitto) {
		// Publish a keepalive message
		QJsonObject json;
		json["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODateWithMs);
		json["type"] = "keepalive";
		json["client_id"] = m_client_id;
		
		QJsonDocument doc(json);
		QByteArray payload = doc.toJson();
		QString base_topic = GetBaseTopic();
		
		int rc = mosquitto_publish(m_mosquitto,
			nullptr,
			(base_topic + "keepalive").toUtf8().constData(),
			payload.size(),
			payload.constData(),
			0, // QoS 0
			false); // Not retained
		
		if (rc != MOSQ_ERR_SUCCESS) {
			Logger::LogError("[MQTT] Failed to publish keepalive: " + QString(mosquitto_strerror(rc)));
		}
	}
}

void MqttClientSimple::ProcessMessage(const QString& topic, const QString& payload) {
	Logger::LogInfo("[MQTT] Received message on topic: " + topic + " payload: " + payload);
	
	QString base_topic = GetBaseTopic();
	QString relative_topic = topic;
	if (topic.startsWith(base_topic)) {
		relative_topic = topic.mid(base_topic.length());
	}
	
	try {
		QJsonDocument doc = QJsonDocument::fromJson(payload.toUtf8());
		QJsonObject json;
		if (!doc.isNull() && doc.isObject()) {
			json = doc.object();
		}
		
		if (relative_topic == "control/recording/start") {
			emit RecordingStartRequested();
		} else if (relative_topic == "control/recording/stop") {
			emit RecordingStopRequested();
		} else if (relative_topic == "control/recording/toggle") {
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
			} else if (action == "toggle" || action == "click") {
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
	}
}