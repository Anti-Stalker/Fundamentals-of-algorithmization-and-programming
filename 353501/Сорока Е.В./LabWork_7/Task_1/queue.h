#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <stdexcept>
#include <algorithm>

template <typename T>
class Queue {
public:
    void enqueue(const T& value) {
        data.push_back(value);
    }

    T dequeue() {
        if (data.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        T value = data.front();
        data.erase(data.begin());
        return value;
    }

    T findAndMoveMin() {
        if (data.empty()) {
            throw std::runtime_error("Queue is empty");
        }

        // Найти минимальный элемент
        auto minIt = std::min_element(data.begin(), data.end());
        T minValue = *minIt;

        // Удалить минимальный элемент из текущего места
        data.erase(minIt);

        // Вставить минимальный элемент в начало
        data.insert(data.begin(), minValue);

        return minValue;
    }

    typename std::vector<T>::iterator begin() {
        return data.begin();
    }

    typename std::vector<T>::iterator end() {
        return data.end();
    }

private:
    std::vector<T> data;
};

#endif // QUEUE_H
