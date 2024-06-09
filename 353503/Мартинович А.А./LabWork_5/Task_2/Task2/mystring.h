#ifndef STRINGFUNSTIONS_H
#define STRINGFUNSTIONS_H
#include "cstddef"
#include "memory"
#include "stringfunstions.h"
#include "stringitearator.h"
#include "cstringiterator.h"
#include "rstringiterator.h"
#include "iostream"
#include "QDebug"

class String {
private:
    std::unique_ptr<char[]> _data;
    size_t _size;
    size_t _capacity;

public:    
    String() : _data(nullptr), _size(0) {}

    explicit String(const char* str) : _size(my_cstring::strlen(str))
    {
        _capacity = _size;
        _data.reset(new char[_size + 1]);
        my_cstring::strcpy(_data.get(), str);
    }

    ~String() = default;

    String(const String& other) : _capacity(other._capacity), _size(other._size) {
        _data.reset(new char[_size + 1]);
        my_cstring::strcpy(_data.get(), other._data.get());
    }

    String& operator=(const String& other) {
        if (this == & other) {
            return *this;
        }

        _capacity = other._capacity;
        _size = other._size;

        _data.reset(new char[_size + 1]);
        my_cstring::strcpy(_data.get(), other._data.get());

        return *this;
    }

    String& operator=(const char* str) {
        _size = my_cstring::strlen(str);
        _capacity = _size;
        _data.reset(new char[_size + 1]);
        my_cstring::strcpy(_data.get(), str);

        return *this;
    }

    String(const char* str, size_t len) {
        _size = len;
        _capacity = len;
        _data.reset(new char[len + 1]);
        my_cstring::memcpy(_data.get(), str, len);
     }

    void reserve(size_t new_capacity) {
        if (new_capacity > _capacity) {
            std::unique_ptr<char[]> new_data(new char[new_capacity]);
            if (_size > 0) {
                my_cstring::strcpy(new_data.get(), _data.get());
            }
            _data.swap(new_data);
            _capacity = new_capacity;
        }
    }

    void shrink_to_fit() {
        if (_size < _capacity) {
            std::unique_ptr<char[]> new_data(new char[_size + 1]);

            if (_size > 0) {
                my_cstring::strcpy(new_data.get(), _data.get());
            }

            _data.swap(new_data);
            _capacity = _size;
        }
    }

    void append(const char* str) {
        size_t str_len = my_cstring::strlen(str);

        if (_size + str_len >= _capacity) {
            reserve(_size + str_len + 1);
        }

        my_cstring::strcpy(_data.get() + _size, str);
        _size += str_len;
    }

    void append(const String& other) {
        if (_size + other._size >= _capacity) {
            reserve(_size + other._size + 1);
        }

        my_cstring::strcpy(_data.get() + _size, other._data.get());
        _size += other._size;
    }

    void push_back(char c) {
        if (_size + 1 >= _capacity) {
            reserve(_size + 2); // +1 for character, +1 for null terminator
        }

        _data[_size] = c;
        _size++;
        _data[_size] = '\0';
    }

    void assign(const char* str) {
        size_t str_len = my_cstring::strlen(str);

        if (str_len >= _capacity) {
            reserve(str_len + 1);
        }

        my_cstring::strcpy(_data.get(), str);

        _size = str_len;
    }

    void assign(const char* str, size_t count) {
        if (count >= _capacity) {
            reserve(count + 1);
        }
        my_cstring::strncpy(_data.get(), str, count);

        _size = count;
        _data[_size] = '\0';
    }

    void assign(const String& other) {
        if (other._size >= _capacity) {
            reserve(other._size + 1);
        }

       my_cstring::strcpy(_data.get(), other._data.get());

       _size = other._size;
    }

    void insert(size_t pos, const char* str) {
        if (pos > _size) {
            return;
        }

        size_t str_len = my_cstring::strlen(str);

        if (_size + str_len >= _capacity) {
            reserve(_size + str_len + 1);
        }

        my_cstring::memmove(_data.get() + pos + str_len, _data.get() + pos, _size - pos + 1);

        my_cstring::memcpy(_data.get() + pos, str, str_len);

        _size += str_len;
    }


    void erase(size_t pos, size_t count = 1) {
        if (pos >= _size) {
            return;
        }

        if (pos + count > _size) {
            count = _size - pos;
        }

        my_cstring::memmove(_data.get() + pos, _data.get() + pos + count, _size - pos - count);

        _size -= count;
        _data[_size] = '\0';
    }

    void replace(size_t pos, size_t len, const char* str) {
        if (pos + len > _size) {
            return;
        }

        size_t new_str_len = my_cstring::strlen(str);

        if (_size - len + new_str_len >= _capacity) {
            reserve(_size - len + new_str_len + 1);
        }


        int delta = new_str_len - len;

        if (delta != 0) {
            my_cstring::memmove(_data.get() + pos + new_str_len,
                         _data.get() + pos + len,
                         _size - pos - len + 1);
        }

        my_cstring::memcpy(_data.get() + pos, str, new_str_len);
        _size += delta;
    }

    void swap(String& other) {
        std::unique_ptr<char[]> tmp_data(std::move(_data));
        _data = std::move(other._data);
        other._data = std::move(tmp_data);

        size_t tmp_size = _size;
        _size = other._size;
        other._size = tmp_size;

        size_t tmp_capacity = _capacity;
        _capacity = other._capacity;
        other._capacity = tmp_capacity;
    }

    void pop_back() {
        if (_size == 0) {
            return;
        }

        _size--;
        _data[_size] = '\0';
    }


    friend std::ostream& operator<<(std::ostream& os, const String& str) {
            os << str._data.get();
            return os;
    }

    friend QDebug operator<<(QDebug dbg, const String& str) {
            dbg.nospace() << str._data.get();
            return dbg.maybeSpace();
    }


    size_t size() const {
        return _size;
    }

    size_t lenght() const {
        return _size;
    }

    size_t capacity() const {
        return _capacity;
    }

    bool empty() const {
        return _size == 0;
    }

    void clear() {
        _size = 0;
        _data[0] = '\0';
    }

    char& at(size_t pos) {
        if (pos >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[pos];
    }

    const char& at(size_t pos) const {
        if (pos >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[pos];
    }

    char& front() {
        if (_size == 0) {
            throw std::out_of_range("String is empty");
        }
        return _data[0];
    }

    const char& front() const {
        if (_size == 0) {
            throw std::out_of_range("String is empty");
        }
        return _data[0];
    }

    char& back() {
        if (_size == 0) {
            throw std::out_of_range("String is empty");
        }
        return _data[_size - 1];
    }

    const char& back() const {
        if (_size == 0) {
            throw std::out_of_range("String is empty");
        }
        return _data[_size - 1];
    }

    String substr(size_t pos, size_t count) const {
        if (pos > _size) {
            throw std::out_of_range("Invalid starting position");
        }

        size_t sub_len = std::min(count, _size - pos);

        String result;
        result._size = sub_len;

        result.reserve(sub_len + 1);

        my_cstring::memcpy(result._data.get(), _data.get() + pos, sub_len);

        result._data[sub_len] = '\0';

        return result;
    }

    int compare(const String& other) const {
        size_t len = std::min(_size, other._size);

        int result = my_cstring::memcmp(_data.get(), other._data.get(), len);

        if (result == 0) {
            if (_size < other._size) {
                result = -1;
            } else if (_size > other._size) {
                result = 1;
            }
        }

        return result;
    }

    size_t find(const char* str, size_t pos = 0) const {
        if (pos > _size) {
            return -1; // Invalid start position
        }

        const char* result = my_cstring::strstr(_data.get() + pos, str);

        if (result) {
            return result - _data.get();
        } else {
            return -1;
        }
    }

    size_t copy(char* dest, size_t count, size_t pos = 0) const {
        if (pos > _size) {
            throw std::out_of_range("Invalid starting position");
        }

        size_t actual_count = std::min(count, _size - pos);

        my_cstring::memcpy(dest, _data.get() + pos, actual_count);

        return actual_count;
    }

    StringIterator begin() {
        return StringIterator(_data.get());
    }

    StringIterator end() {
        return StringIterator(_data.get() + _size);
    }

    CStringIterator cbegin() {
        return CStringIterator(_data.get());
    }

    CStringIterator cend() {
        return CStringIterator(_data.get() + _size);
    }

    RStringIterator rbegin() {
        return RStringIterator(_data.get() + _size);
    }

    RStringIterator rend() {
        return RStringIterator(_data.get());
    }

    String& operator+=(const String& other) {
        append(other);
        return *this;
    }

    String& operator+=(const char* other) {
        append(other);
        return *this;
    }

    char& operator[](size_t n) {
        return _data[n];
    }

    const char& operator[](size_t n) const {
        return _data[n];
    }


};

#endif // STRINGFUNSTIONS_H
