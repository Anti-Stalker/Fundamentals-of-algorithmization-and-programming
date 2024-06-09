#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <QString>
#include <QTextEdit>
struct TreeNode {
    QString data;
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(QString data, int key) : data(data), key(key), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(const QString& data, int key) {
        root = insert(root, data, key);
    }

    void balance() {
        // Реализация балансировки дерева (например, с использованием алгоритма балансировки AVL или Red-Black Tree)
    }

    QString search(int key) const {
        TreeNode* node = search(root, key);
        return node ? node->data : "";
    }

    void remove(int key) {
        root = remove(root, key);
    }

    void printInOrder(QTextEdit* textEdit) const {
        printInOrder(root, textEdit);
    }

    void printPreOrder(QTextEdit* textEdit) const {
        printPreOrder(root, textEdit);
    }

    void printPostOrder(QTextEdit* textEdit) const {
        printPostOrder(root, textEdit);
    }

    int countNodesWithTwoChildren() const {
        return countNodesWithTwoChildren(root);
    }

private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, const QString& data, int key) {
        if (!node) return new TreeNode(data, key);

        if (key < node->key) {
            node->left = insert(node->left, data, key);
        } else if (key > node->key) {
            node->right = insert(node->right, data, key);
        }

        return node;
    }

    TreeNode* search(TreeNode* node, int key) const {
        if (!node || node->key == key) return node;

        if (key < node->key) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

    TreeNode* remove(TreeNode* node, int key) {
        if (!node) return node;

        if (key < node->key) {
            node->left = remove(node->left, key);
        } else if (key > node->key) {
            node->right = remove(node->right, key);
        } else {
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = findMin(node->right);
            node->key = temp->key;
            node->data = temp->data;
            node->right = remove(node->right, temp->key);
        }

        return node;
    }

    TreeNode* findMin(TreeNode* node) const {
        while (node->left) node = node->left;
        return node;
    }

    void printInOrder(TreeNode* node, QTextEdit* textEdit) const {
        if (!node) return;
        printInOrder(node->left, textEdit);
        textEdit->append(QString::number(node->key) + ": " + node->data);
        printInOrder(node->right, textEdit);
    }

    void printPreOrder(TreeNode* node, QTextEdit* textEdit) const {
        if (!node) return;
        textEdit->append(QString::number(node->key) + ": " + node->data);
        printPreOrder(node->left, textEdit);
        printPreOrder(node->right, textEdit);
    }

    void printPostOrder(TreeNode* node, QTextEdit* textEdit) const {
        if (!node) return;
        printPostOrder(node->left, textEdit);
        printPostOrder(node->right, textEdit);
        textEdit->append(QString::number(node->key) + ": " + node->data);
    }

    int countNodesWithTwoChildren(TreeNode* node) const {
        if (!node) return 0;

        int count = 0;
        if (node->left && node->right) {
            count = 1;
        }

        return count + countNodesWithTwoChildren(node->left) + countNodesWithTwoChildren(node->right);
    }
};
#endif // BINARYSEARCHTREE_H
