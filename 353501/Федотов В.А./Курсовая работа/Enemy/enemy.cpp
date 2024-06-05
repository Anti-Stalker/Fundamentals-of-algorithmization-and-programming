#include "enemy.h"

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <cstdlib>
#include <qbrush.h>
#include <qcolor.h>
#include <qcontainerfwd.h>
#include <qnamespace.h>
#include <qtimer.h>
#include <qtmetamacros.h>

QPixmap *Enemy::image;

Enemy::Enemy(double size, QGraphicsScene *scene, int x, int y) {
    this->scene = scene;
    this->size = size;

    pos_x = x;
    pos_y = y;    

    body = new QGraphicsPixmapItem(*Enemy::image); 
    body->setPos(x * size, y * size);
    body->setScale((float)size / body->boundingRect().width());
    body->setZValue(-1000);
    body->setVisible(true);

    idleTimer = new QTimer();
    chaseTimer = new QTimer();
    setIdle();

    scene->addItem(body);
}

Enemy::~Enemy(){
    scene->removeItem(body);
    delete body;
    delete idleTimer;
}

void Enemy::move() {
    emit moveEnemy(this);
}

void Enemy::moveToPlayer() { 
    emit moveEnemyToPlayer(this);
}

void Enemy::setEnemyPos(int x, int y) {
    int dx = x - pos_x; 
    int dy = y - pos_y; 
    pos_x = x;
    pos_y = y;

    // if (dx < 0) {
    //     body->setPixmap(*image);
    // } else if (dx > 0){
    //     body->setPixmap(*rightimage);
    // }

    body->moveBy(dx * size, dy * size);
}

void Enemy::setTriggered() { 
    if (mode == Triggered || mode == Tired) 
        return;
    else 
        mode = Triggered;
    
    body->setOpacity(1); 
    connect(chaseTimer, &QTimer::timeout, this, &Enemy::moveToPlayer);
    chaseTimer->start(400);
    disconnect(idleTimer, &QTimer::timeout, this, &Enemy::move);

    QTimer::singleShot(5000, this, &Enemy::setTired);

}

void Enemy::setTired() {
    mode = Tired;
    // body->setBrush(QColor(100, 100, 100, 50));
    body->setOpacity(0.5);

    disconnect(chaseTimer, &QTimer::timeout, this, &Enemy::moveToPlayer);
    QTimer::singleShot(1500, this, &Enemy::setIdle);
}

void Enemy::setIdle() {
    mode = Idle;

    body->setOpacity(1);

    connect(idleTimer, &QTimer::timeout, this, &Enemy::move);
    idleTimer->start(std::rand() % 600 + 900);
}

int Enemy::get_x() { return pos_x; }
int Enemy::get_y() { return pos_y; }