//
// Created by u on 05.06.24.
//

#ifndef TASK3_TREAP_H
#define TASK3_TREAP_H

#include <random>
#include <time.h>
#include <stack>


template <typename K, typename V>
class Treap
{
public:
    struct Node
    {
        int priority;
        K key;
        size_t sz;
        V value;
        Node *parent = nullptr;
        Node *l = nullptr;
        Node *r = nullptr;

        Node(K key, V value) : key(key), value(value), priority(rand()), sz(1) {};
    };

    int getSize(Node *n)
    {
        return n ? n->sz : 0;
    }

private:
    Node *root = nullptr;

    void update(Node *n)
    {
        if (!n)
            return;
        n->sz = getSize(n->l) + 1 + getSize(n->r);

        if (n->l)
            n->l->parent = n;

        if (n->r)
            n->r->parent = n;
    }

    Node *merge(Node *a, Node *b)
    {
        if (!a || !b)
            return a ? a : b;

        if (a->priority > b->priority)
        {
            a->r = merge(a->r, b);
            update(a);
            return a;
        }
        else
        {
            b->l = merge(a, b->l);
            update(b);
            return b;
        }
    }

    void split(Node *n, K key, Node *&a, Node *&b)
    {
        if (!n)
        {
            a = b = nullptr;
            return;
        }

        if (n->key < key)
        {
            split(n->r, key, n->r, b);
            a = n;
        }
        else
        {
            split(n->l, key, a, n->l);
            b = n;
        }

        update(a);
        update(b);
    }

    void Gsplit(Node *n, K key, Node *&a, Node *&b)
    {
        if (!n)
        {
            a = b = nullptr;
            return;
        }

        if (n->key <= key)
        {
            split(n->r, key, n->r, b);
            a = n;
        }
        else
        {
            split(n->l, key, a, n->l);
            b = n;
        }

        update(a);
        update(b);
    }

public:
    void insert(K key, V value)
    {
        Node *less, *equal, *greater;
        split(root, key, less, greater);
        Gsplit(greater, key, equal, greater);

        if (equal)
        {
            root = merge(less, merge(equal, greater));
            return;
        }

        root = merge(less, new Node(key, value));
        root = merge(root, greater);
    }

    bool contains(K key)
    {
        Node *less, *equal, *greater;
        split(root, key, less, greater);
        Gsplit(greater, key, equal, greater);

        bool res = false;
        if (equal)
            res = true;

        root = merge(less, equal);
        root = merge(root, greater);

        return res;
    }

    void erase(K key)
    {
        Node *less, *equal, *greater;
        split(root, key, less, greater);
        Gsplit(greater, key, equal, greater);

        root = merge(less, greater);

        delete[] equal;
    }

    Node *getRoot()
    {
        return root;
    }

    Node *getNodeByKey(K key)
    {
        Node *less, *equal, *greater;
        split(root, key, less, greater);
        Gsplit(greater, key, equal, greater);

        Node *res = nullptr;
        if (equal)
            res = equal;

        root = merge(less, equal);
        root = merge(root, greater);

        return res;
    }

    void clear(Node *cur)
    {
        if (!cur)
            return;

        clear(cur->l);
        clear(cur->r);

        erase(cur->key);
    }

    void direct(QVector<int> &res)
    {
        res.clear();
        std::stack<Node *> st;

        Node *cur = root;
        while (!st.empty() || cur)
        {
            if (cur)
                st.push(cur);
            else
            {
                cur = st.top()->r;
                st.pop();
                continue;
            }

            res.push_back(cur->key);

            cur = cur->l;
        }
    }

    Treap()
    {
        srand(time(nullptr));
    }

    class Iterator
    {
    protected:
        friend class Treap<K, V>;

        Node *cur;

        Iterator(Node *root) : cur(root)
        {
            if(!cur)
                return;

            while (cur->left != nullptr)
                cur = cur->left;
        }

    public:
        Node *operator->()
        {
            return cur;
        }

        Node &operator*()
        {
            return *cur;
        }

        Iterator &operator++()
        {
            if (!cur)
                return *this;

            if (cur->right != nullptr)
            {
                cur = cur->right;

                while (cur->left != nullptr)
                    cur = cur->left;
            }
            else
            {
                while (cur->parent != nullptr && cur->parent->right == cur)
                    cur = cur->parent;

                cur = cur->parent;
            }

            return *this;
        }

        bool operator==(const Iterator &other)
        {
            return cur == other.cur;
        }

        bool operator!=(const Iterator &other)
        {
            return !(*this == other);
        }
    };

    Iterator begin()
    {
        return Iterator(root);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }
};

#endif //TASK3_TREAP_H
