#include "string.h"
#include <cstring>
#include <cstddef>

String::String()
{
    data = std::make_unique<char[]>(1);
    data[0] = 0;
    _length = 0;
}

void String::copy(const char *source, size_t size)
{
    data = std::make_unique<char[]>(size + 1);
    for (size_t i = 0; i < size; i++) {
        data[i] = source[i];
    }
    _length = size;
    data[size] = 0;
}

String::String(const String &other)
{
    copy(other.data.get(), other._length);
}

String::~String()
{
    data.reset();
}

int String::compare(const String &other) const {
    if (this->_length != other._length)
        return this->_length - other._length;

    for (size_t i = 0; i < _length; i++) {
        if (this->data[i] != other.data[i]) {
            return (this->data[i] > other.data[i]) ? 1 : -1;
        }
    }

    return 0;
}

size_t String::length() const {
    for (size_t i = 0; i < _length; i++) {
        if (data[i] == 0)
            return i;
    }

    return _length;
}

String &String::operator=(const String &other) {
    copy(other.data.get(), other._length);

    return *this;
}

String &String::operator=(const char* str) {

    size_t size = std::strlen(str);
    copy(str, size);
    return *this;

}
size_t strlen(const char* s) {
    size_t length = 0;

    while (*s != '\0') {
        ++length;
        ++s;
    }

    return length;
}


String String::operator+(const String &other) const {
    String res;
    res._length = this->_length + other._length;
    res.data = std::make_unique<char[]>(res._length + 1);

    size_t pos = 0;
    for (size_t i = 0; i < this->_length; ++i) {
        if (this->data[i] == 0)
            break;
        res.data[pos++] = this->data[i];
    }

    for (size_t i = 0; i < other._length; ++i) {
        if (other.data[i] == 0)
            break;
        res.data[pos++] = other.data[i];
    }

    res.data[pos] = 0;
    res._length = pos;
    return res;
}
void* memcpy(void* s1, const void* s2, size_t n) {
    auto dst = static_cast<unsigned char*>(s1);
    auto src = static_cast<const unsigned char*>(s2);

    for (size_t i = 0; i < n; ++i) {
        dst[i] = src[i];
    }

    return s1;
}

void* memmove(void* s1, const void* s2, size_t n) {
    auto dst = static_cast<unsigned char*>(s1);
    auto src = static_cast<const unsigned char*>(s2);

    if (dst < src) {
        for (size_t i = 0; i < n; ++i)
            dst[i] = src[i];

    } else if (dst > src) {
        for (size_t i = n; i > 0; --i)
            dst[i - 1] = src[i - 1];
    }

    return s1;
}

char* strcpy(char* s1, const char* s2) {
    char* original_s1 = s1;

    while (*s2 != '\0') {
        *s1++ = *s2++;
    }

    *s1 = '\0';

    return original_s1;
}

char* strncpy(char* s1, const char* s2, size_t n) {
    char* original_s1 = s1;
    size_t i = 0;

    while (*s2 != '\0' && i < n) {
        *s1++ = *s2++;
        i++;
    }

    while (i < n) {
        *s1++ = '\0';
        i++;
    }

    return original_s1;
}

char* strcat(char* s1, const char* s2) {
    char* original_s1 = s1;

    while (*s1 != '\0') {
        s1++;
    }

    while (*s2 != '\0') {
        *s1++ = *s2++;
    }

    *s1 = '\0';

    return original_s1;
}

char* strncat(char* s1, const char* s2, size_t n) {
    char* original_s1 = s1;

    while (*s1 != '\0') {
        s1++;
    }

    while (*s2 != '\0' && n > 0) {
        *s1++ = *s2++;
        n--;
    }

    *s1 = '\0';

    return original_s1;
}

int memcmp(const void* s1, const void* s2, size_t n) {
    auto p1 = static_cast<const unsigned char*>(s1);
    auto p2 = static_cast<const unsigned char*>(s2);

    for (size_t i = 0; i < n; i++) {
        if (p1[i] < p2[i]) {
            return -1;
        } else if (p1[i] > p2[i]) {
            return 1;
        }
    }

    return 0;
}

int strcmp(const char* s1, const char* s2) {
    while (*s1 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }

    return static_cast<int>(*s1) - static_cast<int>(*s2);
}

int strncmp(const char* s1, const char* s2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (s1[i] < s2[i]) {
            return -1;
        } else if (s1[i] > s2[i]) {
            return 1;
        } else if (s1[i] == '\0') {
            return 0;
        }
    }

    return 0;
}

size_t strxfrm(char* s1, const char* s2, size_t n) {
    size_t length = strlen(s2);

    if (n > 0) {
        strncpy(s1, s2, n - 1);
        s1[n - 1] = '\0';
    }

    return length;
}

int strcoll(const char* s1, const char* s2) {
    return strcmp(s1, s2);
}

char* strtok(char* s1, const char* s2) {
    static char* lastToken = nullptr;

    if (s1 == nullptr) {
        s1 = lastToken;
    }

    while (*s1 != '\0' && strchr(s2, *s1) != nullptr) {
        s1++;
    }

    if (*s1 == '\0') {
        lastToken = nullptr;
        return nullptr;
    }

    char* tokenStart = s1;

    while (*s1 != '\0' && strchr(s2, *s1) == nullptr) {
        s1++;
    }


    if (*s1 == '\0') {
        lastToken = nullptr;
    } else {
        *s1 = '\0';
        lastToken = s1 + 1;
    }

    return tokenStart;
}

void* memset(void* s, int c, size_t n) {
    auto dst = static_cast<unsigned char*>(s);

    for (size_t i = 0; i < n; ++i) {
        dst[i] = static_cast<unsigned char>(c);
    }

    return s;
}
char *String::strerror(int errnum)
{
    static const char *errorMessages[] = {
        "No error",
        "Permission denied",
        "File not found",
        "Invalid argument"
    };

    static const int numErrors = sizeof(errorMessages) / sizeof(errorMessages[0]);
    if (errnum >= 0 && errnum < numErrors) {
        return const_cast<char*>(errorMessages[errnum]);
    } else {
        return const_cast<char*>("Unknown error");
    }
}

