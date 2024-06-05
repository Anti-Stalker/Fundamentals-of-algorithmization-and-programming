#include "Egg.h"
#include "globals.h"

Egg::Egg()
{
    QPixmap image("../resources/egg.png");
    if (image.isNull()) {
        qDebug() << "no egg";
    }
 
    m_image = image.scaled(50, 50); 

    setAcceptHoverEvents(true);

    isMouseOnThisEgg = false;
    isMouseOnEgg = false;    
}

QRectF Egg::boundingRect() const
{
    return QRectF(0, 0, m_image.width(), m_image.height());
}

void Egg::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) 
{
    if(isMouseOnThisEgg)
        painter->setPen(QColor(255,0,0));
    painter->drawRoundedRect(0, 0, m_image.width(), m_image.height(), 5, 5);
    painter->drawPixmap(0, 0, m_image);

}

void Egg::hoverEnterEvent(QGraphicsSceneHoverEvent*) 
{
    isMouseOnEgg = true;
    isMouseOnThisEgg = true;
    QGraphicsItem::update();
}
//------------------------------------------------------------------------------
void Egg::hoverLeaveEvent(QGraphicsSceneHoverEvent*) 
{
    isMouseOnEgg = false;
    isMouseOnThisEgg = false;
    QGraphicsItem::update();
}

void Egg::mousePressEvent(QGraphicsSceneMouseEvent *aEvent) 
{   
    if(!wasEggCollectedBool){

        isMouseOnThisEgg = true;

        move();

        coord = aEvent->pos();
    }
}


void Egg::move(){

    qreal Distance = sqrt(abs((pos().x() - 600) * (pos().x() - 600) + (pos().y() - 600) * (pos().y() - 600)));

    QPropertyAnimation* animation = new QPropertyAnimation(this, "pos");

    animation->setDuration(Distance * 4); 
    animation->setStartValue(pos()); 
    animation->setEndValue(QPoint(600, 700)); 
    
    QObject::connect(animation, &QPropertyAnimation::finished, [this]() {
        emit eggWasCollected(this);
    });

    animation->start();
}

void Egg::mouseReleaseEvent(QGraphicsSceneMouseEvent *aEvent) 
{
}
