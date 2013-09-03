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
#include "PageRecord.h"

#include "MainWindow.h"
#include "PageInput.h"
#include "PageOutput.h"

#include "HotkeyListener.h"

#include "Muxer.h"
#include "VideoEncoder.h"
#include "AudioEncoder.h"
#include "Synchronizer.h"
#include "X11Input.h"
#include "GLInjectLauncher.h"
#include "GLInjectInput.h"
#include "ALSAInput.h"
#include "VideoPreviewer.h"
#include "AudioPreviewer.h"

#include <X11/keysym.h>
#include <X11/keysymdef.h>

static QString GetNewSegmentFile(const QString& file, unsigned int* counter, bool check_existing) {
	QFileInfo fi(file);
	QString path = fi.path(), basename = fi.completeBaseName(), suffix = fi.suffix();
	QString newfile;
	do {
		++*counter;
		if(suffix.isEmpty())
			newfile = path + "/" + basename + QString("-%1").arg(*counter, 4, 10, QLatin1Char('0'));
		else
			newfile = path + "/" + basename + QString("-%1").arg(*counter, 4, 10, QLatin1Char('0')) + "." + suffix;
	} while(check_existing && QFileInfo(newfile).exists());
	return newfile;
}

static std::vector<std::pair<QString, QString> > GetOptionsFromString(const QString& str) {
	std::vector<std::pair<QString, QString> > options;
	QStringList optionlist = str.split(',', QString::SkipEmptyParts);
	for(int i = 0; i < optionlist.size(); ++i) {
		QString a = optionlist[i];
		int p = a.indexOf('=');
		if(p < 0) {
			options.push_back(std::make_pair(a.trimmed(), QString()));
		} else {
			options.push_back(std::make_pair(a.mid(0, p).trimmed(), a.mid(p + 1).trimmed()));
		}
	}
	return options;
}

static QString ReadableSize(uint64_t size, const QString& suffix) {
	if(size < (uint64_t) 10 * 1024)
		return QString::number(size) + " " + suffix;
	if(size < (uint64_t) 10 * 1024 * 1024)
		return QString::number((size + 512) / 1024) + " k" + suffix;
	if(size < (uint64_t) 10 * 1024 * 1024 * 1024)
		return QString::number((size / 1024 + 512) / 1024) + " M" + suffix;
	return QString::number((size / 1024 / 1024 + 512) / 1024) + " G" + suffix;
}

static QString ReadableTime(int64_t time_micro) {
	unsigned int time = (time_micro + 500000) / 1000000;
	return QString("%1:%2:%3")
			.arg(time / 3600)
			.arg((time / 60) % 60, 2, 10, QLatin1Char('0'))
			.arg(time % 60, 2, 10, QLatin1Char('0'));
}

static QString ReadableWidthHeight(unsigned int width, unsigned int height) {
	if(width == 0 && height == 0)
		return "?";
	return QString::number(width) + "x" + QString::number(height);
}

class QTextEditSmall : public QTextEdit {

public:
	QTextEditSmall(QWidget *parent) : QTextEdit(parent) {}
	QTextEditSmall(const QString& text, QWidget *parent) : QTextEdit(text, parent) {}
	virtual QSize sizeHint() const { return QSize(-1, 100); }

};

const int PageRecord::PRIORITY_RECORD = 0;
const int PageRecord::PRIORITY_PREVIEW = -1;

PageRecord::PageRecord(MainWindow* main_window)
	: QWidget(main_window->centralWidget()) {

	m_main_window = main_window;

	m_page_started = false;
	m_capturing = false;
	m_recording = false;
	m_previewing = false;

	QGroupBox *group_recording = new QGroupBox("Recording", this);
	{
		m_pushbutton_start_pause = new QPushButton(group_recording);

		m_checkbox_hotkey_enable = new QCheckBox("Enable recording hotkey", group_recording);
		QLabel *label_hotkey = new QLabel("Hotkey:", group_recording);
		m_checkbox_hotkey_ctrl = new QCheckBox("Ctrl +", group_recording);
		m_checkbox_hotkey_shift = new QCheckBox("Shift +", group_recording);
		m_checkbox_hotkey_alt = new QCheckBox("Alt +", group_recording);
		m_checkbox_hotkey_super = new QCheckBox("Super +", group_recording);
		m_combobox_hotkey_key = new QComboBox(group_recording);
		m_combobox_hotkey_key->setToolTip("The key that you have to press (combined with the given modifiers) to start or pause recording. The program that you are\n"
										  "recording will not receive the key press.\n\n"
										  "Note: The choice of keys is currently rather limited, because capturing key presses session-wide is a bit harder than it looks. For\n"
										  "example, applications are not allowed to capture the F1-F12 keys (on Ubuntu at least). The A-Z keys don't have this limitation apparently.");
		QLabel *label_hint_workspace = new QLabel("Hint: If you want to hide this program completely, move it to a different workspace.", group_recording);
		label_hint_workspace->setWordWrap(true);
		for(unsigned int i = 0; i < 26; ++i) {
			m_combobox_hotkey_key->addItem(QString('A' + i));
		}

		connect(m_pushbutton_start_pause, SIGNAL(clicked()), this, SLOT(RecordStartPause()));
		connect(m_checkbox_hotkey_enable, SIGNAL(clicked()), this, SLOT(UpdateHotkeyFields()));
		connect(m_checkbox_hotkey_ctrl, SIGNAL(clicked()), this, SLOT(UpdateHotkey()));
		connect(m_checkbox_hotkey_shift, SIGNAL(clicked()), this, SLOT(UpdateHotkey()));
		connect(m_checkbox_hotkey_alt, SIGNAL(clicked()), this, SLOT(UpdateHotkey()));
		connect(m_checkbox_hotkey_super, SIGNAL(clicked()), this, SLOT(UpdateHotkey()));
		connect(m_combobox_hotkey_key, SIGNAL(activated(int)), this, SLOT(UpdateHotkey()));

		QVBoxLayout *layout = new QVBoxLayout(group_recording);
		layout->addWidget(m_pushbutton_start_pause);
		layout->addWidget(m_checkbox_hotkey_enable);
		{
			QHBoxLayout *layout2 = new QHBoxLayout();
			layout->addLayout(layout2);
			layout2->addWidget(label_hotkey);
			layout2->addWidget(m_checkbox_hotkey_ctrl);
			layout2->addWidget(m_checkbox_hotkey_shift);
			layout2->addWidget(m_checkbox_hotkey_alt);
			layout2->addWidget(m_checkbox_hotkey_super);
			layout2->addWidget(m_combobox_hotkey_key);
		}
		layout->addWidget(label_hint_workspace);
	}
	QSplitter *splitter_vertical = new QSplitter(Qt::Vertical, this);
	{
		QSplitter *splitter_horizontal = new QSplitter(Qt::Horizontal, splitter_vertical);
		{
			QGroupBox *group_information = new QGroupBox("Information", splitter_horizontal);
			{
				QLabel *label_total_time = new QLabel("Total time:", group_information);
				m_label_info_total_time = new QLabel(group_information);
				QLabel *label_frame_rate_in = new QLabel("FPS in:", group_information);
				m_label_info_frame_rate_in = new QLabel(group_information);
				QLabel *label_frame_rate_out = new QLabel("FPS out:", group_information);
				m_label_info_frame_rate_out = new QLabel(group_information);
				QLabel *label_size_in = new QLabel("Size in:", group_information);
				m_label_info_size_in = new QLabel(group_information);
				QLabel *label_size_out = new QLabel("Size out:", group_information);
				m_label_info_size_out = new QLabel(group_information);
				QLabel *label_file_name = new QLabel("File name:", group_information);
				m_label_info_file_name = new ElidedLabel(QString(), Qt::ElideMiddle, group_information);
				m_label_info_file_name->setMinimumWidth(100);
				QLabel *label_file_size = new QLabel("File size:", group_information);
				m_label_info_file_size = new QLabel(group_information);
				QLabel *label_bit_rate = new QLabel("Bit rate:", group_information);
				m_label_info_bit_rate = new QLabel(group_information);

				QGridLayout *layout = new QGridLayout(group_information);
				layout->addWidget(label_total_time, 0, 0);
				layout->addWidget(m_label_info_total_time, 0, 1);
				layout->addWidget(label_frame_rate_in, 1, 0);
				layout->addWidget(m_label_info_frame_rate_in, 1, 1);
				layout->addWidget(label_frame_rate_out, 2, 0);
				layout->addWidget(m_label_info_frame_rate_out, 2, 1);
				layout->addWidget(label_size_in, 3, 0);
				layout->addWidget(m_label_info_size_in, 3, 1);
				layout->addWidget(label_size_out, 4, 0);
				layout->addWidget(m_label_info_size_out, 4, 1);
				layout->addWidget(label_file_name, 5, 0);
				layout->addWidget(m_label_info_file_name, 5, 1);
				layout->addWidget(label_file_size, 6, 0);
				layout->addWidget(m_label_info_file_size, 6, 1);
				layout->addWidget(label_bit_rate, 7, 0);
				layout->addWidget(m_label_info_bit_rate, 7, 1);
				layout->setColumnStretch(1, 1);
				layout->setRowStretch(8, 1);
			}
			QGroupBox *group_preview = new QGroupBox("Preview", splitter_horizontal);
			{
				m_preview_page1 = new QWidget(group_preview);
				{
					QLabel *label_preview_frame_rate = new QLabel("Preview frame rate:", m_preview_page1);
					m_spinbox_preview_frame_rate = new QSpinBox(m_preview_page1);
					m_spinbox_preview_frame_rate->setRange(1, 1000);
					m_spinbox_preview_frame_rate->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
					QLabel *label_preview_note = new QLabel("Note: Previewing requires extra CPU time (especially at high frame rates).", m_preview_page1);
					label_preview_note->setWordWrap(true);
					label_preview_note->setAlignment(Qt::AlignLeft | Qt::AlignTop);
					label_preview_note->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::MinimumExpanding);

					QGridLayout *layout = new QGridLayout(m_preview_page1);
					layout->setMargin(0);
					layout->addWidget(label_preview_frame_rate, 0, 0);
					layout->addWidget(m_spinbox_preview_frame_rate, 0, 1);
					layout->addWidget(label_preview_note, 1, 0, 1, 2);
				}
				m_preview_page2 = new QWidget(group_preview);
				{
					m_video_previewer = new VideoPreviewer(m_preview_page2);
					m_label_mic_icon = new QLabel(m_preview_page2);
					m_label_mic_icon->setPixmap(QIcon::fromTheme("audio-input-microphone").pixmap(24, 24));
					m_audio_previewer = new AudioPreviewer(m_preview_page2);

					QVBoxLayout *layout = new QVBoxLayout(m_preview_page2);
					layout->setMargin(0);
					layout->addWidget(m_video_previewer);
					{
						QHBoxLayout *layout2 = new QHBoxLayout();
						layout->addLayout(layout2);
						layout2->addStretch();
						layout2->addWidget(m_label_mic_icon);
						layout2->addWidget(m_audio_previewer);
						layout2->addStretch();
					}
				}
				m_pushbutton_preview_start_stop = new QPushButton(group_preview);

				connect(m_pushbutton_preview_start_stop, SIGNAL(clicked()), this, SLOT(PreviewStartStop()));

				QVBoxLayout *layout = new QVBoxLayout(group_preview);
				{
					m_stacked_layout_preview = new QStackedLayout();
					layout->addLayout(m_stacked_layout_preview);
					m_stacked_layout_preview->addWidget(m_preview_page1);
					m_stacked_layout_preview->addWidget(m_preview_page2);
				}
				layout->addWidget(m_pushbutton_preview_start_stop);
			}

			splitter_horizontal->addWidget(group_information);
			splitter_horizontal->addWidget(group_preview);
			splitter_horizontal->setStretchFactor(0, 1);
			splitter_horizontal->setStretchFactor(1, 3);
		}
		QGroupBox *group_log = new QGroupBox("Log", splitter_vertical);
		{
			m_textedit_log = new QTextEditSmall(group_log);
			m_textedit_log->setReadOnly(true);

			QVBoxLayout *layout = new QVBoxLayout(group_log);
			layout->addWidget(m_textedit_log);
		}

		splitter_vertical->addWidget(splitter_horizontal);
		splitter_vertical->addWidget(group_log);
		splitter_vertical->setStretchFactor(0, 3);
		splitter_vertical->setStretchFactor(1, 1);
	}

	QPushButton *button_cancel = new QPushButton(QIcon::fromTheme("process-stop"), "Cancel recording", this);
	QPushButton *button_save = new QPushButton(QIcon::fromTheme("document-save"), "Save recording", this);

	connect(button_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
	connect(button_save, SIGNAL(clicked()), this, SLOT(Save()));

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(group_recording);
	layout->addWidget(splitter_vertical);
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addWidget(button_cancel);
		layout2->addWidget(button_save);
	}

	UpdateRecordPauseButton();
	UpdatePreview();

	m_info_timer = new QTimer(this);
	m_glinject_event_timer = new QTimer(this);
	connect(m_info_timer, SIGNAL(timeout()), this, SLOT(UpdateInformation()));
	connect(m_glinject_event_timer, SIGNAL(timeout()), this, SLOT(CheckGLInjectEvents()));
	connect(&g_hotkey_listener, SIGNAL(Triggered()), this, SLOT(RecordStartPause()));
	connect(Logger::GetInstance(), SIGNAL(NewLine(Logger::enum_type,QString)), this, SLOT(UpdateLog(Logger::enum_type,QString)), Qt::QueuedConnection);

}

PageRecord::~PageRecord() {
	PageStop(false);
}

bool PageRecord::ShouldBlockClose() {

	if(m_output_manager != NULL) {
		if(QMessageBox::warning(this, MainWindow::WINDOW_CAPTION,
								"You have not saved the current recording yet, if you quit now it will be lost.\n"
								"Are you sure you want to quit?", QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
			return true;
		}
	}

	return false;

}

void PageRecord::LoadSettings(QSettings *settings) {
	SetHotkeyEnabled(settings->value("record/hotkey_enable", true).toBool());
	SetHotkeyCtrlEnabled(settings->value("record/hotkey_ctrl", true).toBool());
	SetHotkeyShiftEnabled(settings->value("record/hotkey_shift", false).toBool());
	SetHotkeyAltEnabled(settings->value("record/hotkey_alt", false).toBool());
	SetHotkeySuperEnabled(settings->value("record/hotkey_super", false).toBool());
	SetHotkeyKey(settings->value("record/hotkey_key", 'r' - 'a').toUInt());
	SetPreviewFrameRate(settings->value("record/preview_frame_rate", 10).toUInt());
	UpdateHotkeyFields();
}

void PageRecord::SaveSettings(QSettings *settings) {
	settings->setValue("record/hotkey_enable", IsHotkeyEnabled());
	settings->setValue("record/hotkey_ctrl", IsHotkeyCtrlEnabled());
	settings->setValue("record/hotkey_shift", IsHotkeyShiftEnabled());
	settings->setValue("record/hotkey_alt", IsHotkeyAltEnabled());
	settings->setValue("record/hotkey_super", IsHotkeySuperEnabled());
	settings->setValue("record/hotkey_key", GetHotkeyKey());
	settings->setValue("record/preview_frame_rate", GetPreviewFrameRate());
}

void PageRecord::PageStart() {

	if(m_page_started)
		return;

	Q_ASSERT(!m_capturing);
	Q_ASSERT(!m_recording);

	// save the settings in case libav/ffmpeg decides to kill the process
	m_main_window->SaveSettings();

	// clear the log
	m_textedit_log->clear();

	// clear the preview
	m_video_previewer->Reset();
	m_audio_previewer->Reset();

	Logger::LogInfo("[PageRecord::PageStart] Starting page ...");

	PageInput *page_input = m_main_window->GetPageInput();
	PageOutput *page_output = m_main_window->GetPageOutput();

	// get the video input settings
	m_video_area = page_input->GetVideoArea();
	m_video_x = page_input->GetVideoX();
	m_video_y = page_input->GetVideoY();
	if(m_video_area == PageInput::VIDEO_AREA_GLINJECT) {
		m_video_in_width = 0;
		m_video_in_height = 0;
	} else {
		m_video_in_width = page_input->GetVideoW();
		m_video_in_height = page_input->GetVideoH();
	}
	m_video_frame_rate = page_input->GetVideoFrameRate();
	m_video_scaling = page_input->GetVideoScalingEnabled();
	m_video_scaled_width = page_input->GetVideoScaledW();
	m_video_scaled_height = page_input->GetVideoScaledH();
	m_video_record_cursor = page_input->GetVideoRecordCursor();

	// get the audio input settings
	m_audio_enabled = page_input->GetAudioEnabled();
	m_audio_sample_rate = 44100;
	m_alsa_device = page_input->GetALSADevice();

	// get the glinject settings
	QString glinject_command = page_input->GetGLInjectCommand();
	bool glinject_run_command = page_input->GetGLInjectRunCommand();
	bool glinject_relax_permissions = page_input->GetGLInjectRelaxPermissions();
	unsigned int glinject_megapixels = page_input->GetGLInjectMaxMegaPixels();
	bool glinject_capture_front = page_input->GetGLInjectCaptureFront();
	bool glinject_limit_fps = page_input->GetGLInjectLimitFPS();

	// get file settings
	m_file_base = page_output->GetFile();
	m_file_protocol = page_output->GetFileProtocol();
	m_separate_files = page_output->GetSeparateFiles();
	m_file_segment_counter = 0;

	// get the output settings
	if(m_separate_files)
		m_output_settings.file = GetNewSegmentFile(m_file_base, &m_file_segment_counter, m_file_protocol.isNull());
	else
		m_output_settings.file = m_file_base;
	m_output_settings.container_avname = page_output->GetContainerAVName();

	m_output_settings.video_codec_avname = page_output->GetVideoCodecAVName();
	m_output_settings.video_kbit_rate = page_output->GetVideoKBitRate();
	m_output_settings.video_options.clear();
	m_output_settings.video_width = 0;
	m_output_settings.video_height = 0;
	m_output_settings.video_frame_rate = m_video_frame_rate;
	m_output_settings.video_allow_frame_skipping = page_output->GetVideoAllowFrameSkipping();

	m_output_settings.audio_codec_avname = (m_audio_enabled)? page_output->GetAudioCodecAVName() : QString();
	m_output_settings.audio_kbit_rate = page_output->GetAudioKBitRate();
	m_output_settings.audio_options.clear();
	m_output_settings.audio_sample_rate = m_audio_sample_rate;

	// some codec-specific things
	// you can get more information about all these options by running 'ffmpeg -h' or 'avconv -h' from a terminal
	switch(page_output->GetVideoCodec()) {
		case PageOutput::VIDEO_CODEC_H264: {
			// x264 has a 'constant quality' mode, where the bit rate is simply set to whatever is needed to keep a certain quality. The quality is set
			// with the 'crf' option. 'preset' changes the encoding speed (and hence the efficiency of the compression) but doesn't really influence the quality,
			// which is great because it means you don't have to experiment with different bit rates and different speeds to get good results.
			m_output_settings.video_options.push_back(std::make_pair(QString("crf"), QString::number(page_output->GetH264CRF())));
			m_output_settings.video_options.push_back(std::make_pair(QString("preset"), page_output->GetH264PresetName()));
			break;
		}
		case PageOutput::VIDEO_CODEC_VP8: {
			// The names of there parameters are very unintuitive. The two options we care about (because they change the speed) are 'deadline' and 'cpu-used'.
			// 'deadline'='best' is unusably slow. 'deadline'='good' is the normal setting, it tells the encoder to use the speed set with 'cpu-used'. Higher
			// numbers will use *less* CPU, confusingly, so a higher number is faster. I haven't done much testing with 'realtime' so I'm not sure if it's a good idea here.
			// It sounds useful, but I think it will use so much CPU that it will slow down the program that is being recorded.
			m_output_settings.video_options.push_back(std::make_pair(QString("deadline"), QString("good")));
			m_output_settings.video_options.push_back(std::make_pair(QString("cpu-used"), QString::number(page_output->GetVP8CPUUsed())));
			break;
		}
		case PageOutput::VIDEO_CODEC_OTHER: {
			m_output_settings.video_options = GetOptionsFromString(page_output->GetVideoOptions());
			break;
		}
		default: break; // to keep GCC happy
	}
	switch(page_output->GetAudioCodec()) {
		case PageOutput::AUDIO_CODEC_OTHER: {
			m_output_settings.audio_options = GetOptionsFromString(page_output->GetAudioOptions());
			break;
		}
		default: break; // to keep GCC happy
	}

	// hide the audio previewer if there is no audio
	m_label_mic_icon->setVisible(m_audio_enabled);
	m_audio_previewer->setVisible(m_audio_enabled);

	// for OpenGL recording, allocate shared memory and start the program now
	if(m_video_area == PageInput::VIDEO_AREA_GLINJECT) {
		try {
			m_gl_inject_launcher.reset(new GLInjectLauncher(glinject_command, glinject_run_command, glinject_relax_permissions, glinject_megapixels * 4 * 1024 * 1024,
															m_video_frame_rate, m_video_record_cursor, glinject_capture_front, glinject_limit_fps));
		} catch(...) {
			Logger::LogError("[PageRecord::PageStart] Error: Something went wrong during GLInject initialization.");
			m_gl_inject_launcher.reset();
			return;
		}
	}

	Logger::LogInfo("[PageRecord::PageStart] Started page.");

	m_page_started = true;
	m_recorded_something = false;
	UpdateHotkey();
	UpdateCapture();

	m_info_last_timestamp = hrt_time_micro();
	m_info_last_frame_counter = 0;
	m_info_input_frame_rate = 0.0;
	UpdateInformation();
	m_info_timer->start(1000);

	if(m_video_area == PageInput::VIDEO_AREA_GLINJECT)
		m_glinject_event_timer->start(100);

}

void PageRecord::PageStop(bool save) {

	if(!m_page_started)
		return;

	RecordStop(true);
	CaptureStop();

	Logger::LogInfo("[PageRecord::PageStop] Stopping page ...");

	if(m_output_manager != NULL) {

		// stop the output
		if(save)
			m_output_manager->Finish();
		m_output_manager.reset();

		// delete the file if it isn't needed
		if(!save && m_file_protocol.isNull()) {
			if(QFileInfo(m_output_settings.file).exists())
				QFile(m_output_settings.file).remove();
		}

	}
	// free the shared memory for OpenGL recording
	// This doesn't stop the program, and the memory is only actually freed when the recorded program stops too.
	m_gl_inject_launcher.reset();

	Logger::LogInfo("[PageRecord::PageStop] Stopped page.");

	m_page_started = false;
	UpdateHotkey();

	m_info_timer->stop();
	UpdateInformation();

	m_glinject_event_timer->stop();

}

void PageRecord::RecordStart() {
	Q_ASSERT(m_page_started);

	if(m_recording)
		return;

	Logger::LogInfo("[PageRecord::RecordStart] Starting recording ...");

	try {

		if(m_output_manager == NULL) {

			// for OpenGL recording, detect the application size
			if(m_video_area == PageInput::VIDEO_AREA_GLINJECT && !m_video_scaling) {
				m_gl_inject_launcher->GetCurrentSize(&m_video_in_width, &m_video_in_height);
				if(m_video_in_width == 0 && m_video_in_height == 0) {
					Logger::LogError("[PageRecord::RecordStart] Error: Could not get the size of the OpenGL application. Either the "
									  "application wasn't started correctly, or the application hasn't created an OpenGL window yet. If "
									  "you want to start recording before starting the application, you have to enable scaling and enter "
									  "the video size manually.");
					throw GLInjectException();
				}
			}

			// calculate the output width and height
			if(m_video_scaling) {
				// Only even width and height is allowed because the final images are encoded as YUV.
				m_output_settings.video_width = m_video_scaled_width / 2 * 2;
				m_output_settings.video_height = m_video_scaled_height / 2 * 2;
			} else if(m_video_area == PageInput::VIDEO_AREA_GLINJECT) {
				// The input size is the size of the OpenGL application and can't be changed. The output size is set to the current size of the application.
				m_output_settings.video_width = m_video_in_width / 2 * 2;
				m_output_settings.video_height = m_video_in_height / 2 * 2;
			} else {
				// If the user did not explicitly select scaling, then don't force scaling just because the recording area is one pixel too large.
				// One missing row/column of pixels is probably better than a blurry video (and scaling is SLOW).
				m_video_in_width = m_video_in_width / 2 * 2;
				m_video_in_height = m_video_in_height / 2 * 2;
				m_output_settings.video_width = m_video_in_width;
				m_output_settings.video_height = m_video_in_height;
			}

			// start the output
			m_output_manager.reset(new OutputManager(m_output_settings));

		} else {

			// start a new segment
			m_output_manager->GetSynchronizer()->NewSegment();

		}

		Logger::LogInfo("[PageRecord::RecordStart] Started recording.");

		m_recording = true;
		m_recorded_something = true;
		UpdateRecordPauseButton();
		UpdateCapture();

	} catch(...) {
		Logger::LogError("[PageRecord::RecordStart] Error: Something went wrong during initialization.");
	}

}

void PageRecord::RecordStop(bool final) {
	Q_ASSERT(m_page_started);

	if(!m_recording)
		return;

	Logger::LogInfo("[PageRecord::RecordStop] Stopping recording ...");

	// if final, then PageStop will stop the output (and delete the file if needed)
	if(m_separate_files && !final) {

		// stop the output
		m_output_manager->Finish();
		m_output_manager.reset();

		// change the file name
		m_output_settings.file = GetNewSegmentFile(m_file_base, &m_file_segment_counter, m_file_protocol.isNull());

		// reset the output video size
		m_output_settings.video_width = 0;
		m_output_settings.video_height = 0;

	}

	Logger::LogInfo("[PageRecord::RecordStart] Stopped recording.");

	m_recording = false;
	UpdateRecordPauseButton();
	UpdateCapture();

}

void PageRecord::CaptureStart() {

	if(m_capturing || !m_page_started)
		return;

	Logger::LogInfo("[PageRecord::CaptureStart] Starting capturing ...");

	Q_ASSERT(m_x11_input == NULL);
	Q_ASSERT(m_gl_inject_input == NULL);
	Q_ASSERT(m_alsa_input == NULL);

	try {

		// start the video input
		if(m_video_area == PageInput::VIDEO_AREA_GLINJECT) {
			m_gl_inject_input.reset(new GLInjectInput(m_gl_inject_launcher.get()));
		} else {
			m_x11_input.reset(new X11Input(m_video_x, m_video_y, m_video_in_width, m_video_in_height, m_video_record_cursor, m_video_area == PageInput::VIDEO_AREA_CURSOR));
		}

		// start the audio input
		if(m_audio_enabled) {
			m_alsa_input.reset(new ALSAInput(m_alsa_device, m_audio_sample_rate));
		}

		Logger::LogInfo("[PageRecord::CaptureStart] Started capturing.");

		m_capturing = true;

	} catch(...) {
		Logger::LogError("[PageRecord::CaptureStart] Error: Something went wrong during initialization.");
		m_x11_input.reset();
		m_gl_inject_input.reset();
		m_alsa_input.reset();
		return;
	}

}

void PageRecord::CaptureStop() {

	if(!m_capturing || !m_page_started)
		return;

	Logger::LogInfo("[PageRecord::CaptureStop] Stopping capturing ...");

	if(m_video_area != PageInput::VIDEO_AREA_GLINJECT) {
		m_info_last_frame_counter -= m_x11_input->GetFrameCounter();
	}

	m_x11_input.reset();
	m_gl_inject_input.reset();
	m_alsa_input.reset();

	Logger::LogInfo("[PageRecord::CaptureStop] Stopped capturing.");

	m_capturing = false;

}

void PageRecord::UpdateCapture() {

	if(m_recording || m_previewing) {
		CaptureStart();
	} else {
		CaptureStop();
	}

	// get sources
	VideoSource *video_source = NULL;
	AudioSource *audio_source = NULL;
	if(m_video_area == PageInput::VIDEO_AREA_GLINJECT) {
		video_source = m_gl_inject_input.get();
	} else {
		video_source = m_x11_input.get();
	}
	if(m_audio_enabled) {
		audio_source = m_alsa_input.get();
	}

	// connect sinks
	if(m_output_manager != NULL) {
		if(m_recording) {
			m_output_manager->GetSynchronizer()->ConnectVideoSource(video_source, PRIORITY_RECORD);
			m_output_manager->GetSynchronizer()->ConnectAudioSource(audio_source, PRIORITY_RECORD);
		} else {
			m_output_manager->GetSynchronizer()->ConnectVideoSource(NULL);
			m_output_manager->GetSynchronizer()->ConnectAudioSource(NULL);
		}
	}
	if(m_previewing) {
		m_video_previewer->ConnectVideoSource(video_source, PRIORITY_PREVIEW);
		m_audio_previewer->ConnectAudioSource(audio_source, PRIORITY_PREVIEW);
	} else {
		m_video_previewer->ConnectVideoSource(NULL);
		m_audio_previewer->ConnectAudioSource(NULL);
	}

}

void PageRecord::UpdateRecordPauseButton() {
	if(m_recording) {
		m_pushbutton_start_pause->setText("Pause recording");
		m_pushbutton_start_pause->setIcon(QIcon::fromTheme("media-playback-pause"));
	} else {
		m_pushbutton_start_pause->setText("Start recording");
		m_pushbutton_start_pause->setIcon(QIcon::fromTheme("media-record"));
	}
}

void PageRecord::UpdatePreview() {
	m_video_previewer->SetFrameRate(GetPreviewFrameRate());
	if(m_previewing) {
		m_stacked_layout_preview->setCurrentWidget(m_preview_page2);
		m_pushbutton_preview_start_stop->setText("Stop preview");
	} else {
		m_stacked_layout_preview->setCurrentWidget(m_preview_page1);
		m_pushbutton_preview_start_stop->setText("Start preview");
	}
}

void PageRecord::UpdateHotkeyFields() {

	bool enabled = IsHotkeyEnabled();
	m_checkbox_hotkey_ctrl->setEnabled(enabled);
	m_checkbox_hotkey_shift->setEnabled(enabled);
	m_checkbox_hotkey_alt->setEnabled(enabled);
	m_checkbox_hotkey_super->setEnabled(enabled);
	m_combobox_hotkey_key->setEnabled(enabled);

	UpdateHotkey();

}

void PageRecord::UpdateHotkey() {

	if(m_page_started && IsHotkeyEnabled()) {

		unsigned int modifiers = 0;
		if(IsHotkeyCtrlEnabled()) modifiers |= ControlMask;
		if(IsHotkeyShiftEnabled()) modifiers |= ShiftMask;
		if(IsHotkeyAltEnabled()) modifiers |= Mod1Mask;
		if(IsHotkeySuperEnabled()) modifiers |= Mod4Mask;
		g_hotkey_listener.EnableHotkey(XK_A + GetHotkeyKey(), modifiers);

		if(m_video_area == PageInput::VIDEO_AREA_GLINJECT)
			m_gl_inject_launcher->UpdateHotkey(IsHotkeyEnabled(), XK_A + GetHotkeyKey(), modifiers);

	} else {

		g_hotkey_listener.DisableHotkey();

	}

}

void PageRecord::RecordStartPause() {
	if(m_recording) {
		RecordStop(false);
	} else {
		RecordStart();
	}
}

void PageRecord::PreviewStartStop() {
	m_video_previewer->Reset();
	m_audio_previewer->Reset();
	m_previewing = !m_previewing;
	UpdatePreview();
	UpdateCapture();
}

void PageRecord::Cancel() {
	if(m_output_manager != NULL) {
		if(QMessageBox::warning(this, MainWindow::WINDOW_CAPTION, "Are you sure you want to cancel this recording?",
								QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
			return;
		}
	}
	PageStop(false);
	m_main_window->GoPageOutput();
}

void PageRecord::Save() {
	if(!m_recorded_something) {
		QMessageBox::information(this, MainWindow::WINDOW_CAPTION, "You haven't recorded anything, there is nothing to save.\n\nThe start button is at the top ;).",
								 QMessageBox::Ok);
		return;
	}
	PageStop(true);
	m_main_window->GoPageDone();
}

void PageRecord::UpdateInformation() {

	if(m_page_started) {

		int64_t timestamp = hrt_time_micro();
		if(timestamp - m_info_last_timestamp > 10000) {
			uint32_t frame_counter;
			if(m_video_area == PageInput::VIDEO_AREA_GLINJECT) {
				frame_counter = m_gl_inject_launcher->GetFrameCounter();
			} else if(m_capturing) {
				frame_counter = m_x11_input->GetFrameCounter();
			} else {
				frame_counter = 0;
			}
			m_info_input_frame_rate = (double) (frame_counter - m_info_last_frame_counter) / ((double) (timestamp - m_info_last_timestamp) * 1.0e-6);
			m_info_last_timestamp = timestamp;
			m_info_last_frame_counter = frame_counter;
		}

		int64_t total_time = 0;
		double frame_rate = 0.0, bit_rate = 0.0;
		uint64_t total_bytes = 0;

		if(m_output_manager != NULL) {
			total_time = m_output_manager->GetSynchronizer()->GetTotalTime();
			frame_rate = m_output_manager->GetVideoEncoder()->GetActualFrameRate();
			bit_rate = m_output_manager->GetMuxer()->GetActualBitRate();
			total_bytes = m_output_manager->GetMuxer()->GetTotalBytes();
		}

		// for OpenGL recording, update the application size
		if(m_video_area == PageInput::VIDEO_AREA_GLINJECT) {
			m_gl_inject_launcher->GetCurrentSize(&m_video_in_width, &m_video_in_height);
		}

		m_label_info_total_time->setText(ReadableTime(total_time));
		m_label_info_frame_rate_in->setText(QString::number(m_info_input_frame_rate, 'f', 2));
		m_label_info_frame_rate_out->setText(QString::number(frame_rate, 'f', 2));
		m_label_info_size_in->setText(ReadableWidthHeight(m_video_in_width, m_video_in_height));
		m_label_info_size_out->setText(ReadableWidthHeight(m_output_settings.video_width, m_output_settings.video_height));
		m_label_info_file_name->setText((m_file_protocol.isNull())? QFileInfo(m_output_settings.file).fileName() : "(" + m_file_protocol + ")");
		m_label_info_file_size->setText(ReadableSize(total_bytes, "B"));
		m_label_info_bit_rate->setText(ReadableSize((uint64_t) (bit_rate + 0.5), "bps"));

	} else {

		m_label_info_total_time->clear();
		m_label_info_frame_rate_in->clear();
		m_label_info_frame_rate_out->clear();
		m_label_info_size_in->clear();
		m_label_info_size_out->clear();
		m_label_info_file_name->clear();
		m_label_info_file_size->clear();
		m_label_info_bit_rate->clear();

	}

}

void PageRecord::UpdateLog(Logger::enum_type type, QString str) {
	QTextCursor cursor = m_textedit_log->textCursor();
	QTextCharFormat format;
	bool should_scroll = (m_textedit_log->verticalScrollBar()->value() >= m_textedit_log->verticalScrollBar()->maximum());
	switch(type) {
		case Logger::TYPE_INFO:     format.setForeground(Qt::black);       break;
		case Logger::TYPE_WARNING:  format.setForeground(Qt::darkYellow);  break;
		case Logger::TYPE_ERROR:    format.setForeground(Qt::red);         break;
	}
	cursor.movePosition(QTextCursor::End);
	if(cursor.position() != 0)
		cursor.insertBlock();
	cursor.insertText(str, format);
	if(should_scroll)
		m_textedit_log->verticalScrollBar()->setValue(m_textedit_log->verticalScrollBar()->maximum());
}

void PageRecord::CheckGLInjectEvents() {
	Q_ASSERT(m_video_area == PageInput::VIDEO_AREA_GLINJECT);
	if(m_gl_inject_launcher->GetHotkeyPressed()) {
		RecordStartPause();
	}
}
