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
        T value;
        Node *l = nullptr;
        Node *r = nullptr;

        Node(int key, T value, int priority) : key(key), value(value), priority(priority) {};
    };

private:
    Node *root = nullptr;

    Node *merge(Node *a, Node *b)
    {
        if (!a || !b)
            return a ? a : b;

        if (a->priority > b->priority)
        {
            a->r = merge(a->r, b);
            return a;
        }
        else
        {
            b->l = merge(a, b->l);
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
    }

public:
    void insert(int key, T value, int priority)
    {
        Node *less, *equal, *greater;
        split(root, key, less, greater);
        split(greater, key + 1, equal, greater);

        if (!equal)
        {
            root = merge(less, new Node(key, value, priority));
            root = merge(root, greater);
        }
        else
        {
            root = merge(less, equal);
            root = merge(root, greater);
        }
    }

    void erase(int key)
    {
        Node *less, *equal, *greater;
        split(root, key, less, greater);
        split(greater, key + 1, equal, greater);

        root = merge(less, greater);

        if (equal)
            delete equal;
    }

    T find(int key)
    {
        Node *less, *equal, *greater;
        split(root, key, less, greater);
        split(greater, key + 1, equal, greater);

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

            res.push_back(cur->key);

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
                    res.push_back(st.top().first->key);
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
                res.push_back(st.top()->key);
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

    Treap() = default;
};

#endif //TASK2_TREAP_H
