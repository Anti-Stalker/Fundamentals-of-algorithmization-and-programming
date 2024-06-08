#include <iostream>
#include "binary_heap.h"

int main() {
    binary_heap_list heap;
    for(int i = 0; i < 12 ; ++i){
        heap.add(i);
    }

    heap.show_heap();
    std::cout << "Max - " << heap.getMax() << '\n';
    heap.show_heap();

    binary_heap_array heap2;
    for(int i = 0; i < 12; ++i){
        heap2.add(i);
    }

    heap2.show_heap();
    std::cout << "Max - " << heap2.getMax() << '\n';
    heap2.show_heap();

    return 0;
}
