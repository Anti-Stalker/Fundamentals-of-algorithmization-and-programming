#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include "hashtable.h"

class MyHashTable : public HashTable
{
public:
    using HashTable::HashTable;
    void createRandomHashTable();
    int findMinKeyIndex();
};

#endif // MYHASHTABLE_H
