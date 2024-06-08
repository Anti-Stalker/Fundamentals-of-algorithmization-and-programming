#include "arrow.h"


QRectF Arrow::boundingRect() const
{
    return QRectF(leftUp.x(), leftUp.y(), leftDown.y() - leftUp.y(), right.x() - leftDown.x());
}

void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawLine(leftDown, right);
    painter->drawLine(leftUp, right);
    painter->drawLine(leftDown, leftUp);
}
