<?php

require_once("common.php");

exec_check("rm -rf \"$package_ubuntu_dir\"", $lines);
@mkdir($package_ubuntu_dir);

foreach($ubuntuversions as $ubuntuversion) {
	@mkdir("$package_ubuntu_dir/$ubuntuversion");
	ubuntu_create_package("$package_ubuntu_dir/$ubuntuversion", false, $version, $subversion, $ubuntuversion);
	ubuntu_create_package("$package_ubuntu_dir/$ubuntuversion", true, $version, $subversion, $ubuntuversion);
}

function ubuntu_generate_changelog($packagename, $packageversion, $ubuntuversion, $packagedate) {
	$out = "";
	$out .= "$packagename ($packageversion) $ubuntuversion; urgency=low\n";
	$out .= "\n";
	$out .= "  * Sorry, no changelogs yet.\n";
	$out .= "\n";
	$out .= " -- Maarten Baert (v2) <maarten-baert@hotmail.com>  $packagedate\n";
	return $out;
}

function ubuntu_generate_control($packagename, $multiarch, $builddepends, $predepends, $depends, $recommends, $extradescription) {
	$out = "";
	$out .= "Source: $packagename\n";
	$out .= "Section: video\n";
	$out .= "Priority: optional\n";
	$out .= "Maintainer: Maarten Baert (v2) <maarten-baert@hotmail.com>\n";
	$out .= "Build-Depends: $builddepends\n";
	$out .= "Standards-Version: 3.9.2\n";
	$out .= "Homepage: http://www.maartenbaert.be/simplescreenrecorder/\n";
	$out .= "Vcs-Git: git://github.com/MaartenBaert/ssr.git\n";
	$out .= "Vcs-Browser: https://github.com/MaartenBaert/ssr\n";
	$out .= "\n";
	$out .= "Package: $packagename\n";
	$out .= "Architecture: i386 amd64\n";
	$out .= "Multi-Arch: $multiarch\n";
	$out .= "Pre-Depends: $predepends\n";
	$out .= "Depends: $depends\n";
	$out .= "Recommends: $recommends\n";
	$out .= "Description: A feature-rich screen recorder that supports X11 and OpenGL.\n";
	$out .= " SimpleScreenRecorder is a feature-rich screen recorder that supports X11 and OpenGL. It has a Qt-based graphical user interface. It can record the entire screen or part of it, or record OpenGL applications directly. The recording can be paused and resumed at any time. Many different file formats and codecs are supported.\n";
	$out .= " .\n";
	$out .= " $extradescription\n";
	return $out;
}

function ubuntu_generate_copyright() {
	$out = "";
	$out .= "Format: http://dep.debian.net/deps/dep5\n";
	$out .= "Upstream-Name: simplescreenrecorder\n";
	$out .= "Source: <http://www.maartenbaert.be/simplescreenrecorder>\n";
	$out .= "\n";
	$out .= "Files: *\n";
	$out .= "Copyright: 2012-2013 Maarten Baert <maarten-baert@hotmail.com>\n";
	$out .= "License: GPL-3.0+\n";
	$out .= "\n";
	$out .= "Files: debian/*\n";
	$out .= "Copyright: 2012-2013 Maarten Baert <maarten-baert@hotmail.com>\n";
	$out .= "License: GPL-3.0+\n";
	$out .= "\n";
	$out .= "License: GPL-3.0+\n";
	$out .= " This program is free software: you can redistribute it and/or modify\n";
	$out .= " it under the terms of the GNU General Public License as published by\n";
	$out .= " the Free Software Foundation, either version 3 of the License, or\n";
	$out .= " (at your option) any later version.\n";
	$out .= " .\n";
	$out .= " This package is distributed in the hope that it will be useful,\n";
	$out .= " but WITHOUT ANY WARRANTY; without even the implied warranty of\n";
	$out .= " MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n";
	$out .= " GNU General Public License for more details.\n";
	$out .= " .\n";
	$out .= " You should have received a copy of the GNU General Public License\n";
	$out .= " along with this program. If not, see <http://www.gnu.org/licenses/>.\n";
	$out .= " .\n";
	$out .= " On Debian systems, the complete text of the GNU General\n";
	$out .= " Public License version 3 can be found in \"/usr/share/common-licenses/GPL-3\".\n";
	return $out;
}

function ubuntu_generate_postinst() {
	$out = "";
	$out .= "#!/bin/sh\n";
	$out .= "\n";
	$out .= "set -e\n";
	$out .= "\n";
	$out .= "#DEBHELPER#\n";
	$out .= "\n";
	$out .= "exit 0\n";
	return $out;
}

function ubuntu_generate_rules($lib) {
	$out = "";
	$out .= "#!/usr/bin/make -f\n";
	$out .= "\n";
	$out .= "# Uncomment this to turn on verbose mode.\n";
	$out .= "#export DH_VERBOSE=1\n";
	$out .= "\n";
	$out .= "CPPFLAGS+=-DNDEBUG -DQT_NO_DEBUG -DSSR_USE_FFMPEG_VERSIONS=0\n";
	$out .= "\n";
	$out .= "%:\n";
	$out .= "	dh $@\n";
	$out .= "\n";
	$out .= "override_dh_auto_configure:\n";
	$out .= ($lib)? "	dh_auto_configure -- --disable-ssrprogram\n"
				  : "	dh_auto_configure -- --disable-glinjectlib\n";
	return $out;
}

function ubuntu_create_debian_dir($dir, $changelog, $control, $copyright, $postinst, $rules) {
	@mkdir($dir);
	@mkdir("$dir/source");
	file_put_contents("$dir/changelog", $changelog);
	file_put_contents("$dir/control", $control);
	file_put_contents("$dir/copyright", $copyright);
	file_put_contents("$dir/postinst", $postinst);
	file_put_contents("$dir/rules", $rules);
	file_put_contents("$dir/compat", "9\n");
	file_put_contents("$dir/source/format", "1.0\n");
	chmod("$dir/rules", 0755);
}

function ubuntu_create_package($dir, $lib, $version, $subversion, $ubuntuversion) {
	$packagename = ($lib)? "simplescreenrecorder-lib" : "simplescreenrecorder";
	$packageversion = "$version-$subversion~ppa1~${ubuntuversion}1";
	$packagedate = date("r");
	$multiarch = ($lib)? "same" : "";
	$builddepends = "debhelper (>= 9), dpkg-dev (>= 1.16.0), build-essential, pkg-config, cmake, libx11-dev, libxext-dev, libxfixes-dev"
			. (($lib)? ", libgl1-mesa-dev, libglu1-mesa-dev"
					 : ", qt4-qmake, libqt4-dev, libavformat-dev, libavcodec-dev, libavutil-dev, libswscale-dev, libasound2-dev, libpulse-dev");
	$predepends = "\${misc:Pre-Depends}";
	$depends = "\${shlibs:Depends}, \${misc:Depends}, libx11-6, libxext6, libxfixes3"
			. (($lib)? ", libgl1-mesa-glx | libgl1, libglu1-mesa | libglu1"
					: ", libqtgui4, libavformat53 | libavformat-extra-53, libavcodec53 | libavcodec-extra-53, libavutil51 | libavutil-extra-51, libswscale2 | libswscale-extra-2, libasound2, libpulse0");
	$recommends = ($lib)? "" : "simplescreenrecorder-lib";
	$extradescription = ($lib)? "This package contains the GLInject library."
							  : "This package contains the main program.";
	@mkdir("$dir/$packagename-$version");
	ubuntu_create_debian_dir("$dir/$packagename-$version/debian",
		ubuntu_generate_changelog($packagename, $packageversion, $ubuntuversion, $packagedate),
		ubuntu_generate_control($packagename, $multiarch, $builddepends, $predepends, $depends, $recommends, $extradescription),
		ubuntu_generate_copyright(),
		ubuntu_generate_postinst(),
		ubuntu_generate_rules($lib));
}

?>