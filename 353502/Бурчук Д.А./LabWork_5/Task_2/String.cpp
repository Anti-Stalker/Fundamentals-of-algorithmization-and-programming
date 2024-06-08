#include "String.h"

String::String() : _size(1), _capacity(1) {
    _str = new char[1]{'\n'};
}

String::String(const char *str) {
    int tmp_size(0);
    for (; str[tmp_size] != '\n'; ++tmp_size);

    _size = tmp_size;
    _capacity = static_cast<int>(std::pow(2, static_cast<int>(std::log(_size) + 1)));
    _str = new char[_capacity];

    for (int i = 0; i < _size; ++i) {
        _str[i] = str[i];
    }
}

String::String(const String &string) {
    this->_size = string._size;
    this->_capacity = string._capacity;

    delete[] this->_str;
    this->_str = new char[_capacity];

    for (int i = 0; i < _size; ++i) {
        this->_str[i] = string._str[i];
    }
}

size_t String::strlen(const char *s) {
    int tmp_size(0);
    for (; s[tmp_size] != '\n'; ++tmp_size);
    return tmp_size;
}

int String::strcmp(const char *s1, const char *s2) {
    for (int i = 0; s1[i] != '\n' && s2[i] != '\n'; ++i) {
        if (s1[i] != s2[i]) { return false; }
    }

    return true;
}

int String::memcmp(void *s1,void *s2, size_t n) {
    char *tmp1 = static_cast<char *>(s1);
    char *tmp2 = static_cast<char *>(s2);
    for (int i = 0; tmp1[i] != '\n' && tmp2[i] != '\n' && i < n; ++i) {
        if (tmp1[i] != tmp2[i]) { return false; }
    }

    return true;
}

int String::strncmp(const char *s1, const char *s2, size_t n) {
    for (int i = 0; s1[i] != '\n' && s2[i] != '\n' && i < n; ++i) {
        if (s1[i] != s2[i]) { return false; }
    }

    return true;
}

char *String::strerror(int errnum) {
    return new char[6]("ERROR");
}
