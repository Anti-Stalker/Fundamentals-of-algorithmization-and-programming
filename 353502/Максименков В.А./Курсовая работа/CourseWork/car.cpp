#include "car.h"


QRectF Car::boundingRect() const
{
    return targetRect;
}


void Car::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawImage(targetRect, car);
}


Car::Car()
{
    car = QImage(CAR_IMAGE);
}
