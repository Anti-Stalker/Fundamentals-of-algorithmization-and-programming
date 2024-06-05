#ifndef FIGUREOVAL_H
#define FIGUREOVAL_H

#include "figure.h"
#include "dialogoval.h"

#include <QPainter>

class FigureOval : public Figure
{
public:
    FigureOval();
    float findPerimeter() override;
    float findSquare() override;

public slots:
    void receiveValues(valuesOfOval &values);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int radius1, radius2;
};

#endif // FIGUREOVAL_H
