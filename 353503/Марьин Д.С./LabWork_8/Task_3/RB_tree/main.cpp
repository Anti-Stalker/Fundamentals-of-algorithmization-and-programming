#include <iostream>
#include "RB_Tree.h"
int main()
{
    RB_Tree<int,std::string> tree;
    tree.insert(1,"two");
    tree.insert(2,"three");
    tree.insert(3,"four");
    tree.insert(4,"five");
    tree.insert(6,"six");
    tree.insert(7,"seven");
    tree.insert(8,"eight");
    tree.insert(9,"nine");
    tree.insert(10,"ten");
    tree.erase(2);
    tree.print();
    return 0;
}
