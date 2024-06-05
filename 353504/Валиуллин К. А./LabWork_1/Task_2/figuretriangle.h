#ifndef FIGURETRIANGLE_H
#define FIGURETRIANGLE_H

#include <QPainterPath>
#include <QPainter>

#include "figure.h"
#include "dialogtriangle.h"


class FigureTriangle : public Figure
{
public:
    FigureTriangle();
    float findSquare() override;
    float findPerimeter() override;

public slots:
    void receiveTriangleValues(const TriangleCoordinates &coordinates);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int x1,x2,x3,y1,y2,y3;
};

#endif // FIGURETRIANGLE_H
