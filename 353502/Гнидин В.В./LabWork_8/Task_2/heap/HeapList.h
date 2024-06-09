//
// Created by darina on 5/30/24.
//

#ifndef TASK2_HEAPLIST_H
#define TASK2_HEAPLIST_H


#include <cstddef>
#include <vector>
#include <memory>
#include "Heap.h"

class HeapList : public Heap{
    int _level = 0;
    int _number_level = 0;
    int _size = 0;

    std::vector<int> heap;

    struct Node
    {
        int value;
        std::weak_ptr<Node> parent;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
    };

    std::shared_ptr<Node> root;
    std::shared_ptr<Node> found_node;

    void siftUp(std::shared_ptr<Node> node);
    void siftDown(std::shared_ptr<Node> node);

    void findValue(std::shared_ptr<Node> node, int value);

    void getHeap(std::shared_ptr<Node> node);

    void increaseElement(std::shared_ptr<Node> node, int delta);
    void decreaseElement(std::shared_ptr<Node> node, int delta);
public:
    HeapList();

    void add(int value) override;
    int getMax() override;
    void extractMax() override;

    void increaseValue(int value, int delta) override;
    void decreaseValue(int value, int delta) override;

    int size() override;
    void clear() override;
    std::vector<int> getHeap() override;

};


#endif //TASK2_HEAPLIST_H
