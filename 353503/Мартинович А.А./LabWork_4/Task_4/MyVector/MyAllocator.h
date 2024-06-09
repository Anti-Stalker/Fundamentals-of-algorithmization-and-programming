#ifndef MYALLOCATOR_H
#define MYALLOCATOR_H
#include "cstddef"

//thx to FPMI

template <typename T>
class MyAllocator {
public:
    T* allocate(size_t count) const {
        return static_cast<T*>(::operator new(count * sizeof(T)));
    }

    void deallocate(T* ptr, size_t n) {
        ::operator delete(ptr);
    }

    template <typename ... Args>
    void construct(T* ptr, const Args&... args) {
        new (ptr) T(args ...);
    }

    void destroy(T* ptr) {
        ptr->~T();
    }
};

#endif // MYALLOCATOR_H
