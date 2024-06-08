#ifndef QUEUE_H
#define QUEUE_H

#include <QString>
#include <QTextStream>
template <typename T>
class Queue {
private:
    struct Node {
        T value;
        Node* next;
        Node(const T& val, Node* n = nullptr) : value(val), next(n) {}
    };

    Node* head;
    Node* tail;
    int size_queue;

public:
    Queue() : head(nullptr), tail(nullptr), size_queue(0) {}
    ~Queue() {
        while (!empty()) {
            dequeue();
        }
    }

    void enqueue(const T& val) {
        Node* newNode = new Node(val);
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size_queue++;
    }

    void dequeue() {
        if (empty()) {
            throw std::runtime_error("Queue is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size_queue--;
    }

    void insert(const T& val, int pos) {
        if (pos < 0 || pos > size_queue) {
            throw std::out_of_range("Invalid position");
        }
        if (pos == 0) {
            Node* newNode = new Node(val, head);
            head = newNode;
            if (!tail) {
                tail = newNode;
            }
        } else {
            Node* curr = head;
            for (int i = 0; i < pos - 1; i++) {
                curr = curr->next;
            }
            Node* newNode = new Node(val, curr->next);
            curr->next = newNode;
            if (pos == size_queue) {
                tail = newNode;
            }
        }
        size_queue++;
    }

    void reorder(int start, int end, int newPos) {
        if (start < 0 || end >= size_queue || newPos < 0 || newPos > size_queue) {
            throw std::out_of_range("Invalid range or position");
        }

        Node* curr = head;
        Node* startNode = nullptr, *endNode = nullptr, *newPosNode = nullptr;
        int i = 0;
        while (curr) {
            if (i == start) {
                startNode = curr;
            }
            if (i == end) {
                endNode = curr;
            }
            if (i == newPos) {
                newPosNode = curr;
            }
            curr = curr->next;
            i++;
        }

        if (startNode == head) {
            head = endNode->next;
        } else {
            curr = head;
            for (int j = 0; j < start - 1; j++) {
                curr = curr->next;
            }
            curr->next = endNode->next;
        }

        if (endNode == tail) {
            tail = startNode;
        } else {
            curr = head;
            for (int j = 0; j < newPos - 1; j++) {
                curr = curr->next;
            }
            endNode->next = curr->next;
            curr->next = startNode;
        }

        size_queue -= end - start + 1;
        insert(startNode, newPos);
    }

    std::vector<T> toVector() const {
        std::vector<T> result;
        Node* curr = head;
        while (curr) {
            result.push_back(curr->value);
            curr = curr->next;
        }
        return result;
    }

    bool empty() const {
        return head == nullptr;
    }

    int getSize() const {
        return size_queue;
    }

    const T& front() const {
        if (empty()) {
            throw std::runtime_error("Queue is empty");
        }
        return head->value;
    }

    const T& back() const {
        if (empty()) {
            throw std::runtime_error("Queue is empty");
        }
        return tail->value;
    }
};
#endif // QUEUE_H
