#ifndef NODE_H
#define NODE_H
#include <QString>

class Node {
public:
    int key;
    QString data;
    Node* left;
    Node* right;

    Node(int k, QString d)
        : key(k), data(d), left(nullptr), right(nullptr) {}
};
#endif // NODE_H
