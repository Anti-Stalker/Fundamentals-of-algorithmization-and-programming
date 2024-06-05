#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;
    if (x == 0 && y == 0){
        std::cout << "ERROR";
    }
    else if (x == 0 || y == 0){
        std::cout << "YES";
    }
    else if (((int)x % (int)y == 0) || ((int)y % (int)x == 0)){
        std::cout << "YES";
    }
    else if (((int)x % (int)y != 0) && ((int)y % (int)x != 0)){
        std::cout << "NO";
    } 
    return 0;
}
