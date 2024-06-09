#ifndef RVECTORITERATOR_H
#define RVECTORITERATOR_H
#include "cstdint"
#include "cstddef"

template <typename T>
class RVectorIterator {
public:
  explicit RVectorIterator(T* data) : m_data(data) {}

  RVectorIterator& operator++() {
    --m_data;
    return *this;
  }

  RVectorIterator& operator--() {
    ++m_data;
    return *this;
  }

  T& operator*() const {
    return *m_data;
  }

  bool operator==(const RVectorIterator& other) const {
    return m_data == other.m_data;
  }

  bool operator!=(const RVectorIterator& other) const {
    return m_data != other.m_data;
  }

  bool operator>(const RVectorIterator& other) const {
    return m_data < other.m_data;
  }

  bool operator<(const RVectorIterator& other) const {
    return m_data > other.m_data;
  }

  bool operator>=(const RVectorIterator& other) const {
    return m_data <= other.m_data;
  }

  bool operator<=(const RVectorIterator& other) const {
    return m_data >= other.m_data;
  }

  RVectorIterator& operator+=(size_t n) {
    m_data -= n;
    return *this;
  }

  RVectorIterator& operator-=(size_t n) {
      m_data += n;
      return *this;
  }

private:
  T* m_data;
};

#endif // RVECTORITERATOR_H
