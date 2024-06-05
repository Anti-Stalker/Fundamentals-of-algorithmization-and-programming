#include "player.h"

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <qbrush.h>
#include <qcolor.h>
#include <qgraphicsitem.h>
#include <qnamespace.h>
#include <qpoint.h>
#include <qtmetamacros.h>

QPixmap *Player::defaultFace;
QPixmap *Player::invisibleFace;
Player *Player::instance;

Player::Player(double size, QGraphicsScene* scene) {
    this->scene = scene;
    this->size = size;
    this->defaultFace = defaultFace;
    instance = this;

    powerups.reserve(Powerup::NumberOfTypes);

    pos_x = 0;
    pos_y = 0;    

    body = new QGraphicsPixmapItem(*defaultFace); 
    body->setPos(pos_x * size, pos_y * size);
    body->setScale((float)size / body->boundingRect().width());
    body->setVisible(true);

    scene->addItem(body);
}

Player::~Player(){
    scene->removeItem(body);
    delete body;
}

void Player::setPlayerPos(int x, int y) {
    int dx = x - pos_x; 
    int dy = y - pos_y; 
    pos_x = x;
    pos_y = y;

    body->moveBy(dx * size, dy * size);
    emit playerMoved(QPointF(dx * size, dy * size));
}

void Player::addPowerup(Powerup *powerup) { 
    powerups.append(powerup); 
    emit powerupAdded(powerup);
};

void Player::usePowerup(int index) {
    if (index >= powerups.size()) 
        return;
    
    if (powerups.at(index) == nullptr)
        return;

    powerups.at(index)->use();
    delete powerups.at(index);
    powerups.erase(powerups.begin() + index);
    emit powerupUsed(index);
}

void Player::setInvisible(bool invisible) {
    if (!invisible) {
        body->setPixmap(*defaultFace);
    } else {
        body ->setPixmap(*invisibleFace);
        QTimer::singleShot(2000, [this]() { setInvisible(false); });
    }

    this->invisible = invisible;
}

int Player::get_x() { return pos_x; }
int Player::get_y() { return pos_y; }