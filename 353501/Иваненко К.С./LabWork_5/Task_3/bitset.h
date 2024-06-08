#pragma once

#define BITSET_H
#ifdef BITSET_H

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <bit>

template <size_t N>
class Bitset
{
public:
  Bitset() : data_(new uint64_t[(N + 63) / 64])
  {
    reset();
  }

  Bitset(const Bitset &other) : data_(new uint64_t[(N + 63) / 64])
  {
    for (size_t i = 0; i < (N + 63) / 64; ++i)
    {
      data_[i] = other.data_[i];
    }
  }

  Bitset(Bitset &&other) noexcept : data_(other.data_)
  {
    other.data_ = nullptr;
  }

  ~Bitset()
  {
    delete[] data_;
  }

  Bitset &operator=(const Bitset &other)
  {
    if (this != &other)
    {
      for (size_t i = 0; i < (N + 63) / 64; ++i)
      {
        data_[i] = other.data_[i];
      }
    }
    return *this;
  }

  Bitset &operator=(Bitset &&other) noexcept
  {
    if (this != &other)
    {
      delete[] data_;
      data_ = other.data_;
      other.data_ = nullptr;
    }
    return *this;
  }

  bool operator[](size_t i) const
  {
    if (i >= N)
    {
      throw std::out_of_range("Index out of range");
    }
    return (data_[i / 64] & (1ULL << (i % 64))) != 0;
  }

  Bitset &operator~()
  {
    for (size_t i = 0; i < (N + 63) / 64; ++i)
    {
      data_[i] = ~data_[i];
    }
    return *this;
  }

  Bitset operator|(const Bitset &other) const
  {
    Bitset result;
    for (size_t i = 0; i < (N + 63) / 64; ++i)
    {
      result.data_[i] = data_[i] | other.data_[i];
    }
    return result;
  }

  Bitset operator&(const Bitset &other) const
  {
    Bitset result;
    for (size_t i = 0; i < (N + 63) / 64; ++i)
    {
      result.data_[i] = data_[i] & other.data_[i];
    }
    return result;
  }

  size_t size() const
  {
    return N;
  }

  bool all() const
  {
    for (size_t i = 0; i < (N + 63) / 64 - 1; ++i)
    {
      if (data_[i] != std::numeric_limits<uint64_t>::max())
      {
        return false;
      }
    }
    return (data_[(N + 63) / 64 - 1] & ((1ULL << (N % 64)) - 1)) == ((1ULL << (N % 64)) - 1);
  }

  bool any() const
  {
    for (size_t i = 0; i < (N + 63) / 64; ++i)
    {
      if (data_[i] != 0)
      {
        return true;
      }
    }
    return false;
  }

  bool none() const
  {
    return !any();
  }

  size_t count() const
  {
    size_t cnt = 0;
    for (size_t i = 0; i < (N + 63) / 64; ++i)
    {
      cnt += __builtin_popcount(data_[i]);
    }
    cnt += __builtin_popcount(data_[(N + 63) / 64 - 1] & ((1ULL << (N % 64)) - 1));
    return cnt;
  }

  void flip()
  {
    for (size_t i = 0; i < (N + 63) / 64; ++i)
    {
      data_[i] = ~data_[i];
    }
  }

  void flip(size_t i)
  {
    if (i >= N)
    {
      throw std::out_of_range("Index out of range");
    }
    data_[i / 64] ^= (1ULL << (i % 64));
  }

  void reset()
  {
    for (size_t i = 0; i < (N + 63) / 64; ++i)
    {
      data_[i] = 0;
    }
  }

  void reset(size_t i)
  {
    if (i >= N)
    {
      throw std::out_of_range("Index out of range");
    }
    data_[i / 64] &= ~(1ULL << (i % 64));
  }

void set()
{
  for (size_t i = 0; i < (N + 63) / 64 - 1; ++i)
  {
    data_[i] = std::numeric_limits<uint64_t>::max();
  }
  data_[(N + 63) / 64 - 1] = std::numeric_limits<uint64_t>::max();
}

  void set(size_t i)
  {
    if (i >= N)
    {
      throw std::out_of_range("Index out of range");
    }
    data_[i / 64] |= (1ULL << (i % 64));
  }

  bool test(size_t i) const
  {
    if (i >= N)
    {
      throw std::out_of_range("Index out of range");
    }
    return (data_[i / 64] & (1ULL << (i % 64))) != 0;
  }

  std::string to_string() const
  {
    std::string result;
    result.resize(N, '0');
    for (size_t i = 0; i < N; ++i)
    {
      if ((*this)[i])
      {
        result[N - i - 1] = '1';
      }
    }
    return result;
  }

  uint64_t to_ullong() const
  {
    uint64_t result = 0;
    for (size_t i = 0; i < N; ++i)
    {
      result += (*this)[i];
    }
    return result;
  }

  uint64_t to_ulong() const
  {
    uint64_t result = 0;
    for (size_t i = 0; i < N; ++i)
    {
      result |= (static_cast<uint64_t>((*this)[i]) << i);
    }
    return result;
  }

private:
  uint64_t *data_;
};

#endif // BITSET_H