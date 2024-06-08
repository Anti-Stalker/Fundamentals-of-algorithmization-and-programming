#ifndef J_STACK_H
#define J_STACK_H
#include"node.h"
class j_stack
{
public:
    void add(int);
    Node* find(int);
    void resize(int );
    int sizes();
    Node *ret_node();
private:
    int size=1000;
    int initial=0;
    Node*n=nullptr;
};

#endif // J_STACK_H
