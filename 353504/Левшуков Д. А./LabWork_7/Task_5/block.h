#ifndef BLOCK_H
#define BLOCK_H
template<typename T>
struct block
{
    T *data=new T[4];
    int left=0;
    int right=0;
    block*prev=nullptr;
    block*next=nullptr;
};
#endif // BLOCK_H
