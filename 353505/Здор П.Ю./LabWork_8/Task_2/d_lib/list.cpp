#include "list.h"

list::list(int size) {
    while(sch!=size)
    {
        push_back(INT_MAX);
        sch++;
    }


}


void list::push_back(int val)

{
    if(sch==0){

    //n=k;
    //n1.lock()->nxt1.lock()=nullptr;
    std::shared_ptr<Node> f1=std::make_shared<Node>();
    f=f1;
    q.push_back(f1);
    std::shared_ptr<Node>l=f.lock();
    f.lock()->val=val;
    n=f1;
    }

    else
    {
        std::shared_ptr<Node> j1=std::make_shared<Node>();
        std::weak_ptr<Node> j=j1;
        q.push_back(j1);
        f.lock()->nxt=j1;
        f.lock()->nxt1=f.lock()->nxt;
        if(f.lock())
        f=f.lock()->nxt;
        f.lock()->val=val;
    }
}
int list::index(int ind)
{
    int sc=0;
    std::shared_ptr<Node> l1=std::make_shared<Node>();
    std::weak_ptr<Node> l=l1;
    l=n;
    if(ind==0) return l.lock()->val;
    else{
        l=n;
        while(sc<ind)
        {
            l=l.lock()->nxt;

            sc++;
        }
        return l.lock()->val;
    }
}
void list::ins_ind(int ind,int val)
{
    int sc=0;
    std::weak_ptr<Node> l=n;
    if(ind==0) l.lock()->val=val;
    else{
        l.lock()=n.lock();
        while(sc<ind)
        {
            l=l.lock()->nxt;

            sc++;
        }
       l.lock()->val=val;
    }
}
