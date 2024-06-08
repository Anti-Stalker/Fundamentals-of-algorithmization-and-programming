#ifndef TREE_H
#define TREE_H
#include "node.h"
#include"QTreeView"
#include <queue>
class Tree
{
public:
    Tree();
    void insert(Node*&,int,QString );
    Node* create(QString ,int);
    int height(Node*);
    int balance(Node *);
    Node* rot_right(Node*);
    Node* rot_left(Node*);
    QString find (Node*,int);
    Node* del(Node*,int);
    Node *fmin(Node *);
    void pr_ord(Node* );
    void p_ord(Node*);
    void in_ord(Node *n);
    QVector< QPair <QString,int>> pair1;
    QVector< QPair <QString,int>> pair2;
    QVector< QPair <QString,int>> pair3;
    Node* n1();
    void ins(int,QString);
    void count();
    QVector <QString> ret();
private :
    int h;
    Node *n2=nullptr;
    QVector <QString> l;

};

#endif // TREE_H
