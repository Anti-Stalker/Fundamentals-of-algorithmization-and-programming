#include "product.h"
#include "globals.h"

Product::Product()
{
    QPixmap image("../resources/product.png");
    if (image.isNull()) {
        qDebug() << "no egg";
    }
 
    m_image = image.scaled(50, 70); 

    setAcceptHoverEvents(true);

    isMouseOnProduct = false;    
}

QRectF Product::boundingRect() const
{
    return QRectF(0, 0, m_image.width(), m_image.height());
}

void Product::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) 
{
    painter->drawRoundedRect(0, 0, m_image.width(), m_image.height(), 5, 5);
    painter->drawPixmap(0, 0, m_image);
}

void Product::hoverEnterEvent(QGraphicsSceneHoverEvent*) 
{
    isMouseOnProduct = true;
    QGraphicsItem::update();
}
//------------------------------------------------------------------------------
void Product::hoverLeaveEvent(QGraphicsSceneHoverEvent*) 
{
    isMouseOnProduct = false;
    QGraphicsItem::update();
}

void Product::mousePressEvent(QGraphicsSceneMouseEvent *aEvent) 
{   
        move();
        coord = aEvent->pos();
}

void Product::move(){

    if(!productWasCollectedBool){
        qreal Distance = sqrt(abs((pos().x() - 600) * (pos().x() - 600) + (pos().y() - 600) * (pos().y() - 600)));

        QPropertyAnimation* animation = new QPropertyAnimation(this, "pos");

        animation->setDuration(Distance * 4); 
        animation->setStartValue(pos()); 
        animation->setEndValue(QPoint(580, 720)); 

        
        QObject::connect(animation, &QPropertyAnimation::finished, [this]() {
            emit productWasCollected();
            productWasCollectedBool = true;
        });

        animation->start();
    }
}

void Product::mouseReleaseEvent(QGraphicsSceneMouseEvent *aEvent) 
{
}
