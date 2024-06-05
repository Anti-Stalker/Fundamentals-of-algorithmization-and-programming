#include "figureoval.h"

FigureOval::FigureOval() {}

float FigureOval::findPerimeter()
{
    float scale = this->getScale();
    return 2 * scale * M_PI * sqrt((radius1 * radius1 + radius2 * radius2) / 2);
}

float FigureOval::findSquare()
{
    float scale = this->getScale();
    return scale * scale * M_PI * radius1 * radius2;
}

void FigureOval::receiveValues(valuesOfOval &values)
{
    radius1 = values.r1;
    radius2 = values.r2;
}

void FigureOval::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawEllipse(-radius1/2, -radius2/2, radius1, radius2);
}
