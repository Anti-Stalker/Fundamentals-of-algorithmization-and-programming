#pragma once

#include "../Cell/cell.h"
#include "../Player/player.h"
#include "../Enemy/enemy.h"
#include "../Powerup/basePowerup.h"

#include <QStack>
#include <QTimer>
#include <QKeyEvent>
#include <qcontainerfwd.h>
#include <qpainterpath.h>
#include <qpixmap.h>
#include <qsize.h>

class Powerup;
class Player;

enum Completion { Quit, Lost, Won };

class Maze : public QObject {
    Q_OBJECT
public:
    Maze(int w, int h, QGraphicsScene *scene);
    ~Maze();

    bool movePlayer(Direction direction);

    static QSize size;
private:
    void moveEnemy(Enemy *enemy);
    void moveEnemyToPlayer(Enemy *enemy);
    void checkEnemies();
    void generateCoins();
    void generateEnemies();
    void generatePowerups();
    bool checkCollision();
    void checkPowerups();

    int size_x;
    int size_y;
    int score = 0;

    QGraphicsScene *scene;
    QVector<Enemy*> enemies;
    QVector<Powerup*> powerups;

    Cell ***grid;
    Cell *current = nullptr;
    Cell *next = nullptr;
    Cell *first = nullptr;
    Cell *last = nullptr;

    Player *player;

signals:
    void levelComplete();
    void finishedSearch();
    int scoreUpdated(int score);

};