#include "Expression.h"
#include "BinaryOperation.h"
#include "Number.h"

#include <iostream>

bool check_equals(Expression const* left, Expression const* right)
{
    return (*(size_t*)right == *(size_t*)left);
}

int main()
{
    Expression* sube = new BinaryOperation(new Number(4.5), BinaryOperation::Operation::MULTIPLY, new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), BinaryOperation::Operation::PLUS, sube);

    Expression *q = new Expression();

    void **v = *(void***)q;

    typedef void (*Func);
    ((Func)v[0]);

    std::cout << expr->evaluate() << std::endl;
    delete expr;
}
