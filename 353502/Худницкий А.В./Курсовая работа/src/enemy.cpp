#include "enemy.h"
#include <QPainter>
#include <QTimer>
#include "const.h"

Enemy::Enemy(LevelGenerator *level, int startX, int startY) : QWidget(), m_level(level), m_x(startX), m_y(startY), m_direction(DIRECTION_DELTA) {
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(move()));
}

void Enemy::startMoving() {
    m_timer->start(ENEMY_TIMER);
}

void Enemy::stopMoving() {
    m_timer->stop();
}

void Enemy::move() {
    int nextX = m_x + m_direction;

    if (m_level->getTileType(nextX, m_y) == TileType::Wall) {
        m_direction *= -DIRECTION_DELTA;
    } else {
        m_x += m_direction;
    }

    update();
}

void Enemy::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(Qt::red);
    painter.drawEllipse(rect());
}
