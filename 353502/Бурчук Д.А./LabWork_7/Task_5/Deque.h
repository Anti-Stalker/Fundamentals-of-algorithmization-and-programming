#ifndef DEQUE_H
#define DEQUE_H
#define NODE_CAPACITY 4L

#include <stdexcept>


class Deque {
private:

    struct Node {
        int elements[NODE_CAPACITY];
        int count;
        Node* previous;
        Node* next;

        Node() : count(0), previous(nullptr), next(nullptr) {}
    };

    class Iterator {
    private:
        Node* currentNode;
        int currentIndex;

    public:
        Iterator(Node* node, int index);
        int operator*() const;
        Iterator& operator++();
        bool operator!=(const Iterator& other) const;
    };


    Node* first;
    Node* last;
    int _size;

    void delFirst();
    void delLast();
    void setFirst(Node* tmp);
    void setLast(Node* tmp);

public:
    Deque();
    int back() const;
    int front() const;
    void pop_front();
    void push_back(int element);
    void pop_back();
    void push_front(int element);
    int size() const;
    bool empty() const;
    void clear();

    Iterator begin() const;
    Iterator end() const;
};

#endif // DEQUE_H
