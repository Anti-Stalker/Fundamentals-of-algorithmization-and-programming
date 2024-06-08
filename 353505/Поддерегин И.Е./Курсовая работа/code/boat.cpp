#include "boat.h"

Boat::Boat()
{

}

Boat::~Boat()
{


}

void Boat::paint(QPainter *paint, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    paint->setRenderHint(QPainter::Antialiasing);
    paint->setPen(Qt::white);
    paint->setBrush(Qt::white);

    paint->setRenderHint(QPainter::Antialiasing);
    paint->setPen(Qt::white);
    paint->setBrush(Qt::white);

    paint->drawChord(68, 51, 40, 40, 75*16, 34*16);
    paint->drawChord(29, 30, 75, 150, 0, 720);
    paint->drawChord(71, 30, 75, 150, 2160, 720);

    const QPointF points[4] = {
        QPointF(82, 50),     //лево верх
        QPointF(93, 50),   //право верх
        QPointF(105, 106),  //право низ
        QPointF(70, 106)    //лево низ
    };
    paint->drawConvexPolygon(points, 4);

    paint->setPen(Qt::black);
    const QPointF points2[4] = {
        QPointF(86, 70),     //лево верх
        QPointF(89, 70),   //право верх
        QPointF(95, 90),  //право низ
        QPointF(80, 90)    //лево низ
    };
    paint->drawConvexPolygon(points2, 4);

    paint->drawArc(30, 30, 75, 150, 0, 720);
    paint->drawArc(68, 50, 40, 40, 75*16, 34*16); //корпус
    paint->drawArc(70, 30, 75, 150, 2160, 720);
    paint->drawLine(QLineF(70,106,105,106));
}

QRectF Boat::boundingRect() const
{

    return QRectF(70,50,35,56);
}
