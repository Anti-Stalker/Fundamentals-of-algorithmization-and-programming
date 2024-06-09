#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <QVector>
#include <QStack>
#include <QString>
#include <QRandomGenerator>
#include <climits>

class HashTable {
protected:
    QVector<QStack<int>> table;
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int size) : size(size) {
        table.resize(size);
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push(key);
    }

    void clear() {
        for (auto &stack : table) {
            stack.clear();
        }
    }

    QString toString() {
        QString result;
        for (int i = 0; i < size-1; ++i) {
            result += "Index " + QString::number(i) + ": ";
            QStack<int> stack = table[i];
            while (!stack.isEmpty()) {
                result += QString::number(stack.pop()) + " ";
            }
            result += "\n";
        }
        return result;
    }
};

class ExtendedHashTable : public HashTable {
public:
    ExtendedHashTable(int size) : HashTable(size) {}

    int findMinKey() {
        int minKey = INT_MAX;
        for (const auto &stack : table) {
            for (int i = 0; i < stack.size(); ++i) {
                if (stack.at(i) < minKey) {
                    minKey = stack.at(i);
                }
            }
        }
        return minKey;
    }
};
#endif // HASHTABLE_H
