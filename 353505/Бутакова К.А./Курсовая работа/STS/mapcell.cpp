#include "mapcell.h"
#include "datahub.h"

#include <iostream>
#include <QPainter>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>

MapCell::MapCell()
{
    brushColor = colorUsed::None_Brust;
    penColor = colorUsed::None_Pen;
    Obstacle = false;
    setFlag(QGraphicsItem::ItemIsFocusable);
    m_dSide = FieldData::lenght;
}

QRectF MapCell::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-(m_dSide/2) - adjust, -(m_dSide/2) - adjust, m_dSide + adjust, m_dSide + adjust);
}

void MapCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(brushColor);
    painter->setPen(QPen(penColor, Qt::MiterJoin));
    painter->drawRect(-(m_dSide/2), -(m_dSide/2), m_dSide, m_dSide);
}

std::string MapCell::getCoorInfo()
{
    std::string s = "(" + std::to_string(m_CoorX) + ", " + std::to_string(m_CoorY) + ")\n";
    return s;
}

void MapCell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!Obstacle)
    {
        emit GroundIsSelected(this);
    }
}

void MapCell::setColor(QColor brust, QColor pen)
{
    if(Obstacle)
    {
        brushColor = colorUsed::Obstacle_Brust;
        penColor = colorUsed::None_Pen;
    }
    else
    {
        brushColor = brust;
        penColor = pen;
    }
}


