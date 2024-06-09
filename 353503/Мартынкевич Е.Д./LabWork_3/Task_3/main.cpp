#include <iostream>

int foo(int a) {
    static int buf = 0;
    buf = buf * 10 + a % 10;

    if (a >= 10) {
        return foo (a / 10);
    }
    else {
        return buf;
    }
}

int main()
{
    std::cout << foo(896234567);
}
