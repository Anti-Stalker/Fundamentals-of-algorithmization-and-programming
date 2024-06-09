#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include "figures.h"

class triangle : public figures
{
    Q_OBJECT;
public:
    explicit triangle(QPointF point, QObject* parent = 0);
    ~triangle();

    void set_perimetr() override;
    void set_square() override;
private:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget);
};

#endif // TRIANGLE_H
