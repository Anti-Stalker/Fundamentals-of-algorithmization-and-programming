#include <QApplication>
#include <iostream>
#include <binaryoperation.h>
#include <number.h>

bool check_equals(Expression const* left, Expression const* right) {
    return *(void**)left == *(void**)right;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // сначала создаём объекты для подвыражения 4.5 * 5
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    // потом используем его в выражении для +
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
    // вычисляем и выводим результат: 25.5
    std::cout << expr->evaluate() << std::endl;
    // тут освобождаются *все* выделенные объекты
    // (например, sube будет правым операндом expr, поэтому его удалять не нужно)
    delete expr;

    return a.exec();
}
