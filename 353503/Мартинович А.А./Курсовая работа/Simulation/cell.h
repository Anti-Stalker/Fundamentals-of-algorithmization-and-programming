#ifndef CELL_H
#define CELL_H

#include "object.h"
#include <QObject>
#include "QRandomGenerator"
#include "direction.h"

class Cell : public Object
{
public:
    Cell(Field *field, Coord cord);
    Cell(Field *field, Coord cord, QVector<int> &genome);
    void Mutation();
    void Move(Coord dif_cord);
    void Rotate(int gen);
    void Eat(Coord dif_cord);
    void See(Coord dif_cord);
    void MoveCurrentGen(int gen);

    void Action() override;

    void MoveCurrentGen(Type type);
    QVector<int>& getGenome();

    QColor getColor() override;
    Type getType() override;



private:
    int _current_gen;
    int _rotation;
    QVector<int> _genome;
};



#endif // CELL_H
