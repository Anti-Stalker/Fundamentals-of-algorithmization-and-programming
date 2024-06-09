#include "funcsforquick.h"

int partition(int *arr, int l, int r)
{
    int pivot = arr[l];
    int m = l;

    for(int i = l; i < r; ++i){
        if(arr[i] < arr[pivot]){
            std::swap(arr[i], arr[m]);

            ++m;
        }
    }
    return m;
}
