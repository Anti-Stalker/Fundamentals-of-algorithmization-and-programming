#ifndef NODE_H
#define NODE_H

#include <QString>

class Node
{
public:
    int key;
    QString fullName;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int key, QString fullName)
    {
        this->key = key;
        this->fullName = fullName;
    }
};
#endif // NODE_H
