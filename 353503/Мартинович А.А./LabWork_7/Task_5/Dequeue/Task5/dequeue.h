#ifndef DEQUEUE_H
#define DEQUEUE_H
#include "cstddef"
#include "cstdint"
#include <utility>
#include <stdexcept>
#include "QDebug"

template <typename T> class Deque {
  friend class InspectorGadget;

protected:
    struct deq_idx {
        size_t block;
        size_t idx;

        bool operator==(deq_idx &other) {
            return block == other.block && idx == other.idx;
        }

        deq_idx& operator=(const deq_idx &other) {
            block = other.block;
            idx = other.idx;
            return *this;
        }

        deq_idx& operator++() {
            if (idx == BLOCK_SIZE - 1) {
                block++;
                idx = 0;
            }
            else {
                idx++;
            }
            return *this;
        }
        deq_idx& operator--() {
            if (idx == 0) {
                block--;
                idx = BLOCK_SIZE - 1;
            }
            else {
                idx--;
            }
            return *this;
        }
    };

    T **_data;

    deq_idx _front;
    deq_idx _back;
    size_t _blocks_count;
    size_t _size;

    static const size_t INI_BLOCKS = 4;
    static const size_t BLOCK_SIZE = 4;

    const int EXPAND_FACTOR = 3;

    void init(size_t count) {
        _size = 0;
        _blocks_count = count;
        _data = new T*[count];
        for (int i = 0; i < count; i++) {
            _data[i] = (T*) new int8_t*[BLOCK_SIZE * sizeof(T)];
        }
        _front.block = INI_BLOCKS / 2;
        _front.idx = 0;
        _back.block = INI_BLOCKS / 2;
        _back.idx = 0;

    }

    void expand() {
        T **new_data = new T*[_blocks_count * EXPAND_FACTOR];

        size_t first_part_size = (EXPAND_FACTOR - 1) / 2 * _blocks_count;

        // first part
        for (int i = 0; i < first_part_size; i++) {
            new_data[i] = (T*) new int8_t[BLOCK_SIZE * sizeof(T)];
        }

        // copy old part
        for (int i = 0; i < _blocks_count; i++) {
            new_data[i+first_part_size] = _data[i];
        }

        // last part
        for (int i = first_part_size + _blocks_count; i < _blocks_count*EXPAND_FACTOR; i++) {
            new_data[i] = (T*) new int8_t[BLOCK_SIZE * sizeof(T)];
        }

        _front.block += first_part_size;
        _back.block += first_part_size;
        _blocks_count *= EXPAND_FACTOR;

        delete [] (int8_t*)_data;
        _data = new_data;
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

public:
    Deque() {
        init(INI_BLOCKS);
    }

    ~Deque() {
        clear();
        delete[] (int8_t*)_data;
    }

    Deque(const Deque &other) {
        init(other.blocks_count);

        for (size_t i = 0; i < other.size(); i++) {
            push_back(other[i]);
        }
    }

    Deque &operator=(const Deque &other) {
        clear();

        for (size_t i = 0; i < other.size(); i++) {
            push_back(other[i]);
        }

        return *this;
    }

    T &at(int64_t i) const {
        if (i < 0)
            throw std::out_of_range("Index out of range");


        size_t block_index = _front.block + (i + _front.idx) / BLOCK_SIZE;
        size_t cell_index = (i + _front.idx) % BLOCK_SIZE;

        if (_back.block * BLOCK_SIZE + _back.idx >= block_index * BLOCK_SIZE + cell_index) {
            return _data[block_index][cell_index];
        }

        throw std::out_of_range("Index out of range");
    }

    T &operator[](size_t i) {
        return at(i);
    }


    void push_back(T el) {
        if (_back.block == _blocks_count - 1 && _back.idx == BLOCK_SIZE - 1) {
            expand();
        }

        // move bock position
        if (_size > 0)
            ++_back;

        new (_data[_back.block] + _back.idx) T(el);
        _size++;
    }

    void pop_back() {
        if (_size <= 0) {
            throw std::out_of_range("Index out of range");
        }

        _data[_back.block][_back.idx].~T();

        _size--;
        if (_size > 0) {
            --_back;
        }
    }

    void push_front(T el) {
        if (_front.block == 0 && _front.idx == 0) {
            expand();
        }

        // move bock position
        if (_size > 0)
            --_front;


        new (_data[_front.block] + _front.idx) T(el);
        _size++;
    }

    void pop_front() {
        if (_size <= 0) {
            throw std::out_of_range("Index out of range");
        }

        _data[_front.block][_front.idx].~T();

        _size--;
        if (_size > 0) {
            ++_front;
        }

    }

    size_t size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }

    void clear() {
        while (_size) {
            pop_back();
        }
        _back.block = _blocks_count / 2;
        _back.idx = 0;
        _front.block = _blocks_count / 2;
        _front.idx = 0;
    }

    Iterator begin() { return Iterator(this, 0); }
    Iterator end() { return Iterator(this, size()); }

};

#endif // DEQUEUE_H
