#ifndef FLAMES_H
#define FLAMES_H

#include "movingline.h"

class Flames : public MovingLine
{
public:
    Flames();
    void moveLineUp() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};


#endif // FLAMES_H
