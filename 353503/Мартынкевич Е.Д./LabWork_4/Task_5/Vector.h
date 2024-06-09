#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <memory>
#include <vector>

template<typename T>
class allocator : public std::allocator<T> {
public:
    T* allocate(size_t count) const {
        return reinterpret_cast<T*>(::operator new(count * sizeof(T)));
    }

    void deallocate(void* ptr, size_t) const {
        ::operator delete(ptr);
    }

    template<typename... Args >
    void construct(T* ptr, Args&&... args) {
        new(ptr) T(std::forward<Args>(args) ...);
    }

    void destroy(T* ptr) {
        ptr->~T();
    }

    using value_type = T;
};

template<typename T>
class iterator {
private:
    T* p;
public:
    iterator(T* value) {
        p = value;
    }
    ~iterator() {}
    void operator ++() {
        ++p;
    }
    void operator --() {
        --p;
    }
    void operator +=(int n) {
        p += n;
    }
    void operator -=(int n) {
        p -= n;
    }
    iterator<T> operator +(int n) {
        auto copy = *this;
        copy += n;
        return copy;
    }
    iterator<T> operator -(int n) {
        auto copy = *this;
        copy -= n;
        return copy;
    }
    T& operator* () {
        return *p;
    }
    T* operator ->() {
        return p;
    }
    size_t operator-(iterator<T> secondIter) {
        return p - secondIter.p;
    }
};
/*
void* operator new(size_t n, std::nothrow_t) {
    return malloc(n);
}

void* operator new(size_t n) {
    void* a = malloc(n);

    if (a == nullptr) throw std::bad_alloc();
    else return a;
}

void operator delete(void* ptr) {
    free(ptr);
}
*/

template <typename T, typename Alloc = const allocator<T>>
class Vector
{
    using traits = std::allocator_traits<Alloc>;
public:
    explicit Vector(size_t count = 0, const T& value = T(), const Alloc& alloc = Alloc()) : alloc(alloc) {
        sz = 0;
        cap = count;
        arr = traits::allocate(alloc, count);
        for (int i = 0; i < count; ++i) {
            traits::construct(alloc, arr + i, value);
        }
    };

    explicit Vector(const Vector<T, Alloc>& v) : alloc(traits::select_on_container_copy_construction()) {

    }

    Vector<T, Alloc>& operator =(const Vector<T, Alloc>& v) {
        for (int i = 0; i < sz; ++i) {
            traits::destroy(alloc, arr + i);
        }
        traits::deallocate(arr, sz);

        if (traits::propagate_on_container_copy_assignment::value && alloc != v.alloc) {
            alloc = v.alloc;
        }

        int i = 0;

        try {
            reserve(v.sz);
            for (i = 0; i < v.sz; ++i) {
                traits::construct(alloc, arr + i, v[i]);
            }
        }
        catch (...) {
            for (int j = 0; j < i; ++j) {
                traits::destroy(alloc, arr + j);
            }
            traits::deallocate(alloc, arr, sz);
            throw;
        }
    }
    ~Vector() {
        for (int j = 0; j < sz; ++j) {
            traits::destroy(alloc, arr + j);
        }
        traits::deallocate(alloc, arr, sz);
    }

    T& operator [](int index) {
        return arr[index];
    }

    const T& operator [](int index) const {
        return arr[index];
    }

    T& at(int index) {
        if (index >= sz) {
            throw std::out_of_range("...");
        }
    }

    size_t size() {
        return sz;
    }

    size_t capacity() {
        return cap;
    }

    void clear()
    {
        resize(0);
    }

    bool empty() {
        return sz == 0;
    }

    void reserve(int n) {
        if (n <= cap) return;

        T* newarr = traits::allocate(alloc, n);
        int i = 0;

        try {
            for (; i < sz; ++i) {
                traits::construct(alloc, newarr + i, std::move_if_noexcept(arr[i]));
            }
        }
        catch (...) {
            for (int j = 0; j < i; ++j) {
                traits::destroy(alloc, newarr + j);
            }
            traits::deallocate(alloc, newarr, n);
            throw;
        }

        for (i = 0; i < sz; ++i) {
            traits::destroy(alloc, arr + i);
        }
        traits::deallocate(alloc, arr, sz);
        arr = newarr;

        cap = n;
    }



    void resize(int n, const T& value = T()) {
        if (n > cap) {
            reserve(n);
        }

        for (int i = sz; i < n; ++i) {
            traits::construct(alloc, arr + i, T(value));
        }

        sz = n;
    }

    T &back()
    {
        return arr[sz - 1];
    }

    T &front()
    {
        return arr[0];
    }

    T *data()
    {
        return arr;
    }
    void push_back(T&& value) {
        if (sz == cap) {
            reserve(2 * cap);
        }

        traits::construct(alloc, arr + sz, T(std::forward<T>(value)));
        ++sz;
    }

    template<typename ...Args>
    void emplace_back(Args&& ...args) {
        if (sz == cap) {
            reserve(2 * cap);
        }

        traits::construct(alloc, arr + sz, std::forward<Args>(args) ...);
        ++sz;
    }

    void pop_back() {
        (arr + sz - 1)->~T();
        --sz;
    }

    iterator<T> begin() {
        return iterator<T>(arr);
    }

    iterator<T> end() {
        return iterator<T>(arr + sz);
    }

    template<typename... Args>
    void emplace(iterator<T> pos, Args ... args) {
        int a11 = pos - begin(), a12 = pos - end();
        bool a1 = a11 < 0, a2 = a12 > 0;

        if (a1 || a2) { throw std::out_of_range("Wrong iterator."); }

        if (pos - end() == 0) {
            emplace_back(args ...);
            return;
        }

        int index = pos - begin();
        resize(sz + 1);

        for (auto i = end() - 1; i - (begin() + index) > 0; --i) {
            *i = std::move_if_noexcept(*(i - 1));
        }
        traits::construct(alloc, &(*(begin() + index)), std::forward<Args>(args) ...);
        return;
    }

    void erase(iterator<T> pos) {
        int a11 = pos - begin(), a12 = pos - end();
        bool a1 = a11 < 0, a2 = a12 > 0;

        if (a1 || a2) { throw std::out_of_range("Wrong iterator."); }

        int index = pos - begin();
        for (int i = index; i < sz - 1; ++i) {
            *(arr + i) = std::move_if_noexcept(*(arr + i + 1));
        }

        resize(sz - 1);
        return;
    }

private:
    T* arr;
    int sz;
    int cap;
    Alloc alloc;
};
/*
int main() {
    Vector<int> arr(5);
    arr.push_back(3);
    std::cout << arr.capacity() << ' ' << arr.size() << '\n';
    arr.push_back(4);
    arr.push_back(345);
    std::cout << arr.capacity() << ' ' << arr.size() << '\n';
    arr.push_back(4);
    arr.push_back(345);
    arr.emplace(arr.begin() + 2, 10000);
    arr.push_back(345);
    arr.pop_back();
    arr.emplace_back(23);
    arr.erase(arr.begin() + 3);
    std::cout << arr.capacity() << ' ' << arr.size() << '\n';
    arr.resize(20, 70);
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << '\n';
    }
    std::cout << arr.capacity() << ' ' << arr.size() << '\n';

    auto a1 = arr.begin();
    auto a2 = arr.end() - 5;
    std::cout << a2 - a1 << '\n';
}
*/
#endif // VECTOR_H
