#ifndef FIGURECIRCLE_H
#define FIGURECIRCLE_H

#include "figure.h"

#include <QPainter>
#include <QDebug>

class FigureCircle : public Figure
{
public:
    FigureCircle();

public slots:
    void receiveRadius(int r);
    void receiveRotation(bool is);
    float findPerimeter() override;
    float findSquare() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    bool checkRotation = false;
    int radius;
};

#endif // FIGURECIRCLE_H
