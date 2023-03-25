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

#include "SyncDiagram.h"

#include "MainWindow.h"

constexpr int SyncDiagram::CHANNEL_HEIGHT, SyncDiagram::CHANNEL_SPACING, SyncDiagram::MARGIN_RIGHT;
constexpr double SyncDiagram::PIXELS_PER_SECOND;

inline double floormod(double x, double y) {
	return x - floor(x / y) * y;
}

SyncDiagram::SyncDiagram(size_t channels) {
	assert(channels > 0);

	{
		SharedLock lock(&m_shared_data);
		lock->m_time_channels.resize(channels);
		for(auto &c : lock->m_time_channels) {
			c.m_name = "";
			c.m_current_time = 0.0;
			c.m_time_shift = std::numeric_limits<double>::max() * 0.5;
			c.m_time_shift_v = 0.0;
		}
	}

	m_height = CHANNEL_SPACING + (CHANNEL_HEIGHT + CHANNEL_SPACING) * channels;

	m_font = QFont("Sans");
	m_font.setPixelSize(12);

	setWindowTitle(tr("Synchronization Diagram") + " - " + MainWindow::WINDOW_CAPTION);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	m_update_timer = new QTimer(this);
	m_update_timer->setSingleShot(true);
	connect(this, SIGNAL(NeedsUpdate()), this, SLOT(DelayedUpdate()), Qt::QueuedConnection);
	connect(m_update_timer, SIGNAL(timeout()), this, SLOT(update()));

	setMinimumSize(minimumSizeHint()); // workaround for Qt bug

}

SyncDiagram::~SyncDiagram() {

}

void SyncDiagram::SetChannelName(size_t channel, const QString& name) {
	SharedLock lock(&m_shared_data);
	assert(channel < lock->m_time_channels.size());
	lock->m_time_channels[channel].m_name = name;
}

void SyncDiagram::SetCurrentTime(size_t channel, double current_time) {
	SharedLock lock(&m_shared_data);
	assert(channel < lock->m_time_channels.size());
	lock->m_time_channels[channel].m_current_time = current_time;
	double time_min = current_time - (double) (width() - MARGIN_RIGHT) / PIXELS_PER_SECOND;
	auto &blocks = lock->m_time_channels[channel].m_time_blocks;
	while(!blocks.empty() && blocks.front().m_time_end < time_min) {
		blocks.pop_front();
	}
}

void SyncDiagram::AddBlock(size_t channel, double time_begin, double time_end, const QColor& color) {
	SharedLock lock(&m_shared_data);
	assert(channel < lock->m_time_channels.size());
	lock->m_time_channels[channel].m_time_blocks.push_back(TimeBlock{time_begin, time_end, color});
}

void SyncDiagram::Update() {
	emit NeedsUpdate();
}

void SyncDiagram::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	QPainter painter(this);
	painter.fillRect(rect(), QColor(255, 255, 255));

	SharedLock lock(&m_shared_data);

	int y = CHANNEL_SPACING;
	for(auto &c : lock->m_time_channels) {

		// calculate time limits
		double time_min = c.m_current_time - (double) (width() - MARGIN_RIGHT) / PIXELS_PER_SECOND;
		double time_max = c.m_current_time + (double) MARGIN_RIGHT / PIXELS_PER_SECOND;
		double ts = lock->m_time_channels[0].m_current_time - c.m_current_time;
		if(fabs(ts - c.m_time_shift) > 2.0) {
			c.m_time_shift = ts;
			c.m_time_shift_v = 0.0;
		} else {
			c.m_time_shift_v += 0.4 * (0.4 * (ts - c.m_time_shift) - 2.0 * c.m_time_shift_v);
			c.m_time_shift += c.m_time_shift_v;
		}
		double pixel_wrap = (double) width();

		// draw blocks
		for(auto &b : c.m_time_blocks) {
			QColor edge = b.m_color.darker(200), fill = b.m_color;
			edge.setAlpha(128);
			fill.setAlpha(64);
			painter.setPen(edge);
			painter.setBrush(fill);
			double x1 = floormod((b.m_time_begin + c.m_time_shift) * (double) PIXELS_PER_SECOND, pixel_wrap);
			double x2 = x1 + (b.m_time_end - b.m_time_begin) * (double) PIXELS_PER_SECOND;
			painter.drawRect(QRectF(QPointF(x1, y), QPointF(x2, y + CHANNEL_HEIGHT)));
		}

		// draw grid lines
		painter.setPen(QColor(0, 0, 0));
		for(double t = ceil(time_min); t <= time_max; t += 1.0) {
			double x = floormod((t + c.m_time_shift) * (double) PIXELS_PER_SECOND, pixel_wrap);
			painter.drawLine(QPointF(x, y - CHANNEL_SPACING / 2),
							 QPointF(x, y + CHANNEL_HEIGHT + CHANNEL_SPACING / 2));
		}

		// draw the current time
		{
			double x = floormod((c.m_current_time + c.m_time_shift) * (double) PIXELS_PER_SECOND, pixel_wrap);
			painter.setPen(QColor(255, 0, 0));
			painter.drawLine(QPointF(x, y - CHANNEL_SPACING / 2),
							 QPointF(x, y + CHANNEL_HEIGHT + CHANNEL_SPACING / 2));
		}

		// draw channel name
		painter.setPen(QColor(0, 0, 0));
		painter.setFont(m_font);
		painter.drawText(10, y, width() - 10, CHANNEL_HEIGHT, Qt::AlignLeft | Qt::AlignVCenter | Qt::TextSingleLine, c.m_name);

		y += CHANNEL_HEIGHT + CHANNEL_SPACING;
	}

}

void SyncDiagram::DelayedUpdate() {
	if(!m_update_timer->isActive())
		m_update_timer->start(50);
}
