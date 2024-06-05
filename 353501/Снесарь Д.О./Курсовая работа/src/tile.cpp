#include "tile.h"

Tile::Tile(int row, int col, double size) : row_(row), col_(col), size_(size)
{
    setRect(col * size, row * size, size, size);
    setAcceptHoverEvents(true);
    setAcceptTouchEvents(true);
    setFlag(QGraphicsItem::ItemIsSelectable);
    curColor = mainColor;
    isSelected_ = false;
}

/*Tile::Tile()
{
}*/
void Tile::setIncorrect()
{
    curColor = incorrectColor;
    update();
}

int Tile::getNumber()
{
    if(number=="")
        return -1;
    else
        return number.toInt();
}

bool Tile::isCorrect()
{
    if(curColor == incorrectColor)
        return false;
    else
        return true;
}

void Tile::setIsChangeable(bool value)
{
    isChangeable = value;
}

bool Tile::getIsChaneable()
{
    return isChangeable;
}
void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush brush(curColor);
    painter->setBrush(brush);
    painter->setPen(QPen(Qt::black, 1.5));
    painter->drawRect(rect());
    painter->setPen(Qt::black);
    painter->setFont(QFont("Arial", size_ / 3.5));
    painter->drawText(rect(), Qt::AlignCenter, number);
}

void Tile::setPos(int row, int col, double size)
{
    row_ = row;
    col_ = col;
    size = size_;
    setRect(col * size, row * size, size, size);
}

void Tile::setNumber(int n)
{
    if(n == -1){
        number = "";
    }
    else{
        number = QString::number(n);
    }
    update();
}

void Tile::setTileSize(double size)
{
    size_ = size;
}

int Tile::getRow()
{
    return row_;
}

int Tile::getCol()
{
    return col_;
}

void Tile::hilight()
{
    if(curColor != incorrectColor)
    curColor = secondaryColor;
    update();
}

void Tile::hilightInsertion()
{
    if(curColor != incorrectColor)
    curColor = insertionColor;
    update();
}

void Tile::removeHilight()
{

    curColor = mainColor;
    update();
}

void Tile::selected(bool is)
{
    if(is)
        isSelected_ = true;
    else{
        isSelected_ = false;

    }
}

void Tile::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    QGraphicsRectItem::hoverEnterEvent(event);
    if(curColor != incorrectColor)
    curColor = secondaryColor;
    update();
}

void Tile::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    QGraphicsRectItem::hoverLeaveEvent(event);
    if(curColor != incorrectColor)
    if(!isSelected_)
        curColor = mainColor;
    update();
}

void Tile::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mousePressEvent(event);
    setSelected(!isSelected());


    update();
    emit tileClicked(this);
}
