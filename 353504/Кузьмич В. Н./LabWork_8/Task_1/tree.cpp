#include "tree.h"

Tree::Tree() : root(nullptr) {}

Tree::~Tree() {
    destroyTree(root);
}

Node *Tree::push(Node *node, QPair<int, QString> pair) {
    if (node == nullptr) return new Node(pair.first, pair.second);
    int key = pair.first;
    if (key < node->key) node->left = push(node->left, pair);
    else if (key > node->key) node->right = push(node->right, pair);
    return node;
}

Node *Tree::pop(Node *node, int key) {
    if (node == nullptr) return nullptr;
    if (key < node->key)node->left = pop(node->left, key);
    else if (key > node->key) node->right = pop(node->right, key);
    else if (node->left != nullptr && node->right != nullptr){
        node->key = findMin(node->right)->key;
        node->right = pop(node->right, key);
    }
    else {
        if (node->left != nullptr) node = node->left;
        else if (node->right != nullptr) node = node->right;
        else node = nullptr;
    }
    return node;
}

Node *Tree::findMin(Node *node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void Tree::destroyTree(Node *node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void Tree::preOrderToVec(Node *node, QVector<QPair<int, QString>> & vec) {
    if (node != nullptr) {
        vec.push_back(QPair<int, QString>(node->key, node->str));
        preOrderToVec(node->left, vec);
        preOrderToVec(node->right, vec);
    }
}

void Tree::postOrderToVec(Node *node, QVector<QPair<int, QString>> & vec) {
    if (node != nullptr) {
        postOrderToVec(node->left, vec);
        postOrderToVec(node->right, vec);
        vec.push_back(QPair<int, QString>(node->key, node->str));
    }
}

void Tree::inOrderToVec(Node *node, QVector<QPair<int, QString>> & vec) {
    if (node != nullptr) {
        inOrderToVec(node->left, vec);
        vec.push_back(QPair<int, QString>(node->key, node->str));
        inOrderToVec(node->right, vec);
    }
}

Node *Tree::insert(QPair<int, QString> pair) {
    root = push(root, pair);
    return root;
}

void Tree::remove(int key) {
    root = pop(root, key);
}

QVector<QPair<int, QString>> Tree::preOrderToVec() {
    QVector<QPair<int, QString>> vec;
    preOrderToVec(root, vec);
    return vec;
}

QVector<QPair<int, QString>> Tree::postOrderToVec() {
    QVector<QPair<int, QString>> vec;
    postOrderToVec(root, vec);
    return vec;
}

QVector<QPair<int, QString>> Tree::inOrderToVec() {
    QVector<QPair<int, QString>> vec;
    inOrderToVec(root, vec);
    return vec;
}

Node* Tree::getRoot() {
    return root;
}

int Tree::searchKeyByString(const QString& value) {
    return searchKeyByStringHelper(root, value);
}

int Tree::searchKeyByStringHelper(Node* node, const QString& value) {
    if (node == nullptr) {
        return -1;
    }
    if (node->str == value) {
        return node->key;
    }
    int leftKey = searchKeyByStringHelper(node->left, value);
    if (leftKey != -1) {
        return leftKey;
    }
    int rightKey = searchKeyByStringHelper(node->right, value);
    if (rightKey != -1) {
        return rightKey;
    }
    return -1;
}

Node* Tree::buildBalancedTree(QVector<QPair<int, QString>>& sortedPairs, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    Node* newNode = new Node(sortedPairs[mid].first, sortedPairs[mid].second);
    newNode->left = buildBalancedTree(sortedPairs, start, mid - 1);
    newNode->right = buildBalancedTree(sortedPairs, mid + 1, end);
    return newNode;
}

void Tree::balanceTree() {
    QVector<QPair<int, QString>> sortedPairs;
    inOrderToVec(root, sortedPairs);
    root = buildBalancedTree(sortedPairs, 0, sortedPairs.size() - 1);
}

Node* Tree::deleteLeftSubtreeRecursive(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = deleteLeftSubtreeRecursive(node->left, key);
    } else if (key > node->key) {
        node->right = deleteLeftSubtreeRecursive(node->right, key);
    } else {
        // Ключ найден, удаляем левое поддерево
        deleteSubtree(node->left);
        node->left = nullptr;
    }

    return node;
}

Node* Tree::deleteRightSubtreeRecursive(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = deleteRightSubtreeRecursive(node->left, key);
    } else if (key > node->key) {
        node->right = deleteRightSubtreeRecursive(node->right, key);
    } else {
        // Ключ найден, удаляем правое поддерево
        deleteSubtree(node->right);
        node->right = nullptr;
    }

    return node;
}

void Tree::deleteSubtree(Node* node) {
    if (node == nullptr) {
        return;
    }

    deleteSubtree(node->left);
    deleteSubtree(node->right);
    delete node;
}

void Tree::deleteLeftSubtree(int key) {
    root = deleteLeftSubtreeRecursive(root, key);
}

void Tree::deleteRightSubtree(int key) {
    root = deleteRightSubtreeRecursive(root, key);
}

Node* Tree::findLCA(Node* node, int key1, int key2) {
    if (node == nullptr) {
        return nullptr;
    }
    if (key1 < node->key && key2 < node->key) {
        return findLCA(node->left, key1, key2);
    }
    else if (key1 > node->key && key2 > node->key) {
        return findLCA(node->right, key1, key2);
    }
    else {
        return node;
    }
}

int Tree::find(int key1, int key2){
    return findLCA(root, key1, key2)->key;
}
