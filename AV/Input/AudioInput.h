/*
Copyright (c) 2012 Maarten Baert <maarten-baert@hotmail.com>

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
#include "StdAfx.h"

#include "BaseInput.h"

class AVFrameWrapper;

class AudioInput : public BaseInput {

private:
	unsigned int m_sample_rate;
	unsigned int m_required_frame_size;

	std::unique_ptr<AVFrameWrapper> m_partial_frame;

public:
	AudioInput(Synchronizer* synchronizer, const QString& alsa_device);
	~AudioInput();

private:
	virtual void ReadFrame(AVFrameWrapper* frame);

};
