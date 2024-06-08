#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <QVector>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* top;
    size_t size_;

public:
    // Конструктор
    Stack() : top(nullptr), size_(0) {}

    // Проверка на пустоту
    bool empty() const {
        return top == nullptr;
    }

    // Получение размера стека
    size_t size() const {
        return size_;
    }

    // Вставка элемента на вершину стека
    void push(const T& data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        ++size_;
    }

    // Извлечение элемента с вершины стека
    T pop() {
        if (empty()) {
            throw std::runtime_error("Стек пуст");
        }
        Node* temp = top;
        T data = temp->data;
        top = top->next;
        delete temp;
        --size_;
        return data;
    }

    // Просмотр элемента с вершины стека (без удаления)
    T peek() const {
        if (empty()) {
            throw std::runtime_error("Стек пуст");
        }
        return top->data;
    }

    QVector <T> toVector() const{
        QVector<T> result;
        Node* current = top;
        while (current != nullptr) {
            result.push_back(current->data);
            current = current->next;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }

    void clear(){
        while (!empty()) {
            pop();
        }
    }
};



#endif // STACK_H
