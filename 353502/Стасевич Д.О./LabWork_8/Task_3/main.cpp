#include <QApplication>
#include <iostream>

#include "RBTree/map.h"
#include "RBTree/unordered_map.h"
#include "RBTree/set.h"
#include "mainwindow/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    mainwindow w;
    w.show();

    return QApplication::exec();

}
