#ifndef FIGURESTAR8_H
#define FIGURESTAR8_H

#include "figure.h"
#include "dialogstar.h"

#include <QPainter>

class FigureStar8 : public Figure
{
public:
    FigureStar8();
    float findPerimeter() override;
    float findSquare() override;

public slots:
    void receiveValue(int sideOfStar);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int side;
};

#endif // FIGURESTAR8_H
