#ifndef LAB5TASK2_STRING_H
#define LAB5TASK2_STRING_H

#include "cmath"

class String {

    char *_str;
    int _size;
    int _capacity;

public:
    String();
    explicit String(const char *str);
    explicit String(const String &string);

    int memcmp(void* s1, void* s2, size_t n);
    int strcmp(const char* s1, const char* s2);
    int strncmp(const char* s1, const char* s2, size_t n);

    char* strerror(int errnum);

    size_t strlen(const char* s);

};


#endif //LAB5TASK2_STRING_H
