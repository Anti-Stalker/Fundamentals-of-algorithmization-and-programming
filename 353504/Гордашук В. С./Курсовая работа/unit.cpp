#include "unit.h"

Unit::Unit(QObject *parent)
    : QObject{parent}, QGraphicsItem()
{
    animation = new QGraphicsItemAnimation;
    animation->setItem(this);
    animation->setTimeLine(timer);
    connect(timer, &QTimeLine::finished, this, &Unit::animFinish);
}

QRectF Unit::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void Unit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (selected)
    {
        painter->setPen(Qt::red);
    }
    else if (!selected)
    {
        painter->setPen(color);
    }
    painter->setBrush(brushColor);
    painter->drawEllipse(0, 0, 25, 25);
    if (!isEnemy)
    {
        painter->setBrush(Qt::black);
        painter->drawEllipse(8, 8, 9, 9);
    }
}

void Unit::move(std::vector<std::pair<int, int>> path)
{
    if (path.size() == 0) return;
    inMove = true;
    timer->setDuration(500 * path.size());
    timer->setFrameRange(0, 500 * path.size());
    timer->stop();
    animation->clear();
    for (int i = 0; i < path.size(); ++i)
    {
        animation->setPosAt(1 / (double)path.size() * i, QPointF(path[i].first * 25, path[i].second * 25));
    }
    timer->start();
    to = QPointF(path[path.size() - 1].first, path[path.size() - 1].second);
}

double Unit::getDistance(QPointF point1, QPointF point2)
{
    return sqrt((point1.x() - point2.x()) * (point1.x() - point2.x()) + (point1.y() - point2.y()) * (point1.y() - point2.y()));
}

void Unit::getDamage()
{
    color = Qt::green;
    update();
    QEventLoop loop;
    QTimer::singleShot(10, &loop, SLOT(quit()));
    loop.exec();
    color = baseColor;
    update();
}

void Unit::animFinish()
{
    from = to;
    inMove = false;
}
