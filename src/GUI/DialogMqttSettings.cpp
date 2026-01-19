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
#include <QComboBox>

DialogMqttSettings::DialogMqttSettings(MqttClientInterface* mqtt_client, QWidget* parent)
	: QDialog(parent),
	  m_mqtt_client(mqtt_client),
	  m_update_timer(nullptr) {

	setWindowTitle(tr("MQTT Settings"));
	setWindowIcon(g_icon_ssr);
	setModal(true);

	SetupUi();
	LoadSettings();

	m_update_timer = new QTimer(this);
	connect(m_update_timer, SIGNAL(timeout()), this, SLOT(OnUpdateTimer()));
	m_update_timer->start(1000);

	UpdateConnectionStatus();
}

DialogMqttSettings::~DialogMqttSettings() {
	if (m_update_timer) {
		m_update_timer->stop();
	}
}

void DialogMqttSettings::SetupUi() {
	QVBoxLayout* main_layout = new QVBoxLayout(this);

	// Connection settings group
	QGroupBox* groupbox_connection = new QGroupBox(tr("Connection Settings"), this);
	QFormLayout* connection_layout = new QFormLayout(groupbox_connection);

	m_edit_broker_host = new QLineEdit(this);
	m_spinbox_broker_port = new QSpinBox(this);
	m_spinbox_broker_port->setRange(1, 65535);
	m_spinbox_broker_port->setValue(1883);

	m_checkbox_use_tls = new QCheckBox(tr("Use TLS"), this);
	m_edit_username = new QLineEdit(this);
	m_edit_password = new QLineEdit(this);
	m_edit_password->setEchoMode(QLineEdit::Password);
	m_checkbox_show_password = new QCheckBox(tr("Show password"), this);

	connection_layout->addRow(tr("Broker host:"), m_edit_broker_host);
	connection_layout->addRow(tr("Broker port:"), m_spinbox_broker_port);
	connection_layout->addRow(tr(""), m_checkbox_use_tls);
	connection_layout->addRow(tr("Username:"), m_edit_username);
	connection_layout->addRow(tr("Password:"), m_edit_password);
	connection_layout->addRow(tr(""), m_checkbox_show_password);

	main_layout->addWidget(groupbox_connection);

	// Certificate settings group
	m_groupbox_certificates = new QGroupBox(tr("TLS Certificates"), this);
	QFormLayout* cert_layout = new QFormLayout(m_groupbox_certificates);

	m_edit_ca_cert = new QLineEdit(this);
	m_edit_client_cert = new QLineEdit(this);
	m_edit_client_key = new QLineEdit(this);

	m_button_browse_ca_cert = new QPushButton(tr("Browse..."), this);
	m_button_browse_client_cert = new QPushButton(tr("Browse..."), this);
	m_button_browse_client_key = new QPushButton(tr("Browse..."), this);

	QHBoxLayout* ca_cert_layout = new QHBoxLayout();
	ca_cert_layout->addWidget(m_edit_ca_cert);
	ca_cert_layout->addWidget(m_button_browse_ca_cert);

	QHBoxLayout* client_cert_layout = new QHBoxLayout();
	client_cert_layout->addWidget(m_edit_client_cert);
	client_cert_layout->addWidget(m_button_browse_client_cert);

	QHBoxLayout* client_key_layout = new QHBoxLayout();
	client_key_layout->addWidget(m_edit_client_key);
	client_key_layout->addWidget(m_button_browse_client_key);

	cert_layout->addRow(tr("CA certificate:"), ca_cert_layout);
	cert_layout->addRow(tr("Client certificate:"), client_cert_layout);
	cert_layout->addRow(tr("Client key:"), client_key_layout);

	main_layout->addWidget(m_groupbox_certificates);

	// Topic configuration group
	QGroupBox* groupbox_topics = new QGroupBox(tr("Topic Configuration"), this);
	QFormLayout* topics_layout = new QFormLayout(groupbox_topics);

	QLineEdit* edit_topic_root = new QLineEdit(this);
	edit_topic_root->setText("/ssr/");
	edit_topic_root->setObjectName("edit_topic_root");

	QLineEdit* edit_instance_id = new QLineEdit(this);
	edit_instance_id->setText("main");
	edit_instance_id->setObjectName("edit_instance_id");

	topics_layout->addRow(tr("Topic root:"), edit_topic_root);
	topics_layout->addRow(tr("Instance ID:"), edit_instance_id);

	main_layout->addWidget(groupbox_topics);

	// Connection status
	QGroupBox* groupbox_status = new QGroupBox(tr("Connection Status"), this);
	QVBoxLayout* status_layout = new QVBoxLayout(groupbox_status);

	m_label_status = new QLabel(tr("Not connected"), this);
	m_button_connect = new QPushButton(tr("Connect"), this);
	m_button_disconnect = new QPushButton(tr("Disconnect"), this);
	m_button_disconnect->setEnabled(false);

	QHBoxLayout* button_layout = new QHBoxLayout();
	button_layout->addWidget(m_button_connect);
	button_layout->addWidget(m_button_disconnect);
	button_layout->addStretch();

	status_layout->addWidget(m_label_status);
	status_layout->addLayout(button_layout);

	main_layout->addWidget(groupbox_status);

	// Test button
	m_button_test = new QPushButton(tr("Test Connection"), this);
	main_layout->addWidget(m_button_test);

	// Dialog buttons
	QHBoxLayout* dialog_buttons = new QHBoxLayout();
	m_button_ok = new QPushButton(tr("OK"), this);
	m_button_cancel = new QPushButton(tr("Cancel"), this);

	dialog_buttons->addStretch();
	dialog_buttons->addWidget(m_button_ok);
	dialog_buttons->addWidget(m_button_cancel);

	main_layout->addLayout(dialog_buttons);

	// Connect signals
	connect(m_checkbox_use_tls, SIGNAL(stateChanged(int)), this, SLOT(OnUseTlsChanged(int)));
	connect(m_checkbox_show_password, SIGNAL(stateChanged(int)), this, SLOT(OnShowPasswordChanged(int)));
	connect(m_button_browse_ca_cert, SIGNAL(clicked()), this, SLOT(OnBrowseCaCert()));
	connect(m_button_browse_client_cert, SIGNAL(clicked()), this, SLOT(OnBrowseClientCert()));
	connect(m_button_browse_client_key, SIGNAL(clicked()), this, SLOT(OnBrowseClientKey()));
	connect(m_button_connect, SIGNAL(clicked()), this, SLOT(OnConnect()));
	connect(m_button_disconnect, SIGNAL(clicked()), this, SLOT(OnDisconnect()));
	connect(m_button_test, SIGNAL(clicked()), this, SLOT(OnTest()));
	connect(m_button_ok, SIGNAL(clicked()), this, SLOT(OnAccepted()));
	connect(m_button_cancel, SIGNAL(clicked()), this, SLOT(OnRejected()));

	// Initial state
	OnUseTlsChanged(m_checkbox_use_tls->isChecked() ? Qt::Checked : Qt::Unchecked);
	OnShowPasswordChanged(m_checkbox_show_password->isChecked() ? Qt::Checked : Qt::Unchecked);
}

void DialogMqttSettings::LoadSettings() {
	if (!m_mqtt_client) return;

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

	// Load new topic settings
	QComboBox* combo_topic_architecture = findChild<QComboBox*>("combo_topic_architecture");
	if (combo_topic_architecture) {
		QString architecture = settings.value("topic_architecture", "legacy").toString();
		int index = combo_topic_architecture->findData(architecture);
		if (index >= 0) {
			combo_topic_architecture->setCurrentIndex(index);
		}
	}

	QLineEdit* edit_topic_root = findChild<QLineEdit*>("edit_topic_root");
	if (edit_topic_root) {
		edit_topic_root->setText(settings.value("topic_root", "/ssr/").toString());
	}

	QLineEdit* edit_instance_id = findChild<QLineEdit*>("edit_instance_id");
	if (edit_instance_id) {
		edit_instance_id->setText(settings.value("instance_id", "main").toString());
	}

	settings.endGroup();
}

void DialogMqttSettings::SaveSettings() {
	if (!m_mqtt_client) return;

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

	// Save new topic settings
	QComboBox* combo_topic_architecture = findChild<QComboBox*>("combo_topic_architecture");
	if (combo_topic_architecture) {
		settings.setValue("topic_architecture", combo_topic_architecture->currentData().toString());
	}

	QLineEdit* edit_topic_root = findChild<QLineEdit*>("edit_topic_root");
	if (edit_topic_root) {
		settings.setValue("topic_root", edit_topic_root->text());
	}

	QLineEdit* edit_instance_id = findChild<QLineEdit*>("edit_instance_id");
	if (edit_instance_id) {
		settings.setValue("instance_id", edit_instance_id->text());
	}

	settings.endGroup();

	// Reload settings into MQTT client
	m_mqtt_client->LoadSettings(&settings);
}

void DialogMqttSettings::UpdateConnectionStatus() {
	if (!m_mqtt_client) {
		m_label_status->setText(tr("MQTT client not available"));
		m_button_connect->setEnabled(false);
		m_button_disconnect->setEnabled(false);
		return;
	}

	if (m_mqtt_client->IsConnected()) {
		m_label_status->setText(tr("Connected"));
		m_button_connect->setEnabled(false);
		m_button_disconnect->setEnabled(true);
	} else {
		m_label_status->setText(tr("Disconnected"));
		m_button_connect->setEnabled(true);
		m_button_disconnect->setEnabled(false);
	}
}

void DialogMqttSettings::BrowseCertificate(QLineEdit* edit, const QString& title, const QString& filter) {
	QString filename = QFileDialog::getOpenFileName(this, title, QString(), filter);
	if (!filename.isEmpty()) {
		edit->setText(filename);
	}
}

void DialogMqttSettings::OnUseTlsChanged(int state) {
	bool use_tls = (state == Qt::Checked);
	m_groupbox_certificates->setVisible(use_tls);
}

void DialogMqttSettings::OnShowPasswordChanged(int state) {
	bool show = (state == Qt::Checked);
	m_edit_password->setEchoMode(show ? QLineEdit::Normal : QLineEdit::Password);
}

void DialogMqttSettings::OnBrowseCaCert() {
	BrowseCertificate(m_edit_ca_cert, tr("Select CA Certificate"), tr("Certificate files (*.pem *.crt *.cer);;All files (*)"));
}

void DialogMqttSettings::OnBrowseClientCert() {
	BrowseCertificate(m_edit_client_cert, tr("Select Client Certificate"), tr("Certificate files (*.pem *.crt *.cer);;All files (*)"));
}

void DialogMqttSettings::OnBrowseClientKey() {
	BrowseCertificate(m_edit_client_key, tr("Select Client Key"), tr("Key files (*.pem *.key);;All files (*)"));
}

void DialogMqttSettings::OnConnect() {
	if (!m_mqtt_client) return;

	SaveSettings();
	m_mqtt_client->Connect();
}

void DialogMqttSettings::OnDisconnect() {
	if (!m_mqtt_client) return;

	m_mqtt_client->Disconnect();
}

void DialogMqttSettings::OnTest() {
	if (!m_mqtt_client) return;

	SaveSettings();

	bool was_connected = m_mqtt_client->IsConnected();
	if (!was_connected) {
		m_mqtt_client->Connect();
		// In a real implementation, we would wait for connection
		// and show a message box with the result
		Logger::LogInfo("[MQTT] Test connection initiated");
	} else {
		Logger::LogInfo("[MQTT] Already connected");
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
