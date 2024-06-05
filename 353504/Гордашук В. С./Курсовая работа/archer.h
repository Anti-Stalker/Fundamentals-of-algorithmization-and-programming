#ifndef ARCHER_H
#define ARCHER_H

#include "unit.h"

class Archer : public Unit
{
public:
    Archer();


    // QGraphicsItem interface
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ARCHER_H
