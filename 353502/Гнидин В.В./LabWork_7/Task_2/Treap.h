//
// Created by volodya-petarda on 5/28/24.
//

#ifndef TREE_TREAP_H
#define TREE_TREAP_H


#include <bits/stdc++.h>
#include "BaseTree.h"

class Treap : public BaseTree{
public:
    struct Node{
        Node *l = nullptr, *r = nullptr;
        int key, priority;
        std::string val;
        Node(int key, std::string val, int priority){
            this->key = key;
            this->val = val;
            this->priority = priority;
        }
    };

    void insert(int key, std::string value) override;

    void erase(int key) override;

    void getTree(std::vector<std::vector<std::string>> &result) override;

    std::string find(int key) override;

    void printTree() override;

private:
    Node *root = nullptr;

    void addToVect(Node *root, std::vector<std::vector<std::string>> &result, std::pair<std::string, std::string> last);

    Node* merge(Node *l, Node *r);

    std::pair<Node*, Node*> split(Node *n, int key);

    void recPrint(Node *n);
};


#endif //TREE_TREAP_H
