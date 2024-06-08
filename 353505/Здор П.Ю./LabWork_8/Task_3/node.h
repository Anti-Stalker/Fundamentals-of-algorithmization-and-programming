#ifndef NODE_H
#define NODE_H
#include <QPair>
#include<memory>
template <class T,class T1>
struct Node
{
public:
    QPair <T,T1> info;
    std::shared_ptr<Node> left, right;
    std::weak_ptr<Node> parent;
    bool color;
    T key()  { return info.first; }
    T1& value() { return info.second; }
    const T1& value() const { return info.second; }
};

#endif // NODE_H
