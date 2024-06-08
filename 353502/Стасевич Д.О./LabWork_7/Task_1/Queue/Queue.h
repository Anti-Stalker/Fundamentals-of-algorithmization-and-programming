//
// Created by darina on 5/27/24.
//

#ifndef TASK1_QUEUE_H
#define TASK1_QUEUE_H


#include <vector>
#include <iostream>

template<typename T>
class Queue {

public:
    Queue() {};

    ~Queue() {
        while (_size != 0) {
            dequeue();
        }
    }

    struct Node {
        T data;
        Node *next;
        Node* prev;
        Node(const T &data = T()) : data(data), next(nullptr), prev(nullptr) {}
    };

    void clear() {
        Node* _cur = _head;
        while (_size != 0) {
            Node* temp = _cur;
            _cur = _cur->next;
            _size --;
            delete temp;
        }
        _head = nullptr;
        _tail = nullptr;
    }

    void enqueue(const T &data) {
        Node* _newNode = new Node(data);
        if (_size == 0)
        {
            _head = _newNode;
            _tail = _newNode;
            _head->next = _head;
            _head->prev = _head;
            _tail->next = _head;
            _tail->prev = _head;
            _cur_position = _head;
        }
         else {
             // add after cur_position
             _cur_position->next->prev = _newNode;
             _newNode->next = _cur_position->next;
             _cur_position->next = _newNode;
             _newNode->prev = _cur_position;
             _cur_position = _cur_position->next;
        }
        ++ _size;
    }

    T dequeue() {
        if (_size == 0) {
            throw "Empty queue";
        };

        if(_size == 1)
            clear();
        if(_head == _cur_position)
        {
            _head = _head->next;
        }
        if(_tail == _cur_position)
        {
            _tail = _tail->next;
        }
        T _value = _cur_position->data;
        -- _size;
        if(_size) {
            Node* _temp = _cur_position->prev;
            _cur_position->prev->next = _cur_position->next;
            delete _cur_position;
            _temp->next->prev = _temp;
            _cur_position = _temp->next;
        }
        else
        {
            _head = nullptr;
            _tail = nullptr;
            _cur_position = nullptr;
        }
        return _value;
    }

    bool isEmpty() const {
        return _size == 0;
    }

    int size() const {
        return _size;
    }

    T &front() const {
        if (_head == nullptr) {
            throw "Queue is empty";
        }
        return _head->data;
    }

    T &back() const {
        if (_tail == nullptr) {
            throw "Queue is empty";
        }
        return _tail->data;
    }

    std::vector<T> show()
    {
        std::vector<T> ret;
        Node* temp = _head;
        for(int i = 0; i < _size; i ++)
        {
            std::cout << "temp->data " << temp->data << " temp->prev->data " << temp->prev->data << " temp->next->data " << temp->next->data << "\n";
            ret.push_back(temp->data);
            temp = temp->next;
        }
        return ret;
    }

    T GoLeftCircle()
    {
        if(_size == 0)
        {
            throw "Empty queue";
        }
        _cur_position = _cur_position->prev;
        return _cur_position->data;
    }

    T GetNode()
    {
        if(_size == 0)
        {
            throw "Empty queue";
        }
        return _cur_position->data;
    }

    T GoRightCircle()
    {
        if(_size == 0)
        {
            throw "Empty queue";
        }
        _cur_position = _cur_position->next;
        return _cur_position->data;
    }

private:
    Node* _head = nullptr;
    Node* _tail = nullptr;
    Node* _cur_position = nullptr;
    int _size = 0;
};


#endif //TASK1_QUEUE_H
