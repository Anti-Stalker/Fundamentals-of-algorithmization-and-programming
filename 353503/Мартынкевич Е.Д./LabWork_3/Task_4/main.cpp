#include <iostream>

void hanoi(int a, char place1 = 'A', char place2 = 'C') {
    if (a > 1) {
        hanoi(a - 1, place1, 'A' + 'B' + 'C' - place1 - place2);
        std::cout << a << " : " << place1 << "->" << place2 << '\n';
        hanoi(a - 1,  'A' + 'B' + 'C' - place1 - place2, place2);
    }
    else {
        std::cout << a << " : " << place1 << "->" << place2 << '\n';
    }
}

int main()
{
    hanoi(10);
}
