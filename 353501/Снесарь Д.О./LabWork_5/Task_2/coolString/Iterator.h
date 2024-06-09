#ifndef ITERATOR_H
#define ITERATOR_H

class Iterator {
private:
    char* it;

public:
    Iterator(char* ptr) : it(ptr) {}

    Iterator& operator++() {
        ++it;
        return *this;
    }

    Iterator operator++(int) {
        Iterator temp = *this;
        ++it;
        return temp;
    }

    Iterator& operator--() {
        --it;
        return *this;
    }

    Iterator operator--(int) {
        Iterator temp = *this;
        --it;
        return temp;
    }

    char& operator*() const {
        return *it;
    }

    bool operator==(const Iterator& other) const {
        return it == other.it;
    }

    bool operator!=(const Iterator& other) const {
        return it != other.it;
    }

    Iterator& operator+=(int n) {
        it += n;
        return *this;
    }

    Iterator operator+(int n) const {
        return Iterator(it + n);
    }

    Iterator& operator-=(int n) {
        it -= n;
        return *this;
    }

    Iterator operator-(int n) const {
        return Iterator(it - n);
    }

    int operator-(const Iterator& other) const {
        return static_cast<int>(it - other.it);
    }

    char& operator[](int n) const {
        return it[n];
    }
};
#endif // ITERATOR_H
