#ifndef HACHTABLE_H
#define HACHTABLE_H

#include "Stack.h"
#include <QDebug>

template <typename Value>
class HashTable {
protected:
    QVector <Stack <Value>> table;
    int capacity;

public:
    HashTable(int n) {
        capacity = getNextPrime(n);
        table.resize(capacity);
    }

    bool isPrime(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int getNextPrime(int n) {
        while (!isPrime(n))
            n++;
        return n;
    }

    int hashFunction(int key) {
        return key % capacity;
    }

    void insert(int key, Value data) {
        int index = hashFunction(key);
        table[index].push(data);
    }

    void del(int key) {
        int index = hashFunction(key);
        table[index].clear();
    }

    QVector<QVector<int>> toVector() {
        QVector<QVector<int>> result;
        for (int i = 0; i < capacity; i++) {
            QVector<int> slotContent = table[i].toVector();
            result.append(slotContent);
        }
        return result;
    }

    void clear() {
        for (auto & i : table) {
            i.clear();
        }
    }

};

#endif // HACHTABLE_H
