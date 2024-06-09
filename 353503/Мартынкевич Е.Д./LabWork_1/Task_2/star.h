#ifndef STAR_H
#define STAR_H

#include "figures.h"

class star : public figures
{
public:
    star(int n, QPointF point, QObject* parent = 0);
    void paintEvent(int n);
    void set_perimetr() override;
    void set_square() override;

private:
    int count_point;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget);
};

#endif // STAR_H
