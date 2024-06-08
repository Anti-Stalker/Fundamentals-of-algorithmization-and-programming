#include "startwindow.h"
#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "character.h"
#include "levelgenerator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow startWindow;
    MainWindow mainWindow;

    QObject::connect(&startWindow, &StartWindow::startGame, [&]() {
        mainWindow.show();
        startWindow.hide();
    });

    QObject::connect(&startWindow, &StartWindow::closeApplication, [&]() {
        QApplication::quit();
    });

    startWindow.show();


    return a.exec();
}
