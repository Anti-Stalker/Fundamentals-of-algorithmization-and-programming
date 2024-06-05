#ifndef MHASH_TABLE_H
#define MHASH_TABLE_H

#include <QtCore>
#include <cstdlib>

const size_t DEFAULT_SIZE = 2048;

template<class T>
class mhash_table
{
public:
    mhash_table() :
        _cap(DEFAULT_SIZE),
        _data(new mhash_table_pair[_cap])
    {

    }

    explicit mhash_table(size_t cap) :
        _cap(cap),
        _data(new mhash_table_pair[cap])
    {

    }

    ~mhash_table()
    {
        delete[] _data;
    }

    T& operator[](size_t key)
    {
        auto pos = hashFunc(key);
        for (size_t iter = 0;;++iter)
        {
            if (_data[pos]._state == mhash_table_pair::state::def)
            {
                _data[pos]._key = key;
                _data[pos]._state = mhash_table_pair::state::set;
            }

            if (_data[pos]._key == key)
            {
                return _data[pos]._value;
            }

            pos = collisionSolveFunc(key, pos, iter);
        }
    }

    void setc1(qint64 c1)
    {
        _c1 = c1;
    }

    void setc2(qint64 c2)
    {
        _c2 = c2;
    }

private:

    struct mhash_table_pair
    {
        qint64 _key;
        T _value;
        enum state { def, set } _state { def };
    };

    size_t hashFunc(qint64 value)
    {
        return value % _cap;
    }

    size_t collisionSolveFunc(qint64 key, qint64 collisionHash, size_t iter)
    {
        return (collisionHash + 1) % _cap;
        //return (collisionHash + _c1 * iter + _c2 * iter * iter) % _cap; // <- uladymtsev kak obychno
    }

    qint64 _c1{2};
    qint64 _c2{3};

    mhash_table_pair* _data;
    size_t _cap;
};

#endif // MHASH_TABLE_H
