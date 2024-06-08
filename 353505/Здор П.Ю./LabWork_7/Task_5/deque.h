    #ifndef DEQUE_H
#define DEQUE_H
#include "node.h"


class deque
{
public:
    deque();
    ~deque();

    void push_back(int);
    void pop_back();
    void solve(deque n,int pos1,int pos2);
    void push_front(int va);
    void pop_front();
    int size();
    int front();
    int back();
    int at(int);
    Node *begin();
    Node *end();

private:

    Node*first=nullptr;
    Node *t=first;
    Node*last=nullptr;
};

#endif // DEQUE_H
