//
// Created by volodya-petarda on 5/29/24.
//

#ifndef TREE_SCAPEGOATTREE_H
#define TREE_SCAPEGOATTREE_H

#include <vector>
#include "BaseTree.h"

class ScapegoatTree : public BaseTree {
public:
    struct Node{
        Node *l = nullptr, *r = nullptr;
        int key, size;
        std::string val;
        Node(int key, std::string val){
            this->key = key;
            this->val = val;
            this->size = 1;
        }
        Node(const Node* n){
            this->key = n->key;
            this->val = n->val;
            this->size = n->size;
            this->l = n->l;
            this->r = n->r;
        }
        void copyFrom(Node *n){
            this->key = n->key;
            this->val = n->val;
            this->size = n->size;
            this->l = n->l;
            this->r = n->r;
        }
    };

    std::string find(int key) override;

    void getTree(std::vector<std::vector<std::string>> &result) override;

    void insert(int key, std::string value) override;

    void erase(int key) override;

    void printTree() override;

private:
    double alpha = 0.75;

    void addToVect(Node *n, std::vector<std::vector<std::string>> &result, std::pair<std::string, std::string> last);

    void recPrint(Node *n);

    bool isScapegoat(Node *n);

    int getSize(Node *node);

    Node* deleteNode(Node *root, int key);

    Node* insertNode(Node *root, int key, std::string val);

    Node* buildTree(int tl, int tr, const std::vector<Node*> &v);

    void pushTreeInVector(Node *root, std::vector<Node*> &v);

    Node* punishScapegoat(Node *scapegoat);

    int minimum(Node *root);

    Node *root;
};


#endif //TREE_SCAPEGOATTREE_H
