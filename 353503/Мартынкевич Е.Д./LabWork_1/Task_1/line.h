#ifndef LINE_H
#define LINE_H
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsItem>

class Line : public QGraphicsItem{
public:
    explicit Line();
    void off_on();
    void move();
    QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
protected:
    bool on_off;
    QRectF rect_;
};

#endif // LINE_H
