#pragma once

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <qgraphicsitem.h>
#include <qpixmap.h>

enum Direction { Up, Down, Left, Right};
enum Color { None, Red, Gray };

class Cell {
public:
    Cell(int x_, int y_, QGraphicsScene *scene_);
    ~Cell();

    static QPixmap *image;

private:
    QGraphicsLineItem *upBorder; 
    QGraphicsLineItem *downBorder; 
    QGraphicsLineItem *leftBorder; 
    QGraphicsLineItem *rightBorder;

    QGraphicsRectItem *highlightRect;
    QGraphicsPixmapItem *coin;

    QGraphicsScene *scene;

public:
    bool isVisited();
    bool isFound();
    bool isCoined();
    bool isDirAvailable(Direction direction);
    // void setVisited();
    void setFound(bool found);
    int getValue();
    void addCoin(int value);
    int removeCoin();
    int get_x();
    int get_y();
    void highlight(Color color);
    void removeWall(Direction wall);

    static int size;

private:
    // bool visited = false;
    bool found = false;
    bool walls[4] { 1, 1, 1, 1 };
    bool hasCoin = false;
    int x;
    int y;
    int value;

};
