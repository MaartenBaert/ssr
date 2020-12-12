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

#include "ScreenScaling.h"

#include "Logger.h"

bool g_disable_screen_scaling = false;

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)

static const char legacyDevicePixelEnvVar[] = "QT_DEVICE_PIXEL_RATIO";
static const char scaleFactorEnvVar[] = "QT_SCALE_FACTOR";
static const char screenFactorsEnvVar[] = "QT_SCREEN_SCALE_FACTORS";

static inline double GetGlobalScaleFactor() {
	// This code was mostly copied from QHighDpiScaling.
	if(qEnvironmentVariableIsSet(scaleFactorEnvVar)) {
		bool ok;
		double f = qgetenv(scaleFactorEnvVar).toDouble(&ok);
		if(ok && f > 0) {
			return f;
		}
	} else {
		if(qEnvironmentVariableIsSet(legacyDevicePixelEnvVar)) {
			int dpr = qEnvironmentVariableIntValue(legacyDevicePixelEnvVar);
			if(dpr > 0)
				return (double) dpr;
		}
	}
	return 1.0;
}

std::vector<double> GetScreenScaleFactors() {
	std::vector<double> factors;
	// This code was mostly copied from QHighDpiScaling.
	if(qEnvironmentVariableIsSet(screenFactorsEnvVar)) {
		int i = 0;
		const auto specs = qgetenv(screenFactorsEnvVar).split(';');
		for(const QByteArray &spec : specs) {
			int equalsPos = spec.lastIndexOf('=');
			double factor = 0;
			bool ok;
			if(equalsPos > 0) {
				QByteArray f = spec.mid(equalsPos + 1);
				factor = f.toDouble(&ok);
			} else {
				factor = spec.toDouble(&ok);
			}
			if(ok)
				factors.push_back(factor);
			++i;
		}
	}
	return factors;
}

#endif

void ScreenScalingFix() {

	// Workarounds for broken screen scaling. SSR tries to support screen scaling, but the Qt implementation is
	// somewhat broken, especially for non-integer scale factors. So when we detect that a fractional screen scale
	// factor is being used, we forcibly disable it. The Qt code that determines the scale factors is located in the
	// (undocumented) QHighDpiScaling class, we replicate the same logic here to detect potential problems.

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)

	// Check whether the global scale factor is fractional.
	double global_factor = GetGlobalScaleFactor();
	if(!qFuzzyCompare(global_factor, round(global_factor)))
		g_disable_screen_scaling = true;

	// Check whether any of the screen scale factors are fractional.
	std::vector<double> screen_factors = GetScreenScaleFactors();
	for(double factor : screen_factors) {
		if(!qFuzzyCompare(factor, round(factor)))
			g_disable_screen_scaling = true;
	}

	// Disable screen scaling if any fractional factor was detected.
	if(g_disable_screen_scaling) {
		qunsetenv(legacyDevicePixelEnvVar);
		qunsetenv(scaleFactorEnvVar);
		qunsetenv(screenFactorsEnvVar);
		QCoreApplication::setAttribute(Qt::AA_DisableHighDpiScaling);
	}

	// Qt 5.14 introduces an additional automatic scaling mechanism based on system settings or the DPI of the monitor,
	// but luckily this mechanism has an option to round the detected scale factor to the nearest integer.
#if QT_VERSION >= QT_VERSION_CHECK(5, 14, 0)
	QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::RoundPreferFloor);
#endif

	// We want high-DPI pixmaps in all cases.
	QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

#endif
}

void ScreenScalingMessage() {

	if(g_disable_screen_scaling)
		Logger::LogInfo("[ScreenScaling] " + Logger::tr("Detected fractional screen scale factor, scaling was disabled."));

}
