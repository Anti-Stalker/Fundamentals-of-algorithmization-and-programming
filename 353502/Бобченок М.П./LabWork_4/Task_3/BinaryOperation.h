//
// Created by u on 25.05.24.
//

#include "Expression.h"

#ifndef TASK3_BINARYOPERATION_H
#define TASK3_BINARYOPERATION_H


class BinaryOperation : public Expression
{
public:
    enum Operation {PLUS, MINUS, MULTIPLY, DIVIDE};

private:
    Expression *left = nullptr, *right = nullptr;
    Operation operation;

public:

    double evaluate() override;

    BinaryOperation();
    BinaryOperation(Expression *left, Operation operation, Expression *right);
};


#endif //TASK3_BINARYOPERATION_H
