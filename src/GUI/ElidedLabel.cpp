/*
Created by Jason Gedge. Code is in the public domain.
http://gedgedev.blogspot.be/2010/12/elided-labels-in-qt.html
*/

#include "ElidedLabel.h"

#include <QDebug>
#include <QPainter>
#include <QResizeEvent>

//---------------------------------------------------------------------

ElidedLabel::ElidedLabel(QWidget *parent, Qt::WindowFlags f)
	: QLabel(parent, f)
	, elideMode_(Qt::ElideRight)
{
	setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
}

ElidedLabel::ElidedLabel(const QString &txt, QWidget *parent, Qt::WindowFlags f)
	: QLabel(txt, parent, f)
	, elideMode_(Qt::ElideRight)
{
	setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
}

ElidedLabel::ElidedLabel(const QString &txt,
						 Qt::TextElideMode elideMode,
						 QWidget *parent,
						 Qt::WindowFlags f)
	: QLabel(txt, parent, f)
	, elideMode_(elideMode)
{
	setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
}

//---------------------------------------------------------------------

void ElidedLabel::setText(const QString &txt) {
	QLabel::setText(txt);
	cacheElidedText(geometry().width());
	setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
}

//---------------------------------------------------------------------

void ElidedLabel::cacheElidedText(int w) {
	cachedElidedText = fontMetrics().elidedText(text(), elideMode_, w, Qt::TextShowMnemonic);
}

//---------------------------------------------------------------------

void ElidedLabel::resizeEvent(QResizeEvent *e) {
	QLabel::resizeEvent(e);
	cacheElidedText(e->size().width());
}

//---------------------------------------------------------------------

void ElidedLabel::paintEvent(QPaintEvent *e) {
	if(elideMode_ == Qt::ElideNone) {
		QLabel::paintEvent(e);
	} else {
		QPainter p(this);
		p.drawText(0, 0,
				   geometry().width(),
				   geometry().height(),
				   alignment(),
				   cachedElidedText);
	}
}

//---------------------------------------------------------------------
