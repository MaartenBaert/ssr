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

class AVFrameWrapper : public AVFrame {
public:
	AVFrameWrapper();
	AVFrameWrapper(size_t size);
	AVFrameWrapper(const AVFrameWrapper& other) = delete;
	AVFrameWrapper* operator=(const AVFrameWrapper& other) = delete;
	~AVFrameWrapper();
};

class AVPacketWrapper : public AVPacket {
public:
	AVPacketWrapper();
	AVPacketWrapper(size_t size);
	AVPacketWrapper(const AVPacketWrapper& other) = delete;
	AVPacketWrapper* operator=(const AVPacketWrapper& other) = delete;
	~AVPacketWrapper();
};
