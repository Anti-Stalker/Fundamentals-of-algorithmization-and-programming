#ifndef MRB_TREE_H
#define MRB_TREE_H

#include <memory>
template<class K, class V>
class mrb_tree
{
public:
    struct rb_tree_node
    {
        K _key;
        V _value;
        rb_tree_node *_parent{nullptr};
        rb_tree_node *_left{nullptr};
        rb_tree_node *_right{nullptr};
        enum color { red, black } _color{rb_tree_node::red};

        rb_tree_node(K key, V value, rb_tree_node *parent)
            : _key(key)
            , _value(value)
            , _parent(parent)
            , _left(nullptr)
            , _right(nullptr)
            , _color(rb_tree_node::red)
        {}
    };

private:
    bool isLeftChild(rb_tree_node *node)
    {
        if (!node->_parent) {
            throw "No parent";
        }

        return node->_parent->_left == node;
    }

    rb_tree_node *getUncle(rb_tree_node *node)
    {
        if (!node->_parent) {
            throw "No parent";
        }

        return isLeftChild(node->_parent) ? getGrandparent(node)->_right
                                          : getGrandparent(node)->_left;
    }

    rb_tree_node *getGrandparent(rb_tree_node *node)
    {
        if (!node->_parent) {
            throw "No parent";
        }

        if (!node->_parent->_parent) {
            throw "No grandparent";
        }

        return node->_parent->_parent;
    }

    rb_tree_node *getBrother(rb_tree_node *node)
    {
        if (!node->_parent) {
            throw "No parent";
        }

        return isLeftChild(node) ? node->_parent->_right : node->_parent->_left;
    }

    bool areChildsBlack(rb_tree_node *node)
    {
        if (!node->_left || !node->_right) {
            return false;
        }

        return node->_left->_color == rb_tree_node::black
               && node->_right->_color == rb_tree_node::black;
    }

protected:
    void insert(K key, V value)
    {
        if (_head == nullptr) {
            _head = new rb_tree_node(key, value, nullptr);
            _head->_color = rb_tree_node::black;
            return;
        }

        rb_tree_node *curr = _head;
        rb_tree_node *prev = nullptr;

        while (curr) {
            prev = curr;
            if (curr->_key > key) {
                curr = curr->_left;
            } else {
                curr = curr->_right;
            }
        }

        if (prev->_key > key) {
            prev->_left = new rb_tree_node(key, value, prev);
            curr = prev->_left;
        } else {
            prev->_right = new rb_tree_node(key, value, prev);
            curr = prev->_right;
        }

        fixInsert(curr);
    }

    void remove(K key)
    {
        rb_tree_node *curr = _head;

        while (curr->_key != key) {
            if (curr->_key > key) {
                curr = curr->_left;
            } else {
                curr = curr->_right;
            }
        }

        if (!curr->_left && !curr->_right) {
            if (curr == _head) {
                _head = nullptr;
            } else {
                if (isLeftChild(curr)) {
                    curr->_parent->_left = nullptr;
                } else {
                    curr->_parent->_right = nullptr;
                }
            }

            return;
        }

        rb_tree_node *next = rb_tree_node();

        if (curr->_left && !curr->_right) {
            if (isLeftChild(curr)) {
                curr->_parent->_left = curr->_left;
            } else {
                curr->_parent->_right = curr->_left;
            }
        } else if (!curr->_left && curr->_right) {
            if (isLeftChild(curr)) {
                curr->_parent->_left = curr->_right;
            } else {
                curr->_parent->_right = curr->_right;
            }
        } else {
            next = curr->_right;

            while (next->_left) {
                next = next->_left;
            }

            if (next->_right) {
                next->_right->_parent = next->_parent;
            }

            if (next == _head) {
                _head = next->_right;
            } else {
                if (isLeftChild(next)) {
                    next->_parent->_left = next->_right;
                } else {
                    next->_parent->_right = next->_right;
                }
            }
        }

        if (next != curr) {
            curr->_color = next->_color;
            curr->_key = next->_key;
        }

        if (next->_color == rb_tree_node::black) {
            fixRemove(next);
        }
    }

    rb_tree_node *find(K key)
    {
        rb_tree_node *curr = _head;

        while (curr && curr->_key != key) {
            if (curr->_key > key) {
                curr = curr->_left;
            } else {
                curr = curr->_right;
            }
        }

        return curr;
    }

    void leftRotate(rb_tree_node *node)
    {
        auto q = node->_right;
        node->_right = q->_left;
        q->_left = node;
        q->_parent = node->_parent;
        node->_parent = q;
        if (node->_right) {
            node->_right->_parent = node;
        }

        if (_head == node) {
            _head = q;
        }
    }

    void rightRotate(rb_tree_node *node)
    {
        auto q = node->_left;
        node->_left = q->_right;
        q->_right = node;
        q->_parent = node->_parent;
        node->_parent = q;
        if (node->_left) {
            node->_left->_parent = node;
        }

        if (_head == node) {
            _head = q;
        }
    }

    void fixInsert(rb_tree_node *node)
    {
        if (node == _head) {
            node->_color = rb_tree_node::black;
            return;
        }

        while (node != _head && node->_parent->_color == rb_tree_node::red) {
            if (isLeftChild(node->_parent)) {
                if (getUncle(node) && getUncle(node)->_color == rb_tree_node::red) {
                    node->_parent->_color = rb_tree_node::black;
                    getUncle(node)->_color = rb_tree_node::black;
                    getGrandparent(node)->_color = rb_tree_node::red;
                    node = getGrandparent(node);
                } else {
                    if (!isLeftChild(node)) {
                        node = node->_parent;
                        leftRotate(node);
                    }

                    node->_parent->_color = rb_tree_node::black;
                    getGrandparent(node)->_color = rb_tree_node::red;
                    rightRotate(getGrandparent(node));
                }
            } else {
                if (getUncle(node) && getUncle(node)->_color == rb_tree_node::red) {
                    node->_parent->_color = rb_tree_node::black;
                    getUncle(node)->_color = rb_tree_node::black;
                    getGrandparent(node)->_color = rb_tree_node::red;
                    node = getGrandparent(node);
                } else {
                    if (isLeftChild(node)) {
                        node = node->_parent;
                        rightRotate(node);
                    }

                    node->_parent->_color = rb_tree_node::black;
                    getGrandparent(node)->_color = rb_tree_node::red;
                    leftRotate(getGrandparent(node));
                }
            }
        }

        _head->_color = rb_tree_node::black;
    }

    void fixRemove(rb_tree_node *node)
    {
        while (node->_color == rb_tree_node::black && node != _head) {
            if (isLeftChild(node)) {
                if (getBrother(node)->_color == rb_tree_node::red) {
                    getBrother(node)->_color = rb_tree_node::black;
                    node->_parent->_color = rb_tree_node::red;
                    leftRotate(node->_parent);
                }

                if (areChildsBlack(getBrother(node))) {
                    getBrother(node)->_color = rb_tree_node::red;
                } else {
                    if (!getBrother(node)->_right
                        || getBrother(node)->_right->_color == rb_tree_node::black) {
                        getBrother(node)->_left = rb_tree_node::black;
                        getBrother(node)->_color = rb_tree_node::red;
                        rightRotate(getBrother(node));
                    }

                    getBrother(node)->_color = node->_parent->_color;
                    node->_parent->_color = rb_tree_node::black;
                    getBrother(node)->_right->_color = rb_tree_node::black;
                    leftRotate(node->_parent);
                    node = _head;
                }
            } else {
                if (getBrother(node)->_color == rb_tree_node::red) {
                    getBrother(node)->_color = rb_tree_node::black;
                    node->_parent->_color = rb_tree_node::red;
                    rightRotate(node->_parent);
                }

                if (areChildsBlack(getBrother(node))) {
                    getBrother(node)->_color = rb_tree_node::red;
                } else {
                    if (!getBrother(node)->_left
                        || getBrother(node)->_left->_color == rb_tree_node::black) {
                        getBrother(node)->_right = rb_tree_node::black;
                        getBrother(node)->_color = rb_tree_node::red;
                        leftRotate(getBrother(node));
                    }

                    getBrother(node)->_color = node->_parent->_color;
                    node->_parent->_color = rb_tree_node::black;
                    getBrother(node)->_left->_color = rb_tree_node::black;
                    rightRotate(node->_parent);
                    node = _head;
                }
            }
        }

        node->_color = rb_tree_node::black;
        _head->_color = rb_tree_node::black;
    }

public:
    class Iterator
    {
    public:
        friend class mrb_tree<K, V>;
        explicit Iterator(rb_tree_node *node)
            : _ptr(node)
        {}

        rb_tree_node *operator->() { return _ptr; }

        rb_tree_node &operator*() { return *_ptr; }

        Iterator &operator++()
        {
            if (!_ptr) {
                return *this;
            }

            if (_ptr->_right != nullptr) {
                _ptr = _ptr->_right;

                while (_ptr->_left != nullptr) {
                    _ptr = _ptr->_left;
                }
            } else {
                while (_ptr->parent != nullptr && _ptr->parent->right == _ptr) {
                    _ptr = _ptr->parent;
                }
                _ptr = _ptr->parent;
            }

            return *this;
        }

        bool operator==(const Iterator &other) { return _ptr == other._ptr; }

        bool operator!=(const Iterator &other) { return !(*this == other); }

    private:
        rb_tree_node *_ptr;
    };

    Iterator begin() { return Iterator(_head); }
    Iterator end() { return Iterator(nullptr); }

private:
    rb_tree_node *_head{nullptr};
};

template<typename K, typename V>
class mmap : public mrb_tree<K, V>
{
public:
    V &operator[](const K &key)
    {
        auto t = mrb_tree<K, V>::find(key);
        if (t != nullptr) {
            return t->_value;
        };
        mrb_tree<K, V>::insert(key, V());
        return mrb_tree<K, V>::find(key)->_value;
    };
};

template<typename V>
class mset : public mrb_tree<V, V>
{
public:
    void insertVal(V value) { mrb_tree<V, V>::insert(value, value); }

    typename mrb_tree<V, V>::Iterator findVal(V value)
    {
        return typename mrb_tree<V, V>::Iterator(mrb_tree<V, V>::find(value));
    }
};

#endif // MRB_TREE_H
