#include "figure.h"

Figure::Figure() {}

void Figure::upScale() {
    scale = scale * 1.01;
    this->setScale(scale);
}

void Figure::downScale() {
    scale = scale / 1.01;
    this->setScale(scale);
}

float Figure::getScale()
{
    return this->scale;
}

void Figure::receiveValues(valuesNewXY &XY)
{
    xCoord = XY.x;
    yCoord = XY.y;
}

void Figure::moveRight() {
    this->setPos(this->x() + 2, this->y());
}

void Figure::moveLeft() {
    this->setPos(this->x() - 2, this->y());
}

void Figure::moveUp()
{
    this->setPos(this->x(), this->y() - 2);
}

void Figure::moveDown()
{
    this->setPos(this->x(), this->y() + 2);
}

QRectF Figure::boundingRect() const {
    return QRectF(-500,-500,1000,1000);
}

void Figure::rotateRight()
{
    this->setRotation(rotation() + 1);
}

void Figure::rotateLeft()
{
    this->setRotation(rotation() -1);
}

void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {}

float Figure::findSquare() {}

float Figure::findPerimeter() {}

void Figure::setPosition()
{
    this->setPos(xCoord, yCoord);
}

CoordinatesXY Figure::showPosition()
{
    CoordinatesXY coordinates;
    coordinates.x = this->pos().x();
    coordinates.y = this->pos().y();
    return coordinates;
}

