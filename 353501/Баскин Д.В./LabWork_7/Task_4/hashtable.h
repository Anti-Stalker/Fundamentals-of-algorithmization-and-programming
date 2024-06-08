#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QVector>
#include <QThread>

class HashTable
{
    long long size;
    long long hash(long long key)
    {
        return key % size;
    }

    QVector<QPair<long long, int>> table;

    bool isPrime(int n)
    {
        if (n <= 1)
        {
            return false;
        }
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    int getNextPrime(int n)
    {
        while (!isPrime(n))
        {
            ++n;
        }
        return n;
    }

public:
    HashTable(long long size)
    {
        this->size = getNextPrime(size);
        table.resize(this->size);
    }

    int findItem(long long key)
    {
        long long index = hash(key);
        while (table[index].first != key && table[index].first != 0)
        {
            index = (index + 1) % size;
            QThread::msleep(1);
        }
        if (table[index].first == key)
        {
            return table[index].second;
        }
        return -1;
    }

    void addItem(long long key, int value)
    {
        long long index = hash(key);
        int i = 0;
        while (table[index].first != 0)
        {
            ++i;
            //index = (index + 1) % size;
            long long h = (hash(key) + 3 * i + 7 * i * i);
            index = (h >= 0 ? h : -h)  % size;
        }
        table[index] = qMakePair(key, value);
    }

    void removeItem(long long key)
    {
        long long index = hash(key);
        int i = 0;
        while (table[index].first != 0 && table[index].first != key)
        {
            ++i;
            //index = (index + 1) % size;
            long long h = (hash(key) + 3 * i + 7 * i * i);
            index = (h >= 0 ? h : -h)  % size;
        }
        table[index] = qMakePair(0, 0);
    }

    QVector<QPair<long long, int>> toVector()
    {
        return table;
    }
};

#endif // HASHTABLE_H
