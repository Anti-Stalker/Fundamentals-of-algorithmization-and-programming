#ifndef LOCOMOTIVE_H
#define LOCOMOTIVE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include "moverect.h"
#include "movewheel.h"
#include "smoke.h"


class Locomotive {
private:
    MoveRect *body;
    MoveRect *pipe;
    MoveRect *cabine;
    MoveWheel *wheel1;
    MoveWheel *wheel2;
    MoveWheel *wheel3;
    Smoke *smoke;

public:
    Locomotive (QGraphicsScene *scene) {
        body = new MoveRect(50, 350, 300, 100, scene);
        pipe = new MoveRect (300,270,50,80, scene);
        cabine = new MoveRect(50,250,100,100,scene);
        wheel1 = new MoveWheel(100,490,40, scene);
        wheel2 = new MoveWheel(180,490,40, scene);
        wheel3 = new MoveWheel(300,490,40, scene);
        smoke = new Smoke(300, 150, 50, 50, scene);
    }
    void shift_x(int a);

    int get_left_x();

    void reset_position_x(int x);
};

#endif // LOCOMOTIVE_H
