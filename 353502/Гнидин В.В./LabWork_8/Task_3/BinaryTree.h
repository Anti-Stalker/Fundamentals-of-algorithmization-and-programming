//
// Created by volodya-petarda on 5/29/24.
//

#ifndef TREE_BINARYTREE_H
#define TREE_BINARYTREE_H

#include <iostream>
#include "Map.h"
#include <vector>

template<typename K, typename V>
class BinaryTree : public Map<K, V>{
public:
    struct Node{
        Node *l = nullptr, *r = nullptr;
        K key;
        V val;
        Node(K key, V val){
            this->key = key;
            this->val = val;
        }
    };

    void insert(K key, V value) override{

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
    };

    void erase(K key) override{
        deleteNode(root, key);
    };

    V find(K key) override{
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
        return "-1";

    };

    void printTree() override{
        std::cout<<"Tree:\n";
        recPrint(root);
    };

    void getTree(std::vector<std::pair<std::pair<K, V>, std::pair<K, V>>> &result) override{
        addToVect(root, result, {-1, "-1"});
    };

private:
    void addToVect(Node *root, std::vector<std::pair<std::pair<K, V>, std::pair<K, V>>> &result, std::pair<K, V> last){
        if(root == nullptr)
            return;
        result.push_back({{last.first, last.second}, {root->key, root->val}});
        addToVect(root->l, result, {(root->key), root->val});
        addToVect(root->r, result, {(root->key), root->val});

    };

    Node *root = nullptr;

    Node* deleteNode(Node *root, K key){
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

    };

    void recPrint(Node *n){
        if(n == nullptr)
            return;
        recPrint(n->l);
        std::cout<<"key: "<<n->key<<" value: "<<n->val<<'\n';
        recPrint(n->r);

    };

    K minimum(Node *n){
        if(n->l == nullptr)
            return n->key;
        return minimum(n->l);

    };
};


#endif //TREE_BINARYTREE_H
