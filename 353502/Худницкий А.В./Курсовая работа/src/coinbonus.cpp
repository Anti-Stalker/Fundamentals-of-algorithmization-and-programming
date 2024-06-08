#include "character.h"
#include "coinbonus.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include "const.h"

CoinBonus::CoinBonus(LevelGenerator *level, int x, int y, QWidget *parent)
    : QWidget(parent), m_level(level), m_x(x), m_y(y) {
    setFixedSize(SIZE_X, SIZE_Y);
}

void CoinBonus::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::blue);
}

void CoinBonus::mousePressEvent(QMouseEvent *event, Character* character) {
    if (m_level && m_level->getTileType(m_x, m_y) == TileType::BonusCoin) {

        character->setCoinsCollected(character->getCoinsCollected() + 2);
        multiply(2);

        deleteLater();
    }
}
