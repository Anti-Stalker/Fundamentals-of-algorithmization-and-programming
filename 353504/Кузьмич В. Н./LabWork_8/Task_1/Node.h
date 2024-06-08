#ifndef NODE_H
#define NODE_H
#include <QString>

class Node
{
public:
    int key;
    QString str;
    Node* left;
    Node* right;
    Node(int k, QString stri){
        str = stri;
        key = k;
        left = nullptr;
        right = nullptr;
    };
};
#endif // NODE_H
