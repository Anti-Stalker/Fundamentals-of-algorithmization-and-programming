//
// Created by darina on 5/23/24.
//

#include <iostream>
#include <cstring>
#include "MyString.h"

void *MyString::memcpy(void *s1, const void *s2, size_t n) {

    auto *str1 = static_cast<char *> (s1);
    auto *str2 = static_cast<const char *> (s2);
    if((str1!= nullptr) && (str2!= nullptr))
    {
        while(n) //till cnt
        {
            //Copy byte by byte
            *(str1++)= *(str2++);
            --n;
        }
    }
    return s1;
}

void *MyString::memmove(void *s1, const void *s2, size_t n) {
    unsigned char isCopyRequire = 0;  //flag bit
    auto *str2 = static_cast<const char *> (s2);
    auto *str1 = static_cast<char *> (s1);
    if ((str2 == nullptr) || (str1 == nullptr))
    {
        return nullptr;
    }
    // overlap buffer
    if((str2 < str1) && (str1 < str2 + n))
    {
        for (str1 += n, str2 += n; n--;)
        {
            *--str1 = *--str2;
        }
    }
    else
    {
        while(n--)
        {
            *str1++ = *str2++;
        }
    }
    return s1;
}

char *MyString::strcpy(char *s1, const char *s2) {

    if(s1 != nullptr && s2 != nullptr)
    {
        size_t i = 0;
        while(s2[i] != '\0')
            i ++;
        memcpy(s1, s2, i);
        s1[i] = '\0';
        return s1;
    }
    else
        throw "bad pointer";
}

char *MyString::strncpy(char *s1, const char *s2, size_t n) {

    if(s1 == nullptr || s2 == nullptr)
        throw "bad pointer";
    int i = 0;
    for(; i < n && s2[i] != '\0'; i ++)
    {
        s1[i] = s2[i];
    }
    if(i < n)
        s1[i] = '\0';
    return s1;
}

char *MyString::strcat(char *s1, const char *s2) {
    if(s1 == nullptr || s2 == nullptr)
        throw "bad pointer";
    int i = 0;
    while(s1[i] != '\0')
        i ++;
    int j = 0;
    while(s2[j] != '\0')
    {
        s1[i] = s2[j];
        i ++;
        j ++;
    }
    s1[i] = '\0';
    return s1;
}

char *MyString::strncat(char *s1, const char *s2, size_t n) {
    if(s1 == nullptr || s2 == nullptr)
        throw "bad pointer";
    if(s1 == nullptr || s2 == nullptr)
        throw "bad pointer";
    int i = 0;
    while(s1[i] != '\0')
        i ++;
    int j = 0;
    while(s2[j] != '\0' && j < n)
    {
        s1[i] = s2[j];
        i ++;
        j ++;
    }
    s1[i] = '\0';
    return s1;
}

int MyString::memcmp(const void *s1, const void *s2, size_t n) {
    int i = 0;
    auto *str2 = static_cast<const char *> (s2);
    auto *str1 = static_cast<const char *> (s1);
    while(i < n && str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] < str2[i])
            return -1;
        if(str1[i] > str2[i])
            return 1;
        i ++;
    }
    if(i == n)
        return 0;
    if(str1[i] == '\0' && str2[i] == '\0')
        return 0;
    if(str1[i] == '\0')
        return -1;
    return 1;
}

int MyString::strcmp(const char *s1, const char *s2) {
    int i = 0;
    auto *str2 = static_cast<const char *> (s2);
    auto *str1 = static_cast<const char *> (s1);
    while(str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] < str2[i])
            return -1;
        if(str1[i] > str2[i])
            return 1;
        i ++;
    }
    if(str1[i] == '\0' && str2[i] == '\0')
        return 0;
    if(str1[i] == '\0')
        return -1;
    return 1;
}

int MyString::strcoll(const char *s1, const char *s2) {
    return strcmp(s1, s2);
}

int MyString::strncmp(const char *s1, const char *s2, size_t n) {
    int i = 0;
    auto *str2 = static_cast<const char *> (s2);
    auto *str1 = static_cast<const char *> (s1);
    while(str1[i] != '\0' && str2[i] != '\0' && n --)
    {
        if(str1[i] < str2[i])
            return -1;
        if(str1[i] > str2[i])
            return 1;
        i ++;
    }
    if(str1[i] == '\0' && str2[i] == '\0')
        return 0;
    if(str1[i] == '\0')
        return -1;
    return 1;
}

char *MyString::strxfrm(char *s1, const char *s2, size_t n) {

    return strncpy(s1, s2, n);
}

char *MyString::strtok(char *s1, const char *s2) {
    static char *last = nullptr;
    char *start;
    const char *delim = s2;
    if(s1 == nullptr || s1[0] == '\0')
        return nullptr;
    while (*last != '\0' && strchr(delim, *last) != nullptr)
        last++;

    if (*last == '\0') {
        last = nullptr;
        return nullptr;
    }

    start = last;

    while (*last != '\0' && strchr(delim, *last) == nullptr)
        last++;

    if (*last == '\0') {
        last = nullptr;
    } else {
        *last = '\0';
        last++;
    }

    return start;
}

void *MyString::memset(void *s, int c, size_t n) {
    auto *s2 = static_cast<char *>(s);
    auto v = static_cast<char>(c);
    int i = 0;
    for (; i < n; i++) {
        s2[i] = v;
    }
    s2[i] = '\0';
    return s;
}

char *MyString::strerror(int errnum) {
    return std::strerror(errnum);
}

size_t MyString::strlen(const char *s) {
    if(s == nullptr)
        return 0;
    int len = 0;
    while(*s != '\0')
    {
        s ++;
        len ++;
    }
    return len;
}


MyString::MyString()
        : ptr(std::make_unique<char[]>(1))
        , sz(1)
        , cap(1)
{
    ptr[0] = '\0';
}

MyString::MyString(const char *str)
{
    size_t mySize = strlen(str) + 1;
    ptr = std::make_unique<char[]>(mySize);
    sz = mySize;
    cap = mySize;
    memcpy(ptr.get(), str, strlen(str));
}

MyString::MyString(size_t amnt, char c)
        : ptr(std::make_unique<char[]>(amnt + 1))
        , sz(amnt + 1)
        , cap(amnt + 1)
{
    for (size_t i = 0; i < amnt; ++i) {
        ptr[i] = c;
    }
}

MyString::MyString(const MyString &other)
        : ptr(std::make_unique<char[]>(other.sz))
        , sz(other.sz)
        , cap(other.sz)
{
    strcpy(ptr.get(), other.ptr.get());
}

MyString::MyString(MyString &&other) noexcept
        : ptr(std::move(other.ptr))
        , sz(other.sz)
        , cap(other.sz)
{
    other.cap = 0;
    other.sz = 0;
    other.resize(0);
}

void MyString::resize(size_t _size)
{
    ++_size;
    if (_size <= sz) {
        sz = _size;
        ptr[sz - 1] = '\0';
    } else {
        reserve(_size);
        for (size_t i = sz; i < _size; ++i) {
            ptr[i] = '\0';
        }
        sz = _size;
    }
}

void MyString::reserve(size_t _size)
{
    ++_size;
    if (_size <= cap) {
        return;
    }

    std::unique_ptr<char[]> new_ptr = std::make_unique<char[]>(_size);
    if (sz > 1) {
        memcpy(new_ptr.get(), ptr.get(), sz);
    }
    ptr = std::move(new_ptr);
    cap = _size;
}

bool MyString::empty() const
{
    if(sz <= 1)
        return true;
    return false;
}

size_t MyString::size() const
{
    if (sz == 0) {
        return 0;
    }
    return sz - 1;
}

size_t MyString::capacity() const
{
    return cap;
}

void MyString::clear()
{
    resize(0);
}

void MyString::erase(size_t pos, size_t len)
{
    if(sz - pos < len)
        len = sz - pos;
    memmove(ptr.get() + pos, ptr.get() + pos + len, sz - pos - len + 1);
    sz -= len;
}

void MyString::push_back(char c)
{
    if (sz + 1 >= cap) {
        if(cap == 0)
            reserve(2);
        else
            reserve(cap * 2 + 1);
    }
    ptr[sz - 1] = c;
    ptr[sz] = '\0';
    ++sz;
}

void MyString::pop_back()
{
    if(cap == 0)
        return;

    if (sz > 1) {
        back() = '\0';
        --sz;
        return;
    }

    front() = '\0';
}

char &MyString::front() {
    return ptr[0];
}

char &MyString::back() {
    return ptr[sz - 2];
}

void MyString::insert(size_t pos, const char *str) {
    int len = strlen(str);
    if(len + sz < cap)
        reserve(len + sz + 2);
    memmove(ptr.get() + pos + len, ptr.get() + pos, sz - pos);
    memcpy(ptr.get() + pos, str, len);
    sz += len;
}

void MyString::append(const char *str)
{
    insert(sz - 1, str);
}

void MyString::append(const MyString &str)
{
    append(str.ptr.get());
}


MyString operator+(const MyString &left, const MyString &right)
{
    MyString result(left);
    result.append(right);
    return result;
}

MyString operator+(const MyString &left, char right)
{
    MyString result(left);
    result.push_back(right);
    return result;
}

MyString &MyString::operator=(const MyString &other)
{
    if (&other != this) {
        ptr = std::make_unique<char[]>(other.sz);
        sz = other.sz;
        cap = other.cap;
        strcpy(ptr.get(), other.ptr.get());
    }

    return *this;
}

MyString &MyString::operator=(MyString &&other) noexcept
{
    ptr = std::move(other.ptr);
    sz = other.sz;
    cap = other.cap;

    other.cap = 0;
    other.sz = 0;
    other.resize(0);

    return *this;
}

char &MyString::operator[](size_t n) const {
        return ptr[n];
}
