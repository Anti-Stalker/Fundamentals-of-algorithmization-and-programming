#ifndef ROCKET_H
#define ROCKET_H

#include "movingline.h"

class Rocket : public MovingLine
{

public:
    Rocket();
    void moveLineUp() override;
    void moveLineDown() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

};

#endif // ROCKET_H
