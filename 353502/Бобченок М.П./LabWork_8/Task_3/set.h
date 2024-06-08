//
// Created by u on 05.06.24.
//

#ifndef TASK3_SET_H
#define TASK3_SET_H

#include "Treap.h"

template <typename K>
class set
{
private:
    Treap<K, int> t;

public:
    void insert(K key)
    {
        t.insert(key, 1);
    }

    bool has(K key)
    {
        return t.contains(key);
    }

    void erase(K key)
    {
        t.erase(key);
    }

    void clear()
    {
        t.clear(t.getRoot());
    }

    size_t size()
    {
        return t.getRoot()->sz;
    }

    Treap<K, int>::Iterator begin()
    {
        return t.begin();
    }

    Treap<K, int>::Iterator end()
    {
        return t.end();
    }

    Treap<K, int> getT()
    {
        return t;
    }
};

#endif //TASK3_SET_H
