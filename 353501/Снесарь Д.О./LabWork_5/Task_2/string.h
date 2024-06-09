#ifndef STRING_H
#define STRING_H


#include <iostream>
#include <memory>
#include "Iterator.h"

class String
{
private:
    std::unique_ptr<char[]> data;
    size_t _length;
    void copy(const char* source, size_t size);

public:
    Iterator begin() { return Iterator(data.get()); }
    Iterator end() { return Iterator(data.get() + _length); }
    const Iterator cbegin() const { return Iterator(data.get()); }
    const Iterator cend() const { return Iterator(data.get() + _length); }

    String();

    String(const String &other);
    ~String();

    int compare(const String &other) const;
    size_t length() const;


    String &operator=(const String &other);
    String &operator=(const char* str);
    String operator+(const String &other) const;
    bool operator<(const String &other) const { return compare(other) < 0; }
    bool operator>(const String &other) const { return compare(other) > 0; }
    bool operator==(const String &other) const { return compare(other) == 0; }
    bool operator!=(const String &other) const { return compare(other) != 0; }
    bool operator<=(const String &other) const { return compare(other) <= 0; }
    bool operator>=(const String &other) const { return compare(other) >= 0; }
    char* getData() const { return data.get(); }

    void* memcpy(void* s1, const void* s2, size_t n);
    void* memmove(void* s1, const void* s2, size_t n);
    char* strcpy(char* s1, const char* s2);
    char* strncpy(char* s1, const char* s2, size_t n);
    char* strcat(char* s1, const char* s2);
    char* strncat(char* s1, const char* s2, size_t n);
    int memcmp(const void* s1, const void* s2, size_t n);
    int strcmp(const char* s1, const char* s2);
    int strcoll(const char* s1, const char* s2);
    int strncmp(const char* s1, const char* s2, size_t n);
    size_t strxfrm(char* s1, const char* s2, size_t n);
    char* strtok(char* s1, const char* s2);
    void* memset(void* s, int c, size_t n);
    char* strerror(int errnum);
    size_t strlen(const char* s);
};

#endif // STRING_H
