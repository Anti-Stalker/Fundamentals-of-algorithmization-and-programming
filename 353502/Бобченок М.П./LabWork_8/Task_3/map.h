//
// Created by u on 05.06.24.
//

#ifndef TASK3_MAP_H
#define TASK3_MAP_H

#include "Treap.h"

template <typename K, typename V>
class map
{
private:
    Treap<K, V> t;

public:
    void insert(K key, V value)
    {
        t.insert(key, value);
        t.getNodeByKey(key)->value = value;
    }

    V get(K key)
    {
        return t.getNodeByKey(key)->value;
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

    V &operator[](const K &key)
    {
        if (t.getNodeByKey(key))
            return t.getNodeByKey(key)->value;
        else
            return *(new V());
    }

    Treap<K, V> &getT()
    {
        return t;
    }
};


#endif //TASK3_MAP_H
