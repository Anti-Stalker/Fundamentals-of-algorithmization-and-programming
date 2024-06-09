//
// Created by volodya-petarda on 5/28/24.
//

#ifndef TREE_BASETREE_H
#define TREE_BASETREE_H
#include <vector>
#include <string>


class BaseTree {
public:
    virtual void insert(int key, std::string value){};
    virtual void erase(int key){};
    virtual std::string find(int key){};
    virtual void printTree(){};
    virtual void getTree(std::vector<std::vector<std::string>> &result) { } ;

};


#endif //TREE_BASETREE_H
