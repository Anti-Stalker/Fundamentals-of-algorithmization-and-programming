#ifndef QUEUEZXC_H
#define QUEUEZXC_H

#include <QString>
#include <QRandomGenerator>

template <typename T> struct Node
{
    T data;
    Node* next;
    Node* prev;
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template <typename T> class Queue
{
public:
    Queue();
    ~Queue();
    void push_back(T data);
    T pop_back();
    void push_front(T data);
    T pop_front();
    T front();
    T back();
    bool empty();
    int size();
    void clear();
    QString print();
    void random(bool a);
private:
    Node<T>* head;
    Node<T>* tail;
    ulong count;
};


template <typename T> Queue<T>::Queue()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template <typename T> Queue<T>::~Queue()
{
    clear();
}

template <typename T> void Queue<T>::push_back(T data)
{
    Node<T>* temp = new Node<T>(data);
    temp->prev = tail;
    temp->next = nullptr;
    if (tail != nullptr)
    {
        tail->next = temp;
    }
    tail = temp;
    if (head == nullptr)
    {
        head = temp;
    }
    count++;
}

template <typename T> T Queue<T>::pop_back()
{
    if (empty())
    {
        throw std::out_of_range("Queue is empty");
    }
    Node<T>* temp = tail;
    T data = tail->data;
    tail = tail->prev;
    if (tail != nullptr)
    {
        tail->next = nullptr;
    }
    delete temp;
    count--;
    return data;
}

template <typename T> void Queue<T>::push_front(T data)
{
    Node<T>* temp = new Node<T>(data);
    temp->prev = nullptr;
    temp->next = head;
    if (head != nullptr)
    {
        head->prev = temp;
    }
    head = temp;
    if (tail == nullptr)
    {
        tail = temp;
    }
    count++;
}

template <typename T> T Queue<T>::pop_front()
{
    if (empty())
    {
        throw std::out_of_range("Queue is empty");
    }
    Node<T>* temp = head;
    T data = head->data;
    head = head->next;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    delete temp;
    count--;
    return data;
}

template <typename T> T Queue<T>::front()
{
    if (empty())
    {
        throw std::out_of_range("Queue is empty");
    }
    return head->data;
}

template <typename T> T Queue<T>::back()
{
    if (empty())
    {
        throw std::out_of_range("Queue is empty");
    }
    return tail->data;
}

template <typename T> bool Queue<T>::empty()
{
    return count == 0;
}

template <typename T> int Queue<T>::size()
{
    return count;
}

template <typename T> void Queue<T>::clear()
{
    while (!empty())
    {
        pop_front();
    }
}

template <typename T> void Queue<T>::random(bool a)
{
    T randomValue = static_cast<T>(QRandomGenerator::global()->bounded(1, 1001));
    a ? push_back(randomValue): push_front(randomValue);
}

template <typename T> QString Queue<T>::print()
{
    QString val;
    Node<T>* temp = head;
    while (temp != nullptr)
    {
        val += QString::number(temp->data) + " ";
        temp = temp->next;
    }
    val += "\n";
    return val;
}


#endif // QUEUEZXC_H
