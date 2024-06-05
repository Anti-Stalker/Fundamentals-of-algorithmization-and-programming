#include "cell.h"

#include <cstddef>
#include <qbrush.h>
#include <qcolor.h>
#include <qgraphicsitem.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <qpixmap.h>

int Cell::size = 20;
QPixmap *Cell::image = nullptr;

Cell::Cell(int x, int y, QGraphicsScene *scene) {
    found = false;
    this->scene = scene;

    this->x = x;
    this->y = y;
    x *= size; 
    y *= size;

    highlightRect = new QGraphicsRectItem(x + (float)size / 4, y + (float)size /4, (float)size/2, (float)size/2);
    highlightRect->setBrush(QBrush(Qt::NoBrush));
    highlightRect->setPen(Qt::NoPen);
    highlightRect->setZValue(-1000);

    coin = new QGraphicsPixmapItem(*Cell::image);
    coin->setPos(x , y );
    coin->setScale((float)size / coin->boundingRect().width());
    coin->setZValue(-1000);
    coin->setVisible(false);

    upBorder = new QGraphicsLineItem(x, y, x + size, y);
    downBorder = new QGraphicsLineItem(x, y + size, x + size, y + size);
    leftBorder = new QGraphicsLineItem(x, y, x, y + size);
    rightBorder = new QGraphicsLineItem(x + size, y, x + size, y + size);
    
    scene->addItem(upBorder);
    scene->addItem(downBorder);
    scene->addItem(leftBorder);
    scene->addItem(rightBorder);
    scene->addItem(highlightRect);
    scene->addItem(coin);

    walls[0] = true;
    walls[1] = true;
    walls[2] = true;
    walls[3] = true;
}

Cell::~Cell(){
    scene->removeItem(upBorder);
    scene->removeItem(downBorder);
    scene->removeItem(leftBorder);
    scene->removeItem(rightBorder);
    scene->removeItem(highlightRect);
    scene->removeItem(coin);

    delete upBorder;
    delete downBorder;
    delete leftBorder;
    delete rightBorder;
    delete highlightRect;
}

// bool Cell::isVisited() { return visited; }
bool Cell::isFound() { return found; }
bool Cell::isCoined() { return hasCoin; };

bool Cell::isDirAvailable(Direction direction) { return !walls[direction]; }

// void Cell::setVisited() { visited = true; }
void Cell::setFound(bool found) { this->found = found; }

void Cell::addCoin(int value) { 
    coin->setVisible(true);
    hasCoin = true;
    this->value = value;
}

int Cell::removeCoin() { 
    coin->setVisible(false);
    hasCoin = false;
    return value;
}

int Cell::getValue() { return value; };

int Cell::get_x(){ return x; }
int Cell::get_y(){ return y; }

void Cell::highlight(Color color) {
    switch (color) {
    case None:
        highlightRect->setBrush(Qt::NoBrush);
        break;
    case Red:
        highlightRect->setBrush(QBrush(QColor(255, 0, 0)));
        break;
    case Gray:
        highlightRect->setBrush(QBrush(QColor(200, 200, 200)));
        break;
      break;
    }
}

void Cell::removeWall(Direction wall) {
    // qDebug() << wall;
    switch (wall) {

    case Up:
        // scene->removeItem(upBorder);
        upBorder->hide();
        walls[wall] = false;
        break;

    case Down:
        // scene->removeItem(downBorder);
        downBorder->hide();
        walls[wall] = false;
        break;

    case Left:
        // scene->removeItem(leftBorder);
        leftBorder->hide();
        walls[wall] = false;
        break;

    case Right:
        // scene->removeItem(rightBorder);
        rightBorder->hide();
        walls[wall] = false;
        break;

    default:
        break;
    }
}

