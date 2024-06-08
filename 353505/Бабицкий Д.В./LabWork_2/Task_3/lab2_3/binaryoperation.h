#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H
#include "expression.h"
class BinaryOperation : public Expression
{
private:
    Expression *left_pointer;
    Expression *right_pointer;
    char expression;
public:
    BinaryOperation(Expression *left_pointer,char expression,Expression *right_pointer);
    double evaluate() override;
    ~BinaryOperation();
};

#endif // BINARYOPERATION_H
