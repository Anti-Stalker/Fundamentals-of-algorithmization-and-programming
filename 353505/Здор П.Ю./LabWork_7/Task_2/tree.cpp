#include "tree.h"

Tree::Tree(){

};
int Tree::height(Node*n)
{

    if (n!=nullptr) return n->h;
    else return 0;


}
int Tree::balance(Node *n)
{
    return height(n->left)-height(n->right);
}
Node *Tree::rot_right(Node* smth)
{
    if (smth == nullptr || smth->left == nullptr) return smth;
    Node *tmp=smth->left;
    Node *tmp_r=tmp->right;
    tmp->right=smth;
    smth->left=tmp_r;

    tmp->h= 1 + std::max(height(tmp->left), height(tmp->right));
    smth->h= 1 + std::max(height(smth->left), height(smth->right));
    return tmp;

}
Node* Tree::rot_left(Node* smth)
{
    if (smth == nullptr || smth->right == nullptr) return smth;
    Node *tmp=smth->right;
    Node *tmp_r=tmp->left;
    tmp->left=smth;
    smth->right=tmp_r;

    tmp->h= 1 + std::max(height(tmp->left), height(tmp->right));
    smth->h= 1 + std::max(height(smth->left), height(smth->right));
    return tmp;

}
Node* Tree::create(QString a,int key)
{
    Node*n=new Node;
    n->key=key;
    n->val=a;
    n->left=nullptr;
    n->right=nullptr;
    return n;
}

void Tree::insert(Node* &n,int key,QString val)
{
    if(n==nullptr)
    {
       n=create(val,key);

    }

    if (key < n->key) insert(n->left, key,val);
    else if (key > n->key) insert(n->right, key,val);



    n->h=1+std::max(height(n->left),height(n->right));
    int bal=balance(n);

    if (n->left!=nullptr && bal > 1 && key < n->left->key){
        rot_right(n);
    }
    if (n->right!=nullptr && bal < -1 && key > n->right->key){
        rot_left(n);
    }
    if (n->left!=nullptr && bal> 1 && key > n->left->key) {
        n->left = rot_left(n->left);
        rot_right(n);
    }

    if (n->right!=nullptr && bal < -1 && key < n->right->key) {
        n->right = rot_right(n->right);
         rot_left(n);
    }





}
Node* Tree::fmin(Node *n)
{

        Node* curr = n;
        while (curr && curr->left != nullptr) {
            curr = curr->left;
        }
        return curr;

}
QString Tree::find(Node *n,int key)
{
    if(n==nullptr) throw;
    else
    {
        if(n->key==key) return n->val;
        if(n->key>=key) return find(n->left,key);
        if(n->key<=key) return find(n->right,key);
    }
    throw;
}
Node* Tree::del(Node *n,int key)
{
    if(n==nullptr) throw;
    else
    {
        if(n->key==key){
            if (n->left == nullptr) {
                Node* tmp = n->right;
                delete n;
                return n;
            } else if (n->right == nullptr) {
                Node* temp = n->left;
                delete n;
                return temp;
            }
            Node* temp = fmin(n->right);

            n->key = temp->key;
            n->val=temp->val;

            n->right = del(n->right, n->key);
        }
        if(n->key>=key) return del(n->left,key);
        if(n->key<=key) return del(n->right,key);
    }
    throw;
}
void Tree::pr_ord(Node *n)
{
    if (n != nullptr) {
        QPair <QString,int> p1;
        p1.first=n->val;
        p1.second=n->key;
        pair1.push_back(p1);
        pr_ord(n->left);
        pr_ord(n->right);
    }
}
void Tree::p_ord(Node *n)
{
    if (n != nullptr) {
        p_ord(n->left);
        p_ord(n->right);
        QPair <QString,int> p1;
        p1.first=n->val;
        p1.second=n->key;
        pair2.push_back(p1);
    }
}
void Tree::in_ord(Node *n)
{
    if (n != nullptr) {
        in_ord(n->left);
        QPair <QString,int> p1;
        p1.first=n->val;
        p1.second=n->key;
        pair3.push_back(p1);
        in_ord(n->right);
    }
}
Node* Tree::n1()
{
    return n2;
}
void Tree::ins(int key,QString val)
{
    insert(n2,key,val);
}
void Tree::count()
{

        if (n2 == nullptr) return;

        std::queue<Node*> q;
        q.push(n2);

        int level = 0;
        while (!q.empty()) {
            int nodeCount = q.size();
            l.push_back("Уровень " +QString::number(level)+ ": " +QString::number(nodeCount) + " узлов\n");

            while (nodeCount > 0) {
                Node* node = q.front();
                q.pop();

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);

                nodeCount--;
            }

            level++;
        }

}
QVector <QString> Tree::ret()
{
    return l;
}
