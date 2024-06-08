//
// Created by u on 31.05.24.
//

#ifndef TASK3_HASHTABLE_H
#define TASK3_HASHTABLE_H

#include "Stack.h"

class HashTable
{
protected:
    int cap = 1;
    QVector<Stack> table;

    int hashFunction(int key)
    {
        return key % cap;
    }

public:
    HashTable(int sz)
    {
        cap = sz;
        table.resize(cap);
    }

    void insertItem(int key, int data)
    {
        table[hashFunction(key)].push(data);
    }

    void deleteItem(int key)
    {
        if (!table[hashFunction(key)].isEmpty())
            table[hashFunction(key)].pop();
    }

    QVector<QVector<int>> displayHash()
    {
        QVector<QVector<int>> result;
        for (int i = 0; i < cap; i++)
            result.append(table[i].toQVector());

        return result;
    }
};

#endif //TASK3_HASHTABLE_H
