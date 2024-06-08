#include "mystack.h"

MyStack::MyStack() : head(nullptr) {}

MyStack::~MyStack() {}

void MyStack::push(int value)
{
    if (head == nullptr)
    {
        head = new Node{value, nullptr};
    }
    else
    {
        Node *node = new Node{value, head};
        head = node;
    }
}

void MyStack::pop()
{
    int item = head->data;
    Node *node = head;
    head = head->next;
    delete node;

}

int MyStack::sum()
{
    Node* temp = head;
    int sum = 0;
    while (temp != nullptr)
    {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

int MyStack::back()
{
    return head->data;
}
