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

#include "StdAfx.h"
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

class QTextEditSmall : public QTextEdit {

public:
	QTextEditSmall(QWidget *parent) : QTextEdit(parent) {}
	QTextEditSmall(const QString& text, QWidget *parent) : QTextEdit(text, parent) {}
	virtual QSize sizeHint() const { return QSize(-1, 100); }

};

PageRecord::PageRecord(MainWindow* main_window)
	: QWidget(main_window->centralWidget()) {

	m_main_window = main_window;

	m_page_started = false;
	m_encoders_started = false;
	m_capturing = false;
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
		connect(&g_hotkey_listener, SIGNAL(Triggered()), this, SLOT(RecordStartPause()));
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
	QGroupBox *group_information = new QGroupBox("Information", this);
	{
		QLabel *label_total_time = new QLabel("Total time:", group_information);
		m_label_total_time = new QLabel(group_information);
		QLabel *label_video_frame_rate = new QLabel("Video frame rate:", group_information);
		m_label_video_frame_rate = new QLabel(group_information);
		QLabel *label_video_in_size = new QLabel("Video in size:", group_information);
		m_label_video_in_size = new QLabel(group_information);
		QLabel *label_video_out_size = new QLabel("Video out size:", group_information);
		m_label_video_out_size = new QLabel(group_information);
		QLabel *label_file_name = new QLabel("File name:", group_information);
		m_label_file_name = new QLabel(group_information);
		QLabel *label_file_size = new QLabel("File size:", group_information);
		m_label_file_size = new QLabel(group_information);
		QLabel *label_file_bit_rate = new QLabel("File bit rate:", group_information);
		m_label_file_bit_rate = new QLabel(group_information);

		QGridLayout *layout = new QGridLayout(group_information);
		layout->addWidget(label_total_time, 0, 0);
		layout->addWidget(m_label_total_time, 0, 1);
		layout->addWidget(label_video_frame_rate, 1, 0);
		layout->addWidget(m_label_video_frame_rate, 1, 1);
		layout->addWidget(label_video_in_size, 2, 0);
		layout->addWidget(m_label_video_in_size, 2, 1);
		layout->addWidget(label_video_out_size, 3, 0);
		layout->addWidget(m_label_video_out_size, 3, 1);
		layout->addWidget(label_file_name, 4, 0);
		layout->addWidget(m_label_file_name, 4, 1);
		layout->addWidget(label_file_size, 5, 0);
		layout->addWidget(m_label_file_size, 5, 1);
		layout->addWidget(label_file_bit_rate, 6, 0);
		layout->addWidget(m_label_file_bit_rate, 6, 1);
		layout->setRowStretch(7, 1);
	}
	QGroupBox *group_preview = new QGroupBox("Preview", this);
	{
		m_preview_page1 = new QWidget(group_preview);
		{
			QLabel *label_preview_frame_rate = new QLabel("Preview frame rate:", m_preview_page1);
			m_lineedit_preview_frame_rate = new QLineEdit(m_preview_page1);
			QLabel *label_preview_note = new QLabel("Note: Previewing requires extra CPU time (especially at high frame rates).", m_preview_page1);
			label_preview_note->setWordWrap(true);

			QGridLayout *layout = new QGridLayout(m_preview_page1);
			layout->setMargin(0);
			layout->addWidget(label_preview_frame_rate, 0, 0);
			layout->addWidget(m_lineedit_preview_frame_rate, 0, 1);
			layout->addWidget(label_preview_note, 1, 0, 1, 2);
			layout->setRowStretch(2, 1);
		}
		m_preview_page2 = new QWidget(group_preview);
		{
			m_video_previewer = new VideoPreviewer(m_preview_page2);
			QLabel *label_mic_icon = new QLabel(m_preview_page2);
			label_mic_icon->setPixmap(QIcon::fromTheme("audio-input-microphone").pixmap(24, 24));
			m_audio_previewer = new AudioPreviewer(m_preview_page2);

			QVBoxLayout *layout = new QVBoxLayout(m_preview_page2);
			layout->setMargin(0);
			layout->addWidget(m_video_previewer);
			{
				QHBoxLayout *layout2 = new QHBoxLayout();
				layout->addLayout(layout2);
				layout2->addStretch();
				layout2->addWidget(label_mic_icon);
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
	QGroupBox *group_log = new QGroupBox("Log", this);
	{
		m_textedit_log = new QTextEditSmall(group_log);
		m_textedit_log->setReadOnly(true);

		QVBoxLayout *layout = new QVBoxLayout(group_log);
		layout->addWidget(m_textedit_log);
	}
	QPushButton *button_cancel = new QPushButton(QIcon::fromTheme("process-stop"), "Cancel recording", this);
	QPushButton *button_save = new QPushButton(QIcon::fromTheme("document-save"), "Save recording", this);

	connect(button_cancel, SIGNAL(clicked()), this, SLOT(Cancel()));
	connect(button_save, SIGNAL(clicked()), this, SLOT(Save()));

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(group_recording);
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2, 2);
		layout2->addWidget(group_information);
		layout2->addWidget(group_preview);
	}
	layout->addWidget(group_log, 1);
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addWidget(button_cancel);
		layout2->addWidget(button_save);
	}

	UpdateRecordPauseButton();
	UpdatePreview();

	m_info_timer = new QTimer(this);
	connect(m_info_timer, SIGNAL(timeout()), this, SLOT(UpdateInformation()));

	m_log_timer = new QTimer(this);
	connect(m_log_timer, SIGNAL(timeout()), this, SLOT(UpdateLog()));
	m_log_timer->start(10);

}

PageRecord::~PageRecord() {

	PageStop(false);

}

bool PageRecord::ShouldBlockClose() {

	if(m_encoders_started) {
		if(QMessageBox::warning(this, MainWindow::WINDOW_CAPTION,
								"You have not saved the current recording yet, if you quit now it will be lost.\n"
								"Are you sure you want to quit?", QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
			return true;
		}
	}

	return false;

}

void PageRecord::LoadSettings(QSettings *settings) {
	SetHotkeyEnabled(settings->value("input/hotkey/enable", true).toBool());
	SetHotkeyCtrlEnabled(settings->value("input/hotkey/ctrl", true).toBool());
	SetHotkeyShiftEnabled(settings->value("input/hotkey/shift", false).toBool());
	SetHotkeyAltEnabled(settings->value("input/hotkey/alt", false).toBool());
	SetHotkeySuperEnabled(settings->value("input/hotkey/super", false).toBool());
	SetHotkeyKey(settings->value("input/hotkey/key", 'r' - 'a').toUInt());
	SetPreviewFrameRate(settings->value("input/preview/frame_rate", 10).toUInt());
	UpdateHotkeyFields();
}

void PageRecord::SaveSettings(QSettings *settings) {
	settings->setValue("input/hotkey/enable", IsHotkeyEnabled());
	settings->setValue("input/hotkey/ctrl", IsHotkeyCtrlEnabled());
	settings->setValue("input/hotkey/shift", IsHotkeyShiftEnabled());
	settings->setValue("input/hotkey/alt", IsHotkeyAltEnabled());
	settings->setValue("input/hotkey/super", IsHotkeySuperEnabled());
	settings->setValue("input/hotkey/key", GetHotkeyKey());
	settings->setValue("input/preview/frame_rate", GetPreviewFrameRate());
}

void PageRecord::PageStart() {

	if(m_page_started)
		return;

	// clear the log
	Logger::GetLines();
	m_textedit_log->clear();

	// clear the preview
	m_video_previewer->Reset();
	m_audio_previewer->Reset();

	Logger::LogInfo("[PageRecord::PageStart] Starting page ...");

	PageInput *page_input = m_main_window->GetPageInput();
	PageOutput *page_output = m_main_window->GetPageOutput();

	// get the type of video recording
	m_video_record_cursor = page_input->GetVideoRecordCursor();
	m_video_follow_cursor = (page_input->GetVideoArea() == PageInput::VIDEO_AREA_CURSOR);
	m_video_glinject = (page_input->GetVideoArea() == PageInput::VIDEO_AREA_GLINJECT);

	// get the video recording area
	m_video_x = page_input->GetVideoX();
	m_video_y = page_input->GetVideoY();
	if(m_video_glinject) {
		m_video_in_width = 0;
		m_video_in_height = 0;
	} else {
		m_video_in_width = page_input->GetVideoW();
		m_video_in_height = page_input->GetVideoH();
	}
	m_video_scaling = page_input->GetVideoScalingEnabled();
	m_video_scaled_width = page_input->GetVideoScaledW();
	m_video_scaled_height = page_input->GetVideoScaledH();
	m_video_frame_rate = page_input->GetVideoFrameRate();
	m_audio_sample_rate = 44100;

	// get the audio input settings
	m_audio_enabled = page_input->GetAudioEnabled();
	m_alsa_device = page_input->GetALSADevice();

	// get the glinject settings
	QString glinject_command = page_input->GetGLInjectCommand();
	bool glinject_run_command = page_input->GetGLInjectRunCommand();
	bool glinject_relax_permissions = page_input->GetGLInjectRelaxPermissions();
	unsigned int glinject_megapixels = page_input->GetGLInjectMaxMegaPixels();
	bool glinject_capture_front = page_input->GetGLInjectCaptureFront();
	bool glinject_limit_fps = page_input->GetGLInjectLimitFPS();

	// get the output settings
	m_file = page_output->GetFile();
	m_video_out_width = 0;
	m_video_out_height = 0;
	m_container = page_output->GetContainer();
	m_video_codec = page_output->GetVideoCodec();
	m_audio_codec = page_output->GetAudioCodec();
	m_container_avname = PageOutput::GetContainerAVName(m_container);
	m_video_avname = PageOutput::GetVideoCodecAVName(m_video_codec);
	m_audio_avname = PageOutput::GetAudioCodecAVName(m_audio_codec);
	m_video_kbit_rate = page_output->GetVideoKBitRate();
	m_audio_kbit_rate = page_output->GetAudioKBitRate();
	m_video_options.clear();
	m_audio_options.clear();

	// some codec-specific things
	// you can get more information about all these options by running 'avconv -h' from a terminal
	// I'm not setting any options for the audio encoder yet, but it can be added here if it's ever needed.
	switch(m_video_codec) {
		case PageOutput::VIDEO_CODEC_H264: {
			// x264 has a 'constant quality' mode, where the bit rate is simply set to whatever is needed to keep a certain quality. The quality is set
			// with the 'crf' option. 'preset' changes the encoding speed (and hence the efficiency of the compression) but doesn't really influence the quality,
			// which is great because it means you don't have to experiment with different bit rates and different speeds to get good results.
			m_video_options.push_back(std::make_pair(QString("crf"), QString::number(page_output->GetH264CRF())));
			m_video_options.push_back(std::make_pair(QString("preset"), QString(page_output->GetH264PresetName(page_output->GetH264Preset()))));
			break;
		}
		case PageOutput::VIDEO_CODEC_VP8: {
			// The names of there parameters are very unintuitive. The two options we care about (because they change the speed) are 'deadline' and 'cpu-used'.
			// 'deadline'='best' is unusably slow. 'deadline'='good' is the normal setting, it tells the encoder to use the speed set with 'cpu-used'. Higher
			// numbers will use *less* CPU, confusingly, so a higher number is faster. I haven't done much testing with 'realtime' so I'm not sure if it's a good idea here.
			// It sounds useful, but I think it will use so much CPU that it will slow down the program that is being recorded.
			m_video_options.push_back(std::make_pair(QString("deadline"), QString("good")));
			m_video_options.push_back(std::make_pair(QString("cpu-used"), QString::number(page_output->GetVP8CPUUsed())));
			break;
		}
		default: break; // to keep GCC happy
	}

	// for OpenGL recording, allocate shared memory and start the program now
	if(m_video_glinject) {
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
	m_encoders_started = false;
	m_info_first_time = true;
	m_video_encoder = NULL;
	m_audio_encoder = NULL;

	UpdateHotkey();
	UpdateInformation();
	m_info_timer->start(1000);

}

void PageRecord::PageStop(bool save) {

	if(!m_page_started)
		return;

	CaptureStop();

	Logger::LogInfo("[PageRecord::PageStop] Stopping page ...");

	// stop the synchronizer
	Q_ASSERT(m_x11_input == NULL);
	Q_ASSERT(m_gl_inject_input == NULL);
	Q_ASSERT(m_alsa_input == NULL);
	m_synchronizer.reset();

	// If we want to save the file, we have to wait for the encoders and mixer to finish or else the file will be corrupted.
	// This can take some time depending on how many frames were buffered, so maybe a progress dialog would make sense here.
	if(save && m_muxer != NULL && m_muxer->IsStarted()) {
		m_muxer->Finish();
		while(!m_muxer->IsDone() && !m_muxer->HasErrorOccurred()) {
			usleep(10000);
		}
	}

	// delete the muxer (it will also delete the encoders)
	m_muxer.reset();
	m_video_encoder = NULL;
	m_audio_encoder = NULL;

	// free the shared memory for OpenGL recording
	// This doesn't stop the program, and the memory is only actually freed when the recorded program stops too.
	m_gl_inject_launcher.reset();

	// delete the file if it isn't needed
	// First make sure it's actually *our* file - the user might have pressed Cancel after realising he was about to overwrite an
	// important file, in that case we definitely shouldn't delete the file. If the encoders have already been started, it's too late.
	if(!save && m_encoders_started) {
		if(QFileInfo(m_file).exists())
			QFile(m_file).remove();
	}

	Logger::LogInfo("[PageRecord::PageStop] Stopped page.");

	m_page_started = false;
	m_encoders_started = false;
	UpdateHotkey();
	UpdateInformation();
	m_info_timer->stop();

}

void PageRecord::CaptureStart() {

	if(m_capturing || !m_page_started)
		return;

	Logger::LogInfo("[PageRecord::RecordStart] Starting recording ...");

	// start the encoders if they weren't started already
	if(!m_encoders_started) {

		Q_ASSERT(m_muxer == NULL);
		Q_ASSERT(m_video_encoder == NULL);
		Q_ASSERT(m_audio_encoder == NULL);
		Q_ASSERT(m_synchronizer == NULL);

		try {

			// for OpenGL recording, detect the application size
			if(m_video_glinject && !m_video_scaling) {
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
				m_video_out_width = m_video_scaled_width / 2 * 2;
				m_video_out_height = m_video_scaled_height / 2 * 2;
			} else if(m_video_glinject) {
				// The input size is the size of the OpenGL application and can't be changed. The output size is set to the current size of the application.
				m_video_out_width = m_video_in_width / 2 * 2;
				m_video_out_height = m_video_in_height / 2 * 2;
			} else {
				// If the user did not explicitly select scaling, then don't force scaling just because the recording area is one pixel too large.
				// One missing row/column of pixels is probably better than a blurry video (and scaling is SLOW).
				m_video_in_width = m_video_in_width / 2 * 2;
				m_video_in_height = m_video_in_height / 2 * 2;
				m_video_out_width = m_video_in_width;
				m_video_out_height = m_video_in_height;
			}

			// prepare everything for recording
			m_muxer.reset(new Muxer(m_container_avname, m_file));
			m_video_encoder = new VideoEncoder(m_muxer.get(), m_video_avname, m_video_options, m_video_kbit_rate * 1024, m_video_out_width, m_video_out_height, m_video_frame_rate);
			if(m_audio_enabled)
				m_audio_encoder = new AudioEncoder(m_muxer.get(), m_audio_avname, m_audio_options, m_audio_kbit_rate * 1024, m_audio_sample_rate);
			m_muxer->Start();
			m_synchronizer.reset(new Synchronizer(m_video_encoder, m_audio_encoder));

		} catch(...) {
			Logger::LogError("[PageRecord::RecordStart] Error: Something went wrong during initialization.");
			m_synchronizer.reset();
			m_muxer.reset();
			m_video_encoder = NULL;
			m_audio_encoder = NULL;
			return;
		}

		m_encoders_started = true;

	}

	Q_ASSERT(m_x11_input == NULL);
	Q_ASSERT(m_gl_inject_input == NULL);
	Q_ASSERT(m_alsa_input == NULL);

	try {

		// start a new segment
		m_synchronizer->NewSegment();

		// start the video input
		if(m_video_glinject) {
			m_gl_inject_input.reset(new GLInjectInput(m_synchronizer.get(), m_gl_inject_launcher.get()));
		} else {
			m_x11_input.reset(new X11Input(m_synchronizer.get(), m_video_x, m_video_y, m_video_in_width, m_video_in_height, m_video_record_cursor, m_video_follow_cursor));
		}

		// start the audio input
		if(m_audio_enabled)
			m_alsa_input.reset(new ALSAInput(m_synchronizer.get(), m_alsa_device));

	} catch(...) {
		Logger::LogError("[PageRecord::RecordStart] Error: Something went wrong during initialization.");
		m_x11_input.reset();
		m_gl_inject_input.reset();
		m_alsa_input.reset();
		return;
	}

	Logger::LogInfo("[PageRecord::RecordStart] Started recording.");

	m_capturing = true;

	UpdateRecordPauseButton();
	UpdatePreview(); //TODO// remove after capture/record split

}

void PageRecord::CaptureStop() {

	if(!m_capturing || !m_page_started)
		return;

	Logger::LogInfo("[PageRecord::RecordPause] Pausing recording ...");

	m_x11_input.reset();
	m_gl_inject_input.reset();
	m_alsa_input.reset();

	Logger::LogInfo("[PageRecord::RecordPause] Paused recording.");

	m_capturing = false;

	UpdateRecordPauseButton();

}

void PageRecord::UpdateRecordPauseButton() {
	if(m_capturing) { //TODO// should be 'm_recording' once recording and capturing are split
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
	if(m_gl_inject_input.get() != NULL)
		m_gl_inject_input->ConnectVideoPreviewer((m_previewing)? m_video_previewer : NULL);
	if(m_x11_input.get() != NULL)
		m_x11_input->ConnectVideoPreviewer((m_previewing)? m_video_previewer : NULL);
	if(m_alsa_input.get() != NULL)
		m_alsa_input->ConnectAudioPreviewer((m_previewing)? m_audio_previewer : NULL);
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

	} else {

		g_hotkey_listener.DisableHotkey();

	}

}

void PageRecord::RecordStartPause() {
	if(m_capturing) {
		CaptureStop();
	} else {
		CaptureStart();
	}
}

void PageRecord::PreviewStartStop() {
	m_video_previewer->Reset();
	m_audio_previewer->Reset();
	m_previewing = !m_previewing;
	UpdatePreview();
}

void PageRecord::Cancel() {
	if(m_encoders_started) {
		if(QMessageBox::warning(this, MainWindow::WINDOW_CAPTION, "Are you sure you want to cancel this recording?",
								QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) {
			return;
		}
	}
	PageStop(false);
	m_main_window->GoPageOutput();
}

void PageRecord::Save() {
	if(!m_encoders_started) {
		QMessageBox::information(this, MainWindow::WINDOW_CAPTION, "You haven't recorded anything, there is nothing to save.\n\nThe start button is at the top ;).",
								 QMessageBox::Ok);
		return;
	}
	PageStop(true);
	m_main_window->GoPageDone();
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
	unsigned int time = time_micro / 1000000;
	return QString("%1:%2:%3")
			.arg(time / 3600)
			.arg((time / 60) % 60, 2, 10, QLatin1Char('0'))
			.arg(time % 60, 2, 10, QLatin1Char('0'));
}

void PageRecord::UpdateInformation() {

	if(m_page_started) {

		int64_t total_time = 0;
		double fps = 0.0, bit_rate = 0.0;
		uint64_t current_bytes = 0;

		if(m_encoders_started) {

			total_time = m_synchronizer->GetTotalTime();
			current_bytes = m_muxer->GetTotalBytes();

			// calculate the number of frames recorded per second
			int64_t current_time = hrt_time_micro();
			unsigned int current_frames = m_video_encoder->GetTotalFrames();
			if(!m_info_first_time && current_time - m_info_last_time > 1000) {
				double t = (double) (current_time - m_info_last_time) * 0.000001;
				fps = (double) (current_frames - m_info_last_frames) / t;
				bit_rate =  (double) (current_bytes - m_info_last_bytes) * 8.0 / t;
			}
			m_info_first_time = false;
			m_info_last_time = current_time;
			m_info_last_frames = current_frames;
			m_info_last_bytes = current_bytes;

		}

		// for OpenGL recording, update the application size
		if(m_video_glinject) {
			m_gl_inject_launcher->GetCurrentSize(&m_video_in_width, &m_video_in_height);
		}

		m_label_total_time->setText(ReadableTime(total_time));
		m_label_video_frame_rate->setText(QString::number(fps, 'f', 2));
		if(m_video_in_width == 0 && m_video_in_height == 0)
			m_label_video_in_size->setText("?");
		else
			m_label_video_in_size->setText(QString::number(m_video_in_width) + "x" + QString::number(m_video_in_height));
		if(m_video_out_width == 0 && m_video_out_height == 0)
			m_label_video_out_size->setText("?");
		else
			m_label_video_out_size->setText(QString::number(m_video_out_width) + "x" + QString::number(m_video_out_height));
		m_label_file_name->setText(QFileInfo(m_file).fileName());
		m_label_file_size->setText(ReadableSize(current_bytes, "B"));
		m_label_file_bit_rate->setText(ReadableSize((uint64_t) (bit_rate + 0.5), "bps"));

	} else {

		m_label_total_time->clear();
		m_label_video_frame_rate->clear();
		m_label_video_in_size->clear();
		m_label_video_out_size->clear();
		m_label_file_name->clear();
		m_label_file_size->clear();
		m_label_file_bit_rate->clear();

	}

}

void PageRecord::UpdateLog() {
	auto lines = Logger::GetLines();
	for(auto it = lines.begin(); it != lines.end(); ++it) {
		QTextCursor cursor = m_textedit_log->textCursor();
		QTextCharFormat format;
		bool should_scroll = (m_textedit_log->verticalScrollBar()->value() >= m_textedit_log->verticalScrollBar()->maximum());
		switch(it->first) {
			case Logger::TYPE_INFO:     format.setForeground(Qt::black);       break;
			case Logger::TYPE_WARNING:  format.setForeground(Qt::darkYellow);  break;
			case Logger::TYPE_ERROR:    format.setForeground(Qt::red);         break;
		}
		cursor.movePosition(QTextCursor::End);
		if(cursor.position() != 0)
			cursor.insertBlock();
		cursor.insertText(it->second, format);
		if(should_scroll)
			m_textedit_log->verticalScrollBar()->setValue(m_textedit_log->verticalScrollBar()->maximum());
	}
	m_video_previewer->UpdateIfNeeded();
	m_audio_previewer->UpdateIfNeeded();
}
