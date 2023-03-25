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

class WidgetRack : public QAbstractScrollArea {
	Q_OBJECT

public:
	static constexpr unsigned int NO_SELECTION = (unsigned int) -1;

private:
	std::vector<QWidget*> m_widgets;
	unsigned int m_selected_widget;

public:
	WidgetRack(QWidget* parent = NULL);
	~WidgetRack();

	unsigned int GetWidgetCount();
	QWidget* GetWidget(unsigned int index);

	unsigned int GetSelected();
	void SetSelected(unsigned int index);

	void AddWidget(unsigned int index, QWidget* widget);
	void RemoveWidget(unsigned int index);
	void MoveWidget(unsigned int from, unsigned int to);

	void MakeVisible(QWidget* widget);

protected:
	virtual bool viewportEvent(QEvent* event) override;
	virtual void resizeEvent(QResizeEvent* event) override;
	virtual void scrollContentsBy(int dx, int dy) override;
	virtual bool focusNextPrevChild(bool next) override;

private:
	void UpdateFocusChain();
	void UpdateRange();
	void UpdateLayout();
	void UpdateSelection();

private slots:
	void OnFocusChange(QWidget* old_widget, QWidget* new_widget);

};
