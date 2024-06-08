#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QVector>
#include "stack.h"

class HashTable {
public:
    int n;
    QVector<Stack> table;
    int hashFunction(int key);
    HashTable(int V);
    void insertItem(int key, int data);
    void deleteItem(int key);
    QVector<QVector<int>> displayHash();
    void clear();
};

#endif // HASHTABLE_H
