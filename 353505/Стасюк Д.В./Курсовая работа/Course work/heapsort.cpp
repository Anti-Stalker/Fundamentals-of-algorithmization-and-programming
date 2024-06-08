#include "heapsort.h"
#include "orders.h"
#include <vector>


bool compare(Order &l, Order &r, std::string field) {
    if (field == "price") {
        return l.price > r.price;
    }
    if (field == "volume") {
        return l.volume > r.volume;
    }
    if (field == "date") {
        return l.date > r.date;
    }
    return l.id > r.id;
}



// to heapify a subtree rooted with node i which is an index in array[]
void heapify(std::vector<Order> &arr, int size, int i, std::string field) {
    int max = i; // initialize max as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // if left child is larger than root
    if (left < size && compare(arr[left], arr[max], field))
        max = left;

    // if right child is larger than max
    if (right < size && compare(arr[right], arr[max], field))
        max = right;

    // if max is not root
    if (max != i) {
        // swap
        Order temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;

        // recursively heapify the affected sub-tree
        heapify(arr, size, max, field);
    }
}

void heapSort(std::vector<Order> &arr, std::string field) {
    int size = arr.size();

    // build heapSort (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i, field);
    }

    // one by one extract an element from heapSort
    for (int i = size - 1; i >= 0; i--) {
        // move current root to end
        Order temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call max heapify on the reduced heapSort
        heapify(arr, i, 0, field);
    }
}
