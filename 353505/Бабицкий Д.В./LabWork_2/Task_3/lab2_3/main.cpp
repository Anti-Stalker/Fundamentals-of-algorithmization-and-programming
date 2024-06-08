#include "mainwindow.h"
#include "binaryoperation.h"
#include"number.h"
#include <QApplication>
#include<iostream>
int main()
{
    Expression *subs=new BinaryOperation(new Number(4.5),'*',new Number(5));
    Expression *exprs=new BinaryOperation(new Number(3), '*',subs);
    std::cout << exprs->evaluate() << "\n";
    delete exprs;
}
