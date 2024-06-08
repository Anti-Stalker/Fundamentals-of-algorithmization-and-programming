#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QString>
#include <vector>
#include <chrono>
#include <QTextStream>

class HashTable {
public:
    struct Entry {
        QString key;
        bool isOccupied;
    };

    std::vector<Entry> table;
    int tableSize;

public:
    HashTable(int size) : tableSize(size) {
        table.resize(size);
        for (auto &entry : table) {
            entry.isOccupied = false;
        }
    }

    int hashFunction(const QString &key) const {
        int hash = 0;
        for (auto ch : key) {
            hash += ch.unicode();
        }
        return hash % tableSize;
    }

    void insert(const QString &key) {
        int hash = hashFunction(key);
        int originalHash = hash;

        while (table[hash].isOccupied) {
            hash = (hash + 1) % tableSize;
            if (hash == originalHash) {
                return; // Таблица полная
            }
        }

        table[hash].key = key;
        table[hash].isOccupied = true;
    }

    bool find(const QString &key) const {
        int hash = hashFunction(key);
        int originalHash = hash;

        while (table[hash].isOccupied) {
            if (table[hash].key == key) {
                return true;
            }
            hash = (hash + 1) % tableSize;
            if (hash == originalHash) {
                return false; // Цикл завершен, ключ не найден
            }
        }
        return false;
    }



    QString print() const {
        QString result;
        QTextStream out(&result);
        for (int i = 0; i < tableSize; ++i) {
            out << "[" << i << "]: ";
            if (table[i].isOccupied) {
                out << table[i].key;
            }
            out << "\n";
        }
        return result;
    }

    int findMaxStack() const {
        int maxStack = 0;
        int currentStack = 0;
        for (const auto &entry : table) {
            if (entry.isOccupied) {
                currentStack++;
                if (currentStack > maxStack) {
                    maxStack = currentStack;
                }
            } else {
                currentStack = 0;
            }
        }
        return maxStack;
    }

    double measureSearchTime(const QString &key) const {
        auto start = std::chrono::high_resolution_clock::now();
        find(key);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        return elapsed.count();
    }
};

#endif // HASHTABLE_H
