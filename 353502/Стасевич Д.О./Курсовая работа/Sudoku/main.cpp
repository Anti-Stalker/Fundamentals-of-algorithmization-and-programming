
#include <QApplication>
#include <QPushButton>

#include "mainwindow/mainwindow.h"

#include "SudokuField/SudokuField.h"
#include "SudokuField/PlayersField.h"
#include <iostream>

#include <QDebug>
#include <cmath>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    mainwindow w;
    w.setWindowState(Qt::WindowFullScreen);
    w.show();

    return QApplication::exec();
}
