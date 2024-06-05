#ifndef FIELD_H
#define FIELD_H
#include "QObject"
#include "object.h"
#include "QTimer"
#include "settings.h"

class Object;

class Field: public QObject
{
    Q_OBJECT
public:
    Field(int width, int height);
    Object ***getField();
    Type getType(Coord& cord);
    Type getType(const Coord& cord);
    void setType(Coord& cord, Type type);
    void setSavedGenoms(QVector<QVector<int>> &genoms);
    const QVector<QVector<int>>&getSavedGenoms();

    void newPopulation();
    void bornPopulation();

    void newField();
    void refresh();
    void start();
    void stop();
    void pause();
    void changeSpeedTimer(int value);

    void swapObject(const Coord& old_cord, const Coord& new_cord);
    void kill(const Coord &cord);
    Object*& at(const Coord& cord);
    void clearMap();

    void cellCountMinus();
    void cellCountPlus();
    void foodCountMinus();
    void foodCountPlus();
    void poisonCountMinus();
    void poisonCountPlus();



private:
    QVector<QVector<int>> _saved_genoms;
    Object ***grid;
    QTimer *timer;
    int timer_speed{};

    void changeField();
    void killAllCells();
    void saveGenoms();
    int getCellCount();
    void generateWall(int length);
    void generateMap();

    int _cell_count{};
    int _food_count;
    int _poison_count;

    int _width;
    int _height;

    int _time_live{};
    int _population_number{};

signals:
    void signalChangeField(Object ***grid);
    void signalTimeLive(int value);
    void signalSaveGenoms(QVector<QVector<int>> &saved_genoms);

};

#endif // FIELD_H
