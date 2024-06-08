#ifndef MYSTACK_H
#define MYSTACK_H

class MyStack
{
public:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *head;
    MyStack();
    ~MyStack();
    void push(int value);
    void pop();
    int sum();
    int back();
};

#endif // MYSTACK_H
