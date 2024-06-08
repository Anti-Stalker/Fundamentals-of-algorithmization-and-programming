#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <cstdlib>
#include <ctime>
#include "hashtable.h"
#include <QSet>

class MyHashTable : public HashTable {
public:
    MyHashTable(int size) : HashTable(size) {}

    void generateAndFill(int size) {
        std::srand(std::time(nullptr));
        QSet<QString> uniqueKeys; // Множество для хранения уникальных ключей
        while (uniqueKeys.size() < size) {
            QString randomKey;
            int length = 5 + std::rand() % 5; // Случайная длина ключа от 5 до 9 символов
            for (int j = 0; j < length; ++j) {
                char randomChar;
                if (std::rand() % 2 == 0) {
                    // Случайно выбираем цифру
                    randomChar = '0' + std::rand() % 10; // Генерация случайной цифры от '0' до '9'
                } else {
                    // Случайно выбираем символ от 'a' до 'z'
                    randomChar = 'a' + std::rand() % 26; // Генерация случайного символа от 'a' до 'z'
                }
                randomKey.append(QChar(randomChar));
            }
            if (!uniqueKeys.contains(randomKey)) { // Проверяем, что ключ уникален
                insert(randomKey); // Вставляем уникальный ключ в хеш-таблицу
                uniqueKeys.insert(randomKey); // Добавляем ключ в множество уникальных ключей
            }
        }
    }

    int getSize() const {
        return tableSize;
    }
};

#endif // MYHASHTABLE_H
