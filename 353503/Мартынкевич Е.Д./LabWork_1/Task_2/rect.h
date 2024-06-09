#ifndef RECT_H
#define RECT_H

#include <QGraphicsItem>
#include "figures.h"

class rect : public figures
{
    Q_OBJECT;
public:
    explicit rect(QPointF point, QObject *parent = 0);
    ~rect();

    void set_perimetr() override;
    void set_square() override;

private:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget);
};

#endif // RECT_H
