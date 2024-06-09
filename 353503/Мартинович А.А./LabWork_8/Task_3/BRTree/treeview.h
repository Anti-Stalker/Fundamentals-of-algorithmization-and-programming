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

    void printView(Node *node, int level = 0) {
        if (!nodeExist(node))
            return;

        printView(node->right, level + 1);
        append(QString("\t").repeated(level) + "|-" + QString::number(node->kv.first) + ": "
               + QString::number(node->kv.second) + ((node->red)?"RED":"BLACK"));
        printView(node->left, level + 1);
    };


    void UpdateView() {
        QTextEdit::clear();
        printView(_root);

    };

};

#endif // TREEVIEW_H
