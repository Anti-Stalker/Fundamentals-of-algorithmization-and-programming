#ifndef NODE_H
#define NODE_H
#include<memory>
struct Node
{
    int val;
    std::shared_ptr<Node> nxt;
    std::weak_ptr<Node> nxt1=nxt;
};
#endif // NODE_H
