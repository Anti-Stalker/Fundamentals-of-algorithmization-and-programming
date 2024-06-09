#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Stack.h"
#include <cmath>
#include <QDebug>
class HashTable {
    int capacity = 1;
    QVector<Stack> table;
    const double A = 0.6180339887;

public:
    int hashFunction(int key) {
          qDebug()<<(int)(capacity * (key * A - (int)(key * A)));
        return (int)(capacity * (key * A - (int)(key * A)));

    }

    HashTable(int size) {
        capacity = size;
        table.resize(capacity);
    }
    void insertItem(int key, int data) {
        table[hashFunction(key)].push(data);
    }
    void deleteItem(int key){
        table[hashFunction(key)].pop();
    }
    QVector<QVector<int>> displayHash(){
        QVector<QVector<int>> result;
        for (int i = 0; i < capacity; i++)
            result.append(table[i].toQVector());
        return result;
    }
    void clear() {
        for (int i = 0; i < capacity; i++)
            table[i].clear();
    }


    int findMaxKey() {
        int maxKey = 0;
        for (int i = 1; i < capacity; ++i) {
            if (!table[i].isEmpty() && i > maxKey) {
                maxKey = i;
            }
        }
        return maxKey;
    }
};

#endif // HASHTABLE_H
