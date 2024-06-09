//
// Created by volodya-petarda on 5/28/24.
//

#ifndef TREE_BASETREE_H
#define TREE_BASETREE_H
#include <vector>
#include <string>


template<typename K, typename V>
class Map {
public:
    virtual void insert(K key, V value){};
    virtual void erase(K key){};
    virtual V find(K key){};
    virtual void printTree(){};
    virtual void getTree(std::vector<std::pair<std::pair<K, V>, std::pair<K, V>>> &result) { } ;

};


#endif //TREE_BASETREE_H
