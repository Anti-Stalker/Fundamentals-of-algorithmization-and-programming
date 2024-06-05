#ifndef FIGURESTAR6_H
#define FIGURESTAR6_H

#include "figure.h"
#include "dialogstar.h"

#include <QPainter>

class FigureStar6 : public Figure
{
public:
    FigureStar6();
    float findPerimeter() override;
    float findSquare() override;

public slots:
    void receiveValue(int sideOfStar);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int side;
};

#endif // FIGURESTAR6_H
