#ifndef STACK_H
#define STACK_H

#include <QVector>

class Stack
{
    QVector<int> elements;

public:
    Stack() = default;

    bool isEmpty() const
    {
        return elements.isEmpty();
    }

    int size() const
    {
        return elements.size();
    }

    int peek() const
    {
        if (isEmpty())
        {
            throw "Stack is currently empty!";
        }
        return elements.last();
    }

    void push(int value)
    {
        elements.push_back(value);
    }

    int pop()
    {
        if (isEmpty())
        {
            throw "Stack is currently empty!";
        }
        return elements.takeLast();
    }

    void clear()
    {
        elements.clear();
    }

    QVector<int> toVector() const
    {
        return elements;
    }
};

#endif // STACK_H
