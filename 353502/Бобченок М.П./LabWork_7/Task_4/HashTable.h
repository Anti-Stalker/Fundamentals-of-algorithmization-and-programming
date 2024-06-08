//
// Created by u on 31.05.24.
//

#ifndef TASK4_HASHTABLE_H
#define TASK4_HASHTABLE_H

#include <QVector>
#include <QPair>


class QuadHashTable
{
private:
    int cap = 1;
    QVector<QPair<int, int> >table;

    int hashFunction(int key)
    {
        return key % cap;
    }

public:
    QuadHashTable(int sz)
    {
        cap = sz;
        table.resize(sz);
    }

    void insertItem(int key, int data)
    {
        int index = hashFunction(key) % cap;
        int cnt = 0;
        while (table[index].first != 0 && cnt++ < cap + 1)
            index = (index * index + index + 1) % cap;

        table[index] = qMakePair(key, data);
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key) % cap;
        int cnt = 0;
        while (table[index].first != key && table[index].first != 0 && cnt++ < cap + 1)
            index = (index * index + index + 1) % cap;

        if (table[index].first == key)
            table[index] = qMakePair(0, 0);
    }

    QVector<QPair<int, int>> displayHash()
    {
        return table;
    }

    void clear()
    {
        table.fill(qMakePair(0, 0));
    }

    int findItem(int key)
    {
        int index = hashFunction(key) % cap;
        int cnt = 0;
        while (table[index].first != key && table[index].first != 0 && cnt++ < cap + 1)
            index = (index * index + index + 1) % cap;

        if (table[index].first == key)
            return table[index].second;

        return -1;
    }
};

class LinearHashTable
{
private:
    int cap = 1;
    QVector<QPair<int, int>> table;

    int hashFunction(int key)
    {
        return key % cap;
    }

public:
    LinearHashTable(int sz)
    {
        cap = sz;
        table.resize(cap);
    }

    void insertItem(int key, int data)
    {
        int index = hashFunction(key) % cap;
        int cnt = 0;
        while (table[index].first != 0 && cnt++ < cap + 1)
            index = (index + 1) % cap;

        table[index] = qMakePair(key, data);
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key);
        int cnt = 0;
        while (table[index].first != key && table[index].first != 0 && cnt++ < cap + 1)
            index = (index + 1) % cap;

        if (table[index].first == key)
            table[index] = qMakePair(0, 0);
    }

    QVector<QPair<int, int>> displayHash()
    {
        return table;
    }

    void clear()
    {
        table.fill(qMakePair(0, 0));
    }

    int findItem(int key)
    {
        int index = hashFunction(key);
        int cnt = 0;
        while (table[index].first != key && table[index].first != 0 && cnt++ < cap + 1)
            index = (index + 1) % cap;

        if (table[index].first == key)
            return table[index].second;

        return -1;
    }
};

#endif //TASK4_HASHTABLE_H
