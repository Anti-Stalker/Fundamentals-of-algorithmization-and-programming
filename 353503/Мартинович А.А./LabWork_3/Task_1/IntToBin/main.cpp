#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    const QApplication a(argc, argv);
    MainWindow w(nullptr);
    w.show();
    return a.exec();
}
