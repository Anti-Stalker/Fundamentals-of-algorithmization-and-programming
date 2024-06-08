#ifndef KEY_H
#define KEY_H
#include <QGraphicsItem>
#include <QPainter>
#include <QImage>

const int KEY_SIZE = 40;
const QString KEY_IMAGE = "/home/vlad/Загрузки/Key-Free-PNG-Image.png";

class Key : public QGraphicsItem
{
private:
    QImage key;
    QRectF targetRect = QRectF(-KEY_SIZE/2, -KEY_SIZE/2, 2*KEY_SIZE, 2*KEY_SIZE);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

public:
    Key();

    void selectKey();
    void returnDefaultState();
};

#endif // KEY_H
