#ifndef LAB8TASK3_RBTREE_H
#define LAB8TASK3_RBTREE_H

#include <iostream>

enum Colour {
    black = 0,
    red = 1
};

class Node {
public:
    Node* parent;
    Node* left;
    Node* right;
    Colour colour;
    int data;

    Node() : parent(nullptr), left(nullptr), right(nullptr), colour(black), data(0) {}
    Node(int data, Colour colour) : parent(nullptr), left(nullptr), right(nullptr), colour(colour), data(data) {}
    explicit Node(int data) : parent(nullptr), left(nullptr), right(nullptr), colour(red), data(data) {}

    void insert(Node* node) {
        if (this->data != node->data) {
            if (this->data > node->data) {
                if (this->left != nullptr) {
                    this->left->insert(node);
                } else {
                    this->left = node;
                    node->parent = this;
                }
            } else {
                if (this->right != nullptr) {
                    this->right->insert(node);
                } else {
                    this->right = node;
                    node->parent = this;
                }
            }
        }
    }
};

class RBTree {
    Node* root;

public:
    RBTree() : root(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node(data);
        if (root == nullptr) {
            root = new Node(data, black);
        } else {
            root->insert(newNode);
            balanceTree(root, newNode);
        }
        root->colour = black;
    }

    Node* search(int data) {
        return search(root, data);
    }

    void remove(int data) {
        Node* node = search(data);
        if (node != nullptr) {
            remove(node);
        }
    }

private:
    Node* search(Node* root, int data) {
        if (root == nullptr || root->data == data) {
            return root;
        }
        if (data < root->data) {
            return search(root->left, data);
        }
        return search(root->right, data);
    }

    void balanceTree(Node* root, Node* newNode) {
        Node* uncle;
        while (newNode->parent != nullptr && newNode->parent->colour == red) {
            if (newNode->parent == newNode->parent->parent->left) {
                uncle = newNode->parent->parent->right;
                if (uncle != nullptr && uncle->colour == red) {
                    newNode->parent->colour = black;
                    uncle->colour = black;
                    newNode->parent->parent->colour = red;
                    newNode = newNode->parent->parent;
                } else {
                    if (newNode == newNode->parent->right) {
                        newNode = newNode->parent;
                        leftRotate(root, newNode);
                    }
                    newNode->parent->colour = black;
                    newNode->parent->parent->colour = red;
                    rightRotate(root, newNode->parent->parent);
                }
            } else {
                uncle = newNode->parent->parent->left;
                if (uncle != nullptr && uncle->colour == red) {
                    newNode->parent->colour = black;
                    uncle->colour = black;
                    newNode->parent->parent->colour = red;
                    newNode = newNode->parent->parent;
                } else {
                    if (newNode == newNode->parent->left) {
                        newNode = newNode->parent;
                        rightRotate(root, newNode);
                    }
                    newNode->parent->colour = black;
                    newNode->parent->parent->colour = red;
                    leftRotate(root, newNode->parent->parent);
                }
            }
        }
        root->colour = black;
    }

    void leftRotate(Node* root, Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* root, Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right != nullptr) x->right->parent = y;
        x->parent = y->parent;
        if (y->parent == nullptr) root = x;
        else if (y == y->parent->right) y->parent->right = x;
        else y->parent->left = x;
        x->right = y;
        y->parent = x;
    }

    void remove(Node* z) {
        Node* y = z;
        Node* x;
        Colour yOriginalColour = y->colour;

        if (z->left == nullptr) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nullptr) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            yOriginalColour = y->colour;
            x = y->right;
            if (y->parent == z) {
                if (x != nullptr) x->parent = y;
            } else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->colour = z->colour;
        }

        if (yOriginalColour == black) {
            removeFixup(x);
        }

        delete z;
    }

    void removeFixup(Node* x) {
        Node* w;
        while (x != root && (x == nullptr || x->colour == black)) {
            if (x == x->parent->left) {
                w = x->parent->right;
                if (w->colour == red) {
                    w->colour = black;
                    x->parent->colour = red;
                    leftRotate(root, x->parent);
                    w = x->parent->right;
                }
                if ((w->left == nullptr || w->left->colour == black) && (w->right == nullptr || w->right->colour == black)) {
                    w->colour = red;
                    x = x->parent;
                } else {
                    if (w->right == nullptr || w->right->colour == black) {
                        if (w->left != nullptr) w->left->colour = black;
                        w->colour = red;
                        rightRotate(root, w);
                        w = x->parent->right;
                    }
                    w->colour = x->parent->colour;
                    x->parent->colour = black;
                    if (w->right != nullptr) w->right->colour = black;
                    leftRotate(root, x->parent);
                    x = root;
                }
            } else {
                w = x->parent->left;
                if (w->colour == red) {
                    w->colour = black;
                    x->parent->colour = red;
                    rightRotate(root, x->parent);
                    w = x->parent->left;
                }
                if ((w->right == nullptr || w->right->colour == black) && (w->left == nullptr || w->left->colour == black)) {
                    w->colour = red;
                    x = x->parent;
                } else {
                    if (w->left == nullptr || w->left->colour == black) {
                        if (w->right != nullptr) w->right->colour = black;
                        w->colour = red;
                        leftRotate(root, w);
                        w = x->parent->left;
                    }
                    w->colour = x->parent->colour;
                    x->parent->colour = black;
                    if (w->left != nullptr) w->left->colour = black;
                    rightRotate(root, x->parent);
                    x = root;
                }
            }
        }
        if (x != nullptr) x->colour = black;
    }

    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr) root = v;
        else if (u == u->parent->left) u->parent->left = v;
        else u->parent->right = v;
        if (v != nullptr) v->parent = u->parent;
    }

    Node* minimum(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};

#endif //LAB8TASK3_RBTREE_H
