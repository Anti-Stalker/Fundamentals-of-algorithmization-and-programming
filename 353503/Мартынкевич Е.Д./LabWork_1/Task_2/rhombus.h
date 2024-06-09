#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <QObject>
#include <QGraphicsItem>
#include "figures.h"

class rhombus : public figures
{
    Q_OBJECT;
public:
    explicit rhombus(QPointF point, QObject *parent = 0);
    ~rhombus();

    void set_perimetr() override;
    void set_square() override;
private:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget);
};

#endif // RHOMBUS_H
