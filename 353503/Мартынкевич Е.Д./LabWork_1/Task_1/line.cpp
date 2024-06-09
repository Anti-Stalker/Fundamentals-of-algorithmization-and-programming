#include "line.h"
#include "QPainter"

void Line::paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawLine(100, 500, 100, 400);
}

void Line::off_on()
{
    on_off = true;
}

void Line::move()
{
    if(on_off == true) {
        this->setPos(this->x(), this->y() - 1);
    }

    if(this->y() < -100) {
        this->setPos(this->x(), this->y() + 600);
        on_off = false;
    }
}

QRectF Line::boundingRect() const
{
    return rect_;
}

Line::Line() : QGraphicsItem()
{
    rect_ = QRectF(0, 0, 90, 40);
    on_off = false;
}
