#pragma once

#include "../Cell/cell.h"
#include <qcontainerfwd.h>

class DFS {
public:
    static QVector<Cell*> pathfindAndReturnPath(Cell*** grid, Cell *start, Cell *target, int w, int h);
    static QVector<Cell*> generateAndReturnVector(Cell ***grid, int w, int h );
    static void generate(Cell ***grid, int w, int h );
    static QVector<Cell*> getPathfindNeighbors(Cell ***grid, int w, int h, Cell* current);
private:
    static void removeWalls(Cell *current, Cell *next);
    static Cell *getFreeNeighbor(Cell ***grid, int w, int h, Cell *current);
};