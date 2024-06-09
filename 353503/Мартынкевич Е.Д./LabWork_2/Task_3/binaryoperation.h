#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include <expression.h>

class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression* firstNumb, char opertion, Expression* secondNumb);
    ~BinaryOperation();
    double evaluate();

private:
    Expression* firstNumb;
    char opertion;
    Expression* secondNumb;
};

#endif // BINARYOPERATION_H
