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

#include "MqttConfig.h"
#include "Logger.h"

#include <QCoreApplication>
#include <QStandardPaths>
#include <QRegularExpression>
#include <QDateTime>

MqttConfig::MqttConfig(QObject* parent)
	: QObject(parent),
	  m_config_loaded(false),
	  m_config_changed(false) {
	
	// Set default config path
	m_config_path = getDefaultConfigPath();
}

MqttConfig::~MqttConfig() {
	// Auto-save if config was changed
	if (m_config_changed && m_config_loaded) {
		saveConfig(m_config_path);
	}
}

bool MqttConfig::loadConfig(const QString& config_path) {
	QString path = config_path;
	if (path.isEmpty()) {
		path = m_config_path;
	}
	
	Logger::LogInfo("[MQTT Config] Loading configuration from: " + path);
	
	// Read file content
	QString content = readFileContent(path);
	if (content.isEmpty()) {
		Logger::LogInfo("[MQTT Config] Configuration file not found or empty, using defaults");
		m_config = defaultConfig();
		m_config_loaded = true;
		m_config_changed = false;
		m_config_path = path;
		return true;
	}
	
	// Parse YAML
	QString error;
	ConnectionConfig config = fromYaml(content, &error);
	if (!error.isEmpty()) {
		Logger::LogError("[MQTT Config] Failed to parse configuration: " + error);
		return false;
	}
	
	m_config = config;
	m_config_loaded = true;
	m_config_changed = false;
	m_config_path = path;
	
	Logger::LogInfo("[MQTT Config] Configuration loaded successfully");
	return true;
}

bool MqttConfig::saveConfig(const QString& config_path) {
	QString path = config_path;
	if (path.isEmpty()) {
		path = m_config_path;
	}
	
	Logger::LogInfo("[MQTT Config] Saving configuration to: " + path);
	
	// Ensure directory exists
	if (!ensureConfigDirExists(path)) {
		Logger::LogError("[MQTT Config] Failed to create configuration directory");
		return false;
	}
	
	// Generate YAML
	QString yaml_content = toYaml(m_config);
	
	// Write to file
	if (!writeFileContent(path, yaml_content)) {
		Logger::LogError("[MQTT Config] Failed to write configuration file");
		return false;
	}
	
	m_config_changed = false;
	m_config_path = path;
	
	Logger::LogInfo("[MQTT Config] Configuration saved successfully");
	return true;
}

QString MqttConfig::getDefaultConfigPath() {
	// Use XDG_CONFIG_HOME if set, otherwise ~/.config
	QString config_dir = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
	if (config_dir.isEmpty()) {
		config_dir = QDir::homePath() + "/.config";
	}
	
	// Create SSR-specific config directory
	config_dir += "/simplescreenrecorder";
	
	// Config file name
	return config_dir + "/mqtt.yaml";
}

bool MqttConfig::validateConfig() const {
	return m_config.isValid();
}

QStringList MqttConfig::getValidationErrors() const {
	QStringList errors;
	
	if (m_config.broker_host.isEmpty()) {
		errors.append("Broker host is empty");
	}
	
	if (m_config.broker_port <= 0 || m_config.broker_port > 65535) {
		errors.append(QString("Invalid broker port: %1").arg(m_config.broker_port));
	}
	
	if (m_config.keepalive_interval < 5) {
		errors.append(QString("Keepalive interval too short: %1 seconds (minimum 5)").arg(m_config.keepalive_interval));
	}
	
	if (m_config.reconnect_interval < 1) {
		errors.append(QString("Reconnect interval too short: %1 seconds (minimum 1)").arg(m_config.reconnect_interval));
	}
	
	if (m_config.qos_status < 0 || m_config.qos_status > 2) {
		errors.append(QString("Invalid QoS for status messages: %1 (must be 0, 1, or 2)").arg(m_config.qos_status));
	}
	
	if (m_config.qos_recording_state < 0 || m_config.qos_recording_state > 2) {
		errors.append(QString("Invalid QoS for recording state: %1 (must be 0, 1, or 2)").arg(m_config.qos_recording_state));
	}
	
	if (m_config.qos_recording_events < 0 || m_config.qos_recording_events > 2) {
		errors.append(QString("Invalid QoS for recording events: %1 (must be 0, 1, or 2)").arg(m_config.qos_recording_events));
	}
	
	if (m_config.qos_led_states < 0 || m_config.qos_led_states > 2) {
		errors.append(QString("Invalid QoS for LED states: %1 (must be 0, 1, or 2)").arg(m_config.qos_led_states));
	}
	
	if (m_config.qos_control_messages < 0 || m_config.qos_control_messages > 2) {
		errors.append(QString("Invalid QoS for control messages: %1 (must be 0, 1, or 2)").arg(m_config.qos_control_messages));
	}
	
	if (m_config.log_level < 0 || m_config.log_level > 3) {
		errors.append(QString("Invalid log level: %1 (must be 0-3)").arg(m_config.log_level));
	}
	
	return errors;
}

MqttConfig::ConnectionConfig MqttConfig::fromYaml(const QString& yaml_content, QString* error) {
	ConnectionConfig config = defaultConfig();
	
	if (yaml_content.isEmpty()) {
		if (error) *error = "Empty YAML content";
		return config;
	}
	
	// Split into lines
	QStringList lines = yaml_content.split('\n', Qt::SkipEmptyParts);
	if (lines.isEmpty()) {
		if (error) *error = "No content in YAML";
		return config;
	}
	
	try {
		int current_line = 0;
		QVariantMap map = parseYamlMap(lines, current_line);
		config = variantMapToConfig(map);
		
		// Validate
		if (!config.isValid()) {
			if (error) *error = "Invalid configuration after parsing";
		}
		
		return config;
		
	} catch (const std::exception& e) {
		if (error) *error = QString("YAML parsing error: %1").arg(e.what());
		return config;
	}
}

QString MqttConfig::toYaml(const ConnectionConfig& config) {
	QVariantMap map = configToVariantMap(config);
	QStringList yaml_lines = serializeYamlMap(map);
	return yaml_lines.join('\n') + '\n';
}

MqttConfig::ConnectionConfig MqttConfig::defaultConfig() {
	ConnectionConfig config;
	
	// Connection settings
	config.broker_host = "localhost";
	config.broker_port = 1883;
	config.username = "";
	config.password = "";
	config.use_tls = false;
	config.ca_cert = "";
	config.client_cert = "";
	config.client_key = "";
	config.auto_connect = false;
	config.keepalive_interval = 60;
	config.reconnect_interval = 5;
	
	// Topic configuration
	config.base_topic = "recording";
	config.use_client_id_in_topic = true;
	
	// Publishing configuration
	config.publish_recording_state = true;
	config.publish_recording_events = true;
	config.publish_led_states = true;
	config.publish_status = true;
	config.publish_keepalive = true;
	
	// Subscription configuration
	config.subscribe_recording_control = true;
	config.subscribe_topic_change = true;
	config.subscribe_button_events = true;
	
	// QoS levels
	config.qos_status = 1;
	config.qos_recording_state = 1;
	config.qos_recording_events = 1;
	config.qos_led_states = 1;
	config.qos_control_messages = 1;
	
	// Retained messages
	config.retain_recording_state = true;
	config.retain_led_states = true;
	config.retain_connection_state = true;
	
	// Logging
	config.log_mqtt_messages = false;
	config.log_level = 1; // warning
	
	return config;
}

QVariant MqttConfig::parseYamlValue(const QString& value_str) {
	QString trimmed = value_str.trimmed();
	
	// Check for null/empty
	if (trimmed.isEmpty() || trimmed == "null" || trimmed == "~") {
		return QVariant();
	}
	
	// Check for boolean
	if (trimmed == "true" || trimmed == "True" || trimmed == "TRUE") {
		return true;
	}
	if (trimmed == "false" || trimmed == "False" || trimmed == "FALSE") {
		return false;
	}
	
	// Check for integer
	bool ok;
	int int_value = trimmed.toInt(&ok);
	if (ok) {
		return int_value;
	}
	
	// Check for float
	double double_value = trimmed.toDouble(&ok);
	if (ok) {
		return double_value;
	}
	
	// Check for quoted string
	if ((trimmed.startsWith('"') && trimmed.endsWith('"')) ||
		(trimmed.startsWith('\'') && trimmed.endsWith('\''))) {
		return trimmed.mid(1, trimmed.length() - 2);
	}
	
	// Plain string
	return trimmed;
}

QString MqttConfig::serializeYamlValue(const QVariant& value) {
	if (value.isNull() || !value.isValid()) {
		return "null";
	}
	
	switch (value.type()) {
		case QVariant::Bool:
			return value.toBool() ? "true" : "false";
		case QVariant::Int:
		case QVariant::UInt:
		case QVariant::LongLong:
		case QVariant::ULongLong:
			return QString::number(value.toInt());
		case QVariant::Double:
			return QString::number(value.toDouble());
		case QVariant::String:
			// Quote strings that contain special characters
			{
				QString str = value.toString();
				if (str.contains(':') || str.contains('#') || str.contains('[') || 
					str.contains(']') || str.contains('{') || str.contains('}') ||
					str.contains(',') || str.contains('&') || str.contains('*') ||
					str.contains('?') || str.contains('|') || str.contains('-') ||
					str.contains('<') || str.contains('>') || str.contains('=') ||
					str.contains('!') || str.contains('%') || str.contains('@') ||
					str.contains('\\')) {
					return "\"" + str.replace('\"', "\\\"") + "\"";
				}
				return str;
			}
		default:
			return value.toString();
	}
	
	// Default fallback
	return value.toString();
}

QVariantMap MqttConfig::parseYamlMap(const QStringList& lines, int& current_line) {
	QVariantMap map;
	
	while (current_line < lines.size()) {
		QString line = lines[current_line];
		
		// Skip comments and empty lines
		if (line.trimmed().isEmpty() || line.trimmed().startsWith('#')) {
			current_line++;
			continue;
		}
		
		// Check indentation level (simple implementation)
		int indent = 0;
		while (indent < line.length() && line[indent].isSpace()) {
			indent++;
		}
		
		// Check for key-value pair
		int colon_pos = line.indexOf(':', indent);
		if (colon_pos > indent) {
			QString key = line.mid(indent, colon_pos - indent).trimmed();
			QString value_str = line.mid(colon_pos + 1).trimmed();
			
			// Parse value
			QVariant value;
			if (value_str.isEmpty()) {
				// Check if next line starts a nested structure
				if (current_line + 1 < lines.size()) {
					QString next_line = lines[current_line + 1];
					int next_indent = 0;
					while (next_indent < next_line.length() && next_line[next_indent].isSpace()) {
						next_indent++;
					}
					
					if (next_indent > indent) {
						// Nested map
						current_line++;
						value = parseYamlMap(lines, current_line);
					} else {
						// Empty value
						value = QVariant();
					}
				} else {
					// Empty value at end of file
					value = QVariant();
				}
			} else {
				// Simple value
				value = parseYamlValue(value_str);
			}
			
			map[key] = value;
			current_line++;
		} else {
			// Not a key-value pair, skip
			current_line++;
		}
	}
	
	return map;
}

QStringList MqttConfig::serializeYamlMap(const QVariantMap& map, int indent) {
	QStringList lines;
	QString indent_str = QString(" ").repeated(indent);
	
	for (auto it = map.begin(); it != map.end(); ++it) {
		const QString& key = it.key();
		const QVariant& value = it.value();
		
		if (value.type() == QVariant::Map) {
			// Nested map
			lines.append(indent_str + key + ":");
			lines.append(serializeYamlMap(value.toMap(), indent + 2));
		} else {
			// Simple value
			lines.append(indent_str + key + ": " + serializeYamlValue(value));
		}
	}
	
	return lines;
}

bool MqttConfig::ensureConfigDirExists(const QString& config_path) {
	QFileInfo file_info(config_path);
	QDir config_dir = file_info.dir();
	
	if (!config_dir.exists()) {
		return config_dir.mkpath(".");
	}
	
	return true;
}

QString MqttConfig::readFileContent(const QString& file_path) {
	QFile file(file_path);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		return QString();
	}
	
	QTextStream stream(&file);
	stream.setCodec("UTF-8");
	return stream.readAll();
}

bool MqttConfig::writeFileContent(const QString& file_path, const QString& content) {
	QFile file(file_path);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
		return false;
	}
	
	QTextStream stream(&file);
	stream.setCodec("UTF-8");
	stream << content;
	
	return stream.status() == QTextStream::Ok;
}

QVariantMap MqttConfig::configToVariantMap(const ConnectionConfig& config) {
	QVariantMap map;
	
	// Connection settings
	map["broker_host"] = config.broker_host;
	map["broker_port"] = config.broker_port;
	if (!config.username.isEmpty()) map["username"] = config.username;
	if (!config.password.isEmpty()) map["password"] = config.password;
	if (config.use_tls) map["use_tls"] = config.use_tls;
	if (!config.ca_cert.isEmpty()) map["ca_cert"] = config.ca_cert;
	if (!config.client_cert.isEmpty()) map["client_cert"] = config.client_cert;
	if (!config.client_key.isEmpty()) map["client_key"] = config.client_key;
	if (config.auto_connect) map["auto_connect"] = config.auto_connect;
	if (config.keepalive_interval != 60) map["keepalive_interval"] = config.keepalive_interval;
	if (config.reconnect_interval != 5) map["reconnect_interval"] = config.reconnect_interval;
	
	// Topic configuration
	if (config.base_topic != "recording") map["base_topic"] = config.base_topic;
	if (!config.use_client_id_in_topic) map["use_client_id_in_topic"] = config.use_client_id_in_topic;
	
	// Publishing configuration
	if (!config.publish_recording_state) map["publish_recording_state"] = config.publish_recording_state;
	if (!config.publish_recording_events) map["publish_recording_events"] = config.publish_recording_events;
	if (!config.publish_led_states) map["publish_led_states"] = config.publish_led_states;
	if (!config.publish_status) map["publish_status"] = config.publish_status;
	if (!config.publish_keepalive) map["publish_keepalive"] = config.publish_keepalive;
	
	// Subscription configuration
	if (!config.subscribe_recording_control) map["subscribe_recording_control"] = config.subscribe_recording_control;
	if (!config.subscribe_topic_change) map["subscribe_topic_change"] = config.subscribe_topic_change;
	if (!config.subscribe_button_events) map["subscribe_button_events"] = config.subscribe_button_events;
	
	// QoS levels
	if (config.qos_status != 1) map["qos_status"] = config.qos_status;
	if (config.qos_recording_state != 1) map["qos_recording_state"] = config.qos_recording_state;
	if (config.qos_recording_events != 1) map["qos_recording_events"] = config.qos_recording_events;
	if (config.qos_led_states != 1) map["qos_led_states"] = config.qos_led_states;
	if (config.qos_control_messages != 1) map["qos_control_messages"] = config.qos_control_messages;
	
	// Retained messages
	if (!config.retain_recording_state) map["retain_recording_state"] = config.retain_recording_state;
	if (!config.retain_led_states) map["retain_led_states"] = config.retain_led_states;
	if (!config.retain_connection_state) map["retain_connection_state"] = config.retain_connection_state;
	
	// Logging
	if (config.log_mqtt_messages) map["log_mqtt_messages"] = config.log_mqtt_messages;
	if (config.log_level != 1) map["log_level"] = config.log_level;
	
	return map;
}

MqttConfig::ConnectionConfig MqttConfig::variantMapToConfig(const QVariantMap& map) {
	ConnectionConfig config = defaultConfig();
	
	// Connection settings
	if (map.contains("broker_host")) config.broker_host = map["broker_host"].toString();
	if (map.contains("broker_port")) config.broker_port = map["broker_port"].toInt();
	if (map.contains("username")) config.username = map["username"].toString();
	if (map.contains("password")) config.password = map["password"].toString();
	if (map.contains("use_tls")) config.use_tls = map["use_tls"].toBool();
	if (map.contains("ca_cert")) config.ca_cert = map["ca_cert"].toString();
	if (map.contains("client_cert")) config.client_cert = map["client_cert"].toString();
	if (map.contains("client_key")) config.client_key = map["client_key"].toString();
	if (map.contains("auto_connect")) config.auto_connect = map["auto_connect"].toBool();
	if (map.contains("keepalive_interval")) config.keepalive_interval = map["keepalive_interval"].toInt();
	if (map.contains("reconnect_interval")) config.reconnect_interval = map["reconnect_interval"].toInt();
	
	// Topic configuration
	if (map.contains("base_topic")) config.base_topic = map["base_topic"].toString();
	if (map.contains("use_client_id_in_topic")) config.use_client_id_in_topic = map["use_client_id_in_topic"].toBool();
	
	// Publishing configuration
	if (map.contains("publish_recording_state")) config.publish_recording_state = map["publish_recording_state"].toBool();
	if (map.contains("publish_recording_events")) config.publish_recording_events = map["publish_recording_events"].toBool();
	if (map.contains("publish_led_states")) config.publish_led_states = map["publish_led_states"].toBool();
	if (map.contains("publish_status")) config.publish_status = map["publish_status"].toBool();
	if (map.contains("publish_keepalive")) config.publish_keepalive = map["publish_keepalive"].toBool();
	
	// Subscription configuration
	if (map.contains("subscribe_recording_control")) config.subscribe_recording_control = map["subscribe_recording_control"].toBool();
	if (map.contains("subscribe_topic_change")) config.subscribe_topic_change = map["subscribe_topic_change"].toBool();
	if (map.contains("subscribe_button_events")) config.subscribe_button_events = map["subscribe_button_events"].toBool();
	
	// QoS levels
	if (map.contains("qos_status")) config.qos_status = map["qos_status"].toInt();
	if (map.contains("qos_recording_state")) config.qos_recording_state = map["qos_recording_state"].toInt();
	if (map.contains("qos_recording_events")) config.qos_recording_events = map["qos_recording_events"].toInt();
	if (map.contains("qos_led_states")) config.qos_led_states = map["qos_led_states"].toInt();
	if (map.contains("qos_control_messages")) config.qos_control_messages = map["qos_control_messages"].toInt();
	
	// Retained messages
	if (map.contains("retain_recording_state")) config.retain_recording_state = map["retain_recording_state"].toBool();
	if (map.contains("retain_led_states")) config.retain_led_states = map["retain_led_states"].toBool();
	if (map.contains("retain_connection_state")) config.retain_connection_state = map["retain_connection_state"].toBool();
	
	// Logging
	if (map.contains("log_mqtt_messages")) config.log_mqtt_messages = map["log_mqtt_messages"].toBool();
	if (map.contains("log_level")) config.log_level = map["log_level"].toInt();
	
	return config;
}
