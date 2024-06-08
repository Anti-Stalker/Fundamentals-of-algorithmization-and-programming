#include "SpasgialTable.h"

void SpecialHashTable::removeNegativeKeys()  {
    for (int key = -10; key < 0; ++key) {
        int index = hash(key);
        while (!table[index].empty()) {
            table[index].pop();
        }
    }
}
