#ifndef LEVELCREATER_H
#define LEVELCREATER_H

#include "datahub.h"

#include <QMainWindow>
class CombatZone;
class LevelManager;

class LevelCoordinator : public QMainWindow
{
    Q_OBJECT

private:
    int playerGenerate;
    int enemyGenerate;
    int mapSize;
    int ObstacleType;
    const levelData::dataPack *PackageUsed;
    LevelManager *currentLevel;
    void CreateLevel();

public:
    LevelCoordinator(QMainWindow *parent = 0);
    ~LevelCoordinator();

signals:
    void GameStart(LevelManager*);
    void backToMenu();

public slots:
    void BulidLevelSelected(int i);
};

#endif
