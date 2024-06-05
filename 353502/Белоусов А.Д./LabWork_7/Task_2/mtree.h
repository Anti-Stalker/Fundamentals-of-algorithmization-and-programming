#ifndef MTREE_H
#define MTREE_H

#include <QString>
#include <QVector>
#include <queue>

struct vertex
{
    QString _key{""};
    unsigned char _height{1};

    vertex *_left{nullptr};
    vertex *_right{nullptr};

    vertex() = default;

    explicit vertex(QString key)
        : _key(key)
    {}
};

unsigned char vheight(vertex *p)
{
    return p->_height;
}

char vbalance(vertex *p)
{
    return vheight(p->_right) - vheight(p->_left);
}

void fixheight(vertex *p)
{
    unsigned char hl = vheight(p->_left);
    unsigned char hr = vheight(p->_right);
    p->_height = (hl > hr ? hl : hr) + 1;
}

vertex *rotateRight(vertex *p)
{
    vertex *q = p->_left;
    p->_left = q->_right;
    q->_right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

vertex *rotateLeft(vertex *q)
{
    vertex *p = q->_right;
    q->_right = p->_left;
    p->_left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

vertex *balance(vertex *p)
{
    fixheight(p);
    if (vbalance(p) == 2) {
        if (vbalance(p->_right) < 0) {
            p->_right = rotateRight(p->_right);
        }
        return rotateLeft(p);
    }
    if (vbalance(p) == -2) {
        if (vbalance(p->_left) > 0) {
            p->_left = rotateLeft(p->_left);
        }
        return rotateRight(p);
    }
    return p;
}

vertex *insert(vertex *node, QString value)
{
    if (!node) {
        return new vertex{value};
    }

    if (value < node->_key) {
        node->_left = insert(node->_left, value);
    } else {
        node->_right = insert(node->_right, value);
    }

    return balance(node);
}

vertex *findMinVertex(vertex *node)
{
    if (node->_left) {
        return findMinVertex(node->_left);
    }

    return node->_left;
}

vertex *removeMinVertex(vertex *node)
{
    if (node->_left == nullptr) {
        return node->_right;
    }
    node->_left = removeMinVertex(node->_left);
    return balance(node);
}

vertex *remove(vertex *node, QString key)
{
    if (!node)
        return nullptr;
    if (node->_key > key) {
        return remove(node->_left, key);
    } else if (node->_key < key) {
        return remove(node->_right, key);
    } else {
        vertex *q = node->_left;
        vertex *r = node->_right;
        delete node;
        if (!r)
            return q;
        vertex *min = findMinVertex(r);
        removeMinVertex(r);
        min->_left = q;
        return balance(min);
    }
    return balance(node);
}

#endif // MTREE_H
