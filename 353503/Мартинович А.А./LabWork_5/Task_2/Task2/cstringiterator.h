#ifndef CSTRINGITERATOR_H
#define CSTRINGITERATOR_H


#include "cstddef"

class CStringIterator
{
public:
    CStringIterator();

    explicit CStringIterator(char* data) : m_data(data) {}

    CStringIterator& operator++() {
        ++m_data;
        return *this;
    }

    CStringIterator& operator--() {
        --m_data;
        return *this;
    }

    const char& operator*() const {
        return *m_data;
    }

    bool operator==(const CStringIterator& other) const {
        return m_data == other.m_data;
    }

    bool operator!=(const CStringIterator& other) const {
        return m_data != other.m_data;
    }

    bool operator>(const CStringIterator& other) const {
        return m_data > other.m_data;
    }

    bool operator<(const CStringIterator& other) const {
        return m_data < other.m_data;
    }

    bool operator>=(const CStringIterator& other) const {
        return m_data >= other.m_data;
    }

    bool operator<=(const CStringIterator& other) const {
        return m_data <= other.m_data;
    }

    CStringIterator& operator+=(size_t n) {
        m_data += n;
        return *this;
    }

    CStringIterator& operator-=(size_t n) {
        m_data -= n;
        return *this;
    }

    int operator-(const CStringIterator& other) const {
        return m_data - other.m_data;
    }

private:
    char* m_data;
};

#endif // CSTRINGITERATOR_H
