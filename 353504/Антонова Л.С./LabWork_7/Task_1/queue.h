#ifndef QUEUE_H
#define QUEUE_H

#include <QList>
#include <QVector>

template <typename T>
class Queue {
private:
    QList<T> list;

public:
    void push(const T& value);
    void pop();
    void insertAt(const T& value, int pos);
    void deleteAt(int pos);
    QVector<T> toVector() const;
    T& front();
    T& back();
    bool isEmpty() const;
    int size() const;
    QString toString() const;
    void makeMinFirst();
};

#endif // QUEUE_H
