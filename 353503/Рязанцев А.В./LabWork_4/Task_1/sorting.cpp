#include "sorting.h"

void HeapSort(int *arr, int size, int& counter)
{
    for(int i = size / 2 - 1; i >= 0; i--){
        heapify(arr, size, i, counter);
    }

    for(int i = size - 1; i >= 0; --i){
        counter++;
        std::swap(arr[i], arr[0]);

        heapify(arr, i, 0, counter);
    }
}

void QuickSort(int *arr, int l, int r, int& counter)
{
    int pivot = arr[(l + r) / 2];

    int start = l;
    int end = r;

    while(start <= end){
        while(arr[start] < pivot){
            ++start;
            counter++;
        }
        while (arr[end] > pivot) {
            --end;
            counter++;
        }
        if(start <= end){
            counter++;
            std::swap(arr[start++], arr[end--]);
        }
    }

    if(l < end){
        QuickSort(arr, l, end, counter);
    }
    if(r > start){
        QuickSort(arr, start, r, counter);
    }
}

void MergeSort(int *arr, int l, int r, int size, int& counter)
{
    if(r == l){
        counter++;
        return;
    }

    if(r - l == 1){
        if(arr[r] < arr[l]){
            counter++;
            std::swap(arr[r], arr[l]);
        }

        return;
    }

    int middle = (r + l) / 2;

    MergeSort(arr, l, middle, size / 2, counter);
    MergeSort(arr, middle + 1, r, size / 2, counter);

    int* buf = new int[size];
    int _l = l;
    int _r = middle + 1;
    int cur = 0;

    while(r - l + 1 != cur)
    {
        counter++;
        if(_l > middle)
        {
            buf[cur++] = arr[_r++];
        }
        else if(_r > r)
        {
            buf[cur++] = arr[_l++];
        }
        else if(arr[_l] > arr[_r])
        {
            buf[cur++] = arr[_r++];
        }
        else
        {
            buf[cur++] = arr[_l++];
        }
    }

    for(int i = 0; i < cur; ++i)
    {
        arr[i + l] = buf[i];
    }

    delete[] buf;
}
