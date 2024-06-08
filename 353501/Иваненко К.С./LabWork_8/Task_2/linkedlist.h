#pragma once

#ifndef BINARYHEAP_LINKEDLIST_H
#define BINARYHEAP_LINKEDLIST_H

#include <memory>
#include "shared_ptr.h"

struct Node
{
    int obj;
    shared_ptr<Node> next = nullptr;
    shared_ptr<Node> prev = nullptr;

    Node() = default;
    explicit Node(int data) : obj(data) {}

    ~Node()
    {
        next = prev = nullptr;
    };
};

class linkedlist
{
private:
    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> tail = nullptr;

public:
    linkedlist() = default;

public:
    void push_back(int par)
    {
        shared_ptr<Node> ptr(new Node(par));
        ptr->prev = tail;
        if (tail != shared_ptr<Node>(nullptr))
        {
            tail->next = ptr;
        }
        if (head == shared_ptr<Node>(nullptr))
        {
            head = ptr;
        }
        tail = ptr;
    }

    void push_front(int par)
    {
        shared_ptr<Node> ptr(new Node(par));
        ptr->next = head;
        if (head != shared_ptr<Node>(nullptr))
        {
            head->prev = ptr;
        }
        if (tail == shared_ptr<Node>(nullptr))
        {

            tail = ptr;
        }
        head = ptr;
    }
    void pop_back()
    {
        if (tail == shared_ptr<Node>(nullptr))
        {
            return;
        }
        shared_ptr<Node> ptr = tail->prev;
        if (ptr != shared_ptr<Node>(nullptr))
        {
            ptr->next = shared_ptr<Node>(nullptr);
        }
        else
        {
            head = shared_ptr<Node>(nullptr);
        }
        tail = ptr;
    }

    void pop_front()
    {
        if (head == shared_ptr<Node>(nullptr))
        {
            return;
        }
        shared_ptr<Node> ptr = head->next;
        if (ptr != shared_ptr<Node>(nullptr))
        {
            ptr->prev = shared_ptr<Node>(nullptr);
        }
        else
        {
            tail = shared_ptr<Node>(nullptr);
        }
        head = ptr;
    }

    int &get_at(size_t index)
    {
        shared_ptr<Node> ptr = head;
        int n = 0;
        while (n != index)
        {
            if (ptr == shared_ptr<Node>(nullptr))
            {
                return head->obj;
            }
            ptr = ptr->next;
            ++n;
        }
        return ptr->obj;
    }

    int &operator[](size_t index)
    {
        return get_at(index);
    }

    size_t size()
    {
        shared_ptr<Node> ptr = head;
        if (head == nullptr)
        {
            return 0;
        }
        if (head == tail)
        {
            return 1;
        }
        size_t sz = 0;
        for (ptr; ptr != tail; ptr = ptr->next)
        {
            ++sz;
        }
        ++sz;
        return sz;
    }
};

#endif // BINARYHEAP_LINKEDLIST_H
