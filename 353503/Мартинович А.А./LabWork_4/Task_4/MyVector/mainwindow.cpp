#include "mainwindow.h"
#include "MyVector.h"
#include "QtDebug"
#include "vector"
#include "MyPair.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Pair< Vector<int>,Vector<Pair<int,double>> > a;

    a.first.assign(10, 10);
    a.second.assign(10, Pair<int, double>(10, 20.5));

    for (auto i: a.first) {
        qDebug() << i;
    }

    for (auto i: a.second) {
        qDebug() << i.first << i.second;
    }
}

MainWindow::~MainWindow()
{
}

