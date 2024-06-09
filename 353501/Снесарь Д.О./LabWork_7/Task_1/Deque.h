#ifndef DEQUE_H
#define DEQUE_H


#include <cstdint>
#include <iostream>

template <typename T> class Deque {
    
private:
    static const size_t BLOCK_SIZE = 4; //for denonstration
    static const size_t INITIAL_MAP_SIZE = 4;
    static const size_t GROW_FACTOR = 2;
    size_t mapSize; //size of pointers array
    //size_t totalSize; //number of elements

    struct Block {
        T els[BLOCK_SIZE];
    };

    Block **map;
    size_t _begin;
    size_t _end;
    
    
    
    
public:

    Deque() {
        mapSize = INITIAL_MAP_SIZE;
        map = new Block *[mapSize];
        for (int i = 0; i < mapSize; i++) {
            map[i] = (Block *) new unsigned char [sizeof(Block)];
        }
        
        _begin = 0;
        _end = 0;
    }
    
    ~Deque() {
        clear();
        delete[] (unsigned char  *)map;
    }

    Deque(const Deque &d) {
        mapSize = d.mapSize;
        map = new Block *[mapSize];
        for (int i = 0; i < mapSize; i++) {
            map[i] = (Block *) new unsigned char [sizeof(Block)];
        }

        _begin = 0;
        _end = 0;

        for (size_t i = 0; i < d.size(); i++) {
            push_back(d[i]);
        }
    }

    Deque &operator=(const Deque &d) {
        clear();
        for (size_t i = 0; i < d.size(); i++) {
            push_back(d[i]);
        }

        return *this;
    }

    Deque(Deque &&d) {
        mapSize = d.mapSize;
        map = d.map;
        _begin = d._begin;
        _end = d._end;


        d.mapSize = INITIAL_MAP_SIZE;
        d.map = new Block *[mapSize];
        for (int i = 0; i < mapSize; i++) {
            d.map[i] = (Block *) new unsigned char [sizeof(Block)];
        }

        d._begin = 0;
        d._end = 0;
    }

    Deque& operator=(Deque &&d) {
        mapSize = d.mapSize;
        map = d.map;
        _begin = d._begin;
        _end = d._end;

        d.mapSize = INITIAL_MAP_SIZE;
        d.map = new Block *[mapSize];
        for (int i = 0; i < mapSize; i++) {
            d.map[i] = (Block *) new unsigned char [sizeof(Block)];
        }

        d._begin = 0;
        d._end = 0;

        return *this;
    }

    T& at(size_t i) {
        i += _begin;
        if (i >= mapSize * BLOCK_SIZE)
            i -= mapSize  * BLOCK_SIZE;
        return map[i / BLOCK_SIZE]->els[i % BLOCK_SIZE];
    }

    const T &at(size_t i) const {
        i += _begin;
        if (i >= mapSize  * BLOCK_SIZE)
            i -= mapSize  * BLOCK_SIZE;

        return map[i / BLOCK_SIZE]->els[i % BLOCK_SIZE];
    }

    T &operator[](size_t i) { return at(i); }
    const T &operator[](size_t i) const { return at(i); }

    
    T pop_back() {
        if (_end == 0) {
            _end = mapSize * BLOCK_SIZE - 1;
        } else {
            _end--;
        }
        
        T result = std::move(map[_end / BLOCK_SIZE]->els[_end % BLOCK_SIZE]);
        map[_end / BLOCK_SIZE]->els[_end % BLOCK_SIZE].~T();
        
        return result;
    }
    
    T pop_front() {
        T result = std::move(map[_begin / BLOCK_SIZE]->els[_begin % BLOCK_SIZE]);
        map[_begin / BLOCK_SIZE]->els[_begin % BLOCK_SIZE].~T();
        
        _begin++;
        if (_begin == mapSize * BLOCK_SIZE)
            _begin = 0;
        
        return result;
    }

    void push_front(T element) {
        size_t begin_pos = _begin % BLOCK_SIZE;
        if (begin_pos == 0) {
            size_t end_block = _end / BLOCK_SIZE;
            size_t next_block = (_begin / BLOCK_SIZE) - 1;
            if (next_block < 0)
                next_block += mapSize;

            if (end_block == next_block)
                expand();
        }

        if (_begin == 0) {
            _begin = mapSize * BLOCK_SIZE - 1;
        } else {
            _begin--;
        }

        new (&map[_begin / BLOCK_SIZE]->els[_begin % BLOCK_SIZE]) T(std::move(element));
    }

    void push_back(T element) {
        size_t end_pos = _end % BLOCK_SIZE;
        if (end_pos == BLOCK_SIZE - 1) {
            size_t begin_block = _begin / BLOCK_SIZE;
            size_t next_block = (_end / BLOCK_SIZE) + 1;
            if (next_block >= mapSize)
                next_block -= mapSize;

            if (begin_block == next_block)
                expand();
        }

        new (&map[_end / BLOCK_SIZE]->els[_end % BLOCK_SIZE]) T(std::move(element));

        _end++;
        if (_end >= mapSize * BLOCK_SIZE)
            _end -= mapSize * BLOCK_SIZE;
    }

    size_t size() const {
        if (_end >= _begin)
            return _end - _begin;
        else
            return mapSize * BLOCK_SIZE + _end - _begin;
    }

    bool empty() const
    {
        return _end == _begin;
    }

    void clear() {
        while (!empty())
            pop_back();
    }

private:
    void expand() {
        size_t new_count = mapSize * GROW_FACTOR;
        Block **new_blocks = new Block *[new_count];

        size_t copy_block = _begin / BLOCK_SIZE;
        size_t end_block = _end / BLOCK_SIZE;

        for (size_t i = 0; i < mapSize; i++) {
            new_blocks[i] = map[copy_block];

            if (end_block == copy_block) {
                _end = i * BLOCK_SIZE + _end % BLOCK_SIZE;
            }

            copy_block++;
            if (copy_block >= mapSize) {
                copy_block -= mapSize;
            }
        }
        _begin %= BLOCK_SIZE;

        for (size_t i = mapSize; i < new_count; i++) {
            new_blocks[i] = (Block *)new unsigned char[sizeof(Block)];
        }

        delete[] (unsigned char *)map;

        mapSize = new_count;
        map = new_blocks;
    }

public:
    class Iterator {
        friend class Deque<T>;

    private:
        Deque<T> *parent;
        size_t pos;

        Iterator(Deque<T> *parent, size_t pos) : parent(parent), pos(pos) {}

    public:
        T &operator*() const { return parent->at(pos); }
        T *operator->() const { return &parent->at(pos); }

        Iterator &operator++() {
            pos++;
            return *this;
        }
        Iterator &operator--() {
            pos--;
            return *this;
        }
        Iterator operator++(int) {
            Iterator res = *this;
            pos++;
            return res;
        }
        Iterator operator--(int) {
            Iterator res = *this;
            pos--;
            return res;
        }

        bool operator==(const Iterator &other) const { return pos == other.pos; }
        bool operator!=(const Iterator &other) const { return pos != other.pos; }

        Iterator operator+=(size_t n) {
            pos += n;
            return *this;
        }
        Iterator operator-=(size_t n) {
            pos -= n;
            return *this;
        }
        Iterator operator+(size_t n) const {
            Iterator res = *this;
            res.pos += n;
            return res;
        }
        Iterator operator-(size_t n) const {
            Iterator res = *this;
            res.pos -= n;
            return res;
        }
    };

    Iterator begin() { return Iterator(this, 0); }
    Iterator end() { return Iterator(this, size()); }
};


#endif // DEQUE_H
