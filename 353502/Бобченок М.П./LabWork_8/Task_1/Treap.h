//
// Created by u on 31.05.24.
//

#ifndef TASK2_TREAP_H
#define TASK2_TREAP_H

#include <iostream>
#include <QVector>
#include <stack>
#include <random>

template <typename T>
class Treap
{
public:
    struct Node
    {
        int priority;
        int key;
        int sz;
        T value;
        Node *par = nullptr;
        Node *l = nullptr;
        Node *r = nullptr;

        Node(int key, T value, int priority) : key(key), value(value), priority(priority), sz(1) {};
    };

    int getSize(Node *n)
    {
        return n ? n->sz : 0;
    }

private:

    void update(Node *n)
    {
        if (!n)
            return;
        n->sz = getSize(n->l) + 1 + getSize(n->r);

        if (n->l)
            n->l->par = n;

        if (n->r)
            n->r->par = n;
    }

    Node *root = nullptr;

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

    void split(Node *n, int key, Node *&a, Node *&b)
    {
        if (!n)
        {
            a = b = nullptr;
            return;
        }

        if (getSize(n->l) + 1 <= key)
        {
            split(n->r, key - getSize(n->l) - 1, n->r, b);
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
    void insert(int key, T value, int priority)
    {
        Node *less, *greater;
        split(root, key, less, greater);

        root = merge(less, new Node(key, value, priority));
        root = merge(root, greater);
    }

    void erase(int key)
    {
        Node *less, *equal, *greater;
        split(root, key, less, greater);
        split(greater, 1, equal, greater);

        root = merge(less, greater);

        if (equal)
            delete equal;
    }

    T find(int key)
    {
        Node *less, *equal, *greater;
        split(root, key, less, greater);
        split(greater, 1, equal, greater);

        T res;
        if (equal)
            res = equal->value;

        root = merge(less, equal);
        root = merge(root, greater);

        return res;
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

            res.push_back(cur->value);

            cur = cur->l;
        }
    }

    void back(QVector<int> &res)
    {
        res.clear();
        std::stack<std::pair<Node *, bool> > st;

        Node *cur = root;
        while (!st.empty() || cur)
        {
            if (cur)
                st.push({cur, 0});
            else
            {
                if (st.top().second)
                {
                    res.push_back(st.top().first->value);
                    st.pop();
                    continue;
                }

                cur = st.top().first->r;
                st.top().second = true;
                continue;
            }

            cur = cur->l;
        }
    }

    void byKey(QVector<int> &res)
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
                res.push_back(st.top()->value);
                cur = st.top()->r;
                st.pop();
                continue;
            }

            cur = cur->l;
        }
    }

    int numOfLeaves()
    {
        int res = 0;
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

            if (!cur->l && !cur->r)
                res++;

            cur = cur->l;
        }

        return res;
    }

    Node *getRoot()
    {
        return root;
    }

    Node *getNodeOnPos(int pos)
    {
        Node *less, *equal, *greater;
        split(root, pos, less, greater);
        split(greater, 1, equal, greater);

        Node *res = nullptr;
        if (equal)
            res = equal;

        root = merge(less, equal);
        root = merge(root, greater);

        return res;
    }

    int numOfLeft(Node *n, int pos)
    {
        if (!n)
            return 0;

        int res = pos;
        n = n->l;
        while (n)
        {
            res = res - 1 - getSize(n->r);
            n = n->l;
        }

        return res;
    }

    int numOfRight(Node *n, int pos)
    {
        if (!n)
            return 0;

        int res = pos;
        n = n->r;
        while (n)
        {
            res = res + 1 - getSize(n->l);;
            n = n->r;
        }

        return res;
    }

    Treap() = default;
};

#endif //TASK2_TREAP_H
