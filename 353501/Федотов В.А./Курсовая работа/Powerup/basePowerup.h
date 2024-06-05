#pragma once

#include "../Player/player.h"
#include "../Maze/maze.h"
#include <QPixmap>
#include <QGraphicsScene>
#include <qpixmap.h>

class Player;
class Maze;

class Powerup {
public:
    enum Type { Teleport, Invisible, NumberOfTypes };

    static Powerup* newInstance(int size, QGraphicsScene *scene, int x, int y, Type type);

    virtual void use() {};
    
    int get_x() { return pos_x; }
    int get_y() { return pos_y; }
    Type getType() { return type; }
    Powerup *pickUp();
    QPixmap *getImage() { return image; }

    static QPixmap *imageTeleport;
    static QPixmap *imageInvisibility;


protected:
    bool taken = false;

    QGraphicsScene *scene;
    Type type = Teleport;
    QGraphicsPixmapItem *body;
    QPixmap *image;

    int pos_x;
    int pos_y;

};