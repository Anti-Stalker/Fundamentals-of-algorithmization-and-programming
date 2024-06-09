#ifndef RBTREE_H
#define RBTREE_H


#ifndef BRTREE_H
#define BRTREE_H

#include <stdexcept>
#include <utility>
#include "QDebug"

template <typename K, typename V>
class RBTree {
protected:
    struct Node {
        std::pair<K, V> kv;
        Node *parent;
        Node *left;
        Node *right;
        bool red;

    };

    Node* _root;
    Node* _nil;

    void initNil(Node* node, Node* parent) {
        node->key = 0;
        node->parent = parent;
        node->left = nullptr;
        node->right = nullptr;
        node->red = 0;
    }

    bool nodeExist(Node *node) {
        return (node != _nil && node != nullptr);
    }

    void deleteFix(Node* node) {
        Node* brother;
        while (node != _root && node->red == 0) {
            if (node == node->parent->left) {
                brother = node->parent->right;
            if (brother->red == 1) {
                brother->red = 0;
                node->parent->red = 1;
                leftRotate(node->parent);
                brother = node->parent->right;
            }

            if (brother->left->red == 0 && brother->right->red == 0) {
                brother->red = 1;
                node = node->parent;
            }
            else {
                if (brother->right->red == 0) {
                    brother->left->red = 0;
                    brother->red = 1;
                    rightRotate(brother);
                    brother = node->parent->right;
                }

                brother->red = node->parent->red;
                node->parent->red = 0;
                brother->right->red = 0;
                leftRotate(node->parent);
                node = _root;
                }
            }
            else {
                brother = node->parent->left;
                if (brother->red == 1) {
                    brother->red = 0;
                    node->parent->red = 1;
                    rightRotate(node->parent);
                    brother = node->parent->left;
                }

                if (brother->right->red == 0 && brother->right->red == 0) {
                    brother->red = 1;
                    node = node->parent;
                }
                else {
                    if (brother->left->red == 0) {
                        brother->right->red = 0;
                        brother->red = 1;
                        leftRotate(brother);
                        brother = node->parent->left;
                     }

                    brother->red = node->parent->red;
                    node->parent->red = 0;
                    brother->left->red = 0;
                    rightRotate(node->parent);
                    node = _root;
                }
            }
        }
        node->red = 0;
    }

    void transplantNode(Node* to, Node* from) {
        if (to->parent == nullptr) {
            _root = from;
        }
        else if (to == to->parent->left) {
            to->parent->left = from;
        }
        else {
            to->parent->right = from;
        }
        from->parent = to->parent;
    }

    void deleteNode(Node* node, K key) {
        Node* nodeToDel = _nil;
        Node* x;
        Node* y;
        while (node != _nil) {
            if (node->kv.first == key) {
                nodeToDel = node;
            }

            if (node->kv.first <= key) {
                node = node->right;
            }
            else {
                node = node->left;
            }
        }

        if (nodeToDel == _nil) {
            throw std::out_of_range("No found key");
            return;
        }

        y = nodeToDel;
        bool y_original_red = y->red;
        if (nodeToDel->left == _nil) {
            x = nodeToDel->right;
            transplantNode(nodeToDel, nodeToDel->right);
        }
        else if (nodeToDel->right == _nil) {
            x = nodeToDel->left;
            transplantNode(nodeToDel, nodeToDel->left);
        }
        else {
            y = getMinNode(nodeToDel->right);
            y_original_red = y->red;
            x = y->right;
            if (y->parent == nodeToDel) {
                x->parent = y;
            }
            else {
                transplantNode(y, y->right);
                y->right = nodeToDel->right;
                y->right->parent = y;
            }

            transplantNode(nodeToDel, y);
            y->left = nodeToDel->left;
            y->left->parent = y;
            y->red = nodeToDel->red;
        }
        delete nodeToDel;
        if (y_original_red == 0) {
            deleteFix(x);
        }
    }

    void insertNode(K key, V value) {
        Node* parent = nullptr;
        Node* child = _root;

        while (child != _nil) {
            parent = child;
            if (key < child->kv.first) {
                child = child->left;
            }
            else if (key > child->kv.first) {
                child = child->right;
            }
            else {
                child->kv.second = value;
                return;
            }
        }

        Node* node = new Node;
        node->kv.first = key;
        node->kv.second = value;
        node->left = _nil;
        node->right = _nil;
        node->red = 1;

        node->parent = parent;
        if (parent == nullptr) {
            _root = node;
        }
        else if (node->kv.first < parent->kv.first) {
            parent->left = node;
        }
        else {
            parent->right = node;
        }

        if (node->parent == nullptr) {
            node->red = 0;
            return;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        insertFix(node);
    }

    void insertFix(Node* node) {
        Node* u;
        while (node->parent->red == 1) {
            if (node->parent == node->parent->parent->right) {
                u = node->parent->parent->left;
                if (u->red == 1) {
                    u->red = 0;
                    node->parent->red = 0;
                    node->parent->parent->red = 1;
                    node = node->parent->parent;
                }
                else {
                    if (node == node->parent->left) {
                        node = node->parent;
                        rightRotate(node);
                    }
                    node->parent->red = 0;
                    node->parent->parent->red = 1;
                    leftRotate(node->parent->parent);
                }
            }
            else {
                u = node->parent->parent->right;

                if (u->red == 1) {
                    u->red = 0;
                    node->parent->red = 0;
                    node->parent->parent->red = 1;
                    node = node->parent->parent;
                }
                else {
                    if (node == node->parent->right) {
                        node = node->parent;
                        leftRotate(node);
                    }
                    node->parent->red = 0;
                    node->parent->parent->red = 1;
                    rightRotate(node->parent->parent);
                }
            }
            if (node == _root) {
                break;
            }
        }
        _root->red = 0;
    }

    Node* searchNode(K key) {
        Node *temp = _root;
        while (nodeExist(temp)) {
            if (temp->kv.first == key) {
                return temp;
            }

            if (key < temp->kv.first) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }

        throw std::out_of_range("No found key");
    }

    Node* getMinNode(Node* node) {
        while (node->left != _nil) {
            node = node->left;
        }
        return node;
    }

    Node* getMaxNode(Node* node) {
        while (node->right != _nil) {
            node = node->right;
        }
        return node;
    }

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != _nil) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            _root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != _nil) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            _root = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    class iterator {
        friend class RBTree;
        Node *cur_node;
        Node *_nil_node;

        iterator(Node *target, Node *leaf) : cur_node(target), _nil_node(leaf) {}

    public:
        iterator &operator++() {
            if (cur_node->right != _nil_node) {
                cur_node = cur_node->right;
                while (cur_node->left != _nil_node) {
                    cur_node = cur_node->left;
                }
            }
            else {
                while (cur_node->parent != nullptr && cur_node == cur_node->parent->right) {
                    cur_node = cur_node->parent;
                }
                cur_node = cur_node->parent;
            }
            return *this;
        }

        std::pair<const K,V> operator*() { return cur_node->kv; }
        std::pair<const K,V> *operator->() { return &cur_node->kv; }
        bool operator==(const iterator &other) { return cur_node == other.cur_node; }
        bool operator!=(const iterator &other) { return cur_node != other.cur_node; }
    };



public:
    RBTree() {
        _nil = new Node;
        _nil->red = 0;
        _nil->left = nullptr;
        _nil->right = nullptr;
        _root = _nil;
    }

    void insert(K key, V value) {
        insertNode(key,value);
    }

    void erase(K key) {
        deleteNode(_root, key);
    }

    bool contains(K key) {
        try {
            searchNode(key);
            return true;
        }
        catch (...) {
            return false;
        }
    }

    iterator begin() {
        Node *lmost = _root;
        while (lmost->left != _nil) {
            lmost = lmost->left;
        }
        return iterator(lmost, _nil);
    }

    iterator end() {
        return iterator(nullptr, _nil);
    }

};


#endif // BRTREE_H


#endif // RBTREE_H
