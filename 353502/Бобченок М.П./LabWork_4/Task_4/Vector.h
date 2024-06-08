//
// Created by u on 18.05.24.
//

#ifndef TASK2_VECTOR_H
#define TASK2_VECTOR_H

#include <iostream>
#include <memory>
#include <string>
#include <iostream>
#include <vector>

template <typename T>
class iterator
{
private:
    T *it;

public:
    const T *base() const
    {
        return it;
    }

    T &operator*() const
    {
        return *it;
    }

    T *operator->() const
    {
        return it;
    }

    iterator &operator++()
    {
        ++it;
        return *this;
    }

    iterator &operator--()
    {
        --it;
        return *this;
    }

    iterator operator++(int)
    {
        return iterator(it++);
    }

    iterator operator--(int)
    {
        return iterator(it--);
    }

    iterator operator+(size_t n)
    {
        return iterator(it + n);
    }

    iterator operator-(size_t n)
    {
        return iterator(it - n);
    }

    void operator+=(size_t n)
    {
        it += n;
    }

    void operator-=(size_t n)
    {
        it -= n;
    }

    T operator[](size_t i)
    {
        return it[i];
    }

    bool operator!=(iterator x)
    {
        return it != x.operator->();
    }

    explicit iterator(T *ptr)
    {
        it = ptr;
    }

    ~iterator() = default;
};

template <typename T>
class reverse_iterator
{
private:
    T *it;

public:
    const T *base() const
    {
        return it;
    }

    T &operator*() const
    {
        return *it;
    }

    T *operator->() const
    {
        return it;
    }

    reverse_iterator &operator++()
    {
        --it;
        return *this;
    }

    reverse_iterator &operator--()
    {
        ++it;
        return *this;
    }

    reverse_iterator operator++(int)
    {
        return reverse_iterator(it--);
    }

    reverse_iterator operator--(int)
    {
        return reverse_iterator(it++);
    }

    reverse_iterator operator+(size_t n)
    {
        return reverse_iterator(it - n);
    }

    reverse_iterator operator-(size_t n)
    {
        return reverse_iterator(it + n);
    }

    void operator+=(size_t n)
    {
        it -= n;
    }

    void operator-=(size_t n)
    {
        it += n;
    }

    T operator[](size_t i)
    {
        return it[i];
    }

    bool operator!=(reverse_iterator x)
    {
        return it != x.operator->();
    }

    explicit reverse_iterator(T *ptr)
    {
        it = ptr;
    }

    ~reverse_iterator() = default;
};

template <class T>
class Vector
{
    using def_it = iterator<T>;
    using rev_it = reverse_iterator<T>;
    using c_it = iterator<const T>;

private:
    T *arr = nullptr;
    size_t cap = 0;
    size_t sz = 0;

public:
    Vector()
    {
        arr = nullptr;
        cap = 0;
        sz = 0;
    };

    explicit Vector(size_t n)
    {
        reserve(n);
        for (int i = 0; i < n; i++)
            new (arr + i) T();
    }

    Vector(Vector<T> const &tmp)
    {
        sz = tmp.sz;
        reserve(tmp.cap);
        for (int i = 0; i < tmp.sz; i++)
            new (arr + i) T(tmp[i]);
    }

    Vector(std::initializer_list<T> l)
    {
        reserve(l.size());
        sz = l.size();

        arr = reinterpret_cast<T *>(new int8_t[sz * sizeof(T)]);
        auto listIt = l.begin();
        for (size_t i = 0; i < sz; i++, listIt++) {
            T tmp = *listIt;
            new(arr + i) T(std::move(tmp));
        }
    }

    ~Vector()
    {
        for (int i = 0; i < sz; i++)
            (arr + i)->~T();

        delete[] reinterpret_cast<int8_t*>(arr);
    }

    void reserve(size_t n)
    {
        if (n == 0)
            n = 1;
        if (n <= cap)
            return;

        T *newArr = reinterpret_cast<T*>(new int8_t[n * sizeof(T)]);
        try
        {
            std::uninitialized_copy(arr, arr + sz, newArr);
        }
        catch (...)
        {
            delete[] reinterpret_cast<int8_t*>(newArr);
            throw;
        }

        delete[] reinterpret_cast<int8_t*>(arr);
        arr = newArr;
        cap = n;
    };

    void resize(size_t new_size)
    {
        if (new_size > cap)
            reserve(cap);

        for (int i = sz; i < new_size; i++)
            new (arr + i) T();

        for (int i = new_size; i < sz; i++)
            (arr + i)->~T();

        sz = new_size;
    }

    void resize(size_t new_size, T value)
    {
        if (new_size > cap)
            reserve(cap);

        for (int i = sz; i < new_size; i++)
            new (arr + i) T(value);

        sz = new_size;
    }

    void insert(def_it pos, T const &tmp)
    {
        size_t position = pos.base() - arr;
        reserve(sz + 1);
        for (int i = sz; i > position; i--)
        {
            new (arr + i) T(arr + i - 1);
            (arr + i - 1)->~T();
        }

        new (arr + position) T(tmp);
        sz++;
    }

    void insert(size_t position, T const &tmp)
    {
        reserve(sz + 1);
        for (int i = sz; i > position; i--)
        {
            new (arr + i) T(*(arr + i - 1));
            (arr + i - 1)->~T();
        }

        new (arr + position) T(tmp);
        sz++;
    }

    void insert(size_t position, T &&tmp)
    {
        reserve(sz + 1);
        for (int i = sz; i > position; i--)
        {
            new (arr + i) T(*(arr + i - 1));
            (arr + i - 1)->~T();
        }

        new (arr + position) T(tmp);
        sz++;
    }


    void insert(def_it pos, T &&tmp)
    {
        size_t position = pos.base() - arr;
        reserve(sz + 1);
        for (int i = sz; i > position; i--)
        {
            new (arr + i) T(arr + i - 1);
            (arr + i - 1)->~T();
        }

        new (arr + position) T(tmp);
        sz++;
    }

    void push_back(const T &arg)
    {
        if (cap == sz)
        {
            reserve(cap * 2);
        }
        new (arr + sz) T(arg);
        ++sz;
    }

    template<typename... Args>
    void emplace(c_it pos, Args &&... args)
    {
        T tmp(args...);
        insert(pos, tmp);
    }

    template<typename... Args>
    void emplace_back(Args &&... args)
    {
        T tmp(args...);
        push_back(tmp);
    }

    void clear()
    {
        resize(0);
    }

    void assign(size_t n, T value)
    {
        resize(n);
        for (int i = 0; i < sz; i++)
        {
            (arr + i)->~T();
            new (arr + i) T(value);
        }
    }

    void assign(c_it beg, c_it end)
    {
        size_t size = end.base() - beg.base();
        resize(size);
        for (int i = 0; i < size; i++)
        {
            (arr + i)->~T();
            new (arr + i) T(*(beg + i));
        }
    }

    bool empty()
    {
        return sz == 0;
    }

    void erase(size_t l, size_t r)
    {
        for (size_t i = l; i < r; i++)
        {
            arr[i].~T();
        }
        std::uninitialized_copy(arr + r, arr + sz, arr + l);
        sz -= (r - l);
    }

    void erase(size_t pos)
    {
        if (pos >= sz)
            return;
        erase(pos, pos + 1);
    }

    void pop_back()
    {
        if (!empty())
        {
            sz--;
            arr[sz - 1].~T();
        }
    }

    T &front()
    {
        if (!empty())
            return arr[0];
    }

    T &back()
    {
        return arr[sz - 1];
    }

    T *data()
    {
        return arr;
    }

    size_t capacity()
    {
        return cap;
    }

    size_t size()
    {
        return sz;
    }

    size_t max_size()
    {
        return INT64_MAX / sizeof(T);
    }

    void swap(Vector<T> &tmp)
    {
        std::swap(arr, tmp.arr);
        std::swap(cap, tmp.cap);
        std::swap(sz, tmp.sz);
    }

    T& operator [](size_t i)
    {
        return arr[i];
    }

    const T& operator [](size_t i) const
    {
        return arr[i];
    }

    T& at(size_t i)
    {
       if (i > sz)
           throw std::out_of_range("...");

       return arr[i];
    }

    def_it begin()
    {
        return def_it(arr);
    }

    rev_it rbegin()
    {
        return rev_it(arr + sz - 1);
    }

    c_it cbegin()
    {
        return c_it(arr);
    }

    def_it end()
    {
        return def_it(arr + sz);
    }

    rev_it rend()
    {
        return rev_it(arr);
    }

    c_it cend()
    {
        return c_it(arr + sz);
    }

};

#endif //TASK2_VECTOR_H
