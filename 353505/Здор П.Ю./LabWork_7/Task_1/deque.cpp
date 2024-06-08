#include "deque.h"



deque::deque(){};
deque::~deque()
{
    while(last!=nullptr)
    {
        last->nxt=nullptr;
        last=last->prv;
    }
}
void deque::push_back(int va)
{
    if(first==nullptr)
    {
        Node *n=new Node;
        n->val = va;
        n->prv=nullptr;
        n->nxt=nullptr;
        last=n;
        first=last;
    }
    else if (first==last) {
        Node *n=new Node;
        n->val = va;
        n->prv=last;
        n->nxt=nullptr;
        last->nxt=n;
        last=n;
    }
    else
    {
        Node *n=new Node;
        n->val = va;
        n->prv=last;
        n->nxt=nullptr;
        last->nxt=n;
        last=n;
    }
}
void deque::pop_back()
{
    if(first!=nullptr)
    {
        if(last==first)
        {
            delete first;
            first=nullptr;
            last=nullptr;
        }
        else {
            last=last->prv;
            delete last->nxt;
            last->nxt=nullptr;
        }
    }
}
void deque::solve(deque n,int pos1,int pos2)
{
    if(pos1<pos2)
    {
        int position1=pos1;
        int posotion2=pos2;
    }
    else {
        int position1=pos2;
        int posotion2=pos1;
    }
    int tmp=0;
    int tmp1=0;
    Node *iter=first;
    Node *iter3=first;
    if(iter==nullptr) throw;
    else
    {
        while(tmp!=pos1)
        {
            iter=iter->nxt;
            tmp++;
        }
        while(tmp1!=pos2)
        {
            iter3=iter3->nxt;
            tmp1++;
        }
        Node *ttmp=n.begin();
        Node *ttp=n.end();
        iter->nxt=ttmp;
        ttmp->prv=iter;
        iter3->prv=ttp;
        ttp->nxt=iter3;
        iter=first;
    }
}
void deque::push_front(int va)
{
    if(first==nullptr)
    {
        Node *n=new Node;
        n->val=va;
        n->prv=nullptr;
        n->nxt=nullptr;
        first=n;
        last=first;
    }
    else if (first==last) {
        Node *n=new Node;
        n->val = va;
        n->nxt=first;
        n->prv=nullptr;
        first->prv=n;
        first=n;
    }
    else
    {
        Node *n=new Node;
        n->val = va;
        n->nxt=first;
        n->prv=nullptr;
        first->prv=n;
        first=n;
    }
}
void deque::pop_front()
{
    if(first!=nullptr)
    {
        if(last==first)
        {
            delete first;
            first=nullptr;
            last=nullptr;
        }
        else {
            first=first->nxt;
            delete first->prv;
            first->prv=nullptr;
        }
    }
}
int deque::size()
{
    Node *iter=last;
    if(iter==nullptr) return 0;
    else {
        int tmp=1;
        while(iter!=first)
        {
            iter=iter->prv;
            tmp++;
        }
        return tmp;
    }
}
int deque::front()
{
    if(first!=nullptr)
        return first->val;
    else {
        throw;
    }
}
int deque::back()
{
    if(last!=nullptr)
        return last->val;
    else {
        throw;
    }
}
int deque::at(int pos)
{
    Node *iter=last;
    int sizet=size();
    if(iter==nullptr || pos>=sizet) throw;
    else {
        int tmp=0;
        while(tmp!=pos)
        {
            iter=iter->prv;
            tmp++;
        }
        return iter->val;
    }
}
Node* deque::begin()
{
    return first;
}
Node* deque::end()
{
    return last;
}
