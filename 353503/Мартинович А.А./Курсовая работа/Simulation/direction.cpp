#include "direction.h"


const Coord Direction::getDirect(int value)
{
    value = value % DIRECT_NUMBER;
    if (value == 0) {
        return Coord(-1, -1);
    }
    if (value == 1) {
        return Coord(0, -1);
    }
    if (value == 2) {
        return Coord(1, -1);
    }
    if (value == 3) {
        return Coord(-1, 0);
    }
    if (value == 4) {
        return Coord(1, 0);
    }
    if (value == 5) {
        return Coord(-1, 1);
    }
    if (value == 6) {
        return Coord(0, 1);
    }
    else {
        return Coord(1, 1);
    }
}
