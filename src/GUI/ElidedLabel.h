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

#pragma once
#include "Global.h"

// A label that elides its text when not enough geometry is available to show all of the text.
// Currently only capable of one-line.
class ElidedLabel : public QLabel {
	Q_OBJECT

private:
	Qt::TextElideMode m_elide_mode;
	QString m_cached_elided_text;

public:
	ElidedLabel(QWidget* parent = NULL, Qt::WindowFlags f = Qt::WindowFlags());
	ElidedLabel(const QString& txt, QWidget* parent = NULL, Qt::WindowFlags f = Qt::WindowFlags());
	ElidedLabel(const QString& txt, Qt::TextElideMode elideMode = Qt::ElideRight, QWidget* parent = NULL, Qt::WindowFlags f = Qt::WindowFlags());

public:
	// Set the elide mode used for displaying text.
	inline void setElideMode(Qt::TextElideMode elideMode) {
		m_elide_mode = elideMode;
		updateGeometry();
	}

	// Get the elide mode currently used to display text.
	inline Qt::TextElideMode elideMode() const {
		return m_elide_mode;
	}

public: // QLabel overrides
	void setText(const QString&); // note: not virtual so no polymorphism ...

protected: // QLabel overrides
	virtual void paintEvent(QPaintEvent*) override;
	virtual void resizeEvent(QResizeEvent*) override;

protected:
	// Cache the elided text so as to not recompute it every paint event
	void cacheElidedText(int w);

};
