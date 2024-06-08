#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QString>
#include <QTextStream>
#include <vector>

class HashTable {
private:
    static const int tableSize = 10;
    std::vector<std::vector<int>> table;

public:
    HashTable() {
        table.resize(tableSize);
    }

    // Метод вставки элемента в хеш-таблицу
    void insert(int key, int index) {
        if (index >= 0 && index < tableSize) {
            table[index].push_back(key);
        }
    }

    // Метод поиска номера стека с максимальным значением ключа
    int findMaxStack() {
        int maxStackSize = 0;
        int maxStackIndex = -1;
        for (int i = 0; i < tableSize; ++i) {
            if (table[i].size() > maxStackSize) {
                maxStackSize = table[i].size();
                maxStackIndex = i;
            }
        }
        return maxStackIndex;
    }

    // Метод вывода хеш-таблицы
    QString print() {
        QString result;
        QTextStream stream(&result);
        for (int i = 0; i < tableSize; ++i) {
            stream << "Stack " << i << ": ";
            for (int j = 0; j < table[i].size(); ++j) {
                stream << table[i][j] << " ";
            }
            stream << "\n";
        }
        return result;
    }
    // Метод поиска элемента в хеш-таблице
    bool find(int key, int& index, int& stackIndex) {
        for (int i = 0; i < tableSize; ++i) {
            for (int j = 0; j < table[i].size(); ++j) {
                if (table[i][j] == key) {
                    index = i;
                    stackIndex = j;
                    return true;
                }
            }
        }
        return false;
    }

    // Метод удаления элемента из хеш-таблицы
    bool remove(int key) {
        for (int i = 0; i < tableSize; ++i) {
            for (int j = 0; j < table[i].size(); ++j) {
                if (table[i][j] == key) {
                    table[i].erase(table[i].begin() + j);
                    return true;
                }
            }
        }
        return false;
    }
};

#endif // HASHTABLE_H
