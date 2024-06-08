#ifndef LAB7TASK1_DEQUE_H
#define LAB7TASK1_DEQUE_H

#include <stdexcept>

class Deque {
protected:
    Deque(int element);

    Deque* previous;
    Deque* next;

    static Deque* first;
    static Deque* last;

    int _element;
    static int _size;

    static void delFirst();
    static void setFirst(Deque* tmp);
    static void setLast(Deque* tmp);

public:
    Deque();

    [[nodiscard]] int back() const;
    [[nodiscard]] int front() const;

    int size();

    void pop();
    void push(int element);
};

#endif //LAB7TASK1_DEQUE_H
