#include "factory.h"

Factory::Factory(int* collectedEggs, QGraphicsItem* parent) : QGraphicsObject(parent)
{
    _collectedEggs = collectedEggs;
    QPixmap image("../resources/factory.png");
    if (image.isNull()) {
        qDebug() << "no picture of grass";
    }
    m_image = image.scaled(170, 170);
    timerToMakeProduct = new QTimer();
    setFlag(ItemIsSelectable, true);
    setFlag(ItemIsFocusable, true);
}

void Factory::hoverEnterEvent(QGraphicsSceneHoverEvent*) 
{
    QGraphicsItem::update();
}
//------------------------------------------------------------------------------
void Factory::hoverLeaveEvent(QGraphicsSceneHoverEvent*) 
{
    QGraphicsItem::update();
}
//------------------------------------------------------------------------------
void Factory::mouseReleaseEvent(QGraphicsSceneMouseEvent *aEvent) 
{   
    if(!isFactoryWorking){
        if(*_collectedEggs > 0){
            --(*_collectedEggs);
            connect(timerToMakeProduct, &QTimer::timeout, this, &Factory::updateMakingProduct);
            timerToMakeProduct->start(2000);
            isFactoryWorking = true;
            QGraphicsItem::update();
            emit updateCollectedEggsLabelSignal();
        }
    }
}

void Factory::updateMakingProduct(){
    if(progress < 8){
        progress++;
    }
    else{
        progress = 0;
        disconnect(timerToMakeProduct, &QTimer::timeout, this, &Factory::updateMakingProduct);
        timerToMakeProduct->stop();
        emit makeProduct();
        isFactoryWorking = false;
    }
    QGraphicsItem::update();
}

QRectF Factory::boundingRect() const
{
    return QRectF(0, 0, m_image.width(), m_image.height());
}

void Factory::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->drawPixmap(0, 0, m_image);
    for(int i = 0; i < progress; i++){
        painter->setBrush(Qt::yellow);
        painter->drawRect(0, 170 - (170 / 8) * (i + 1), 15, 15);
    }
}

