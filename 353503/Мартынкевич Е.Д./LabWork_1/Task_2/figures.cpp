#include "figures.h"

figures::figures(QPointF point, QObject *parent) : QObject(parent), QGraphicsItem()
{
    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));

    connect(this, &figures::point_changed, this, &figures::updeteRect);
}

figures::~figures()
{

}

QPointF figures::startPoint() const
{
    return m_startpoint;
}

QPointF figures::endPoint() const
{
    return m_endpoint;
}

void figures::setStartPoint(const QPointF point)
{
    m_startpoint = mapFromScene(point);
    emit point_changed();
}

void figures::setEndPoint(const QPointF point)
{
    m_endpoint = mapFromScene(point);
    emit point_changed();
}

//void figures::set_centre(const QPointF point)
//{
//    m_centre = point;
//}

double figures::perimetr()
{
    return m_perimetr;
}

double figures::square()
{
    return m_square;
}

QPointF figures::centre()
{
    return m_centre;
}

void figures::set_centre()
{
    m_centre = this->boundingRect().center();
}

QRectF figures::boundingRect() const
{
    return QRectF(m_startpoint.x() < m_endpoint.x() ? m_startpoint.x() : m_endpoint.x() - 5,
                  m_startpoint.y() < m_endpoint.y() ? m_startpoint.y() : m_endpoint.y() - 5,
                  qAbs(m_startpoint.x() - m_endpoint.x()) + 10,
                  qAbs(m_startpoint.y() - m_endpoint.y() + 10)
                  );
}

void figures::updeteRect()
{
    this->update(QRectF(m_startpoint.x() < m_endpoint.x() ? m_startpoint.x() : m_endpoint.x() - 5,
                        m_startpoint.y() < m_endpoint.y() ? m_startpoint.y() : m_endpoint.y() - 5,
                        qAbs(m_startpoint.x() - m_endpoint.x()) + 10,
                        qAbs(m_startpoint.y() - m_endpoint.y()) + 10
                        ));

    this->set_perimetr();
    this->set_square();
    this->set_centre();
}
