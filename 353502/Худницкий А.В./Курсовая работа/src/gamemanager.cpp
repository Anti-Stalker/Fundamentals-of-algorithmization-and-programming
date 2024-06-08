#include "gamemanager.h"
#include "const.h"

GameManager::GameManager(QWidget *parent) : QWidget(parent), m_level(60, 30) {
    createLevel();
    setupUI();
    displayLevel();
}

void GameManager::createLevel() {
    m_level = LevelGenerator(GLOBAL_WIDTH, GLOBAL_HEIGHT);
}

void GameManager::setupUI() {
    m_layout = new QGridLayout(this);

    for (int y = 0; y < m_level.getHeight(); ++y) {
        for (int x = 0; x < m_level.getWidth(); ++x) {
            TileWidget *tileWidget = new TileWidget(this);
            tileWidget->setType(m_level.getTileType(x, y));
            m_layout->addWidget(tileWidget, y, x);
        }
    }

    setLayout(m_layout);
}


void GameManager::displayLevel() {
    show();
}
