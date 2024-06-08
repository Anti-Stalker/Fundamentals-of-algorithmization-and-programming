#include "Deque.h"

Deque* Deque::first = nullptr;
Deque* Deque::last = nullptr;
int Deque::_size = 0;

Deque::Deque(int element) : _element(element), previous(nullptr), next(nullptr) {}

Deque::Deque() = default;

int Deque::back() const {
    return last ? last->_element : throw std::out_of_range("Deque is empty");
}

int Deque::front() const {
    return first ? first->_element : throw std::out_of_range("Deque is empty");
}

void Deque::delFirst() {
    if (first) {
        Deque* tmp = first;
        first = first->next;
        if (first) {
            first->previous = nullptr;
        } else {
            last = nullptr; // List is now empty
        }
        delete tmp;
    }
}

void Deque::setFirst(Deque* tmp) {
    first = tmp;
}

void Deque::setLast(Deque* tmp) {
    last = tmp;
}

void Deque::pop() {
    if (_size != 0) {
        delFirst();
        --_size;
    }
}

void Deque::push(int element) {
    Deque* tmp = new Deque(element);
    if (_size) {
        tmp->previous = last;
        if (last) {
            last->next = tmp;
        }
        setLast(tmp);
    } else {
        setFirst(tmp);
        setLast(tmp);
    }
    ++_size;
}

int Deque::size() {
    return _size;
}
