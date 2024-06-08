#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Task 1");
    w.setFixedSize(w.width(),w.height());
    w.show();
    return a.exec();
}
