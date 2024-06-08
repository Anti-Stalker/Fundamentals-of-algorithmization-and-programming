#include "mytree.h"

int MyTree::countRightNodes(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int rightCount = 0;
    if (node->right != nullptr) {
        rightCount = 1 + countRightNodes(node->right);
    }
    return rightCount + countRightNodes(node->left);
}

int MyTree::countRightNodes() {
    return countRightNodes(root);
}
