#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <cstdlib>
#include <ctime>
#include "hashtable.h"

class MyHashTable : public HashTable {
public:
    MyHashTable() : HashTable() {}

    // Метод генерации случайных чисел и заполнения хеш-таблицы
    void generateAndFill(int size) {
        std::srand(std::time(nullptr));
        for (int i = 0; i < size; ++i) {
            int randomNumber = std::rand() % 100;
            int index = std::rand() % 10; // Генерация случайного индекса
            insert(randomNumber, index);
        }
    }
};

#endif // MYHASHTABLE_H
