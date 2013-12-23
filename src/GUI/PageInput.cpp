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
#include "PageInput.h"

#include "MainWindow.h"

#include <QX11Info>
#include <X11/Xlib.h>

// This does some sanity checking on the rubber band rectangle before creating it.
// Rubber bands with width or height zero or extremely large appear to cause problems.
static QRect ValidateRubberBandRectangle(QRect rect) {
	QRect screenrect = QApplication::desktop()->screenGeometry(0);
	for(int i = 1; i < QApplication::desktop()->screenCount(); ++i) {
		screenrect |= QApplication::desktop()->screenGeometry(i);
	}
	rect = rect.normalized();
	rect &= screenrect.adjusted(-10, -10, 10, 10);
	return (rect.isNull())? QRect(-10, -10, 1, 1) : rect;
}

QComboBoxWithSignal::QComboBoxWithSignal(QWidget* parent)
	: QComboBox(parent) {}

void QComboBoxWithSignal::showPopup() {
	emit popupShown();
	QComboBox::showPopup();
}

void QComboBoxWithSignal::hidePopup() {
	emit popupHidden();
	QComboBox::hidePopup();
}

QSpinBoxWithSignal::QSpinBoxWithSignal(QWidget* parent)
	: QSpinBox(parent) {}

void QSpinBoxWithSignal::focusInEvent(QFocusEvent* event) {
	emit focusIn();
	QSpinBox::focusInEvent(event);
}

void QSpinBoxWithSignal::focusOutEvent(QFocusEvent* event) {
	emit focusOut();
	QSpinBox::focusOutEvent(event);
}

PageInput::PageInput(MainWindow* main_window)
	: QWidget(main_window->centralWidget()) {

	m_main_window = main_window;

	m_grabbing = false;
	m_selecting_window = false;

	QGroupBox *group_video = new QGroupBox(tr("Video input"), this);
	{
		m_buttongroup_video_area = new QButtonGroup(group_video);
		QRadioButton *radio_area_screen = new QRadioButton(tr("Record the entire screen"), group_video);
		QRadioButton *radio_area_fixed = new QRadioButton(tr("Record a fixed rectangle"), group_video);
		QRadioButton *radio_area_cursor = new QRadioButton(tr("Follow the cursor"), group_video);
		QRadioButton *radio_area_glinject = new QRadioButton(tr("Record OpenGL (experimental)"), group_video);
		m_buttongroup_video_area->addButton(radio_area_screen, VIDEO_AREA_SCREEN);
		m_buttongroup_video_area->addButton(radio_area_fixed, VIDEO_AREA_FIXED);
		m_buttongroup_video_area->addButton(radio_area_cursor, VIDEO_AREA_CURSOR);
		m_buttongroup_video_area->addButton(radio_area_glinject, VIDEO_AREA_GLINJECT);
		m_combobox_screens = new QComboBoxWithSignal(group_video);
		m_combobox_screens->setToolTip(tr("Select what monitor should be recorded in a multi-monitor configuration."));
		m_pushbutton_video_select_rectangle = new QPushButton(tr("Select rectangle..."), group_video);
		m_pushbutton_video_select_rectangle->setToolTip(tr("Use the mouse to select the recorded rectangle."));
		m_pushbutton_video_select_window = new QPushButton(tr("Select window..."), group_video);
		m_pushbutton_video_select_window->setToolTip(tr("Use the mouse to select a window to record.\n"
														"Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only\n"
														"the client area of the window will be recorded."));
		m_pushbutton_video_opengl_settings = new QPushButton(tr("OpenGL settings..."), group_video);
		m_pushbutton_video_opengl_settings->setToolTip(tr("Change the settings for OpenGL recording."));
		m_label_video_x = new QLabel(tr("Left:"), group_video);
		m_spinbox_video_x = new QSpinBoxWithSignal(group_video);
		m_spinbox_video_x->setRange(0, 10000);
		m_spinbox_video_x->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
		m_spinbox_video_x->setToolTip(tr("The x coordinate of the upper-left corner of the recorded rectangle.\n"
										 "Hint: You can also change this value with the scroll wheel or the up/down arrows."));
		m_label_video_y = new QLabel(tr("Top:"), group_video);
		m_spinbox_video_y = new QSpinBoxWithSignal(group_video);
		m_spinbox_video_y->setRange(0, 10000);
		m_spinbox_video_y->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
		m_spinbox_video_y->setToolTip(tr("The y coordinate of the upper-left corner of the recorded rectangle.\n"
										 "Hint: You can also change this value with the scroll wheel or the up/down arrows."));
		m_label_video_w = new QLabel(tr("Width:"), group_video);
		m_spinbox_video_w = new QSpinBoxWithSignal(group_video);
		m_spinbox_video_w->setRange(0, 10000);
		m_spinbox_video_w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
		m_spinbox_video_w->setToolTip(tr("The width of the recorded rectangle.\n"
										 "Hint: You can also change this value with the scroll wheel or the up/down arrows."));
		m_label_video_h = new QLabel(tr("Height:"), group_video);
		m_spinbox_video_h = new QSpinBoxWithSignal(group_video);
		m_spinbox_video_h->setRange(0, 10000);
		m_spinbox_video_h->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
		m_spinbox_video_h->setToolTip(tr("The height of the recorded rectangle.\n"
										 "Hint: You can also change this value with the scroll wheel or the up/down arrows."));
		QLabel *label_frame_rate = new QLabel(tr("Frame rate:"), group_video);
		m_spinbox_video_frame_rate = new QSpinBox(group_video);
		m_spinbox_video_frame_rate->setRange(1, 1000);
		m_spinbox_video_frame_rate->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
		m_spinbox_video_frame_rate->setToolTip(tr("The number of frames per second in the final video. Higher frame rates use more CPU time."));
		m_checkbox_scale = new QCheckBox(tr("Scale video"), group_video);
		m_checkbox_scale->setToolTip(tr("Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster."));
		m_label_video_scaled_w = new QLabel(tr("Scaled width:"), group_video);
		m_spinbox_video_scaled_w = new QSpinBox(group_video);
		m_spinbox_video_scaled_w->setRange(0, 10000);
		m_spinbox_video_scaled_w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
		m_label_video_scaled_h = new QLabel(tr("Scaled height:"), group_video);
		m_spinbox_video_scaled_h = new QSpinBox(group_video);
		m_spinbox_video_scaled_h->setRange(0, 10000);
		m_spinbox_video_scaled_h->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
		m_checkbox_record_cursor = new QCheckBox(tr("Record cursor"), group_video);

		connect(m_buttongroup_video_area, SIGNAL(buttonClicked(int)), this, SLOT(OnUpdateVideoAreaFields()));
		connect(m_combobox_screens, SIGNAL(activated(int)), this, SLOT(OnUpdateVideoAreaFields()));
		connect(m_combobox_screens, SIGNAL(popupShown()), this, SLOT(OnIdentifyScreens()));
		connect(m_combobox_screens, SIGNAL(popupHidden()), this, SLOT(OnStopIdentifyScreens()));
		connect(m_spinbox_video_x, SIGNAL(focusIn()), this, SLOT(OnUpdateRecordingFrame()));
		connect(m_spinbox_video_x, SIGNAL(focusOut()), this, SLOT(OnUpdateRecordingFrame()));
		connect(m_spinbox_video_x, SIGNAL(valueChanged(int)), this, SLOT(OnUpdateRecordingFrame()));
		connect(m_spinbox_video_y, SIGNAL(focusIn()), this, SLOT(OnUpdateRecordingFrame()));
		connect(m_spinbox_video_y, SIGNAL(focusOut()), this, SLOT(OnUpdateRecordingFrame()));
		connect(m_spinbox_video_y, SIGNAL(valueChanged(int)), this, SLOT(OnUpdateRecordingFrame()));
		connect(m_spinbox_video_w, SIGNAL(focusIn()), this, SLOT(OnUpdateRecordingFrame()));
		connect(m_spinbox_video_w, SIGNAL(focusOut()), this, SLOT(OnUpdateRecordingFrame()));
		connect(m_spinbox_video_w, SIGNAL(valueChanged(int)), this, SLOT(OnUpdateRecordingFrame()));
		connect(m_spinbox_video_h, SIGNAL(focusIn()), this, SLOT(OnUpdateRecordingFrame()));
		connect(m_spinbox_video_h, SIGNAL(focusOut()), this, SLOT(OnUpdateRecordingFrame()));
		connect(m_spinbox_video_h, SIGNAL(valueChanged(int)), this, SLOT(OnUpdateRecordingFrame()));
		connect(m_pushbutton_video_select_rectangle, SIGNAL(clicked()), this, SLOT(OnStartSelectRectangle()));
		connect(m_pushbutton_video_select_window, SIGNAL(clicked()), this, SLOT(OnStartSelectWindow()));
		connect(m_pushbutton_video_opengl_settings, SIGNAL(clicked()), this, SLOT(OnGLInjectDialog()));
		connect(m_checkbox_scale, SIGNAL(clicked()), this, SLOT(OnUpdateVideoScaleFields()));

		QVBoxLayout *layout = new QVBoxLayout(group_video);
		{
			QHBoxLayout *layout2 = new QHBoxLayout();
			layout->addLayout(layout2);
			layout2->addWidget(radio_area_screen);
			layout2->addWidget(m_combobox_screens);
		}
		layout->addWidget(radio_area_fixed);
		layout->addWidget(radio_area_cursor);
		layout->addWidget(radio_area_glinject);
		{
			QHBoxLayout *layout2 = new QHBoxLayout();
			layout->addLayout(layout2);
			layout2->addWidget(m_pushbutton_video_select_rectangle);
			layout2->addWidget(m_pushbutton_video_select_window);
			layout2->addWidget(m_pushbutton_video_opengl_settings);
			layout2->addStretch();
		}
		{
			QGridLayout *layout2 = new QGridLayout();
			layout->addLayout(layout2);
			layout2->addWidget(m_label_video_x, 0, 0);
			layout2->addWidget(m_spinbox_video_x, 0, 1);
			layout2->addWidget(m_label_video_y, 0, 2);
			layout2->addWidget(m_spinbox_video_y, 0, 3);
			layout2->addWidget(m_label_video_w, 1, 0);
			layout2->addWidget(m_spinbox_video_w, 1, 1);
			layout2->addWidget(m_label_video_h, 1, 2);
			layout2->addWidget(m_spinbox_video_h, 1, 3);
		}
		{
			QGridLayout *layout2 = new QGridLayout();
			layout->addLayout(layout2);
			layout2->addWidget(label_frame_rate, 0, 0);
			layout2->addWidget(m_spinbox_video_frame_rate, 0, 1);
		}
		layout->addWidget(m_checkbox_scale);
		{
			QGridLayout *layout2 = new QGridLayout();
			layout->addLayout(layout2);
			layout2->addWidget(m_label_video_scaled_w, 0, 0);
			layout2->addWidget(m_spinbox_video_scaled_w, 0, 1);
			layout2->addWidget(m_label_video_scaled_h, 0, 2);
			layout2->addWidget(m_spinbox_video_scaled_h, 0, 3);
		}
		layout->addWidget(m_checkbox_record_cursor);
	}
	QGroupBox *group_audio = new QGroupBox(tr("Audio input"), this);
	{
		m_checkbox_audio_enable = new QCheckBox(tr("Record audio"), group_audio);
		m_label_audio_backend = new QLabel(tr("Backend:"), group_audio);
		m_combobox_audio_backend = new QComboBox(group_audio);
		m_combobox_audio_backend->addItem("ALSA");
#if SSR_USE_PULSEAUDIO
		m_combobox_audio_backend->addItem("PulseAudio");
#endif
#if SSR_USE_JACK
		m_combobox_audio_backend->addItem("JACK");
#endif
		m_combobox_audio_backend->setToolTip(tr("The audio backend that will be used for recording.\n"
												"The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly."));
		m_label_alsa_device = new QLabel(tr("Device:"), group_audio);
		m_lineedit_alsa_device = new QLineEdit(group_audio);
		m_lineedit_alsa_device->setToolTip(tr("The ALSA device that will be used for recording. Normally this should be 'default'.\n"
											  "You can change this to something like plughw:0,0 (which means sound card 0 input 0 with plugins enabled).", "Don't translate 'default' and 'plughw'"));
#if SSR_USE_PULSEAUDIO
		m_label_pulseaudio_source = new QLabel(tr("Source:"), group_audio);
		m_combobox_pulseaudio_source = new QComboBox(group_audio);
		m_combobox_pulseaudio_source->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
		m_combobox_pulseaudio_source->setToolTip(tr("The PulseAudio source that will be used for recording.\n"
													"A 'monitor' is a source that records the audio played by other applications.", "Don't translate 'monitor' unless PulseAudio does this as well"));
		m_pushbutton_pulseaudio_refresh = new QPushButton(tr("Refresh"), group_audio);
		m_pushbutton_pulseaudio_refresh->setToolTip(tr("Refreshes the list of PulseAudio sources."));
#endif

		connect(m_checkbox_audio_enable, SIGNAL(clicked()), this, SLOT(OnUpdateAudioFields()));
		connect(m_combobox_audio_backend, SIGNAL(activated(int)), this, SLOT(OnUpdateAudioFields()));
#if SSR_USE_PULSEAUDIO
		connect(m_pushbutton_pulseaudio_refresh, SIGNAL(clicked()), this, SLOT(OnUpdatePulseAudioSources()));
#endif

		QVBoxLayout *layout = new QVBoxLayout(group_audio);
		layout->addWidget(m_checkbox_audio_enable);
		{
			QGridLayout *layout2 = new QGridLayout();
			layout->addLayout(layout2);
			layout2->addWidget(m_label_audio_backend, 0, 0);
			layout2->addWidget(m_combobox_audio_backend, 0, 1, 1, 2);
			layout2->addWidget(m_label_alsa_device, 1, 0);
			layout2->addWidget(m_lineedit_alsa_device, 1, 1, 1, 2);
#if SSR_USE_PULSEAUDIO
			layout2->addWidget(m_label_pulseaudio_source, 2, 0);
			layout2->addWidget(m_combobox_pulseaudio_source, 2, 1);
			layout2->addWidget(m_pushbutton_pulseaudio_refresh, 2, 2);
#endif
		}
	}
	QPushButton *button_back = new QPushButton(QIcon::fromTheme("go-previous"), tr("Back"), this);
	QPushButton *button_continue = new QPushButton(QIcon::fromTheme("go-next"), tr("Continue"), this);

	connect(button_back, SIGNAL(clicked()), m_main_window, SLOT(GoPageWelcome()));
	connect(button_continue, SIGNAL(clicked()), this, SLOT(OnContinue()));

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(group_video);
	layout->addWidget(group_audio);
	layout->addStretch();
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addWidget(button_back);
		layout2->addWidget(button_continue);
	}

	connect(QApplication::desktop(), SIGNAL(screenCountChanged(int)), this, SLOT(OnUpdateScreenConfiguration()));
	connect(QApplication::desktop(), SIGNAL(resized(int)), this, SLOT(OnUpdateScreenConfiguration()));
	LoadScreenConfigurations();
#if SSR_USE_PULSEAUDIO
	LoadPulseAudioSources();
#endif

	OnUpdateVideoAreaFields();
	OnUpdateVideoScaleFields();
	OnUpdateAudioFields();

}

void PageInput::LoadSettings(QSettings* settings) {

	// choose default audio backend
#if SSR_USE_PULSEAUDIO
	enum_audio_backend default_audio_backend = (m_pulseaudio_available)? AUDIO_BACKEND_PULSEAUDIO : AUDIO_BACKEND_ALSA;
#else
	enum_audio_backend default_audio_backend = AUDIO_BACKEND_ALSA;
#endif

	// load settings
	SetVideoArea((enum_video_area) settings->value("input/video_area", VIDEO_AREA_SCREEN).toUInt());
	SetVideoAreaScreen(settings->value("input/video_area_screen", 0).toUInt());
	SetVideoX(settings->value("input/video_x", 0).toUInt());
	SetVideoY(settings->value("input/video_y", 0).toUInt());
	SetVideoW(settings->value("input/video_w", 800).toUInt());
	SetVideoH(settings->value("input/video_h", 600).toUInt());
	SetVideoFrameRate(settings->value("input/video_frame_rate", 30).toUInt());
	SetVideoScalingEnabled(settings->value("input/video_scale", false).toBool());
	SetVideoScaledW(settings->value("input/video_scaled_w", 854).toUInt());
	SetVideoScaledH(settings->value("input/video_scaled_h", 480).toUInt());
	SetVideoRecordCursor(settings->value("input/video_record_cursor", true).toBool());
	SetAudioEnabled(settings->value("input/audio_enabled", true).toBool());
	SetAudioBackend((enum_audio_backend) settings->value("input/audio_backend", default_audio_backend).toUInt());
	SetALSADevice(settings->value("input/audio_alsa_device", "default").toString());
#if SSR_USE_PULSEAUDIO
	SetPulseAudioSource(FindPulseAudioSource(settings->value("input/audio_pulseaudio_source", QString()).toString()));
#endif
	SetGLInjectPid(settings->value("input/glinject_pid", "").toString());
	SetGLInjectSource(settings->value("input/glinject_source", "").toString());
	SetGLInjectProgramName(settings->value("input/glinject_program_name", "").toString());
	SetGLInjectLimitFPS(settings->value("input/glinject_limit_fps", false).toBool());
	SetGLInjectCommand(settings->value("input/glinject_command", "").toString());
	SetGLInjectWorkingDirectory(settings->value("input/glinject_working_directory", "").toString());
	SetGLInjectRelaxPermissions(settings->value("input/glinject_relax_permissions", false).toBool());

	// update things
	OnUpdateVideoAreaFields();
	OnUpdateVideoScaleFields();
	OnUpdateAudioFields();

}

void PageInput::SaveSettings(QSettings* settings) {
	settings->setValue("input/video_area", GetVideoArea());
	settings->setValue("input/video_area_screen", GetVideoAreaScreen());
	settings->setValue("input/video_x", GetVideoX());
	settings->setValue("input/video_y", GetVideoY());
	settings->setValue("input/video_w", GetVideoW());
	settings->setValue("input/video_h", GetVideoH());
	settings->setValue("input/video_frame_rate", GetVideoFrameRate());
	settings->setValue("input/video_scale", GetVideoScalingEnabled());
	settings->setValue("input/video_scaled_w", GetVideoScaledW());
	settings->setValue("input/video_scaled_h", GetVideoScaledH());
	settings->setValue("input/video_record_cursor", GetVideoRecordCursor());
	settings->setValue("input/audio_enabled", GetAudioEnabled());
	settings->setValue("input/audio_backend", GetAudioBackend());
	settings->setValue("input/audio_alsa_device", GetALSADevice());
#if SSR_USE_PULSEAUDIO
	settings->setValue("input/audio_pulseaudio_source", GetPulseAudioSourceName());
#endif
	settings->setValue("input/glinject_pid", GetGLInjectPid());
	settings->setValue("input/glinject_source", GetGLInjectSource());
	settings->setValue("input/glinject_program_name", GetGLInjectProgramName());
	settings->setValue("input/glinject_limit_fps", GetGLInjectLimitFPS());
	settings->setValue("input/glinject_command", GetGLInjectCommand());
	settings->setValue("input/glinject_working_directory", GetGLInjectWorkingDirectory());
	settings->setValue("input/glinject_relax_permissions", GetGLInjectRelaxPermissions());
}

#if SSR_USE_PULSEAUDIO

QString PageInput::GetPulseAudioSourceName() {
	return m_pulseaudio_sources[GetPulseAudioSource()].name;
}

unsigned int PageInput::FindPulseAudioSource(const QString &name) {
	for(unsigned int i = 0; i < m_pulseaudio_sources.size(); ++i) {
		if(m_pulseaudio_sources[i].name == name)
			return i;
	}
	return 0;
}

#endif

// Tries to find the real window that corresponds to a top-level window (the actual window without window manager decorations).
// Returns None if it can't find the window (probably because the window is not handled by the window manager).
// Based on the xprop source code (http://cgit.freedesktop.org/xorg/app/xprop/tree/clientwin.c).
static Window X11FindRealWindow(Display* display, Window window) {

	// is this the real window?
	Atom actual_type;
	int actual_format;
	unsigned long items, bytes_left;
	unsigned char *data = NULL;
	XGetWindowProperty(display, window, XInternAtom(display, "WM_STATE", true),
					   0, 0, false, AnyPropertyType, &actual_type, &actual_format, &items, &bytes_left, &data);
	if(data != NULL)
		XFree(data);
	if(actual_type != None)
		return window;

	// get the child windows
	Window root, parent, *childs;
	unsigned int childcount;
	if(!XQueryTree(display, window, &root, &parent, &childs, &childcount)) {
		return None;
	}

	// recursively call this function for all childs
	Window real_window = None;
	for(unsigned int i = childcount; i > 0; ) {
		--i;
		Window w = X11FindRealWindow(display, childs[i]);
		if(w != None) {
			real_window = w;
			break;
		}
	}

	// free child window list
	if(childs != NULL)
		XFree(childs);

	return real_window;

}

void PageInput::mousePressEvent(QMouseEvent* event) {
	if(m_grabbing) {
		if(event->button() == Qt::LeftButton) {
			if(m_selecting_window) {
				// As expected, Qt does not provide any functions to find the window at a specific position, so I have to use Xlib directly.
				// I'm not completely sure whether this is the best way to do this, but it appears to work. XQueryPointer returns the window
				// currently below the mouse along with the mouse position, but apparently this may not work correctly when the mouse pointer
				// is also grabbed (even though it works fine in my test), so I use XTranslateCoordinates instead. Originally I wanted to
				// show the rubber band when the mouse hovers over a window (instead of having to click it), but this doesn't work correctly
				// since X will simply return a handle the rubber band itself (even though it should be transparent to mouse events).
				Window selected_window;
				int x, y;
				if(XTranslateCoordinates(QX11Info::display(), QX11Info::appRootWindow(), QX11Info::appRootWindow(), event->globalX(), event->globalY(), &x, &y, &selected_window)) {
					XWindowAttributes attributes;
					if(selected_window != None && XGetWindowAttributes(QX11Info::display(), selected_window, &attributes)) {

						// naive outer/inner rectangle, this won't work for window decorations
						m_select_window_outer_rect = QRect(attributes.x, attributes.y, attributes.width + 2 * attributes.border_width, attributes.height + 2 * attributes.border_width);
						m_select_window_inner_rect = QRect(attributes.x + attributes.border_width, attributes.y + attributes.border_width, attributes.width, attributes.height);

						// try to find the real window (rather than the decorations added by the window manager)
						Window real_window = X11FindRealWindow(QX11Info::display(), selected_window);
						if(real_window != None) {
							Atom actual_type;
							int actual_format;
							unsigned long items, bytes_left;
							long *data = NULL;
							int result = XGetWindowProperty(QX11Info::display(), real_window, XInternAtom(QX11Info::display(), "_NET_FRAME_EXTENTS", true),
															0, 4, false, AnyPropertyType, &actual_type, &actual_format, &items, &bytes_left, (unsigned char**) &data);
							if(result == Success) {
								if(items == 4 && bytes_left == 0 && actual_format == 32) { // format 32 means 'long', even if long is 64-bit ...
									Window child;
									// the attributes of the real window only store the *relative* position which is not what we need, so use XTranslateCoordinates again
									if(XTranslateCoordinates(QX11Info::display(), real_window, QX11Info::appRootWindow(), 0, 0, &x, &y, &child)
											 && XGetWindowAttributes(QX11Info::display(), real_window, &attributes)) {

										// finally!
										m_select_window_inner_rect = QRect(x, y, attributes.width, attributes.height);
										m_select_window_outer_rect = m_select_window_inner_rect.adjusted(-data[0], -data[2], data[1], data[3]);

									} else {

										// I doubt this will ever be needed, but do it anyway
										m_select_window_inner_rect = m_select_window_outer_rect.adjusted(data[0], data[2], -data[1], -data[3]);

									}
								}
							}
							if(data != NULL)
								XFree(data);
						}

						// pick the inner rectangle if the users clicks inside the window, or the outer rectangle otherwise
						m_rubber_band_rect = (m_select_window_inner_rect.contains(event->globalPos()))? m_select_window_inner_rect : m_select_window_outer_rect;
						m_rubber_band.reset(new QRubberBand(QRubberBand::Rectangle));
						m_rubber_band->setGeometry(ValidateRubberBandRectangle(m_rubber_band_rect));
						m_rubber_band->show();

					}
				}
			} else {
				m_rubber_band_rect = QRect(event->globalPos(), QSize(0, 0));
				m_rubber_band.reset(new QRubberBand(QRubberBand::Rectangle));
				m_rubber_band->setGeometry(ValidateRubberBandRectangle(m_rubber_band_rect));
				m_rubber_band->show();
			}
			return;
		} else {
			StopGrabbing();
			return;
		}
	}
	event->ignore();
}

void PageInput::mouseReleaseEvent(QMouseEvent* event) {
	if(m_grabbing) {
		if(event->button() == Qt::LeftButton) {
			if(m_rubber_band != NULL) {
				SetVideoAreaFromRubberBand();
			}
		}
		StopGrabbing();
		return;
	}
	event->ignore();
}

void PageInput::mouseMoveEvent(QMouseEvent* event) {
	if(m_grabbing) {
		if(m_rubber_band != NULL) {
			if(m_selecting_window) {
				// pick the inner rectangle if the users clicks inside the window, or the outer rectangle otherwise
				m_rubber_band_rect = (m_select_window_inner_rect.contains(event->globalPos()))? m_select_window_inner_rect : m_select_window_outer_rect;
			} else {
				m_rubber_band_rect.setBottomRight(event->globalPos());
			}
			m_rubber_band->setGeometry(ValidateRubberBandRectangle(m_rubber_band_rect));
		}
		return;
	}
	event->ignore();
}

void PageInput::keyPressEvent(QKeyEvent* event) {
	if(event->key() == Qt::Key_Escape) {
		StopGrabbing();
		return;
	}
	event->ignore();
}

void PageInput::StartGrabbing() {
	// Grab the mouse and keyboard, and hide the window. Grabbing the keyboard isn't required, but if we don't grab it the user could still alt-tab
	// to other windows, switch workspaces, ... which would be very confusing. Grabbing doesn't work if the window is actually hidden or minimized,
	// so instead I just lower the window below all other windows (this is probably less confusing too). Grabbing stops as soon as the escape key
	// or any mouse button is pressed (or released in the case of the left mouse button).
	m_grabbing = true;
	if(m_selecting_window)
		m_pushbutton_video_select_window->setDown(true);
	else
		m_pushbutton_video_select_rectangle->setDown(true);
	m_main_window->lower();
	grabMouse(Qt::CrossCursor);
	grabKeyboard();
	setMouseTracking(true);
}

void PageInput::StopGrabbing() {
	m_rubber_band.reset();
	setMouseTracking(false);
	releaseKeyboard();
	releaseMouse();
	m_main_window->raise();
	m_main_window->activateWindow();
	if(m_selecting_window)
		m_pushbutton_video_select_window->setDown(false);
	else
		m_pushbutton_video_select_rectangle->setDown(false);
	m_grabbing = false;
}

void PageInput::SetVideoAreaFromRubberBand() {
	QRect r = m_rubber_band_rect.normalized();
	if(GetVideoArea() == VIDEO_AREA_CURSOR) {
		SetVideoX(0);
		SetVideoY(0);
	} else {
		SetVideoX(r.x());
		SetVideoY(r.y());
	}
	SetVideoW(r.width());
	SetVideoH(r.height());
}

void PageInput::LoadScreenConfigurations() {
	QRect rect = QApplication::desktop()->screenGeometry(0);
	for(int i = 1; i < QApplication::desktop()->screenCount(); ++i) {
		rect |= QApplication::desktop()->screenGeometry(i);
	}
	m_combobox_screens->clear();
	m_combobox_screens->addItem(tr("All screens: %1x%2", "This appears in the screen selection combobox")
								.arg(rect.width()).arg(rect.height()));
	for(int i = 0; i < QApplication::desktop()->screenCount(); ++i) {
		rect = QApplication::desktop()->screenGeometry(i);
		m_combobox_screens->addItem(tr("Screen %1: %2x%3 at %4,%5", "This appears in the screen selection combobox")
									.arg(i + 1).arg(rect.width()).arg(rect.height()).arg(rect.left()).arg(rect.top()));
	}
	// update the video x/y/w/h in case the position or size of the selected screen changed
	OnUpdateVideoAreaFields();
}

#if SSR_USE_PULSEAUDIO

void PageInput::LoadPulseAudioSources() {
	m_pulseaudio_sources = PulseAudioInput::GetSourceList();
	if(m_pulseaudio_sources.empty()) {
		m_pulseaudio_available = false;
		PulseAudioInput::Source source;
		source.name = "";
		source.description = "(no sources found)";
		m_pulseaudio_sources.push_back(source);
	} else {
		m_pulseaudio_available = true;
	}
	m_combobox_pulseaudio_source->clear();
	for(unsigned int i = 0; i < m_pulseaudio_sources.size(); ++i) {
		// limit the width of the strings (PulseAudio can generate really long names)
		QString elided = m_combobox_pulseaudio_source->fontMetrics().elidedText(m_pulseaudio_sources[i].description, Qt::ElideMiddle, 400);
		m_combobox_pulseaudio_source->addItem(elided);
	}
}

#endif

void PageInput::OnUpdateRecordingFrame() {
	if(m_spinbox_video_x->hasFocus() || m_spinbox_video_y->hasFocus() || m_spinbox_video_w->hasFocus() || m_spinbox_video_h->hasFocus()) {
		if(m_recording_frame == NULL) {
			m_recording_frame.reset(new QRubberBand(QRubberBand::Rectangle));
			m_recording_frame->setGeometry(ValidateRubberBandRectangle(QRect(GetVideoX(), GetVideoY(), GetVideoW(), GetVideoH())));
			m_recording_frame->show();
		} else {
			m_recording_frame->setGeometry(ValidateRubberBandRectangle(QRect(GetVideoX(), GetVideoY(), GetVideoW(), GetVideoH())));
		}
	} else {
		m_recording_frame.reset();
	}
}

void PageInput::OnUpdateVideoAreaFields() {
	switch(GetVideoArea()) {
		case VIDEO_AREA_SCREEN: {
			m_combobox_screens->setEnabled(true);
			m_pushbutton_video_select_rectangle->setEnabled(false);
			m_pushbutton_video_select_window->setEnabled(false);
			m_pushbutton_video_opengl_settings->setEnabled(false);
			GroupEnabled({m_label_video_x, m_spinbox_video_x, m_label_video_y, m_spinbox_video_y,
						  m_label_video_w, m_spinbox_video_w, m_label_video_h, m_spinbox_video_h}, false);
			int sc = m_combobox_screens->currentIndex();
			QRect rect;
			if(sc == 0) {
				rect = QApplication::desktop()->screenGeometry(0);
				for(int i = 1; i < QApplication::desktop()->screenCount(); ++i) {
					rect |= QApplication::desktop()->screenGeometry(i);
				}
			} else {
				rect = QApplication::desktop()->screenGeometry(sc - 1);
			}
			SetVideoX(rect.left());
			SetVideoY(rect.top());
			SetVideoW(rect.width());
			SetVideoH(rect.height());
			break;
		}
		case VIDEO_AREA_FIXED: {
			m_combobox_screens->setEnabled(false);
			m_pushbutton_video_select_rectangle->setEnabled(true);
			m_pushbutton_video_select_window->setEnabled(true);
			m_pushbutton_video_opengl_settings->setEnabled(false);
			GroupEnabled({m_label_video_x, m_spinbox_video_x, m_label_video_y, m_spinbox_video_y,
						  m_label_video_w, m_spinbox_video_w, m_label_video_h, m_spinbox_video_h}, true);
			break;
		}
		case VIDEO_AREA_CURSOR: {
			m_combobox_screens->setEnabled(false);
			m_pushbutton_video_select_rectangle->setEnabled(true);
			m_pushbutton_video_select_window->setEnabled(true);
			m_pushbutton_video_opengl_settings->setEnabled(false);
			GroupEnabled({m_label_video_x, m_spinbox_video_x, m_label_video_y, m_spinbox_video_y}, false);
			GroupEnabled({m_label_video_w, m_spinbox_video_w, m_label_video_h, m_spinbox_video_h}, true);
			SetVideoX(0);
			SetVideoY(0);
			break;
		}
		case VIDEO_AREA_GLINJECT: {
			m_combobox_screens->setEnabled(false);
			m_pushbutton_video_select_rectangle->setEnabled(false);
			m_pushbutton_video_select_window->setEnabled(false);
			m_pushbutton_video_opengl_settings->setEnabled(true);
			GroupEnabled({m_label_video_x, m_spinbox_video_x, m_label_video_y, m_spinbox_video_y,
						  m_label_video_w, m_spinbox_video_w, m_label_video_h, m_spinbox_video_h}, false);
			break;
		}
		default: break;
	}
}

void PageInput::OnUpdateVideoScaleFields() {
	bool enabled = GetVideoScalingEnabled();
	GroupEnabled({m_label_video_scaled_w, m_spinbox_video_scaled_w, m_label_video_scaled_h, m_spinbox_video_scaled_h}, enabled);
}

void PageInput::OnUpdateAudioFields() {
	bool enabled = GetAudioEnabled();
	enum_audio_backend backend = GetAudioBackend();
	GroupEnabled({
		m_label_audio_backend, m_combobox_audio_backend, m_label_alsa_device, m_lineedit_alsa_device,
#if SSR_USE_PULSEAUDIO
		m_label_pulseaudio_source, m_combobox_pulseaudio_source, m_pushbutton_pulseaudio_refresh,
#endif
	}, enabled);
	MultiGroupVisible({
		{{m_label_alsa_device, m_lineedit_alsa_device}, (backend == AUDIO_BACKEND_ALSA)},
#if SSR_USE_PULSEAUDIO
		{{m_label_pulseaudio_source, m_combobox_pulseaudio_source, m_pushbutton_pulseaudio_refresh}, (backend == AUDIO_BACKEND_PULSEAUDIO)}
#endif
	});
}

void PageInput::OnUpdateScreenConfiguration() {
	unsigned int selected_screen = GetVideoAreaScreen();
	LoadScreenConfigurations();
	SetVideoAreaScreen(selected_screen);
}

void PageInput::OnUpdatePulseAudioSources() {
#if SSR_USE_PULSEAUDIO
	QString selected_source = GetPulseAudioSourceName();
	LoadPulseAudioSources();
	SetPulseAudioSource(FindPulseAudioSource(selected_source));
#endif
}

void PageInput::OnIdentifyScreens() {
	OnStopIdentifyScreens();
	for(int i = 0; i < QApplication::desktop()->screenCount(); ++i) {
		QRect rect = QApplication::desktop()->screenGeometry(i);
		WidgetScreenLabel *label = new WidgetScreenLabel(this, tr("Screen %1", "This appears in the screen labels").arg(i + 1));
		label->move(rect.left(), rect.top());
		label->show();
		m_screen_labels.push_back(label);
	}
}

void PageInput::OnStopIdentifyScreens() {
	for(unsigned int i = 0; i < m_screen_labels.size(); ++i) {
		delete m_screen_labels[i];
	}
	m_screen_labels.clear();
}

void PageInput::OnStartSelectRectangle() {
	m_selecting_window = false;
	StartGrabbing();
}

void PageInput::OnStartSelectWindow() {
	m_selecting_window = true;
	StartGrabbing();
}

void PageInput::OnGLInjectDialog() {
	DialogGLInject dialog(this);
	dialog.exec();
}

void PageInput::OnContinue() {
	if(GetVideoArea() == VIDEO_AREA_GLINJECT && GetGLInjectCommand().isEmpty()) {
		QMessageBox::critical(this, MainWindow::WINDOW_CAPTION,
							  tr("You did not enter a command to start the OpenGL application that you want to record.\n"
								 "Click the 'OpenGL settings' button and enter a command."), QMessageBox::Ok);
		return;
	}
	m_main_window->GoPageOutput();
}

WidgetScreenLabel::WidgetScreenLabel(QWidget* parent, const QString &text)
	: QWidget(parent, Qt::Window | Qt::X11BypassWindowManagerHint | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint) {
	m_text = text;
}

QSize WidgetScreenLabel::sizeHint() const {
	return QSize(180, 60);
}

void WidgetScreenLabel::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	QPainter painter(this);
	painter.setPen(QColor(0, 0, 0));
	painter.setBrush(QColor(255, 192, 128));
	painter.drawRect(0, 0, width() - 1, height() - 1);
	painter.setFont(QFont("Sans", 18, QFont::Bold));
	painter.drawText(0, 0, width(), height(), Qt::AlignHCenter | Qt::AlignVCenter | Qt::TextSingleLine, m_text);
}

DialogGLInject::DialogGLInject(PageInput* parent)
	: QDialog(parent) {

	m_parent = parent;

	setWindowTitle(tr("OpenGL Settings"));

	QLabel *label_info = new QLabel(this);
	label_info->setText(tr("<p>Warning: OpenGL recording works by injecting a library into the program that will be recorded. "
						   "This library will override some system functions in order to capture the frames before they are "
						   "displayed on the screen. If you are trying to record a game that tries to detect hacking attempts "
						   "on the client side, it's (theoretically) possible that the game will consider this a hack. This "
						   "might even get you banned, so it's a good idea to make sure that the program you want to record "
						   "won't ban you, *before* you try to record it. You've been warned :).</p>\n\n"
						   "<p>Another warning: OpenGL recording is experimental, it may not work or even crash the program you "
						   "are recording. If you are worried about losing program data, make a backup first!</p>\n\n"
						   "<p>If you want to record Steam games, <a href=\"http://www.maartenbaert.be/simplescreenrecorder/recording-steam-games/\">read this first</a>.</p>"));
	label_info->setWordWrap(true);
	label_info->setTextFormat(Qt::RichText);
	label_info->setTextInteractionFlags(Qt::TextBrowserInteraction);
	label_info->setOpenExternalLinks(true);

	QGroupBox *groupbox_stream = new QGroupBox(tr("Select stream"), this);
	{
		QLabel *label_pid = new QLabel(tr("Pid:"), groupbox_stream);
		m_lineedit_pid = new QLineEdit(m_parent->GetGLInjectPid(), groupbox_stream);
		QLabel *label_source = new QLabel(tr("Source:"), groupbox_stream);
		m_lineedit_source = new QLineEdit(m_parent->GetGLInjectSource(), groupbox_stream);
		QLabel *label_program_name = new QLabel(tr("Program name:"), groupbox_stream);
		m_lineedit_program_name = new QLineEdit(m_parent->GetGLInjectProgramName(), groupbox_stream);
		m_checkbox_limit_fps = new QCheckBox(tr("Limit application frame rate"), this);
		m_checkbox_limit_fps->setToolTip(tr("If checked, the injected library will slow down the application so the frame rate doesn't become higher than the recording frame rate.\n"
											"This stops the application from wasting CPU time for frames that won't be recorded, and sometimes results in smoother video\n"
											"(this depends on the application)."));
		m_checkbox_limit_fps->setChecked(m_parent->GetGLInjectLimitFPS());

		QGridLayout *layout = new QGridLayout(groupbox_stream);
		layout->addWidget(label_pid, 0, 0);
		layout->addWidget(m_lineedit_pid, 0, 1);
		layout->addWidget(label_source, 1, 0);
		layout->addWidget(m_lineedit_source, 1, 1);
		layout->addWidget(label_program_name, 2, 0);
		layout->addWidget(m_lineedit_program_name, 2, 1);
		layout->addWidget(m_checkbox_limit_fps, 3, 0, 1, 2);
	}

	QGroupBox *groupbox_launch = new QGroupBox(tr("Launch application"), this);
	{
		QLabel *label_command = new QLabel(tr("Command:"), groupbox_launch);
		m_lineedit_command = new QLineEdit(m_parent->GetGLInjectCommand(), groupbox_launch);
		m_lineedit_command->setToolTip(tr("This command will be executed to start the program that should be recorded."));
		m_lineedit_command->setMinimumWidth(300);
		QLabel *label_working_directory = new QLabel(tr("Working directory:"), groupbox_launch);
		m_lineedit_working_directory = new QLineEdit(m_parent->GetGLInjectWorkingDirectory(), groupbox_launch);
		m_lineedit_working_directory->setToolTip(tr("The command will be executed in this directory. If you leave this empty, the working directory won't be changed."));
		m_lineedit_working_directory->setMinimumWidth(300);
		m_checkbox_relax_permissions = new QCheckBox(tr("Relax shared memory permissions (insecure)"), groupbox_launch);
		m_checkbox_relax_permissions->setToolTip(tr("If checked, other users on the same machine will be able to attach to the shared memory that's used for communication with the OpenGL program.\n"
													"This means other users can (theoretically) see what you are recording, modify the frames, inject their own frames, or simply disrupt the communication.\n"
													"This even applies to users that are logged in remotely (ssh). You should only enable this if you need to record a program that runs as a different user."));
		m_checkbox_relax_permissions->setChecked(m_parent->GetGLInjectRelaxPermissions());
		QPushButton *pushbutton_launch = new QPushButton(tr("Launch"), this);

		connect(pushbutton_launch, SIGNAL(clicked()), this, SLOT(OnLaunch()));

		QGridLayout *layout = new QGridLayout(groupbox_launch);
		layout->addWidget(label_command, 0, 0);
		layout->addWidget(m_lineedit_command, 0, 1);
		layout->addWidget(label_working_directory, 1, 0);
		layout->addWidget(m_lineedit_working_directory, 1, 1);
		layout->addWidget(m_checkbox_relax_permissions, 2, 0, 1, 2);
		layout->addWidget(pushbutton_launch, 3, 0, 1, 2);
	}

	QPushButton *pushbutton_close = new QPushButton(tr("Close"), this);
	pushbutton_close->setDefault(true);

	connect(pushbutton_close, SIGNAL(clicked()), this, SLOT(accept()));
	connect(this, SIGNAL(accepted()), this, SLOT(OnWriteBack()));
	connect(this, SIGNAL(rejected()), this, SLOT(OnWriteBack()));

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(label_info);
	layout->addWidget(groupbox_stream);
	layout->addWidget(groupbox_launch);
	layout->addStretch();
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addStretch();
		layout2->addWidget(pushbutton_close);
		layout2->addStretch();
	}

	setMinimumSize(minimumSizeHint()); // workaround for Qt bug

}

void DialogGLInject::OnWriteBack() {
	m_parent->SetGLInjectPid(m_lineedit_pid->text());
	m_parent->SetGLInjectSource(m_lineedit_source->text());
	m_parent->SetGLInjectProgramName(m_lineedit_program_name->text());
	m_parent->SetGLInjectLimitFPS(m_checkbox_limit_fps->isChecked());
	m_parent->SetGLInjectCommand(m_lineedit_command->text());
	m_parent->SetGLInjectWorkingDirectory(m_lineedit_working_directory->text());
	m_parent->SetGLInjectRelaxPermissions(m_checkbox_relax_permissions->isChecked());
}

void DialogGLInject::OnLaunch() {

	// prepare command
	QString command = "LD_PRELOAD=libssr-glinject.so " + m_lineedit_command->text();
	QString working_directory = m_lineedit_working_directory->text();
	if(m_checkbox_relax_permissions->isChecked())
		command = "SSR_STREAM_RELAX_PERMISSIONS=1 " + command;

	// execute it
	QStringList args;
	args.push_back("-c");
	args.push_back(command);
	if(!QProcess::startDetached("/bin/sh", args, working_directory)) {
		QMessageBox::critical(NULL, MainWindow::WINDOW_CAPTION, QObject::tr("The application could not be launched."), QMessageBox::Ok);
	}

}
