#ifndef MYTREE_H
#define MYTREE_H

#include "tree.h"
class MyTree : public Tree
{
private:
    int countRightNodes(Node*);
public:
    using Tree::Tree;
    int countRightNodes();
};

#endif // MYTREE_H
