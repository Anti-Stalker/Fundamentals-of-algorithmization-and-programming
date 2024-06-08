#include "mainwindow.h"

#include <QApplication>
//GSAID PROBD (Game Scenario Analysis and Probability-Based Decision)
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
