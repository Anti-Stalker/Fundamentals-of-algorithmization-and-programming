#include "moveitem.h"

MoveItem::MoveItem(ItemType type, QObject *parent) : QObject(parent), QGraphicsItem()
{
    itemType = type;
}

MoveItem::~MoveItem()
{
}

QRectF MoveItem::boundingRect() const
{
    return QRectF(-30, -30, 60, 60);
}

void MoveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch (itemType)
    {
    case noteType:
        painter->setPen(Qt::black);
        painter->setBrush(Qt::green);
        painter->drawEllipse(-30, -30, 60, 60);
        Q_UNUSED(option);
        Q_UNUSED(widget);
        break;

    case tagType:
        painter->setPen(Qt::black);
        painter->setBrush(Qt::red);
        painter->drawEllipse(-15, -15, 30, 30);
        Q_UNUSED(option);
        Q_UNUSED(widget);
        break;
    }
}

void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void MoveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

void MoveItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    emit itemDoubleClicked(id, title);
    Q_UNUSED(event);
}

void MoveItem::setupMoveItemNote(const Note &note)
{
    titleText = new QGraphicsTextItem(note.title, this);
    titleText->setPos(-30, 30);

    title = note.title;
    tags = note.tags;
    id = note.id;
}

void MoveItem::setupMoveItemTag(const QString tag)
{
    titleText = new QGraphicsTextItem(tag, this);
    titleText->setPos(-15, 15);

    title = tag;
    tags = "";
    id = -1;
}
    
QPointF MoveItem::getPosition() const
{
    return mapToScene(0, 0);
}

