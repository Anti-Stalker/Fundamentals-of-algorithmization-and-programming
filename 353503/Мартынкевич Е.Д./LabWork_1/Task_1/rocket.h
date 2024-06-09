#ifndef ROCKET_H
#define ROCKET_H
#include <QTime>
#include <QTimerEvent>
#include "line.h"

class Rocket : public Line
{
public:
    Rocket();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    int angle_wheel = 0;
private:
};

#endif // ROCKET_H
