#include <QObject>
#include <QTimer>
#include <QCoreApplication>
#include <QThread>
#include <pthread.h>
#include <PageRecord.h>

class Terminator : public QObject {

  private:
    struct TermData {
      int seconds;
      int minutes;
      PageRecord * page_record;
    };

    TermData * termData;

    static void * Terminate(void * _termData);

  public:
    Terminator(int _seconds, PageRecord * _page_record);
};
