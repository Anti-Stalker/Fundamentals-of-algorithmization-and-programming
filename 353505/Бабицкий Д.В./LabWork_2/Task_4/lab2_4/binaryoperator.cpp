#include "binaryoperator.h"
BinaryOperation::BinaryOperation(Expression *left_pointer,char expression,Expression *right_pointer){
    BinaryOperation::left_pointer=left_pointer;
    BinaryOperation::expression=expression;
    BinaryOperation::right_pointer=right_pointer;
}
double BinaryOperation::evaluate(){
    if(expression=='+'){
        return left_pointer->evaluate() + right_pointer->evaluate();
    }
    else if(expression=='-'){
        return left_pointer->evaluate() - right_pointer->evaluate();
    }
    else if(expression=='*'){
        return left_pointer->evaluate() * right_pointer->evaluate();
    }
    else if(expression=='/') {
        if(right_pointer->evaluate()!=0){
            return left_pointer->evaluate() / right_pointer->evaluate();
        }
        else return 0;
    }
    else return 0;
}
BinaryOperation::~BinaryOperation(){
    delete left_pointer;
    delete right_pointer;
}
