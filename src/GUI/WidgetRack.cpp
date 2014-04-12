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

const unsigned int WidgetRack::NO_SELECTION = (unsigned int) -1;

WidgetRack::WidgetRack(QWidget* parent)
	: QWidget(parent) {

	m_selected_widget = NO_SELECTION;

	setBackgroundRole(QPalette::Dark);
	setAutoFillBackground(true);
	setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

	/*m_layout = new QBoxLayout(direction, this);
	m_layout->setMargin(0);
	m_layout->setSpacing(1);
	m_layout->addStretch();*/

	connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this, SLOT(OnFocusChange(QWidget*, QWidget*)));

	UpdateSizeHint();

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
	m_selected_widget = index;
	UpdateSelection();
}

void WidgetRack::AddWidget(unsigned int index, QWidget* widget) {
	assert(index <= m_widgets.size());
	assert(widget->parent() == this);

	widget->setAutoFillBackground(true);
	widget->setBackgroundRole(QPalette::Base);
	if(widget->focusPolicy() == Qt::NoFocus)
		widget->setFocusPolicy(Qt::ClickFocus);
	widget->show();

	m_widgets.insert(m_widgets.begin() + index, widget);
	UpdateFocusChain();
	UpdateSizeHint();
	UpdateLayout();

	if(m_selected_widget != NO_SELECTION && index <= m_selected_widget)
		++m_selected_widget;

}

void WidgetRack::RemoveWidget(unsigned int index) {
	assert(index < m_widgets.size());

	delete m_widgets[index];
	m_widgets.erase(m_widgets.begin() + index);
	UpdateFocusChain();
	UpdateSizeHint();
	UpdateLayout();

	if(m_selected_widget != NO_SELECTION) {
		if(m_selected_widget > index) {
			--m_selected_widget;
		} else if(m_selected_widget >= m_widgets.size()) {
			m_selected_widget = (m_widgets.size() == 0)? NO_SELECTION : m_widgets.size() - 1;
			UpdateSelection();
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

QSize WidgetRack::sizeHint() const {
	return m_size_hint;
}

void WidgetRack::resizeEvent(QResizeEvent* event) {
	Q_UNUSED(event);
	UpdateLayout();
}

bool WidgetRack::event(QEvent* event) {
	if(event->type() == QEvent::LayoutRequest) {
		qDebug() << "LayoutRequest";
		UpdateSizeHint();
		UpdateLayout();
		event->accept();
		return true;
	}
	return QWidget::event(event);
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

void WidgetRack::UpdateSizeHint() {
	int width = 0, height = 0;
	for(unsigned int i = 0; i < m_widgets.size(); ++i) {
		QSize size = m_widgets[i]->sizeHint();
		if(!size.isValid())
			size = QSize(0, 0);
		QSize minimumsize = m_widgets[i]->minimumSize();
		if(!minimumsize.isValid())
			minimumsize = m_widgets[i]->minimumSizeHint();
		if(minimumsize.isValid())
			size.expandedTo(minimumsize);
		if(size.width() > width)
			width = size.width();
		height += size.height() + 1;
	}
	qDebug() << "sizeHint =" << QSize(width, std::max(height - 1, 0));
	QSize size_hint(width, std::max(height - 1, 0));
	if(size_hint != m_size_hint) {
		m_size_hint = size_hint;
		updateGeometry();
	}
}

void WidgetRack::UpdateLayout() {
	int y = 0;
	for(unsigned int i = 0; i < m_widgets.size(); ++i) {
		QSize size = m_widgets[i]->sizeHint();
		if(!size.isValid())
			size = QSize(0, 0);
		QSize minimumsize = m_widgets[i]->minimumSize();
		if(!minimumsize.isValid())
			minimumsize = m_widgets[i]->minimumSizeHint();
		if(minimumsize.isValid())
			size.expandedTo(minimumsize);
		m_widgets[i]->setGeometry(0, y, width(), size.height());
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
			break;
		}
	}
}
