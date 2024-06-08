#include "bowlingpin.h"
#include<QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QPen>

BowlingPin::BowlingPin(qreal x, qreal y, qreal width, qreal height,qreal mass, QGraphicsItem* parent)
    : QGraphicsItemGroup(parent), m_mass(mass)
{
    qreal ballRadius = width / 2;

    qreal ballY = y;
    qreal cylinderY = y + ballRadius + 0.1 * height; // Добавляем небольшой зазор

    cylinder = new QGraphicsEllipseItem(x, cylinderY, width, height - ballRadius + 10, this);
    cylinder->setBrush(Qt::darkGray); // Цвет цилиндра

    ball = new QGraphicsEllipseItem(x, ballY, width, ballRadius + 14, this);
    ball->setBrush(Qt::darkRed); // Цвет шара

    addToGroup(cylinder);
    addToGroup(ball);

    // Добавляем проекцию эллипса
    qreal ellipseRadiusY = (height - ballRadius) / 2;
    qreal ellipseX = x;
    qreal ellipseY = y + height; // Положение проекции по Y
    QGraphicsEllipseItem* ellipseProjection = new QGraphicsEllipseItem(ellipseX, ellipseY, width, ellipseRadiusY * 2, this);
    ellipseProjection->setPen(QPen(Qt::black, 0, Qt::DashLine)); // Пунктирная линия
    addToGroup(ellipseProjection);

    // Добавляем возможность перемещения кегли
    setFlags(ItemIsMovable | ItemIsSelectable);

}
void BowlingPin::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    Q_UNUSED(event);
    setSelected(!isSelected()); // Переключаем выделение при клике на кеглю
    QGraphicsItemGroup::mousePressEvent(event); // Передаем событие базовому классу

}
