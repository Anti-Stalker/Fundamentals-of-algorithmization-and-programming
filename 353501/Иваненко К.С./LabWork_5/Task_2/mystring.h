#pragma once

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <memory>
#include <string>
#include <cstring>

template <class T>
class Iterator
{
public:
    T *const_it = nullptr;
    T *def_it = nullptr;

    void adr(T *arr)
    {
        def_it = arr;
    }

    Iterator() = default;

    Iterator(const Iterator<T> &tmp) : def_it(tmp.def_it) {}

    explicit Iterator(T *a) : def_it(a) {}

    bool operator==(const Iterator<T> &tmp)
    {
        return def_it == tmp.def_it;
    }

    Iterator<T> operator++()
    {
        if (const_it != nullptr)
        {
            return Iterator<T>(const_it);
        }
        return Iterator<T>(def_it++);
    };

    T &operator*()
    {
        if (const_it != nullptr)
        {
            re();
        }
        return *def_it;
    }

    int operator-(T *tmp)
    {
        return this->def_it - tmp;
    }

    int operator-(Iterator<T> tmp)
    {
        return this->def_it - tmp.def_it;
    }

    Iterator<T> operator-(const int &tmp)
    {
        this->def_it -= tmp;
        return *this;
    }

    int operator+(T *tmp)
    {
        return this->def_it + tmp;
    }

    Iterator<T> operator+(const int &tmp)
    {
        this->def_it += tmp;
        return *this;
    }

    T re()
    {
        return *const_it;
    }
};

template <class T>
class unique_ptr
{
    T *ptr = nullptr;

public:
    unique_ptr() = default;

    unique_ptr(const unique_ptr<T> &tmp) = delete;

    unique_ptr(unique_ptr<T> &&uptr) noexcept : ptr(uptr.release()) {}

    explicit unique_ptr(T *tmp) : ptr(tmp)
    {
    }

    ~unique_ptr()
    {
        delete ptr;
    }

    unique_ptr<T> &operator=(const unique_ptr<T> &tmp) = delete;

    unique_ptr<T> &operator=(unique_ptr<T> &&tmp) noexcept
    {
        reset(tmp.release());
        return *this;
    }

public:
    void swap(unique_ptr<T> &other) noexcept
    {
        std::swap(ptr, other.ptr);
    }

    T *get() const
    {
        return ptr;
    }

    T *gget()
    {
        return ptr;
    }

    T &operator*()
    {
        return *ptr;
    }

    T *release()
    {
        T *tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    void reset(T *tmp = nullptr)
    {
        if (tmp != ptr)
        {
            delete ptr;
            ptr = tmp;
        }
    }

    T &operator[](size_t index) const
    {
        return *(ptr + index);
    }
};

template <class T, class... Args>
unique_ptr<T> make_unique(Args &&...args)
{
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

class string
{
    size_t len = 0;
    unique_ptr<char> s;
    size_t cap = 1;

public:
    ~string()
    {
        s.release();
        len = 0;
        cap = 1;
    }

    Iterator<char> begin()
    {
        return Iterator<char>(this->s.gget());
    }

    string() = default;

    string(const string &tmp)
    {
        this->s.reset(new char[tmp.len]);
        this->len = tmp.len;
        cap = tmp.cap;
        for (int i = 0; i < len; i++)
        {
            s[i] = tmp.s[i];
        }
        s[len] = '\0';
    }
    
    string(const std::string &str)
    {
        this->s.reset(new char[str.length()]);
        len = str.length();
        cap = len;
        for (int i = 0; i < len; ++i)
        {

            s[i] = str[i];
        }
        s[len] = '\0';
    }

    string(const char *tmp)
    {
        this->len = std::strlen(tmp);
        cap = len;
        s.reset(new char[len]);
        for (int i = 0; i < len; ++i)
        {
            s[i] = tmp[i];
        }
        s[len] = '\0';
    }

    size_t length() const
    {
        return len;
    }

    string &operator+=(const string &tmp)
    {
        unique_ptr<char> temp(new char[this->len + tmp.length()]);
        for (int i = 0; i < this->len; ++i)
        {
            temp[i] = this->s[i];
        }
        int j = 0;
        for (int i = this->len; i < this->len + tmp.len; ++i)
        {
            temp[i] = tmp.s[j];
            j++;
        }
        len += tmp.len;

        cap = len;
        temp[len] = '\0';
        this->s.reset(temp.release());
        return *this;
    }

    string &operator=(const string &tmp)
    {
        this->len = tmp.len;
        cap = len;
        this->s.reset(new char[len]);
        for (int i = 0; i < len; ++i)
        {
            s[i] = tmp.s[i];
        }
        s[len] = '\0';
        return *this;
    }

    string &operator=(const char *str)
    {
        this->len = std::strlen(str);
        cap = len;
        this->s.reset(new char[len]);
        for (int i = 0; i < len; ++i)
        {
            s[i] = str[i];
        }
        s[len] = '\0';
        return *this;
    }

    string operator+(const string &tmp)
    {
        string n = *this;
        return n += tmp;
    }

    const char &operator[](size_t index)
    {
        if (index > len - 1)
        {
            throw std::runtime_error("out of range");
        }
        return s[index];
    }

    void reserve(size_t n)
    {
        if (n < cap)
        {
            return;
        }
        unique_ptr<char> tmp(new char[n]);
        std::copy(s.get(), s.get() + len, tmp.get());
        s = std::move(tmp);
        cap = n;
    }

    void resize(size_t n)
    {
        if (n > cap)
        {
            reserve(n + 1);
        }
        len = n;
    }

    void resize(size_t n, char to)
    {
        std::cout << to << "\n";
        reserve(n + 1);
        for (int i = len; i < n; i++)
        {
            this->s[i] = to;
            std::cout << this->s[i] << "\n";
        }
        len = n;
    }

    void emplace(size_t index, char c)
    {
        if (cap == len)
        {
            reserve(cap + 2);
        }
        for (int i = len - 1; i >= index; --i)
        {
            s[i + 1] = s[i];
        }
        s[index] = c;
        len++;
    }

    void push_back(char c)
    {
        emplace(len, c);
    }

    void push_front(char c)
    {
        emplace(0, c);
    }

    void insert(size_t index, char c)
    {
        emplace(index, c);
    }

    void insert(size_t pos, const string &tmp)
    {
        int tl = tmp.length();
        unique_ptr<char> t(new char[cap + tl]);
        for (int i = 0; i < pos; ++i)
        {
            t[i] = s[i];
        }
        for (int i = 0; i < tl; ++i)
        {
            t[pos + i] = tmp.s[i];
        }
        for (int i = 0; i < len - pos; ++i)
        {
            t[pos + tl + i] = s[pos + i];
        }
        s = std::move(t);
        len += tl;
    }

    void insert(size_t pos, char *tmp)
    {
        insert(pos, string(tmp));
    }

    size_t size() const
    {
        return len;
    }

    size_t capacity()
    {
        return cap;
    }

    char *data()
    {
        return s.get();
    }

    void erase(size_t index)
    {
        reserve(cap + 1);
        if (index > len)
        {
            throw std::runtime_error("out of range");
            return;
        }
        for (int i = index; i < len; ++i)
        {
            s[i] = s[i + 1];
        }
        --len;
    }

    void pop_back()
    {
        erase(len - 1);
    }

    void pop_front()
    {
        erase(0);
    }

    void reverse_copy(size_t pos, const string &to_copy)
    {
        int tmplen = to_copy.length();
        reserve(cap + tmplen);
        int j = 0;
        for (int i = pos; i < len; ++i)
        {
            s[len + j] = s[i];
            ++j;
        }
        for (int i = 0; i < tmplen; ++i)
        {
            s[pos + i] = to_copy.s[i];
        }
        len += tmplen;
    }

    void copy(size_t pos, string &to_copy)
    {
        if (pos >= len)
        {
            throw std::runtime_error("out of range");
        }
        int templen = len - pos;
        to_copy.reserve(templen);
        for (int i = 0; i < templen; ++i)
        {
            to_copy.s[i] = s[pos + i];
        }
        to_copy.len = templen;
    }

    void clear()
    {
        resize(0);
    }

    char &at(size_t pos)
    {
        return s[pos];
    }

    int compare(const string &to_compare)
    {
        if (len != to_compare.length())
        {
            return 0;
        }
        for (int i = 0; i < len; ++i)
        {
            if (s[i] != to_compare.s[i])
            {
                return 0;
            }
        }
        return 1;
    }

    int compare(size_t pos, size_t l, const string &to_compare)
    {
        if (pos + l - 1 > len)
        {
            throw std::runtime_error("out of range");
        }
        if (pos + l - 1 > to_compare.length())
        {
            return 2;
        }
        if (pos + l - 1 < to_compare.length())
        {
            return -2;
        }
        for (int i = 0; i < l; ++i)
        {
            if (s[pos + i] != to_compare.s[i])
            {
                return 0;
            }
        }
        return 1;
    }

    int compare(size_t pos, size_t l, size_t spos, size_t sl, const string &to_compare)
    {
        if (pos + l - 1 > len)
        {
            throw std::runtime_error("out of range");
        }
        if (spos + sl - 1 > to_compare.length())
        {
            throw std::runtime_error("out of range");
        }
        size_t tl;
        if (l >= sl)
        {
            tl = l;
        }
        else
        {
            tl = sl;
        }
        for (int i = 0; i < tl; ++i)
        {
            if (s[pos + i] != to_compare.s[spos + i])
            {
                return 0;
            }
        }
        return 1;
    }

    void swap(string &to_swap)
    {
        this->s.swap(to_swap.s);
        std::swap(len, to_swap.len);
        std::swap(cap, to_swap.cap);
    }

    int find(const string &from_find)
    {
        if (from_find.length() > this->length())
        {
            throw std::runtime_error("out of range");
        }
        int pos = -1;
        for (int i = 0; i < len; ++i)
        {
            if (s[i] != from_find.s[0])
            {
                continue;
            }
            for (int j = 0; j < from_find.length(); ++j)
            {
                if (s[i + j] != from_find.s[j])
                {
                    pos = -1;
                    break;
                }
                pos = i;
                return pos;
            }
        }
        return pos;
    }

    int find(char *arr)
    {
        return find(string(arr));
    }

    string substr(size_t pos)
    {
        int tl = len - pos;
        unique_ptr<char> tmp(new char[tl]);
        for (int i = 0; i < tl; ++i)
        {
            tmp[i] = s[pos + i];
        }
        return string(tmp.get());
    }

    string substr(size_t pos, size_t l)
    {
        unique_ptr<char> tmp(new char[l]);
        for (int i = 0; i < l; ++i)
        {
            tmp[i] = s[pos + i];
        }
        return string(tmp.get());
    }

    bool empty() const
    {
        return !len;
    }

    friend std::ostream &operator<<(std::ostream &out, const string &s);
};

std::ostream &operator<<(std::ostream &out, const string &st)
{
    for (int i = 0; i < st.length(); i++)
        std::cout << st.s[i];
    return out;
}

size_t mstrlen(const char *s)
{
    unique_ptr<const char> t(s);
    int i = 0;
    for (; t[i] != '\0'; ++i)
        ;
    t.release();
    return static_cast<size_t>(i);
}

char *mstrcpy(char *dest, const char *src)
{
    int ldest = mstrlen(dest);
    int lsrc = mstrlen(src);
    if (ldest < lsrc)
    {
        throw std::runtime_error("out of range");
    }
    unique_ptr<char> d(dest);
    unique_ptr<const char> f(src);
    if (ldest < lsrc)
    {
        throw std::runtime_error("not enough space");
    }
    for (int i = 0; i < lsrc; ++i)
    {
        d[i] = f[i];
    }
    d[lsrc] = '\0';
    f.release();
    return d.release();
}

char *mstrncpy(char *s1, const char *s2, size_t n)
{
    int ldest = mstrlen(s1);
    if (ldest < n)
    {
        throw std::runtime_error("out of range");
    }
    unique_ptr<char> d(s1);
    unique_ptr<const char> f(s2);
    for (int i = 0; i < n; ++i)
    {
        d[i] = f[i];
    }
    d[n] = '\0';
    f.release();
    return d.release();
}

void *mmemcpy(void *s1, const void *s2, size_t n)
{
    int sdest = mstrlen(reinterpret_cast<char *>(s1));
    if (sdest < n)
    {
        throw std::runtime_error("out of range");
    }
    unique_ptr<char> dest(reinterpret_cast<char *>(s1));
    unique_ptr<const char> from(reinterpret_cast<const char *>(s2));
    std::uninitialized_copy(from.get(), from.get() + n, dest.get());
    dest[n] = '\0';
    from.release();
    return dest.release();
}

void *mmemmove(void *s1, const void *s2, size_t n)
{
    int sdest = mstrlen(reinterpret_cast<char *>(s1));
    if (sdest < n)
    {
        throw std::runtime_error("out of range");
    }
    unique_ptr<char> dest(reinterpret_cast<char *>(s1));
    unique_ptr<const char> from(reinterpret_cast<const char *>(s2));
    std::uninitialized_move(from.get(), from.get() + n, dest.get());
    dest[n] = '\0';
    from.release();
    return dest.release();
}

char *mstrcat(char *s1, const char *s2)
{
    if (mstrlen(s1) < mstrlen(s2))
    {
        throw std::runtime_error("out of range");
    }
    int destlen = mstrlen(s1);
    unique_ptr<char> dest(s1);
    unique_ptr<const char> from(s2);
    strcpy(dest.get() + destlen, from.get());
    from.release();
    return dest.release();
}

char *mstrncat(char *s1, const char *s2, size_t n)
{
    if (mstrlen(s1) < n)
    {
        throw std::runtime_error("out of range");
    }
    unique_ptr<char> dest(s1);
    unique_ptr<const char> from(s2);
    strcpy(dest.get() + n, from.get());
    from.release();
    return dest.release();
}

int mmemcmp(const void *s1, const void *s2, size_t n)
{
    if (n > mstrlen(reinterpret_cast<const char *>(s1)))
    {
        throw std::runtime_error("out of range");
    }
    unique_ptr<const char> d(reinterpret_cast<const char *>(s1));
    unique_ptr<const char> f(reinterpret_cast<const char *>(s2));
    for (int i = 0; i < n; ++i)
    {
        if (d[i] != f[i])
        {
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

int mstrcmp(const char *s1, const char *s2)
{
    if (mstrlen(s1) < mstrlen(s2))
    {
        throw std::runtime_error("");
    }
    unique_ptr<const char> d(s1);
    unique_ptr<const char> f(s2);
    int l = strlen(d.get());
    for (int i = 0; i < l; ++i)
    {
        if (d[i] != f[i])
        {
            char a = f[i];
            char b = d[i];
            d.release();
            f.release();
            return a - b;
        }
    }
    d.release();
    f.release();
    return 0;
}

int mstrncmp(const char *s1, const char *s2, size_t n)
{
    if (mstrlen(s1) < n)
    {
        throw std::runtime_error("out ofrange");
    }
    unique_ptr<const char> d(s1);
    unique_ptr<const char> f(s2);
    for (int i = 0; i < n; ++i)
    {
        if (d[i] != f[i])
        {
            char a = f[i];
            char b = d[i];
            d.release();
            f.release();
            return a - b;
        }
    }
    d.release();
    f.release();
    return 0;
}

char *mstrtok(char *str, const char *delim)
{
    unique_ptr<char> ptr;
    if (str != nullptr)
    {
        ptr = make_unique<char>(strlen(str) + 1);
        strcpy(ptr.get(), str);
    }
    if (ptr.get() == nullptr || ptr[0] == '\0')
    {
        return nullptr;
    }
    const char *token_start = ptr.get();
    const char *token_end = strpbrk(token_start, delim);
    if (token_end != nullptr)
    {
        ptr[token_end - token_start] = '\0';
        ptr = make_unique<char>(strlen(token_end + 1) + 1);
        strcpy(ptr.get(), token_end + 1);
    }
    else
    {
        ptr.release();
    }
    ptr.release();
    return const_cast<char *>(token_start);
}

void *mmemset(void *s, int c, size_t n)
{
    unique_ptr<char> ptr(static_cast<char *>(s));
    for (int i = 0; i < n; ++i)
    {
        ptr[i] = static_cast<char>(c);
    }
    return static_cast<void *>(ptr.release());
}

char *mstrerror(int errnum)
{
    switch (errnum)
    {
    case 0:
    {
        unique_ptr<char> er0("out of range");
        return er0.release();
    }
    case 1:
    {
        unique_ptr<char> er1("memory limit");
        return er1.release();
    }
    case 2:
    {
        unique_ptr<char> er3("stack overflow");
        return er3.release();
    }
    case 3:
    {
        unique_ptr<char> er4("heap overflow");
        return er4.release();
    }
    case 4:
    {
        unique_ptr<char> er5("iq overflow");
        return er5.release();
    }
    default:
    {
        unique_ptr<char> erdef("unknown error");
        return erdef.release();
    }
    }
}

#endif // MYSTRING_H