#ifndef VECTORITERATOR_H
#define VECTORITERATOR_H
#include "cstdint"
#include "cstddef"

template <typename T>
class VectorIterator {
public:
    explicit VectorIterator(T* data) : m_data(data) {}

    VectorIterator& operator++() {
        ++m_data;
        return *this;
    }

    VectorIterator& operator--() {
        --m_data;
        return *this;
    }

    T& operator*() const {
        return *m_data;
    }

    bool operator==(const VectorIterator& other) const {
        return m_data == other.m_data;
    }

    bool operator!=(const VectorIterator& other) const {
        return m_data != other.m_data;
    }

    bool operator>(const VectorIterator& other) const {
        return m_data > other.m_data;
    }

    bool operator<(const VectorIterator& other) const {
        return m_data < other.m_data;
    }

    bool operator>=(const VectorIterator& other) const {
        return m_data >= other.m_data;
    }

    bool operator<=(const VectorIterator& other) const {
        return m_data <= other.m_data;
    }

    VectorIterator& operator+=(size_t n) {
        m_data += n;
        return *this;
    }

    VectorIterator& operator-=(size_t n) {
        m_data -= n;
        return *this;
    }

    int operator-(const VectorIterator& other) const {
        return m_data - other.m_data;
    }

private:
    T* m_data;
};

#endif // VECTORITERATOR_H
