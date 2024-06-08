#include <iostream>
#include "Bitset.h"

int main()
{
    Bitset<32> t;

    std::cout << t.to_string() << "\n";
    t.set(3);
    std::cout << t.to_string();
}
