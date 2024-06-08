#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <QDebug>
#include "hashtable.h"

class MyHashTable  : public HashTable
{
public:
    MyHashTable(int _capacity) : HashTable(_capacity) {}
    int getMinIndex();
};

#endif // MYHASHTABLE_H
