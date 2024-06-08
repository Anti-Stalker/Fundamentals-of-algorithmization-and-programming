#include "queue.h"
#include <QDebug>

// Конструктор класса Queue, инициализирующий указатели front и rear как nullptr
Queue::Queue() : front(nullptr), rear(nullptr) {}

// Деструктор класса Queue, освобождающий память, выделенную под узлы очереди
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue(true);
    }
}

// Метод для проверки, пуста ли очередь
bool Queue::isEmpty() {
    return (front == nullptr);
}

// Метод для добавления элемента в начало или конец очереди
void Queue::enqueue(QString val, bool addToFront) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        if (addToFront) {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }
}

// Метод для удаления элемента из начала или конца очереди
void Queue::dequeue(bool deleteFromFront) {
    if (isEmpty()) {
        qDebug() << "Queue is empty. Cannot dequeue.";
    } else {
        Node* temp;
        if (deleteFromFront) {
            temp = front;
            if (front == rear) {
                front = rear = nullptr;
            } else {
                front = front->next;
                front->prev = nullptr;
            }
        } else {
            temp = rear;
            if (front == rear) {
                front = rear = nullptr;
            } else {
                rear = rear->prev;
                rear->next = nullptr;
            }
        }
        delete temp;
    }
}

// Метод для отображения содержимого очереди в виджете QListWidget
void Queue::display(QListWidget* listWidget) {
    listWidget->clear();
    if (isEmpty()) {
        qDebug() << "Queue is empty.";
    } else {
        Node* temp = front;
        while (temp) {
            listWidget->addItem(temp->data);
            temp = temp->next;
        }
    }
}

// Метод для преобразования очереди в кольцевую структуру
void Queue::convertToCircular() {
    if (!isEmpty()) {
        rear->next = front;
        front->prev = rear;
    }
}

// Метод для проверки, является ли очередь кольцевой
bool Queue::isCircular() {
    if (isEmpty())
        return false;
    return rear->next == front && front->prev == rear;
}
