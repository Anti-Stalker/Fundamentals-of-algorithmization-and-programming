#include <QApplication>
#include <QPushButton>

#include "mainwindow/mainwindow.h"

#include "AVLTree/Tree.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    mainwindow w;
    w.show();

    return QApplication::exec();


}
