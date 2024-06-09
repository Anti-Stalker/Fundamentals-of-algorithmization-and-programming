#include <QCoreApplication>
#include <iostream>

unsigned long long Akkerman(unsigned long long n, unsigned long long m) {
    while (n != 0) {
        if (m == 0) {
            m = 1;
        }
        else {
            m = Akkerman(n, m - 1);
        }

        --n;
    }

    return m + 1;
}

int main()
{
    std::cout << Akkerman(1, 5);
}
