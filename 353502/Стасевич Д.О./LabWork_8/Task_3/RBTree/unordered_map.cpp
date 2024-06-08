//
// Created by darina on 6/4/24.
//

#include "unordered_map.h"


/*
#include <iostream>
#include "HashTable.h"

HashTable::HashTable() {
    table.resize(3);
    capacity = 3;
    all = 0;
    CalculateSt();
}

HashTable::HashTable(int n) {
    table.resize(n);
    capacity = n;
    all = 0;
    CalculateSt();
}

int HashTable::GetHash(std::string s) {
    int value = 0;
    for(int i = 0; i < s.size(); i ++)
    {
        value = value + (st[i] * (s[i] - 'a')) % capacity;
        value %= capacity;
    }
    return value;
}

voi HashTable::reserve(int n) {
    if(n <= capacity)
        return;
    std::vector<std::pair<int, std::string> > old_table(n);
    std::swap(old_table, table);
    CalculateSt();
    capacity = n;
    all = 0;
    for(int i = 0; i < old_table.size(); i ++)
    {
        if(old_table[i].first == 2 || old_table[i].first == 4)
        {
            insert(old_table[i].second);
        }
    }
}

// 0 - empty (nothing was)
// 1 - deleted (real key deleted)
// 2 - not empty (has correct)
// 3 - removed (collision deleted)
// 4 - filled by collision
void HashTable::insert(std::string s) {

    if(findItem(s) != -1)
        return;
    if(double (capacity) * 0.7 < all)
        reserve(capacity * 2);
    int key = GetHash(s);
    int type = 2;
    while(table[key].first == 2 || table[key].first == 4)
    {
        key ++;
        key %= capacity;
        type = 4;
    }
    table[key] = {type, s};
    all ++;
}

// 0 - empty (nothing was)
// 1 - deleted (real key deleted)
// 2 - not empty (has correct)
// 3 - removed (collision deleted)
// 4 - filled by collision
bool HashTable::remove(std::string s) {
    int key = findItem(s);
    if(key == GetHash(s))
    {
        all --;
        table[key] = {1, ""};
        return true;
    }
    if(key == -1)
    {
        // not find
        return false;
    }
    table[key] = {3, ""};
    all --;
    return true;
}

std::vector<std::pair<int, std::string> > HashTable::GetCollisions() {
    std::vector<std::pair<int, std::string> > ret;
    for(int i = 0; i < capacity; i ++)
    {
        if(table[i].first == 4)
        {
            ret.push_back({i, table[i].second});
        }
    }
    return ret;
}

int HashTable::findItem(std::string s) {
    int key = GetHash(s);
    if(table[key].first == 2 && table[key].second == s)
    {
        return key;
    }
    int cur = (key + 1) % capacity;
    while(cur != key)
    {
        if(table[cur].second == s) {
            return cur;
        }
        if(table[cur].first == 0)
            return -1;
        cur = (cur + 1) % capacity;
    }
    return -1;
}

void HashTable::CalculateSt() {
    st.clear();
    st.push_back(1);
    for(int i = 0; i < 100000; i ++)
    {
        st.push_back((st.back() * 31) % capacity);
    }
}
*/