#include "firstwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstWindow w;
    //w.setFixedSize(630,500);
    w.showFullScreen();
    w.show();
    return a.exec();
}
