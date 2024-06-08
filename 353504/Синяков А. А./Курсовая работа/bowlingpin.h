#ifndef BOWLINGPIN_H
#define BOWLINGPIN_H

#include <QGraphicsItemGroup>
#include <QGraphicsEllipseItem>
#include <QPointF>

class BowlingPin : public QGraphicsItemGroup
{
public:
    BowlingPin(qreal x, qreal y, qreal width, qreal height,qreal mass, QGraphicsItem* parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

private:
    QGraphicsEllipseItem* cylinder;
    QGraphicsEllipseItem* ball;
    qreal m_mass;
};

#endif // BOWLINGPIN_H
