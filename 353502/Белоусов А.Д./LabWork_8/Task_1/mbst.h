    #ifndef MTREE_H
#define MTREE_H

#include <QString>
#include <QVector>
#include <queue>

template<class T>
struct vertex
{
    T _key{""};
    unsigned char _height{1};

    vertex *_left{nullptr};
    vertex *_right{nullptr};

    vertex() = default;

    explicit vertex(T key)
        : _key(key)
    {}

    ~vertex()
    {
        if (_left) {
            delete _left;
        }

        if (_right) {
            delete _right;
        }
    }
};

template<class T>
unsigned char vheight(vertex<T> *p)
{
    return p->_height;
}

template<class T>
char vbalance(vertex<T> *p)
{
    return vheight(p->_right) - vheight(p->_left);
}

template<class T>
void fixheight(vertex<T> *p)
{
    unsigned char hl = vheight(p->_left);
    unsigned char hr = vheight(p->_right);
    p->_height = (hl > hr ? hl : hr) + 1;
}

template<class T>
vertex<T> *rotateRight(vertex<T> *p)
{
    vertex<T> *q = p->_left;
    p->_left = q->_right;
    q->_right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

template<class T>
vertex<T> *rotateLeft(vertex<T> *q)
{
    vertex<T> *p = q->_right;
    q->_right = p->_left;
    p->_left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

template<class T>
vertex<T> *balance(vertex<T> *p)
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

template<class T>
vertex<T> *insert(vertex<T> *node, T value)
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

template<class T>
vertex<T> *findMinVertex(vertex<T> *node)
{
    if (node->_left) {
        return findMinVertex(node->_left);
    }

    return node->_left;
}

template<class T>
vertex<T> *removeMinVertex(vertex<T> *node)
{
    if (node->_left == nullptr) {
        return node->_right;
    }
    node->_left = removeMinVertex(node->_left);
    return balance(node);
}

template<class T>
vertex<T> *remove(vertex<T> *node, T key)
{
    if (!node) {
        return nullptr;
    }
    if (node->_key > key) {
        return remove(node->_left, key);
    } else if (node->_key < key) {
        return remove(node->_right, key);
    } else {
        vertex<T> *q = node->_left;
        vertex<T> *r = node->_right;
        delete node;
        if (!r) {
            return q;
        }
        vertex<T> *min = findMinVertex(r);
        removeMinVertex(r);
        min->_left = q;
        return balance(min);
    }
    return balance(node);
}

template<class T>
vertex<T> *findLca(vertex<T> *node, vertex<T> *first, vertex<T> *second)
{
    if (!node) {
        return nullptr;
    }

    if (node->_key > first->_key && node->_key > second->_key) {
        auto ans = findLca(node->_left);
        return ans ? ans : node;
    }

    if (node->_key <= first->_key && node->_key <= second->_key) {
        auto ans = findLca(node->_right);
        return ans ? ans : node;
    }

    return node;
}

template<class T>
void traverse(vertex<T> *node, QVector<vertex<T>> &answer)
{
    if (!node) {
        return;
    }

    if (node->_left) {
        traverse(node->_left, answer);
    }

    answer.push_back(node);

    if (node->_right) {
        traverse(node->_right, answer);
    }
}

template<class T>
vertex<T> *findVertex(vertex<T> *node, T key)
{
    if (!node) {
        return nullptr;
    }

    if (node->_key == key) {
        return node;
    }

    if (node->_key > key) {
        return findVertex(node->_left, key);
    } else {
        return findVertex(node->_right, key);
    }
}

#endif // MTREE_H
