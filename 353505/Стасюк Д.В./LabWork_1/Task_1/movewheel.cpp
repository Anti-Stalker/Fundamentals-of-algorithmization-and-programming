#include "movewheel.h"

void MoveWheel::shift_x(int a) {
    int new_x = wheel->pos().x() + a;
    QPointF newPos = QPointF(new_x, wheel->pos().y());
    wheel->setPos(newPos);

    float step = 0.3;
    int new_x_line = X+wheel->pos().x()+R + R*sin(angle+step);
    int new_y_line = Y+wheel->pos().y() + (R - R*cos(angle+step));

    needle->setLine(QLineF(X+wheel->pos().x()+R, Y+wheel->pos().y()+R, new_x_line, new_y_line));

    angle = angle+step;
}

void MoveWheel::reset_position(int x_pos) {
    QPointF newPos = QPointF(x_pos, wheel->pos().y());
    wheel->setPos(newPos);

    needle->setLine(QLineF(X, Y, X, Y-R));
}
