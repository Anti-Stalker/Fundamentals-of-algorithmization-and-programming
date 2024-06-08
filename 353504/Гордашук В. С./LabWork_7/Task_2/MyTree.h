#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H
#include <QString>
#include <QVector>
#include "node.h"
class BST
{
    Node *root = nullptr;

public:
    BST(){}

    void fill(QVector<std::pair<int,QString>>data)
    {
        for(auto& i:data)
            insert(root, i.first, i.second);
    }

    void insert(int key, QString value) { insert(root, key, value);
    }
    void insert(Node *& v,int key,QString fullName)
    {
        if(v==nullptr)
        {
            v = new Node(key, fullName);
            return;
        }
        if(key<=v->key)
        {
            insert(v->left,key,fullName);
            return;
        }
        insert(v->right, key, fullName);
    }

    QString find(int key) { return find(root, key);
    }
    QString find(Node * v,int key)
    {
        if(v==nullptr)
            return "";
        if(v->key==key)
            return v->fullName;
        if(key<=v->key)
        {
            return find(v->left, key);
        }
        return find(v->right, key);
    }
void remove(int key,bool left=false)
{
    Node * pred=nullptr;
    return remove(key,root,pred,left);
}

void remove(int key, Node *v,Node *& pred,bool left)
    {
        if(v==nullptr)
            return;
        if(key==v->key)
        {
            if(v->left==v->right&&v->left==nullptr)
            {
                delete v;
                if(pred==nullptr)// 1 v
                {
                    root=nullptr;
                    return;
                }

                if(left)
                    pred->left=nullptr;
                else
                    pred->right=nullptr;
            }
            else if(v->left==nullptr)
            {
                if(pred==nullptr)
                {
                    root=v->right;
                }
                else
                {
                    if(left)
                        pred->left=v->right;
                    else
                        pred->right=v->right;
                }
                delete v;
            }
            else if(v->right==nullptr)//without right
            {
                if(pred==nullptr)//Root
                {
                    root=v->left;
                }
                else
                {
                    if(left)
                        pred->left=v->left;
                    else
                        pred->right=v->left;
                }
                delete v;
            }
            else
            {
                Node *Successor = v->right;
                while(Successor->left!=nullptr)
                    Successor = Successor->left;

                v->key = Successor->key;
                v->fullName = Successor->fullName;
                remove(Successor->key, v->right, v, true);
            }
            return;
        }
        if(key<v->key)
        {
            remove(key, v->left, v, true);
                return;
        }
        remove(key, v->right, v, false);
    }
    int height(Node * v)
    {
        if(v==nullptr)
            return 0;
        return std::max(height(v->left), height(v->right)) + 1;
    }
    void balance() { return balance(root);
    }
    void balance(Node *& v)
    {
        if(v==nullptr)return;

        int delta=height(v->left)-height(v->right);

        if(delta>1)
        {
            if(height(v->left->right)>height(v->left->left))
                Lrotate(v->left);
            Rrotate(v);
        }
        if(delta<-1)
        {
            if(height(v->right->left)>height(v->right->right))
                Rrotate(v->left);
            Lrotate(v);
        }

        balance(v->left);
        balance(v->right);
    }

    void Lrotate(Node *&v)
    {
        Node * temp=v->right;
        v->right=temp->left;
        temp->left=v;
        v=temp;
    }

    void Rrotate(Node *&v)
    {
        Node * temp=v->left;
        v->left=temp->right;
        temp->right=v;
        v=temp;
    }
    void prefOrder(QString& way)
    {
        prefOrder(root,way);
    }
    void prefOrder(Node * v, QString& way)
    {
        if(v==nullptr)return;
        way+=QString::fromStdString("{"+std::to_string(v->key))+", "+v->fullName+"}\n";
        prefOrder(v->left,way);
        prefOrder(v->right,way);
    }

    void infOrder(QString& way)
    {
        infOrder(root,way);
    }
    void infOrder(Node * v, QString& way)
    {
        if(v==nullptr)return;

        infOrder(v->left,way);
        way+=QString::fromStdString("{"+std::to_string(v->key))+", "+v->fullName+"}\n";
        infOrder(v->right,way);
    }

    void postfOrder(QString& way)
    {
        postfOrder(root,way);
    }
    void postfOrder(Node * v, QString& way)
    {
        if(v==nullptr)return;

        postfOrder(v->left,way);

        postfOrder(v->right,way);
        way+=QString::fromStdString("{"+std::to_string(v->key))+", "+v->fullName+"}\n";
    }
    Node* getRoot() const
    {
        return root;
    }
    int calculateRightNodesNumber()
    {
        if (root == nullptr) {
            return 0;
        }
        int count = 0;
        for (auto rt = root; rt != nullptr;) {
            ++count;
            rt = rt->right;
        }
        return count;
    }
};



#endif // BINSEARCHTREE_H
