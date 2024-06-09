#ifndef STACK_H
#define STACK_H


#include "cstddef"
#include "cstdint"
#include "algorithm"
#include "stdexcept"
#include "QDebug"

template <typename T>
class Stack
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

    Stack() : _start(nullptr), _end(nullptr), _size(0) {}

    Stack(Stack& other) {
        _start = nullptr;
        _end = nullptr;
        _size = 0;

        Node *temp = other._start;
        for (int i = 0; i < other.size(); i++) {
            push(temp->data);
            temp = temp->next;
        }
    }

    ~Stack () {
        clear();
    }

    void clear() {
        while(_size) {
            pop();
        }
    }

    void push(T value)
    {
        if (!_size) {
            _start = new Node();
            _start->data = value;
            _start->next = nullptr;
            _end = _start;
        }
        else {
            Node *temp = _end;
            _end = new Node();
            _end->data = value;
            _end->next = temp;
        }
        _size++;
    }

    void pop()
    {
        if (_size == 0) return;
        if (_size == 1) {
            delete _end;
            _end = nullptr;
            _start = nullptr;
        }
        else {
            Node *temp = _end->next;
            delete _end;
            _end = temp;
        }
        _size--;
    }

    const T &top() const
    {
        if (_size ==0) {
            throw std::runtime_error("Error: Stack is empty");
        }
        return _end->data;
    }

    bool empty() const
    {
        return _size==0;
    }

    int64_t size() const
    {
        return _size;
    }

    void swap(Stack other)
    {
        std::swap(other._end, _end);
        std::swap(other._start, _start);
        std::swap(other._size, _size);
    }


};

#endif // STACK_H
