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

#include "ssr_panel.h"

#include <QDateTime>

SSRPanel::SSRPanel(QWidget* parent)
    : QWidget(parent)
    , m_timer(new QTimer(this))
    , m_recordingStartTime(0)
    , m_isRecording(false)
{
    setupUi();

    connect(m_timer, &QTimer::timeout, this, &SSRPanel::updateTime);

    setRecordingState(false);
    setConnectionState(false);
    setStatus("Disconnected");
}

SSRPanel::~SSRPanel()
{
}

void SSRPanel::setupUi()
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Status labels
    m_statusLabel = new QLabel("Status: Unknown", this);
    m_timeLabel = new QLabel("Time: 00:00:00", this);
    m_connectionLabel = new QLabel("Connection: Disconnected", this);

    mainLayout->addWidget(m_statusLabel);
    mainLayout->addWidget(m_timeLabel);
    mainLayout->addWidget(m_connectionLabel);

    // Control buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();

    m_startButton = new QPushButton("Start", this);
    m_stopButton = new QPushButton("Stop", this);
    m_toggleButton = new QPushButton("Toggle", this);
    m_statusButton = new QPushButton("Status", this);

    buttonLayout->addWidget(m_startButton);
    buttonLayout->addWidget(m_stopButton);
    buttonLayout->addWidget(m_toggleButton);
    buttonLayout->addWidget(m_statusButton);

    mainLayout->addLayout(buttonLayout);

    // Connect buttons
    connect(m_startButton, &QPushButton::clicked,
            this, &SSRPanel::startRecordingRequested);
    connect(m_stopButton, &QPushButton::clicked,
            this, &SSRPanel::stopRecordingRequested);
    connect(m_toggleButton, &QPushButton::clicked,
            this, &SSRPanel::toggleRecordingRequested);
    connect(m_statusButton, &QPushButton::clicked,
            this, &SSRPanel::statusRequested);

    setLayout(mainLayout);
}

void SSRPanel::setRecordingState(bool recording)
{
    m_isRecording = recording;

    if(recording) {
        m_startButton->setEnabled(false);
        m_stopButton->setEnabled(true);
        m_toggleButton->setEnabled(true);

        if(m_recordingStartTime == 0) {
            m_recordingStartTime = QDateTime::currentMSecsSinceEpoch();
        }

        if(!m_timer->isActive()) {
            m_timer->start(1000); // Update every second
        }
    } else {
        m_startButton->setEnabled(true);
        m_stopButton->setEnabled(false);
        m_toggleButton->setEnabled(true);

        m_recordingStartTime = 0;
        m_timer->stop();
        updateTime();
    }
}

void SSRPanel::setConnectionState(bool connected)
{
    if(connected) {
        m_connectionLabel->setText("Connection: Connected");
        m_connectionLabel->setStyleSheet("color: green;");

        m_startButton->setEnabled(true);
        m_stopButton->setEnabled(false);
        m_toggleButton->setEnabled(true);
        m_statusButton->setEnabled(true);
    } else {
        m_connectionLabel->setText("Connection: Disconnected");
        m_connectionLabel->setStyleSheet("color: red;");

        m_startButton->setEnabled(false);
        m_stopButton->setEnabled(false);
        m_toggleButton->setEnabled(false);
        m_statusButton->setEnabled(false);
    }
}

void SSRPanel::setStatus(const QString& status)
{
    m_statusLabel->setText("Status: " + status);

    if(status == "idle") {
        m_statusLabel->setStyleSheet("color: blue;");
    } else if(status == "recording") {
        m_statusLabel->setStyleSheet("color: green;");
    } else if(status == "paused") {
        m_statusLabel->setStyleSheet("color: orange;");
    } else if(status == "error") {
        m_statusLabel->setStyleSheet("color: red;");
    } else {
        m_statusLabel->setStyleSheet("color: black;");
    }
}

void SSRPanel::updateTime()
{
    if(m_isRecording && m_recordingStartTime > 0) {
        qint64 elapsed = QDateTime::currentMSecsSinceEpoch() - m_recordingStartTime;
        qint64 seconds = elapsed / 1000;
        qint64 minutes = seconds / 60;
        qint64 hours = minutes / 60;

        QString timeStr = QString("Time: %1:%2:%3")
            .arg(hours, 2, 10, QChar('0'))
            .arg(minutes % 60, 2, 10, QChar('0'))
            .arg(seconds % 60, 2, 10, QChar('0'));

        m_timeLabel->setText(timeStr);
    } else {
        m_timeLabel->setText("Time: 00:00:00");
    }
}
