#include "Deque.h"

Deque::Deque() : first(nullptr), last(nullptr), _size(0) {}

Deque::Iterator::Iterator(Node* node, int index) : currentNode(node), currentIndex(index) {}

int Deque::back() const {
    if (!last || last->count == 0) {
        throw std::out_of_range("Deque is empty");
    }
    return last->elements[last->count - 1];
}

int Deque::front() const {
    if (!first || first->count == 0) {
        throw std::out_of_range("Deque is empty");
    }
    return first->elements[0];
}

void Deque::delFirst() {
    if (first) {
        Node* tmp = first;
        first = first->next;
        if (first) {
            first->previous = nullptr;
        } else {
            last = nullptr;
        }
        delete tmp;
    }
}

void Deque::delLast() {
    if (last) {
        Node* tmp = last;
        last = last->previous;
        if (last) {
            last->next = nullptr;
        } else {
            first = nullptr;
        }
        delete tmp;
    }
}

void Deque::setFirst(Node* tmp) {
    first = tmp;
}

void Deque::setLast(Node* tmp) {
    last = tmp;
}

void Deque::pop_front() {
    if (_size == 0) {
        throw std::out_of_range("Deque is empty");
    }
    for (int i = 0; i < first->count - 1; ++i) {
        first->elements[i] = first->elements[i + 1];
    }
    first->count--;
    if (first->count == 0) {
        delFirst();
    }
    --_size;
}

void Deque::push_back(int element) {
    if (!last || last->count == NODE_CAPACITY) {
        Node* tmp = new Node();
        if (last) {
            last->next = tmp;
            tmp->previous = last;
        }
        setLast(tmp);
        if (!first) {
            setFirst(tmp);
        }
    }
    last->elements[last->count++] = element;
    ++_size;
}
void Deque::pop_back() {
    if (_size == 0) {
        throw std::out_of_range("Deque is empty");
    }
    last->count--;
    if (last->count == 0) {
        delLast();
    }
    --_size;
}

void Deque::push_front(int element) {
    if (!first || first->count == NODE_CAPACITY) {
        Node* tmp = new Node();
        if (first) {
            first->previous = tmp;
            tmp->next = first;
        }
        setFirst(tmp);
        if (!last) {
            setLast(tmp);
        }
    }
    for (int i = first->count; i > 0; --i) {
        first->elements[i] = first->elements[i - 1];
    }
    first->elements[0] = element;
    first->count++;
    ++_size;
}

int Deque::size() const {
    return _size;
}


bool Deque::empty() const {
    return _size == 0;
}

void Deque::clear() {
    while (first) {
        delFirst();
    }
    _size = 0;
}


int Deque::Iterator::operator*() const {
    return currentNode->elements[currentIndex];
}

Deque::Iterator& Deque::Iterator::operator++() {
    if (++currentIndex == currentNode->count) {
        currentNode = currentNode->next;
        currentIndex = 0;
    }
    return *this;
}

bool Deque::Iterator::operator!=(const Iterator& other) const {
    return currentNode != other.currentNode || currentIndex != other.currentIndex;
}

Deque::Iterator Deque::begin() const {
    return Iterator(first, 0);
}

Deque::Iterator Deque::end() const {
    return Iterator(nullptr, 0);
}

