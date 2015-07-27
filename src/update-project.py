#!/usr/bin/python3

import os
import os.path

project = "SimpleScreenRecorder.pro"
marker = "########## Warning: Everything below this line is auto-generated and will be overwritten! ##########"

def recursive_search(directory, prefix, headers, sources, directories):
	entries = os.listdir(directory)
	entries.sort()
	for filename in entries:
		path = directory + "/" + filename
		if os.path.isdir(path):
			directories.append(prefix + filename)
			recursive_search(path, prefix + filename + "/", headers, sources, directories)
	for filename in entries:
		path = directory + "/" + filename
		if os.path.isfile(directory + "/" + filename):
			if filename.endswith(".h") or filename.endswith(".hpp"):
				headers.append(prefix + filename)
			if filename.endswith(".c") or filename.endswith(".cpp"):
				sources.append(prefix + filename)

headers = []
sources = []
directories = []
recursive_search(".", "", headers, sources, directories)

with open(project, "r") as f:
	contents = f.read()
header, _, _ = contents.partition(marker)
with open(project + ".new", "w") as f:
	f.write(header)
	f.write(marker)
	#f.write("\n\n");
	#f.write("INCLUDEPATH += \\\n\t" + " \\\n\t".join(directories))
	#f.write("\n\n");
	#f.write("DEPENDPATH += \\\n\t" + " \\\n\t".join(directories))
	f.write("\n\n");
	f.write("HEADERS += \\\n\t" + " \\\n\t".join(headers))
	f.write("\n\n");
	f.write("SOURCES += \\\n\t" + " \\\n\t".join(sources))
	f.write("\n\n");
os.rename(project + ".new", project)
