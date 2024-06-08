#include "j_stack.h"


void j_stack::add(int val)
{
    if(n==nullptr)
    {
        n=new Node;
        n->val=val;
        n->nxt=nullptr;
        initial++;
    }
    else
    { if(initial>size)
        {
            throw;
        }
        n->nxt=new Node;
        n->nxt->val=val;
        initial++;
    }
}

Node* j_stack::find(int l)
{
    if(l>initial-1) throw;
    else
    {
        Node *tmp=n;
        int t=0;
        while(l!=t)
        {
            tmp=tmp->nxt;
            t++;
        }
        return tmp;
    }
}
void j_stack::resize(int s)
{
    if(s>size) throw;
    else
    {
        n=new Node;
        int k=1;
        Node *tmp=n;
        while(k<s)
        {
            tmp->nxt=new Node;
            tmp->val=0;
            tmp=tmp->nxt;
            k++;
        }
        initial=k;
        tmp->val=0;
    }
}
int j_stack::sizes(){
    return initial;
}
Node *j_stack::ret_node()
{
     return n;
 }
