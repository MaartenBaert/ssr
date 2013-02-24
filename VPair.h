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

template<typename T>
class VPair {

public:
	class Lock {
	private:
		T *m_data;
		QMutexLocker m_locker;
	public:
		inline Lock(VPair* parent) : m_locker(&parent->m_mutex) {
			m_data = const_cast<T*>(&parent->m_data);
		}
		inline T* operator->() { return m_data; }
		inline T& operator*() { return *m_data; }
		inline T* get() { return m_data; }
	};

private:
	volatile T m_data;
	QMutex m_mutex;

};
