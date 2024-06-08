#include "TileWidget.h"
#include <QPainter>

TileWidget::TileWidget(QWidget *parent) : QWidget(parent), m_type(TileType::Empty) {}

void TileWidget::setType(TileType type) {
    m_type = type;
    update();
}

void TileWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int cellSize = qMin(width(), height());

    switch (m_type) {
    case TileType::Wall:
        painter.fillRect(rect(), Qt::black);
        break;
    case TileType::Coin:
        painter.fillRect(rect(), Qt::yellow);
        break;
    case TileType::BonusShield:
        painter.fillRect(rect(), Qt::blue);
        break;
    case TileType::BonusFreeze:
        painter.fillRect(rect(), Qt::cyan);
        break;
    case TileType::BonusCoin:
        painter.fillRect(rect(), Qt::green);
        break;
    case TileType::Enemy:
        painter.fillRect(rect(), Qt::red);
        break;
    case TileType::Empty:
        painter.fillRect(rect(), Qt::white);
        break;
    case TileType::Character:
        painter.fillRect(rect(), Qt::gray);
        break;
    case TileType::Goal:
        painter.fillRect(rect(), Qt::darkGreen);
        break;
    }


    painter.setPen(Qt::black);
    painter.drawRect(0, 0, cellSize - 1, cellSize - 1);
}
