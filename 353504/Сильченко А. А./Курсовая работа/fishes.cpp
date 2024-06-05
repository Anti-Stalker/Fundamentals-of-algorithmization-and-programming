#include "fishes.h"

Fishes::Fishes(QObject *parent) : QObject(parent), QGraphicsItem(){
    xi=&x;
    yi=&y;
    wi=&w;
    hi=&h;
}

Fishes::~Fishes()
{

}

QRectF Fishes::boundingRect() const
{
    return QRectF (-30,-30,60,60);
}

void Fishes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    x=rand()%100;
    y=rand()%100;
    w=rand()%100;
    h=w;
    midx=x+w/2;
    midy=y+h/2;
    midxi=&midx;
    midyi=&midy;
    //QImage image("url(:/Images/Images/15.png)");
    QImage image("/home/oblachko/Projects/CourseProject/fish.jpg");
    QRect recrangle(*xi,*yi,w,h);
    QRectF source( 0.0 ,  0.0 ,  70.0 ,  40.0 );
    painter->drawImage(recrangle, image);
    m=rand()%4;
    //qDebug()<<m;

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Fishes::move()
{
    m=rand()%4;
    //qDebug()<<m;
    switch(m)
    {
    case 0:
        for(; x<1700; x+=0.01)
        {
            this->setPos(x, y);
            t->start(10000);
        }
    case 1:
        for(; x<1700&&y>600; x+=0.01, y+=0.01)
        {
            this->setPos(x, y);
        t->start(10000);
        }
    case 2:
        for(; x<1700&&y>0; x+=0.01, y-=0.01)
        {

            this->setPos(x, y);
        t->start(10000);
        }
    default:
        update();
    }
}

void Fishes::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
    /*    m=0;
    //m=rand()%4;
    //qDebug()<<m;
    switch(m)
    {
    case 0:
        for(; x<1700; x+=0.01)
        {
            this->setPos(x, y);
        }
    case 1:
        for(; x<1700&&y>600; x+=0.01, y+=0.01)
            this->setPos(x, y);
    case 2:
        for(; x<1700&&y>0; x+=0.01, y-=0.01)
            this->setPos(x, y);
    default:
    }*/
}

void Fishes::pathGeneration()
{
    m=rand()%5;
    //qDebug()<<m;
    if(x<=0)
    {
        switch(m)
        {
        case 0:
            for(; x<1700; x+=0.01)
                this->setPos(x, y);
        case 1:
            for(; x<1700&&y<600; x+=0.02, y+=0.01)
                this->setPos(x, y);
        case 2:
            for(; x<1700&&y>0; x+=0.03, y-=0.04)
                this->setPos(x, y);
        case 3:
            for(; x<1700&&y<600; x+=0.001, y+=0.001)
                this->setPos(x, y);
        case 4:
            for(; x<1700&&y>0; x+=0.02, y-=0.02)
                this->setPos(x, y);
        default:
        }
    }
    else
    {
        switch(m)
        {
        case 0:
            for(; x>0; x-=0.01)
            {
                this->setPos(x, y);
            }
        case 1:
            for(; x>0&&y<600; x+=0.02, y+=0.03)
                this->setPos(x, y);
        case 2:
            for(; x>0&&y>0; x+=0.03, y-=0.01)
                this->setPos(x, y);
        case 3:
            for(; x>0&&y<600; x+=0.01, y+=0.03)
                this->setPos(x, y);
        case 4:
            for(; x>0&&y>0; x+=0.001, y-=0.02)
                this->setPos(x, y);
        default:
        }
    }
}
