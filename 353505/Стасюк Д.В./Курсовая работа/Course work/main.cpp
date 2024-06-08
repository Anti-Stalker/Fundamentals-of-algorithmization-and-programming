#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtGui>
#include <QtQuick3D/qquick3d.h>
#include <QQuickWindow>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

    w.engine.load(QUrl(QStringLiteral("qrc:/mainQuat.qml")));

    w.show();
    return app.exec();
}
