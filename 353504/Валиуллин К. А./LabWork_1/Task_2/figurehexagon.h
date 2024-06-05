#ifndef FIGUREHEXAGON_H
#define FIGUREHEXAGON_H

#include "figure.h"
#include "dialoghexagon.h".h"

#include <QPainter>

class FigureHexagon : public Figure
{
public:
    FigureHexagon();
    float findPerimeter() override;
    float findSquare() override;

public slots:
    void receiveValue(int side);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int side;
};

#endif // FIGUREHEXAGON_H
