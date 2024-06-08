#ifndef HEAP_H
#define HEAP_H
#include <QApplication>
#include <iostream>

class heap
{
private :
   static const int maximum =1000;
    int size=0;
   int *h;
public:
    heap();
    void create(int);
    void up(int);
    void down(int);
    int fmin();
    void delmin();
};

#endif // HEAP_H
