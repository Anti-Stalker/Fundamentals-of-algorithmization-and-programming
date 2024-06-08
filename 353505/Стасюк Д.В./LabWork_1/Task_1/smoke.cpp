#include "smoke.h"

void Smoke::moveToRandPlace (QGraphicsEllipseItem* ellipse) {
    int x = X + arc4random() % W;
    int y = Y + arc4random() % H;
    int r = 20 + arc4random() % 15;
    ellipse->setRect(x, y, r, r);
}

void Smoke::shift_circle_x(QGraphicsEllipseItem* c, int a){
    QPointF newPos = QPointF(c->pos().x() + a, c->pos().y());
    c->setPos(newPos);
}

void Smoke::reset_circle_x(QGraphicsEllipseItem* c, int x){
    QPointF newPos = QPointF(x, c->pos().y());
    c->setPos(newPos);
}

int Smoke::generate_time() {
    return 10 + arc4random() % 10;
}

void Smoke::shift_x(int a) {
    if (counter1 == 0) {
        moveToRandPlace(circle1);
        moveToRandPlace(circle2);
        counter1 = generate_time();
    } else {
        shift_circle_x(circle1, a);
        shift_circle_x(circle2, a);
    }
    if (counter2 == 0) {
        moveToRandPlace(circle3);
        moveToRandPlace(circle4);
        counter2 = generate_time();
    } else {
        shift_circle_x(circle3, a);
        shift_circle_x(circle4, a);
    }

    counter1 -= 1;
    counter2 -= 1;
}

void Smoke::reset_position_x(int x) {
    reset_circle_x(circle1, x);
    reset_circle_x(circle2, x);
    reset_circle_x(circle3, x);
    reset_circle_x(circle4, x);
}
