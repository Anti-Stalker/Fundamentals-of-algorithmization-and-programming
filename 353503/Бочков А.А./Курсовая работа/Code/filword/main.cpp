
//#include "mainwindow.h"
#include <level.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Level w;
    w.showFullScreen();
    return a.exec();
}
