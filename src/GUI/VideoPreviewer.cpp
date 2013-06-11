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

#include "Global.h"
#include "VideoPreviewer.h"

#include "Logger.h"

QSize CalculateScaledSize(QSize in, QSize out) {
	if(in.width() <= out.width() && in.height() <= out.height())
		return in;
	if(in.width() * out.height() > out.width() * in.height())
		return QSize(out.width(), (out.width() * in.height() + in.width() / 2) / in.width());
	else
		return QSize((out.height() * in.width() + in.height() / 2) / in.height(), out.height());
}

VideoPreviewer::VideoPreviewer(QWidget* parent)
	: QWidget(parent) {

	m_sws_context = NULL;

	m_should_repaint = false;

	{
		SharedLock lock(&m_shared_data);
		lock->m_next_frame_time = hrt_time_micro();
		lock->m_size = QSize(0, 0);
		lock->m_frame_rate = 10;
	}

	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

}

VideoPreviewer::~VideoPreviewer() {
	if(m_sws_context != NULL) {
		sws_freeContext(m_sws_context);
		m_sws_context = NULL;
	}
}

void VideoPreviewer::Reset() {
	SharedLock lock(&m_shared_data);
	lock->m_image = QImage();
	m_should_repaint = true;
}

void VideoPreviewer::SetFrameRate(unsigned int frame_rate) {
	SharedLock lock(&m_shared_data);
	lock->m_frame_rate = std::max(1u, frame_rate);
}

void VideoPreviewer::ReadVideoFrame(unsigned int width, unsigned int height, uint8_t* data, int stride, PixelFormat format, int64_t timestamp) {
	Q_UNUSED(timestamp);
	SharedLock lock(&m_shared_data);

	// check the size
	if(width < 2 || height < 2 || lock->m_size.width() < 2 || lock->m_size.height() < 2)
		return;

	// check the time (the timestamp is not used, everything is displayed immediately because there's no synchronization anyway)
	int64_t time = hrt_time_micro();
	if(time < lock->m_next_frame_time)
		return;
	lock->m_next_frame_time = std::max(lock->m_next_frame_time + 1000000 / lock->m_frame_rate, time);

	// calculate the scaled size
	QSize image_size = CalculateScaledSize(QSize(width, height), lock->m_size);

	// allocate the image
	if(lock->m_image.size() != image_size) {
		lock->m_image = QImage(image_size, QImage::Format_RGB32);
	}

	// get sws context
	m_sws_context = sws_getCachedContext(m_sws_context,
										 width, height, format,
										 image_size.width(), image_size.height(), PIX_FMT_BGRA,
										 SWS_BILINEAR, NULL, NULL, NULL);
	if(m_sws_context == NULL) {
		Logger::LogError("[VideoPreviewer::ReadFrame] Error: Can't get swscale context!");
		throw LibavException();
	}

	// scale the image
	uint8_t *out_data = lock->m_image.bits();
	int out_stride = lock->m_image.bytesPerLine();
	sws_scale(m_sws_context, &data, &stride, 0, height, &out_data, &out_stride);

	// set the alpha channel to 0xff (just to be sure)
	// Some applications (e.g. firefox) generate alpha values that are not 0xff.
	// I'm not sure whether Qt cares about this, apparently Qt 4.8 with the 'native' back-end doesn't,
	// but I'm not sure about the other back-ends.
	for(int y = 0; y < image_size.height(); ++y) {
		uint8_t *row = lock->m_image.scanLine(y);
		for(int x = 0; x < image_size.width(); ++x) {
			row[x * 4 + 3] = 0xff; // third byte is alpha because we're little-endian
		}
	}

	m_should_repaint = true;

}

void VideoPreviewer::UpdateIfNeeded() {
	if(m_should_repaint) {
		update();
	}
}

void VideoPreviewer::resizeEvent(QResizeEvent* event) {
	Q_UNUSED(event);
	SharedLock lock(&m_shared_data);

	lock->m_size = QSize(width() - 2, height() - 2);

}

void VideoPreviewer::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	SharedLock lock(&m_shared_data);
	QPainter painter(this);
	QImage &img = lock->m_image;

	if(img.isNull()) {

		painter.setPen(QApplication::palette().text().color());
		painter.setFont(QFont("Sans", 10));
		painter.drawText(0, 0, width(), height(), Qt::AlignHCenter | Qt::AlignVCenter, "(recording not started)");

	} else {

		// draw the image
		// Scaling is only used if the widget was resized after the image was captured, which is unlikely
		// except when the video is paused. That's good because the quality after Qt's scaling is horrible.
		QSize out_size = CalculateScaledSize(img.size(), lock->m_size);
		QPoint out_pos((width() - out_size.width()) / 2, (height() - out_size.height()) / 2);
		QRect out_rect(out_pos, out_size);
		painter.drawImage(out_rect, img);

		// draw the border
		painter.setPen(Qt::black);
		painter.setBrush(Qt::NoBrush);
		painter.drawRect(out_rect.adjusted(-1, -1, 0, 0));

	}
	m_should_repaint = false;

}
