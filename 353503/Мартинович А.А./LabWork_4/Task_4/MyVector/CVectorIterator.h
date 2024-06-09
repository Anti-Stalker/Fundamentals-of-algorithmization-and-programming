#ifndef CVECTORITERATOR_H
#define CVECTORITERATOR_H
#include "cstdint"
#include "cstddef"

template <typename T>
class CVectorIterator {
public:
  explicit CVectorIterator(T* data) : m_data(data) {}

  const CVectorIterator& operator++() {
    ++m_data;
    return *this;
  }

  const CVectorIterator& operator--() {
    --m_data;
    return *this;
  }

  T operator*() const {
    return *m_data;
  }

  bool operator==(const CVectorIterator& other) const {
    return m_data == other.m_data;
  }

  bool operator!=(const CVectorIterator& other) const {
    return m_data != other.m_data;
  }

  bool operator>(const CVectorIterator& other) const {
    return m_data > other.m_data;
  }

  bool operator<(const CVectorIterator& other) const {
    return m_data < other.m_data;
  }

  bool operator>=(const CVectorIterator& other) const {
    return m_data >= other.m_data;
  }

  bool operator<=(const CVectorIterator& other) const {
    return m_data <= other.m_data;
  }

  const CVectorIterator& operator+=(size_t n) {
    m_data += n;
    return *this;
  }

  const CVectorIterator& operator-=(size_t n) {
      m_data -= n;
      return *this;
  }

private:
  T* m_data;
};

#endif // CVECTORITERATOR_H
