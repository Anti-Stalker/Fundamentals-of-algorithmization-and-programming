#include "coord.h"


Coord::Coord()
= default;

Coord::Coord(int x, int y) : _x(x), _y(y)
{
}

Coord &Coord::operator=(const Coord &coord)
{
    if (this == &coord) {
            return *this;
    }
    _x = coord._x;
    _y = coord._y;
    return *this;
}

int Coord::getX() const
{
    return _x;
}

int Coord::getY() const
{
    return _y;
}

bool Coord::in(int x, int y, int width, int height)
{
    return (_x > x && _x < (x+width) && _y > y && _y < (y+height));
}

Coord Coord::getRandCord(int x_max, int y_max)
{
    return Coord(QRandomGenerator::global()->bounded(x_max), QRandomGenerator::global()->bounded(y_max));
}

Coord Coord::operator+(const Coord &other) {
    return {_x+other._x,_y+other._y};
}
