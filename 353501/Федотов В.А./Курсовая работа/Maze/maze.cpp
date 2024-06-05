#include "maze.h"

#include "../Pathfinder/pathfinder.h"

#include <cstdlib>
#include <qcontainerfwd.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <qpixmap.h>
#include <qpoint.h>
#include <qtmetamacros.h>

QSize Maze::size;

Maze::Maze(int w, int h, QGraphicsScene *scene){
    size_x = w;
    size_y = h;
    size = QSize(w, h);
    this->scene = scene;

    srand (time(NULL));

    player = new Player(Cell::size, scene);

    scene->setSceneRect(0, 0, size_x * Cell::size, size_y * Cell::size);
    scene->setBackgroundBrush(QBrush(QColor(255, 255, 255), Qt::SolidPattern));

    grid = new Cell**[size_x];
    for (int i = 0; i < size_x; i++) {
        grid[i] = new Cell*[size_y];
        for (int j = 0; j < size_y; j++) {
            grid[i][j] = new Cell(i, j, scene);
        }
    }

    first = grid[0][0];
    last = grid[size_x-1][size_y-1];
    DFS::generate(grid, w, h);

    last->removeWall(Down); //Выход

    generateCoins();
    generateEnemies();
    generatePowerups();

    scene->update();
}

Maze::~Maze(){
    delete player;

    for (int i = 0; i < enemies.size(); i++) {
        delete enemies[i];
    }
    enemies.clear();

    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            delete grid[i][j];
            grid[i][j] = nullptr;
        }
        delete[] grid[i];
        grid[i] = nullptr;
    }

    delete[] grid;
    grid = nullptr;
}

bool Maze::movePlayer(Direction direction) {
    int x = player->get_x();
    int y = player->get_y();
    // qDebug() << x << y << " " << direction;
    int newX = x;
    int newY = y;

    if (grid[x][y]->isDirAvailable(direction)) {
        switch (direction) {
        case Up:
            newY--;
            break;
        case Down:
            newY++;
            break;
        case Left:
            newX--;
            break;
        case Right:
            newX++;
            break;
        }

        if (newX == size_x-1 && newY == size_y) {
            player->setPlayerPos(newX, newY);
            emit levelComplete();
            return false;
        }

        if (grid[newX][newY]->isCoined()) {
            score += grid[newX][newY]->removeCoin();
            emit scoreUpdated(score);
            qDebug() << score;
        }

        player->setPlayerPos(newX, newY);
        checkEnemies();
        checkPowerups();
        
        if(checkCollision())
            emit levelComplete();

        return true;
    }

    return false;
}

bool Maze::checkCollision() {
    if (player->isInvisible()) {
        return false;
    }

    for (auto &enemy : enemies) {
        if (enemy->get_x() == player->get_x() && 
        enemy->get_y() == player->get_y() &&
        enemy->getMode() != Tired) {
            return true;
        }
    }

    return false;
}

void Maze::moveEnemy(Enemy *enemy) {
    int pos_x = enemy->get_x();
    int pos_y = enemy->get_y();

    Cell* next = nullptr;
    QVector<Cell*> neighbors = DFS::getPathfindNeighbors(grid, size_x, size_y, grid[pos_x][pos_y]);
    int numNeighbors = neighbors.size();

    next = neighbors[rand() % numNeighbors];

    enemy->setEnemyPos(next->get_x(), next->get_y());

    checkEnemies();

    if (checkCollision())
        emit levelComplete();
}

void Maze::moveEnemyToPlayer(Enemy *enemy) {
    int pos_x = enemy->get_x();
    int pos_y = enemy->get_y();

    Cell* next = nullptr;
    QVector<Cell*> path = DFS::pathfindAndReturnPath(grid, grid[player->get_x()][player->get_y()], grid[pos_x][pos_y], size_x, size_y);

    enemy->setEnemyPos(path.at(1)->get_x(), path.at(1)->get_y());
    if (checkCollision())
        emit levelComplete();
}

void Maze::checkEnemies() {
    if (player->isInvisible()) {
        return;
    }

    int player_x = player->get_x();
    int player_y = player->get_y();

    bool noWalls = true;
    int i = 1;
    while (noWalls) { //up
        Cell *current = grid[player_x][player_y - i + 1];
        noWalls = current->isDirAvailable(Up);
        if (noWalls) {
            for (int j = 0; j < enemies.size(); j++) {
                if (enemies[j]->get_x() == player_x && enemies[j]->get_y() == player_y - i) {
                    enemies[j]->setTriggered();
                    return;
                }
            }
        }
        i++;
    }

    i = 1;
    noWalls = true;
    while (noWalls) { //down
        Cell *current = grid[player_x][player_y + i - 1];
        if (current->get_x() == size_x - 1 && current->get_y() == size_y - 1) //break if near exit
            break;
        
        noWalls = current->isDirAvailable(Down);
        if (noWalls) {
            for (int j = 0; j < enemies.size(); j++) {
                if (enemies[j]->get_x() == player_x && enemies[j]->get_y() == player_y + i) {
                    enemies[j]->setTriggered();
                    return;
                }
            }
        }
        i++;
    }

    i = 1;
    noWalls = true;
    while (noWalls) { //left
        Cell *current = grid[player_x - i + 1][player_y];
        noWalls = current->isDirAvailable(Left);
        if (noWalls) {
            for (int j = 0; j < enemies.size(); j++) {
                if (enemies[j]->get_x() == player_x - i && enemies[j]->get_y() == player_y) {
                    enemies[j]->setTriggered();
                    return;
                }
            }
        }
        i++;
    }

    i = 1;
    noWalls = true;
    while (noWalls) { //right
        Cell *current = grid[player_x + i - 1][player_y];
        noWalls = current->isDirAvailable(Right);
        if (noWalls) {
            for (int j = 0; j < enemies.size(); j++) {
                if (enemies[j]->get_x() == player_x + i && enemies[j]->get_y() == player_y) {
                    enemies[j]->setTriggered();
                    return;
                }
            }
        }
        i++;
    }
}

void Maze::checkPowerups() {
    QPointF playerPos (player->get_x(), player->get_y());
    for (auto powerup : powerups) {
        QPointF powerupPos(powerup->get_x(), powerup->get_y());
        if (playerPos == powerupPos) {
            player->addPowerup(powerup->pickUp());
        }
    }
}

void Maze::generateCoins() {
    int numCoins = (size_x * size_y) / 15; 
    int count = numCoins;
    while (count) {
        int x = rand() % size_x;
        int y = rand() % size_y;
        
        int lengthToStart = DFS::pathfindAndReturnPath(grid, grid[0][0], grid[x][y], size_x, size_y).size();
        int lengthToFinish = DFS::pathfindAndReturnPath(grid, grid[x][y], grid[size_x-1][size_y-1], size_x, size_y).size();
        qDebug() << x << y << lengthToStart << lengthToFinish;
        grid[x][y]->addCoin(lengthToFinish + lengthToStart);
        count--;
    }
}

void Maze::generateEnemies() {
    int numEnemies = (size_x * size_y) / 100; 
    int count = numEnemies;
    while (count) {
        int x = rand() % size_x;
        int y = rand() % size_y;

        if (DFS::pathfindAndReturnPath(grid, grid[x][y], grid[0][0], size_x, size_y).size() < 10)
            continue;

        Enemy *enemy = new Enemy(Cell::size, scene, x, y);
        connect(enemy, &Enemy::moveEnemy, this, &Maze::moveEnemy);
        connect(enemy, &Enemy::moveEnemyToPlayer, this, &Maze::moveEnemyToPlayer);
        enemies.append(enemy);
        count--;
    }   
}

void Maze::generatePowerups() {
    for (int i = 0; i < Powerup::NumberOfTypes; i++) {
        int x = rand() % size_x;
        int y = rand() % size_y;

        if (grid[x][y]->isCoined()) {
            i--;
            continue;
        }

        Powerup *powerup = Powerup::newInstance(Cell::size, scene, x, y, (Powerup::Type)i);
        powerups.append(powerup);
    }   
}