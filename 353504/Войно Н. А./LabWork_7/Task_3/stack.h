#ifndef STACK_H
#define STACK_H

#include <QVector>

class Stack {
private:
    int items[1000];
    int top;

public:
    Stack();
    bool isEmpty();
    bool isFull();
    void push(int newItem);
    void clear();
    int pop();
    QVector<int> toQVector();
    int peek();
};

#endif // STACK_H
