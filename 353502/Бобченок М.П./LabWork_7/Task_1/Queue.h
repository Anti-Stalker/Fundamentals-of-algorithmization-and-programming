//
// Created by u on 30.05.24.
//

#ifndef TASK1_QUEUE_H
#define TASK1_QUEUE_H

#include <QVector>
#include <iostream>

template <typename T>
class Queue
{
private:
    struct Data {
        T value;
        Data *next = nullptr;

        Data(const T &inf = T(), Data *next = nullptr) : value(inf), next(next) {}
    };

    Data *head = nullptr;
    Data *tail = nullptr;

public:

    void push(const T &val)
    {
        Data *elem = new Data();
        elem->value = val;

        if (head == nullptr)
        {
            head = elem;
            tail = elem;
        }
        else
        {
            tail->next = elem;
            tail = elem;
        }
    }

    T pop()
    {
        if (!head)
            throw "Queue is empty";

        T res = head->value;
        Data *elem = head;
        head = head->next;
        delete elem;
        return res;
    }

    bool empty() const
    {
        return !head;
    }

    int size() const
    {
        int count = 0;
        Data *cur = head;
        while (cur)
        {
            ++count;
            cur = cur->next;
        }
        return count;
    }

    T &front() const
    {
        if (!head)
            throw;

        return head->value;
    }

    T &back() const
    {
        if (!tail)
            throw;

        return tail->value;
    }

    void clear()
    {
        while (!empty())
            pop();
    }

    void insertAtPosition(const T &val, int pos)
    {
        if (pos < 0 || pos > size())
            throw;

        if (pos == size())
        {
            push(val);
            return;
        }

        Data *elem = new Data(val);
        if (pos == 0)
        {
            elem->next = head;
            head = elem;
            return;
        }

        Data* prev = nullptr;
        Data* curr = head;

        while (pos)
        {
            prev = curr;
            curr = curr->next;
            pos--;
        }

        elem->next = curr;
        prev->next = elem;
    }

    QVector<T> toVector()
    {
        QVector<T> result;
        Data *cur = head;
        while (cur)
        {
            result.push_back(cur->value);
            cur = cur->next;
        }

        return result;
    }

    Queue() {};

    virtual ~Queue()
    {

    }

};

#endif //TASK1_QUEUE_H
