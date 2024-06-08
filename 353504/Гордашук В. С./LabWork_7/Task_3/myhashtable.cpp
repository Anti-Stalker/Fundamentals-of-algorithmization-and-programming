#include "myhashtable.h"

int MyHashTable::getMinIndex()
{
    for (int i = 0; i < capacity; ++i)
    {
        if (table[i] != nullptr)
        {
            qDebug() << table[i]->value->back();
                        return i;
        }
    }
    return -1;
}
