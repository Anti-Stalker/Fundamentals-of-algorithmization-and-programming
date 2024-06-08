#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>
#include <utility>
template<typename T>
class VectorIterator {
public:
    // Конструкторы
    VectorIterator(T* ptr) : m_Ptr(ptr) {}

    // Операторы
    VectorIterator& operator++() { ++m_Ptr; return *this; } // Префиксный инкремент
    VectorIterator operator++(int) { VectorIterator iterator = *this; ++m_Ptr; return iterator; } // Постфиксный инкремент
    VectorIterator& operator--() { --m_Ptr; return *this; } // Префиксный декремент
    VectorIterator operator--(int) { VectorIterator iterator = *this; --m_Ptr; return iterator; } // Постфиксный декремент
    T& operator*() const { return *m_Ptr; } // Разыменование
    T* operator->() const { return m_Ptr; } // Структурная разыменование
    bool operator==(const VectorIterator& other) const { return m_Ptr == other.m_Ptr; } // Оператор сравнения на равенство
    bool operator!=(const VectorIterator& other) const { return m_Ptr != other.m_Ptr; } // Оператор сравнения на неравенство

private:
    T* m_Ptr;
};

template<typename T>
class Vector {
public:
    // Конструкторы и деструкторы
    Vector() : m_Data(nullptr), m_Size(0), m_Capacity(0) {}
    Vector(const Vector& other) : m_Data(nullptr), m_Size(0), m_Capacity(0) { assign(other.begin(), other.end()); }
    ~Vector() { clear(); }

    // Операторы присваивания
    Vector& operator=(const Vector& other) { assign(other.begin(), other.end()); return *this; }

    // Методы
    void assign( T* first, T* last);
    T& at(size_t pos);
    T& back();
    VectorIterator<T> begin();
    size_t capacity() const;
    VectorIterator<const T> cbegin() const;
    void clear();
    T* data();
    void emplace(size_t pos, const T& value);
    void emplace_back(const T& value);
    bool empty() const;
    VectorIterator<T> end();
    void erase(VectorIterator<T> pos);
    void erase(VectorIterator<T> first, VectorIterator<T> last);
    T& front();
    void insert(VectorIterator<T> pos, const T& value);
    size_t max_size() const;
    void pop_back();
    void push_back(const T& value);
    VectorIterator<T> rbegin();
    VectorIterator<const T> rbegin() const;
    VectorIterator<T> rend();
    VectorIterator<const T> rend() const;
    void reserve(size_t newCapacity);
    void resize(size_t newSize);
    size_t size() const;
    void swap(Vector& other);

private:
    T* m_Data;
    size_t m_Size;
    size_t m_Capacity;
};

// Реализация методов библиотеки Vector

template<typename T>
void Vector<T>::assign( T* first, T* last) {
    clear();
    resize(last - first);
    for (size_t i = 0; i < m_Size; ++i) {
        m_Data[i] = first[i];
    }
}

template<typename T>
T& Vector<T>::at(size_t pos) {
    if (pos >= m_Size)
        throw std::out_of_range("Vector::at out of range");
    return m_Data[pos];
}

template<typename T>
T& Vector<T>::back() {
    if (m_Size == 0)
        throw std::out_of_range("Vector::back called on empty vector");
    return m_Data[m_Size - 1];
}

template<typename T>
VectorIterator<T> Vector<T>::begin() {
    return VectorIterator<T>(m_Data);
}

template<typename T>
size_t Vector<T>::capacity() const {
    return m_Capacity;
}

template<typename T>
VectorIterator<const T> Vector<T>::cbegin() const {
    return VectorIterator<const T>(m_Data);
}

template<typename T>
void Vector<T>::clear() {
    delete[] m_Data;
    m_Data= nullptr;
    m_Size = 0;
    m_Capacity = 0;
}

template<typename T>
T* Vector<T>::data() {
    return m_Data;
}

template<typename T>
void Vector<T>::emplace(size_t pos, const T& value) {
    if (pos > m_Size)
        throw std::out_of_range("Vector::emplace out of range");

    if (m_Size == m_Capacity)
        reserve(m_Capacity * 2 + 1);

    for (size_t i = m_Size; i > pos; --i) {
        m_Data[i] = m_Data[i - 1];
    }

    m_Data[pos] = value;
    ++m_Size;
}

template<typename T>
void Vector<T>::emplace_back(const T& value) {
    if (m_Size == m_Capacity)
        reserve(m_Capacity * 2 + 1);

    m_Data[m_Size] = value;
    ++m_Size;
}

template<typename T>
bool Vector<T>::empty() const {
    return m_Size == 0;
}

template<typename T>
VectorIterator<T> Vector<T>::end() {
    return VectorIterator<T>(m_Data + m_Size);
}

template<typename T>
void Vector<T>::erase(VectorIterator<T> pos) {
    if (pos == end())
        throw std::out_of_range("Vector::erase out of range");

    for (auto it = pos; it != end() - 1; ++it) {
        *it = *(it + 1);
    }

    --m_Size;
}

template<typename T>
void Vector<T>::erase(VectorIterator<T> first, VectorIterator<T> last) {
    if (first == last)
        return;

    if (first < begin() || last > end())
        throw std::out_of_range("Vector::erase out of range");

    auto it = first;
    while (last != end()) {
        *it = *last;
        ++it;
        ++last;
    }

    m_Size -= last - first;
}

template<typename T>
T& Vector<T>::front() {
    if (m_Size == 0)
        throw std::out_of_range("Vector::front called on empty vector");
    return m_Data[0];
}

template<typename T>
void Vector<T>::insert(VectorIterator<T> pos, const T& value) {
    emplace(pos - begin(), value);
}

template<typename T>
size_t Vector<T>::max_size() const {
    // Возвращаем максимально возможное значение размера вектора
    return static_cast<size_t>(-1) / sizeof(T);
}

template<typename T>
void Vector<T>::pop_back() {
    if (m_Size == 0)
        throw std::out_of_range("Vector::pop_back called on empty vector");
    --m_Size;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    emplace_back(value);
}

template<typename T>
VectorIterator<T> Vector<T>::rbegin() {
    return VectorIterator<T>(m_Data + m_Size - 1);
}

template<typename T>
VectorIterator<const T> Vector<T>::rbegin() const {
    return VectorIterator<const T>(m_Data + m_Size - 1);
}

template<typename T>
VectorIterator<T> Vector<T>::rend() {
    return VectorIterator<T>(m_Data - 1);
}

template<typename T>
VectorIterator<const T> Vector<T>::rend() const {
    return VectorIterator<const T>(m_Data - 1);
}

template<typename T>
void Vector<T>::reserve(size_t newCapacity) {
    if (newCapacity <= m_Capacity)
        return;

    T* newData = new T[newCapacity];

    for (size_t i = 0; i < m_Size; ++i) {
        newData[i] = m_Data[i];
    }

    delete[] m_Data;
    m_Data = newData;
    m_Capacity = newCapacity;
}

template<typename T>
void Vector<T>::resize(size_t newSize) {
    if (newSize > m_Capacity)
        reserve(newSize);

    if (newSize > m_Size) {
        for (size_t i = m_Size; i < newSize; ++i) {
            m_Data[i] = T();
        }
    }

    m_Size = newSize;
}

template<typename T>
size_t Vector<T>::size() const {
    return m_Size;
}

template<typename T>
void Vector<T>::swap(Vector& other) {
    using std::swap;
    swap(m_Data, other.m_Data);
    swap(m_Size, other.m_Size);
    swap(m_Capacity, other.m_Capacity);
}

#endif // VECTOR_H
