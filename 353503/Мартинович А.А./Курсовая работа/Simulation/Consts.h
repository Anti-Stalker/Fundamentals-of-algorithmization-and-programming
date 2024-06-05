#ifndef CONSTS_H
#define CONSTS_H

const int CELL_SIZE = 10;
const int COLOR_MAX = 256;
const int WIDNOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;
const int GRAPH_SCENE_WIDTH = 600;
const int GRAPH_SCENE_HEIGHT = 350;
const int DIRECT_NUMBER = 8;
const int MAX_ACTION_COUNT = 10;
const bool IS_BORDER = true;
const int GRAPH_SMOOTH = 10;
const int GEN_COUNT = 64;
const int START_POPULATION_SIZE = 64;

enum Type {
    CELL,
    VOID,
    WALL,
    POISON,
    FOOD
};

#endif // CONSTS_H
