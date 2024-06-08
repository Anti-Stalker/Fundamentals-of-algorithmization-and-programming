#include "key.h"


Key::Key()
{
    key = QImage(KEY_IMAGE);
}


void Key::selectKey()
{
    setTransformOriginPoint(boundingRect().center());
    setScale(1.5);
}


void Key::returnDefaultState()
{
    setTransformOriginPoint(boundingRect().center());
    setScale(1);
}


QRectF Key::boundingRect() const
{
    return targetRect;
}


void Key::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawImage(targetRect, key);
}

