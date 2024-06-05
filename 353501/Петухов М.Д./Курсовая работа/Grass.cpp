#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsObject>
#include "Grass.h"


Grass::Grass(QGraphicsItem* parent) : QGraphicsObject(parent)
{
    QPixmap image("../resources/grass_final-transformed.png");
    if (image.isNull()) {
        qDebug() << "no picture of grass";
    }

    m_image = image.scaled(100, 100);   
}

QRectF Grass::boundingRect() const
{
    return QRectF(0, 0, m_image.width(), m_image.height());
}

void Grass::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->drawPixmap(0, 0, m_image);
}

