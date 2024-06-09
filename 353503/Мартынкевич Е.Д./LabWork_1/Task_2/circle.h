#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsItem>
#include "figures.h"

class circle : public figures
{
    Q_OBJECT;
public:
    explicit circle(QPointF point, QObject *parent = 0);
    ~circle();

    void set_perimetr() override;
    void set_square() override;

private:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget);
};

#endif // CIRCLE_H
