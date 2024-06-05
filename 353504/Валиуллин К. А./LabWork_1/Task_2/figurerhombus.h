#ifndef FIGURERHOMBUS_H
#define FIGURERHOMBUS_H

#include "figure.h"
#include "dialogrhombus.h"

#include <QPainter>

class FigureRhombus : public Figure
{
public:
    FigureRhombus();
    float findSquare() override;
    float findPerimeter() override;

public slots:
    void receiveRhombus(sideAndAngleCoordinates &coordinates);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int d1, d2;
};

#endif // FIGURERHOMBUS_H
