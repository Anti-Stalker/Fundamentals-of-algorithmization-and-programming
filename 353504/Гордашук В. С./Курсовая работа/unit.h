#ifndef UNIT_H
#define UNIT_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QGraphicsItemAnimation>
#include <QTimer>
#include <QTimeLine>
#include <QEventLoop>

class Unit : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Unit(QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double health = 100;
    QPointF to = QPointF();
    QPointF from = QPointF();
    QColor baseColor = Qt::blue;
    QColor color = Qt::blue;
    QColor brushColor = Qt::blue;
    bool selected = false;
    void move(std::vector<std::pair<int, int>> path);
    double getDistance(QPointF point1, QPointF point2);
    void getDamage();
    double range = 2;
    QList<QPair<int, QPair<double, int>>> nearList;
    bool inMove = false;
    bool isEnemy = true;

signals:
    void hpChange();
    void posChange();
    void animFin();

public slots:
    void animFinish();

protected:
    double damage;

private:
    QGraphicsItemAnimation *animation;
    QTimeLine *timer = new QTimeLine();
};

#endif // UNIT_H
