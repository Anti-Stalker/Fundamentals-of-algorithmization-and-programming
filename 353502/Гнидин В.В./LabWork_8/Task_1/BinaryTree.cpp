//
// Created by volodya-petarda on 5/29/24.
//

#include "BinaryTree.h"

void BinaryTree::insert(int key, std::string value) {

    if(root == nullptr){
        root = new Node(key, value);
        return;
    }
    Node *cur = root;
    while(true){
        if(cur->key == key){
            cur->val = value;
            break;
        }
        else if(cur->key < key){
            if(cur->r == nullptr){
                cur->r = new Node(key, value);
                break;
            }
            cur = cur->r;
        }
        else{
            if(cur->l == nullptr){
                cur->l = new Node(key, value);
                break;
            }
            cur = cur->l;
        }
    }
}

void BinaryTree::recPrint(BinaryTree::Node *n) {
    if(n == nullptr)
        return;
    recPrint(n->l);
    std::cout<<"key: "<<n->key<<" value: "<<n->val<<'\n';
    recPrint(n->r);
}

void BinaryTree::printTree() {
    std::cout<<"Tree:\n";
    recPrint(root);
}

void BinaryTree::erase(int key) {
    deleteNode(root, key);
}

BinaryTree::Node *BinaryTree::deleteNode(BinaryTree::Node *root, int key) {
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
    return root;
}

int BinaryTree::minimum(BinaryTree::Node *n) {
    if(n->l == nullptr)
        return n->key;
    return minimum(n->l);
}

std::string BinaryTree::find(int key) {
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

void BinaryTree::getTree(std::vector<std::vector<std::string>> &result) {
    addToVect(root, result, {"-1", "-1"});
}

void BinaryTree::addToVect(BinaryTree::Node *root, std::vector<std::vector<std::string>> &result, std::pair<std::string, std::string> last) {
    if(root == nullptr)
        return;
    result.push_back({last.first, last.second, std::to_string(root->key), root->val});
    addToVect(root->l, result, {std::to_string(root->key), root->val});
    addToVect(root->r, result, {std::to_string(root->key), root->val});
}
