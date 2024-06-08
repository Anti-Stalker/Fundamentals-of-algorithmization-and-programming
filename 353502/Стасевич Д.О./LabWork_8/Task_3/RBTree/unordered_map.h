//
// Created by darina on 6/4/24.
//

#ifndef TASK3_UNORDERED_MAP_H
#define TASK3_UNORDERED_MAP_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

template <typename K, typename V>
class unordered_map {
    int capacity;
    int all;
    std::vector<int> st;

    struct Node
    {
        std::pair<K, V> data;
        short type;

        Node(const K &key, const V &value)
        {
            data.first = key;
            data.second = value;
            type = 0;
        }

    };

    std::vector<Node*> table;

    int GetHash(K key)
    {
        std::ostringstream os;
        os << key;
        std::string s = os.str();
        int value = 0;
        for(int i = 0; i < s.size(); i ++)
        {
            value = value + (st[i] * char(s[i])) % capacity;
            value %= capacity;
        }
        return value;
    }

    void reserve(int n)
    {
        if(n <= capacity)
            return;
        std::vector<Node*> old_table(n);
        std::swap(old_table, table);
        CalculateSt();
        capacity = n;
        all = 0;
        for(int i = 0; i < old_table.size(); i ++)
        {
            if(old_table[i] != nullptr && old_table[i]->type == 2)
            {
                insert(old_table[i]->data.first, old_table[i]->data.second);
            }
        }
    }

    void CalculateSt()
    {
        st.clear();
        st.push_back(1);
        for(int i = 0; i < 100000; i ++)
        {
            st.push_back((st.back() * 97) % capacity);
        }
    }

    int findItem(const K &key)
    {
        int k = GetHash(key);
        if(table[k] == nullptr)
            return -1;
        if(table[k]->type == 2 && table[k]->data.first == key)
        {
            return k;
        }
        int cur = (k + 1) % capacity;
        while(cur != k)
        {
            if(table[cur] != nullptr && table[cur]->type == 2 && table[cur]->data.first == key)
                return cur;
            if(table[cur] == nullptr)
                return -1;
            cur = (cur + 1) % capacity;
        }
        return -1;
    }

public:

    unordered_map()
    {
        table.resize(7);
        capacity = 7;
        all = 0;
        CalculateSt();
    }

    unordered_map(size_t n)
    {
        table.resize(n);
        capacity = n;
        all = 0;
        CalculateSt();
    }

    void insert(const K &key, const V &value)
    {
        if(double(capacity) * 0.7 < all)
            reserve((capacity + 1) * 2 - 1);

        int kk = findItem(key);
        if(kk != -1)
        {
            table[kk]->data.second = value;
            return;
        }
        int k = GetHash(key);
        while(table[k] != nullptr && table[k]->type == 2)
        {
            k ++;
            k %= capacity;
        }
        table[k] = new Node(key, value);
        table[k]->type = 2;
        all ++;
    }

    bool remove(const K &key)
    {
        int k = findItem(key);
        if(k == GetHash(key))
        {
            table[k]->type = 1;
            return true;
        }
        return false;
    }

    bool contains(const K &key)
    {
        int k = findItem(key);
        if(k == -1)
        {
            return false;
        }
        return true;
    }

    V& operator[](const K& key)
    {
        int k = findItem(key);
        if(k != -1)
        {
            Node* node = table[k];
            return node->data.second;
        }
        insert(key, V());
        k = findItem(key);
        Node* node = table[k];
        return node->data.second;
    }

public:
    class Iterator
    {
    protected:
        friend class unordered_map<K, V>;
        int cur = 0;
        Node* node;
        std::vector<Node*> table;
        int capacity;
        Iterator(int i, std::vector<Node*> t, int c, bool type) {
            cur = i;
            table = t;
            capacity = c;
            if(type == 0) {
                while (this->table[cur] == nullptr || this->table[cur]->type != 2) {
                    cur++;
                    cur %= this->capacity;
                    if (cur == i) {
                        cur = -1;
                        break;
                    }
                }
            }
            else
            {
                cur --;
                cur += capacity;
                cur %= capacity;
                while (this->table[cur] == nullptr || this->table[cur]->type != 2) {
                    cur--;
                    cur += capacity;
                    cur %= this->capacity;
                    if (cur == i) {
                        cur = -1;
                        break;
                    }
                }
            }

            if(cur != -1)
                node = this->table[cur];
        }

    public:
        Node *operator->() { return node; }

        Node &operator*() { return *node; }

        Iterator &operator++()
        {
            if(cur == -1)
                return *this;

            cur ++;
            cur %= this->capacity;

            while(this->table[cur] == nullptr || this->table[cur]->type != 2)
            {
                cur ++;
                cur %= this->capacity;
            }

            node = this->table[cur];
            return *this;
        }

        Iterator &operator--()
        {
            if(cur == -1)
                return *this;

            cur --;
            cur %= this->capacity;

            while(this->table[cur] == nullptr || this->table[cur]->type != 2)
            {
                cur --;
                cur += this->capacity;
                cur %= this->capacity;
            }

            node = this->table[cur];
            return *this;
        }

        bool operator==(const Iterator &other) const { return cur == other.cur; }
        bool operator!=(const Iterator &other) const { return cur != other.cur; }

    };

    Iterator begin()
    {
        return Iterator(0, table, capacity, 0);
    }

    Iterator back()
    {
        return Iterator(0, table, capacity, 1);
    }

};

#endif //TASK3_UNORDERED_MAP_H