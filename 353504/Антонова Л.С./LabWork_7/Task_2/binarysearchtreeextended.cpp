#include "binarysearchtreeextended.h"

void BinarySearchTreeExtended::swapMinMax() {
    Node* minNode = findMin(getRoot());
    Node* maxNode = findMax(getRoot());

    if (minNode && maxNode) {
        QString temp = minNode->value;
        minNode->value = maxNode->value;
        maxNode->value = temp;
    }
}

Node* BinarySearchTreeExtended::findMin(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    while (node->left) {
        node = node->left;
    }

    return node;
}

Node* BinarySearchTreeExtended::findMax(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    while (node->right) {
        node = node->right;
    }

    return node;
}
