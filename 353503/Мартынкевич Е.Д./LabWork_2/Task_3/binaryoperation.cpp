#include "binaryoperation.h"

BinaryOperation::BinaryOperation(Expression *firstNumb, char opertion, Expression *secondNumb)
{
    this->firstNumb = firstNumb;
    this->opertion = opertion;
    this->secondNumb = secondNumb;
}

BinaryOperation::~BinaryOperation()
{
    delete this->firstNumb;
    delete this->secondNumb;
}

double BinaryOperation::evaluate()
{
    switch (opertion) {
    case '+':
        return this->firstNumb->evaluate() + this->secondNumb->evaluate();
        break;
    case '-':
        return this->firstNumb->evaluate() - this->secondNumb->evaluate();
        break;
    case '*':
        return this->firstNumb->evaluate() * this->secondNumb->evaluate();
        break;
    case '/':
        return this->firstNumb->evaluate() / this->secondNumb->evaluate();
        break;
    default:
        return 0;
        break;
    }
}
