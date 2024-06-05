#ifndef SWORDSMAN_H
#define SWORDSMAN_H

#include <unit.h>

class Swordsman : public Unit
{
public:
    Swordsman();


    // QGraphicsItem interface
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // SWORDSMAN_H
