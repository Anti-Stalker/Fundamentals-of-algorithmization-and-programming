#ifndef D2_H
#define D2_H

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


public:
    Node<T>* head;
    Node<T>* tail;
    Deque() : head(nullptr), tail(nullptr) {}

    void push_back(const T& data) {
        Node<T>* newNode = new Node<T>(data);

        if (tail != nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
        } else {
            head = newNode;
        }
        tail = newNode;
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
    }

    T pop_front() {
        if (head == nullptr) {
            throw "Очередь пуста";
        }
        T data = head->data;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        return data;
    }
    T pop_back() {
        if (tail == nullptr) {
            throw "Очередь пуста";
        }
        T data = tail->data;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        return data;
    }
    bool empty() const {
        return head == nullptr;
    }

    void swap(){
        Node <T> *min = head, *max = head;
        if (empty()) return;
        Node <int>* node = head;
        do {
            if (node->data > max->data) max = node;
            if (node->data < min->data) min = node;
            node = node->next;
        } while (node != nullptr);

        T sw = max->data;
        max->data = min->data;
        min->data = sw;
    }
};

#endif // D2_H
