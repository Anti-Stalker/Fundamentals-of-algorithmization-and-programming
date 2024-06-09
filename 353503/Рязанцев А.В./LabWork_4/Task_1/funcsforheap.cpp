#include "funcsforheap.h"

void heapify(int* arr, int size, int i, int& counter){
    int largest = i; // largest = arr[i]

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < size && arr[l] > arr[largest]){
        largest = l;
    }
    if(r < size && arr[r] > arr[largest]){
        largest = r;
    }

    if(largest != i){
        counter++;
        std::swap(arr[i], arr[largest]);
        heapify(arr, size, largest, counter);
    }
}

