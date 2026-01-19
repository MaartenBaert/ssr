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

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>

class SSRPanel : public QWidget
{
    Q_OBJECT

public:
    SSRPanel(QWidget* parent = nullptr);
    ~SSRPanel();

    void setRecordingState(bool recording);
    void setConnectionState(bool connected);
    void setStatus(const QString& status);

signals:
    void startRecordingRequested();
    void stopRecordingRequested();
    void toggleRecordingRequested();
    void statusRequested();

private slots:
    void updateTime();

private:
    void setupUi();

private:
    // UI elements
    QPushButton* m_startButton;
    QPushButton* m_stopButton;
    QPushButton* m_toggleButton;
    QPushButton* m_statusButton;

    QLabel* m_statusLabel;
    QLabel* m_timeLabel;
    QLabel* m_connectionLabel;

    QTimer* m_timer;
    qint64 m_recordingStartTime;
    bool m_isRecording;
};
