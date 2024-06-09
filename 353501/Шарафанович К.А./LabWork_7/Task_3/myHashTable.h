#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H
#include "hashTable.h"
class mht: public HashTable
{
public:
    mht(int size):HashTable(size)
    {

    }
    void solveTask()
    {
        for(int i=0;i<mod;i+=2)
        {
            table[i].clear();
        }
    }
};

#endif // MYHASHTABLE_H
