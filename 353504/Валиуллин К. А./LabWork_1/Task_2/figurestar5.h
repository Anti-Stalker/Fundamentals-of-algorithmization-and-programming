#ifndef FIGURESTAR5_H
#define FIGURESTAR5_H

#include "figure.h"
#include "dialogstar.h"

#include <QPainter>

class FigureStar5 : public Figure
{
public:
    FigureStar5();
    float findPerimeter() override;
    float findSquare() override;

public slots:
    void receiveValue(int sideOfStar);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int side;
};

#endif // FIGURESTAR5_H
