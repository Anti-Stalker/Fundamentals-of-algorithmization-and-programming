#ifndef FIGURESQUARE_H
#define FIGURESQUARE_H

#include "figure.h"

#include <QPainter>

class FigureSquare : public Figure
{
public:
    FigureSquare();
    float findPerimeter() override;
    float findSquare() override;

public slots:
    void receiveValues(int s);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int side;
};

#endif // FIGURESQUARE_H
