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
#include <QSettings>

class MqttClientInterface {

public:
	virtual ~MqttClientInterface() = default;

	// Configuration
	virtual void LoadSettings(QSettings* settings) = 0;
	virtual void SaveSettings(QSettings* settings) = 0;

	// Connection management
	virtual bool IsEnabled() const = 0;
	virtual bool IsConnected() const = 0;
	virtual void Connect() = 0;
	virtual void Disconnect() = 0;

	// Publishing
	virtual void PublishStatus(const QString& status, const QString& session_id = QString(), const QString& topic = QString()) = 0;
	virtual void PublishRecordingState(bool recording) = 0;
	virtual void PublishRecordingEvent(const QString& event, const QString& session_id = QString(), const QString& topic = QString()) = 0;
	virtual void PublishLedState(const QString& led, bool state) = 0;
	virtual void PublishError(const QString& error) = 0;
	virtual void PublishFullStatus(bool recording, const QString& session_id = QString(), const QString& topic = QString()) = 0;

signals:
	void RecordingStartRequested();
	void RecordingStopRequested();
	void RecordingToggleRequested();
	void TopicChangeRequested(const QString& topic);
	void ButtonRecordingPressed();
	void ButtonRecordingReleased();
	void ButtonOnAirPressed();
	void ButtonOnAirReleased();
	void ConnectionStateChanged(bool connected);


};