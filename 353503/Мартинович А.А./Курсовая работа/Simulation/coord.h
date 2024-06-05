#ifndef COORD_H
#define COORD_H
#include "QRandomGenerator"

class Coord
{
public:
    Coord();
    Coord(int x, int y);
    Coord& operator=(const Coord& coord);
    int getX() const;
    int getY() const;
    bool in(int x, int y, int width, int height);
    static Coord getRandCord(int x_max, int y_max);
    Coord operator+(const Coord& other);
private:
    int _x{0};
    int _y{0};
};

#endif // COORD_H
