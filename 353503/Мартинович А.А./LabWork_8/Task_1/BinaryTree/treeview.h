#ifndef TREEVIEW_H
#define TREEVIEW_H

#include "QTextEdit"
#include "binarysearchtree.h"

class TreeView : public QTextEdit, public BinarySearchTree<QString>
{
public:
    TreeView(QWidget *parent = 0) : QTextEdit(parent), BinarySearchTree() {
        setReadOnly(true);
    }

    void printView(Node *root, int level = 0) {
        if (root == nullptr)
            return;

        printView(root->right, level + 1);
        append(QString("\t").repeated(level) + "|-" + QString::number(root->key) + ": " + root->value);
        printView(root->left, level + 1);
    };


    void UpdateView() {
        clear();
        printView(_root);

    };

    void swapMaxMin() {
        QString temp = getMin(_root)->value;
        getMin(_root)->value = getMax(_root)->value;
        getMax(_root)->value = temp;
        UpdateView();

    };
};

#endif // TREEVIEW_H
