#ifndef BINARYSEARCHTREEEXTENDED_H
#define BINARYSEARCHTREEEXTENDED_H

#include "binarysearchtree.h"

class BinarySearchTreeExtended : public BinarySearchTree {
public:
    void swapMinMax();

private:
    Node* findMin(Node* node);
    Node* findMax(Node* node);
};

#endif // BINARYSEARCHTREEEXTENDED_H
