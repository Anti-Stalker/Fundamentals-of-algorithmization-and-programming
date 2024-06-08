#include "spike.h"
#include "character.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include "levelgenerator.h"
#include "const.h"

Spike::Spike(LevelGenerator *level, int x, int y, QWidget *parent)
    : QWidget(parent), m_level(level), m_x(x), m_y(y) {
    setFixedSize(SIZE_X, SIZE_Y);
}

void Spike::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::red);
}

void Spike::mousePressEvent(QMouseEvent *event, Character* character) {
    if (m_level && m_level->getTileType(m_x, m_y) == TileType::Spike) {
        int newHealth = character->getHealth() - HEALTHDECREASE;
        character->setHealth(newHealth);

        if (newHealth <= 0) {
            character->die();
        }
    }
}
