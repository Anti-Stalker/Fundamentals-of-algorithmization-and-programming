#pragma once

#ifndef BINARYHEAP_SHARED_PTR_H
#define BINARYHEAP_SHARED_PTR_H

#include <memory>

template<class T>
class shared_ptr {
private:
    T *ptr;
    size_t *count;

public:
    ~shared_ptr() {
        if (!count) {
            return;
        }
        --*count;
        if (!*count) {
            delete ptr;
            delete count;
        }
    }

    size_t use_count() {
        return *count;
    }

    T *get() {
        return ptr;
    }

    shared_ptr(T *tmp) : ptr(tmp), count(new size_t(1)) {}

    shared_ptr(const shared_ptr<T> &tmp) : ptr(tmp.ptr), count(tmp.count) {
        ++*count;
    }

    shared_ptr<T> &operator=(const shared_ptr<T> &tmp) {
        if (this == &tmp) {
            return *this;
        }
        --*count;
        if (*count == 0) {
            delete ptr;
            delete count;
        }
        ptr = tmp.ptr;
        count = tmp.count;
        ++*count;
        return *this;
    }
    
    shared_ptr<T>& operator = (T* tmp) {    
    if (ptr != tmp) {
        if (count && --(*count) == 0) {
            delete ptr;
            delete count;
        }
        ptr = tmp;
        count = new size_t(1);
    }
    return *this;
}

    bool operator==(const shared_ptr<T> &tmp) {
        return this->ptr == tmp.ptr;
    }

    bool operator != (const shared_ptr<T> &tmp) {
        return !(this->ptr == tmp.ptr);
    }
    bool operator != (T * tmp){
        return !(this->ptr == tmp);
    }

    shared_ptr(shared_ptr<T> &&tmp) noexcept {
        ptr = tmp.ptr;
        count = tmp.count;
        tmp.count = nullptr;
        tmp.ptr = nullptr;

    }

    shared_ptr<T> &operator=(shared_ptr<T> &&tmp) noexcept {
        if (this == &tmp) {
            return *this;
        }
        --*count;
        if (*count == 0) {
            delete ptr;
            delete count;
        }
        ptr = tmp.ptr;
        count = tmp.count;
        tmp.count = nullptr;
        tmp.ptr = nullptr;
        return *this;
    }

    T &operator*() {
        return *ptr;
    }

    T *operator->() {
        return ptr;
    }

    T& operator[](size_t index) {
        return *(ptr + index);
    }
};
#endif //BINARYHEAP_SHARED_PTR_H
