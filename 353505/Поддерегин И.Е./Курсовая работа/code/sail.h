#ifndef SAIL_H
#define SAIL_H

#include <QGraphicsItem>
#include <QPainter>

class Sail : public QGraphicsItem
{
public:
    Sail();
    ~Sail();
protected:
    void paint(QPainter *paint, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};


#endif // SAIL_H
