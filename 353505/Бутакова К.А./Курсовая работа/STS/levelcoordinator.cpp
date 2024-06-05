#include "levelcoordinator.h"
#include "levelmanager.h"
#include "combatzone.h"
#include <QTimer>

LevelCoordinator::LevelCoordinator(QMainWindow *parent) : QMainWindow(parent)
{

}

LevelCoordinator::~LevelCoordinator()
{
}

void LevelCoordinator::BulidLevelSelected(int i)
{
    switch (i)
    {
        case 1:
        {
            PackageUsed = &levelData::level_1;
            break;
        }

        case 2:
        default:
        {
            PackageUsed = &levelData::level_2;
            break;
        }
    }

    playerGenerate = PackageUsed->PlayerNumber;
    enemyGenerate = PackageUsed->EnemyNumber;
    ObstacleType = PackageUsed->ObstacleType;
    mapSize = PackageUsed->mapSize;
    CreateLevel();
}

void LevelCoordinator::CreateLevel()
{
    currentLevel = new LevelManager;
    currentLevel->CreateBattleField(playerGenerate, enemyGenerate, mapSize, ObstacleType);
    connect(this, &LevelCoordinator::GameStart, currentLevel, &LevelManager::startLevel);
    connect(currentLevel, &LevelManager::backToMenu, this, &LevelCoordinator::backToMenu);
    QTimer::singleShot(100, this, [=](){ emit GameStart(currentLevel); });
}
