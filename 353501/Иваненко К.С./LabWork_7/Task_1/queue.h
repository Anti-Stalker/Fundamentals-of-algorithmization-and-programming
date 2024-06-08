#pragma once

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class Queue
{
private:
    Node *head;
    Node *tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    void enqueue(Node *newNode)
    {
        if (tail)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {
            head = tail = newNode;
        }
    }

    int pop_end()
    {
        if (!head)
            throw std::out_of_range("Queue is empty");
        Node *temp = head;
        int value = temp->data;
        head = head->next;
        if (head)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
        return value;
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    QString output() const
    {   
        QString result;
        Node *temp = head;
        while (temp)
        {
            result += (QString::number(temp->data) + " ");
            temp = temp->next;
        }
        return result;
    }

    void splitQueue(Queue& negatives, Queue& positives) {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            if (current->data < 0) {
                current->prev = current->next = nullptr;
                negatives.enqueue(current);
            } else {
                current->prev = current->next = nullptr;
                positives.enqueue(current);
            }
            current = next;
        }
        head = tail = nullptr;
    }

    ~Queue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};