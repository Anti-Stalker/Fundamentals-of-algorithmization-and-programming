#ifndef LIST_H
#define LIST_H
#include "node.h"
#include <climits>
#include <vector>
class list
{
private :
    std::weak_ptr<Node> f;
    std::weak_ptr<Node> n;
    int sch=0;
    std::vector<std::shared_ptr<Node>> q;
public:
    list(int);
    void push_back(int);
    int index(int);
    void ins_ind(int,int);
};

#endif // LIST_H
