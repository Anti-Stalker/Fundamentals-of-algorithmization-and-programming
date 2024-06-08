#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"
#include<QString>
class Queue {
public:
    Queue();
    ~Queue();

    void enqueue(int value);
    int dequeue();
    bool isEmpty() const;
    void bubbleSort();
    QString toString() const;

private:
    Node* head;
    Node* tail;
};

#endif // QUEUE_H
