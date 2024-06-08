//
// Created by u on 05.06.24.
//

#ifndef TASK4_HASHTABLE_H
#define TASK4_HASHTABLE_H

#include <stack>
#include <QVector>
#include <functional>

template <typename K, typename V, typename F>
class HashTable
{
private:
    F hash;
    size_t cap;
    size_t sz;
    QVector<std::stack<std::pair<K, V> > > table;

public:
    void rehash()
    {
        QVector<std::stack<std::pair<K, V> > > tmp;

        tmp.resize(cap);

        for (auto &st : table)
        {
            while (!st.empty())
            {
                int pos = hash(st.top().first) % cap;
                tmp[pos].push(st.top());

                st.pop();
            }
        }

        swap(tmp, table);
    }

    void expand()
    {
        cap *= 2;
        table.resize(cap);
        rehash();
    }

    bool contains(const K &key)
    {
        int pos = hash(key) % cap;
        std::stack<std::pair<K, V> > st;

        bool res = false;

        while (!table[pos].empty())
        {
            st.push(table[pos].top());
            table[pos].pop();
        }

        while (!st.empty())
        {
            if (st.top().first == key)
                res = true;

            table[pos].push(st.top());
            st.pop();
        }

        return res;
    }

    V &operator[](const K &key)
    {
        int pos = hash(key) % cap;

        if (!contains(key))
        {
            if (sz == cap)
                expand();

            pos = hash(key) % cap;

            table[pos].push({key, *(new V())});
            sz++;
        }

        std::pair<K, V> res;
        std::stack<std::pair<K, V> > st;

        while (!table[pos].empty())
        {
            if (table[pos].top().first == key)
            {
                res = table[pos].top();
                table[pos].pop();
                continue;
            }
            st.push(table[pos].top());
            table[pos].pop();
        }

        while (!st.empty())
        {
            table[pos].push(st.top());
            st.pop();
        }

        table[pos].push(res);
        return table[pos].top().second;
    }

    void clear()
    {
        table.clear();
    }

    void erase(const K &key)
    {
        int pos = hash(key) % cap;

        std::stack<std::pair<K, V> > st;

        while (!table[pos].empty())
        {
            if (table[pos].top().first == key)
            {
                table[pos].pop();
                sz--;
                continue;
            }

            st.push(table[pos].top());
            table[pos].pop();
        }

        while (!st.empty())
        {
            table[pos].push(st.top());
            st.pop();
        }
    }

    QVector<QVector<int>> displayHash()
    {
        QVector<QVector<int>> result;
        for (int i = 0; i < cap; i++)
        {
            std::stack<std::pair<K, V> > st;
            QVector<V> tmp;

            while (!table[i].empty())
            {
                tmp.push_back(table[i].top().second);
                st.push(table[i].top());
                table[i].pop();
            }

            while (!st.empty())
            {
                table[i].push(st.top());
                st.pop();
            }

            result.append(tmp);
        }

        return result;
    }

    HashTable(F f)
    {
        hash = f;
        cap = 1;
        sz = 0;
        table.resize(cap);
    }

    HashTable()
    {
        cap = 1;
        sz = 0;
        table.resize(cap);
    }
};

#endif //TASK4_HASHTABLE_H
