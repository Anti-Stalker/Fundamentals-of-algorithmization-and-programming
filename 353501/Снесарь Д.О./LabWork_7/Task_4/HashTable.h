#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QRandomGenerator>
#include <QPair>
#include <stdexcept>


template <typename V> class HashTable {
    static const int BPRIME = 3571;


    class HashNode {
    public:
        V value;
        int key;
        HashNode(int key, V value)
        {
            this->value = value;
            this->key = key;
        }
    };

    int _a, _b;
    int size;
    HashNode** table;
    int collisions = 0;

    const HashNode* const DELETED = new HashNode(-1, -1);

    int hashFunction(int key) {
        return (((_a * key + _b) % BPRIME) % size);
    }

    void initHashFunction()
    {
        _a = QRandomGenerator::global()->bounded(1, BPRIME - 1);
        _b = QRandomGenerator::global()->bounded(0, BPRIME - 1);
    }

public:

    HashTable(int size)
    {
        initHashFunction();
        this->size = size;
        table = new HashNode* [size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;

    }

    void insertNode(int key, V value)
    {
        HashNode* temp = new HashNode(key, value);

        int id = hashFunction(key);


        while (table[id] != nullptr
               && table[id]->key != key
               && table[id]->key != -1)
        {
            id++;
            id %= size;
        }

        table[id] = temp;
    }


    V deleteNode(int key)
    {
        int id = hashFunction(key);
        while (table[id] != nullptr) {

            if (table[id]->key == key) {
                HashNode* temp = table[id];

                table[id] = DELETED;
                return table->value;
            }
            id++;
            id %= size;
        }
        return nullptr;
    }


    V get(int key)
    {
        int id = hashFunction(key);
        int counter = 0;
        while (table[id] != nullptr)
        {

            if (counter++ > size)
                  throw new std::invalid_argument("Key not found");

            if (table[id]->key == key)
                return table[id]->value;
            id++;
            id %= size;
        }

         throw new std::invalid_argument("Key not found");
    }

    bool isEmpty() { return size == 0; }

    std::string display()
    {
        std::string output;
        for (int i = 0; i < size; i++) {
            if (table[i] != nullptr && table[i]->key != -1) {
                output +=  std::to_string(i) + " key = " + std::to_string(table[i]->key) + "  value = " + std::to_string(table[i]->value) + "\n";
            }
        }
        return output;
    }
    void clear()
    {
        delete[] table;
        table = new HashNode* [size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;


    }
};

#endif // HASHTABLE_H
