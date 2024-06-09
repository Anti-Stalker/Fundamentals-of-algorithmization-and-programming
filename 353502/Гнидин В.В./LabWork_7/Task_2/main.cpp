//
// Created by volodya-petarda on 5/30/24.
//

#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwindow w;
    w.show();
    return a.exec();
}
