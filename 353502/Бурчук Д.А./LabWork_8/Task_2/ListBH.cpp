#include "ListBH.h"
#include <queue>
#include <iostream>

ListBH::ListBH(int *array, int size) : root(nullptr) {
    for (int i = 0; i < size; ++i) {
        add(array[i]);
    }
    normalize();
}

void ListBH::normalize() {
    normalize(root);
}

void ListBH::normalize(Node *node) {
    if (!node) return;

    std::queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        Node *current = q.front();
        q.pop();

        compare(current);

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

void ListBH::compare(Node *node) {
    if (!node) return;

    Node *maxNode = node;
    if (node->left && node->left->value > maxNode->value) {
        maxNode = node->left;
    }
    if (node->right && node->right->value > maxNode->value) {
        maxNode = node->right;
    }

    if (maxNode != node) {
        std::swap(node->value, maxNode->value);
        compare(maxNode);
    }
}

void ListBH::add(int num) {
    if (!root) {
        root = new Node(num);
        return;
    }

    Node *node = new Node(num);
    Node *tmp = root;
    while (tmp->right != nullptr) tmp = tmp->right;
    tmp->right = node;
    node->left = root;
}


void ListBH::print() {
    if (!root) {
        std::cout << "Heap is empty." << std::endl;
        return;
    }


    Node *tmp = root;
    while (tmp->right != nullptr)  {
        std::cout << tmp << ' ';
        tmp = tmp->right;
    }
}
