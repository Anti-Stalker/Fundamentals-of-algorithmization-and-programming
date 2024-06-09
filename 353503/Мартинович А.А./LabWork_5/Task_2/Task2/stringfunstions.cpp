#include "stringfunstions.h"


void *my_cstring::memcpy(void *s1, const void *s2, size_t n) {
    char* dest = static_cast<char*>(s1);
    const char* src = static_cast<const char*>(s2);
    while (n-- > 0) {
        *dest++ = *src++;
    }
    return s1;
}

void *my_cstring::memmove(void *s1, const void *s2, size_t n) {
    char* dest = static_cast<char*>(s1);
    const char* src = static_cast<const char*>(s2);

    if (dest <= src) {
        while (n--) {
            *dest++ = *src++;
        }
    } else {
        dest += n;
        src += n;
        while (n--) {
            *--dest = *--src;
        }
    }

    return s1;
}

char *my_cstring::strcpy(char *s1, const char *s2) {
    char* dest = s1;
    while ((*dest++ = *s2++) != '\0') {;
}
    return s1;
}

char *my_cstring::strncpy(char *s1, const char *s2, size_t n) {
    char* dst = s1;
    const char* src = s2;
    size_t i = 0;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dst[i] = src[i];
    }
    for ( ; i < n; i++) {
        dst[i] = '\0';
    }
    return s1;
}

char *my_cstring::strcat(char *s1, const char *s2) {
    char* dst = s1;
    while (*dst) {
        dst++;  // Находим конец строки s1
    }
    while ((*dst++ = *s2++) != '\0') { /* ничего не делаем */ }
    return s1;
}

char *my_cstring::strncat(char *s1, const char *s2, size_t n) {
    char* dst = s1;
    while (*dst) {
        dst++;  // Находим конец строки s1
    }
    size_t i = 0;
    for (; i < n && s2[i] != '\0'; i++) {
        dst[i] = s2[i];
    }
    dst[i] = '\0';  // Добавляем завершающий символ null
    return s1;
}

int my_cstring::memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char* p1 = static_cast<const unsigned char*>(s1);
    const unsigned char* p2 = static_cast<const unsigned char*>(s2);

    for (size_t i = 0; i < n; i++) {
        if (p1[i] < p2[i]) {
            return -1;
        } else if (p1[i] > p2[i]) {
            return 1;
        }
    }
    return 0;
}

int my_cstring::strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *reinterpret_cast<const unsigned char*>(s1) - *reinterpret_cast<const unsigned char*>(s2);
}

int my_cstring::strcoll(const char *s1, const char *s2) {
    setlocale(LC_ALL, "");  // Устанавливаем текущую локаль
    return strcmp(s1, s2);  // Используем strcmp для сравнения строк
}

int my_cstring::strncmp(const char *s1, const char *s2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            return static_cast<unsigned char>(s1[i]) - (unsigned char)s2[i];
        }
        if (s1[i] == '\0') {
            return 0;
        }
    }
    return 0;
}

size_t my_cstring::strxfrm(char *s1, const char *s2, size_t n) {
    setlocale(LC_ALL, "");  // Устанавливаем текущую локаль
    size_t len = strlen(s2);
    if (len < n) {
        memcpy(s1, s2, len + 1);  // Копируем s2 в s1
    }
    return len;
}

size_t my_cstring::strlen(const char *s) {
    const char* p = s;
    while (*p) {
        ++p;
    }
    return p - s;
}

char *my_cstring::strtok(char *s1, const char *s2) {
    static char* next_token;
    if (s1 != nullptr) {
        next_token = s1;
    }
    if (next_token == nullptr) {
        return nullptr;
    }
    char* token_start = next_token;
    next_token = strpbrk(token_start, s2);
    if (next_token != nullptr) {
        *next_token = '\0';
        next_token++;
    }
    return token_start;
}

char *my_cstring::strpbrk(const char *token_start, const char *s2) {
    while (*token_start) {
        const char* s = s2;
        while (*s) {
            if (*token_start == *s++) {
                return const_cast<char*>(token_start);
            }
        }
        token_start++;
    }
    return nullptr;
}

void *my_cstring::memset(void *s, int c, size_t n) {
    unsigned char* p = static_cast<unsigned char*>(s);
    while (n--) {
        *p++ = static_cast<unsigned char>(c);
    }
    return s;
}

const char *my_cstring::strerror(int errnum) {
    switch (errnum) {
    case EPERM: return "Operation not permitted";
    case ENOENT: return "No such file or directory";
    default: return "Unknown error";
    }
}

char *my_cstring::strstr(const char *haystack, const char *needle) {
    if (*needle == '\0') {
        return (char *) haystack;
    }

    const char *p1, *p2, *p1_start;

    for (p1 = haystack; *p1 != '\0'; p1++) {
        p1_start = p1;
        p2 = needle;

        while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
            p1++;
            p2++;
        }

        if (*p2 == '\0') {
            return (char *) p1_start;
        }
    }

    return nullptr;
}
