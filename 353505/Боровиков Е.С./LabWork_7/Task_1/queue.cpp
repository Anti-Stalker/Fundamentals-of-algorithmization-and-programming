#include "queue.h"
#include <QString>

Queue::Queue() : head(nullptr), tail(nullptr) {}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    Node* temp = head;
    int value = temp->data;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
    return value;
}

bool Queue::isEmpty() const {
    return head == nullptr;
}

void Queue::bubbleSort() {
    if (isEmpty()) return;

    bool swapped;
    Node* current;
    Node* last = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

QString Queue::toString() const {
    QString result;
    Node* current = head;
    while (current) {
        result += QString::number(current->data) + " ";
        current = current->next;
    }
    return result.trimmed();
}
