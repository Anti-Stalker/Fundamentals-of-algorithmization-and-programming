#ifndef NODE_H
#define NODE_H
#include <QString>
struct Node
{
    QString val;
    int key;
    Node *right=nullptr;
    Node *left=nullptr;
    int h=1;
};
#endif // NODE_H
