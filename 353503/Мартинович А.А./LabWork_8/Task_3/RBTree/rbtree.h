#ifndef RBTREE_H
#define RBTREE_H


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
        bool isNil;

        Node(const K &key, const V &value)
            : key(key), value(value), left(nullptr), right(nullptr), parent(nullptr),
              red(1), isNil(false) {}
    };

    Node *_root;

    Node *findNode(const K &key) {

    }

    void swap(Node *&node1, Node *&node2) {
        std::swap(node1->key, node2->key);
        std::swap(node1->value, node2->value);
        std::swap(node1->red, node2->red);
    }

    void rightRotate(Node *&node) {
        swap(node, node->left);

        if (node->left->left != nullptr) {
            node->left->left->parent = node;
        }

        Node *temp = node->right;
        if (temp != nullptr) {
            temp->parent = node->left;
        }

        node->right = node->left;
        node->left = node->left->left;

        node->right->left = node->right->right;
        node->right->right = temp;
    }

    void leftRotate(Node *&node) {
        swap(node, node->right);

        if (node->right->right != nullptr) {
            node->right->right->parent = node;
        }
        Node *temp = node->left;
        if (temp != nullptr) {
            temp->parent = node->right;
        }

        node->left = node->right;
        node->right = node->right->right;

        node->left->right = node->left->left;
        node->left->left = temp;
    }

    void insertNode(Node *&node, K key, V value) {
        if (!nodeExist(_root)) {
            _root = new Node(key, value);
            _root->left = newNil(_root);
            _root->right = newNil(_root);
            _root->red = false;
            return;
        }

        Node *newNode;
        Node *parent = _root;
        while (true) {
            if (key < parent->key) {
                if (!nodeExist(parent->left)) {
                    delete parent->left;
                    newNode = new Node(key, value);
                    newNode->left = newNil(newNode);
                    newNode->right = newNil(newNode);
                    parent->left = newNode;
                    break;
                }
                else {
                    parent = parent->left;
                }

            }
            else if (key > parent->key) {
                if (!nodeExist(parent->right)) {
                    delete parent->right;
                    newNode = new Node(key, value);
                    newNode->left = newNil(newNode);
                    newNode->right = newNil(newNode);
                    parent->right = newNode;
                    break;
                }
                else {
                    parent = parent->right;
                }
            }
            else {
                parent->value = value;
                return;
            }
        }


        newNode->red = true;
        newNode->parent = parent;

        fixAfterInsert(newNode);

    }

    Node *newNil(Node *parent) {
        Node *new_nil = new Node(K(), V());
        new_nil->left = nullptr;
        new_nil->right = nullptr;
        new_nil->isNil = true;
        new_nil->red = false;
        new_nil->parent = parent;
        return new_nil;
    }

    void fixAfterInsert(Node *&node) {

        Node *uncle;
        while ( nodeExist(node->parent) && node->parent->red) {
            if (node->parent == node->parent->parent->left) {
                uncle = node->parent->parent->right;
                if ( nodeExist(uncle) && uncle->red) {
                    node->parent->red = false;
                    uncle->red = false;
                    node->parent->parent->red = true;
                    node = node->parent->parent;
                }
                else {
                    if (node == node->parent->right) {
                        node = node->parent;
                        leftRotate(node);
                        node = node->left;
                    }
                    node->parent->red = false;
                    node->parent->parent->red = true;
                    rightRotate(node->parent->parent);

                }
            }
            else {
                uncle = node->parent->parent->left;
                if ( nodeExist(uncle) && uncle->red) {
                    node->parent->red = false;
                    uncle->red = false;
                    node->parent->parent->red = true;
                    node = node->parent->parent;
                }
                else {
                    if (node == node->parent->left) {
                        node = node->parent;
                        rightRotate(node);
                        node = node->right;
                    }
                    node->parent->red = false;
                    node->parent->parent->red = true;
                    leftRotate(node->parent->parent);
                }
            }
        }
        _root->red = false;
    }

    int getChildCount(Node *node) {
        int count = 0;
        if (nodeExist(node->left))
            count++;
        if (nodeExist(node->right))
            count++;
        return count;
    }


    Node *search(Node *root, K key) {
        if (nodeExist(root)) {

            if (key == root->key) {
                return root;
            }
            if (root->key > key) {
                return search(root->left, key);
            }
            else {
                return search(root->right, key);
            }
        }

        throw std::out_of_range("No key");
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

    void transplantNode(Node *&to, Node *&from) {
        if (to == _root) {
            _root = from;
        }
        else if (to->parent->left == to) {
            to->parent->left = from;
        }
        else {
            to->parent->right = from;
        }
        from->parent = to->parent;
    }

    void remove(const K& key) {
        Node *nodeToDelete = search(_root, key);
        Node *child;
        bool colorDelNode = nodeToDelete->red;
        if (getChildCount(nodeToDelete) < 2) {
            child = getChildOrMock(nodeToDelete);
            transplantNode(nodeToDelete, child);
            qDebug() << child->parent->key;
        }
        else {
            Node *minNode = getMin(nodeToDelete->right);
            nodeToDelete->key = minNode->key;
            nodeToDelete->value = minNode->value;
            colorDelNode = minNode->red;

            child = getChildOrMock(minNode);
            transplantNode(minNode, child);
            qDebug() << child->parent->key;
        }
        if (!colorDelNode) {
            fixRulesAfterRemove(child);
        }
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

    void init() {
        _root = nullptr;
    }

    bool nodeExist(Node *node) {
        return (node != nullptr && !node->isNil);
    }

public:
    RBTree() {
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

#endif // RBTREE_H
