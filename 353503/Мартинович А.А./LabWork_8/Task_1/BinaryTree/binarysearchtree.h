#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "cstdint"
#include "stdexcept"
#include "QDebug"
#include "cmath"

class KeyExistsException : public std::exception {
public:
    const char* what() const throw () {
        return "Key already exists in the tree";
    }
};

template <typename T>
class BinarySearchTree
{
protected:
    struct Node {
        int64_t key;
        T value;
        Node* left;
        Node* right;
    };

    Node *_root;

    //Private functions

    Node* createNode(int64_t key, T value) {
        Node* newNode = new Node();
        if (!newNode) {
            throw std::bad_alloc();
            return nullptr;
        }

        newNode->key = key;
        newNode->value = value;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    void insertNode(Node *&root, int64_t key, T value) {
        if (root == nullptr) {
            root = createNode(key, value);
            return;
        }

        if (key < root->key)
            insertNode(root->left, key, value);
        else if (key > root->key)
            insertNode(root->right, key, value);
        else
            throw KeyExistsException();

    }

    void deleteNode(Node *&root, int key) {
        if (root == nullptr) {
            throw std::bad_alloc();
            return;
        }
        else if (key < root->key)
            deleteNode(root->left, key);
        else if (key > root->key)
            deleteNode(root->right, key);
        else {
            if (root->left == nullptr || root->right == nullptr)
                root = (root->left == nullptr)?root->right:root->left;
            else {
                Node *maxInLeft = getMax(root->left);
                root->key = maxInLeft->key;
                root->value = maxInLeft->value;
                deleteNode(root->left, maxInLeft->key);
            }
        }

    }

    Node *searchValue (Node *root, int64_t key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->key == key) {
            return root;
        }
        return (key < root->key)?searchValue(root->left, key):searchValue(root->right, key);
    }

    Node *getMin(Node *root) {
        if (root == nullptr)
            throw KeyExistsException();
        if (root->left == nullptr)
            return root;
        return getMin(root->left);
    }

    Node *getMax(Node *root) {
        if (root == nullptr)
            throw KeyExistsException();
        if (root->right == nullptr)
            return root;
        return getMax(root->right);
    }

    void symmetricPrint(Node* root) {
        if (root == nullptr)
            return;

        symmetricPrint(root->left);
        qDebug() << root->height << root->key;
        symmetricPrint(root->right);
    }

    void reversePrint(Node* root) {
        if (root == nullptr)
            return;
        reversePrint(root->left);
        reversePrint(root->right);
        qDebug() << root->key;
    }

    void straightPrint(Node *root) {
        if (root == nullptr)
            return;
        qDebug() << root->key;
        straightPrint(root->left);
        straightPrint(root->right);
    }

    int64_t getHeight(Node *root) {
        return (root==nullptr)?-1:root->height;
    }

    int64_t getBalance(Node *root) {
        return (root==nullptr)?0:getHeight(root->right)-getHeight(root->left);
    }

    void swap(Node *&node1, Node *&node2) {
        std::swap(node1->value, node2->value);
        std::swap(node1->key, node2->key);
    }

    void rightRotate(Node *&root) {
        swap(root, root->left);
        Node *temp = root->right;
        root->right = root->left;
        root->left = root->right->left;

        root->right->left = root->right->right;
        root->right->right = temp;
        updateHeight(root->right);
        updateHeight(root);
    }

    void leftRotate(Node *&root) {
        swap(root, root->right);
        Node *temp = root->left;
        root->left = root->right;
        root->right = root->left->right;

        root->left->right = root->left->left;
        root->left->left = temp;
        updateHeight(root->left);
        updateHeight(root);
    }

public:

    BinarySearchTree() : _root(nullptr) {};

    void insert(int64_t key, T value) {
        insertNode(_root, key, value);
    }

    void del(int64_t key) {
        deleteNode(_root, key);
    }

    T& search(int64_t key) {
        return searchValue(_root, key)->value;
    }

    T& getMinByKey() {
        return getMin(_root)->value;
    }

    T& getMaxByKey() {
        return getMax(_root)->value;
    }

    void printReverse() {
        reversePrint(_root);

    }

    void printSymmentric() {
        symmetricPrint(_root);
    }

    void printStraight() {
        straightPrint(_root);
    }
};

#endif // BINARYSEARCHTREE_H
