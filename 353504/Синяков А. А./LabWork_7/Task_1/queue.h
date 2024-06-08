#ifndef QUEUE_H
#define QUEUE_H

#include <QString>
#include <QListWidget>
#include <QTextEdit>

class Node {
public:
    QString data;
    Node* next;
    Node* prev;

    Node(QString val) : data(val), next(nullptr), prev(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue();
    ~Queue();

    bool isEmpty();
    void enqueue(QString val, bool addToFront);
    void dequeue(bool deleteFromFront);
    void display(QListWidget* listWidget);
    void convertToCircular();
    bool isCircular();
    void displayAll() ;

};

#endif // QUEUE_H
