#ifndef PRIRITYQUEUE_H
#define PRIRITYQUEUE_H


#include <memory>

template <typename T> class PriorityQueue {
protected:
    static const size_t INITIAL_CAPACITY = 16;
    std::unique_ptr<T[]> data;
    size_t sizevar = 0;
    size_t capacity;

    size_t heapify(size_t i) {
        int max_ind = i;
        auto l = i * 2 + 1, r = i * 2 + 2;
        if (l < sizevar && data[l] > data[max_ind]) {
            max_ind = l;
        }
        if (r < sizevar && data[r] > data[max_ind]) {
            max_ind = r;
        }
        std::swap(data[max_ind], data[i]);
        return max_ind;
    }

    void grow() {
        auto new_data = std::make_unique<T[]>(capacity * 2);
        for (int i = 0; i < sizevar; ++i) {
            new_data[i] = data[i];
        }

        data = std::move(new_data);
        capacity *= 2;
    }

    bool is_full() {
        return sizevar + 1 == capacity;
    }

public:
    PriorityQueue() : data(std::make_unique<T[]>(INITIAL_CAPACITY)) {
        capacity = INITIAL_CAPACITY;
        sizevar = 0;

    }

    void clear() {
        auto initial_data = std::make_unique<T[]>(INITIAL_CAPACITY);
        data = std::move(initial_data);

        sizevar = 0;
        capacity = INITIAL_CAPACITY;
    }
    void push(T val) {
        if (is_full()) {
            grow();
        }

        data[sizevar] = val;
        ++sizevar;
        long cur = sizevar / 2 - 1;
        while (cur > 0 && heapify(cur) != cur) {
            cur = (cur - 1) / 2;
        }
        if (cur == 0) {
            heapify(0);
        }
    }
    T pop() {
        T max = data[0];

        data[0] = data[sizevar - 1];
        --sizevar;

        auto cur = 0;
        size_t largest;
        while (cur < sizevar) {
            largest = heapify(cur);
            if (cur == largest) {
                break;
            }
            cur = largest;
        }
        return max;
    }

    const T &max() {
        return data[0];
    }

    size_t size() {
        return sizevar;
    }
};

#endif // PRIRITYQUEUE_H
