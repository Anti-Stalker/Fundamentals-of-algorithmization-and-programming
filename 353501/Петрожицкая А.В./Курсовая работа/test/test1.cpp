#include <iostream>
#include <iomanip>

int main() {
    long double b1, q, a;
    q = (long double)1 / 1001;
    std::cin >> b1; 
    a = b1 / (1 - q); 
    std::cout << std::setprecision(8) << a; 
    return 0;
}
