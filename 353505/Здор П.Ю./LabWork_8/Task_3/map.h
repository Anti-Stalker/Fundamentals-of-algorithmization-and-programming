#ifndef MAP_H
#define MAP_H
#include "rbtree.h"
#include <forward_list>
#include <vector>
template <typename T,typename T1>
class map : public RBTree<T,T1>
{
public:
    map()
    {
        beba.resize(100000);
    }
    bool contains(T key)
    {
        RBTree<T,T1>::find_key(key);
    }
    using RBTree<T, T1>::operator[];
    void clear()
    {
        RBTree<T,T1>::clear();
    }
    void add(T key,T1 a)
    {
        int tmp=hash(key);
        RBTree<T,T1>::insert(tmp,a);
        //beba.push_back(tmp,a);

    }
    int hash(T key)
    {
        return (int)key%100000;
    }
    void erase(T key)
    {
        RBTree<T,T1>::remove(key);
    }
private :
    std::vector<std::forward_list<std::pair<T,T1>>> beba;

};

#endif // map_H
