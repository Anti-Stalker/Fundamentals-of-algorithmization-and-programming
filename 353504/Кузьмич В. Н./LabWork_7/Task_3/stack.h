#ifndef STACK_H
#define STACK_H

#include <QVector>

class Stack {
private:
    static const int MAX_STACK_SIZE = 1000;
    int stackItems[MAX_STACK_SIZE];
    int topIndex;

public:
    Stack();
    bool isStackEmpty();
    bool isStackFull();
    void pushItem(int newItem);
    void clearStack();
    int popItem();
    QVector<int> convertToQVector();
    int peekTopItem();
    int getSize();
};

#endif // STACK_H
