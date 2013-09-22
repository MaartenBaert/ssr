/*
Copyright (c) 2012-2013 Maarten Baert <maarten-baert@hotmail.com>

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

SyncDiagram::SyncDiagram(size_t channels) {

	m_time_channels.resize(channels);
	for(auto &c : m_time_channels) {
		c.m_name = "";
		c.m_current_time = 0.0;
	}

	m_font = QFont("Sans");
	m_font.setPixelSize(14);

	setWindowTitle("Sync Diagram - " + MainWindow::WINDOW_CAPTION);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	connect(this, SIGNAL(NeedsUpdate()), this, SLOT(update()), Qt::QueuedConnection);

	setMinimumSize(minimumSizeHint()); // workaround for Qt bug

}

SyncDiagram::~SyncDiagram() {

}

void SyncDiagram::SetChannelName(size_t channel, const QString& name) {
	Q_ASSERT(channel < m_time_channels.size());
	m_time_channels[channel].m_name = name;
}

void SyncDiagram::SetCurrentTime(size_t channel, double current_time) {
	Q_ASSERT(channel < m_time_channels.size());
	m_time_channels[channel].m_current_time = current_time;
	double time_min = current_time - (double) (width() - MARGIN_RIGHT) / PIXELS_PER_SECOND;
	auto &blocks = m_time_channels[channel].m_time_blocks;
	while(!blocks.empty() && blocks.front().m_time_end < time_min) {
		blocks.pop_front();
	}
}

void SyncDiagram::AddBlock(size_t channel, double time_begin, double time_end, const QColor& color) {
	Q_ASSERT(channel < m_time_channels.size());
	m_time_channels[channel].m_time_blocks.push_back(TimeBlock{time_begin, time_end, color});
}

void SyncDiagram::Update() {
	emit NeedsUpdate();
}

void SyncDiagram::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	QPainter painter(this);
	painter.fillRect(rect(), QColor(255, 255, 255));

	int y = CHANNEL_SPACING;
	for(auto &c : m_time_channels) {

		// calculate time limits
		double time_min = c.m_current_time - (double) (width() - MARGIN_RIGHT) / PIXELS_PER_SECOND;
		double time_max = c.m_current_time + (double) MARGIN_RIGHT / PIXELS_PER_SECOND;

		// draw blocks
		for(auto &b : c.m_time_blocks) {
			QColor edge = b.m_color.darker(200), fill = b.m_color;
			edge.setAlpha(128);
			fill.setAlpha(64);
			painter.setPen(edge);
			painter.setBrush(fill);
			double x1 = (b.m_time_begin - time_min) * (double) PIXELS_PER_SECOND;
			double x2 = (b.m_time_end - time_min) * (double) PIXELS_PER_SECOND;
			painter.drawRect(QRectF(QPointF(x1, y), QPointF(x2, y + CHANNEL_HEIGHT)));
		}

		// draw grid lines
		painter.setPen(QColor(0, 0, 0));
		for(double t = ceil(time_min); t <= time_max; t += 1.0) {
			double x = (t - time_min) * (double) PIXELS_PER_SECOND;
			painter.drawLine(QPointF(x, y - CHANNEL_SPACING / 2),
							 QPointF(x, y + CHANNEL_HEIGHT + CHANNEL_SPACING / 2));
		}

		// draw the current time
		painter.setPen(QColor(255, 0, 0));
		painter.drawLine(QPointF(width() - MARGIN_RIGHT, y - CHANNEL_SPACING / 2),
						 QPointF(width() - MARGIN_RIGHT, y + CHANNEL_HEIGHT + CHANNEL_SPACING / 2));

		// draw channel name
		painter.setPen(QColor(0, 0, 0));
		painter.setFont(m_font);
		painter.drawText(10, y, width() - 10, CHANNEL_HEIGHT, Qt::AlignLeft | Qt::AlignVCenter | Qt::TextSingleLine, c.m_name);

		y += CHANNEL_HEIGHT + CHANNEL_SPACING;
	}

}
