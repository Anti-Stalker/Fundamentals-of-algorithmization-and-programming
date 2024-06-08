//
// Created by darina on 5/31/24.
//

#ifndef TASK3_RBTREE_H
#define TASK3_RBTREE_H

#include <memory>
#include <vector>
#include <iostream>

template<typename K, typename V>
class RBTree {
public:
    struct Node
    {
        Node* parent = nullptr;
        Node* left = nullptr;
        Node* right = nullptr;

        std::pair<K, V> data;

        bool color = 0; // 0 if black

        Node(const K &key, const V &value)
        {
            data.first = key;
            data.second = value;
            left = nullptr;
            right = nullptr;
            parent = nullptr;
            color = 0;
        }

        Node()
        {
            left = nullptr;
            right = nullptr;
            parent = nullptr;
            color = 0;
        }
    };


protected:
    Node* root;
    Node* fictive_son;
    size_t _size = 0;
    bool red = 1;
    bool black = 0;

protected:
    void LeftRotate(Node* node)
    {
        if(node == nullptr || node == fictive_son)
            return;

        bool f = (node == root);


        auto b = node->right;
        auto c = b->left;

        b->parent = node->parent;
        if(f)
        {
            // node = root
        }
        else {
            if (node->parent->left == node)
                node->parent->left = b;
            else {
                node->parent->right = b;
            }
        }
        b->left = node;
        node->parent = b;
        node->right = c;
        if(c != fictive_son)
            c->parent = node;

        if(f) {
            b->parent = nullptr;
            root = b;
        }
//        return b;
    }

    void RightRotate(Node* node) {
        if (node == nullptr || node == fictive_son)
            return;

        bool f = (node == root);

        auto b = node->left;
        auto c = b->right;

        b->parent = node->parent;
        if(f)
        {
            // node = root
        }
        else {
            if (node->parent->left == node)
                node->parent->left = b;
            else {
                node->parent->right = b;
            }
        }

        b->right = node;
        node->parent = b;
        node->left = c;
        if (c != fictive_son)
            c->parent = node;

        if (f){
            b->parent = nullptr;
            root = b;
        }
//        return b;
    }

    Node* Find(Node* node, int k)
    {
        if(node == nullptr)
            return node;
        if(node->data.first == k)
        {
            return node;
        }
        if(node->data.first < k)
        {
            return Find(node->right, k);
        }
        else
        {
            return Find(node->left, k);
        }
    }

    std::vector<std::pair<std::pair<int, int>, bool> > path;

    void GetTree(Node* node)
    {
        if(node == fictive_son)
            return;
        path.push_back({node->data, node->color});
        GetTree(node->left);
        GetTree(node->right);
    }

public:

    RBTree()
    {
        root = new Node();
        _size = 0;
        fictive_son = new Node();
    }

    ~RBTree() = default;

    void clear()
    {
        while (_size != 0)
        {
            std::cout << "go to delete " << root->data.first << '\n';
            erase_key(root->data.first);
        }
    }

    void insert(const K &key, const V &value)
    {
        std::cout << "add " << key << '\n';
        if(_size == 0)
        {
            Node* node = new Node(key, value);
            root = node;
            root->left = fictive_son;
            root->right = fictive_son;
            _size ++;
            return;
        }
        else
        {
            if(Find(root, key) != nullptr && Find(root, key) != fictive_son)
            {
                Find(root, key)->data.second = value;
                return;
            }

            Node* cur = root;
            Node* node = new Node(key, value);
            node->left = fictive_son;
            node->right = fictive_son;
            node->color = 1;
            _size ++;
            while(true)
            {
                if(cur->data.first > key)
                {
                    // goto left;
                    if(cur->left == fictive_son)
                    {
                        // create new node
                        cur->left = node;
                        node->parent = cur;
                        break;
                    }
                    else
                    {
                        cur = cur->left;
                    }
                }
                else
                {
                    // goto right
                    if(cur->right == fictive_son)
                    {
                        cur->right = node;
                        node->parent = cur;
                        break;
                    }
                    else
                    {
                        cur = cur->right;
                    }
                }
            }
            // cur is current red node we add

            if(cur->color == 0)
            {
                return;
            }

            // parent is red
            // two red
            // look at uncle

            // rebalance
            while(true)
            {
                Node* parent = node->parent;
                if(parent->color == 0)
                    return;

                if(parent == root)
                {
                    parent->color = 0;
                    return;
                }
                Node* grandparent = parent->parent;

                Node* uncle;

                if(grandparent->left == parent)
                {
                    uncle = grandparent->right;
                }
                else
                {
                    uncle = grandparent->left;
                }

                if(uncle->color == 1)
                {
                    // red
                    grandparent->color = 1;
                    grandparent->left->color = 0;
                    grandparent->right->color = 0;
                    if(grandparent == root){
                        grandparent->color = 0;
                        grandparent->parent = nullptr;
                        return;
                    }
                    node = grandparent;
                }
                else
                {
                    // black

                    if (grandparent->left == parent && parent->right == node) {
                        LeftRotate(parent);
                        std::swap(node, parent);
                    }

                    if (grandparent->right == parent && parent->left == node) {
                        RightRotate(parent);
                        std::swap(node, parent);
                    }

                    if (grandparent->left == parent) {
                        RightRotate(grandparent);
                    } else {
                        LeftRotate(grandparent);
                    }

                    parent->color = 0; // grandparent after rotation
                    grandparent->color = 1;  // uncle after rotation
                    return;
                }
            }
        }
    }

    V find(const K &key)
    {
        if(_size == 0)
            return V();
        if(Find(root, key) == nullptr || Find(root, key) == fictive_son)
            return V();
        return Find(root, key)->data.second;
    }

    void do_delete(Node* node)
    {
        if(node == root)
        {
            root = fictive_son;
            delete node;
            return;
        }
        Node* node_delete = node;

        while(node->parent != nullptr)
        {
            Node* parent = node->parent;
            Node* sibling;
            if(parent->left == node)
            {
                sibling = parent->right;
            }
            else
            {
                sibling = parent->left;
            }

            // case 2
            if(sibling->color == black && sibling != fictive_son && sibling->left->color == black && sibling->right->color == black && parent->color == black)
            {
                sibling->color = red;
                node = parent;
                continue;
                continue;
            }

            //case 3
            if(sibling->color == red)
            {
                bool left_sibling = 0;
                Node* closest_nephew;
                Node* distant_nephew;
                if(parent->left == sibling)
                {
                    left_sibling = 1;
                    RightRotate(parent);
                    closest_nephew = sibling->right;
                    distant_nephew = sibling->left;
                }
                else
                {
                    LeftRotate(parent);
                    closest_nephew = sibling->left;
                    distant_nephew = sibling->right;
                }
                parent->color = red;
                sibling->color = black;

                sibling = closest_nephew;

                if(left_sibling)
                {
                    closest_nephew = sibling->right;
                    distant_nephew = sibling->left;
                }
                else
                {
                    closest_nephew = sibling->left;
                    distant_nephew = sibling->right;
                }

                if(distant_nephew->color == red)
                {
                    // case 6
                    if(parent->right == sibling)
                    {
                        LeftRotate(parent);
                    }
                    else
                    {
                        RightRotate(parent);
                    }
                    sibling->color = parent->color;
                    parent->color = black;
                    distant_nephew->color = black;
                    break;
                }
                if(closest_nephew->color == red)
                {
                    // case 5
                    if(sibling->left == closest_nephew)
                    {
                        RightRotate(sibling);
                    }
                    else
                    {
                        LeftRotate(sibling);
                    }
                    closest_nephew->color = black;
                    sibling->color = red;

                    distant_nephew = sibling;
                    sibling = closest_nephew;

                    // case 6
                    if(parent->right == sibling)
                    {
                        LeftRotate(parent);
                    }
                    else
                    {
                        RightRotate(parent);
                    }
                    sibling->color = parent->color;
                    parent->color = black;
                    distant_nephew->color = black;
                    break;
                }

                // continue to case 4
            }

            // case 4
            if(parent->color == red && sibling->color == black && sibling != fictive_son && sibling->left->color == black && sibling->right->color == black)
            {
                sibling->color = red;
                parent->color = black;
                break;
            }

            Node* closest_nephew;
            Node* distant_nephew;
            if(sibling != fictive_son)
            {
                if(parent->left == sibling)
                {
                    closest_nephew = sibling->right;
                    distant_nephew = sibling->left;
                }
                else
                {
                    closest_nephew = sibling->left;
                    distant_nephew = sibling->right;
                }
            }

            // case 5
            if(sibling->color == black && sibling != fictive_son && closest_nephew->color == red && distant_nephew->color == black)
            {
                if(sibling->left == closest_nephew)
                {
                    RightRotate(sibling);
                }
                else
                {
                    LeftRotate(sibling);
                }
                closest_nephew->color = black;
                sibling->color = red;

                distant_nephew = sibling;
                sibling = closest_nephew;

                // continue to case 6
            }

            // case 6
            if(sibling->color == black && sibling != fictive_son && distant_nephew->color == red)
            {
                if(parent->right == sibling)
                {
                    LeftRotate(parent);
                }
                else
                {
                    RightRotate(parent);
                }
                sibling->color = parent->color;
                parent->color = black;
                distant_nephew->color = black;
                break;
            }
        }

        node->color = black;
        root->color = black;

        Node* parent = node_delete->parent;
        if(parent->left == node_delete)
        {
            parent->left = fictive_son;
        }
        else
        {
            parent->right = fictive_son;
        }
        delete node_delete;
    }

    void ShowTree(Node* node)
    {
        if(node == fictive_son)
        {
            return;
        }

        if(node == root)
        {
            std::cout << "root " << root->data.first << " " << root->color << " \n";
        }
        else
        {
            std::cout << "node " << node->data.first << " " << node->color << " parent " << node->parent->data.first << " " << node->parent->color << '\n';
        }
        ShowTree(node->left);
        ShowTree(node->right);
    }

    void erase_key(const K &key) {
        Node *node = Find(root, key);
        if (node == nullptr || node == fictive_son)
            return;

        --_size;
        erase(node);

        std::cout << "success delete " << _size << '\n';
        ShowTree(root);
        std::cout << std::endl;
    }

    void erase(Node* node){

        int child = -1;
        if(node->left == fictive_son && node->right == fictive_son)
        {
            // child = 0;
            if(node->color == 1)
            {
                if(node->parent->left == node)
                {
                    node->parent->left = fictive_son;
                    delete node;
                    return;
                }
                else
                {
                    node->parent->right = fictive_son;
                    delete node;
                    return;
                }
            }  // red node no child done
            else
            {
                do_delete(node);
                // pain
            }
            return;
        }
        if(node->left == fictive_son || node->right == fictive_son)
        {
            // child = 1;
            if(node->color == red)
            {
                // impossible
            }
            else
            {
                // repaint red child
                if(node->left->color == red)
                {
                    node->data = node->left->data;
                    delete node->left;
                    node->left = fictive_son;
                }
                else
                {
                    node->data = node->right->data;
                    delete node->right;
                    node->right = fictive_son;
                }
            }
            return;
        }
        //child = 2;
        if(node->color == red)
        {
            // find max element in left subtree
            Node* cur = node->left;
            while(cur->right != fictive_son)
                cur = cur->right;
            node->data = cur->data;
            // now need to delete cur
            erase(cur);
        }
        else
        {
            // find min element in right subtree
            Node* cur = node->right;
            while (cur->left != fictive_son)
                cur = cur->left;

            node->data = cur->data;

            // do delete cur

            erase(cur);
        }
    }

    int size()
    {
        return _size;
    }

    std::vector<std::pair<std::pair<int, int> , bool > > GetTree()
    {
        path.clear();
        if(_size == 0)
        {
            return path;
        }

        GetTree(root);
        return path;
    }

    V& operator[](const K& key)
    {
        auto t = Find(root, key);
        if(t != nullptr || t == fictive_son) {
            return t->data.second;
        }
        insert(key, V());
        t = Find(root, key);
        return t->data.second;
    }
public:
    class Iterator
    {
    protected:
        friend class RBTree<K, V>;
        Node* cur;
        Iterator(Node* root, bool type) {
            if(type)
            {
                // try to do .rend()
                cur = root;
                while (!(cur->right->left == nullptr && cur->right->right == nullptr))
                    cur = cur->right;
            }
            else {
                cur = root;
                std::cout << "root = " << root << " " << root->data.first << '\n';
                // get the smallest element in tree to make s.begin()
                while (!(cur->left->left == nullptr && cur->right->left == nullptr)) {
                    cur = cur->left;
                }
                std::cout << "cur = " << cur << " " << cur->data.first << '\n';

            }
        }
    public:
        Node *operator->() { return cur; }

        Node &operator*() { return *cur; }

        Iterator &operator++() {
            if(cur == nullptr || (cur->left == nullptr && cur->right == nullptr))
                return *this;

            // next element in subtree

            if(cur->right->left != nullptr || cur->right->left != nullptr)
            {
                /*       5 - cur
                *  4           7 - go here
                * or here - 6     8
                *  */

                cur = cur->right;
                while(!(cur->left->left == nullptr && cur->left->right == nullptr))
                    cur = cur->left;
            }
            else
            {
                // go up
                while (cur->parent != nullptr && cur->parent->right == cur) {
                    cur = cur->parent;
                }
                // get to the smallest not visited element in subtree
                cur = cur->parent;
            }

            return *this;
        }

        Iterator &operator--()
        {
            if(cur == nullptr || (cur->left == nullptr && cur->right == nullptr))
                return *this;

            if(cur->left->left != nullptr || cur->left->left != nullptr)
            {
                cur = cur->left;
                while(!(cur->right->left == nullptr && cur->right->right == nullptr))
                {
                    cur = cur->right;
                }
            }
            else
            {
                while(cur->parent != nullptr && cur->parent->left == cur)
                {
                    cur = cur->parent;
                }
                cur = cur->parent;
            }
            return *this;
        }

        bool operator==(const Iterator &other) const { return cur == other.cur; }
        bool operator!=(const Iterator &other) const { return cur != other.cur; }


    };

    Iterator begin()
    {
        return Iterator(root, 0);
    }

    Iterator rbegin()
    {
        return Iterator(root, 1);
    }
};

#endif //TASK3_RBTREE_H
