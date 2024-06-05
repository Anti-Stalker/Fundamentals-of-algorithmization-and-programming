#include "powerupTeleport.h"
#include "basePowerup.h"
#include <cstdlib>
#include <qgraphicsitem.h>

PowerupTeleport::PowerupTeleport(int size, QGraphicsScene *scene, int x, int y) {
    this->scene = scene;

    pos_x = x;
    pos_y = y;

    image = PowerupTeleport::imageTeleport;
    body = new QGraphicsPixmapItem(*image);
    
    body->setPos(x * size, y * size);
    body->setScale((float)size / body->boundingRect().width());
    body->setZValue(-1000);
    body->setVisible(true);

    scene->addItem(body);
}

void PowerupTeleport::use() {
    Player *player = Player::getInstance();

    player->setPlayerPos(rand() % Maze::size.width(), rand() % Maze::size.height());
}