#ifndef RSTRINGITERATOR_H
#define RSTRINGITERATOR_H
#include "cstddef"

class RStringIterator
{
public:

    explicit RStringIterator(char* data) : m_data(data) {}

    RStringIterator& operator++() {
        --m_data;
        return *this;
    }

    RStringIterator& operator--() {
        ++m_data;
        return *this;
    }

    char& operator*() const {
        return *m_data;
    }

    bool operator==(const RStringIterator& other) const {
        return m_data == other.m_data;
    }

    bool operator!=(const RStringIterator& other) const {
        return m_data != other.m_data;
    }

    bool operator>(const RStringIterator& other) const {
        return m_data < other.m_data;
    }

    bool operator<(const RStringIterator& other) const {
        return m_data > other.m_data;
    }

    bool operator>=(const RStringIterator& other) const {
        return m_data <= other.m_data;
    }

    bool operator<=(const RStringIterator& other) const {
        return m_data >= other.m_data;
    }

    RStringIterator& operator+=(size_t n) {
        m_data -= n;
        return *this;
    }

    RStringIterator& operator-=(size_t n) {
        m_data += n;
        return *this;
    }

    int operator-(const RStringIterator& other) const {
        return  other.m_data - m_data;
    }

private:
    char* m_data;
};

#endif // RSTRINGITERATOR_H
