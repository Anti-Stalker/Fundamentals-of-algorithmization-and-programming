#include "field.h"
#include "algorithm"
#include "QDebug"
#include "cell.h"

Field::Field(int width, int height) : _width(width), _height(height), _food_count(0),
    _poison_count(0)
{
    grid = new Object** [width];
    for (int i = 0; i < width; i++) {
        grid[i] = new Object*[height];
    }
    for (int i = 0; i < _width; ++i) {
        for (int j = 0; j < _height; ++j) {
            if (i == 0 || i == (_width - 1) || j == 0 || (j == _height -1)) {
                grid[i][j] = new Object(this, Type::WALL);
            }
            else {
                grid[i][j] = new Object(this, Type::VOID);
            }
        }
    }

    generateMap();

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Field::changeField);
}



Object ***Field::getField()
{
    return grid;
}



void Field::changeField()
{
    refresh();
    for (int i = 0; i < _width; i++) {
        for (int j = 0; j < _height; j++) {
            if (grid[i][j]->getHP() <= 0) {
                kill(Coord(i,j));
            }
            if (_cell_count == Settings::MIN_POPULATIONS_SIZE) {
                saveGenoms();
                clearMap();
                bornPopulation();
                refresh();
                emit signalTimeLive(_time_live);
                _population_number++;
                _time_live=0;
            }
            else if (getType(Coord(i, j)) == Type::CELL) {
                grid[i][j]->Action();
            }
        }
    }
    _time_live++;
    emit signalChangeField(grid);
}

void Field::killAllCells()
{
    for (int i = 0; i < _width; ++i) {
        for (int j = 0; j < _height; ++j) {
            if (grid[i][j]->getType() == Type::CELL) {
                kill(Coord(i, j));
            }
        }
    }
}

void Field::newPopulation()
{
    killAllCells();
    _cell_count = 0;
    _saved_genoms.clear();
    while (_cell_count < START_POPULATION_SIZE) {
        Coord cord = Coord::getRandCord(_width, _height);
        if (getType(cord) == Type::VOID) {
            delete at(cord);
            at(cord) = new Cell(this, cord);
            _cell_count++;
        }
    }

}

void Field::bornPopulation()
{
    killAllCells();
    _cell_count = 0;
    while (_cell_count < START_POPULATION_SIZE) {
        for (int i = 0; i < _saved_genoms.size(); i++) {
            Coord cord = Coord::getRandCord(_width, _height);
            if (getType(cord) == Type::VOID) {
                delete at(cord);
                at(cord) = new Cell(this, cord, _saved_genoms[i]);
                _cell_count++;
                if (i == 0) {
                    Cell *cell = reinterpret_cast<Cell*>(at(cord));
                    cell->Mutation();
                }
            }
        }
    }
}

int Field::getCellCount()
{
    int res = 0;
    for (int i = 0; i < _width; i++) {
        for (int j = 0; j < _height; j++) {
            if (grid[i][j]->getType() == Type::CELL) {
                res++;
            }
        }
    }
    return res;
}

void Field::saveGenoms()
{
    _saved_genoms.clear();
    for (int i = 0; i < _width; i++) {
        for (int j = 0; j < _height; j++) {
            if (grid[i][j]->getType() == Type::CELL) {
                Cell *cell = reinterpret_cast<Cell*>(grid[i][j]);
                _saved_genoms.push_back(cell->getGenome());
            }
        }
    }
    emit signalSaveGenoms(_saved_genoms);
}

void Field::changeSpeedTimer(int value)
{
    timer_speed = 99 - value;
    start();
}

void Field::generateWall(int length)
{
    Coord last_cord = Coord::getRandCord(_width, _height);
    Coord plus_cord;
    const Coord directions[] = {
        Coord(1, 0),
        Coord(0, 1),
        Coord(0, -1),
        Coord(-1, 0)
    };

    for (int i = 0; i < length; i++) {

        int choice = QRandomGenerator::global()->bounded(4);
        plus_cord = directions[choice];
        last_cord = last_cord+plus_cord;
        if (last_cord.in(0, 0, _width, _height)) {
            if (at(last_cord)->getType() != Type::WALL) {
                setType(last_cord, Type::WALL);
            }
        }
    }
}

void Field::generateMap()
{
    for (int i = 1; i < _width-1; i++) {
        for (int j = 1; j < _height-1; j++) {
            if (grid[i][j]->getType() == Type::CELL) {
                _cell_count--;
                kill(Coord(i,j));
            }
            else {
                grid[i][j]->setType(Type::VOID);
            }
        }
    }

    for (int i = 0; i < Settings::COUNT_WALLS; i++) {
        int dl = Settings::MAX_WALL_SIZE-Settings::MIN_WALL_SIZE;
        dl = (dl>0)?dl:1;
        generateWall(Settings::MIN_WALL_SIZE+QRandomGenerator::global()->bounded(dl));
    }

    for (int i = 1; i < _width-1; i++) {
        for (int j = 1; j < _height-1; j++) {
            int count = 0;
            count += (grid[i-1][j]->getType() == Type::WALL);
            count += (grid[i+1][j]->getType() == Type::WALL);
            count += (grid[i][j-1]->getType() == Type::WALL);
            count += (grid[i][j+1]->getType() == Type::WALL);
            if (count >= 3) {
                grid[i][j]->setType(Type::WALL);
            }
        }
    }
    _cell_count = 0;
    _food_count = 0;
    _poison_count = 0;
    refresh();
}

Type Field::getType(Coord &cord)
{
    return grid[cord.getX()][cord.getY()]->getType();
}

Type Field::getType(const Coord &cord)
{
    return grid[cord.getX()][cord.getY()]->getType();
}

void Field::setType(Coord &cord, Type type)
{
    if (grid[cord.getX()][cord.getY()]->getType() != Type::CELL) {
        grid[cord.getX()][cord.getY()]->setType(type);
    }
}

void Field::setSavedGenoms(QVector<QVector<int> > &genoms)
{
    if (genoms.size() > 0) {
        Settings::MIN_POPULATIONS_SIZE = genoms.size();
        Settings::GENOME_SIZE = genoms[0].size();
        _saved_genoms = genoms;
    }
}

const QVector<QVector<int>> &Field::getSavedGenoms()
{
    return _saved_genoms;
}

void Field::newField()
{
    stop();
    generateMap();
    start();
}


void Field::start()
{
    timer->stop();
    timer->start(timer_speed);
}

void Field::stop()
{
    timer->stop();
}

void Field::pause()
{
    if (timer->isActive()) {
        stop();
    }
    else {
        start();
    }
}


void Field::swapObject(const Coord &old_cord, const Coord &new_cord)
{
    std::swap(at(old_cord), at(new_cord));
}


void Field::kill(const Coord &cord)
{

    if (getType(cord) == Type::CELL) {
        _cell_count--;
    }
    delete at(cord);
    at(cord) = new Object(this, Type::VOID);
}

Object *&Field::at(const Coord &cord)
{
    return grid[cord.getX()][cord.getY()];
}

void Field::clearMap()
{
    killAllCells();
    for (int i = 0; i < _width; ++i) {
        for (int j = 0; j < _height; ++j) {
            if (grid[i][j]->getType() != WALL) {
                grid[i][j]->setType(Type::VOID);
            }
        }
    }
    _cell_count = 0;
    _food_count = 0;
    _poison_count = 0;
}

void Field::cellCountMinus()
{
    _cell_count--;
}

void Field::cellCountPlus()
{
    _cell_count++;
}

void Field::foodCountMinus()
{
    _food_count--;
}

void Field::foodCountPlus()
{
    _food_count++;
}

void Field::poisonCountMinus()
{
    _poison_count--;
}

void Field::poisonCountPlus()
{
    _poison_count++;
}



void Field::refresh()
{
    while (_food_count < Settings::MAX_FOOD) {
        Coord cord = Coord::getRandCord(_width, _height);
        if (getType(cord) == Type::VOID) {
            at(cord)->setType(Type::FOOD);
            _food_count++;
        }
    }
    while (_poison_count < Settings::MAX_POISON) {
        Coord cord = Coord::getRandCord(_width, _height);
        if (getType(cord) == Type::VOID) {
            at(cord)->setType(Type::POISON);
            _poison_count++;
        }
    }
}
