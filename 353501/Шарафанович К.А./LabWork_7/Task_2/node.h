#ifndef NODE_H
#define NODE_H

#include <QString>
#include <QDebug>

struct node {
    int key;
    QString str;
    node *left = nullptr;
    node *right = nullptr;

    node(int key, QString s) : key(key), str(s) {}

    // Friend function to allow QDebug to access private members
    friend QDebug operator<<(QDebug dbg, const node &n) {
        dbg.nospace() << "node(" << n.key << ", " << n.str << ", "
                      << "left: " << (n.left ? QString::number(n.left->key) : "nullptr") << ", "
                      << "right: " << (n.right ? QString::number(n.right->key) : "nullptr") << ")";
        return dbg.space();
    }
};

#endif // NODE_H
