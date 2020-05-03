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

#include "WidgetRack.h"

static QSize GetWidgetSize(QWidget* widget) {
	QSize size = widget->sizeHint();
	if(!size.isValid())
		size = QSize(0, 0);
	QSize minimumsize = widget->minimumSize();
	if(!minimumsize.isValid())
		minimumsize = widget->minimumSizeHint();
	if(minimumsize.isValid())
		size = size.expandedTo(minimumsize);
	QSize maximumsize = widget->maximumSize();
	if(maximumsize.isValid())
		size = size.boundedTo(maximumsize);
	return size;
}

WidgetRack::WidgetRack(QWidget* parent)
	: QAbstractScrollArea(parent) {

	m_selected_widget = NO_SELECTION;

	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn); // buggy with GTK style, maximumViewportSize() doesn't take the border into account :(
	verticalScrollBar()->setSingleStep(20);

	viewport()->setBackgroundRole(QPalette::Dark);
	viewport()->setAutoFillBackground(true);

	connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this, SLOT(OnFocusChange(QWidget*, QWidget*)));

	UpdateRange();

}

WidgetRack::~WidgetRack() {

}

unsigned int WidgetRack::GetWidgetCount() {
	return m_widgets.size();
}

QWidget* WidgetRack::GetWidget(unsigned int index) {
	assert(index < m_widgets.size());
	return m_widgets[index];
}

unsigned int WidgetRack::GetSelected() {
	return m_selected_widget;
}

void WidgetRack::SetSelected(unsigned int index) {
	assert(index == NO_SELECTION || index < m_widgets.size());
	m_selected_widget = index;
	UpdateSelection();
}

void WidgetRack::AddWidget(unsigned int index, QWidget* widget) {
	assert(index <= m_widgets.size());
	assert(widget->parent() == viewport());

	widget->setAutoFillBackground(true);
	widget->setBackgroundRole(QPalette::Base);
	if(widget->focusPolicy() == Qt::NoFocus)
		widget->setFocusPolicy(Qt::ClickFocus);
	widget->show();

	m_widgets.insert(m_widgets.begin() + index, widget);
	UpdateFocusChain();
	UpdateRange();
	UpdateLayout();

	if(m_selected_widget != NO_SELECTION && m_selected_widget >= index)
		++m_selected_widget;

}

void WidgetRack::RemoveWidget(unsigned int index) {
	assert(index < m_widgets.size());

	delete m_widgets[index];
	m_widgets.erase(m_widgets.begin() + index);
	UpdateFocusChain();
	UpdateRange();
	UpdateLayout();

	if(m_selected_widget != NO_SELECTION) {
		if(m_selected_widget == index) {
			m_selected_widget = NO_SELECTION;
		} else if(m_selected_widget > index) {
			--m_selected_widget;
		}
	}

}

void WidgetRack::MoveWidget(unsigned int from, unsigned int to) {
	assert(from < m_widgets.size());
	assert(to < m_widgets.size());

	QWidget *widget = m_widgets[from];
	m_widgets.erase(m_widgets.begin() + from);
	m_widgets.insert(m_widgets.begin() + to, widget);
	UpdateFocusChain();
	UpdateLayout();

	if(m_selected_widget != NO_SELECTION) {
		if(m_selected_widget == from) {
			m_selected_widget = to;
		} else {
			if(m_selected_widget > from && m_selected_widget <= to)
				--m_selected_widget;
			if(m_selected_widget < from && m_selected_widget >= to)
				++m_selected_widget;
		}
	}

}

void WidgetRack::MakeVisible(QWidget* widget) {
	assert(viewport()->isAncestorOf(widget));
	QRect widget_rect(widget->mapTo(viewport(), QPoint(0, verticalScrollBar()->value())), widget->size());
	QRect visible_rect(QPoint(0, verticalScrollBar()->value()), viewport()->size());
	if(widget_rect.height() > visible_rect.height()) {
		if(widget_rect.top() > visible_rect.top()) {
			verticalScrollBar()->setValue(widget_rect.top());
		} else if(widget_rect.bottom() < visible_rect.bottom()) {
			verticalScrollBar()->setValue(visible_rect.top() + widget_rect.bottom() - visible_rect.bottom());
		}
	} else {
		if(widget_rect.top() < visible_rect.top()) {
			verticalScrollBar()->setValue(widget_rect.top());
		} else if(widget_rect.bottom() > visible_rect.bottom()) {
			verticalScrollBar()->setValue(visible_rect.top() + widget_rect.bottom() - visible_rect.bottom());
		}
	}
}

bool WidgetRack::viewportEvent(QEvent* event) {
	switch(event->type()) {
		case QEvent::LayoutRequest: {
			UpdateRange();
			UpdateLayout();
			event->accept();
			return true;
		}
		default: return QAbstractScrollArea::viewportEvent(event);
	}
}

void WidgetRack::resizeEvent(QResizeEvent* event) {
	Q_UNUSED(event);
	UpdateRange();
	UpdateLayout();
}

void WidgetRack::scrollContentsBy(int dx, int dy) {
	if(dx == 0 && dy == 0)
		return;
	UpdateLayout();
}

bool WidgetRack::focusNextPrevChild(bool next) {
	return QWidget::focusNextPrevChild(next); //TODO// remove?
}

void WidgetRack::UpdateFocusChain() {
	/*
	This algorithm assumes that all direct and indirect childs of widgets in the rack are created right after the widget itself,
	with no non-child widgets in between. It also assumes that the focus policy of widgets won't change after they have been added to the rack.
	If these assumptions are incorrect, the focus chain will probably be messed up, but it won't cause any serious problems.
	There's probably some clever way to do this without an intermediate std::vector,
	but I don't want to depend too much on Qt internals such as the exact implementation of setTabOrder().
	*/
	QWidget *prev = this;
	while(prev->focusPolicy() == Qt::NoFocus) {
		prev = prev->previousInFocusChain();
		if(prev == this)
			break;
	}
	std::vector<QWidget*> focuschain; // keep this outside the loop to reuse memory
	for(unsigned int i = 0; i < m_widgets.size(); ++i) {
		focuschain.clear();
		QWidget *curr = m_widgets[i];
		while(curr != NULL && m_widgets[i]->isAncestorOf(curr)) {
			if(curr->focusPolicy() != Qt::NoFocus) // setTabOrder() won't accept these
				focuschain.push_back(curr);
			curr = curr->nextInFocusChain();
			if(curr == m_widgets[i])
				break;
		}
		for(QWidget *w : focuschain) {
			setTabOrder(prev, w);
			prev = w;
		}
	}
}

void WidgetRack::UpdateRange() {
	int height = 0;
	for(unsigned int i = 0; i < m_widgets.size(); ++i) {
		QSize size = GetWidgetSize(m_widgets[i]);
		height += size.height() + 1;
	}
	verticalScrollBar()->setPageStep(viewport()->height());
	verticalScrollBar()->setRange(0, std::max(0, height - 1 - viewport()->height()));
}

void WidgetRack::UpdateLayout() {
	int y = -verticalScrollBar()->value();
	for(unsigned int i = 0; i < m_widgets.size(); ++i) {
		QSize size = GetWidgetSize(m_widgets[i]);
		m_widgets[i]->setGeometry(0, y, viewport()->width(), size.height());
		y += size.height() + 1;
	}
}

void WidgetRack::UpdateSelection() {
	assert(m_selected_widget < m_widgets.size() || m_selected_widget == NO_SELECTION);
	for(unsigned int i = 0; i < m_widgets.size(); ++i) {
		m_widgets[i]->setBackgroundRole((i == m_selected_widget)? QPalette::Highlight : QPalette::Base);
	}
}

void WidgetRack::OnFocusChange(QWidget* old_widget, QWidget* new_widget) {
	Q_UNUSED(old_widget);
	for(unsigned int i = 0; i < m_widgets.size(); ++i) {
		if(m_widgets[i]->isAncestorOf(new_widget)) {
			SetSelected(i);
			MakeVisible(m_widgets[i]);
			break;
		}
	}
	if(viewport()->isAncestorOf(new_widget)) {
		MakeVisible(new_widget);
	}
}
