#ifndef BOAT_H
#define BOAT_H

#include <QGraphicsItem>
#include <QPainter>

class Boat: public QGraphicsItem
{
public:
    double q=0,w=0,q2=0,w2=0;
    Boat();
    ~Boat();
    bool starboard;
protected:
    void paint(QPainter *paint, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // BOAT_H
