#include "figurecircle.h"

FigureCircle::FigureCircle() {}

void FigureCircle::receiveRadius(int r)
{
    radius = r;
}

void FigureCircle::receiveRotation(bool is)
{
    checkRotation = is;
}

void FigureCircle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawEllipse(-radius/2, -radius/2, radius, radius);
    if (checkRotation) {
        QPen pen(Qt::DashLine);
        painter->setPen(pen);
        painter->drawLine(-radius/2, 0, radius/2, 0);
        painter->drawLine(0, -radius/2, 0, radius/2);
    }
}

float FigureCircle::findSquare()
{
    float scale = this->getScale();
    return scale * scale * radius * radius * M_PI;
}

float FigureCircle::findPerimeter()
{
    float scale = this->getScale();
    return 2 * M_PI * radius * scale;
}
