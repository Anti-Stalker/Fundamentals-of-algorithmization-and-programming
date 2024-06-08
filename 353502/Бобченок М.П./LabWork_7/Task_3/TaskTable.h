//
// Created by u on 31.05.24.
//

#ifndef TASK3_TASKTABLE_H
#define TASK3_TASKTABLE_H

#include "HashTable.h"

class TaskTable : public HashTable
{
public:
    TaskTable(int sz) : HashTable(sz) {}

    void deleteEvenKeys()
    {
        for (int i = 0; i < cap; ++i)
            if (i % 2) table[i].clear();
    }
};

#endif //TASK3_TASKTABLE_H
