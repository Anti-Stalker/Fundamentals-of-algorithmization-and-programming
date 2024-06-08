#ifndef SMOKE_H
#define SMOKE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>


class Smoke {
private:
    int X, Y, W, H;
    QGraphicsEllipseItem *circle1;
    QGraphicsEllipseItem *circle2;
    QGraphicsEllipseItem *circle3;
    QGraphicsEllipseItem *circle4;

    int counter1 = generate_time();
    int counter2 = generate_time();


    void moveToRandPlace (QGraphicsEllipseItem* ellipse);

    void shift_circle_x(QGraphicsEllipseItem* c, int a);

    void reset_circle_x(QGraphicsEllipseItem* c, int x);

    int generate_time();

public:
    Smoke (int x, int y, int w, int h, QGraphicsScene* scene) {
        X = x; Y=y; W=w; H=h;
        circle1 = new QGraphicsEllipseItem();
        circle1->setBrush(QBrush(Qt::gray));
        scene->addItem(circle1);
        moveToRandPlace(circle1);
        circle2 = new QGraphicsEllipseItem();
        circle2->setBrush(QBrush(Qt::gray));
        scene->addItem(circle2);
        moveToRandPlace(circle2);
        circle3 = new QGraphicsEllipseItem();
        circle3->setBrush(QBrush(Qt::gray));
        scene->addItem(circle3);
        moveToRandPlace(circle3);
        circle4 = new QGraphicsEllipseItem();
        circle4->setBrush(QBrush(Qt::gray));
        scene->addItem(circle4);
        moveToRandPlace(circle4);
    }
    void shift_x(int a);

    void reset_position_x(int x);
};
#endif // SMOKE_H
