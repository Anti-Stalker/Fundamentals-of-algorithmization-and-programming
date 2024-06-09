#ifndef HASH_H
#define HASH_H

#include <QVector>
#include <QPair>
#include "j_stack.h"
class Hash {
private:
    int capacity=0;
     j_stack table1;
     j_stack table2;


    int hashFunction(int );
    int re_hash(int);

public:
    Hash(int V);
    void insert(int , int );
    void del(int );
    j_stack hash_table_display1();
    j_stack hash_table_display2();

    int find(int);
    int fib(int);
    void delete_ch();
};

#endif // HASH_H
