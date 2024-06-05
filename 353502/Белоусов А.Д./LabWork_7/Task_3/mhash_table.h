#ifndef MHASH_TABLE_H
#define MHASH_TABLE_H

#include <QtCore>
#include "mstack.h"

template<class T>
class mhash_table
{
private:
    struct item
    {
        qint64 _key;
        T _value;
    };

    size_t hashFunc(qint64 key)
    {
        return key % _cap;
    }

    mstack<item>* _data;
    size_t _cap;

public:
    explicit mhash_table(size_t cap) :
        _data(new mstack<item>[cap]),
        _cap(cap)
    {

    }

    void insertItem(qint64 key, T value)
    {
        _data[hashFunc(key)].push({key, value});
    }

    T getItem(qint64 key)
    {
        auto hashedKey = hashFunc(key);
        mstack<item> dop = _data[hashedKey];
        T answer;
        while(!_data[hashedKey].empty())
        {
            if (_data[hashedKey].peek()._key == key)
            {
                answer = _data[hashedKey].peek()._value;
                break;
            }
            _data[hashedKey].pop();
        }
        _data[hashedKey] = dop;
        return answer;
    }

    QVector<QVector<std::pair<qint64, T>>> toQVector()
    {
        QVector<QVector<std::pair<qint64, T>>> answer(_cap);
        for (int i = 0;i<_cap;i++)
        {
            mstack<item> dop = _data[i];
            while(!_data[i].empty())
            {
                answer[i].push_back({_data[i].peek()._key, _data[i].peek()._value});
                _data[i].pop();
            }
            _data[i] = dop;
        }

        return answer;
    }
};

#endif // MHASH_TABLE_H
