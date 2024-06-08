#ifndef RBTREE_H
#define RBTREE_H
#include "node.h"
template <class T,class T1>
class RBTree
{
public:
    void insert(T key ,T1 value) {
        std::shared_ptr<Node<T,T1>> tmp=rt;
        std::shared_ptr<Node<T,T1>> p=std::make_shared<Node<T, T1>>();
        while (tmp) {
            p=tmp;
            if (tmp->info.first> key)
            {
                tmp = tmp->left;
            }
            else if (tmp->info.first < key)
            {
                tmp = tmp->right;
            }
            else
            {
                return;
            }
        }
        tmp=std::make_shared<Node<T, T1>>();
        tmp->info.first=key;
        tmp->info.second=value;
        tmp->color=0;
        tmp->parent=p;
        if(rt!=nullptr){
            if(tmp->key()>p->key()) p->right=tmp;
            else if(tmp->key()<p->key()) p->left=tmp;
        }
        else rt=tmp;
        insert_1(tmp);

    }




    std::shared_ptr<Node<T,T1>> find(std::shared_ptr<Node<T,T1>> tmp,T key){

        if(tmp)
        {
            if(tmp->key()==key) return tmp;
            if(tmp->key()>key) return find(tmp->left,key);
            if(tmp->key()<key) return find(tmp->right,key);
        }
        return nullptr;
    }


    void rot_right(std::shared_ptr<Node<T,T1>> smth)
    {
        if (smth == nullptr || smth->left == nullptr) return;
        std::shared_ptr<Node<T,T1>>tmp=smth->left;
        tmp->parent=smth->parent;
        if(smth->parent.lock()!=nullptr)
        {
            std::shared_ptr<Node<T,T1>> p = smth->parent.lock();

            if (p->left==(smth)) {
                p->left = tmp;
            }
            else {
                p->right = tmp;
            }
        }
        else
        {
            rt=tmp;
        }
        smth->left=tmp->right;
        if (tmp->right) {
            tmp->right->parent = smth;
        }
        smth->parent=tmp;
        smth->right=smth;

    }


    void rot_left(std::shared_ptr<Node<T,T1>>smth)
    {
        if (smth == nullptr || smth->right == nullptr) return;
        std::shared_ptr<Node<T,T1>>tmp=smth->right;
        tmp->parent=smth->parent;
        if(smth->parent.lock()!=nullptr)
        {
            std::shared_ptr<Node<T,T1>> p = smth->parent.lock();

            if (p->left==(smth)) {
                p->left = tmp;
            }
            else {
                p->right = tmp;
            }
        }
        else
        {
            rt=tmp;
        }
        smth->right=tmp->left;
        if (tmp->left) {
            tmp->left->parent = smth;
        }
        smth->parent=tmp;
        tmp->left=smth;
    }


    std::shared_ptr <Node<T,T1>> grandparent(std::shared_ptr<Node<T,T1>> node) {
        std::shared_ptr<Node<T,T1>> p = node->parent.lock();
        if (p && !p->parent.expired())
        {
            return p->parent.lock();
        }
        else {
            return std::make_shared<Node<T,T1>>();
        }
    }
    std::shared_ptr <Node<T, T1>>uncle(std::shared_ptr<Node<T,T1>> node) {
        std::shared_ptr<Node<T,T1>> tmp = grandparent(node);

        if (tmp) {
            if (tmp->left==(node->parent.lock()))
            {
                return tmp->right;
            }
            else {
                return tmp->left;
            }
        }
        else {
            return std::make_shared<Node<T,T1>>();
        }
    }

    QVector<QPair<T,T1>> p_ord(std::shared_ptr<Node<T,T1>> n)
    {
        QVector<QPair <T,T1>>pair2;
        if (n != nullptr) {
            p_ord(n->left);
            p_ord(n->right);
            QPair <T,T1> p1;
            p1.first=n->value();
            p1.second=n->key();
            pair2.push_back(p1);
        }
        return pair2;
    }

    void insert_1(std::shared_ptr<Node<T,T1>> tmp)
    {
        if(tmp->parent.expired()) tmp->color=1; //если нода корень
        else insert_2(tmp);
    }

    std::shared_ptr <Node<T,T1>> rot() {
        return rt;
    }
    void insert_2(std::shared_ptr<Node<T,T1>> tmp)
    {
        if(!tmp->parent.lock()->color)  // если у родителя цвет НЕ черный все НЕ ок
        {
            std::shared_ptr<Node<T,T1>> uncl=uncle(tmp);
            if (uncl && !uncl->color) {
                tmp->parent.lock()->color = 1;
                uncl->color = 1;
                std::shared_ptr<Node<T,T1>> grand = grandparent(tmp);
                grand->color = 0;
                insert_1(grand);
            }
            else insert_3(tmp);
        }


    }


    void insert_3(std::shared_ptr<Node<T,T1>> tmp)
    { //Повороты для случая дядя - черный : нода справа
        std::shared_ptr<Node<T,T1>> g = grandparent(tmp), tmp1 = tmp;
        std::shared_ptr<Node<T,T1>> p = tmp->parent.lock();
        if(tmp){
        if (tmp==p->right && p==g->left) {
            rot_left(p);
            tmp1 = tmp->left;
        } else if (tmp==p->left && p==g->right) {
            rot_right(p);
            tmp1 = tmp->right;
        }
        }
        insert_4(tmp1);
    }

    void insert_4(std::shared_ptr<Node<T,T1>> tmp)
    {   if(tmp){
        //Повороты для случая дядя - черный  : нода слева
        std::shared_ptr<Node<T,T1>> g = grandparent(tmp);
        std::shared_ptr<Node<T,T1>> p = tmp->parent.lock();
        p->color = 1;
        g->color = 0;

        if (tmp==p->left) {
            rot_right(g);
        }
        else {
            rot_left(g);
        }
        }
    }


    void remove(T key)
    {
        std::shared_ptr<Node<T,T1>> tmp = find(rt, key);
        if(tmp.expired()) return;
        if(tmp->parent.expired() && tmp->left.expired() && tmp->right.expired())
        {
            rt=nullptr;
        }
        if(tmp->left.expired() && tmp->right.expired())
        {
            if(tmp->color)
            {
                delete_1(tmp);
            }
            else
            {
                std::shared_ptr<Node<T,T1>> parent = tmp->parent;

                if (parent->left==tmp)  parent->left=nullptr;
                else  parent->right = nullptr;

            }
        }
        else
        {
            if(tmp->left && tmp->right)
            {
                std::shared_ptr<Node<T,T1>> removed = tmp->left;
                while (removed->right)
                {
                    removed = removed->right;
                }
                tmp->info = removed->info;
                tmp = removed;
            }
            std::shared_ptr<Node<T,T1>> child;
            if(!tmp->left.expired()) child=tmp->left;
            else child->right;
            child->parent = tmp->parent;
            std::shared_ptr<Node<T,T1>> parent = tmp->parent;
            if (tmp->parent) {
                if (tmp==parent->left)
                {
                    parent->left = child;
                } else
                {
                    parent->right = child;
                }
            }
            else {
                rt = child;
                if (tmp->color)
                {
                    if (!child->color)
                    {
                        child->color = 1;
                    }
                    else
                    {
                        delete_1(child);
                    }
                }
            }
        }
    }

    void delete_1(std::shared_ptr<Node<T,T1>> node)
    {
        while (node != rt && (node == nullptr || node->color == 1)) {
            if (node == node->parent->left) {
                std::shared_ptr<Node<T,T1>> sibling = node->parent->right;


                if (sibling != nullptr && sibling->color == 0) {
                    sibling->color = 1;
                    node->parent->color = 0;
                    leftRotate(node->parent);
                    sibling = node->parent->right;
                }


                if (sibling == nullptr || sibling->left == nullptr || ((sibling->left->color == 1) &&(sibling->right == nullptr || sibling->right->color == 1))) {
                    if (sibling != nullptr) sibling->color = 0;
                    node = node->parent;
                } else {

                    if (sibling->right == nullptr || sibling->right->color == 1) {
                        if (sibling->left != nullptr) sibling->left->color = 1;
                        sibling->color = 0;
                        rightRotate(sibling);
                        sibling = node->parent->right;
                    }

                    if (sibling != nullptr) {
                        sibling->color = node->parent->color;
                        node->parent->color = 1;
                        if (sibling->right != nullptr) sibling->right->color = 1;
                        leftRotate(node->parent);
                    }
                    node = rt;
                }
            } else {
                std::shared_ptr<Node<T,T1>> sibling = node->parent->left;


                if (sibling != nullptr && sibling->color == 0) {
                    sibling->color = 1;
                    node->parent->color = 0;
                    rightRotate(node->parent);
                    sibling = node->parent->left;
                }


                if (sibling == nullptr ||((sibling->left == nullptr || sibling->left->color == 1) && (sibling->right == nullptr || sibling->right->color == 1)))
                {
                    if (sibling != nullptr) sibling->color = 0;
                    node = node->parent;
                } else {
                    if (sibling->left == nullptr || sibling->left->color == 1)
                    {
                        if (sibling->right != nullptr) sibling->right->color = 1;
                        sibling->color = 0;
                        leftRotate(sibling);
                        sibling = node->parent->left;
                    }


                    if (sibling != nullptr)
                    {
                        sibling->color = node->parent->color;
                        node->parent->color = 1;
                        if (sibling->left != nullptr) sibling->left->color = 1;
                        rightRotate(node->parent);
                    }
                    node = rt;
                }
            }
        }
        if (node != nullptr) {
            node->color = 1;
        }
    }

    T1& operator[](T key){
        auto node = find(rt, key);
        if (node) {
            return node->value();
        } else {
            insert(key, T1());
            node = find(rt, key);
            return node->value();
        }
    }

    void clear(std::shared_ptr<Node<T, T1>> node){
        if (node) {
            clear(node->left);
            clear(node->right);
            node.reset();
        }
    }

    bool find_key(T key)
    {

        auto node = find(rt, key);
        if (!node) {
            return false;
        }
        return true;
    }

    class Iterator {
    protected:
        friend class RBTree<T, T1>;
        Iterator(std::shared_ptr<Node<T,T1>> rt)
        {
            current = rt ;
            if(!current) return;
            while (current->left != nullptr)
                current = current->left;
        }

    public:


        Iterator &operator++() {
            if (!current)
                return *this;

            if (current->right != nullptr) {
                current = current->right;

                while (current->left != nullptr)
                    current = current->left;
            } else {
                while (current->parent != nullptr && current->parent->right == current) {
                    current = current->parent;
                }
                current = current->parent;
            }


            return *this;
        }



    protected:
        std::shared_ptr<Node<T,T1>> current;
    };

    Iterator begin() { return Iterator(rt); }
    Iterator end() { return Iterator(nullptr); }
private:
    std::shared_ptr<Node<T,T1>> rt;
};

#endif // RBTREE_H
