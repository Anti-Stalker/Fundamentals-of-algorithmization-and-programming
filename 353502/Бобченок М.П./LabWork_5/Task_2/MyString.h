//
// Created by u on 29.05.24.
//

#ifndef TASK2_MYSTRING_H
#define TASK2_MYSTRING_H

#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include "Iterator.h"

namespace str {
    class MyString {
    private:
        size_t sz = 0;
        size_t cap = 0;
        unique_ptr<char> s;

    public:

        Iterator<char> begin() {
            return Iterator<char>(s.adr());
        }

        size_t size() const {
            return sz;
        }

        size_t length() const {
            return sz;
        }

        size_t capaity() const {
            return cap;
        }

        char *data() {
            return s.adr();
        }

        void reserve(size_t n) {
            if (n <= cap)
                return;

            unique_ptr<char> tmp(new char[n]);
            std::copy(s.adr(), s.adr() + sz, tmp.adr());
            s = std::move(tmp);
            cap = n;
        }

        void resize(size_t n) {
            if (n > cap)
                reserve(n + 1);

            sz = n;
        }

        void resize(size_t n, char value) {
            reserve(n + 1);
            for (int i = sz; i < n; i++) {
                s[i] = value;
            }
            sz = n;
        }

        void emplace(size_t pos, char c) {
            if (cap == sz)
                reserve(cap + 2);
            for (int i = sz - 1; i >= pos; --i)
                s[i + 1] = s[i];

            s[pos] = c;
            sz++;
        }

        void push_back(char c) {
            emplace(sz, c);
        }

        void push_front(char c) {
            emplace(0, c);
        }

        void insert(size_t pos, char c) {
            emplace(pos, c);
        }

        void insert(size_t pos, const MyString &tmp) {
            int len = tmp.length();
            unique_ptr<char> t(new char[cap + len]);

            for (int i = 0; i < pos; ++i)
                t[i] = s[i];

            for (int i = 0; i < len; ++i)
                t[pos + i] = tmp.s[i];

            for (int i = 0; i < sz - pos; ++i)
                t[pos + len + i] = s[pos + i];

            s = std::move(t);
            sz += len;
        }

        void insert(size_t pos, char *tmp) {
            insert(pos, MyString(tmp));
        }

        void erase(size_t pos) {
            reserve(cap + 1);
            if (pos > sz)
                throw std::runtime_error("out of range");

            for (int i = pos; i < sz; ++i) {
                s[i] = s[i + 1];
            }
            --sz;
        }

        void pop_back() {
            erase(sz - 1);
        }

        void pop_front() {
            erase(0);
        }

        void copy(size_t pos, MyString &to_copy) {
            if (pos >= sz)
                throw std::runtime_error("out of range");

            int tmpLen = sz - pos;
            to_copy.reserve(tmpLen);
            for (int i = 0; i < tmpLen; ++i)
                to_copy.s[i] = s[pos + i];

            to_copy.sz = tmpLen;
        }

        void clear() {
            resize(0);
        }

        char &at(size_t pos) {
            if (pos < sz && pos >= 0)
                return s[pos];

            throw std::runtime_error("out of range");
        }

        int compare(const MyString &a) {
            if (sz != a.length())
                return 0;

            for (int i = 0; i < sz; ++i)
                if (s[i] != a.s[i])
                    return 0;

            return 1;
        }

        int compare(size_t pos, size_t len, const MyString &a) {
            if (pos + len - 1 > sz)
                throw std::runtime_error("out of range");

            if (pos + len - 1 > a.length())
                return 2;

            if (pos + len - 1 < a.length())
                return -2;

            for (int i = 0; i < len; ++i)
                if (s[pos + i] != a.s[i])
                    return 0;

            return 1;
        }

        int compare(size_t pos, size_t len, size_t spos, size_t slen, const MyString &a) {
            if (pos + len - 1 > sz)
                throw std::runtime_error("out of range");

            if (spos + slen - 1 > a.length())
                throw std::runtime_error("out of range");

            size_t tl;
            if (len >= slen)
                tl = len;
            else
                tl = slen;

            for (int i = 0; i < tl; ++i)
                if (s[pos + i] != a.s[spos + i])
                    return 0;

            return 1;
        }

        void swap(MyString &a) {
            s.swap(a.s);
            std::swap(sz, a.sz);
            std::swap(cap, a.cap);
        }

        int find(const MyString &a) {
            if (a.length() > sz)
                throw std::runtime_error("out of range");

            int pos = -1;
            for (int i = 0; i < sz; ++i) {
                if (s[i] != a.s[0])
                    continue;

                pos = i;
                for (int j = 0; j < a.length(); ++j) {
                    if (s[i + j] != a.s[j]) {
                        pos = -1;
                        break;
                    }
                }

                if (pos != -1)
                    return pos;
            }
            return pos;
        }

        int find(char *arr) {
            return find(MyString(arr));
        }

        MyString substr(size_t pos) {
            int len = sz - pos;
            unique_ptr<char> tmp(new char[len]);
            for (int i = 0; i < len; ++i)
                tmp[i] = s[pos + i];

            return MyString(tmp.adr());
        }

        MyString substr(size_t pos, size_t len) {
            if (pos + len >= sz)
                throw std::runtime_error("out of range");

            unique_ptr<char> tmp(new char[len]);
            for (int i = 0; i < len; ++i)
                tmp[i] = s[pos + i];

            return MyString(tmp.adr());
        }

        bool empty() const {
            return (sz == 0);
        }

        MyString &operator+=(const MyString &tmp) {
            unique_ptr<char> temp(new char[sz + tmp.sz]);
            for (int i = 0; i < sz; ++i) {
                temp[i] = s[i];
            }
            int j = 0;
            for (int i = sz; i < sz + tmp.sz; ++i) {
                temp[i] = tmp.s[j];
                j++;
            }
            sz += tmp.sz;

            cap = sz;
            temp[sz] = '\0';
            s.reset(temp.release());
            return *this;
        }

        MyString &operator=(const MyString &tmp) {
            cap = sz = tmp.sz;
            s.reset(new char[sz]);
            for (int i = 0; i < sz; ++i)
                s[i] = tmp.s[i];

            s[sz] = '\0';
            return *this;
        }

        MyString &operator=(const char *str) {
            cap = sz = std::strlen(str);
            s.reset(new char[sz]);
            for (int i = 0; i < sz; ++i)
                s[i] = str[i];

            s[sz] = '\0';
            return *this;
        }

        MyString operator+(const MyString &tmp) {
            return *this += tmp;
        }

        const char &operator[](size_t index) {
            if (index >= sz)
                throw std::runtime_error("out of range");

            return s[index];
        }

        MyString() = default;

        MyString(const MyString &tmp) {
            s.reset(new char[tmp.sz]);
            sz = tmp.sz;
            cap = tmp.cap;
            for (int i = 0; i < sz; i++)
                s[i] = tmp.s[i];

            s[sz] = '\0';
        }

        MyString(const std::string &str) {
            this->s.reset(new char[str.length()]);
            cap = sz = str.length();
            for (int i = 0; i < sz; ++i)
                s[i] = str[i];

            s[sz] = '\0';
        }

        MyString(const char *tmp) {
            cap = sz = std::strlen(tmp);
            s.reset(new char[sz]);
            for (int i = 0; i < sz; ++i)
                s[i] = tmp[i];

            s[sz] = '\0';
        }

        ~MyString() = default;

        friend std::ostream &operator<<(std::ostream &out, const MyString &s);
    };

    std::ostream &operator<<(std::ostream &out, const MyString &st) {
        for (int i = 0; i < st.length(); i++)
            std::cout << st.s[i];
        return out;
    }

    size_t mstrlen(const char *s) {
        unique_ptr<const char> t(s);
        size_t i = 0;
        for (; t[i] != '\0'; ++i);
        t.release();
        return i;
    }

    char *mstrcpy(char *dest, const char *src) {
        int ldest = mstrlen(dest);
        int lsrc = mstrlen(src);
        if (ldest < lsrc)
            throw std::runtime_error("out of range");

        unique_ptr<char> d(dest);
        unique_ptr<const char> f(src);

        for (int i = 0; i < lsrc; ++i)
            d[i] = f[i];

        d[lsrc] = '\0';
        f.release();
        return d.release();
    }

    char *mstrncpy(char *dest, const char *src, size_t n) {
        int ldest = mstrlen(dest);
        if (ldest < n)
            throw std::runtime_error("out of range");

        unique_ptr<char> d(dest);
        unique_ptr<const char> f(src);
        for (int i = 0; i < n; ++i)
            d[i] = f[i];

        d[n] = '\0';
        f.release();
        return d.release();
    }

    void *mmemcpy(void *dest, const void *src, size_t n) {
        int sdest = mstrlen(reinterpret_cast<char *>(dest));
        if (sdest < n)
            throw std::runtime_error("out of range");

        unique_ptr<char> d(reinterpret_cast<char *>(dest));
        unique_ptr<const char> f(reinterpret_cast<const char *>(src));
        std::uninitialized_copy(f.adr(), f.adr() + n, d.adr());
        d[n] = '\0';
        f.release();
        return d.release();
    }

    void *mmemmove(void *dest, const void *src, size_t n) {
        int sdest = mstrlen(reinterpret_cast<char *>(dest));
        if (sdest < n)
            throw std::runtime_error("out of range");

        unique_ptr<char> d(reinterpret_cast<char *>(dest));
        unique_ptr<const char> f(reinterpret_cast<const char *>(src));
        std::uninitialized_move(f.adr(), f.adr() + n, d.adr());
        d[n] = '\0';
        f.release();
        return d.release();
    }

    char *mstrcat(char *dest, const char *src) {
        if (mstrlen(dest) < mstrlen(src))
            throw std::runtime_error("out of range");

        int destlen = mstrlen(dest);
        unique_ptr<char> d(dest);
        unique_ptr<const char> f(src);
        strcpy(d.adr() + destlen, f.adr());
        f.release();
        return d.release();
    }

    char *mstrncat(char *dest, const char *src, size_t n) {
        if (mstrlen(dest) < n)
            throw std::runtime_error("out of range");

        unique_ptr<char> d(dest);
        unique_ptr<const char> f(src);
        mstrcpy(d.adr() + n, f.adr());
        f.release();
        return d.release();
    }

    int mmemcmp(const void *dest, const void *src, size_t n) {
        if (n > mstrlen(reinterpret_cast<const char *>(dest))) {
            throw std::runtime_error("out of range");
        }
        unique_ptr<const char> d(reinterpret_cast<const char *>(dest));
        unique_ptr<const char> f(reinterpret_cast<const char *>(src));
        for (int i = 0; i < n; ++i) {
            if (d[i] != f[i]) {
                char a = f[i];
                char b = d[i];
                d.release();
                f.release();
                return a - b;
            }
        }
        f.release();
        d.release();
        return 0;
    }

    int mstrcmp(const char *dest, const char *src) {
        if (mstrlen(dest) < mstrlen(src))
            throw std::runtime_error("out of range");

        unique_ptr<const char> d(dest);
        unique_ptr<const char> f(src);
        int l = strlen(d.adr());
        for (int i = 0; i < l; ++i)
            if (d[i] != f[i]) {
                char a = f[i];
                char b = d[i];
                d.release();
                f.release();
                return a - b;
            }

        d.release();
        f.release();
        return 0;
    }

    int mstrncmp(const char *dest, const char *src, size_t n) {
        if (mstrlen(dest) < n)
            throw std::runtime_error("out of range");

        unique_ptr<const char> d(dest);
        unique_ptr<const char> f(src);
        for (int i = 0; i < n; ++i)
            if (d[i] != f[i]) {
                char a = f[i];
                char b = d[i];
                d.release();
                f.release();
                return a - b;
            }

        d.release();
        f.release();
        return 0;
    }

    char *mstrtok(char *str, const char *delim) {
        unique_ptr<char> ptr;
        if (str != nullptr) {
            ptr = make_unique<char>(strlen(str) + 1);
            mstrcpy(ptr.adr(), str);
        }

        if (ptr.adr() == nullptr || ptr[0] == '\0')
            return nullptr;

        const char *token_start = ptr.adr();
        const char *token_end = strpbrk(token_start, delim);
        if (token_end != nullptr) {
            ptr[token_end - token_start] = '\0';
            ptr = make_unique<char>(strlen(token_end + 1) + 1);
            mstrcpy(ptr.adr(), token_end + 1);
        }

        ptr.release();
        return const_cast<char *>(token_start);
    }

    void *mmemset(void *ptr, int value, size_t num) {
        unique_ptr<char> p(static_cast<char *>(ptr));
        for (int i = 0; i < num; ++i)
            p[i] = static_cast<char>(value);

        return static_cast<void *>(p.release());
    }

    char *mstrerror(int errnum) {
        switch (errnum) {
            case 0: {
                char *c = "out of range";
                unique_ptr<char> er0(c);
                return er0.release();
            }
            case 1: {
                char *c = "memory limit";
                unique_ptr<char> er1(c);
                return er1.release();
            }
            case 2: {
                char *c = "stack overflow";
                unique_ptr<char> er3(c);
                return er3.release();
            }
            case 3: {
                char *c = "heap overflow";
                unique_ptr<char> er4(c);
                return er4.release();
            }
            case 4: {
                char *c = "iq overflow";
                unique_ptr<char> er5(c);
                return er5.release();
            }
            default: {
                char *c = "unknown error";
                unique_ptr<char> erdef(c);
                return erdef.release();
            }
        }
    }
}
#endif //TASK2_MYSTRING_H
