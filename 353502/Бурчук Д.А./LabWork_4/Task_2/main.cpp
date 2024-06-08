#include <QApplication>

#include "Headers/Widget.h"



int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Widget widget;
    widget.setFixedSize(1000,720);
    widget.show();
    return QApplication::exec();
}
