//
// Created by volodya-petarda on 5/29/24.
//

#include <algorithm>
#include <iostream>
#include "ScapegoatTree.h"

void ScapegoatTree::insert(int key, std::string value) {
    if(root == nullptr) {
        root = new Node(key, value);
        return;
    }

    Node *scapegoat = insertNode(root, key, value);
    if(scapegoat == nullptr)
        return;
    Node *n = punishScapegoat(scapegoat);
    scapegoat->copyFrom(n);
}

ScapegoatTree::Node *ScapegoatTree::insertNode(ScapegoatTree::Node *root, int key, std::string val) {
    Node *scapegoat = nullptr;
    if(root->key < key){
        if(root->r != nullptr)
            scapegoat = insertNode(root->r, key, val);
        else
            root->r = new Node(key, val);
    }
    else if(root->key > key){
        if(root->l != nullptr)
            scapegoat = insertNode(root->l, key, val);
        else
            root->l = new Node(key, val);
    }
    else{
        root->val = val;
    }

    root->size = getSize(root->l) + getSize(root->r) + 1;
    if(isScapegoat(root))
        scapegoat = root;
    return scapegoat;
}

int ScapegoatTree::getSize(ScapegoatTree::Node *node) {
    if(node == nullptr)
        return 0;
    return node->size;
}

bool ScapegoatTree::isScapegoat(ScapegoatTree::Node *n) {
    if(n == nullptr)
        return false;
    int s1 = getSize(n->l), s2 = getSize(n->r);
    if(s1 < s2)
        s1++;
    if(s2 < s1)
        s2++;
    if(s1 + s2 == 0)
        return false;

    double a = std::max((double)s1 / (s1 + s2), (double)s2 / (s1 + s2));
    return (a > alpha);
}

void ScapegoatTree::recPrint(ScapegoatTree::Node *n) {
    if(n == nullptr)
        return;
    recPrint(n->l);
    std::cout<<"key: "<<n->key<<" value: "<<n->val<<" size: "<<n->size<<'\n';
    recPrint(n->r);
}

ScapegoatTree::Node* ScapegoatTree::deleteNode(ScapegoatTree::Node *root, int key) {
    if(root == nullptr)
        return root;

    if (root->key > key){
        root->l = deleteNode(root->l, key);
    }
    else if(root->key < key){
        root->r = deleteNode(root->r, key);
    }
    else if(root->l != nullptr && root->r != nullptr){
        root->key = minimum(root->r);
        root->r = deleteNode(root->r, root->key);
    }
    else{
        if(root->l != nullptr){
            if(this->root == root){
                this->root = root->l;
            }
            root = root->l;
        }
        else if(root->r != nullptr){
            if(this->root == root){
                this->root = root->r;
            }
            root = root->r;
        }
        else{
            if(this->root == root){
                this->root = nullptr;
            }
            root = nullptr;
        }
    }

    if(root != nullptr)
        root->size = getSize(root->l) + getSize(root->r) + 1;

    return root;
}

int ScapegoatTree::minimum(ScapegoatTree::Node *root) {
    if(root->l == nullptr)
        return root->key;
    return minimum(root->l);

}

void ScapegoatTree::printTree() {
    std::cout<<"Tree:\n";
    recPrint(root);
}

void ScapegoatTree::erase(int key) {
    deleteNode(root, key);
}

ScapegoatTree::Node *ScapegoatTree::buildTree(int tl, int tr, const std::vector<Node*> &v) {
    if(tr - tl < 1)
        return nullptr;
    int m = (tl + tr) / 2;

    Node *n = new Node(0, "");
    n->copyFrom(v[m]);
    n->l = buildTree(tl, m, v);
    n->r = buildTree(m + 1, tr, v);
    n->size = getSize(n->l) + getSize(n->r) + 1;
    return n;
}

void ScapegoatTree::pushTreeInVector(ScapegoatTree::Node *root, std::vector<Node *> &v) {
    if(root == nullptr)
        return;
    pushTreeInVector(root->l, v);
    v.push_back(root);
    pushTreeInVector(root->r, v);
}

ScapegoatTree::Node* ScapegoatTree::punishScapegoat(ScapegoatTree::Node *scapegoat) {
    std::vector<Node*> nodes;
    pushTreeInVector(scapegoat, nodes);

    return buildTree(0, nodes.size(), nodes);
}

std::string ScapegoatTree::find(int key) {
    Node *cur = root;
    while(cur != nullptr){
        if(cur->key < key){
            cur = cur->r;
        }
        else if(cur->key > key){
            cur = cur->l;
        }
        else{
            return cur->val;
        }
    }
    return "not_found";
}

void ScapegoatTree::getTree(std::vector<std::vector<std::string>> &result) {
    addToVect(root, result, {"-1", "-1"});
}

void ScapegoatTree::addToVect(ScapegoatTree::Node *root, std::vector<std::vector<std::string>> &result,
                              std::pair<std::string, std::string> last) {
    if(root == nullptr)
        return;
    result.push_back({last.first, last.second, std::to_string(root->key), root->val});
    addToVect(root->l, result, {std::to_string(root->key), root->val});
    addToVect(root->r, result, {std::to_string(root->key), root->val});
}