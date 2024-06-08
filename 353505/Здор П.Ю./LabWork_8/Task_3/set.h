#ifndef SET_H
#define SET_H
#include "rbtree.h"
#include <forward_list>
#include <vector>
template <typename T>
class set : public RBTree<T,char>
{
public:
    set()
    {
        beba.resize(100000);
    }
    bool contains(T key)
    {

        return set::find_key(key);
    }
    using RBTree<T, char>::operator[];
    using RBTree<T, char>::find_key;
    void clear()
    {
        RBTree<T,char>::clear();
    }
    void add(char a)
    {
        int tmp=hash(rand());
        RBTree<T,char>::insert(tmp,a);
        //beba.push_back(tmp,a);

    }
    int hash(T key)
    {
        return (int)key%100000;
    }
    void erase(T key)
    {
        RBTree<T,char>::remove(key);
    }
private :
    std::vector<std::forward_list<std::pair<T,char>>> beba;

};

#endif // SET_H
