#include "hashtable.h"

HashTable::HashTable(int namber) {
    n = namber;
    table.resize(n);
}

int HashTable::hashFunction(int key) {
    return key % n;
}

void HashTable::insertItem(int key, int data) {
    int ind = hashFunction(key);
    table[ind].pushItem(data);
}

void HashTable::deleteItem(int key) {
    int ind = hashFunction(key);
    table[ind].popItem();
}

QVector<QVector<int>> HashTable::displayHash() {
    QVector<QVector<int>> result;
    for (int i = 0; i < n; i++) {
        QVector<int> vec = table[i].convertToQVector();
        result.append(vec);
    }
    return result;
}

void HashTable::clear() {
    for (auto & i : table) {
        i.clearStack();
    }
}
