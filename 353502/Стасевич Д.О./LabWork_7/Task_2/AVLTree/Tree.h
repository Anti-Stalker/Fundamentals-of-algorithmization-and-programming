//
// Created by darina on 5/27/24.
//

#ifndef TASK2_TREE_H
#define TASK2_TREE_H


#include <string>
#include <vector>
#include <iostream>

class Tree {

    std::vector<std::pair<int, int> > tree;
    std::vector<std::pair<int, std::string> > path;

    struct Node
    {
        std::string data;
        int key;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(int key, std::string data){
            this->key = key;
            this->data = data;
        }
    };

    Node* root = nullptr;

    int GetHeight(Node* node)
    {
        if(node == nullptr)
            return 0;
        return 1 + std::max(GetHeight(node->left), GetHeight(node->right));
    }

    int GetBalance(Node* node)
    {

        if(node == nullptr)
            return  0;
        int h1 = GetHeight(node->left);
        int h2 = GetHeight(node->right);
        return h1 - h2;
    }

    Node* LeftRotate(Node* node)
    {
        if(node == nullptr)
            return node;

        auto b = node->right;
        auto c = b->left;

        b->left = node;
        node->right = c;

        return b;
    }

    Node* RightRotate(Node* node)
    {
        if(node == nullptr)
            return node;

        auto b = node->left;
        auto c = b->right;

        b->right = node;
        node->left = c;

        return b;
    }

    Node* DoBalance(Node* p)
    {
        //int height = GetHeight(p);
        int balance = GetBalance(p);
        if(balance == 2)
        {
            // right turn
            if(GetBalance(p->left) >= 0)
            {
                p = RightRotate(p);
                return p;
            }
            else
            {
                p->left = LeftRotate(p->left);
                p = RightRotate(p);
                return p;
            }
        }
        else if (balance == -2)
        {
            // left turn
            if(GetBalance(p->right) <= 0)
            {
                // small left turn
                p = LeftRotate(p);
                return p;
            }
            else
            {
                p->right = RightRotate(p->right);
                p = LeftRotate(p);
                return p;
            }
        }
        return p;
    }

    Node* FindMin(Node* node)
    {
        if(node->left == nullptr)
        {
            return node;
        }
        return FindMin(node->left);
    }

    Node* remove_min(Node* node)
    {
        if(node->left == nullptr)
            return node->right;
        node->left = remove_min(node->left);
        return DoBalance(node);
    }

public:

    Tree() {};

    Node* Insert(Node* p, int k, const std::string& s)
    {

        Node* add = new Node(k, s);
        if(p == nullptr)
        {
            return add;
        }

        if(k < p->key)
        {
            // add to left
            p->left = Insert(p->left, k, s);
        }
        else if(k > p->key)
        {
            // add to right
            p->right = Insert(p->right, k, s);
        }
        else
        {
            return p;
        }
        p = DoBalance(p);
        return p;
    }

    void Insert(int k, const std::string & s)
    {
        root = Insert(root, k, s);
    }

    Node* Find(Node* node, int k)
    {
        if(node == nullptr)
            return node;
        if(node->key == k)
        {
            return node;
        }
        if(node->key < k)
        {
            return Find(node->right, k);
        }
        else
        {
            return Find(node->left, k);
        }
    }

    std::string Find(int k)
    {
        auto t = Find(root, k);
        if(t == nullptr)
            return "Не найдено в дереве";
        else
            return t->data;
    }

    Node* Delete(Node* p, int k)
    {
        if(p == nullptr)
            return p;
        if(p->key < k)
        {
            p->right = Delete(p->right, k);
        }
        else if(p->key > k)
        {
            p->left = Delete(p->left, k);
        }
        else
        {
            // p->key == k
            Node* q = p->left;
            Node* r = p->right;
            bool f = 0;
            if(p == root)
                f = 1;
            delete p;
            if(r == nullptr)
            {
                p = q;
                if(f)
                    root = p;
                return p;
            }
            Node* f_min = FindMin(r);
            f_min->right = remove_min(r);
            f_min->left = q;
            p = DoBalance(f_min);
            if(f)
                root = p;
            return p;
        }
        bool f = 0;
        if(p == root)
            f = 1;
        p = DoBalance(p);
        if(f)
            root = p;
        return p;
    }

    void Delete(int k)
    {
        Delete(root, k);
    }

    std::string GetValue(Node* node)
    {
        return node->data;
    }

    int CalculateNodes(Node* node)
    {
        if(node == nullptr)
            return 0;
        if(node->left != nullptr)
        {
            if(node->right == nullptr)
            {
                return 1 + CalculateNodes(node->left);
            }
            return CalculateNodes(node->left);
        }
        if(node->right != nullptr)
        {
            return 1 + CalculateNodes(node->right);
        }
        return 0;
    }

    void getTree(Node* node)
    {
        if(node == nullptr)
            return;
        if(node->left != nullptr)
        {
            tree.push_back({node->key, node->left->key});
            getTree(node->left);
        }
        if(node->right != nullptr)
        {
            tree.push_back({node->key, node->right->key});
            getTree(node->right);
        }
    }

    std::vector<std::pair<int, int> > getTree()
    {
        tree.clear();
        if(root == nullptr)
            return tree;
        tree.push_back({-1, root->key});

        getTree(root);
        return tree;
    }

    void Prime(Node* node)
    {
        if(node == nullptr)
            return;
        path.push_back({node->key, node->data});
        Prime(node->left);
        Prime(node->right);
    }

    void Reverse(Node* node)
    {
        if(node == nullptr)
            return;
        Reverse(node->left);
        Reverse(node->right);
        path.push_back({node->key, node->data});
    }

    void IncreasePath(Node* node)
    {
        if(node == nullptr)
            return;
        IncreasePath(node->left);
        path.push_back({node->key, node->data});
        IncreasePath(node->right);
    }

    std::vector<std::pair<int, std::string> > GetInfo(int type)
    {
        path.clear();
        switch (type) {
            case 1:
            {
                Prime(root);
                break;
            }
            case 2:
            {
                Reverse(root);
                break;
            }
            default:
            {
                IncreasePath(root);
            }
        }
        return path;
    }
};


#endif //TASK2_TREE_H
