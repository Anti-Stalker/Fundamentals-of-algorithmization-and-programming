#include "mydeque.h"

MyDeque::MyDeque() : head(nullptr), tail(nullptr) {};

void MyDeque::push_front(int data) {
    Node* node = new Node{data, head, nullptr};
    if (head) {
        head->prev = node;
    } else {
        tail = node;
    }
    head = node;
}

void MyDeque::push_back(int data) {
    Node* node = new Node{data, nullptr, tail};
    if (tail) {
        tail->next = node;
    } else {
        head = node;
    }
    tail = node;
}

void MyDeque::pop_front() {
    if (head) {
        Node* node = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete node;
    }
}

void MyDeque::pop_back() {
    if (tail) {
        Node* node = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete node;
    }
}

int MyDeque::front() {
    if (head) {
        return head->data;
    } else {
        throw QException();
    }
}

int MyDeque::back()
{
    if (tail) {
        return tail->data;
    } else {
        throw QException();
    }
}

QString MyDeque::print()
{
    Node *node = head;
    QString res;
    while (node != nullptr)
    {
        res += QString::number(node->data);
        if (node->next != nullptr) res += ' ';
        node = node->next;
    }
    return res;
}

int MyDeque::minValue()
{
    Node *node = head;
    int min = node->data;
    while (node != nullptr)
    {
        if (node->next != nullptr && min > node->next->data) min = node->next->data;
        node = node->next;
    }
    return min;
}

int MyDeque::maxValue()
{
    Node *node = head;
    int max = node->data;
    while (node != nullptr)
    {
        if (node->next != nullptr && max < node->next->data) max = node->next->data;
        node = node->next;
    }
    return max;
}

void MyDeque::removeAt(int index) {
    if (head == nullptr)
    {
        return;
    }
    Node* node = head;

    for (int i = 0; node != nullptr && i < index; ++i)
    {
        node = node->next;
    }

    if (node == nullptr)
    {
        return;
    }

    if (node == head)
    {
        head = node->next;
    }

    if (node == tail)
    {
        tail = node->prev;
    }

    if (node->next != nullptr)
    {
        node->next->prev = node->prev;
    }
    if (node->prev != nullptr)
    {
        node->prev->next = node->next;
    }

    delete node;
}

int MyDeque::at(int index)
{
    if (head == nullptr)
    {
        throw QException();
    }
    Node* node = head;

    for (int i = 0; node != nullptr && i < index; ++i)
    {
        node = node->next;
    }

    if (node == nullptr)
    {
        throw QException();
    }
    return node->data;
}

int MyDeque::lastIndex() {
    if (head == nullptr) {
        throw QException();
    }
    Node* node = head;
    int index = 0;
    while (node->next != nullptr) {
        node = node->next;
        index++;
    }
    return index;
}

int MyDeque::indexOf(int value)
{
    Node* node = head;
    int index = 0;
    while (node != nullptr)
    {
        if (node->data == value)
        {
            return index;
        }
        node = node->next;
        ++index;
    }
    return -1;
}
