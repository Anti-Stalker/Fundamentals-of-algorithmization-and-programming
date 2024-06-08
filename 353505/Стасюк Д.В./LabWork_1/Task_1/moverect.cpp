#include "moverect.h"

void MoveRect::shift_x(int a) {
    int new_x = rect->pos().x() + a;
    QPointF newPos = QPointF(new_x, rect->pos().y());

    rect->setPos(newPos);
}

void MoveRect::reset_position_x(int x_pos) {
    QPointF newPos = QPointF(x_pos, rect->pos().y());

    rect->setPos(newPos);
}

int MoveRect::get_left_x() {
    return rect->pos().x();
}
