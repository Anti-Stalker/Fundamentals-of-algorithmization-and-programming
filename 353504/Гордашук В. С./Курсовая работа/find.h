#ifndef FIND_H
#define FIND_H
#include <QtMath>
#include <vector>
#include <queue>
#include <algorithm>

class Find
{
public:
    Find();

    struct Node {
        int x, y;
        int g;
        int h;
        Node* parent;

        Node(int x, int y, int g, int h, Node* parent) : x(x), y(y), g(g), h(h), parent(parent) {}

        int f() const {
            return g + h;
        }
    };

    struct CompareNode {
        bool operator()(const Node* a, const Node* b)
        {
            return a->f() > b->f();
        }
    };

    bool isValid(int x, int y, int rows, int cols)
    {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    int heuristic(int x, int y, int dest_x, int dest_y)
    {
        return abs(x - dest_x) + abs(y - dest_y);
    }

    std::vector<std::pair<int, int>> aStar(int **a, int start_x, int start_y, int dest_x, int dest_y);
};

#endif // FIND_H
