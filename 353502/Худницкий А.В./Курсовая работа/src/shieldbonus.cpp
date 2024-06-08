#include "shieldbonus.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include "character.h"
#include "const.h"

ShieldBonus::ShieldBonus(LevelGenerator *level, int x, int y, QWidget *parent)
    : QWidget(parent), m_level(level), m_x(x), m_y(y) {
    setFixedSize(SIZE_X, SIZE_Y);
}

void ShieldBonus::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::green);
}

void ShieldBonus::mousePressEvent(QMouseEvent *event, Character* character) {
    if (m_level && m_level->getTileType(m_x, m_y) == TileType::BonusShield) {

        int newHealth = (character->getHealth());
        character->setHealth(newHealth);

        emit healthIncreased(newHealth);

        deleteLater();
    }
}
