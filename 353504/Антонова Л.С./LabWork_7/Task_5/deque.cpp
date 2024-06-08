#include "deque.h"

template <typename T>
void Deque<T>::push_front(const T& value) {
    list.prepend(value);
}

template <typename T>
void Deque<T>::push_back(const T& value) {
    list.append(value);
}

template <typename T>
void Deque<T>::pop_front() {
    if (!list.isEmpty()) {
        list.removeFirst();
    }
}

template <typename T>
void Deque<T>::pop_back() {
    if (!list.isEmpty()) {
        list.removeLast();
    }
}

template <typename T>
T& Deque<T>::begin() {
    return list.first();
}

template <typename T>
T& Deque<T>::end() {
    return list.last();
}

template <typename T>
bool Deque<T>::isEmpty() const {
    return list.isEmpty();
}

template <typename T>
int Deque<T>::size() const {
    return list.size();
}

template <typename T>
QString Deque<T>::toString() const {
    QString str;
    for (const T& item : list) {
        str += QString::number(item) + ", ";
    }
    str.chop(2);
    return str;
}
