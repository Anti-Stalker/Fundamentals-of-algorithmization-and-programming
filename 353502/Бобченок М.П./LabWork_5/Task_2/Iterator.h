//
// Created by u on 29.05.24.
//

#ifndef TASK2_ITERATOR_H
#define TASK2_ITERATOR_H

#include <iostream>

template<class T>
class Iterator {
public:
    T *const_it = nullptr;
    T *def_it = nullptr;

    void adr(T *arr) {
        def_it = arr;
    }

    bool operator==(const Iterator<T> &tmp) {
        return def_it == tmp.def_it;
    }

    Iterator<T> operator++() {
        if (const_it != nullptr) {
            return Iterator<T>(const_it);
        }
        return Iterator<T>(def_it++);
    };

    T &operator*() {
        if (const_it != nullptr) {
            return *const_it;
        }
        return *def_it;
    }

    int operator-(T *tmp) {
        return this->def_it - tmp;
    }

    int operator-(Iterator<T> tmp) {
        return this->def_it - tmp.def_it;
    }

    Iterator<T> operator-(const int &tmp) {
        this->def_it -= tmp;
        return *this;
    }

    int operator+(T *tmp) {
        return this->def_it + tmp;
    }

    Iterator<T> operator+(const int &tmp) {
        this->def_it += tmp;
        return *this;
    }

    Iterator() = default;

    Iterator(const Iterator<T> &tmp) : def_it(tmp.def_it) {}

    explicit Iterator(T *a) : def_it(a) {}
};

template<class T>
class unique_ptr {
    T *ptr = nullptr;

public:
    void swap(unique_ptr<T> &other) noexcept {
        std::swap(ptr, other.ptr);
    }

    T *adr() {
        return ptr;
    }

    T *release() {
        T *tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    void reset(T *tmp = nullptr) {
        if (ptr != tmp) {
            delete ptr;
            ptr = tmp;
        }
    }

    unique_ptr<T> &operator=(const unique_ptr<T> &tmp) = delete;

    unique_ptr<T> &operator=(unique_ptr<T> &&tmp) noexcept {
        reset(tmp.release());
        return *this;
    }

    T &operator[](size_t index) const {
        return *(ptr + index);
    }

    T &operator*() {
        return *ptr;
    }

    unique_ptr() = default;

    unique_ptr(const unique_ptr<T> &tmp) = delete;

    unique_ptr(unique_ptr<T> &&uptr) noexcept: ptr(uptr.release()) {}

    explicit unique_ptr(T *tmp) : ptr(tmp) {}

    ~unique_ptr()
    {
        delete[] ptr;
    }
};

template<class T, class... Args>
unique_ptr<T> make_unique(Args &&...args) {
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif //TASK2_ITERATOR_H
