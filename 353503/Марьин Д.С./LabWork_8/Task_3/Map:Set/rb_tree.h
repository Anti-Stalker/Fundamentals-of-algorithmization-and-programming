#ifndef RB_TREE_H
#define RB_TREE_H

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsTextItem>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

template <typename Key,typename Value>
class Iterator;
template <typename Key,typename Value>
class RB_Tree
{
private:
    struct Base_Node
    {
        std::pair <Key, Value> data;
        std::weak_ptr<Base_Node> parent;
        std::shared_ptr<Base_Node> left;
        std::shared_ptr<Base_Node> right;
        std::shared_ptr<Base_Node> prev;
        bool is_black;

        Key key() { return data.first; }
        void swap(std::shared_ptr<Base_Node> p)
        {
            std::swap(this->data,p->data);
        }

        Value& value() { return data.second; }
        const Value& value() const { return data.second; }
        explicit Base_Node(std::pair<Key, Value> data)
            : data(data), left(nullptr), right(nullptr), is_black(false) {}
        Base_Node()
            : left(nullptr), right(nullptr), is_black(false) {}
    };

    std::shared_ptr<Base_Node> root; // root of the tree
    std::shared_ptr<Base_Node> nil;// sentinel node

    void left_rotate(std::shared_ptr<Base_Node> x);
    void right_rotate(std::shared_ptr<Base_Node> x);

    //std::shared_ptr<Base_Node> remove(std::shared_ptr<Base_Node> node, Key data);
    std::shared_ptr<Base_Node> insert(std::shared_ptr<Base_Node> node, Key key, Value data);
    std::shared_ptr<Base_Node> search(std::shared_ptr<Base_Node> x, Key data);

    void insert_fixup(std::shared_ptr<Base_Node> z);
    void transplant(std::shared_ptr<Base_Node> u, std::shared_ptr<Base_Node> v);
    void delete_fixup(std::shared_ptr<Base_Node> x);
    std::string to_string(std::shared_ptr<Base_Node> x);

    std::shared_ptr<Base_Node> minimum(std::shared_ptr<Base_Node> x);
    std::shared_ptr<Base_Node> maximum(std::shared_ptr<Base_Node> x);

    std::shared_ptr<Base_Node> successor(std::shared_ptr<Base_Node> x);
    std::shared_ptr<Base_Node> predecessor(std::shared_ptr<Base_Node> x);


public:
    RB_Tree();
    ~RB_Tree();
    void insert( Key key, Value data);
    void remove(Key key);
    std::shared_ptr<Base_Node> search(Key key);
    bool contains(Key key) { return search(key) != nil; }
    void operator=(const RB_Tree<Key,Value>& other) = delete;
    void operator=(RB_Tree<Key,Value>&& other) = delete;
    Value& operator [](Key data) { return search(data)->value(); }
    const Value& operator [](Key data) const { return search(data)->value(); }
    void clear();
    std::string to_string();
    void print(std::shared_ptr<Base_Node> node) const;
    void print() const;
    friend class Iterator<Key, Value>;
    Iterator<Key,Value> end()
    {
        return Iterator(nil, nil,this);
    }
    Iterator<Key, Value> begin()
    {
        return Iterator(minimum(root), nil,this);
    }
    void drawTree(QGraphicsScene* scene,std::shared_ptr<Base_Node> node, int x, int y, int level);
    void drawTree(QGraphicsScene* scene);
};

template <typename Key,typename Value>
RB_Tree<Key,Value>::RB_Tree()
{
    nil = std::make_shared<Base_Node>(std::make_pair(Key(),Value()));
    nil->left = nil;
    nil->right = nil;
    nil->parent = nil;
    nil->is_black = true;
    root = nil;
}

template <typename Key,typename Value>
RB_Tree<Key,Value>::~RB_Tree()
{
    clear();
}

template <typename Key,typename Value>
void RB_Tree<Key,Value>::left_rotate(std::shared_ptr<Base_Node> x)
{
    auto y = x->right;
    x->right = y->left;
    if (y->left != nil)
        y->left ->parent.lock() = x;
    y ->parent.lock() = x ->parent.lock();
    if (x ->parent.lock() == nil)
        root = y;
    else if (x == x ->parent.lock()->left)
        x ->parent.lock()->left = y;
    else
        x ->parent.lock()->right = y;
    y->left = x;
    x ->parent.lock() = y;
}

// template <typename Key, typename Value>
// void RB_Tree<Key, Value>::left_rotate(std::shared_ptr<Base_Node> x)
// {
//     auto y = x->right;
//     if (x != nullptr && y != nullptr)
//     {
//         x->right = y->left;
//     }
//     if (y!= nullptr && y->left != nil)
//         y->left->parent = x;
//     y->parent = x->parent;
//     if (x->parent == nil)
//         root = y;
//     else if (x == x->parent->left)
//         x->parent->left = y;
//     else
//         x->parent->right = y;
//     y->left = x;
//     x->parent = y;
// }



template <typename Key,typename Value>
void RB_Tree<Key,Value>::right_rotate(std::shared_ptr<Base_Node> x)
{
    auto y = x->left;
    x->left = y->right;
    if (y->right != nil)
        y->right ->parent.lock() = x;
    y ->parent.lock() = x ->parent.lock();
    if (x ->parent.lock() == nil)
        root = y;
    else if (x == x ->parent.lock()->right)
        x ->parent.lock()->right = y;
    else
        x ->parent.lock()->left = y;
    y->right = x;
    x ->parent.lock() = y;
}



// template <typename Key,typename Value>
// void RB_Tree<Key,Value>::insert_fixup(std::shared_ptr<Base_Node> z)
// {
//     // if the parent of z is null, then z is the root
//     if (!z->parent.lock())
//     {
//         z->is_black = true;
//         return;
//     }
//     // if the parent of z is black, then the tree is still valid
//     if (z->parent.lock()->is_black)
//     {
//         return;
//     }
//     // if the parent of z is red, then we need to fix the tree

//     // if it is at the left side of the grandparent of z
//     if (z->parent.lock() == z->parent.lock()->parent.lock()->left)
//     {
//         auto y = z->parent.lock()->parent.lock()->right;
//         // Case 1: z's uncle y is red
//         if (!y->is_black)
//         {
//             z->parent.lock()->is_black = true; // make the parent black
//             y->is_black = true; // make the uncle black
//             z->parent.lock()->parent.lock()->is_black = false;
//             insert_fixup(z->parent.lock()->parent.lock());
//         }
//         // Case 2: z's uncle y is black
//         else
//         {
//             if (z == z->parent.lock()->right) {
//                 z = z->parent.lock();
//                 left_rotate(z);
//             }
//             //and case 3 for left side
//             z->parent.lock()->is_black = true;
//             z->parent.lock()->parent.lock()->is_black = false;
//             right_rotate(z->parent.lock()->parent.lock());
//         }
//     }

//     else
//     {
//         auto y = z->parent.lock()->parent.lock()->left;
//         if (!y->is_black)
//         {
//             z->parent.lock()->is_black = true;
//             y->is_black = true;
//             z->parent.lock()->parent.lock()->is_black = false;
//             insert_fixup(z->parent.lock()->parent.lock());
//         }
//         else
//         {
//             if (z == z->parent.lock()->left)
//             {
//                 z = z->parent.lock();
//                 right_rotate(z);
//             }
//             z->parent.lock()->is_black = true;
//             z->parent.lock()->parent.lock()->is_black = false;
//             left_rotate(z->parent.lock()->parent.lock());
//         }
//     }
//     root->is_black = true;
// }
// template <typename Key, typename Value>
// void RB_Tree<Key, Value>::delete_fixup(std::shared_ptr<Base_Node> x)
// {
//     if (x == root || !x->is_black)
//     {
//         x->is_black = true;
//         return;
//     }
//     if (x == x->parent.lock()->left)
//     {
//         auto w = x->parent.lock()->right;
//         if (!w->is_black)
//         {
//             w->is_black = true;
//             x->parent.lock()->is_black = false;
//             left_rotate(x->parent.lock());
//             delete_fixup(x->parent.lock());
//         }
//         else if (w->left->is_black && w->right->is_black)
//         {
//             w->is_black = false;
//             delete_fixup(x->parent.lock());
//         }
//         else
//         {
//             if (w->right->is_black)
//             {
//                 w->left->is_black = true;
//                 w->is_black = false;
//                 right_rotate(w);
//             }
//             w->is_black = x->parent.lock()->is_black;
//             x->parent.lock()->is_black = true;
//             w->right->is_black = true;
//             left_rotate(x->parent.lock());
//         }
//     }
//     else
//     {
//         auto w = x->parent.lock()->left;
//         if (!w->is_black)
//         {
//             w->is_black = true;
//             x->parent.lock()->is_black = false;
//             right_rotate(x->parent.lock());
//             delete_fixup(x->parent.lock());
//         }
//         else if (w->right->is_black && w->left->is_black)
//         {
//             w->is_black = false;
//             delete_fixup(x->parent.lock());
//         }
//         else
//         {
//             if (w->left->is_black)
//             {
//                 w->right->is_black = true;
//                 w->is_black = false;
//                 left_rotate(w);
//             }
//             w->is_black = x->parent.lock()->is_black;
//             x->parent.lock()->is_black = true;
//             w->left->is_black = true;
//             right_rotate(x->parent.lock());
//         }
//     }
// }

// template <typename Key, typename Value>
// void RB_Tree<Key, Value>::insert_fixup(std::shared_ptr<Base_Node> z)
// {
//     while (!z->parent.lock()->is_black)
//     {
//         if (z->parent.lock() == z->parent.lock()->parent.lock()->left)
//         {
//             auto y = z->parent.lock()->parent.lock()->right;
//             if (!y->is_black)
//             {
//                 z->parent.lock()->is_black = true;
//                 y->is_black = true;
//                 z->parent.lock()->parent.lock()->is_black = false;
//                 z = z->parent.lock()->parent.lock();
//             }
//             else
//             {
//                 if (z == z->parent.lock()->right)
//                 {
//                     z = z->parent.lock();
//                     left_rotate(z);
//                 }
//                 z->parent.lock()->is_black = true;
//                 z->parent.lock()->parent.lock()->is_black = false;
//                 right_rotate(z->parent.lock()->parent.lock());
//             }
//         }
//         else
//         {
//             auto y = z->parent.lock()->parent.lock()->left;
//             if (!y->is_black)
//             {
//                 z->parent.lock()->is_black = true;
//                 y->is_black = true;
//                 z->parent.lock()->parent.lock()->is_black = false;
//                 z = z->parent.lock()->parent.lock();
//             }
//             else
//             {
//                 if (z == z->parent.lock()->left)
//                 {
//                     z = z->parent.lock();
//                     right_rotate(z);
//                 }
//                 z->parent.lock()->is_black = true;
//                 z->parent.lock()->parent.lock()->is_black = false;
//                 left_rotate(z->parent.lock()->parent.lock());
//             }
//         }
//     }
//     root->is_black = true;
// }

template <typename Key,typename Value>
void RB_Tree<Key,Value>::transplant(std::shared_ptr<Base_Node> u, std::shared_ptr<Base_Node> v)
{
    if (u->parent.lock() == nil)
        root = v;
    else if (u == u ->parent.lock()->left)
        u->parent.lock()->left = v;
    else
        u->parent.lock()->right = v;
    v->parent = std::weak_ptr<Base_Node>(u->parent.lock());
}

template <typename Key, typename Value>
void RB_Tree<Key, Value>::remove(Key key)
{
    if (!contains(key))
        return;
    auto p = root;
    // find the node with the key
    while (p->key() != key)
    {
        if (p->key() < key)
            p = p->right;
        else
            p = p->left;
    }
    if (p->left == nil && p->right == nil)
    { // if p has no children
        if (p == root)
            root = nil;
        else if (p == p->parent.lock()->left)
            p->parent.lock()->left = nil;
        else
            p->parent.lock()->right = nil;
        return;
    }
    auto y = nil;
    auto q = nil;
    if (p->left == nil || p->right == nil)
    { // one child
        y = (p->left != nil) ? p->left : p->right;
        if (p == root)
            root = y;
        else if (p == p->parent.lock()->left)
            p->parent.lock()->left = y;
        else
            p->parent.lock()->right = y;
        y->parent.lock() = p->parent.lock();
    }
    else
    { // two children
        y = successor(p); // node with the next key value, it has no left child
        if (y->right != nil)
            y->right->parent.lock() = y->parent.lock();
        if (y == root)
            root = y->right;
        else if (y == y->parent.lock()->left)
            y->parent.lock()->left = y->right;
        else
            y->parent.lock()->right = y->right;
        y->right->parent.lock() = y->parent.lock();
        p.swap(y);//////
        p->is_black = y->is_black;
    }
    if (y->is_black == true)
        delete_fixup(q);
}

template <typename Key, typename Value>
void RB_Tree<Key, Value>::insert(Key key,Value val)
{
    auto t = std::make_shared<Base_Node>(Base_Node(std::make_pair(key,val))); // constructor, passing key, color, left and right child
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
        auto p = root;
        auto q = nil;
        while (p != nil)
        { // go down until we reach the appropriate leaf
            q = p;
            if (p->key() < t->key())
                p = p->right;
            else
                p = p->left;
        }
        t->parent.lock() = q;
        // add a new red element
        if (q->key() < t->key())
            q->right = t;
        else
            q->left = t;
    }
    insert_fixup(t); // check if the properties of the red-black tree are violated
}

template <typename Key, typename Value>
void RB_Tree<Key, Value>::insert_fixup(std::shared_ptr<Base_Node> t)
{
    while (t->parent.lock()->is_black == false)
    { // property 3 is violated
        auto uncle = nil;
        if (t->parent.lock() == t->parent.lock()->parent.lock()->left)
        { // if "father" is a left child
            uncle = t->parent.lock()->parent.lock()->right;
            if (uncle->is_black == false)
            { // if there is a red "uncle"
                t->parent.lock()->is_black = true;
                uncle->is_black = true;
                t->parent.lock()->parent.lock()->is_black = false;
                t = t->parent.lock()->parent.lock();
            } else
            { // no "uncle"
                if (t == t->parent.lock()->right)
                {
                    t = t->parent.lock();
                    left_rotate(t);
                }
                t->parent.lock()->is_black = true;
                t->parent.lock()->parent.lock()->is_black = false;
                right_rotate(t->parent.lock()->parent.lock());
            }
        }
        else
        { // "father" is a right child
            uncle = t->parent.lock()->parent.lock()->left;
            if (uncle->is_black == false)
            { // if there is a red "uncle"
                t->parent.lock()->is_black = true;
                uncle->is_black = true;
                t->parent.lock()->parent.lock()->is_black = false;
                t = t->parent.lock()->parent.lock();
            }
            else
            { // no "uncle"
                if (t == t->parent.lock()->left)
                {
                    t = t->parent.lock();
                    right_rotate(t);
                }
                t->parent.lock()->is_black = true;
                t->parent.lock()->parent.lock()->is_black = false;
                left_rotate(t->parent.lock()->parent.lock());
            }
        }
    }
    root->is_black = true; // restore root property
}

template <typename Key, typename Value>
void RB_Tree<Key, Value>::delete_fixup(std::shared_ptr<RB_Tree::Base_Node> p)
{
    while (p != root && p->is_black == true)
    {
        if (p == p->parent.lock()->left) {
            auto brother = p->parent.lock()->right;
            if (brother->is_black == true)
            {
                brother->is_black = true;
                p->parent.lock()->is_black = false;
                left_rotate(p->parent.lock());
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
                brother->is_black = p->parent.lock()->is_black;
                p->parent.lock()->is_black = true;
                brother->right->is_black = true;
                left_rotate(p->parent.lock());
                p = root;
            }
        } else
        {
            auto brother = p->parent.lock()->left;
            if (brother->is_black == false)
            {
                brother->is_black = true;
                p->parent.lock()->is_black = false;
                right_rotate(p->parent.lock());
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
                brother->is_black = p->parent.lock()->is_black;
                p->parent.lock()->is_black = true;
                brother->left->is_black = true;
                right_rotate(p->parent.lock());
                p = root;
            }
        }
    }
    p->is_black = true;
    root->is_black = true;
}

template <typename Key,typename Value>
std::shared_ptr<typename RB_Tree<Key,Value>::Base_Node> RB_Tree<Key,Value>::minimum(std::shared_ptr<Base_Node> x)
{
    while (x->left != nil)
        x = x->left;
    return x;
}

template <typename Key,typename Value>
std::shared_ptr<typename RB_Tree<Key,Value>::Base_Node> RB_Tree<Key,Value>::maximum(std::shared_ptr<Base_Node> x)
{
    while (x->right != nil)
        x = x->right;
    return x;
}

template <typename Key,typename Value>
std::shared_ptr<typename RB_Tree<Key,Value>::Base_Node> RB_Tree<Key,Value>::successor(std::shared_ptr<Base_Node> x)
{
    if (x->right != nil)
        return minimum(x->right);
    auto y = x ->parent.lock();
    while (y != nil && x == y->right)
    {
        x = y;
        y = y->parent.lock();
    }
    return y;
}

template <typename Key,typename Value>
std::shared_ptr<typename RB_Tree<Key,Value>::Base_Node> RB_Tree<Key,Value>::predecessor(std::shared_ptr<Base_Node> x)
{
    return x->parent.lock();
}

template <typename Key,typename Value>
std::shared_ptr<typename RB_Tree<Key,Value>::Base_Node> RB_Tree<Key,Value>::search(std::shared_ptr<Base_Node> x, Key data)
{
    // Base case: if the tree is empty or the key is found
    if (x == nil || x->data.first == data)
        return x;

    // If the given key is less than the node's key, then it must be in left subtree
    if (data < x->data.first)
        return search(x->left, data);

    // Else the key must be in right subtree
    return search(x->right, data);
}

template <typename Key,typename Value>
std::shared_ptr<typename RB_Tree<Key,Value>::Base_Node> RB_Tree<Key,Value>::search(Key key)
{
    return search(root, key);
}

template <typename Key,typename Value>
void RB_Tree<Key,Value>::clear()
{
    root = nil;
}

template <typename Key,typename Value>
std::string RB_Tree<Key,Value>::to_string(std::shared_ptr<Base_Node> node)
{
    std::string result;
    if (node != nil)
    {
        result += to_string(node->left);
        result += "(" + std::to_string(node->data.first) + ", " + node->data.second + ")\n";
        result += to_string(node->right);
    }
    return result;
}

template <typename Key,typename Value>
std::string RB_Tree<Key,Value>::to_string()
{
    std::string str;
    str = to_string(root);
    return str;
}

template <typename Key,typename Value>
class Iterator
{
private:
    friend class RB_Tree<Key,Value>;
    std::shared_ptr<typename RB_Tree<Key,Value>::Base_Node> current;
    RB_Tree<Key,Value>* tree; // Add a pointer to the tree

public:
    Iterator(std::shared_ptr<typename RB_Tree<Key,Value>::Base_Node> current,std::shared_ptr<typename RB_Tree<Key,Value>::Base_Node> nil, RB_Tree<Key,Value>* tree)
        : current(current), tree(tree) {}

    Iterator& operator++()
    {
        current = tree->successor(current);
        return *this;
    }

    Iterator& operator--()
    {
        current = tree->predecessor(current);
        return *this;
    }

    std::pair <const Key, Value>& operator*()
    {
        return current->data;
    }

    bool operator==(const Iterator& other)
    {
        return current == other.current;
    }

    bool operator!=(const Iterator& other)
    {
        return current != other.current;
    }

    std::pair <const Key, Value>* operator->()
    {
        return &(current->data);
    }
};

template <typename Key,typename Value>
class ListIterator
{
private:
    friend class RB_Tree<Key,Value>;
    std::shared_ptr<typename RB_Tree<Key,Value>::Base_Node> current;
public:
    ListIterator(std::shared_ptr<typename RB_Tree<Key,Value>::Base_Node> current) : current(current) {}
    ListIterator& operator++()
    {
        current = successor(current);
        return *this;
    }
    ListIterator& operator--()
    {
        current = current->prev;
        return *this;
    }
    std::pair <const Key, Value>& operator*()
    {
        return current->data;
    }
    bool operator==(const ListIterator& other)
    {
        return current == other.current;
    }
    bool operator!=(const ListIterator& other)
    {
        return current != other.current;
    }
    std::pair <const Key, Value> operator->()
    {
        return current->data;
    }
};

template <typename Key,typename Value>
void RB_Tree<Key,Value>::print(std::shared_ptr<Base_Node> node) const
{
    if (node != nil)
    {
        print(node->left);
        std::cout << "(" << node->data.first << ", " << node->data.second << ")" << std::endl;
        print(node->right);
    }
}

template <typename Key,typename Value>
void RB_Tree<Key,Value>::print() const
{
    print(root);
}

template <typename Key, typename Value>
void RB_Tree<Key,Value>::drawTree(QGraphicsScene* scene)
{
    drawTree(scene,root,0,0,0);
}

template <typename Key, typename Value>
void RB_Tree<Key,Value>::drawTree(QGraphicsScene* scene,std::shared_ptr<Base_Node> node, int x, int y, int level)
{

    if (node == nil)
    {
        return;
    }

    int offset = 100 / (level + 1);  // Adjust this value to change the spacing between nodes

    QGraphicsEllipseItem* ellipse = scene->addEllipse(x, y, 40, 40);
    ellipse->setBrush(QColor( node->is_black? Qt::black : Qt::darkRed));
    QGraphicsTextItem* text = scene->addText(QString::number(node->data.first));
    text->setDefaultTextColor(Qt::white);
    text->setPos(x+7, y+7);  // Adjust these values to center the text in the ellipse

    if (node->left && node->left != nil)
    {
        scene->addLine(x+20, y+40, x-offset+20, y+80);  // Draw line to left child
        drawTree(scene, node->left, x-offset, y+80, level+1);
    }

    if (node->right && node->right != nil)
    {
        scene->addLine(x+20, y+40, x+offset+20, y+80);  // Draw line to right child
        drawTree(scene, node->right, x+offset, y+80, level+1);
    }
}


#endif // RB_TREE_H
