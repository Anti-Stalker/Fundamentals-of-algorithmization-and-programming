#ifndef MOVEWHEEL_H
#define MOVEWHEEL_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>


class MoveWheel {
private:
    int X, Y, R;
    QGraphicsEllipseItem *wheel;
    QGraphicsLineItem *needle;
    float angle = 0;

public:
    MoveWheel(int x, int y, int r, QGraphicsScene* scene) {
        X=x-r;
        Y=y-r;
        R=r;
        wheel = new QGraphicsEllipseItem(x-r, y-r, 2*r, 2*r);
        needle = new QGraphicsLineItem(x, y, x, y-r);
        wheel->setBrush(QBrush(Qt::gray));
        scene->addItem(wheel);
        scene->addItem(needle);
    }
    void shift_x(int a);

    void reset_position(int x_pos);
};
#endif // MOVEWHEEL_H
