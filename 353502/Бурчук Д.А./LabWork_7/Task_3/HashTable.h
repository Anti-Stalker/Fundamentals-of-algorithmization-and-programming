#ifndef LAB7TASK3_HASHTABLE_H
#define LAB7TASK3_HASHTABLE_H
#define TABLE_SIZE 21L


#include <iostream>
#include <string>
#include "vector"
#include <stack>

class HashTable {
protected:
    std::vector<std::stack<int>> table;

    int hash(int key) const;

public:
    HashTable() : table(TABLE_SIZE) {}

    void insert(int key, int value);

    void remove(int key);

    bool search(int key, int value) const;

    void print() const;
};


#endif //LAB7TASK3_HASHTABLE_H
