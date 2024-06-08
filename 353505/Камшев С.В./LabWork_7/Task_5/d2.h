#ifndef D2_H
#define D2_H
#include <stdexcept>

template <typename T>
    struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
};

template <typename T>
class Deque {
private:
    size_t size_;

public:
    Node<T>* head;
    Node<T>* tail;

    Deque() : head(nullptr), tail(nullptr), size_(0) {}

    bool empty() const {
        return head == nullptr;
    }

    // Методы для добавления элементов
    void push_back(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (tail != nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
        } else {
            head = newNode;
        }
        tail = newNode;
        ++size_;
    }

    void push_front(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (head != nullptr) {
            head->prev = newNode;
            newNode->next = head;
        } else {
            tail = newNode;
        }
        head = newNode;
        ++size_;
    }

    // Методы для извлечения элементов
    T pop_front() {
        if (head == nullptr) {
            throw std::runtime_error("Очередь пуста");
        }
        T data = head->data;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        --size_;
        return data;
    }

    T pop_back() {
        if (tail == nullptr) {
            throw std::runtime_error("Очередь пуста");
        }
        T data = tail->data;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        --size_;
        return data;
    }

    // Методы для доступа к элементам
    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Индекс вне диапазона");
        }
        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    const T& operator[](size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Индекс вне диапазона");
        }
        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Метод для получения размера
    size_t size() const {
        return size_;
    }

    // Метод для очистки очереди
    void clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size_ = 0;
    }

    // Метод для изменения размера
    void resize(size_t newSize) {
        if (newSize < size_) {
            // Удаление элементов
            while (size_ > newSize) {
                pop_back();
            }
        } else if (newSize > size_) {
            // Добавление элементов
            for (size_t i = size_; i < newSize; ++i) {
                push_back(T()); // Добавление по умолчанию
            }
        }
    }

    // Итератор с произвольным доступом
    class RandomAccessIterator {
    private:
        Node<T>* current;

    public:
        RandomAccessIterator(Node<T>* node) : current(node) {}

        T& operator*() {
            return current->data;
        }

        const T& operator*() const {
            return current->data;
        }

        RandomAccessIterator& operator++() {
            current = current->next;
            return *this;
        }

        RandomAccessIterator operator++(int) {
            RandomAccessIterator temp(*this);
            current = current->next;
            return temp;
        }

        RandomAccessIterator& operator--() {
            current = current->prev;
            return *this;
        }

        RandomAccessIterator operator--(int) {
            RandomAccessIterator temp(*this);
            current = current->prev;
            return temp;
        }

        RandomAccessIterator& operator+=(size_t offset) {
            if (offset == 0) {
                return *this;
            }
            if (offset > 0) {
                for (size_t i = 0; i < offset; ++i) {
                    current = current->next;
                }
            } else {
                for (size_t i = 0; i > offset; --i) {
                    current = current->prev;
                }
            }
            return *this;
        }

        RandomAccessIterator operator+(size_t offset) const {
            RandomAccessIterator temp(*this);
            return temp += offset;
        }

        RandomAccessIterator& operator-=(size_t offset) {
            return *this += -offset;
        }

        RandomAccessIterator operator-(size_t offset) const {
            RandomAccessIterator temp(*this);
            return temp -= offset;
        }

        bool operator==(const RandomAccessIterator& other) const {
            return current == other.current;
        }

        bool operator!=(const RandomAccessIterator& other) const {
            return current != other.current;
        }

        T& operator[](size_t offset) {
            return *(this + offset);
        }

        const T& operator[](size_t offset) const {
            return *(this + offset);
        }

    };

    // Методы для получения итераторов
    RandomAccessIterator begin() {
        return RandomAccessIterator(head);
    }

    RandomAccessIterator end() {
        return RandomAccessIterator(nullptr);
    }

    RandomAccessIterator cbegin() const {
        return RandomAccessIterator(head);
    }

    RandomAccessIterator cend() const {
        return RandomAccessIterator(nullptr);
    }
};

#endif // D2_H
