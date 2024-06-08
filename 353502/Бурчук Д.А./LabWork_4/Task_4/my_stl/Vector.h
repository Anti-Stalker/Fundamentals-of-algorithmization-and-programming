#ifndef LAB4TASK4_VECTOR_H
#define LAB4TASK4_VECTOR_H

#include "iterator"
#include <memory>
#include <utility>
#include <cmath>

namespace my {
    template<typename T, typename Alloc = std::allocator<T>>
    class Vector {
        T *ptr;
        int _size;
        int _capacity;
        Alloc _allocator;

    public:
        typedef T *iterator;
        typedef const T *const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;

        Vector();

        Vector(T array[], int size);

        ~Vector();

        Vector(const Vector &&other) : Vector(other.data(), other.size()) {
            other->ptr = nullptr;
            other->_size = 0;
            other->_capacity = 0;
            other->_allocator = nullptr;
        }

        Vector(const Vector &other) {
            _size = other._size;
            _capacity = other._capacity;
            ptr = _allocator.allocate(_capacity);
            for (int i = 0; i < _size; ++i) {
                std::allocator_traits<Alloc>::construct(_allocator, ptr + i, other.ptr[i]);
            }
            other->ptr = nullptr;
            other->_size = 0;
            other->_capacity = 0;
            other->_allocator = nullptr;
        }


        void print();

        void assign(const T *array, int size);

        T &at(int ind);

        T &back();

        iterator begin() noexcept;

        [[nodiscard]] int capacity() const;

        const_iterator cbegin() const noexcept;

        void clear();

        T *data();

        template<typename... Args>
        typename Vector<T, Alloc>::iterator emplace_back(Args &&... _args);

        template<typename... Args>
        typename Vector<T, Alloc>::iterator emplace(const_iterator _position, Args &&... _args);

        [[nodiscard]] bool empty() const;

        iterator end() noexcept;

        void erase(iterator pos);

        T &front();

        void insert(int pos, const T &value);

        [[nodiscard]] long long max_size() const;

        void pop_back();

        void push_back(const T &element);

        reverse_iterator rbegin() noexcept;

        reverse_iterator rend() noexcept;

        void reserve(int num);

        void resize(int new_size);

        [[nodiscard]] int size() const;

        void swap(Vector<T> &arr);

        T &operator[](int ind) {
            return ptr[ind];
        }

        Vector &operator=(const Vector &other) {
            if (this != &other) {
                clear();
                _allocator.deallocate(ptr, _capacity);

                _size = other._size;
                _capacity = other._capacity;
                ptr = _allocator.allocate(_capacity);
                for (int i = 0; i < _size; ++i) {
                    std::allocator_traits<Alloc>::construct(_allocator, ptr + i, other.ptr[i]);
                }
            }
            return *this;
        }

        bool operator==(const Vector &other) const {
            if (_size != other._size) {
                return false;
            }
            for (int i = 0; i < _size; ++i) {
                if (ptr[i] != other.ptr[i]) {
                    return false;
                }
            }
            return true;
        }

        bool operator!=(const Vector &other) const {
            return !(*this == other);
        }
    };

    template<typename T, typename Alloc>
    void Vector<T, Alloc>::assign(const T *array, int size) {
        clear();

        _size = size;
        _capacity = size > 0 ? std::pow(2, static_cast<int>(std::log(size)) + 1) : 1;

        ptr = _allocator.allocate(_capacity);

        for (int i = 0; i < size; ++i) {
            std::allocator_traits<Alloc>::construct(_allocator, ptr + i, array[i]);
        }
    }

    template<typename T, typename Alloc>
    Vector<T, Alloc>::Vector()
            : ptr(nullptr), _size(0), _capacity(1) {
        ptr = _allocator.allocate(_capacity);
    }

    template<typename T, typename _Alloc>
    Vector<T, _Alloc>::Vector(T array[], int size)
            : _size(size), _capacity(std::pow(2, static_cast<int>(std::log2(size)) + 1)) {
        ptr = _allocator.allocate(_capacity);
        for (int i = 0; i < size; ++i) {
            std::allocator_traits<_Alloc>::construct(_allocator, ptr + i, array[i]);
        }
    }

    template<typename T, typename Alloc>
    Vector<T, Alloc>::~Vector() {
        clear();
        _allocator.deallocate(ptr, _capacity);
    }

    template<typename T, typename Alloc>
    void Vector<T, Alloc>::print() {
        for (int i = 0; i < _size; ++i) {
            std::cout << ptr[i] << " ";
        }
        std::cout << std::endl;
    }

    template<typename T, typename Alloc>
    void Vector<T, Alloc>::clear() {
        for (int i = 0; i < _size; ++i) {
            std::allocator_traits<Alloc>::destroy(_allocator, ptr + i);
        }
        _size = 0;
    }

    template<typename T, typename Alloc>
    T &Vector<T, Alloc>::at(int ind) {
        if (ind < 0 || ind >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return ptr[ind];
    }

    template<typename T, typename Alloc>
    T &Vector<T, Alloc>::back() {
        if (_size > 0) {
            return ptr[_size - 1];
        }
        throw std::out_of_range("Vector is empty");
    }

    template<typename T, typename Alloc>
    typename Vector<T, Alloc>::iterator Vector<T, Alloc>::begin() noexcept {
        return ptr;
    }

    template<typename T, typename Alloc>
    int Vector<T, Alloc>::capacity() const {
        return _capacity;
    }

    template<typename T, typename Alloc>
    typename Vector<T, Alloc>::const_iterator Vector<T, Alloc>::cbegin() const noexcept {
        return ptr;
    }

    template<typename T, typename Alloc>
    T *Vector<T, Alloc>::data() {
        return ptr;
    }

    template<typename T, typename Alloc>
    template<typename... _Args>
    typename Vector<T, Alloc>::iterator Vector<T, Alloc>::emplace_back(_Args &&... _args) {
        if (_size >= _capacity) {
            resize(_capacity * 2);
        }
        std::allocator_traits<Alloc>::construct(_allocator, ptr + _size, std::forward<_Args>(_args)...);
        ++_size;
        return end();
    }

    template<typename T, typename Alloc>
    template<typename... _Args>
    typename Vector<T, Alloc>::iterator Vector<T, Alloc>::emplace(const_iterator __position, _Args &&... __args) {
        if (__position < begin() || __position > end()) {
            throw std::out_of_range("Invalid position");
        }

        size_t index = __position - begin();

        if (_size >= _capacity) {
            resize(_capacity * 2);
        }

        for (iterator it = end(); it != begin() + index; --it) {
            std::allocator_traits<Alloc>::construct(_allocator, it, std::move(*(it - 1)));
            std::allocator_traits<Alloc>::destroy(_allocator, it - 1);
        }

        std::allocator_traits<Alloc>::construct(_allocator, ptr + index, std::forward<_Args>(__args)...);
        ++_size;

        return begin() + index;
    }

    template<typename T, typename Alloc>
    bool Vector<T, Alloc>::empty() const {
        return _size == 0;
    }

    template<typename T, typename Alloc>
    typename Vector<T, Alloc>::iterator Vector<T, Alloc>::end() noexcept {
        return ptr + _size;
    }

    template<typename T, typename Alloc>
    void Vector<T, Alloc>::erase(iterator pos) {
        if (pos < begin() || pos >= end()) {
            throw std::out_of_range("Invalid position");
        }
        std::allocator_traits<Alloc>::destroy(_allocator, pos);
        for (iterator it = pos; it != end() - 1; ++it) {
            std::allocator_traits<Alloc>::construct(_allocator, it, std::move(*(it + 1)));
            std::allocator_traits<Alloc>::destroy(_allocator, it + 1);
        }
        --_size;
    }

    template<typename T, typename Alloc>
    T &Vector<T, Alloc>::front() {
        if (_size > 0) {
            return ptr[0];
        }
        throw std::out_of_range("Vector is empty");
    }

    template<typename T, typename Alloc>
    void Vector<T, Alloc>::insert(int pos, const T &value) {
        if (pos < 0 || pos > _size) {
            throw std::out_of_range("Invalid position");
        }
        if (_size >= _capacity) {
            resize(_capacity * 2);
        }
        iterator tmp = ptr + pos;
        for (iterator it = end(); it != tmp; --it) {
            std::allocator_traits<Alloc>::construct(_allocator, it, std::move(*(it - 1)));
            std::allocator_traits<Alloc>::destroy(_allocator, it - 1);
        }
        std::allocator_traits<Alloc>::construct(_allocator, ptr + pos, value);
        ++_size;
    }

    template<typename T, typename Alloc>
    long long Vector<T, Alloc>::max_size() const {
        return std::allocator_traits<Alloc>::max_size(_allocator);
    }

    template<typename T, typename Alloc>
    void Vector<T, Alloc>::pop_back() {
        if (_size > 0) {
            std::allocator_traits<Alloc>::destroy(_allocator, ptr + _size - 1);
            --_size;
        }
    }

    template<typename T, typename Alloc>
    void Vector<T, Alloc>::push_back(const T &element) {
        if (_size == _capacity) {
            resize(_capacity * 2);
        }
        std::allocator_traits<Alloc>::construct(_allocator, ptr + _size, element);
        ++_size;
    }

    template<typename T, typename Alloc>
    typename Vector<T, Alloc>::reverse_iterator Vector<T, Alloc>::rbegin() noexcept {
        return reverse_iterator(end());
    }

    template<typename T, typename Alloc>
    typename Vector<T, Alloc>::reverse_iterator Vector<T, Alloc>::rend() noexcept {
        return reverse_iterator(begin());
    }

    template<typename T, typename Alloc>
    void Vector<T, Alloc>::reserve(int num) {
        if (num > max_size()) {
            throw std::length_error("Reserve exceeds maximum size");
        }
        if (_capacity < num) {
            resize(num);
        }
    }

    template<typename T, typename Alloc>
    void Vector<T, Alloc>::resize(int new_size) {
        T *new_data = _allocator.allocate(new_size);
        for (int i = 0; i < _size; ++i) {
            std::allocator_traits<Alloc>::construct(_allocator, new_data + i, std::move(ptr[i]));
            std::allocator_traits<Alloc>::destroy(_allocator, ptr + i);
        }
        _allocator.deallocate(ptr, _capacity);
        ptr = new_data;
        _capacity = new_size;
    }

    template<typename T, typename Alloc>
    int Vector<T, Alloc>::size() const {
        return _size;
    }

    template<typename T, typename Alloc>
    void Vector<T, Alloc>::swap(Vector<T> &arr) {
        std::swap(ptr, arr.ptr);
        std::swap(_size, arr._size);
        std::swap(_capacity, arr._capacity);
        std::swap(_allocator, arr._allocator);
    }

} // namespace my

#endif // LAB4TASK4_VECTOR_H
