//
// Created by darina on 5/23/24.
//

#ifndef TASK2_MYSTRING_H
#define TASK2_MYSTRING_H


#include <cstddef>
#include <memory>

class MyString {

        std::unique_ptr<char[]> ptr;
        size_t cap = 0;
        size_t sz = 0;

public:

    MyString();
    explicit MyString(const char *str);
    MyString(size_t amnt, char c);
    MyString(const MyString &other);
    MyString(MyString &&other) noexcept;
    MyString &operator=(const MyString &other);
    MyString &operator=(MyString &&other) noexcept;
    ~MyString() = default;

    char &operator[](size_t n) const;

    static void* memcpy(void* s1, const void* s2, size_t n);
    static void* memmove(void* s1, const void* s2, size_t n);
    static char* strcpy(char* s1, const char* s2);
    static char* strncpy(char* s1, const char* s2, size_t n);
    static char* strcat(char* s1, const char* s2);
    static char* strncat(char* s1, const char* s2, size_t n);
    static int memcmp(const void* s1, const void* s2, size_t n);
    static int strcmp(const char* s1, const char* s2);
    static int strcoll(const char* s1, const char* s2);
    static int strncmp(const char* s1, const char* s2, size_t n);
    static char* strxfrm(char* s1, const char* s2, size_t n);
    static char* strtok(char* s1, const char* s2);
    static void* memset(void* s, int c, size_t n);
    static char* strerror(int errnum);
    static size_t strlen(const char* s);

    void resize(size_t _size);
    void reserve(size_t _size);
    bool empty() const;
    size_t size() const;
    size_t capacity() const;

    char& front();
    char& back();

    void clear();
    void erase(size_t pos, size_t len);
    void push_back(char c);
    void pop_back();
    void insert(size_t pos, const char* str);

    void append(const char* str);
    void append(const MyString &str);

    friend MyString operator+(const MyString &left, const MyString &right);
    friend MyString operator+(const MyString &left, char right);

};


#endif //TASK2_MYSTRING_H
