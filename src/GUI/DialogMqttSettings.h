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
#include "Global.h"

#include "MqttClientInterface.h"

class DialogMqttSettings : public QDialog {
	Q_OBJECT

private:
	MqttClientInterface* m_mqtt_client;
	
	// Connection settings
	QLineEdit* m_edit_broker_host;
	QSpinBox* m_spinbox_broker_port;
	QCheckBox* m_checkbox_use_tls;
	QLineEdit* m_edit_username;
	QLineEdit* m_edit_password;
	QCheckBox* m_checkbox_show_password;
	
	// Certificate settings
	QGroupBox* m_groupbox_certificates;
	QLineEdit* m_edit_ca_cert;
	QLineEdit* m_edit_client_cert;
	QLineEdit* m_edit_client_key;
	QPushButton* m_button_browse_ca_cert;
	QPushButton* m_button_browse_client_cert;
	QPushButton* m_button_browse_client_key;
	
	// Connection status
	QLabel* m_label_status;
	QPushButton* m_button_connect;
	QPushButton* m_button_disconnect;
	
	// Test connection
	QPushButton* m_button_test;
	
	// Dialog buttons
	QPushButton* m_button_ok;
	QPushButton* m_button_cancel;
	
	QTimer* m_update_timer;

public:
	DialogMqttSettings(MqttClientInterface* mqtt_client, QWidget* parent = nullptr);
	~DialogMqttSettings();
	
	void LoadSettings();
	void SaveSettings();
	
	void UpdateConnectionStatus();

private:
	void SetupUi();
	void BrowseCertificate(QLineEdit* edit, const QString& title, const QString& filter);
	
private slots:
	void OnUseTlsChanged(int state);
	void OnShowPasswordChanged(int state);
	void OnBrowseCaCert();
	void OnBrowseClientCert();
	void OnBrowseClientKey();
	void OnConnect();
	void OnDisconnect();
	void OnTest();
	void OnUpdateTimer();
	void OnAccepted();
	void OnRejected();

};
