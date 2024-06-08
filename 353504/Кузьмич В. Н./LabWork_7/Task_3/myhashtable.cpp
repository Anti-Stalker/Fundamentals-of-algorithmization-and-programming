#include "myhashtable.h"
#include <QRandomGenerator>

void MyHashTable::createRandomHashTable() {
    int nam = QRandomGenerator::global()->bounded(5, 1000);
    for (int i = 0; i < nam; ++i) {
        insertItem(QRandomGenerator::global()->bounded(0, n), QRandomGenerator::global()->bounded(10, 1000));
    }
}

int MyHashTable::findMinKeyIndex() {
    int minKeyIndex = 0;
    int minKey = 1001;
    for (int i = 0; i < n; i++) {
        if (!table[i].isStackEmpty()) {
            QVector<int> values = table[i].convertToQVector();
            for (int value : values) {
                if (value < minKey) {
                    minKey = value;
                    minKeyIndex = i;
                }
            }
        }
    }
    return minKeyIndex;
}
