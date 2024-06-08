#include "coin.h"
#include "const.h"
#include "character.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

Coin::Coin(LevelGenerator *level, int x, int y, QWidget *parent)
    : QWidget(parent), m_level(level), m_x(x), m_y(y) {
    setFixedSize(SIZE_X, SIZE_Y);
}

void Coin::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::yellow);
}

