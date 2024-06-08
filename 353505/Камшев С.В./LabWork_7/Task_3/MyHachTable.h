#ifndef MYHACHTABLE_H
#define MYHACHTABLE_H

#include <QRandomGenerator>
#include "HachTable.h"

template <typename Value>
class MyHashTable: public HashTable <Value>
{

public:
    MyHashTable(int n): HashTable<Value>(n){}
    MyHashTable() : HashTable<Value>(0){};
    void createRandomHashTable(){
        int n = QRandomGenerator::global()->bounded(0, 1000);
        for (int i = 0; i < n; ++i) {
            this->insert(QRandomGenerator::global()->bounded(0, this->capacity), QRandomGenerator::global()->bounded(0, 100));
        }
    }

    int findMinKey(){
        int minKey = 0;
        for (int i = 1; i < this->capacity; ++i) {
            if (!this->table[i].empty() && i < minKey) {
                minKey = i;
            }
        }
        return minKey;
    }

    QVector<Value> operator [](int index){
        return this->table[index].toVector();

    }
};

#endif // MYHACHTABLE_H
