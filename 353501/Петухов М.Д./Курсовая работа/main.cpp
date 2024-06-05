#include "mainwindow.h"
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QPixmap backgroundImage("../resources/menuWidgetBackground.png");  
    QPalette palette;
    QSize newSize(1600, 1058); 
    backgroundImage = backgroundImage.scaled(newSize, Qt::KeepAspectRatio);
    palette.setBrush(QPalette::Window, backgroundImage);
    w.setPalette(palette);
    w.resize(1600, 1058);
    w.show();
    return a.exec();
}