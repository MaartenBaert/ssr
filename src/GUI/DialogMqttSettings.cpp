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

#include "DialogMqttSettings.h"
#include "MqttClientInterface.h"
#include "MqttClientSimple.h"
#include "Icons.h"
#include "Dialogs.h"
#include "Logger.h"

#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include <QFileDialog>
#include <QSettings>
#include <QTimer>

DialogMqttSettings::DialogMqttSettings(MqttClientInterface* mqtt_client, QWidget* parent)
	: QDialog(parent),
	  m_mqtt_client(mqtt_client),
	  m_update_timer(nullptr) {
	
	setWindowTitle(tr("MQTT Settings"));
	setWindowIcon(g_icon_ssr);
	setModal(true);
	
	SetupUi();
	LoadSettings();
	UpdateConnectionStatus();
	
	m_update_timer = new QTimer(this);
	connect(m_update_timer, &QTimer::timeout, this, &DialogMqttSettings::OnUpdateTimer);
	m_update_timer->start(1000); // Update every second
}

DialogMqttSettings::~DialogMqttSettings() {
}

void DialogMqttSettings::SetupUi() {
	QVBoxLayout* main_layout = new QVBoxLayout(this);
	
	// Connection settings group
	QGroupBox* groupbox_connection = new QGroupBox(tr("Connection Settings"), this);
	{
		QFormLayout* layout = new QFormLayout(groupbox_connection);
		
		m_edit_broker_host = new QLineEdit(groupbox_connection);
		m_edit_broker_host->setPlaceholderText(tr("localhost"));
		layout->addRow(tr("Broker Host:"), m_edit_broker_host);
		
		m_spinbox_broker_port = new QSpinBox(groupbox_connection);
		m_spinbox_broker_port->setRange(1, 65535);
		m_spinbox_broker_port->setValue(1883);
		layout->addRow(tr("Broker Port:"), m_spinbox_broker_port);
		
		m_checkbox_use_tls = new QCheckBox(tr("Use TLS/SSL"), groupbox_connection);
		layout->addRow(QString(), m_checkbox_use_tls);
		
		m_edit_username = new QLineEdit(groupbox_connection);
		layout->addRow(tr("Username:"), m_edit_username);
		
		m_edit_password = new QLineEdit(groupbox_connection);
		m_edit_password->setEchoMode(QLineEdit::Password);
		m_checkbox_show_password = new QCheckBox(tr("Show password"), groupbox_connection);
		QHBoxLayout* password_layout = new QHBoxLayout();
		password_layout->addWidget(m_edit_password);
		password_layout->addWidget(m_checkbox_show_password);
		layout->addRow(tr("Password:"), password_layout);
		
		connect(m_checkbox_use_tls, SIGNAL(stateChanged(int)), this, SLOT(OnUseTlsChanged(int)));
		connect(m_checkbox_show_password, SIGNAL(stateChanged(int)), this, SLOT(OnShowPasswordChanged(int)));
	}
	main_layout->addWidget(groupbox_connection);
	
	// Certificate settings group (initially hidden)
	m_groupbox_certificates = new QGroupBox(tr("Certificate Settings"), this);
	m_groupbox_certificates->setVisible(false);
	{
		QFormLayout* layout = new QFormLayout(m_groupbox_certificates);
		
		m_edit_ca_cert = new QLineEdit(m_groupbox_certificates);
		m_button_browse_ca_cert = new QPushButton(tr("Browse..."), m_groupbox_certificates);
		QHBoxLayout* ca_cert_layout = new QHBoxLayout();
		ca_cert_layout->addWidget(m_edit_ca_cert);
		ca_cert_layout->addWidget(m_button_browse_ca_cert);
		layout->addRow(tr("CA Certificate:"), ca_cert_layout);
		
		m_edit_client_cert = new QLineEdit(m_groupbox_certificates);
		m_button_browse_client_cert = new QPushButton(tr("Browse..."), m_groupbox_certificates);
		QHBoxLayout* client_cert_layout = new QHBoxLayout();
		client_cert_layout->addWidget(m_edit_client_cert);
		client_cert_layout->addWidget(m_button_browse_client_cert);
		layout->addRow(tr("Client Certificate:"), client_cert_layout);
		
		m_edit_client_key = new QLineEdit(m_groupbox_certificates);
		m_button_browse_client_key = new QPushButton(tr("Browse..."), m_groupbox_certificates);
		QHBoxLayout* client_key_layout = new QHBoxLayout();
		client_key_layout->addWidget(m_edit_client_key);
		client_key_layout->addWidget(m_button_browse_client_key);
		layout->addRow(tr("Client Key:"), client_key_layout);
		
		connect(m_button_browse_ca_cert, SIGNAL(clicked()), this, SLOT(OnBrowseCaCert()));
		connect(m_button_browse_client_cert, SIGNAL(clicked()), this, SLOT(OnBrowseClientCert()));
		connect(m_button_browse_client_key, SIGNAL(clicked()), this, SLOT(OnBrowseClientKey()));
	}
	main_layout->addWidget(m_groupbox_certificates);
	
	// Connection status
	QGroupBox* groupbox_status = new QGroupBox(tr("Connection Status"), this);
	{
		QVBoxLayout* layout = new QVBoxLayout(groupbox_status);
		
		m_label_status = new QLabel(groupbox_status);
		m_label_status->setAlignment(Qt::AlignCenter);
		m_label_status->setStyleSheet("QLabel { font-weight: bold; }");
		layout->addWidget(m_label_status);
		
		QHBoxLayout* button_layout = new QHBoxLayout();
		m_button_connect = new QPushButton(tr("Connect"), groupbox_status);
		m_button_disconnect = new QPushButton(tr("Disconnect"), groupbox_status);
		m_button_test = new QPushButton(tr("Test Connection"), groupbox_status);
		
		button_layout->addWidget(m_button_connect);
		button_layout->addWidget(m_button_disconnect);
		button_layout->addWidget(m_button_test);
		button_layout->addStretch();
		
		layout->addLayout(button_layout);
		
		connect(m_button_connect, SIGNAL(clicked()), this, SLOT(OnConnect()));
		connect(m_button_disconnect, SIGNAL(clicked()), this, SLOT(OnDisconnect()));
		connect(m_button_test, SIGNAL(clicked()), this, SLOT(OnTest()));
	}
	main_layout->addWidget(groupbox_status);
	
	// Dialog buttons
	QHBoxLayout* button_layout = new QHBoxLayout();
	m_button_ok = new QPushButton(tr("OK"), this);
	m_button_cancel = new QPushButton(tr("Cancel"), this);
	
	button_layout->addStretch();
	button_layout->addWidget(m_button_ok);
	button_layout->addWidget(m_button_cancel);
	
	main_layout->addLayout(button_layout);
	
	connect(m_button_ok, SIGNAL(clicked()), this, SLOT(OnAccepted()));
	connect(m_button_cancel, SIGNAL(clicked()), this, SLOT(OnRejected()));
}

void DialogMqttSettings::LoadSettings() {
	if (!m_mqtt_client) return;
	
	// Try to cast to MqttClientSimple to access YAML config
	MqttClientSimple* mqtt_simple = dynamic_cast<MqttClientSimple*>(m_mqtt_client);
	if (mqtt_simple && mqtt_simple->GetConfigManager()) {
		// Load from YAML config
		MqttConfig::ConnectionConfig config = mqtt_simple->GetConfig();
		
		m_edit_broker_host->setText(config.broker_host);
		m_spinbox_broker_port->setValue(config.broker_port);
		m_checkbox_use_tls->setChecked(config.use_tls);
		m_edit_username->setText(config.username);
		m_edit_password->setText(config.password);
		m_edit_ca_cert->setText(config.ca_cert);
		m_edit_client_cert->setText(config.client_cert);
		m_edit_client_key->setText(config.client_key);
		
		// Load additional YAML-only settings if we have UI for them
		// (we would need to add UI elements for these)
	} else {
		// Fall back to legacy QSettings
		QSettings settings;
		settings.beginGroup("MQTT");
		
		m_edit_broker_host->setText(settings.value("broker_host", "localhost").toString());
		m_spinbox_broker_port->setValue(settings.value("broker_port", 1883).toInt());
		m_checkbox_use_tls->setChecked(settings.value("use_tls", false).toBool());
		m_edit_username->setText(settings.value("username", "").toString());
		m_edit_password->setText(settings.value("password", "").toString());
		m_edit_ca_cert->setText(settings.value("ca_cert", "").toString());
		m_edit_client_cert->setText(settings.value("client_cert", "").toString());
		m_edit_client_key->setText(settings.value("client_key", "").toString());
		
		settings.endGroup();
	}
	
	// Update certificate group visibility
	OnUseTlsChanged(m_checkbox_use_tls->isChecked() ? Qt::Checked : Qt::Unchecked);
}

void DialogMqttSettings::SaveSettings() {
	if (!m_mqtt_client) return;
	
	// Try to cast to MqttClientSimple to save to YAML config
	MqttClientSimple* mqtt_simple = dynamic_cast<MqttClientSimple*>(m_mqtt_client);
	if (mqtt_simple && mqtt_simple->GetConfigManager()) {
		// Save to YAML config
		MqttConfig::ConnectionConfig config = mqtt_simple->GetConfig();
		
		// Update config with UI values
		config.broker_host = m_edit_broker_host->text();
		config.broker_port = m_spinbox_broker_port->value();
		config.use_tls = m_checkbox_use_tls->isChecked();
		config.username = m_edit_username->text();
		config.password = m_edit_password->text();
		config.ca_cert = m_edit_ca_cert->text();
		config.client_cert = m_edit_client_cert->text();
		config.client_key = m_edit_client_key->text();
		
		// Apply the updated config
		mqtt_simple->ApplyConfig(config);
		
		// Save to YAML file
		mqtt_simple->SaveConfigToFile();
	} else {
		// Fall back to legacy QSettings
		QSettings settings;
		settings.beginGroup("MQTT");
		
		settings.setValue("broker_host", m_edit_broker_host->text());
		settings.setValue("broker_port", m_spinbox_broker_port->value());
		settings.setValue("use_tls", m_checkbox_use_tls->isChecked());
		settings.setValue("username", m_edit_username->text());
		settings.setValue("password", m_edit_password->text());
		settings.setValue("ca_cert", m_edit_ca_cert->text());
		settings.setValue("client_cert", m_edit_client_cert->text());
		settings.setValue("client_key", m_edit_client_key->text());
		
		settings.endGroup();
	}
}

void DialogMqttSettings::UpdateConnectionStatus() {
	if (!m_mqtt_client) {
		m_label_status->setText(tr("MQTT client not available"));
		m_label_status->setStyleSheet("QLabel { color: red; font-weight: bold; }");
		m_button_connect->setEnabled(false);
		m_button_disconnect->setEnabled(false);
		m_button_test->setEnabled(false);
		return;
	}
	
	if (m_mqtt_client->IsConnected()) {
		m_label_status->setText(tr("Connected"));
		m_label_status->setStyleSheet("QLabel { color: green; font-weight: bold; }");
		m_button_connect->setEnabled(false);
		m_button_disconnect->setEnabled(true);
		m_button_test->setEnabled(true);
	} else if (m_mqtt_client->IsEnabled()) {
		m_label_status->setText(tr("Disconnected (enabled)"));
		m_label_status->setStyleSheet("QLabel { color: orange; font-weight: bold; }");
		m_button_connect->setEnabled(true);
		m_button_disconnect->setEnabled(false);
		m_button_test->setEnabled(true);
	} else {
		m_label_status->setText(tr("Disabled"));
		m_label_status->setStyleSheet("QLabel { color: gray; font-weight: bold; }");
		m_button_connect->setEnabled(true);
		m_button_disconnect->setEnabled(false);
		m_button_test->setEnabled(false);
	}
}

void DialogMqttSettings::BrowseCertificate(QLineEdit* edit, const QString& title, const QString& filter) {
	QString filename = QFileDialog::getOpenFileName(this, title, QString(), filter);
	if (!filename.isEmpty()) {
		edit->setText(filename);
	}
}

void DialogMqttSettings::OnUseTlsChanged(int state) {
	m_groupbox_certificates->setVisible(state == Qt::Checked);
}

void DialogMqttSettings::OnShowPasswordChanged(int state) {
	m_edit_password->setEchoMode(state == Qt::Checked ? QLineEdit::Normal : QLineEdit::Password);
}

void DialogMqttSettings::OnBrowseCaCert() {
	BrowseCertificate(m_edit_ca_cert, tr("Select CA Certificate"), tr("Certificate Files (*.pem *.crt *.cer);;All Files (*)"));
}

void DialogMqttSettings::OnBrowseClientCert() {
	BrowseCertificate(m_edit_client_cert, tr("Select Client Certificate"), tr("Certificate Files (*.pem *.crt *.cer);;All Files (*)"));
}

void DialogMqttSettings::OnBrowseClientKey() {
	BrowseCertificate(m_edit_client_key, tr("Select Client Key"), tr("Key Files (*.pem *.key);;All Files (*)"));
}

void DialogMqttSettings::OnConnect() {
	if (!m_mqtt_client) return;
	
	// Save settings first
	SaveSettings();
	
	// Try to cast to MqttClientSimple to reload YAML config
	MqttClientSimple* mqtt_simple = dynamic_cast<MqttClientSimple*>(m_mqtt_client);
	if (mqtt_simple) {
		// Reload config from YAML file
		mqtt_simple->LoadConfigFromFile();
	} else {
		// Fall back to legacy QSettings
		QSettings settings;
		m_mqtt_client->LoadSettings(&settings);
	}
	
	// Connect
	m_mqtt_client->Connect();
	UpdateConnectionStatus();
}

void DialogMqttSettings::OnDisconnect() {
	if (!m_mqtt_client) return;
	
	m_mqtt_client->Disconnect();
	UpdateConnectionStatus();
}

void DialogMqttSettings::OnTest() {
	if (!m_mqtt_client) return;
	
	// Save settings first
	SaveSettings();
	
	// Try to cast to MqttClientSimple to reload YAML config
	MqttClientSimple* mqtt_simple = dynamic_cast<MqttClientSimple*>(m_mqtt_client);
	if (mqtt_simple) {
		// Reload config from YAML file
		mqtt_simple->LoadConfigFromFile();
	} else {
		// Fall back to legacy QSettings
		QSettings settings;
		m_mqtt_client->LoadSettings(&settings);
	}
	
	// Test connection
	if (m_mqtt_client->IsConnected()) {
		m_mqtt_client->PublishStatus("test");
		MessageBox(QMessageBox::Information, this, tr("MQTT Test"),
				  tr("Test message sent successfully."), BUTTON_OK);
	} else {
		MessageBox(QMessageBox::Warning, this, tr("MQTT Test"),
				  tr("Not connected to MQTT broker. Please connect first."), BUTTON_OK);
	}
}

void DialogMqttSettings::OnUpdateTimer() {
	UpdateConnectionStatus();
}

void DialogMqttSettings::OnAccepted() {
	SaveSettings();
	accept();
}

void DialogMqttSettings::OnRejected() {
	reject();
}