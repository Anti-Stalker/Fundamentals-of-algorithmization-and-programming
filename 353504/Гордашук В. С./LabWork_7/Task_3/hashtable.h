#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QVector>
#include "mystack.h"

class HashTable
{
public:
    HashTable(int _capacity);
    void insert(MyStack *value);
    void remove(int index);
    struct Node
    {
        int key;
        MyStack *value;
        Node *child = nullptr;
    };
    QVector<Node*> table;
    int capacity;
    int hash(int key);
};

#endif // HASHTABLE_H
