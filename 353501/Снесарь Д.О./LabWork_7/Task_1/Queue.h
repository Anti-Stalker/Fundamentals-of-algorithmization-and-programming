#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>
#include <sstream>

template <typename T>
class Deque {
public:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T data) : data(data), next(nullptr), prev(nullptr) {}
        Node(T data, Node* n, Node* p) : data(data), next(n), prev(p) {}
    };
    Node* head;
    Node* tail;
    int size;


    Deque() : head(nullptr), tail(nullptr), size(0) {}

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void pushFront(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void pushBack(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    T popFront() {
        if (isEmpty()) {
            throw std::runtime_error("Deque is empty");
        }
        T data = head->data;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
        return data;
    }

    T popBack() {
        if (isEmpty()) {
            throw std::runtime_error("Deque is empty");
        }
        T data = tail->data;
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
        return data;
    }

    ~Deque() {
        while (!isEmpty()) {
            popFront();
        }
    }

    int Size(){return size;}
    void popFromBackToBackQ(Deque<T>& dq)
    {
        if (isEmpty()) {
            throw std::runtime_error("Deque is empty");
        }

        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        if (dq.isEmpty()) {
            dq.head = dq.tail = temp;
        } else {
            dq.tail->next = temp;
            temp->prev = dq.tail;
        }
        dq.tail = temp;
        temp->next = nullptr;

        dq.size++;
        size--;
    }

    std::string toString() const {
        std::stringstream ss;
        Node* current = head;
        while (current != nullptr) {
            ss << current->data << " ";
            current = current->next;
        }
        return ss.str();
    }

    void clear() {

        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }


        head = tail = nullptr;

        size = 0;
    }


};


#endif // QUEUE_H
