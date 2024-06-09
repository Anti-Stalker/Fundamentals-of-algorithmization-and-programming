#ifndef BRTREE_H
#define BRTREE_H

#include <stdexcept>
#include <utility>
#include "QDebug"


template <typename K, typename V>
class RBTree {
protected:
    struct Node {

        K key;
        V value;

        Node *left;
        Node *right;
        Node *parent;
        bool red;

        Node(const K &key, const V &value)
            : key(key), value(value), left(nullptr), right(nullptr), parent(nullptr),
              red(0) {}
    };

    Node *_root;
    Node *_nil;


    Node *findNode(const K &key) {

    }

    void swap(Node *&node1, Node *&node2) {
        std::swap(node1->value, node2->value);
        std::swap(node1->key, node2->key);
    }

    void balanceTree(Node *&newNode) {
        Node* uncle;
        while (newNode->parent->red) {
            if (newNode->parent == newNode->parent->parent->left) {
                uncle = newNode->parent->parent->right;
                if (uncle->red) {
                    newNode->parent->red = false;
                    uncle->red = false;
                    newNode->parent->parent->red = true;
                    newNode = newNode->parent->parent;
                }
                else {
                    if (newNode == newNode->parent->right) {
                        newNode = newNode->parent;
                        leftRotate(newNode);
                    }
                    newNode->parent->red = false;
                    newNode->parent->parent->red = true;
                    rightRotate(newNode->parent->parent);
                }
            }
            else {
                uncle = newNode->parent->parent->left;
                if (uncle->red) {
                    newNode->parent->red = false;
                    uncle->red = false;
                    newNode->parent->parent->red = true;
                    newNode = newNode->parent->parent;
                }
                else {
                    if (newNode == newNode->parent->left) {
                        newNode = newNode->parent;
                        rightRotate(newNode);
                    }
                    newNode->parent->red = false;
                    newNode->parent->parent->red = true;
                    leftRotate(newNode->parent->parent);
                }
            }
            _root->red = false;
        }

    }

    void rightRotate(Node *&node) {
        swap(node, node->left);
        Node *temp = node->right;
        node->right = node->left;
        node->left = node->right->left;

        node->right->left = node->right->right;
        node->right->right = temp;
    }

    void leftRotate(Node *&node) {
        swap(node, node->right);
        Node *temp = node->left;
        node->left = node->right;
        node->right = node->left->right;
        node->left->right = node->left->left;
        node->left->left = temp;
    }

    void insertNode(Node *&node, K key, V value) {
        Node *currentNode = _root;
        Node *parent = nullptr;
        while (nodeExist(currentNode)) {
            parent = currentNode;
            if (value < currentNode->value)
                currentNode = currentNode->left;
            else
                currentNode = currentNode->right;
        }

        Node *newNode = new Node(K(), V());
        createNode(newNode, key, value);
        newNode->parent = parent;
        if (parent == nullptr) {
            _root = newNode;
            _root->red = false;
        }
        else {
            if (value < parent->value)
                parent->left = newNode;
            else
                parent->right = newNode;
            balanceTree(newNode);
        }

        qDebug() << "Root: " << _root->value;
        qDebug() << "left: " << _root->left->value;
        qDebug() << "right: " << _root->right->value;

    }

    int getChildCount(Node *node) {
        int count = 0;
        if (nodeExist(node->left))
            count++;
        if (nodeExist(node->right))
            count++;
        return count;
    }

    void transplantNode(Node *&toNode, Node *&fromNode) {
        if (toNode == _root)
            _root = fromNode;
        else if (toNode->parent->left == toNode)
            toNode->parent->left = fromNode;
        else
            toNode->parent->right = fromNode;
        // ???????
        toNode->parent == fromNode->parent;
    }

    void remove(K key) {
        Node *nodeToDelete = search(_root, key);
        Node *child;
        bool colorDelNode = nodeToDelete->red;
        if (getChildCount(nodeToDelete) < 2) {
            child = getChildOrMock(nodeToDelete);
            transplantNode(nodeToDelete, child);
        }
        else {
            Node *minNode = getMin(nodeToDelete->right);
            nodeToDelete->key = minNode->key;
            nodeToDelete->value = minNode->value;
            colorDelNode = minNode->red;
            child = getChildOrMock(minNode);
            transplantNode(minNode, child);
        }
        if (!colorDelNode) {
            fixRulesAfterRemove(child);
        }
    }

    Node *search(Node *root, K key) {
        if (nodeExist(root)) {

            if (key == root->key) {
                qDebug() << root->value;
                return root;
            }
            if (root->key > key) {
                return search(root->left, key);
            }
            else {
                return search(root->right, key);
            }
        }


    }

    Node *getMin(Node *root) {
        if (nodeExist(root->left)) {
            return getMin(root->left);
        }
        else {
            return root;
        }
    }

    Node *getMax(Node *root) {
        if (nodeExist(root->right)) {
            return getMax(root->right);
        }
        else {
            return root;
        }
    }

    Node* getChildOrMock(Node *node) {
        return nodeExist(node->left)?node->left:node->right;
    }

    void fixRulesAfterRemove(Node *&node) {
        while (node != _root && !node->red) {
            Node *brother;
            if (node == node->parent->left) {
                brother = node->parent->right;
                if (brother->red) {
                    brother->red = false;
                    node->parent->red = true;
                    leftRotate(node->parent);
                    brother = node->parent->right;
                }
                if (!brother->left->red && !brother->right->red) {
                    brother->red = true;
                    node = node->parent;
                }
                else {
                    if (!brother->right->red ) {
                        brother->left->red = true;
                        brother->red = true;
                        rightRotate(brother);
                        brother = node->parent->right;
                    }
                    brother->red = node->parent->red;
                    node->parent->red = false;
                    brother->right->red = false;
                    leftRotate(node->parent);
                    node = _root;
                }
            }
            else {
                brother = node->parent->left;
                if (brother->red) {
                    brother->red = false;
                    node->parent->red = true;
                    rightRotate(node->parent);
                    brother = node->parent->left;
                }
                if (!brother->right->red && !brother->left->red) {
                    brother->red = true;
                    node = node->parent;
                }
                else {
                    if (!brother->left->red ) {
                        brother->right->red = true;
                        brother->red = true;
                        leftRotate(brother);
                        brother = node->parent->left;
                    }
                    brother->red = node->parent->red;
                    node->parent->red = false;
                    brother->left->red = false;
                    rightRotate(node->parent);
                    node = _root;
                }
            }

        }
        node->red = false;
    }

    void clear(Node *root) {

    }

    void createNode(Node *&node, K key, V value) {
        node->key = key;
        node->value = value;
        node->left = _nil;
        node->right = _nil;
        node->parent = nullptr;
        node->red = true;

    }

    void init() {
        _nil = new Node(K(), V());
        _nil->left = nullptr;
        _nil->right = nullptr;
        _nil->red = false;
    }

    bool nodeExist(Node *node) {
        return (node != _nil && node != nullptr);
    }

public:
    RBTree() : _root(nullptr) {
        init();
    }
    ~RBTree() {

    }

    void clear() {

    }

    bool contains(const K &key) {
        return nodeExist(search(_root, key));
    }

    V get(const K &key) {
        return search(_root, key)->value;
    }

    void insert(const K &key, const V &val) {
        insertNode(_root, key, val);
    }

    void erase(const K &key) {
        remove(key);
    }

};




#endif // BRTREE_H
