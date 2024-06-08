#ifndef POINT_H
#define POINT_H
class Point {
public:
    int x;
    int y;

    Point() : x(0), y(0) {}  // Конструктор по умолчанию

    Point(int xVal, int yVal) : x(xVal), y(yVal) {}  // Конструктор с аргументами

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

#endif // POINT_H
