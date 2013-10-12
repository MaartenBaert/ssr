<?php

require_once("common.php");

exec_check("rm -rf \"$package_arch_dir\"", $lines);
@mkdir($package_arch_dir);

arch_create_package($package_arch_dir, false, $version, $subversion);
arch_create_package($package_arch_dir, true, $version, $subversion);

function arch_generate_pkgbuild($lib32, $packagename, $version, $subversion) {
	$out = "";
	$out .= "pkgname=$packagename\n";
	$out .= "pkgver=$version\n";
	$out .= "pkgrel=$subversion\n";
	$out .= ($lib32)? "pkgdesc=\"OpenGL recording of 32-bit applications with SimpleScreenRecorder.\"\n"
					: "pkgdesc=\"A feature-rich screen recorder that supports X11 and OpenGL.\"\n";
	$out .= ($lib32)? "arch=(\"x86_64\")\n"
					: "arch=(\"i686\" \"x86_64\")\n";
	$out .= "url=\"http://www.maartenbaert.be/simplescreenrecorder/\"\n";
	$out .= "license=(\"GPL3\")\n";
	$out .= "source=(\"git+https://github.com/MaartenBaert/ssr.git#tag=$version\")\n";
	$out .= "md5sums=(\"SKIP\")\n";
	$out .= ($lib32)? "depends=(\"lib32-libgl\" \"lib32-glu\" \"lib32-libx11\" \"lib32-libxext\" \"lib32-libxfixes\")\n"
					: "depends=(\"qt4\" \"ffmpeg\" \"alsa-lib\" \"libpulse\" \"libgl\" \"glu\" \"libx11\" \"libxext\" \"libxfixes\")\n";
	if(!$lib32) {
		$out .= "if test \"\$CARCH\" == x86_64; then\n";
		$out .= "	optdepends=(\"lib32-simplescreenrecorder: OpenGL recording of 32-bit applications\")\n";
		$out .= "fi\n";
	}
	$out .= ($lib32)? "makedepends=(\"git\" \"gcc-multilib\")\n"
					: "makedepends=(\"git\")\n";
	$out .= "options=(\"!libtool\")\n";
	$out .= "install=$packagename.install\n";
	$out .= "\n";
	$out .= "build() {\n";
	$out .= "	cd ssr\n";
	$out .= "	export CPPFLAGS=\"\$CPPFLAGS -DNDEBUG -DQT_NO_DEBUG -DSSR_USE_FFMPEG_VERSIONS=1\"\n";
	if($lib32) {
		$out .= "	export CC=\"gcc -m32\"\n";
		$out .= "	export CXX=\"g++ -m32\"\n";
		$out .= "	export PKG_CONFIG_PATH=\"/usr/lib32/pkgconfig\"\n";
		$out .= "	./configure --prefix=/usr --libdir=/usr/lib32 --disable-ssrprogram\n";
	} else {
		$out .= "	./configure --prefix=/usr\n";
	}
	$out .= "	make\n";
	$out .= "}\n";
	$out .= "package() {\n";
	$out .= "	cd ssr\n";
	$out .= "	make DESTDIR=\"\${pkgdir}\" install\n";
	$out .= "}\n";
	return $out;
}

function arch_generate_install($lib32) {
	$out = "";
	$out .= "post_install() {\n";
	if(!$lib32) {
		$out .= "	update-desktop-database -q\n";
		$out .= "	gtk-update-icon-cache -q -f usr/share/icons/hicolor\n";
	}
	$out .= "	ldconfig\n";
	$out .= "}\n";
	$out .= "post_upgrade() {\n";
	$out .= "	post_install\n";
	$out .= "}\n";
	$out .= "post_remove() {\n";
	$out .= "	post_install\n";
	$out .= "}\n";
	return $out;
}

function arch_create_package($dir, $lib32, $version, $subversion) {
	$packagename = ($lib32)? "lib32-simplescreenrecorder" : "simplescreenrecorder";
	@mkdir("$dir/$packagename");
	file_put_contents("$dir/$packagename/PKGBUILD", arch_generate_pkgbuild($lib32, $packagename, $version, $subversion));
	file_put_contents("$dir/$packagename/$packagename.install", arch_generate_install($lib32));
}

?>