
#ifndef RB_TREE_RB_TREE_H
#define RB_TREE_RB_TREE_H

#include <iostream>
#include <stdexcept>

template <typename Key, typename Value>
class RB_Tree
{
private:
    struct Base_Node
    {
        std::pair<const Key, Value> value;
        Base_Node* left;
        Base_Node* right;
        Base_Node* parent;
        bool is_black;
        Key getKey() const
        {
            return value.first;
        }
        Base_Node(Key key):is_black(false),value(std::make_pair(key,Value())){}
        Base_Node():is_black(false),value(){}
    };
    Base_Node* root;
    Base_Node* nil;
    void left_rotate(Base_Node* x);
    void right_rotate(Base_Node* x);
    void insert_fixup(Base_Node* z);
    void transplant(Base_Node* u, Base_Node* v);
    void delete_fixup(Base_Node* x);
    Base_Node* successor(Base_Node* x);
    Base_Node* predecessor(Base_Node* x);
    Base_Node* minimum(Base_Node* x);
    void clear(Base_Node* x);
    void print(Base_Node* x);
public:
    RB_Tree();
    ~RB_Tree();
    void insert(Key key, Value value);
    void erase(Key key);
    Value& operator[](Key key);
    void print();
    bool empty();
    bool contains(Key key);
    Value& at(Key key);
    Value& find(Key key);
};
template <typename Key, typename Value>
RB_Tree<Key, Value>::RB_Tree()
{
    nil = new Base_Node();
    nil->is_black = true;
    nil->left = nullptr;
    nil->right = nullptr;
    nil->parent = nullptr;
    root = nil;
}
template <typename Key, typename Value>
RB_Tree<Key, Value>::~RB_Tree()
{
    clear(root);
    delete nil;
}
template <typename Key, typename Value>
void RB_Tree<Key, Value>::clear(Base_Node* x)
{
    if (x == nil)
        return;
    clear(x->left);
    clear(x->right);
    delete x;
}
template <typename Key, typename Value>
void RB_Tree<Key, Value>::left_rotate(Base_Node* t) {
    Base_Node* y = t->right;
    t->right = y->left;
    if (y->left != nil)
        y->left->parent = t;
    y->parent = t->parent;
    if (t->parent == nil)
        root = y;
    else if (t == t->parent->left)
        t->parent->left = y;
    else
        t->parent->right = y;
    y->left = t;
    t->parent = y;
}
template <typename Key, typename Value>
void RB_Tree<Key, Value>::right_rotate(Base_Node* t)
{
    Base_Node* y = t->left;
    t->left = y->right;
    if (y->right != nil)
        y->right->parent = t;
    y->parent = t->parent;
    if (t->parent == nil)
        root = y;
    else if (t == t->parent->right)
        t->parent->right = y;
    else
        t->parent->left = y;
    y->right = t;
    t->parent = y;
}

template <typename Key, typename Value>
void RB_Tree<Key, Value>::insert(Key key,Value val)
{
    Base_Node* t = new Base_Node(key); // constructor, passing key, color, left and right child
    t->left = nil;
    t->right = nil;
    t->parent = nil;
    if (root == nil)
    { // if tree is empty
        root = t;
        t->parent = nil;
    }
    else
    {
        Base_Node* p = root;
        Base_Node* q = nil;
        while (p != nil)
        { // go down until we reach the appropriate leaf
            q = p;
            if (p->getKey() < t->getKey())
                p = p->right;
            else
                p = p->left;
        }
        t->parent = q;
        // add a new red element
        if (q->getKey() < t->getKey())
            q->right = t;
        else
            q->left = t;
    }
    insert_fixup(t); // check if the properties of the red-black tree are violated
}

template <typename Key, typename Value>
void RB_Tree<Key, Value>::insert_fixup(Base_Node* t)
{
    while (t->parent->is_black == false)
    { // property 3 is violated
        Base_Node* uncle = nil;
        if (t->parent == t->parent->parent->left)
        { // if "father" is a left child
            uncle = t->parent->parent->right;
            if (uncle->is_black == false)
            { // if there is a red "uncle"
                t->parent->is_black = true;
                uncle->is_black = true;
                t->parent->parent->is_black = false;
                t = t->parent->parent;
            } else
            { // no "uncle"
                if (t == t->parent->right)
                {
                    t = t->parent;
                    left_rotate(t);
                }
                t->parent->is_black = true;
                t->parent->parent->is_black = false;
                right_rotate(t->parent->parent);
            }
        }
        else
        { // "father" is a right child
            uncle = t->parent->parent->left;
            if (uncle->is_black == false)
            { // if there is a red "uncle"
                t->parent->is_black = true;
                uncle->is_black = true;
                t->parent->parent->is_black = false;
                t = t->parent->parent;
            }
            else
            { // no "uncle"
                if (t == t->parent->left)
                {
                    t = t->parent;
                    right_rotate(t);
                }
                t->parent->is_black = true;
                t->parent->parent->is_black = false;
                left_rotate(t->parent->parent);
            }
        }
    }
    root->is_black = true; // restore root property
}

template <typename Key, typename Value>
void RB_Tree<Key, Value>::transplant(Base_Node* u, Base_Node* v)
{
    if (u->parent == nil)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
}

template <typename Key, typename Value>
void RB_Tree<Key, Value>::erase(Key key)
{
    if (!contains(key))
        return;
    Base_Node* p = root;
    // find the node with the key
    while (p->getKey() != key)
    {
        if (p->getKey() < key)
            p = p->right;
        else
            p = p->left;
    }
    if (p->left == nil && p->right == nil)
    { // if p has no children
        if (p == root)
            root = nil;
        else if (p == p->parent->left)
            p->parent->left = nil;
        else
            p->parent->right = nil;
        return;
    }
    Base_Node* y = nil;
    Base_Node* q = nil;
    if (p->left == nil || p->right == nil)
    { // one child
        y = (p->left != nil) ? p->left : p->right;
        if (p == root)
            root = y;
        else if (p == p->parent->left)
            p->parent->left = y;
        else
            p->parent->right = y;
        y->parent = p->parent;
    } else
    { // two children
        y = successor(p); // node with the next key value, it has no left child
        if (y->right != nil)
            y->right->parent = y->parent;
        if (y == root)
            root = y->right;
        else if (y == y->parent->left)
            y->parent->left = y->right;
        else
            y->parent->right = y->right;
        y->right->parent = y->parent;
       // p->getKey() = y->getKey();
        std::swap(p, y);
        p->is_black = y->is_black;
    }
    if (y->is_black == true)
        delete_fixup(q);
}
template <typename Key, typename Value>
void RB_Tree<Key, Value>::delete_fixup(RB_Tree::Base_Node *p)
{
    while (p != root && p->is_black == true)
    {
        if (p == p->parent->left) {
            Base_Node* brother = p->parent->right;
            if (brother->is_black == true)
            {
                brother->is_black = true;
                p->parent->is_black = false;
                left_rotate(p->parent);
            }
            if (brother->left->is_black == true && brother->right->is_black == true)
            {
                brother->is_black = false;
            } else {
                if (brother->right->is_black == true) {
                    brother->left->is_black = true;
                    brother->is_black = false;
                    right_rotate(brother);
                }
                brother->is_black = p->parent->is_black;
                p->parent->is_black = true;
                brother->right->is_black = true;
                left_rotate(p->parent);
                p = root;
            }
        } else
        {
            Base_Node* brother = p->parent->left;
            if (brother->is_black == false)
            {
                brother->is_black = true;
                p->parent->is_black = false;
                right_rotate(p->parent);
            }
            if (brother->right->is_black == true && brother->right->is_black == true)
            {
                brother->is_black = false;
            } else {
                if (brother->left->is_black == true)
                {
                    brother->right->is_black = true;
                    brother->is_black = false;
                    left_rotate(brother);
                }
                brother->is_black = p->parent->is_black;
                p->parent->is_black = true;
                brother->left->is_black = true;
                right_rotate(p->parent);
                p = root;
            }
        }
    }
    p->is_black = true;
    root->is_black = true;
}

template <typename Key, typename Value>
typename RB_Tree<Key, Value>::Base_Node* RB_Tree<Key, Value>::successor(Base_Node* x)
{
    if (x->right != nil)
        return minimum(x->right);
    Base_Node* y = x->parent;
    while (y != nil && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

template <typename Key, typename Value>
typename RB_Tree<Key, Value>::Base_Node* RB_Tree<Key, Value>::predecessor(Base_Node* x)
{
    if (x->left != nil)
        return maximum(x->left);
    Base_Node* y = x->parent;
    while (y != nil && x == y->left)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

template <typename Key, typename Value>
typename RB_Tree<Key, Value>::Base_Node* RB_Tree<Key, Value>::minimum(Base_Node* x)
{
    while (x->left != nil)
        x = x->left;
    return x;
}

template <typename Key, typename Value>
void RB_Tree<Key, Value>::print(Base_Node* x)
{
    if (x == nil)
        return;
    print(x->left);
    std::cout << x->getKey() << " " << x->value.second << " " << x->is_black << std::endl;
    print(x->right);
}

template <typename Key, typename Value>
void RB_Tree<Key, Value>::print()
{
    print(root);
    std::cout << std::endl;
}

template <typename Key, typename Value>
bool RB_Tree<Key, Value>::empty()
{
    return root == nil;
}

template <typename Key, typename Value>
bool RB_Tree<Key, Value>::contains(Key key)
{
    Base_Node* x = root;
    while (x != nil)
    {
        if (key < x->getKey())
            x = x->left;
        else if (key > x->getKey())
            x = x->right;
        else
            return true;
    }
    return false;
}

template <typename Key, typename Value>
Value& RB_Tree<Key, Value>::at(Key key)
{
    Base_Node* x = root;
    while (x != nil)
    {
        if (key < x->getKey())
            x = x->left;
        else if (key > x->getKey())
            x = x->right;
        else
            return x->value;
    }
    throw std::out_of_range("Key not found");
}

template <typename Key, typename Value>
Value& RB_Tree<Key, Value>::find(Key key)
{
    Base_Node* x = root;
    while (x != nil)
    {
        if (key < x->getKey())
            x = x->left;
        else if (key > x->getKey())
            x = x->right;
        else
            return x->value;
    }
    insert(key, Value());
    return find(key);
}

template <typename Key, typename Value>
Value& RB_Tree<Key, Value>::operator[](Key key)
{
    return find(key);
}


#endif//RB_TREE_RB_TREE_H
