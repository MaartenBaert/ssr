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

#include "PageInput.h"

#include "DialogGLInject.h"
#include "Dialogs.h"
#include "EnumStrings.h"
#include "HiddenScrollArea.h"
#include "Icons.h"
#include "MainWindow.h"

ENUMSTRINGS(PageInput::enum_video_area) = {
	{PageInput::VIDEO_AREA_SCREEN, "screen"},
	{PageInput::VIDEO_AREA_FIXED, "fixed"},
	{PageInput::VIDEO_AREA_CURSOR, "cursor"},
#if SSR_USE_OPENGL_RECORDING
	{PageInput::VIDEO_AREA_GLINJECT, "glinject"},
#endif
#if SSR_USE_V4L2
	{PageInput::VIDEO_AREA_V4L2, "v4l2"},
#endif
};

ENUMSTRINGS(PageInput::enum_audio_backend) = {
#if SSR_USE_ALSA
	{PageInput::AUDIO_BACKEND_ALSA, "alsa"},
#endif
#if SSR_USE_PULSEAUDIO
	{PageInput::AUDIO_BACKEND_PULSEAUDIO, "pulseaudio"},
#endif
#if SSR_USE_JACK
	{PageInput::AUDIO_BACKEND_JACK, "jack"},
#endif
};

static std::vector<QRect> GetScreenGeometries() {
	std::vector<QRect> screen_geometries;
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
	for(QScreen *screen :  QApplication::screens()) {
		QRect geometry = screen->geometry();
		qreal ratio = screen->devicePixelRatio();
		screen_geometries.emplace_back(geometry.x(), geometry.y(), lrint((qreal) geometry.width() * ratio), lrint((qreal) geometry.height() * ratio));
	}
#else
	for(int i = 0; i < QApplication::desktop()->screenCount(); ++i) {
		screen_geometries.push_back(QApplication::desktop()->screenGeometry(i));
	}
#endif
	return screen_geometries;
}

static QRect CombineScreenGeometries(const std::vector<QRect>& screen_geometries) {
	QRect combined_geometry;
	for(const QRect &geometry : screen_geometries) {
		combined_geometry |= geometry;
	}
	return combined_geometry;
}

static QPoint GetMousePhysicalCoordinates() {
	if(IsPlatformX11()) {
		Window root, child;
		int root_x, root_y;
		int win_x, win_y;
		unsigned int mask_return;
		XQueryPointer(QX11Info::display(), QX11Info::appRootWindow(), &root, &child, &root_x, &root_y, &win_x, &win_y, &mask_return);
		return QPoint(root_x, root_y);
	} else {
		return QPoint(0, 0); // TODO: implement for wayland
	}
}

static QRect MapToLogicalCoordinates(const QRect& rect) {
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
	for(QScreen *screen :  QApplication::screens()) {
		QRect geometry = screen->geometry();
		qreal ratio = screen->devicePixelRatio();
		QRect physical_geometry(geometry.x(), geometry.y(), lrint((qreal) geometry.width() * ratio), lrint((qreal) geometry.height() * ratio));
		if(physical_geometry.contains(rect.center())) {
			return QRect(
						geometry.x() + lrint((qreal) (rect.x() - physical_geometry.x()) / ratio - 0.4999),
						geometry.y() + lrint((qreal) (rect.y() - physical_geometry.y()) / ratio - 0.4999),
						lrint((qreal) rect.width() / ratio - 0.4999),
						lrint((qreal) rect.height() / ratio - 0.4999));
		}
	}
#endif
	return rect;
};

// This does some sanity checking on the rubber band rectangle before creating it.
// Rubber bands with width or height zero or extremely large appear to cause problems.
static QRect ValidateRubberBandRectangle(QRect rect) {
	std::vector<QRect> screen_geometries = GetScreenGeometries();
	QRect combined_geometry = CombineScreenGeometries(screen_geometries);
	return rect.normalized() & combined_geometry.adjusted(-10, -10, 10, 10);
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

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)

#define TRANSPARENT_WINDOW_FLAGS (Qt::Window | Qt::BypassWindowManagerHint | Qt::FramelessWindowHint | \
		Qt::WindowStaysOnTopHint | Qt::WindowTransparentForInput | Qt::WindowDoesNotAcceptFocus)

#define TRANSPARENT_WINDOW_ATTRIBUTES() {\
}

#else

#define TRANSPARENT_WINDOW_FLAGS (Qt::Window | Qt::X11BypassWindowManagerHint | Qt::FramelessWindowHint | \
		Qt::WindowStaysOnTopHint)

// Replacement for Qt::WindowTransparentForInput based on X11 'shape' extension as described here:
// http://shallowsky.com/blog/programming/translucent-window-click-thru.html
#define TRANSPARENT_WINDOW_ATTRIBUTES() {\
	setAttribute(Qt::WA_X11DoNotAcceptFocus); \
	int shape_event_base, shape_error_base; \
	if(IsPlatformX11()) { \
		if(XShapeQueryExtension(QX11Info::display(), &shape_event_base, &shape_error_base)) { \
			Region region = XCreateRegion(); \
			XShapeCombineRegion(QX11Info::display(), winId(), ShapeInput, 0, 0, region, ShapeSet); \
			XDestroyRegion(region); \
		} \
	} \
}

#endif

ScreenLabelWindow::ScreenLabelWindow(QWidget* parent, const QString &text)
	: QWidget(parent, TRANSPARENT_WINDOW_FLAGS) {
	TRANSPARENT_WINDOW_ATTRIBUTES();
	m_text = text;
	m_font = QFont("Sans", 18, QFont::Bold);
	QFontMetrics fm(m_font);
	setFixedSize(fm.size(Qt::TextSingleLine, m_text) + QSize(60, 40));
	setWindowOpacity(0.75);
}

void ScreenLabelWindow::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	QPainter painter(this);
	painter.setPen(QColor(0, 0, 0));
	painter.setBrush(QColor(255, 192, 128));
	painter.drawRect(QRectF(0.5, 0.5, (qreal) width() - 1.0, (qreal) height() - 1.0));
	painter.setFont(m_font);
	painter.drawText(0, 0, width(), height(), Qt::AlignHCenter | Qt::AlignVCenter | Qt::TextSingleLine, m_text);
}

RecordingFrameWindow::RecordingFrameWindow(QWidget* parent, bool outside)
	: QWidget(parent, TRANSPARENT_WINDOW_FLAGS) {
	TRANSPARENT_WINDOW_ATTRIBUTES();
	m_outside = outside;
	QImage image(16, 16, QImage::Format_RGB32);
	for(size_t j = 0; j < (size_t) image.height(); ++j) {
		uint32_t *row = (uint32_t*) image.scanLine(j);
		for(size_t i = 0; i < (size_t) image.width(); ++i) {
			//row[i] = ((i + j) % 16 < 8)? 0xffbfbfff : 0xff9f9fdf;
			row[i] = ((i + j) % 16 < 8)? 0xffff8080 : 0xff8080ff;
		}
	}
	m_texture = QPixmap::fromImage(image);
	UpdateMask();
}

void RecordingFrameWindow::SetRectangle(const QRect& r) {
	QRect rect = MapToLogicalCoordinates(ValidateRubberBandRectangle(r));
	if(m_outside)
		rect.adjust(-RecordingFrameWindow::BORDER_WIDTH, -RecordingFrameWindow::BORDER_WIDTH,
					RecordingFrameWindow::BORDER_WIDTH, RecordingFrameWindow::BORDER_WIDTH);
	if(rect.isEmpty()) {
		hide();
	} else {
		setGeometry(rect);
		show();
	}
}

void RecordingFrameWindow::UpdateMask() {
	if(m_outside) {
		setMask(QRegion(0, 0, width(), height()).subtracted(QRegion(BORDER_WIDTH, BORDER_WIDTH, width() - 2 * BORDER_WIDTH, height() - 2 * BORDER_WIDTH)));
		setWindowOpacity(0.5);
	} else {
		if(QX11Info::isCompositingManagerRunning()) {
			clearMask();
			setWindowOpacity(0.25);
		} else {
			setMask(QRegion(0, 0, width(), height()).subtracted(QRegion(BORDER_WIDTH, BORDER_WIDTH, width() - 2 * BORDER_WIDTH, height() - 2 * BORDER_WIDTH)));
			setWindowOpacity(1.0);
		}
	}
}

void RecordingFrameWindow::resizeEvent(QResizeEvent *event) {
	Q_UNUSED(event);
	UpdateMask();
}

void RecordingFrameWindow::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	QPainter painter(this);
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
	m_texture.setDevicePixelRatio(devicePixelRatioF());
#endif
	painter.setPen(QColor(0, 0, 0, 128));
	painter.setBrush(Qt::NoBrush);
	painter.drawTiledPixmap(0, 0, width(), height(), m_texture);
	if(m_outside) {
		painter.drawRect(QRectF((qreal) BORDER_WIDTH - 0.5,
								(qreal) BORDER_WIDTH - 0.5,
								(qreal) (width() - 2 * BORDER_WIDTH) + 1.0,
								(qreal) (height() - 2 * BORDER_WIDTH) + 1.0));
	} else {
		painter.drawRect(QRectF(0.5, 0.5, (qreal) width() - 1.0, (qreal) height() - 1.0));
	}
}

PageInput::PageInput(MainWindow* main_window)
	: QWidget(main_window->centralWidget()) {

	m_main_window = main_window;

	m_grabbing = false;
	m_selecting_window = false;

	HiddenScrollArea *scrollarea = new HiddenScrollArea(this);
	QWidget *scrollarea_contents = new QWidget(scrollarea);
	scrollarea->setWidget(scrollarea_contents);
	{
		m_profile_box = new ProfileBox(tr("Input profile"), scrollarea_contents, "input-profiles", &LoadProfileSettingsCallback, &SaveProfileSettingsCallback, this);

		QGroupBox *groupbox_video = new QGroupBox(tr("Video input"), scrollarea_contents);
		{
			m_buttongroup_video_area = new QButtonGroup(groupbox_video);
			QRadioButton *radio_area_screen = new QRadioButton(tr("Record the entire screen"), groupbox_video);
			QRadioButton *radio_area_fixed = new QRadioButton(tr("Record a fixed rectangle"), groupbox_video);
			QRadioButton *radio_area_cursor = new QRadioButton(tr("Follow the cursor"), groupbox_video);
#if SSR_USE_OPENGL_RECORDING
			QRadioButton *radio_area_glinject = new QRadioButton(tr("Record OpenGL"), groupbox_video);
#endif
#if SSR_USE_V4L2
			QRadioButton *radio_area_v4l2 = new QRadioButton(tr("Record V4L2 device"), groupbox_video);
#endif
			m_buttongroup_video_area->addButton(radio_area_screen, VIDEO_AREA_SCREEN);
			m_buttongroup_video_area->addButton(radio_area_fixed, VIDEO_AREA_FIXED);
			m_buttongroup_video_area->addButton(radio_area_cursor, VIDEO_AREA_CURSOR);
#if SSR_USE_OPENGL_RECORDING
			m_buttongroup_video_area->addButton(radio_area_glinject, VIDEO_AREA_GLINJECT);
#endif
#if SSR_USE_V4L2
			m_buttongroup_video_area->addButton(radio_area_v4l2, VIDEO_AREA_V4L2);
#endif
			m_combobox_screens = new QComboBoxWithSignal(groupbox_video);
			m_combobox_screens->setToolTip(tr("Select what monitor should be recorded in a multi-monitor configuration."));
			m_checkbox_follow_fullscreen = new QCheckBox(tr("Record entire screen with cursor"), groupbox_video);
			m_checkbox_follow_fullscreen->setToolTip(tr("Record the entire screen on which the cursor is located, rather than following the cursor position."));
			m_pushbutton_video_select_rectangle = new QPushButton(tr("Select rectangle..."), groupbox_video);
			m_pushbutton_video_select_rectangle->setToolTip(tr("Use the mouse to select the recorded rectangle."));
			m_pushbutton_video_select_window = new QPushButton(tr("Select window..."), groupbox_video);
			m_pushbutton_video_select_window->setToolTip(tr("Use the mouse to select a window to record.\n"
															"Hint: If you click the border of a window, the entire window will be recorded (including the borders). Otherwise only\n"
															"the client area of the window will be recorded."));
#if SSR_USE_OPENGL_RECORDING
			m_pushbutton_video_opengl_settings = new QPushButton(tr("OpenGL settings..."), groupbox_video);
			m_pushbutton_video_opengl_settings->setToolTip(tr("Change the settings for OpenGL recording."));
#endif
#if SSR_USE_V4L2
			m_lineedit_v4l2_device = new QLineEdit(groupbox_video);
			m_lineedit_v4l2_device->setToolTip(tr("The V4L2 device to record (e.g. /dev/video0)."));
#endif
			m_label_video_x = new QLabel(tr("Left:"), groupbox_video);
			m_spinbox_video_x = new QSpinBoxWithSignal(groupbox_video);
			m_spinbox_video_x->setRange(0, SSR_MAX_IMAGE_SIZE);
			m_spinbox_video_x->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
			m_spinbox_video_x->setToolTip(tr("The x coordinate of the upper-left corner of the recorded rectangle.\n"
											 "Hint: You can also change this value with the scroll wheel or the up/down arrows."));
			m_label_video_y = new QLabel(tr("Top:"), groupbox_video);
			m_spinbox_video_y = new QSpinBoxWithSignal(groupbox_video);
			m_spinbox_video_y->setRange(0, SSR_MAX_IMAGE_SIZE);
			m_spinbox_video_y->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
			m_spinbox_video_y->setToolTip(tr("The y coordinate of the upper-left corner of the recorded rectangle.\n"
											 "Hint: You can also change this value with the scroll wheel or the up/down arrows."));
			m_label_video_w = new QLabel(tr("Width:"), groupbox_video);
			m_spinbox_video_w = new QSpinBoxWithSignal(groupbox_video);
			m_spinbox_video_w->setRange(0, SSR_MAX_IMAGE_SIZE);
			m_spinbox_video_w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
			m_spinbox_video_w->setToolTip(tr("The width of the recorded rectangle.\n"
											 "Hint: You can also change this value with the scroll wheel or the up/down arrows."));
			m_label_video_h = new QLabel(tr("Height:"), groupbox_video);
			m_spinbox_video_h = new QSpinBoxWithSignal(groupbox_video);
			m_spinbox_video_h->setRange(0, SSR_MAX_IMAGE_SIZE);
			m_spinbox_video_h->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
			m_spinbox_video_h->setToolTip(tr("The height of the recorded rectangle.\n"
											 "Hint: You can also change this value with the scroll wheel or the up/down arrows."));
			QLabel *label_frame_rate = new QLabel(tr("Frame rate:"), groupbox_video);
			m_spinbox_video_frame_rate = new QSpinBox(groupbox_video);
			m_spinbox_video_frame_rate->setRange(1, 1000);
			m_spinbox_video_frame_rate->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
			m_spinbox_video_frame_rate->setToolTip(tr("The number of frames per second in the final video. Higher frame rates use more CPU time."));
			m_checkbox_scale = new QCheckBox(tr("Scale video"), groupbox_video);
			m_checkbox_scale->setToolTip(tr("Enable or disable scaling. Scaling uses more CPU time, but if the scaled video is smaller, it could make the encoding faster."));
			m_label_video_scaled_w = new QLabel(tr("Scaled width:"), groupbox_video);
			m_spinbox_video_scaled_w = new QSpinBox(groupbox_video);
			m_spinbox_video_scaled_w->setRange(0, SSR_MAX_IMAGE_SIZE);
			m_spinbox_video_scaled_w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
			m_label_video_scaled_h = new QLabel(tr("Scaled height:"), groupbox_video);
			m_spinbox_video_scaled_h = new QSpinBox(groupbox_video);
			m_spinbox_video_scaled_h->setRange(0, SSR_MAX_IMAGE_SIZE);
			m_spinbox_video_scaled_h->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
			m_checkbox_record_cursor = new QCheckBox(tr("Record cursor"), groupbox_video);

			connect(m_buttongroup_video_area, SIGNAL(buttonClicked(int)), this, SLOT(OnUpdateVideoAreaFields()));
			connect(m_combobox_screens, SIGNAL(activated(int)), this, SLOT(OnUpdateVideoAreaFields()));
			connect(m_combobox_screens, SIGNAL(popupShown()), this, SLOT(OnIdentifyScreens()));
			connect(m_combobox_screens, SIGNAL(popupHidden()), this, SLOT(OnStopIdentifyScreens()));
			connect(m_checkbox_follow_fullscreen, SIGNAL(clicked()), this, SLOT(OnUpdateVideoAreaFields()));
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
#if SSR_USE_OPENGL_RECORDING
			connect(m_pushbutton_video_opengl_settings, SIGNAL(clicked()), this, SLOT(OnGLInjectDialog()));
#endif
			connect(m_checkbox_scale, SIGNAL(clicked()), this, SLOT(OnUpdateVideoScaleFields()));

			QVBoxLayout *layout = new QVBoxLayout(groupbox_video);
			{
				QHBoxLayout *layout2 = new QHBoxLayout();
				layout->addLayout(layout2);
				layout2->addWidget(radio_area_screen);
				layout2->addWidget(m_combobox_screens);
			}
			layout->addWidget(radio_area_fixed);
			{
				QHBoxLayout *layout2 = new QHBoxLayout();
				layout->addLayout(layout2);
				layout2->addWidget(radio_area_cursor);
				layout2->addWidget(m_checkbox_follow_fullscreen);
			}
#if SSR_USE_OPENGL_RECORDING
			layout->addWidget(radio_area_glinject);
#endif
#if SSR_USE_V4L2
			{
				QHBoxLayout *layout2 = new QHBoxLayout();
				layout->addLayout(layout2);
				layout2->addWidget(radio_area_v4l2);
				layout2->addWidget(m_lineedit_v4l2_device);
			}
#endif
			{
				QHBoxLayout *layout2 = new QHBoxLayout();
				layout->addLayout(layout2);
				layout2->addWidget(m_pushbutton_video_select_rectangle);
				layout2->addWidget(m_pushbutton_video_select_window);
#if SSR_USE_OPENGL_RECORDING
				layout2->addWidget(m_pushbutton_video_opengl_settings);
#endif
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
		QGroupBox *groupbox_audio = new QGroupBox(tr("Audio input"), scrollarea_contents);
		{
			m_checkbox_audio_enable = new QCheckBox(tr("Record audio"), groupbox_audio);
			m_label_audio_backend = new QLabel(tr("Backend:"), groupbox_audio);
			m_combobox_audio_backend = new QComboBox(groupbox_audio);
#if SSR_USE_ALSA
			m_combobox_audio_backend->addItem("ALSA");
#endif
#if SSR_USE_PULSEAUDIO
			m_combobox_audio_backend->addItem("PulseAudio");
#endif
#if SSR_USE_JACK
			m_combobox_audio_backend->addItem("JACK");
#endif
#if SSR_USE_ALSA && SSR_USE_PULSEAUDIO
			m_combobox_audio_backend->setToolTip(tr("The audio backend that will be used for recording.\n"
													"The ALSA backend will also work on systems that use PulseAudio, but it is better to use the PulseAudio backend directly."));
#else
			m_combobox_audio_backend->setToolTip(tr("The audio backend that will be used for recording."));
#endif
#if SSR_USE_ALSA
			m_label_alsa_source = new QLabel(tr("Source:"), groupbox_audio);
			m_combobox_alsa_source = new QComboBox(groupbox_audio);
			m_combobox_alsa_source->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
			m_combobox_alsa_source->setToolTip(tr("The ALSA source that will be used for recording.\n"
												  "The default is usually fine. The 'shared' sources allow multiple programs to record at the same time, but they may be less reliable."));
			m_pushbutton_alsa_refresh = new QPushButton(tr("Refresh"), groupbox_audio);
			m_pushbutton_alsa_refresh->setToolTip(tr("Refreshes the list of ALSA sources."));
#endif
#if SSR_USE_PULSEAUDIO
			m_label_pulseaudio_source = new QLabel(tr("Source:"), groupbox_audio);
			m_combobox_pulseaudio_source = new QComboBox(groupbox_audio);
			m_combobox_pulseaudio_source->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
			m_combobox_pulseaudio_source->setToolTip(tr("The PulseAudio source that will be used for recording.\n"
														"A 'monitor' is a source that records the audio played by other applications.", "Don't translate 'monitor' unless PulseAudio does this as well"));
			m_pushbutton_pulseaudio_refresh = new QPushButton(tr("Refresh"), groupbox_audio);
			m_pushbutton_pulseaudio_refresh->setToolTip(tr("Refreshes the list of PulseAudio sources."));
#endif
#if SSR_USE_JACK
			m_checkbox_jack_connect_system_capture = new QCheckBox(tr("Record system microphone"));
			m_checkbox_jack_connect_system_capture->setToolTip(tr("If checked, the ports will be automatically connected to the system capture ports."));
			m_checkbox_jack_connect_system_playback = new QCheckBox(tr("Record system speakers"));
			m_checkbox_jack_connect_system_playback->setToolTip(tr("If checked, the ports will be automatically connected to anything that connects to the system playback ports."));
#endif

			connect(m_checkbox_audio_enable, SIGNAL(clicked()), this, SLOT(OnUpdateAudioFields()));
			connect(m_combobox_audio_backend, SIGNAL(activated(int)), this, SLOT(OnUpdateAudioFields()));
#if SSR_USE_ALSA
			connect(m_pushbutton_alsa_refresh, SIGNAL(clicked()), this, SLOT(OnUpdateALSASources()));
#endif
#if SSR_USE_PULSEAUDIO
			connect(m_pushbutton_pulseaudio_refresh, SIGNAL(clicked()), this, SLOT(OnUpdatePulseAudioSources()));
#endif

			QVBoxLayout *layout = new QVBoxLayout(groupbox_audio);
			layout->addWidget(m_checkbox_audio_enable);
			{
				QGridLayout *layout2 = new QGridLayout();
				layout->addLayout(layout2);
				layout2->addWidget(m_label_audio_backend, 0, 0);
				layout2->addWidget(m_combobox_audio_backend, 0, 1, 1, 2);
#if SSR_USE_ALSA
				layout2->addWidget(m_label_alsa_source, 1, 0);
				layout2->addWidget(m_combobox_alsa_source, 1, 1);
				layout2->addWidget(m_pushbutton_alsa_refresh, 1, 2);
#endif
#if SSR_USE_PULSEAUDIO
				layout2->addWidget(m_label_pulseaudio_source, 2, 0);
				layout2->addWidget(m_combobox_pulseaudio_source, 2, 1);
				layout2->addWidget(m_pushbutton_pulseaudio_refresh, 2, 2);
#endif
			}
#if SSR_USE_JACK
			{
				QHBoxLayout *layout2 = new QHBoxLayout();
				layout->addLayout(layout2);
				layout2->addWidget(m_checkbox_jack_connect_system_capture);
				layout2->addWidget(m_checkbox_jack_connect_system_playback);
			}
#endif
		}

		QVBoxLayout *layout = new QVBoxLayout(scrollarea_contents);
		layout->addWidget(m_profile_box);
		layout->addWidget(groupbox_video);
		layout->addWidget(groupbox_audio);
		layout->addStretch();
	}

	QPushButton *button_back = new QPushButton(g_icon_go_previous, tr("Back"), this);
	QPushButton *button_continue = new QPushButton(g_icon_go_next, tr("Continue"), this);

	connect(button_back, SIGNAL(clicked()), m_main_window, SLOT(GoPageWelcome()));
	connect(button_continue, SIGNAL(clicked()), this, SLOT(OnContinue()));

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(scrollarea);
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addSpacing(style()->pixelMetric(QStyle::PM_LayoutLeftMargin));
		layout2->addWidget(button_back);
		layout2->addWidget(button_continue);
		layout2->addSpacing(style()->pixelMetric(QStyle::PM_LayoutRightMargin));
	}
	layout->addSpacing(style()->pixelMetric(QStyle::PM_LayoutBottomMargin));

	connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this, SLOT(OnFocusChange(QWidget*, QWidget*)));
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
	connect(qApp, SIGNAL(screenAdded(QScreen*)), this, SLOT(OnScreenAdded(QScreen*)));
	connect(qApp, SIGNAL(screenRemoved(QScreen*)), this, SLOT(OnUpdateScreenConfiguration()));
#else
	connect(QApplication::desktop(), SIGNAL(screenCountChanged(int)), this, SLOT(OnUpdateScreenConfiguration()));
	connect(QApplication::desktop(), SIGNAL(resized(int)), this, SLOT(OnUpdateScreenConfiguration()));
#endif

	LoadScreenConfigurations();
#if SSR_USE_ALSA
	LoadALSASources();
#endif
#if SSR_USE_PULSEAUDIO
	LoadPulseAudioSources();
#endif

	// temporary settings to calculate the worst-case size
	SetAudioEnabled(true);
#if SSR_USE_ALSA
	SetAudioBackend(AUDIO_BACKEND_ALSA);
#else
#if SSR_USE_PULSEAUDIO
	SetAudioBackend(AUDIO_BACKEND_PULSEAUDIO);
#else
#if SSR_USE_JACK
	SetAudioBackend(AUDIO_BACKEND_JACK);
#else
#error "At least one audio backend must be enabled!"
#endif
#endif
#endif

	OnUpdateVideoAreaFields();
	OnUpdateVideoScaleFields();
	OnUpdateAudioFields();

}

void PageInput::LoadSettings(QSettings* settings) {
	SetProfile(m_profile_box->FindProfile(settings->value("input/profile", QString()).toString()));
	LoadProfileSettings(settings);
}

void PageInput::SaveSettings(QSettings* settings) {
	settings->setValue("input/profile", m_profile_box->GetProfileName());
	SaveProfileSettings(settings);
}

void PageInput::LoadProfileSettingsCallback(QSettings* settings, void* userdata) {
	PageInput *page = (PageInput*) userdata;
	page->LoadProfileSettings(settings);
}

void PageInput::SaveProfileSettingsCallback(QSettings* settings, void* userdata) {
	PageInput *page = (PageInput*) userdata;
	page->SaveProfileSettings(settings);
}

void PageInput::LoadProfileSettings(QSettings* settings) {

	// choose default audio backend
#if SSR_USE_ALSA
#if SSR_USE_PULSEAUDIO
	enum_audio_backend default_audio_backend = (m_pulseaudio_available)? AUDIO_BACKEND_PULSEAUDIO : AUDIO_BACKEND_ALSA;
#else
	enum_audio_backend default_audio_backend = AUDIO_BACKEND_ALSA;
#endif
#else
#if SSR_USE_PULSEAUDIO
	enum_audio_backend default_audio_backend = AUDIO_BACKEND_PULSEAUDIO;
#else
#if SSR_USE_JACK
	enum_audio_backend default_audio_backend = AUDIO_BACKEND_JACK;
#else
#error "At least one audio backend must be enabled!"
#endif
#endif
#endif

	// load settings
	SetVideoArea(StringToEnum(settings->value("input/video_area", QString()).toString(), VIDEO_AREA_SCREEN));
	SetVideoAreaScreen(settings->value("input/video_area_screen", 0).toUInt());
	SetVideoAreaFollowFullscreen(settings->value("input/video_area_follow_fullscreen", false).toBool());
#if SSR_USE_V4L2
	SetVideoV4L2Device(settings->value("input/video_v4l2_device", "/dev/video0").toString());
#endif
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
	SetAudioBackend(StringToEnum(settings->value("input/audio_backend", QString()).toString(), default_audio_backend));
#if SSR_USE_ALSA
	SetALSASource(FindALSASource(settings->value("input/audio_alsa_source", QString()).toString()));
#endif
#if SSR_USE_PULSEAUDIO
	SetPulseAudioSource(FindPulseAudioSource(settings->value("input/audio_pulseaudio_source", QString()).toString()));
#endif
#if SSR_USE_JACK
	SetJackConnectSystemCapture(settings->value("input/audio_jack_connect_system_capture", true).toBool());
	SetJackConnectSystemPlayback(settings->value("input/audio_jack_connect_system_playback", false).toBool());
#endif
#if SSR_USE_OPENGL_RECORDING
	SetGLInjectChannel(settings->value("input/glinject_channel", QString()).toString());
	SetGLInjectRelaxPermissions(settings->value("input/glinject_relax_permissions", false).toBool());
	SetGLInjectCommand(settings->value("input/glinject_command", "").toString());
	SetGLInjectWorkingDirectory(settings->value("input/glinject_working_directory", "").toString());
	SetGLInjectAutoLaunch(settings->value("input/glinject_auto_launch", false).toBool());
	SetGLInjectLimitFPS(settings->value("input/glinject_limit_fps", false).toBool());
#endif

	// update things
	OnUpdateRecordingFrame();
	OnUpdateVideoAreaFields();
	OnUpdateVideoScaleFields();
	OnUpdateAudioFields();

}

void PageInput::SaveProfileSettings(QSettings* settings) {
	settings->setValue("input/video_area", EnumToString(GetVideoArea()));
	settings->setValue("input/video_area_screen", GetVideoAreaScreen());
	settings->setValue("input/video_area_follow_fullscreen", GetVideoAreaFollowFullscreen());
#if SSR_USE_V4L2
	settings->setValue("input/video_v4l2_device", GetVideoV4L2Device());
#endif
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
	settings->setValue("input/audio_backend", EnumToString(GetAudioBackend()));
#if SSR_USE_ALSA
	settings->setValue("input/audio_alsa_source", GetALSASourceName());
#endif
#if SSR_USE_PULSEAUDIO
	settings->setValue("input/audio_pulseaudio_source", GetPulseAudioSourceName());
#endif
#if SSR_USE_JACK
	settings->setValue("input/audio_jack_connect_system_capture", GetJackConnectSystemCapture());
	settings->setValue("input/audio_jack_connect_system_playback", GetJackConnectSystemPlayback());
#endif
#if SSR_USE_OPENGL_RECORDING
	settings->setValue("input/glinject_channel", GetGLInjectChannel());
	settings->setValue("input/glinject_relax_permissions", GetGLInjectRelaxPermissions());
	settings->setValue("input/glinject_command", GetGLInjectCommand());
	settings->setValue("input/glinject_working_directory", GetGLInjectWorkingDirectory());
	settings->setValue("input/glinject_auto_launch", GetGLInjectAutoLaunch());
	settings->setValue("input/glinject_limit_fps", GetGLInjectLimitFPS());
#endif
}

bool PageInput::Validate() {
	if(m_grabbing)
		return false;
	return true;
}

#if SSR_USE_ALSA
QString PageInput::GetALSASourceName() {
	return QString::fromStdString(m_alsa_sources[GetALSASource()].m_name);
}
#endif

#if SSR_USE_PULSEAUDIO
QString PageInput::GetPulseAudioSourceName() {
	return QString::fromStdString(m_pulseaudio_sources[GetPulseAudioSource()].m_name);
}
#endif

#if SSR_USE_ALSA
unsigned int PageInput::FindALSASource(const QString& name) {
	for(unsigned int i = 0; i < m_alsa_sources.size(); ++i) {
		if(QString::fromStdString(m_alsa_sources[i].m_name) == name)
			return i;
	}
	return 0;
}
#endif

#if SSR_USE_PULSEAUDIO
unsigned int PageInput::FindPulseAudioSource(const QString& name) {
	for(unsigned int i = 0; i < m_pulseaudio_sources.size(); ++i) {
		if(QString::fromStdString(m_pulseaudio_sources[i].m_name) == name)
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
			if(IsPlatformX11()) {
				QPoint mouse_physical = GetMousePhysicalCoordinates();
				if(m_selecting_window) {
					// As expected, Qt does not provide any functions to find the window at a specific position, so I have to use Xlib directly.
					// I'm not completely sure whether this is the best way to do this, but it appears to work. XQueryPointer returns the window
					// currently below the mouse along with the mouse position, but apparently this may not work correctly when the mouse pointer
					// is also grabbed (even though it works fine in my test), so I use XTranslateCoordinates instead. Originally I wanted to
					// show the rubber band when the mouse hovers over a window (instead of having to click it), but this doesn't work correctly
					// since X will simply return a handle the rubber band itself (even though it should be transparent to mouse events).
					Window selected_window;
					int x, y;
					if(XTranslateCoordinates(QX11Info::display(), QX11Info::appRootWindow(), QX11Info::appRootWindow(), mouse_physical.x(), mouse_physical.y(), &x, &y, &selected_window)) {
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
							m_rubber_band_rect = (m_select_window_inner_rect.contains(mouse_physical))? m_select_window_inner_rect : m_select_window_outer_rect;
							UpdateRubberBand();

						}
					}
				} else {
					m_rubber_band_rect = QRect(mouse_physical, mouse_physical);
					UpdateRubberBand();
				}
			}
		} else {
			StopGrabbing();
		}
		event->accept();
		return;
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
		event->accept();
		return;
	}
	event->ignore();
}

void PageInput::mouseMoveEvent(QMouseEvent* event) {
	if(m_grabbing) {
		if(m_rubber_band != NULL && IsPlatformX11()) {
			QPoint mouse_physical = GetMousePhysicalCoordinates();
			if(m_selecting_window) {
				// pick the inner rectangle if the user clicks inside the window, or the outer rectangle otherwise
				m_rubber_band_rect = (m_select_window_inner_rect.contains(mouse_physical))? m_select_window_inner_rect : m_select_window_outer_rect;
			} else {
				m_rubber_band_rect.setBottomRight(mouse_physical);
			}
			UpdateRubberBand();
		}
		event->accept();
		return;
	}
	event->ignore();
}

void PageInput::keyPressEvent(QKeyEvent* event) {
	if(m_grabbing) {
		if(event->key() == Qt::Key_Escape) {
			StopGrabbing();
			return;
		}
		event->accept();
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

void PageInput::UpdateRubberBand() {
	if(m_rubber_band == NULL)
		m_rubber_band.reset(new RecordingFrameWindow(this, false));
	m_rubber_band->SetRectangle(m_rubber_band_rect);
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
	std::vector<QRect> screen_geometries = GetScreenGeometries();
	QRect combined_geometry = CombineScreenGeometries(screen_geometries);
	m_combobox_screens->clear();
	m_combobox_screens->addItem(tr("All screens: %1x%2", "This appears in the screen selection combobox")
								.arg(combined_geometry.width()).arg(combined_geometry.height()));
	for(size_t i = 0; i < screen_geometries.size(); ++i) {
		QRect &geometry = screen_geometries[i];
		m_combobox_screens->addItem(tr("Screen %1: %2x%3 at %4,%5", "This appears in the screen selection combobox")
									.arg(i + 1).arg(geometry.width()).arg(geometry.height()).arg(geometry.x()).arg(geometry.y()));
	}
	// update the video x/y/w/h in case the position or size of the selected screen changed
	OnUpdateVideoAreaFields();
}

#if SSR_USE_ALSA
void PageInput::LoadALSASources() {
	m_alsa_sources = ALSAInput::GetSourceList();
	if(m_alsa_sources.empty()) {
		m_alsa_sources.push_back(ALSAInput::Source("", "(no sources found)"));
	}
	m_combobox_alsa_source->clear();
	for(unsigned int i = 0; i < m_alsa_sources.size(); ++i) {
		QString elided = m_combobox_alsa_source->fontMetrics().elidedText("\u200e[" + QString::fromStdString(m_alsa_sources[i].m_name) + "] "
																		  + QString::fromStdString(m_alsa_sources[i].m_description), Qt::ElideMiddle, 400) + "\u200e";
		m_combobox_alsa_source->addItem(elided);
	}
}
#endif

#if SSR_USE_PULSEAUDIO
void PageInput::LoadPulseAudioSources() {
	m_pulseaudio_sources = PulseAudioInput::GetSourceList();
	if(m_pulseaudio_sources.empty()) {
		m_pulseaudio_available = false;
		m_pulseaudio_sources.push_back(PulseAudioInput::Source("", "(no sources found)"));
	} else {
		m_pulseaudio_available = true;
	}
	m_combobox_pulseaudio_source->clear();
	for(unsigned int i = 0; i < m_pulseaudio_sources.size(); ++i) {
		QString elided = m_combobox_pulseaudio_source->fontMetrics().elidedText(QString::fromStdString(m_pulseaudio_sources[i].m_description), Qt::ElideMiddle, 400);
		m_combobox_pulseaudio_source->addItem("\u200e" + elided + "\u200e");
	}
}
#endif

void PageInput::OnUpdateRecordingFrame() {
	if(m_spinbox_video_x->hasFocus() || m_spinbox_video_y->hasFocus() || m_spinbox_video_w->hasFocus() || m_spinbox_video_h->hasFocus()) {
		if(m_recording_frame == NULL)
			m_recording_frame.reset(new RecordingFrameWindow(this, false));
		m_recording_frame->SetRectangle(QRect(GetVideoX(), GetVideoY(), GetVideoW(), GetVideoH()));
	} else {
		m_recording_frame.reset();
	}
}

void PageInput::OnUpdateVideoAreaFields() {
	switch(GetVideoArea()) {
		case VIDEO_AREA_SCREEN: {
			m_combobox_screens->setEnabled(true);
			m_checkbox_follow_fullscreen->setEnabled(false);
			m_pushbutton_video_select_rectangle->setEnabled(false);
			m_pushbutton_video_select_window->setEnabled(false);
#if SSR_USE_OPENGL_RECORDING
			m_pushbutton_video_opengl_settings->setEnabled(false);
#endif
#if SSR_USE_V4L2
			m_lineedit_v4l2_device->setEnabled(false);
#endif
			m_checkbox_record_cursor->setEnabled(true);
			GroupEnabled({m_label_video_x, m_spinbox_video_x, m_label_video_y, m_spinbox_video_y,
						  m_label_video_w, m_spinbox_video_w, m_label_video_h, m_spinbox_video_h}, false);
			int sc = m_combobox_screens->currentIndex();
			std::vector<QRect> screen_geometries = GetScreenGeometries();
			QRect rect;
			if(sc > 0 && sc <= (int) screen_geometries.size()) {
				rect = screen_geometries[sc - 1];
			} else {
				rect = CombineScreenGeometries(screen_geometries);
			}
			SetVideoX(rect.left());
			SetVideoY(rect.top());
			SetVideoW(rect.width());
			SetVideoH(rect.height());
			break;
		}
		case VIDEO_AREA_FIXED: {
			m_combobox_screens->setEnabled(false);
			m_checkbox_follow_fullscreen->setEnabled(false);
			m_pushbutton_video_select_rectangle->setEnabled(true);
			m_pushbutton_video_select_window->setEnabled(true);
#if SSR_USE_OPENGL_RECORDING
			m_pushbutton_video_opengl_settings->setEnabled(false);
#endif
#if SSR_USE_V4L2
			m_lineedit_v4l2_device->setEnabled(false);
#endif
			m_checkbox_record_cursor->setEnabled(true);
			GroupEnabled({m_label_video_x, m_spinbox_video_x, m_label_video_y, m_spinbox_video_y,
						  m_label_video_w, m_spinbox_video_w, m_label_video_h, m_spinbox_video_h}, true);
			break;
		}
		case VIDEO_AREA_CURSOR: {
			m_combobox_screens->setEnabled(false);
			m_checkbox_follow_fullscreen->setEnabled(true);
#if SSR_USE_OPENGL_RECORDING
			m_pushbutton_video_opengl_settings->setEnabled(false);
#endif
#if SSR_USE_V4L2
			m_lineedit_v4l2_device->setEnabled(false);
#endif
			m_checkbox_record_cursor->setEnabled(true);
			if(m_checkbox_follow_fullscreen->isChecked()) {
				m_pushbutton_video_select_rectangle->setEnabled(false);
				m_pushbutton_video_select_window->setEnabled(false);
				GroupEnabled({m_label_video_x, m_spinbox_video_x, m_label_video_y, m_spinbox_video_y,
							  m_label_video_w, m_spinbox_video_w, m_label_video_h, m_spinbox_video_h}, false);
				std::vector<QRect> screen_geometries = GetScreenGeometries();
				QRect rect = (screen_geometries.size() == 0)? QRect(0, 0, 0, 0) : screen_geometries[0];
				SetVideoX(rect.left());
				SetVideoY(rect.top());
				SetVideoW(rect.width());
				SetVideoH(rect.height());
			} else {
				m_pushbutton_video_select_rectangle->setEnabled(true);
				m_pushbutton_video_select_window->setEnabled(true);
				GroupEnabled({m_label_video_x, m_spinbox_video_x, m_label_video_y, m_spinbox_video_y}, false);
				GroupEnabled({m_label_video_w, m_spinbox_video_w, m_label_video_h, m_spinbox_video_h}, true);
				SetVideoX(0);
				SetVideoY(0);
			}
			break;
		}
#if SSR_USE_OPENGL_RECORDING
		case VIDEO_AREA_GLINJECT: {
			m_combobox_screens->setEnabled(false);
			m_checkbox_follow_fullscreen->setEnabled(false);
			m_pushbutton_video_select_rectangle->setEnabled(false);
			m_pushbutton_video_select_window->setEnabled(false);
			m_pushbutton_video_opengl_settings->setEnabled(true);
#if SSR_USE_V4L2
			m_lineedit_v4l2_device->setEnabled(false);
#endif
			m_checkbox_record_cursor->setEnabled(true);
			GroupEnabled({m_label_video_x, m_spinbox_video_x, m_label_video_y, m_spinbox_video_y,
						  m_label_video_w, m_spinbox_video_w, m_label_video_h, m_spinbox_video_h}, false);
			break;
		}
#endif
#if SSR_USE_V4L2
		case VIDEO_AREA_V4L2: {
			m_combobox_screens->setEnabled(false);
			m_checkbox_follow_fullscreen->setEnabled(false);
			m_pushbutton_video_select_rectangle->setEnabled(false);
			m_pushbutton_video_select_window->setEnabled(false);
#if SSR_USE_OPENGL_RECORDING
			m_pushbutton_video_opengl_settings->setEnabled(false);
#endif
			m_lineedit_v4l2_device->setEnabled(true);
			m_checkbox_record_cursor->setEnabled(false);
			GroupEnabled({m_label_video_x, m_spinbox_video_x, m_label_video_y, m_spinbox_video_y}, false);
			GroupEnabled({m_label_video_w, m_spinbox_video_w, m_label_video_h, m_spinbox_video_h}, true);
			break;
		}
#endif
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
		m_label_audio_backend, m_combobox_audio_backend,
#if SSR_USE_ALSA
		m_label_alsa_source, m_combobox_alsa_source, m_pushbutton_alsa_refresh,
#endif
#if SSR_USE_PULSEAUDIO
		m_label_pulseaudio_source, m_combobox_pulseaudio_source, m_pushbutton_pulseaudio_refresh,
#endif
#if SSR_USE_JACK
		m_checkbox_jack_connect_system_capture, m_checkbox_jack_connect_system_playback,
#endif
	}, enabled);
	MultiGroupVisible({
#if SSR_USE_ALSA
		{{m_label_alsa_source, m_combobox_alsa_source, m_pushbutton_alsa_refresh}, (backend == AUDIO_BACKEND_ALSA)},
#endif
#if SSR_USE_PULSEAUDIO
		{{m_label_pulseaudio_source, m_combobox_pulseaudio_source, m_pushbutton_pulseaudio_refresh}, (backend == AUDIO_BACKEND_PULSEAUDIO)},
#endif
#if SSR_USE_JACK
		{{m_checkbox_jack_connect_system_capture, m_checkbox_jack_connect_system_playback}, (backend == AUDIO_BACKEND_JACK)},
#endif
	});
}

void PageInput::OnFocusChange(QWidget* old, QWidget* now) {
	Q_UNUSED(old);
	if(m_grabbing && now != NULL && now->window() != window()) {
		// workaround to avoid a deadlock situation when a modal dialog appears
		StopGrabbing();
	}
}

#if QT_VERSION_MAJOR >= 5
void PageInput::OnScreenAdded(QScreen* screen) {
	connect(screen, SIGNAL(geometryChanged()), this, SLOT(OnUpdateScreenConfiguration()));
	connect(screen, SIGNAL(physicalDotsPerInchChanged()), this, SLOT(OnUpdateScreenConfiguration()));
	OnUpdateScreenConfiguration();
}
#endif

void PageInput::OnUpdateScreenConfiguration() {
	unsigned int selected_screen = GetVideoAreaScreen();
	LoadScreenConfigurations();
	SetVideoAreaScreen(selected_screen);
}

#if SSR_USE_ALSA
void PageInput::OnUpdateALSASources() {
	QString selected_source = GetALSASourceName();
	LoadALSASources();
	SetALSASource(FindALSASource(selected_source));
}
#endif

#if SSR_USE_PULSEAUDIO
void PageInput::OnUpdatePulseAudioSources() {
	QString selected_source = GetPulseAudioSourceName();
	LoadPulseAudioSources();
	SetPulseAudioSource(FindPulseAudioSource(selected_source));
}
#endif

void PageInput::OnIdentifyScreens() {
	OnStopIdentifyScreens();
	std::vector<QRect> screen_geometries = GetScreenGeometries();
	for(size_t i = 0; i < screen_geometries.size(); ++i) {
		QRect &rect = screen_geometries[i];
		ScreenLabelWindow *label = new ScreenLabelWindow(this, tr("Screen %1", "This appears in the screen labels").arg(i + 1));
		label->move(rect.x(), rect.y());
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

#if SSR_USE_OPENGL_RECORDING
void PageInput::OnGLInjectDialog() {
	DialogGLInject dialog(this);
	dialog.exec();
}
#endif

void PageInput::OnContinue() {
	if(!Validate())
		return;
	m_main_window->GoPageOutput();
}
