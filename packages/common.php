<?php

$packages_dir = dirname(__FILE__);
$ssr_dir = "$packages_dir/..";
$build_dir = "$packages_dir/private-build";

$package_arch_dir = "$packages_dir/package-arch";
$package_ubuntu_dir = "$packages_dir/package-ubuntu";

$build_arch_dir = "$packages_dir/private-build-arch";
$build_ubuntu_dir = "$packages_dir/private-build-ubuntu";

$ubuntuversions = array("precise", "quantal", "raring");

error_reporting(E_ALL);
function error_handler($errno, $errstr, $file, $line) {
	if(!(error_reporting() & $errno))
		return;
	die("Error: [" . $errno . "] " . $errstr . "\n"
		. "File: " . $file . "\n"
		. "Line: " . $line . "\n");
}
set_error_handler("error_handler");

function assert_callback($file, $line, $expression) {
	die("Assertion failure: " . (($expression == "")? "(unknown expression)" : $expression) . "\n"
		. "File: " . $file . "\n"
		. "Line: " . $line . "\n");
}
assert_options(ASSERT_WARNING, false);
assert_options(ASSERT_CALLBACK, "assert_callback");

function exec_check($cmd, &$lines) {
	exec($cmd, $lines, $res);
	if($res != 0)
		die("Command '$cmd' failed!\n");
}

// --------------------------------------------------------

$upload = false;

for($i = 1; $i < $_SERVER["argc"]; ++$i) {
	$opt = $_SERVER["argv"][$i];
	switch($opt) {
		case "upload": {
			$upload = true;
			break;
		}
		default: {
			die("Unknown option '$opt'!\n");
		}
	}
}

// --------------------------------------------------------

exec_check("$ssr_dir/configure --version", $lines);
assert(preg_match("/^simplescreenrecorder configure ([0-9\.]+)$/", $lines[0], $match));
$version = $match[1];
$subversion = trim(file_get_contents("$packages_dir/subversion"));

echo "---- SSR version: $version-$subversion\n";

$source_tarball = "$build_dir/simplescreenrecorder-$version.tar.gz";

?>