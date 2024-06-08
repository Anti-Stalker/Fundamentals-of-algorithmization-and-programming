#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <QException>
#include <QStringList>
#include "node.h"
#include "qdebug.h"
#include "qtypes.h"

template <typename T>
class Dequeue
{
public:
    Dequeue();
    ~Dequeue();
    bool isEmpty();
    void insertFront(T value);
    void insertRear(T value);
    void removeFront();
    void removeRear();
    T getFront();
    T getRear();
    qsizetype getSize();
    QStringList getValues();

private:
    Node<T> *front;
    Node<T> *rear;
    qsizetype size;
};

template<typename T>
Dequeue<T>::Dequeue()
    : front(nullptr)
    , rear(nullptr)
    , size(0)
{}

template<typename T>
Dequeue<T>::~Dequeue()
{
    while (!isEmpty()) {
        removeRear();
    }
}

template<typename T>
bool Dequeue<T>::isEmpty()
{
    return front == nullptr;
}

template<typename T>
void Dequeue<T>::insertFront(T value)
{
    Node<T> *newNode = new Node(value);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        front->next = newNode;
        newNode->prev = front;
        front = newNode;
    }
    ++size;
}

template<typename T>
void Dequeue<T>::insertRear(T value)
{
    Node<T> *newNode = new Node(value);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->prev = newNode;
        newNode->next = rear;
        rear = newNode;
    }
    ++size;
}

template<typename T>
void Dequeue<T>::removeFront()
{
    if (isEmpty()) {
        return;
    } else if (front != rear) {
        Node<T> *temp = front->prev;
        delete front;
        front = temp;
        front->next = nullptr;
    } else {
        delete front;
        front = nullptr;
    }
    --size;
}

template<typename T>
void Dequeue<T>::removeRear()
{
    if (isEmpty()) {
        return;
    } else {
        Node<T> *temp = rear->next;
        delete rear;
        rear = temp;
        rear->prev = nullptr;
    }
    --size;
}

template<typename T>
T Dequeue<T>::getFront()
{
    if (isEmpty())
        throw QException();
    else
        return front->value;
}

template<typename T>
T Dequeue<T>::getRear()
{
    if (isEmpty())
        throw QException();
    else
        return rear->value;
}

template<typename T>
qsizetype Dequeue<T>::getSize()
{
    return size;
}

template<typename T>
QStringList Dequeue<T>::getValues()
{
    QStringList list;
    if (!isEmpty()) {
        for (auto it = front; it != nullptr;) {
            list.push_back(it->value);
            it = it->prev;
        }
        return list;
    } else
        return list = {""};
}

#endif // DEQUEUE_H
