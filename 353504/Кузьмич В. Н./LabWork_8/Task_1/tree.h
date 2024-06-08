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

    void destroyTree(Node*);

    void preOrderToVec(Node*, QVector<QPair<int, QString>> &);

    void postOrderToVec(Node*, QVector<QPair<int, QString>> &);

    void inOrderToVec(Node*, QVector<QPair<int, QString>> &);

    Node* buildBalancedTree(QVector<QPair<int, QString>>&, int, int);

    Node* getRoot();

    Node * insert(QPair<int, QString>);

    void remove(int);

    QVector<QPair<int, QString>> preOrderToVec();

    QVector<QPair<int, QString>> postOrderToVec();

    QVector<QPair<int, QString>> inOrderToVec();

    void balanceTree();

    int searchKeyByStringHelper(Node* node, const QString& value);

    int searchKeyByString(const QString& value);

    void deleteSubtree(Node* node);

    Node* deleteRightSubtreeRecursive(Node* node, int key);

    Node* deleteLeftSubtreeRecursive(Node* node, int key);

    void deleteLeftSubtree(int key);

    void deleteRightSubtree(int key);

    Node* findLCA(Node* node, int key1, int key2);

    int find(int key1, int key2);
};

#endif // TREE_H
