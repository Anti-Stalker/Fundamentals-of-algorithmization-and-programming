#ifndef ARROW_H
#define ARROW_H
#include <QGraphicsItem>
#include <QPainter>

const int WIDTH_OF_ARROW = 50;
const int HEIGHT_OF_ARROW = 20;

class Arrow : public QGraphicsItem
{
private:
    QPointF leftDown = QPointF(0, HEIGHT_OF_ARROW/2);
    QPointF leftUp = QPointF(0, -HEIGHT_OF_ARROW/2);
    QPointF right = QPointF(WIDTH_OF_ARROW, 0);

public:
    Arrow() = default;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ARROW_H
