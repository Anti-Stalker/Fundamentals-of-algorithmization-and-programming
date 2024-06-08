//
// Created by u on 30.05.24.
//

#ifndef TASK5_DEQUE_H
#define TASK5_DEQUE_H

#include <iostream>

template <typename T>
class Deque
{
public:
    class Iterator
    {
        friend class Deque<T>;

    private:
        Deque<T> *parent;
        size_t pos;

        Iterator(Deque<T> *parent, size_t pos) : parent(parent), pos(pos) {}

    public:
        T &operator*() const
        {
            return parent->at(pos);
        }

        T *operator->() const
        {
            return &parent->at(pos);
        }

        Iterator &operator++()
        {
            pos++;
            return *this;
        }

        Iterator &operator--()
        {
            pos--;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator res = *this;
            pos++;
            return res;
        }

        Iterator operator--(int)
        {
            Iterator res = *this;
            pos--;
            return res;
        }

        bool operator==(const Iterator &other) const
        {
            return pos == other.pos;
        }

        bool operator!=(const Iterator &other) const
        {
            return pos != other.pos;
        }

        Iterator operator+=(size_t n)
        {
            pos += n;
            return *this;
        }

        Iterator operator-=(size_t n)
        {
            pos -= n;
            return *this;
        }

        Iterator operator+(size_t n) const
        {
            Iterator res = *this;
            res.pos += n;
            return res;
        }

        Iterator operator-(size_t n) const
        {
            Iterator res = *this;
            res.pos -= n;
            return res;
        }
    };

private:
    static const size_t INIT_BLOCKS_COUNT = 4;
    static const size_t BLOCK_SIZE = 4;

    struct block
    {
        T els[BLOCK_SIZE];
    };

    block **blocks;
    size_t blocks_count;

    size_t _begin;
    size_t _end;

    void init(size_t count)
    {
        blocks_count = count;

        blocks = new block*[blocks_count];
        for (int i = 0; i < blocks_count; i++)
            blocks[i] = reinterpret_cast<block *>(new int8_t[sizeof(block)]);

        _begin =_end = 0;
    }

    void expand()
    {
        size_t new_count = blocks_count * 2;
        block **tmp = new block *[new_count];

        size_t copy_block = _begin / BLOCK_SIZE;
        size_t end_block = _end / BLOCK_SIZE;

        for (size_t i = 0; i < blocks_count; i++)
        {
            tmp[i] = blocks[copy_block];

            if (end_block == copy_block)
                _end = i * BLOCK_SIZE + _end % BLOCK_SIZE;

            copy_block++;
            if (copy_block >= blocks_count)
                copy_block -= blocks_count;
        }
        _begin %= BLOCK_SIZE;

        for (size_t i = blocks_count; i < new_count; i++)
            tmp[i] = reinterpret_cast<block *>(new int8_t[sizeof(block)]);

        delete[] (int8_t *)blocks;

        blocks_count = new_count;
        blocks = tmp;
    }

public:
    void push_back(T el)
    {
        size_t end_pos = _end % BLOCK_SIZE;
        if (end_pos == BLOCK_SIZE - 1)
        {
            size_t begin_block = _begin / BLOCK_SIZE;
            size_t next_block = (_end / BLOCK_SIZE) + 1;
            if (next_block >= blocks_count)
                next_block -= blocks_count;

            if (begin_block == next_block)
                expand();
        }

        new (&blocks[_end / BLOCK_SIZE]->els[_end % BLOCK_SIZE]) T(std::move(el));

        _end++;
        if (_end >= blocks_count * BLOCK_SIZE)
            _end -= blocks_count * BLOCK_SIZE;
    }

    T pop_back()
    {
        if (_end == 0)
            _end = blocks_count * BLOCK_SIZE - 1;
        else
            _end--;

        T res = std::move(blocks[_end / BLOCK_SIZE]->els[_end % BLOCK_SIZE]);
        blocks[_end / BLOCK_SIZE]->els[_end % BLOCK_SIZE].~T();

        return res;
    }

    void push_front(T el)
    {
        size_t begin_pos = _begin % BLOCK_SIZE;
        if (begin_pos == 0)
        {
            size_t end_block = _end / BLOCK_SIZE;
            size_t next_block = (_begin / BLOCK_SIZE) - 1;
            if (next_block < 0)
                next_block += blocks_count;

            if (end_block == next_block)
                expand();
        }

        if (_begin == 0)
            _begin = blocks_count * BLOCK_SIZE - 1;
        else
            _begin--;

        new (&blocks[_begin / BLOCK_SIZE]->els[_begin % BLOCK_SIZE]) T(std::move(el));
    }

    T pop_front()
    {
        T res = std::move(blocks[_begin / BLOCK_SIZE]->els[_begin % BLOCK_SIZE]);
        blocks[_begin / BLOCK_SIZE]->els[_begin % BLOCK_SIZE].~T();

        _begin++;
        if (_begin == blocks_count * BLOCK_SIZE)
            _begin = 0;

        return res;
    }

    size_t size() const
    {
        if (_end >= _begin)
            return _end - _begin;
        else
            return blocks_count * BLOCK_SIZE + _end - _begin;
    }

    bool empty() const
    {
        return _end == _begin;
    }

    void clear()
    {
        while (!empty())
            pop_back();
    }

    Iterator begin()
    {
        return Iterator(this, 0);

    }
    Iterator end()
    {
        return Iterator(this, size());
    }

    T &at(size_t i) const
    {
        i += _begin;
        if (i >= blocks_count * BLOCK_SIZE)
            i -= blocks_count * BLOCK_SIZE;
        return blocks[i / BLOCK_SIZE]->els[i % BLOCK_SIZE];
    }

    T &operator[](size_t i)
    {
        return at(i);
    }

    Deque &operator =(const Deque &d)
    {
        clear();
        for (size_t i = 0; i < d.size(); i++)
            push_back(d[i]);

        return *this;
    }

    Deque &operator =(Deque &&d)  noexcept
    {
        blocks_count = d.blocks_count;
        blocks = d.blocks;
        _begin = d._begin;
        _end = d._end;

        d.init(INIT_BLOCKS_COUNT);

        return *this;
    }

    Deque()
    {
        init(INIT_BLOCKS_COUNT);
    }

    Deque(const Deque &d)
    {
        init(d.blocks_count);

        for (size_t i = 0; i < d.size(); i++)
            push_back(d[i]);
    }

    Deque(Deque &&d)
    {
        blocks_count = d.blocks_count;
        blocks = d.blocks;
        _begin = d._begin;
        _end = d._end;

        d.init(INIT_BLOCKS_COUNT);
    }

    ~Deque() {
        clear();
        delete[] (int8_t *)blocks;
    }
};

#endif //TASK5_DEQUE_H
