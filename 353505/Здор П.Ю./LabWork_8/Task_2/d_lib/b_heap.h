#ifndef B_HEAP_H
#define B_HEAP_H

#include "b_heap_global.h"
#include "list.h"

class B_HEAP_EXPORT B_heap
{
private :
    static const int maximum =1000;
    int size=0;
    list *l;
public:
    B_heap();
    void create(int);
    void up(int);
    void down(int);
    int fmin();
    void delmin();
};

#endif // B_HEAP_H
