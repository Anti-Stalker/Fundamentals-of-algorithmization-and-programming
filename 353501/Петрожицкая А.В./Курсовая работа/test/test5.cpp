#include <iostream>

int main() {
  for (int t = 0; t < 100; t++) {
    std::cout << t;
    if (t == 10) {
      break;
    }
  }
  return 0;
}