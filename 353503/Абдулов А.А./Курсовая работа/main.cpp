#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("My Simulator");
    w.setGeometry(0, 0, 1920, 1080);
    w.show();
    return a.exec();
}
