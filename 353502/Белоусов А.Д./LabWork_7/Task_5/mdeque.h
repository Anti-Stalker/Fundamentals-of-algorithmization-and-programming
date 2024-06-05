#ifndef MQUEUE_H
#define MQUEUE_H

#include <cstdlib>
#include <memory>
#include <stdexcept>

template<class T>
class mdeque
{
    using container_type = mdeque<T>;
    using value_type = T;
    using size_type = size_t;
    using reference = T*;
    using const_reference = const T&;

public:

    class iterator
    {
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference  = T&;
        using iterator_category = std::random_access_iterator_tag;

    public:

        iterator() : _ptr(nullptr), _iter(0)
        {

        }
        iterator(mdeque<T>* ptr, size_t iter) : _ptr(ptr), _iter(iter)
        {

        }

        reference operator*() const
        {
            return _ptr->_data[_ptr->_start + _iter];
        }

        const pointer operator->() const
        {
            return &_ptr->_data[_ptr->_start + _iter];
        }

        reference operator[](size_t n) const
        {
            return *_ptr->_data[_ptr->_start + _iter + n];
        }

        iterator& operator++()
        {
            _iter++;
            return *this;
        }

        iterator& operator--()
        {
            _iter--;
            return *this;
        }

        const iterator operator++(int)
        {
            iterator r(*this);
            ++_iter;
            return r;
        }

        const iterator operator--(int)
        {
            iterator r(*this);
            --_iter;
            return r;
        }


        iterator &operator+(size_t n)
        {
            iterator r(*this);

            r.i += n;
            return r;
        }
        iterator &operator-(size_t n)
        {
            iterator r(*this);

            r.i -= n;
            return r;
        }

        bool operator!=(iterator const& r) const
        {
            return _iter != r._iter || _ptr != r._ptr;
        }

    private:
        mdeque<T>* _ptr;
        size_t _iter;
    };

    mdeque() :
        _data(new value_type[3])
    {

    }
    mdeque(const mdeque& other) :
        _data(new value_type[other._cap]),
        _start(other._start),
        _end(other._end),
        _cap(other._cap)
    {
        std::uninitialized_copy(other._data, other._data + _cap - 1, _data);
    }
    mdeque(mdeque&& other) noexcept :
        _data(other._data),
        _start(other._start),
        _end(other._end),
        _cap(other._cap)
    {
        other._data = nullptr;
    }

    ~mdeque()
    {
        delete[] _data;
    }

    constexpr const_reference front() const
    {
        if (empty())
        {
            throw "Deque is empty, but needed to take front element";
        }

        return _data[_start];
    }

    constexpr const_reference back() const
    {
        if (empty())
        {
            throw "Deque is empty, but needed to take back element";
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

    void clear()
    {
        _start = _end = 1;
        reserve();
        --_end;
    }

    void push_back(const_reference value)
    {
        if (_end + 1 >= _cap)
        {
            reserve();
        }

        _data[++_end] = value;
    }

    void push_back(value_type&& value)
    {
        if (_end + 1 >= _cap)
        {
            reserve();
        }

        _data[++_end] = std::move(value);
    }

    void push_front(const_reference value)
    {
        if (_start == 0)
        {
            reserve();
        }

        _data[--_start] = value;
    }

    void push_front(value_type&& value)
    {
        if (_start == 0)
        {
            reserve();
        }

        _data[--_start] = std::move(value);
    }

    void pop_front()
    {
        if (empty())
        {
            throw "Deque underflow";
        }

        _start++;
    }

    void pop_back()
    {
        if (empty())
        {
            throw "Deque underflow";
        }

        _end--;
    }

    iterator begin()
    {
        return iterator(this, 0);
    }

    iterator end()
    {
        return iterator(this, size());
    }

private:

    void reserve()
    {
        size_type currSize = size();
        reference newData = new value_type[3 * currSize];

        try
        {
            std::uninitialized_move(_data + _start, _data + _end, newData + currSize);
        }
        catch(const std::exception& excep)
        {
            delete[] newData;
            throw excep;
        }

        delete[] _data;

        _cap = 3 * currSize;
        _data = newData;
        _start = currSize;
        _end = 2 * currSize;
    }

    reference _data;
    size_type _start{1};
    size_type _end{0};
    size_type _cap{3};
};

#endif // MQUEUE_H
