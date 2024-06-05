#include "powerupInvisible.h"
#include "basePowerup.h"
#include "powerupInvisible.h"
#include <cstdlib>
#include <qgraphicsitem.h>
#include <qtimer.h>

PowerupInvisible::PowerupInvisible(int size, QGraphicsScene *scene, int x, int y) {
    this->scene = scene;

    pos_x = x;
    pos_y = y;

    image = PowerupInvisible::imageInvisibility;
    body = new QGraphicsPixmapItem(*image);
    
    body->setPos(x * size, y * size);
    body->setScale((float)size / body->boundingRect().width());
    body->setZValue(-1000);
    body->setVisible(true);

    scene->addItem(body);
}

void PowerupInvisible::use() {
    Player *player = Player::getInstance();

    player->setInvisible(true);
}