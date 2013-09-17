#include "Version.h"
#include "config.h"

// The point of this file is to avoid including config.h everywhere.
// When config.h changes, only this file will be recompiled.
const char SSR_VERSION[] = PACKAGE_VERSION;
