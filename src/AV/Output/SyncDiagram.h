/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

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

#include "MutexDataPair.h"

class SyncDiagram : public QWidget {
	Q_OBJECT

private:
	struct TimeBlock {
		double m_time_begin, m_time_end;
		QColor m_color;
	};
	struct TimeChannel {
		QString m_name;
		double m_current_time, m_time_shift, m_time_shift_v;
		std::deque<TimeBlock> m_time_blocks;
	};
	struct SharedData {
		std::vector<TimeChannel> m_time_channels;
	};
	typedef MutexDataPair<SharedData>::Lock SharedLock;

private:
	static constexpr int CHANNEL_HEIGHT = 20, CHANNEL_SPACING = 10, MARGIN_RIGHT = 50;
	static constexpr double PIXELS_PER_SECOND = 400.0;

private:
	MutexDataPair<SharedData> m_shared_data;

	int m_height;
	QFont m_font;
	QTimer *m_update_timer;

public:
	SyncDiagram(size_t channels);
	~SyncDiagram();

	// These functions are thread-safe.
	void SetChannelName(size_t channel, const QString& name);
	void SetCurrentTime(size_t channel, double current_time);
	void AddBlock(size_t channel, double time_begin, double time_end, const QColor& color);
	void Update();

public:
	virtual QSize minimumSizeHint() const override { return QSize(200, m_height); }
	virtual QSize sizeHint() const override { return QSize(800, m_height); }

protected:
	virtual void paintEvent(QPaintEvent* event) override;

signals:
	void NeedsUpdate();

private slots:
	void DelayedUpdate();

};
