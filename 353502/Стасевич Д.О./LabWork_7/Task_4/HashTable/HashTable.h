//
// Created by darina on 5/28/24.
//

#ifndef TASK4_HASHTABLE_H
#define TASK4_HASHTABLE_H


#include <vector>
#include <string>

class HashTable {
    int capacity;
    int all;

    std::vector<int> st;

    std::vector<std::pair<int, std::string> > table;

    int GetHash(std::string s);
    void reserve(int n);
    void CalculateSt();

public:

    HashTable();
    HashTable(int n);
    void insert(std::string s);
    bool remove(std::string s);
    std::vector<std::pair<int, std::string> > GetCollisions();
    int findItem(std::string s);

};


#endif //TASK4_HASHTABLE_H
