#ifndef LAB8TASK2_LISTBH_H
#define LAB8TASK2_LISTBH_H

#include <cmath>
#include <algorithm>

#include "BinaryHeap.h"

class ListBH : public BinaryHeap {
public:
    ListBH() = default;
    ListBH(int *array, int size);
    void add(int num);
    void normalize() override;
    void print();

private:
    struct Node {
        int value;
        Node *left;
        Node *right;
        Node(int val) : value(val), left(nullptr), right(nullptr) {}

        friend class ListBH;
    };

    Node *root;

    void compare(Node *node);
    void normalize(Node *node);
};

#endif //LAB8TASK2_LISTBH_H
