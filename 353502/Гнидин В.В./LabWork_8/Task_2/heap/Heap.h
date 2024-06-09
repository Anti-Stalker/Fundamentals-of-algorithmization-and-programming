//
// Created by volodya-petarda on 5/31/24.
//

#ifndef LAB8_2_HEAP_H
#define LAB8_2_HEAP_H


#include <vector>

class Heap {
public:
    virtual void add(int value){};
    virtual int getMax(){};
    virtual void extractMax(){};

    virtual void increaseValue(int value, int delta){};
    virtual void decreaseValue(int value, int delta){};

    virtual int size(){};
    virtual void clear(){};
    virtual std::vector<int> getHeap(){};
};


#endif //LAB8_2_HEAP_H
