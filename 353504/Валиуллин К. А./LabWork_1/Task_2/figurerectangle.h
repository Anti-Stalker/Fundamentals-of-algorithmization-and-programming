#ifndef FIGURERECTANGLE_H
#define FIGURERECTANGLE_H

#include "figure.h"
#include "dialogrectangle.h"

#include <QPainter>
#include <QDebug>

class FigureRectangle : public Figure
{
public:
    FigureRectangle();
    float findPerimeter() override;
    float findSquare() override;

public slots:
    void receiveValues(sidesValues &sides);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int side1, side2;
};

#endif // FIGURERECTANGLE_H
