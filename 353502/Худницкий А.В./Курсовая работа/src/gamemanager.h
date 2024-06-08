#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QWidget>
#include <QGridLayout>
#include "levelgenerator.h"
#include "TileWidget.h"

class GameManager : public QWidget {
    Q_OBJECT

public:
    explicit GameManager(QWidget *parent = nullptr);

private:
    LevelGenerator m_level;
    QGridLayout *m_layout;

    void createLevel();
    void setupUI();
    void displayLevel();
};

#endif // GAMEMANAGER_H
