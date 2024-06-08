#include "stack.h"

Stack::Stack() : topIndex(-1) {}

bool Stack::isStackEmpty() {
    return topIndex == -1;
}

bool Stack::isStackFull() {
    return topIndex == MAX_STACK_SIZE - 1;
}

void Stack::pushItem(int newItem) {
    if (topIndex < MAX_STACK_SIZE - 1) {
        ++topIndex;
        stackItems[topIndex] = newItem;
    }
}

int Stack::popItem() {
    if (!isStackEmpty()) {
        int removedItem = stackItems[topIndex];
        --topIndex;
        return removedItem;
    }
}

QVector<int> Stack::convertToQVector() {
    QVector<int> vec;
    for (int i = topIndex; i >= 0; --i) {
        vec.append(stackItems[i]);
    }
    return vec;
}

int Stack::peekTopItem() {
    if (!isStackEmpty()) {
        return stackItems[topIndex];
    }
}

void Stack::clearStack() {
    topIndex = -1;
}

int Stack::getSize() {
    return topIndex + 1;
}
