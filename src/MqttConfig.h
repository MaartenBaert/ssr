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
#include <QMap>
#include <QVariant>
#include <QFile>
#include <QTextStream>
#include <QDir>

class MqttConfig : public QObject {
	Q_OBJECT

public:
	struct ConnectionConfig {
		QString broker_host = "localhost";
		int broker_port = 1883;
		QString username;
		QString password;
		bool use_tls = false;
		QString ca_cert;
		QString client_cert;
		QString client_key;
		bool auto_connect = false;
		int keepalive_interval = 60;
		int reconnect_interval = 5;

		// Topic configuration
		QString base_topic = "recording";
		bool use_client_id_in_topic = true;
		QString topic_root = "/ssr/";
		QString instance_id = "main";
		QString topic_architecture = "legacy"; // legacy|centralized|both

		// Publishing configuration
		bool publish_recording_state = true;
		bool publish_recording_events = true;
		bool publish_led_states = true;
		bool publish_status = true;
		bool publish_keepalive = true;

		// Subscription configuration
		bool subscribe_recording_control = true;
		bool subscribe_topic_change = true;
		bool subscribe_button_events = true;

		// QoS levels
		int qos_status = 1;
		int qos_recording_state = 1;
		int qos_recording_events = 1;
		int qos_led_states = 1;
		int qos_control_messages = 1;
		int qos_status_get = 1;

		// Retained messages
		bool retain_recording_state = true;
		bool retain_led_states = true;
		bool retain_connection_state = true;
		bool retain_full_status = true;

		// Logging
		bool log_mqtt_messages = false;
		int log_level = 1; // 0=error, 1=warning, 2=info, 3=debug

		// New centralized architecture features
		bool publish_full_status = true;
		bool subscribe_status_get = true;

		// Validation
		bool isValid() const {
			return !broker_host.isEmpty() && broker_port > 0 && broker_port <= 65535;
		}
	};

private:
	ConnectionConfig m_config;
	QString m_config_path;
	bool m_config_loaded;
	bool m_config_changed;

public:
	MqttConfig(QObject* parent = nullptr);
	~MqttConfig();

	// Configuration management
	bool loadConfig(const QString& config_path = QString());
	bool saveConfig(const QString& config_path = QString());
	bool hasConfig() const { return m_config_loaded; }
	bool isConfigChanged() const { return m_config_changed; }
	void markConfigChanged() { m_config_changed = true; }

	// Configuration access
	const ConnectionConfig& config() const { return m_config; }
	ConnectionConfig& config() { m_config_changed = true; return m_config; }
	void setConfig(const ConnectionConfig& config) { m_config = config; m_config_changed = true; }

	// Convenience methods
	QString getConfigPath() const { return m_config_path; }
	static QString getDefaultConfigPath();

	// Validation
	bool validateConfig() const;
	QStringList getValidationErrors() const;

	// YAML serialization
	static ConnectionConfig fromYaml(const QString& yaml_content, QString* error = nullptr);
	static QString toYaml(const ConnectionConfig& config);

	// Default configuration
	static ConnectionConfig defaultConfig();
	ConnectionConfig& getConfig() { return m_config; }

private:
	// YAML parsing helpers
	static QVariant parseYamlValue(const QString& value_str);
	static QString serializeYamlValue(const QVariant& value);
	static QVariantMap parseYamlMap(const QStringList& lines, int& current_line);
	static QStringList serializeYamlMap(const QVariantMap& map, int indent = 0);

	// Configuration file helpers
	bool ensureConfigDirExists(const QString& config_path);
	QString readFileContent(const QString& file_path);
	bool writeFileContent(const QString& file_path, const QString& content);

	// Type conversion
	static QVariantMap configToVariantMap(const ConnectionConfig& config);
	static ConnectionConfig variantMapToConfig(const QVariantMap& map);
};
