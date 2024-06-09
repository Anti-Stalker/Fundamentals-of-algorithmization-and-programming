#ifndef QUEUE_H
#define QUEUE_H
#include "cstddef"
#include "cstdint"
#include "algorithm"
#include "stdexcept"
#include "QDebug"

template <typename T>
class Queue
{
private:

    class Node {
    public:
        T data;
        Node* next;

        Node() : next(nullptr) {};
        Node(T data) : data(data), next(nullptr) {}
    };

    Node *_start;
    Node *_end;
    int64_t _size;

public:

    Queue() : _start(nullptr), _end(nullptr), _size(0) { }

    void push(T temp)
    {
        if (!_start) {
            _start = new Node();
            _start->data = temp;
            _start->next = nullptr;
            _end = _start;
        }
        else {
            _end->next = new Node();
            _end = _end->next;
            _end->next = nullptr;
            _end->data = temp;
        }
        _size++;
    }

    void pop()
    {
        if (_size == 0) return;
        if (_size == 1) {
            delete _start;
            _end = nullptr;
            _start = nullptr;
        }
        else {
            Node *temp = _start->next;
            delete _start;
            _start = temp;
        }
        _size--;
    }

    const T &front()
    {
        if (_size ==0) {
            throw std::runtime_error("Error: Queue is empty");
        }
        return _start->data;
    }

    const T &back()
    {
        if (_size ==0) {
            throw std::runtime_error("Error: Queue is empty");
        }
        return _end->data;
    }

    bool empty()
    {
        return _size==0;
    }

    int64_t size()
    {
        return _size;
    }

    void swap(Queue other)
    {
        std::swap(other._end, _end);
        std::swap(other._start, _start);
        std::swap(other._size, _size);
    }


};

#endif // QUEUE_H
