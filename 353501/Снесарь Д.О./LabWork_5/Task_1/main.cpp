#include "mainwindow.h"

#include <QApplication>
#include "globaleventfilter.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*GlobalEventFilter *globalEventFilter = new GlobalEventFilter(&a);
    a.installEventFilter(globalEventFilter);*/
    MainWindow w;
    w.show();
    return a.exec();
}
