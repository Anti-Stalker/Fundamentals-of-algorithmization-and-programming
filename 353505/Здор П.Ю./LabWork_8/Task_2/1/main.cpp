#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    heap *h=new heap;
    h->create(10);
    h->create(2);
    h->create(40);
    h->create(-2);
    qDebug() << h->fmin();
    return a.exec();
}
