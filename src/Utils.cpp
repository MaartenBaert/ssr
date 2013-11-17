#include "Global.h"
#include <QByteArray>

void getDisplaySize(const QString& display_name, int *w, int *h) {
    Display* pdsp = NULL;
    Window wid = 0;
    XWindowAttributes xwAttr;
    *h = -1;
    *w = -1;

    if(display_name=="this") {
        pdsp = XOpenDisplay(NULL);
    } else {
        QByteArray ba = display_name.toAscii();
        pdsp = XOpenDisplay(ba.data());
    }
    if ( !pdsp ) {
        return;
    }

    wid = DefaultRootWindow(pdsp);
    if (wid < 0) {
        XCloseDisplay(pdsp);
        return;
    }

    Status status = XGetWindowAttributes(pdsp, wid, &xwAttr);
    *w = xwAttr.width;
    *h = xwAttr.height;

    XCloseDisplay( pdsp );
    return;
}
