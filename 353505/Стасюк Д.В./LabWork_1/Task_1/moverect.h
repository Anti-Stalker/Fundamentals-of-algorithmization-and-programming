#ifndef MOVERECT_H
#define MOVERECT_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>

class MoveRect {
private:
    int X, Y, W, H;
    QGraphicsRectItem *rect;

public:
    MoveRect (int x, int y, int w, int h, QGraphicsScene* scene) {
        X=x;
        Y=y;
        W=w;
        H=h;
        rect = new QGraphicsRectItem(x,y,w,h);
        rect->setBrush(QBrush(Qt::red));
        scene->addItem(rect);
    }
    void shift_x(int a);

    void reset_position_x(int x_pos);

    int get_left_x();
};
#endif // MOVERECT_H
