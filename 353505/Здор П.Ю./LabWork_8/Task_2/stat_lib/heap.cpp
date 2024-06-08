#include "heap.h"
heap::heap()
{
    h=new int[maximum]{INT_MAX};
    size=0;
}
void heap::create(int val)
{
    h[size]=val;
    size++;
    up(size-1);
}
void heap::down(int ind)
{
    while (ind < size) {
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        int small = ind;

        if (left < size && h[left] < h[small]) {
            small = left;
        }
        if (right < size && h[right] < h[small]) {
            small = right;
        }

        if (small != ind) {
            std::swap(h[ind], h[small]);
            ind = small;
        }
        else break;

    }
}

void heap::up(int ind)
{
    while (ind > 0) {
        int p_ind = (ind - 1) / 2;
        if (h[ind] < h[p_ind]) {
            std::swap(h[ind], h[p_ind]);
            ind = p_ind;
        }
        else break;

    }
}
int heap::fmin()
{
    if(size==0) throw;
    else
    {
        return h[0];
    }
}
void heap::delmin(){
    if(size==0) throw;
    h[0]=h[size-1];
    h[size-1]=INT_MAX;
    size--;
    if (size > 0) {
        down(0);
    }
}
