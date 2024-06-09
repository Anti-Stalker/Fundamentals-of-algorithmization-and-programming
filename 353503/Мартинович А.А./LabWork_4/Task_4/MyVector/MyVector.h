#include "cstdint"
#include "cstddef"
#include "MyAllocator.h"
#include "VectorIterator.h"
#include "CVectorIterator.h"
#include "RVectorIterator.h"
#include "iostream"
#include "QDebug"

template <typename T>
class Vector {
private:
    T* _arr;
    size_t _capacity{0};
    size_t _size{0};
    MyAllocator<T> alloc;

public:
    Vector() {
        reserve(1);
    }

    explicit Vector(size_t n, const T& value = T()) {
        this->resize(n, value);
    }

    Vector(const Vector& other) : _capacity(other._capacity), _size(other._size) {
        _arr = alloc.allocate(_capacity);

        for (size_t i = 0; i < _size; ++i) {
            alloc.construct(_arr+i, other._arr[i]);
            //new(_arr + i) T(other._arr[i]);
        }
    }

    Vector& operator=(const Vector& other) {
        if (this == & other) {
            return *this;
        }

        for (size_t i = 0; i < _size; ++i) {
            alloc.destroy(_arr + i);
        }
        alloc.deallocate(_arr, _size);

        _capacity = other._capacity;
        _size = other._size;
        _arr = alloc.allocate(_capacity);

        for (size_t i = 0; i < _size; ++i) {
            alloc.construct(_arr+i, other._arr[i]);
            //new(_arr + i) T(other._arr[i]);
        }

        return *this;
    }

    Vector(std::initializer_list<T> list) {
        reserve(list.size());
        _size = list.size();
        for (int i = 0; i < _size; i++) {
            alloc.construct(_arr + i, *(list.begin() + i));
        }
    }

    Vector& operator=(std::initializer_list<T> list) {
        reserve(list.size());
        _size = list.size();
        for (int i = 0; i < _size; i++) {
            alloc.construct(_arr + i, *(list.begin() + i));
        }
    }

    Vector (Vector&& other)  noexcept : _arr(other._arr), _capacity(other._capacity), _size(other._size) {
        other._arr = nullptr;
        other._size = 0;
        other._capacity = 0;
    }

    Vector& operator=(Vector&& other)  noexcept {
        if (this == &other) {
            return *this;
        }
        for (int i = 0; i < _size; i++) {
            alloc.destroy(_arr + i);
        }
        alloc.deallocate(_arr);

        _arr = other._arr;
        _size = other._size;
        _capacity = other._capacity;
        other._arr = nullptr;
        other._size = 0;
        other._capacity = 0;
    }

    ~Vector() {
        for (size_t i = 0; i < _size; ++i) {
            alloc.destroy(_arr + i);
        }
        alloc.deallocate(_arr, _capacity);
    }

    T& operator[](size_t n) {
        return _arr[n];
    }

    const T& operator[](size_t n) const {
        return _arr[n];
    }

    void assign(size_t n, const T& value) {
        for (size_t i = 0; i < _size; ++i) {
            alloc.destroy(_arr + i);
        }
        alloc.deallocate(_arr, _size);

        _capacity = n;
        _size = n;
        _arr = alloc.allocate(_capacity);

        for (size_t i = 0; i < _size; ++i) {
            alloc.construct(_arr+i, value);
            //new(_arr + i) T(value);
        }
    }

    T& at(size_t n) {
        if (n < _size && 0 <= n) {
            return _arr[n];
        }
        else {
            throw std::out_of_range("Index out of bounds!");
        }
    }

    T& back() {
        if (_size != 0) {
            return _arr[_size-1];
        }
        else {
            throw std::out_of_range("Index out of bounds!");
        }
    }

    T& front() {
        if (_size != 0) {
            return _arr[0];
        }
        else {
            throw std::out_of_range("Index out of bounds!");
        }
    }

    T* data() {
        if (_size != 0) {
            return _arr;
        }
        else {
            throw std::out_of_range("Index out of bounds!");
        }
    }

    const size_t size(){
        return _size;
    }

    const size_t capacity(){
        return _capacity;
    }

    bool empty() const {
        return _size == 0;
    }

    void reserve(size_t n) {
        if (n <= _capacity) {
            return;
        }

        T *new_arr = alloc.allocate(n);

        size_t i = 0;
        try {
            for (; i < _size; i++){
                alloc.construct(new_arr+i, _arr[i]);
                //new (new_arr + i) T(_arr[i]);
            }

        }  catch (...) {
            for (size_t j = 0; j < i; j++) {
                alloc.destroy(new_arr + i);
            }
            alloc.deallocate(new_arr, _size);
        }


        for (size_t i = 0; i < _size; i++) {
            alloc.destroy(_arr);
        }

        if (_capacity != 0) {
            alloc.deallocate(_arr, _size);
        }
        _arr = new_arr;
        _capacity = n;
    }

    void resize(size_t new_size, const T& value = T()) {
        if (new_size > _capacity) {
            reserve(new_size);
        }
        for (size_t i = _size; i < new_size; i ++) {
            _arr[i] = value;
        }
        _size = new_size;
    }

    template <typename ... Args>
    void emplace(size_t n, const Args& ... args) {
        if (n > _size) {
            throw std::out_of_range("Index out of bounds!");
        }

        if (_size == _capacity) {
            reserve(2 * _capacity);
        }

        for (size_t i = _size; i > n; --i) {
            alloc.construct(_arr + i, _arr[i-1]);
            alloc.destroy(_arr + i - 1);
        }

        alloc.construct(_arr + n, T(args ...));

        _size++;
    }

    void insert(size_t n, const T& value) {
            if (n > _size) {
                throw std::out_of_range("Index out of bounds!");
            }

            if (_size == _capacity) {
                reserve(2 * _capacity);
            }

            for (size_t i = _size; i > n; --i) {
                alloc.construct(_arr + i, _arr[i-1]);
                alloc.destroy(_arr + i - 1);
            }

            alloc.construct(_arr + n, value);

            _size++;
        }

    void erase(size_t n) {
        if (n >= _size) {
            throw std::out_of_range("Index out of bounds!");
        }

        for (size_t i = n; i < _size - 1; ++i) {
            alloc.construct(_arr + i, _arr[i + 1]);
            alloc.destroy(_arr + i + 1);
        }

        _size--;
    }

    template <typename ... Args>
    void emplace_back(const Args& ... args) {
        if (_capacity == _size) {
            reserve(2 * _capacity);
        }
        alloc.construct(_arr + _size, args ...);
        //new(_arr + _size) T(args ...);
        ++_size;
    }

    void push_back(const T& value) {
        emplace_back(value);
    }

    void pop_back(){
        if (_size <= 0) {
            throw std::out_of_range("Index out of bounds!");
        }
        else {
            _size--;
            alloc.destroy(_arr + _size);
        }
    }

    void clear() {
        for (size_t i = 0; i < _size; i++) {
            alloc.destroy(_arr + i);
        }

        //alloc.deallocate(_arr, _size);
        _size = 0;
    }

    void swap(Vector& other) {
        T* temp = _arr;
        _arr = other._arr;
        other._arr = temp;

        size_t t;

        t = _size;
        _size = other._size;
        other._size = t;

        t = _capacity;
        _capacity = other._capacity;
        other._capacity = t;
    }

    VectorIterator<T> begin() {
        return VectorIterator<T>(_arr);
    }

    CVectorIterator<T> cbegin() {
        return CVectorIterator<T>(_arr);
    }

    VectorIterator<T> end() {
        return VectorIterator<T>(_arr+_size);
    }

    CVectorIterator<T> cend() {
        return CVectorIterator<T>(_arr+_size);
    }

    RVectorIterator<T> rbegin() {
        return RVectorIterator<T>(_arr+_size-1);
    }

    RVectorIterator<T> rend() {
        return RVectorIterator<T>(_arr-1);
    }

};
