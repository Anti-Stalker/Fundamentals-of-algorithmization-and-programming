//
// Created by darina on 6/1/24.
//

#ifndef TASK3_SET_H
#define TASK3_SET_H

#include "RBTree.h"

template<typename K>
class set : public RBTree<K, char> {

    char& operator[](const K& key)
    {
        char c = 'l';
        return c;
    }

public:
    set()
    {

    }

    void insert(const K& key)
    {
        RBTree<K, char>::insert(key, '1');
    }

    bool find(const K& key)
    {
        auto t = RBTree<K, char>::Find(RBTree<K, char>::root, key);
        if(t == nullptr)
            return false;
        return true;
    }
};


#endif //TASK3_SET_H
