#ifndef MSTACK_H
#define MSTACK_H

#include <cstdlib>
#include <memory>

template<class T>
class mstack
{
public:
    void push(T value)
    {
        if (_end >= _cap)
        {
            reserve(2 * _end);
        }

        _data[_end++] = value;
    }
    void pop()
    {
        if (_end == 0)
        {
            throw "Stack underflow";
        }
        _end--;
    }
    T peek()
    {
        if (_end == 0)
        {
            throw "Stack is empty";
        }
        return _data[_end - 1];
    }
    size_t size()
    {
        return _end;
    }
    bool empty()
    {
        return size() == 0;
    }
    void reserve(size_t new_cap)
    {
        T* new_data = new T[new_cap];
        try {
            std::uninitialized_move(_data, _data + _end, new_data);
        } catch (...) {
            delete[] new_data;
            throw;
        }

        delete[] _data;

        _data = new_data;
        _cap = new_cap;
    }
private:
    T* _data{nullptr};
    size_t _end{0};
    size_t _cap{0};
};

#endif // MSTACK_H
