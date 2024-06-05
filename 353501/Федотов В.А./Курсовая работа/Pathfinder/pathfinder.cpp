#include "pathfinder.h"

#include <qcontainerfwd.h>
#include <qdebug.h>
#include <qlogging.h>
#include <qstack.h>

QVector<Cell *> DFS::generateAndReturnVector(Cell ***grid, int w, int h) {
    QVector<Cell *> path;
    QStack<Cell *> stack;
    Cell *current = nullptr;

    current = grid[0][0];
    current->setFound(true);
    stack.push(current);
    path.append(current);

    while (!stack.isEmpty()) {
        Cell *next = getFreeNeighbor(grid, w, h, current);
        if (next != nullptr) {
            stack.push(next);
            next->setFound(true);
            path.append(next);
            current = next;
        } else {
            current = stack.pop();
            path.append(current);
        }
    }

    //setting all cells to unfound
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            grid[i][j]->setFound(false);
        }
    }

    return path;
}

void DFS::generate(Cell ***grid, int w, int h) {
    QStack<Cell *> stack;
    Cell *current = nullptr;

    current = grid[0][0];
    current->setFound(true);
    stack.push(current);

    while (!stack.isEmpty()) {
        Cell *next = getFreeNeighbor(grid, w, h, current);
        if (next != nullptr) {
            stack.push(next);
            next->setFound(true);
            removeWalls(current, next);
            current = next;
        } else {
            current = stack.pop();
        }
    }

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            grid[i][j]->setFound(false);
        }
    }
}

QVector<Cell*> DFS::pathfindAndReturnPath(Cell*** grid, Cell *start, Cell *target, int w, int h){
    QVector<Cell*> path;
    QStack<Cell*> stack;
    stack.clear();
    Cell* current = nullptr;

    current = start;
    // current->setFound(true);
    stack.push(current);

    while (!stack.isEmpty()) {
        QVector<Cell *> neighbors = getPathfindNeighbors(grid, w, h, current);
        int numNeighbors = neighbors.length();
        Cell* next = nullptr;

        if (numNeighbors != 0) {
            next = neighbors[rand() % numNeighbors];
        }
        
        if (next != nullptr) {
            stack.push(next);
            next->setFound(true);
            current = next;
        } else {
            stack.pop();
            current = stack.top();
            // current = stack.pop();
        }

        if (current == target) {
            qDebug() << stack.size();
            while (!stack.isEmpty()) {
                stack.top()->setFound(false);
                // stack.top()->highlight(Color::Gray);
                path.append(stack.pop());
            }
            // path.append(current);
            for (int i = 0; i < w; i++) {
                for (int j = 0; j < h; j++) {
                    grid[i][j]->setFound(false);
                }
            }
            return path;
        }
    }

    return QVector<Cell*>();
}

void DFS::removeWalls(Cell* current, Cell* next) {
    int cx, cy, nx, ny;
    cx = current->get_x();
    cy = current->get_y();
    nx = next->get_x();
    ny = next->get_y();

    if (nx > cx) {
        current->removeWall(Direction::Right);
        next->removeWall(Direction::Left);
    } else if (nx < cx) {
        current->removeWall(Direction::Left);
        next->removeWall(Direction::Right);
    } else if (ny > cy) {
        current->removeWall(Direction::Down);
        next->removeWall(Direction::Up);
    } else if (ny < cy) {
        current->removeWall(Direction::Up);
        next->removeWall(Direction::Down);
    }
}

Cell* DFS::getFreeNeighbor(Cell ***grid, int w, int h, Cell* current) {
    QList<Cell*> freeNeighbors;

    int x, y;
    x = current->get_x();
    y = current->get_y();

    if (x > 0 && !grid[x - 1][y]->isFound())      //left
        freeNeighbors.push_back(grid[x - 1][y]);
  
    if (x < w - 1 && !grid[x + 1][y]->isFound())     //right
        freeNeighbors.push_back(grid[x + 1][y]);

    if (y > 0 && !grid[x][y - 1]->isFound())      //up
        freeNeighbors.push_back(grid[x][y - 1]);
  
    if (y < h - 1 && !grid[x][y + 1]->isFound()) //down
        freeNeighbors.push_back(grid[x][y + 1]);
  
    int len = freeNeighbors.size();
    if (len != 0) 
        return freeNeighbors[rand() % len];

    return nullptr;
}

QVector<Cell*> DFS::getPathfindNeighbors(Cell*** grid, int w, int h, Cell* current) {
    QVector<Cell*> freeNeighbors;

    int x = current->get_x();
    int y = current->get_y();

    if (x > 0 && !grid[x - 1][y]->isFound() && current->isDirAvailable(Left))      // left
        freeNeighbors.push_back(grid[x - 1][y]);

    if (x < w - 1 && !grid[x + 1][y]->isFound() && current->isDirAvailable(Right))     // right
        freeNeighbors.push_back(grid[x + 1][y]);

    if (y > 0 && !grid[x][y - 1]->isFound() && current->isDirAvailable(Up))      // up
        freeNeighbors.push_back(grid[x][y - 1]);

    if (y < h - 1 && !grid[x][y + 1]->isFound() && current->isDirAvailable(Down)) // down
        freeNeighbors.push_back(grid[x][y + 1]);

    return freeNeighbors;
}