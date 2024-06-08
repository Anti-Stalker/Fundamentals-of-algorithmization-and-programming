//
// Created by u on 04.06.24.
//

#include <memory>
#include <QVector>

#ifndef TASK2_PTRHEAP_H
#define TASK2_PTRHEAP_H

struct Node
{
    int val;
    std::weak_ptr<Node> parent;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    Node(int x) : val(x) {}
};

class PtrHeap
{
private:

    std::shared_ptr<Node> root;
    int sz = 0;

    void heapifyUp(std::shared_ptr<Node> node)
    {
        if (!node)
            return;

        if (node->parent.lock() == nullptr)
            return;

        if (node->val > node->parent.lock()->val)
        {
            std::swap(node->val, node->parent.lock()->val);
            heapifyUp(node->parent.lock());
        }
    }

    void heapifyDown(std::shared_ptr<Node> cur)
    {
        if (!cur)
            return;

        if (cur->left && cur->left->val > cur->val)
        {
            std::swap(cur->val, cur->left->val);
            heapifyDown(cur->left);

            return;
        }

        if (cur->right && cur->right->val > cur->val)
        {
            std::swap(cur->val, cur->right->val);
            heapifyDown(cur->right);

            return;
        }
    }

public:
    void push(int x)
    {
        QVector<bool> path;

        int tmp = sz + 1;
        while (tmp > 1)
        {
            if (tmp % 2 == 0)
                path.push_back(false);
            else
                path.push_back(true);
            tmp /= 2;
        }

        std::shared_ptr<Node> cur = root;

        for (int i = path.size() - 1; i > 0; i--)
        {
            if (!path[i])
                cur = cur->left;
            else
                cur = cur->right;
        }

        if (!cur)
        {
            root = std::make_shared<Node>(x);
            sz++;
            return;
        }

        if (!path[0])
        {
            cur->left = std::make_shared<Node>(x);
            cur->left->parent = cur;
            heapifyUp(cur->left);
        }
        else
        {
            cur->right = std::make_shared<Node>(x);
            cur->right->parent = cur;
            heapifyUp(cur->right);
        }

        sz++;
    }

    void pop()
    {
        if (!root)
            return;

        if (sz == 1)
        {
            root.reset();
            sz--;
            return;
        }

        QVector<bool> path;

        int tmp = sz;
        while (tmp > 1)
        {
            if (tmp % 2 == 0)
                path.push_back(false);
            else
                path.push_back(true);
            tmp /= 2;
        }

        std::shared_ptr<Node> cur = root;

        for (int i = path.size() - 1; i >= 0; i--)
        {
            if (!path[i])
                cur = cur->left;
            else
                cur = cur->right;
        }

        int t = root->val;
        root->val = cur->val;
        cur->val = t;

        if (!path[0])
            cur->parent.lock()->left.reset();
        else
            cur->parent.lock()->right.reset();

        cur.reset();
        heapifyDown(root);

        sz--;
    }

    bool empty()
    {
        return sz == 0;
    }

    std::shared_ptr<Node> getRoot()
    {
        return root;
    }

    PtrHeap()
    {
        root = nullptr;
        sz = 0;
    }

    ~PtrHeap() = default;
};

#endif //TASK2_PTRHEAP_H
