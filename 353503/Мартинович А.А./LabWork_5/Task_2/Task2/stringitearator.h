#ifndef STRINGITEARATOR_H
#define STRINGITEARATOR_H
#include "cstddef"

class StringIterator
{
public:
    StringIterator();

    explicit StringIterator(char* data) : m_data(data) {}

    StringIterator& operator++() {
        ++m_data;
        return *this;
    }

    StringIterator& operator--() {
        --m_data;
        return *this;
    }

    char& operator*() const {
        return *m_data;
    }

    bool operator==(const StringIterator& other) const {
        return m_data == other.m_data;
    }

    bool operator!=(const StringIterator& other) const {
        return m_data != other.m_data;
    }

    bool operator>(const StringIterator& other) const {
        return m_data > other.m_data;
    }

    bool operator<(const StringIterator& other) const {
        return m_data < other.m_data;
    }

    bool operator>=(const StringIterator& other) const {
        return m_data >= other.m_data;
    }

    bool operator<=(const StringIterator& other) const {
        return m_data <= other.m_data;
    }

    StringIterator& operator+=(size_t n) {
        m_data += n;
        return *this;
    }

    StringIterator& operator-=(size_t n) {
        m_data -= n;
        return *this;
    }

    int operator-(const StringIterator& other) const {
        return m_data - other.m_data;
    }

private:
    char* m_data;
};

#endif // STRINGITEARATOR_H
