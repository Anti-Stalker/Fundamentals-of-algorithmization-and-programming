#include "b_heap.h"
B_heap::B_heap()
{
    size=0;
    l=new list(100);
}
void B_heap::create(int val)
{
    l->ins_ind(size,val);
    size++;
    up(size-1);
}
void B_heap::down(int ind)
{
    while (ind < size) {
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        int small = ind;

        if (left < size && l->index(left) < l->index(small)) {
            small = left;
        }
        if (right < size && l->index(right) < l->index(small)) {
            small = right;
        }

        if (small != ind) {
            int tmp=l->index(ind);
            l->ins_ind(ind,l->index(small));
            l->ins_ind(small,tmp);
            ind = small;
        }
        else break;

    }
}

void B_heap::up(int ind)
{
    while (ind > 0) {
        int p_ind = (ind - 1) / 2;
        if (l->index(ind) < l->index(p_ind)) {
            int tmp=l->index(ind);
            l->ins_ind(ind,l->index(p_ind));
            l->ins_ind(p_ind,tmp);
            ind = p_ind;
        }
        else break;

    }
}
int B_heap::fmin()
{
    if(size==0) throw;
    else
    {
        return l->index(0);
    }
}
void B_heap::delmin(){
    if(size==0) throw;
    l->ins_ind(0,l->index(size-1));
    l->ins_ind(size-1,INT16_MAX);

    size--;
    if (size > 0) {
        down(0);
    }
}
