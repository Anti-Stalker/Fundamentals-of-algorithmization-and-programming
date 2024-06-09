#include <iostream>

std::string foo(int a, std::string& str) {
    str.insert(str.begin(), a % 2 + 48);
    if (a == 1) {
        return str;
    }
    else
        return foo(a / 2, str);
}


int main()
{
    std::cout << foo(66, *new std::string());
}
