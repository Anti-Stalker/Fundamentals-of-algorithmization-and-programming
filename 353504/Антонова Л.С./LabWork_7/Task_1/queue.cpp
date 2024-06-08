#include "queue.h"

template <typename T>
void Queue<T>::push(const T& value) {
    list.append(value);
}

template <typename T>
void Queue<T>::pop() {
    if (!list.isEmpty()) {
        list.removeFirst();
    }
}

template <typename T>
void Queue<T>::insertAt(const T& value, int pos) {
    if (pos < 0 || pos > list.size()) {
        throw "Invalid position to insert at!";
    }
    list.insert(pos, value);
}

template <typename T>
void Queue<T>::deleteAt(int pos) {
    if (pos < 0 || pos >= list.size()) {
        throw "Invalid position to delete at!";
    }
    list.removeAt(pos);
}

template <typename T>
QVector<T> Queue<T>::toVector() const {
    return QVector<T>(list.begin(), list.end());
}

template <typename T>
T& Queue<T>::front() {
    return list.first();
}

template <typename T>
T& Queue<T>::back() {
    return list.last();
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return list.isEmpty();
}

template <typename T>
int Queue<T>::size() const {
    return list.size();
}

template <typename T>
QString Queue<T>::toString() const {
    QString str;
    for (const T& item : list) {
        str += QString::number(item) + ", ";
    }
    str.chop(2);
    return str;
}

template <typename T>
void Queue<T>::makeMinFirst() {
    if (!list.isEmpty()) {
        int minIndex = 0;
        T minValue = list[0];
        for (int i = 1; i < list.size(); ++i) {
            if (list[i] < minValue) {
                minValue = list[i];
                minIndex = i;
            }
        }
        list.move(minIndex, 0);
    }
}
