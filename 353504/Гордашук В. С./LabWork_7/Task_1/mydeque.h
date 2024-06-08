#ifndef MYDEQUE_H
#define MYDEQUE_H

#include <QException>

class MyDeque
{
public:
    MyDeque();
    void push_front(int data);
    void push_back(int data);
    void pop_front();
    void pop_back();
    int minValue();
    int maxValue();
    int front();
    int back();
    QString print();
    void removeAt(int index);
    int at(int index);
    int lastIndex();
    int indexOf(int value);

private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
};

#endif // MYDEQUE_H
