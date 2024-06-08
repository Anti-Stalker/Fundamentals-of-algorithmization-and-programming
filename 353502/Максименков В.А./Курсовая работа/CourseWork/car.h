#ifndef CAR_H
#define CAR_H
#include <QGraphicsItem>
#include <QPainter>
#include <QImage>

const int LENGTH_OF_CAR = 150;
const int WIDTH_OF_CAR = 80;
const QString CAR_IMAGE = "/home/vlad/Загрузки/Automobile.jpeg";

class Car : public QGraphicsItem
{
private:
    QImage car;

    QRectF targetRect = QRectF(-LENGTH_OF_CAR/2, -WIDTH_OF_CAR/2, LENGTH_OF_CAR*2, WIDTH_OF_CAR*2);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

public:
    Car();
};

#endif // CAR_H
