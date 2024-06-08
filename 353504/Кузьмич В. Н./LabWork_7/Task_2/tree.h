#ifndef TREE_H
#define TREE_H

#include <QVector>
#include <QPair>
#include <Node.h>

class Tree {
public:
    Tree();
    ~Tree();

    Node* root;

    Node* push(Node*, QPair<int, QString>);

    Node* pop(Node*, int);

    Node* findMin(Node*);

    Node* findNode(Node*, int);

    void destroyTree(Node*);

    void preOrderToVec(Node*, QVector<QPair<int, QString>> &);

    void postOrderToVec(Node*, QVector<QPair<int, QString>> &);

    void inOrderToVec(Node*, QVector<QPair<int, QString>> &);

    Node* buildBalancedTree(QVector<QPair<int, QString>>&, int, int);

    Node* getRoot();

    Node * insert(QPair<int, QString>);

    int search(int);

    void remove(int);

    QVector<QPair<int, QString>> preOrderToVec();

    QVector<QPair<int, QString>> postOrderToVec();

    QVector<QPair<int, QString>> inOrderToVec();

    QString searchStringByKey(int);

    void balanceTree();
};

#endif // TREE_H
