#include "face.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow window;
    QWidget w;
    face Face;

    Face.setFixedSize(500,500);


    window.setCentralWidget(&w);
    QGridLayout layout(&w);

    QPushButton move_right("Move_eyes_right");
    QPushButton move_left("Move_eyes_left");
    QPushButton open_m("Open mouth");
    QPushButton close_m("Close mouth");
    QObject::connect(&move_right, &QPushButton::clicked, [&]() {
        Face.move_eyes_right();
    });
    QObject::connect(&move_left, &QPushButton::clicked, [&]() {
        Face.move_eyes_left();
    });
    QObject::connect(&close_m, &QPushButton::clicked, [&]() {
        Face.close_mouth();
    });
    QObject::connect(&open_m, &QPushButton::clicked, [&]() {
        Face.open_mouth();
    });

    layout.addWidget(&Face,0,0);
    layout.addWidget(&move_right,1,0);
    layout.addWidget(&move_left,2,0);
    layout.addWidget(&open_m,3,0);
    layout.addWidget(&close_m,4,0);
    window.show();
    return a.exec();
}
