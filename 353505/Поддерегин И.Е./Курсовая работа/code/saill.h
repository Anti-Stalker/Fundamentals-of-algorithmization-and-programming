#ifndef SAILL_H
#define SAILL_H

#include "sail.h"


class SailL:public QGraphicsItem
{
public:
    SailL();

    ~SailL();

protected:
    void paint(QPainter *paint, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // SAILL_H
