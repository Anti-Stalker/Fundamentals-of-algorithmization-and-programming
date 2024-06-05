#include "fish.h"

Fish::Fish(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    xj=&x;
    yj=&y;
    wj=&w;
    hj=&h;
}

Fish::~Fish()
{

}

QRectF Fish::boundingRect() const
{
    return QRectF (-30,-30,60,60);
}

void Fish::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //QImage image("url(:/Images/Images/15.png)");
    QImage image("/home/oblachko/Projects/CourseProject/fish.jpg");
    QRect recrangle(-30,-30,60,60);
    QRectF source( 0.0 ,  0.0 ,  70.0 ,  40.0 );
    /*painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawRect(-30,-30,60,60);*/
    painter->drawImage(recrangle, image);

    /*painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawRect(-30,-30,60,60);*/
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Fish::growFish(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget, int i)
{
    QImage image("/home/oblachko/Projects/CourseProject/fish.jpg");
    for(int j=1; j<=i; ++j)
    {
    QRect recrangle(x,y,w+j,h+j);
    painter->drawImage(recrangle, image);
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

void Fish::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));
}

void Fish::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void Fish::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}


