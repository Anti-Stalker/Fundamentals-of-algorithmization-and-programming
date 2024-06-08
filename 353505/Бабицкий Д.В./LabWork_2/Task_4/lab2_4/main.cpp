#include "mainwindow.h"
#include "binaryoperator.h"
#include"number.h"
#include <QApplication>
#include<iostream>
bool check_equals(Expression const*left,Expression const *right){
    if(*(int*)left==*(int*)right) return true;
    else return false;
}
int main()
{
    Expression *subs=new BinaryOperation(new Number(4.5),'*',new Number(5));
    Expression *exprs=new BinaryOperation(new Number(3), '*',subs);
   Expression*ex=new Number(5);
   // std::cout << exprs->evaluate() << "\n";
    bool a=check_equals(subs,ex);

    if(a) {
        std::cout << "Yes\n";
    }
    else {
        std::cout << "No\n";
    }
    delete exprs;
}
