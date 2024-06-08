#ifndef BST_H
#define BST_H
#include <QString>
#include <QTextStream>
#include <QVector>
#include "node.h"
class BST {
private:
    Node* root;



    Node* insert(Node* node, int key, QString data) {
        if (!node) return new Node(key, data);
        if (key < node->key) {
            node->left = insert(node->left, key, data);
        } else if (key > node->key) {
            node->right = insert(node->right, key, data);
        }
        // Обновляем корень, если вставка происходит в корень или если корень меняется
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int key) {
        if (!root) return root;
        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    Node* find(Node* node, int key) {
        if (!node || node->key == key)
            return node;
        if (node->key < key)
            return find(node->right, key);
        return find(node->left, key);
    }

    void preOrder(Node* node, QTextStream& out) {
        if (node) {
            out << node->key << ": " << node->data << "\n";
            preOrder(node->left, out);
            preOrder(node->right, out);
        }
    }

    void inOrder(Node* node, QTextStream& out) {
        if (node) {
            inOrder(node->left, out);
            out << node->key << ": " << node->data << "\n";
            inOrder(node->right, out);
        }
    }

    void postOrder(Node* node, QTextStream& out) {
        if (node) {
            postOrder(node->left, out);
            postOrder(node->right, out);
            out << node->key << ": " << node->data << "\n";
        }
    }
    int countNodesWithSingleChild(Node* node) {
        if (!node) return 0;

        int count = 0;
        if ((node->left && !node->right) || (!node->left && node->right)) {
            count = 1;
        }

        count += countNodesWithSingleChild(node->left);
        count += countNodesWithSingleChild(node->right);

        return count;
    }
public:
    BST() : root(nullptr) {}

    void insert(int key, QString data) {
        root = insert(root, key, data);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    QString find(int key) {
        Node* result = find(root, key);
        return result ? result->data : "Not found";
    }

    QString preOrder() {
        QString result;
        QTextStream out(&result);
        preOrder(root, out);
        return result;
    }

    QString inOrder() {
        QString result;
        QTextStream out(&result);
        inOrder(root, out);
        return result;
    }

    QString postOrder() {
        QString result;
        QTextStream out(&result);
        postOrder(root, out);
        return result;
    }
    int countNodesWithSingleChild() {
        return countNodesWithSingleChild(root);
    }
};
#endif // BST_H
