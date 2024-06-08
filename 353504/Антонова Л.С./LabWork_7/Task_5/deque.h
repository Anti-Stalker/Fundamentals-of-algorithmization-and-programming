#ifndef DEQUE_H
#define DEQUE_H

#include <QList>

template <typename T>
class Deque {
private:
    QList<T> list;

public:
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    T& begin();
    T& end();
    bool isEmpty() const;
    int size() const;
    QString toString() const;
};

#endif // DEQUE_H
