#ifndef TREEVIEW_H
#define TREEVIEW_H


#include <QTextEdit>
#include "rbtree.h"

class TreeView : public QTextEdit, public RBTree<int, double>
{
public:
    TreeView(QWidget *parent = 0) : QTextEdit(parent), RBTree<int, double>() {
        setReadOnly(true);
    }

    void printView(Node *root, int level = 0) {
        if (root == nullptr)
            return;

        printView(root->right, level + 1);
        append(QString("\t").repeated(level) + "| " + QString::number(root->key) + ": "
               + QString::number(root->value) + ((root->red)?"R":"B")
               + ((root->parent)?QString::number(root->parent->key):""));
        printView(root->left, level + 1);
    };


    void UpdateView() {
        QTextEdit::clear();
        printView(_root);

    };

};

#endif // TREEVIEW_H
