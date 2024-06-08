//
// Created by darina on 6/1/24.
//

#ifndef TASK3_MAP_H
#define TASK3_MAP_H


#include "RBTree.h"


template<typename K, typename V>
class map : public RBTree <K, V> {

    using RBTree<K, V>::insert;

public:
    map()
    {

    }

    int count(const K& key)
    {
        auto t = RBTree<K, V>::Find(RBTree<K, V>::root, key);
        if(t == nullptr)
            return 0;
        return 1;
    }

    bool contains(const K& key)
    {
        auto t = RBTree<K, V>::Find(RBTree<K, V>::root, key);
        if(t == nullptr)
            return false;
        return true;
    }

};


#endif //TASK3_MAP_H
