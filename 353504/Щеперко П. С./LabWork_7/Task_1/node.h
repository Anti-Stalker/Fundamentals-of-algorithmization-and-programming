#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
public:
    T value;
    Node<T> *next;
    Node<T> *prev;
    Node(T value)
        : value(value)
        , next(nullptr)
        , prev(nullptr)
    {}
};

#endif // NODE_H
