/*
Copyright (c) 2012-2017 Maarten Baert <maarten-baert@hotmail.com>

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

#include <Terminator.h>

Terminator::Terminator(int _seconds, PageRecord * _page_record) {
  termData = (TermData*)malloc(sizeof(TermData));
  termData->seconds = _seconds;
  termData->page_record = _page_record;
  pthread_t pth;
  pthread_create(&pth, NULL, Terminate, termData);
}

void * Terminator::Terminate(void * _termData) {
    TermData * termData = ((TermData*)_termData);
    Logger::LogInfo(Logger::tr("This program will exit in %1 seconds").arg(termData->seconds));

    sleep(termData->seconds);
    termData->page_record->StopPage(true);
    free(termData);
    QCoreApplication::exit(0);
    return NULL;
}
