//
// Created by darina on 5/29/24.
//

#ifndef TASK5_DEQUE_H
#define TASK5_DEQUE_H

#include <cstddef>
#include <algorithm>
#include <iostream>

template<typename T>
class Deque {
    static const int BUCKET_SIZE = 8;
    static const int NUMBER_OF_BUCKETS = 4;

    size_t _size = 0;

    struct Bucket {
        T bucket[BUCKET_SIZE];
    };

    Bucket **p_bucket;

    size_t cnt_buckets;
    size_t _begin;
    size_t _end;

    void init(size_t n) {
        cnt_buckets = n;
        p_bucket = new Bucket *[n];
        for (int i = 0; i < n; i++) {
            p_bucket[i] = (Bucket *) new unsigned char[sizeof(Bucket)];
        }

        _begin = 0;
        _end = 0;
    }

    void reserve() {
        size_t new_cnt_bucket = cnt_buckets * 2;
        Bucket **new_bucket = new Bucket *[new_cnt_bucket];
        int begin_bucket = _begin / BUCKET_SIZE;
        int end_bucket = _end / BUCKET_SIZE;
        for (int i = 0; i < new_cnt_bucket; i++) {
            new_bucket[i] = (Bucket *) new unsigned char[sizeof(Bucket)];
        }
        for (int i = 0; i < cnt_buckets; i++) {
            new_bucket[i] = std::move(p_bucket[begin_bucket]);
            if (begin_bucket == end_bucket) {
                _end = i * BUCKET_SIZE + _end % BUCKET_SIZE;
            }
            begin_bucket++;
            begin_bucket %= cnt_buckets;

        }
        _begin %= BUCKET_SIZE;

        delete[] p_bucket;

        cnt_buckets = new_cnt_bucket;
        p_bucket = new_bucket;
    }

public:

    Deque() {
        init(NUMBER_OF_BUCKETS);
    }

    Deque(size_t n) {
        init(n);
    }

    ~Deque() {
        clear();
        delete[] (unsigned char *) p_bucket;
    }

    T &at(size_t i) {
        if (i >= _size || i < 0)
            throw "out of range";

        i = (i + _begin) % (cnt_buckets * BUCKET_SIZE);
        return p_bucket[i / BUCKET_SIZE]->bucket[i % BUCKET_SIZE];
    }

    T &operator[](size_t i) {
        i = (i + _begin) % (cnt_buckets * BUCKET_SIZE);
        return p_bucket[i / BUCKET_SIZE]->bucket[i % BUCKET_SIZE];
    }

    void push_back(T value) {
        int end_position_in_block = _end % BUCKET_SIZE;
        if (end_position_in_block + 1 == BUCKET_SIZE) {
            // end of block

            int block_begin = _begin / BUCKET_SIZE;
            int next_end_block = ((_end + 1) / BUCKET_SIZE) % cnt_buckets;

            if (block_begin == next_end_block) {
                reserve();
            }

        }


        new(p_bucket[_end / BUCKET_SIZE]->bucket + (_end % BUCKET_SIZE)) T(value);
        _end = (_end + 1) % (BUCKET_SIZE * cnt_buckets);
        _size++;
    }

    T pop_back() {
        if (_size == 0)
            throw "empty deque";

        _end = (_end - 1 + cnt_buckets * BUCKET_SIZE) % (BUCKET_SIZE * cnt_buckets);
        T value = std::move(p_bucket[_end / BUCKET_SIZE]->bucket[_end % BUCKET_SIZE]);
        p_bucket[_end / BUCKET_SIZE]->bucket[_end % BUCKET_SIZE].~T();
        _size--;

        return value;
    }

    void push_front(T value) {
        int begin_position_in_block = _begin % BUCKET_SIZE;
        if (begin_position_in_block - 1 < 0) {
            // begin of first block

            int block_end = _end / BUCKET_SIZE;
            int prev_begin_block = ((_begin - 1 + BUCKET_SIZE * cnt_buckets) / BUCKET_SIZE) % cnt_buckets;

            if (block_end == prev_begin_block) {
                reserve();
            }
        }
        _begin = (_begin - 1 + BUCKET_SIZE * cnt_buckets) % (BUCKET_SIZE * cnt_buckets);
        new(p_bucket[_begin / BUCKET_SIZE]->bucket + _begin % BUCKET_SIZE) T(value);
        _size++;
    }

    T pop_front() {
        if (_size == 0)
            throw "empty deque";

        T value = std::move(p_bucket[_begin / BUCKET_SIZE]->bucket[_begin % BUCKET_SIZE]);
        p_bucket[_begin / BUCKET_SIZE]->bucket[_begin % BUCKET_SIZE].~T();
        _begin = (_begin + 1) % (BUCKET_SIZE * cnt_buckets);
        _size--;
        return value;
    }

    void clear() {
        while (_size)
            pop_back();
    }

    size_t size() {
        return _size;
    }

    bool empty() {
        return (size() == 0);
    }

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
    };

    Iterator begin() {
        return Iterator(this, 0);
    }
    Iterator end() {
        return Iterator(this, size());
    }
};

#endif //TASK5_DEQUE_H
