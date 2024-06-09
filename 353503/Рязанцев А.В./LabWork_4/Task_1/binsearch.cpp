#include "binsearch.h"

int BinSearch(int *arr, int l, int r, int num_to_find)
{
    int curr_elem = (l + r) / 2;

    if(r - l == 1 && arr[l] != num_to_find){
        return -1;
    }

    if(arr[curr_elem] == num_to_find)
    {
        return curr_elem;
    }
    else if(arr[curr_elem] < num_to_find)
    {
        return BinSearch(arr, curr_elem + 1, r, num_to_find);
    }
    else if(arr[curr_elem] > num_to_find)
    {
        return BinSearch(arr, l, curr_elem - 1, num_to_find);
    }
    return -1;
}
