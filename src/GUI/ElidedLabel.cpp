/*
Copyright (c) 2012-2020 Maarten Baert <maarten-baert@hotmail.com>

Original code written by Jason Gedge and placed in the public domain.
http://gedgedev.blogspot.be/2010/12/elided-labels-in-qt.html
This is a slightly modified version.

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

#include "ElidedLabel.h"

#include <QPainter>
#include <QResizeEvent>

ElidedLabel::ElidedLabel(QWidget* parent, Qt::WindowFlags f)
	: QLabel(parent, f), m_elide_mode(Qt::ElideRight) {
	setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
}

ElidedLabel::ElidedLabel(const QString& txt, QWidget* parent, Qt::WindowFlags f)
	: QLabel(txt, parent, f), m_elide_mode(Qt::ElideRight) {
	setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
}

ElidedLabel::ElidedLabel(const QString& txt, Qt::TextElideMode elideMode, QWidget* parent, Qt::WindowFlags f)
	: QLabel(txt, parent, f), m_elide_mode(elideMode) {
	setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
}

void ElidedLabel::setText(const QString& txt) {
	QLabel::setText(txt);
	cacheElidedText(geometry().width());
	setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
}

void ElidedLabel::cacheElidedText(int w) {
	m_cached_elided_text = fontMetrics().elidedText(text(), m_elide_mode, w, (buddy() == NULL)? 0 : Qt::TextShowMnemonic);
}

void ElidedLabel::resizeEvent(QResizeEvent* e) {
	QLabel::resizeEvent(e);
	cacheElidedText(e->size().width());
}

void ElidedLabel::paintEvent(QPaintEvent* e) {
	if(m_elide_mode == Qt::ElideNone) {
		QLabel::paintEvent(e);
	} else {
		QPainter p(this);
		p.drawText(0, 0, geometry().width(), geometry().height(),
				   QStyle::visualAlignment(text().isRightToLeft()? Qt::RightToLeft : Qt::LeftToRight, alignment()) | ((buddy() == NULL)? 0 : Qt::TextShowMnemonic),
				   m_cached_elided_text);
	}
}
