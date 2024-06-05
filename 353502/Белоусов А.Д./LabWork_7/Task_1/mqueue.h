#ifndef MQUEUE_H
#define MQUEUE_H

#include <cstdlib>
#include <memory>
#include <stdexcept>

template<class T>
class mqueue
{
    using container_type = mqueue<T>;
    using value_type = T;
    using size_type = size_t;
    using reference = T*;
    using const_reference = const T&;

public:
    mqueue() :
        _data(new value_type[1])
    {

    }
    mqueue(const mqueue& other) :
        _data(new value_type[other._cap]),
        _start(other._start),
        _end(other._end),
        _cap(other._cap)
    {
        std::uninitialized_copy(other._data, other._data + _cap, _data);
    }
    mqueue(mqueue&& other) noexcept :
        _data(other._data),
        _start(other._start),
        _end(other._end),
        _cap(other._cap)
    {
        other._data = nullptr;
    }

    constexpr const_reference front() const
    {
        if (empty())
        {
            throw std::length_error("Queue is empty, but needed to take front element");
        }

        return _data[_start];
    }

    constexpr const_reference back() const
    {
        if (empty())
        {
            throw std::length_error("Queue is empty, but needed to take back element");
        }

        return _data[_end];
    }

    bool empty() const
    {
        return (size() == 0);
    }

    size_type size() const
    {
        return _end - _start + 1;
    }

    void push(const_reference value)
    {
        _end++;

        if (_end >= _cap)
        {
            reserve();
        }

        _data[_end] = value;
    }

    void push(value_type&& value)
    {
        _end++;

        if (_end >= _cap)
        {
            reserve();
        }

        _data[_end] = std::move(value);
    }

    void pop()
    {
        if (empty())
        {
            throw std::length_error("Queue is empty, but needed to pop");
        }

        _start++;
    }

private:

    void reserve()
    {
        size_type currSize = size();
        reference newData = new value_type[2 * currSize];

        try
        {
            std::uninitialized_move(_data + _start, _data + _end, newData);
        }
        catch(const std::exception& excep)
        {
            delete[] newData;
            throw excep;
        }

        delete[] _data;

        _cap = 2 * currSize;
        _data = newData;
        _start = 0;
        _end = currSize - 1;
    }

    reference _data;
    size_type _start{1};
    size_type _end{0};
    size_type _cap{1};
};

#endif // MQUEUE_H
