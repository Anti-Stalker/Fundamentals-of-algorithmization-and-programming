//
// Created by volodya-petarda on 5/29/24.
//

#ifndef TREE_BINARYTREE_H
#define TREE_BINARYTREE_H

#include <iostream>
#include "BaseTree.h"
#include <vector>

class BinaryTree : public BaseTree{
public:
    struct Node{
        Node *l = nullptr, *r = nullptr;
        int key;
        std::string val;
        Node(int key, std::string val){
            this->key = key;
            this->val = val;
        }
    };

    void insert(int key, std::string value) override;

    void erase(int key) override;

    std::string find(int key) override;

    void printTree() override;

    void getTree(std::vector<std::vector<std::string>> &result) override;

private:
    void addToVect(Node *root, std::vector<std::vector<std::string>> &result, std::pair<std::string, std::string> last);

    Node *root = nullptr;

    Node* deleteNode(Node *root, int key);

    void recPrint(Node *n);

    int minimum(Node *n);
};


#endif //TREE_BINARYTREE_H
