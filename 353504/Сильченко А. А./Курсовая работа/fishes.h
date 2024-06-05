#ifndef FISHES_H
#define FISHES_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

class Fishes: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Fishes(QObject *parent = 0);
    ~Fishes();

    void move();
    int m;
    double x=0, y=0, mid=0, h, w, midx=0, midy=0;
    double *xi, *yi, *midxi, *midyi, *wi, *hi;
public slots:
    void pathGeneration();
signals:

private:
    QTimer *t;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // FISHES_H
