#ifndef MINE_H
#define MINE_H

#include "basetower.h"

class Mine : public BaseTower
{
public:
    Mine();


    // QGraphicsItem interface
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // MINE_H
