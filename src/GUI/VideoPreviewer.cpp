/*
Copyright (c) 2012-2014 Maarten Baert <maarten-baert@hotmail.com>

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

#include "VideoPreviewer.h"

#include "Logger.h"
#include "AVWrapper.h"

QSize CalculateScaledSize(QSize in, QSize out) {
	assert(in.width() > 0 && in.height() > 0);
	if(in.width() <= out.width() && in.height() <= out.height())
		return in;
	if(in.width() * out.height() > out.width() * in.height())
		return QSize(out.width(), (out.width() * in.height() + in.width() / 2) / in.width());
	else
		return QSize((out.height() * in.width() + in.height() / 2) / in.height(), out.height());
}

VideoPreviewer::VideoPreviewer(QWidget* parent)
	: QWidget(parent) {

	{
		SharedLock lock(&m_shared_data);
		lock->m_frame_rate = 10;
		lock->m_next_frame_time = SINK_TIMESTAMP_ASAP;
		lock->m_is_visible = false;
		lock->m_source_size = QSize(0, 0);
		lock->m_widget_size = QSize(0, 0);
	}

	setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

	connect(this, SIGNAL(NeedsUpdate()), this, SLOT(update()), Qt::QueuedConnection);

}

VideoPreviewer::~VideoPreviewer() {

	// disconnect
	ConnectVideoSource(NULL);

}

void VideoPreviewer::Reset() {
	SharedLock lock(&m_shared_data);
	lock->m_image_buffer.reset();
	emit NeedsUpdate();
}

void VideoPreviewer::SetFrameRate(unsigned int frame_rate) {
	SharedLock lock(&m_shared_data);
	lock->m_frame_rate = std::max(1u, frame_rate);
}

int64_t VideoPreviewer::GetNextVideoTimestamp() {
	SharedLock lock(&m_shared_data);
	if(!lock->m_is_visible)
		return SINK_TIMESTAMP_NONE;
	if(lock->m_widget_size.width() < 2 || lock->m_widget_size.height() < 2)
		return SINK_TIMESTAMP_NONE;
	return lock->m_next_frame_time;
}

void VideoPreviewer::ReadVideoFrame(unsigned int width, unsigned int height, const uint8_t* data, int stride, PixelFormat format, int64_t timestamp) {
	Q_UNUSED(timestamp);

	QSize image_size;
	{
		SharedLock lock(&m_shared_data);

		// check the timestamp
		if(lock->m_next_frame_time == SINK_TIMESTAMP_ASAP) {
			lock->m_next_frame_time = timestamp + 1000000 / lock->m_frame_rate;
		} else {
			if(timestamp < lock->m_next_frame_time - 1000000 / lock->m_frame_rate)
				return;
			lock->m_next_frame_time = std::max(lock->m_next_frame_time + 1000000 / lock->m_frame_rate, timestamp);
		}

		// don't do anything if the preview window is invisible
		if(!lock->m_is_visible)
			return;

		// check the size (the scaler can't handle sizes below 2)
		if(width < 2 || height < 2 || lock->m_widget_size.width() < 2 || lock->m_widget_size.height() < 2)
			return;

		// calculate the scaled size
		lock->m_source_size = QSize(width, height);
		image_size = CalculateScaledSize(lock->m_source_size, lock->m_widget_size);

	}

	// allocate the image
	int image_stride = grow_align16(image_size.width() * 4);
	std::shared_ptr<TempBuffer<uint8_t> > image_buffer = std::make_shared<TempBuffer<uint8_t> >();
	image_buffer->Alloc(image_stride * image_size.height());
	uint8_t *image_data = image_buffer->GetData();

	// scale the image
	m_fast_scaler.Scale(width, height, format, &data, &stride,
						image_size.width(), image_size.height(), AV_PIX_FMT_BGRA, &image_data, &image_stride);

	// set the alpha channel to 0xff (just to be sure)
	// Some applications (e.g. firefox) generate alpha values that are not 0xff.
	// I'm not sure whether Qt cares about this, apparently Qt 4.8 with the 'native' back-end doesn't,
	// but I'm not sure about the other back-ends.
	/*for(int y = 0; y < image_size.height(); ++y) {
		uint8_t *row = image_data + image_stride * y;
		for(int x = 0; x < image_size.width(); ++x) {
			row[x * 4 + 3] = 0xff; // third byte is alpha because we're little-endian
		}
	}*/

	// store the image
	SharedLock lock(&m_shared_data);
	lock->m_image_buffer = std::move(image_buffer); image_buffer.reset();
	lock->m_image_stride = image_stride;
	lock->m_image_size = image_size;

	emit NeedsUpdate();

}

void VideoPreviewer::showEvent(QShowEvent* event) {
	Q_UNUSED(event);
	SharedLock lock(&m_shared_data);
	lock->m_is_visible = true;
}

void VideoPreviewer::hideEvent(QHideEvent *event) {
	Q_UNUSED(event);
	SharedLock lock(&m_shared_data);
	lock->m_is_visible = false;
}

void VideoPreviewer::resizeEvent(QResizeEvent* event) {
	Q_UNUSED(event);
	SharedLock lock(&m_shared_data);
	lock->m_widget_size = QSize(width() - 2, height() - 2);
}

void VideoPreviewer::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	QPainter painter(this);

	// copy the image data so the lock isn't held while actually drawing the image
	std::shared_ptr<TempBuffer<uint8_t> > image_buffer;
	int image_stride;
	QSize image_size, source_size;
	{
		SharedLock lock(&m_shared_data);
		image_buffer = lock->m_image_buffer; // shared pointer copy is cheap
		image_stride = lock->m_image_stride;
		image_size = lock->m_image_size;
		source_size = lock->m_source_size;
	}

	if(image_buffer != NULL) {

		// create image (data is not copied)
		QImage img(image_buffer->GetData(), image_size.width(), image_size.height(), image_stride, QImage::Format_RGB32);

		// draw the image
		// Scaling is only used if the widget was resized after the image was captured, which is unlikely
		// except when the video is paused. That's good because the quality after Qt's scaling is horrible.
		QSize out_size = CalculateScaledSize(source_size, QSize(width() - 2, height() - 2));
		QPoint out_pos((width() - out_size.width()) / 2, (height() - out_size.height()) / 2);
		QRect out_rect(out_pos, out_size);
		painter.drawImage(out_rect, img);

		// draw the border
		painter.setPen(Qt::black);
		painter.setBrush(Qt::NoBrush);
		painter.drawRect(out_rect.adjusted(-1, -1, 0, 0));

	}

}
