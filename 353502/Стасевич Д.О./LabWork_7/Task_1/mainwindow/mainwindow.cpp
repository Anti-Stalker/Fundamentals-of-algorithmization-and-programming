//
// Created by darina on 5/27/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QTimer>

mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    v = {
            "#ifndef TASK1_QUEUE_H",
            "#define TASK1_QUEUE_H",
            "#include <vector>",
            "#include <iostream>",
            "template<typename T>",
            "class Queue {",
            "public:",
            "    Queue() {};",
            "    ~Queue() {",
            "        while (_size != 0) {",
            "            dequeue();",
            "        }",
            "    }",
            "    struct Node {",
            "        T data;",
            "        Node *next;",
            "        Node* prev;",
            "        Node(const T &data = T()) : data(data), next(nullptr), prev(nullptr) {}",
            "    };",
            "    void clear() {",
            "        Node* _cur = _head;",
            "        while (_size != 0) {",
            "            Node* temp = _cur;",
            "            _cur = _cur->next;",
            "            _size --;",
            "            delete temp;",
            "        }",
            "        _head = nullptr;",
            "        _tail = nullptr;",
            "    }",
            "    void enqueue(const T &data) {",
            "        Node* _newNode = new Node(data);",
            "        if (_head == nullptr)",
            "        {",
            "            _head = _newNode;",
            "            _tail = _newNode;",
            "            _head->next = _head;",
            "            _head->prev = _head;",
            "            _tail->next = _head;",
            "            _tail->prev = _head;",
            "            _cur_position = _head;",
            "        }",
            "         else {",
            // add after cur_position
            "             _cur_position->next->prev = _newNode;",
            "             _newNode->next = _cur_position->next;",
            "             _cur_position->next = _newNode;",
            "             _newNode->prev = _cur_position;",
            "             _cur_position = _cur_position->next;",
            "        }",
            "        ++ _size;",
            "   }",
            "    T dequeue() {",
            "        if (_size == 0) {",
            "            throw \"Empty queue\";",
            "        };",
            "       T _value = _cur_position->data;",
            "        -- _size;",
            "        if(_size) {",
            "            Node* _temp = _cur_position->prev;",
            "            _cur_position->prev->next = _cur_position->next;",
            "            delete _cur_position;",
            "            _temp->next->prev = _temp;",
            "            _cur_position = _temp->next;",
            "        }",
            "        else",
            "        {",
            "            _head = nullptr;",
            "            _tail = nullptr;",
            "            _cur_position = nullptr;",
            "        }",
            "        return _value;",
            "    }",
            "   bool isEmpty() const {",
            "        return _size == 0;",
            "    }",
            "    int size() const {",
            "       return _size;",
            "   }",
            "    T &front() const {",
            "        if (_head == nullptr) {",
            "            throw \"Queue is empty\";",
            "        }",
            "        return _head->data;",
            "    }",
            "    T &back() const {",
            "        if (_tail == nullptr) {",
            "            throw \"Queue is empty\";",
            "        }",
            "        return _tail->data;",
            "    }",
            "    std::vector<T> show()",
            "    {",
            "        std::vector<T> ret;",
            "        Node* temp = _head;",
            "        for(int i = 0; i < _size; i ++)",
            "        {",
            "            ret.push_back(temp->data);",
            "            temp = temp->next;",
            "        }",
            "        return ret;",
            "    }",
            "    T GoLeftCircle()",
            "    {",
            "        if(_size == 0)",
            "        {",
            "            throw \"Empty queue\";",
            "        }",
            "        _cur_position = _cur_position->prev;",
            "        return _cur_position->data;",
            "    }",
            "    T GetNode()",
            "    {",
            "        if(_size == 0)",
            "        {",
            "            throw \"Empty queue\";",
            "        }",
            "        return _cur_position->data;",
            "    }",
            "    T GoRightCircle()",
            "    {",
            "        if(_size == 0)",
            "        {",
            "            throw \"Empty queue\";",
            "        }",
            "        _cur_position = _cur_position->next;",
            "        return _cur_position->data;",
            "    }",
            "private:",
            "    Node* _head = nullptr;",
            "    Node* _tail = nullptr;",
            "    Node* _cur_position = nullptr;",
            "    int _size = 0;",
            "};",
            "#endif //TASK1_QUEUE_H",
            "    };"
    };

    auto *timer_prev = new QTimer(this);
    timer_prev->setInterval(500);

    auto *timer_nxt = new QTimer(this);
    timer_nxt->setInterval(500);

    for(auto x : v)
        q.enqueue(x);
    ShowQueue();

    ui->oneLineplainTextEdit->setPlainText(QString::fromStdString(q.GetNode()));

    connect(ui->sizepushButton, SIGNAL(clicked(bool)), this, SLOT(GetSize()));
    connect(ui->prevpushButton, SIGNAL(clicked(bool)), this, SLOT(previousElement()));
    connect(ui->nextpushButton, SIGNAL(clicked()), this, SLOT(NextElement()));
    connect(ui->dequeuepushButton, SIGNAL(clicked(bool)), this, SLOT(DoDequeue()));
    connect(ui->enqueuepushButton, SIGNAL(clicked(bool)), this, SLOT(DoEnqueue()));
    connect(ui->frontpushButton, SIGNAL(clicked(bool)), this, SLOT(ShowFront()));
    connect(ui->backpushButton, SIGNAL(clicked(bool)), this, SLOT(ShowBack()));

    connect(ui->prevpushButton, SIGNAL(pressed()), timer_prev, SLOT(start()));
    connect(timer_prev, SIGNAL(timeout()), this, SLOT(previousElement()));
    connect(ui->prevpushButton, SIGNAL(released()), timer_prev, SLOT(stop()));

    connect(ui->nextpushButton, SIGNAL(pressed()), timer_nxt, SLOT(start()));
    connect(timer_nxt, SIGNAL(timeout()), this, SLOT(NextElement()));
    connect(ui->nextpushButton, SIGNAL(released()), timer_nxt, SLOT(stop()));

    connect(ui->clearpushButton, SIGNAL(clicked(bool)), this, SLOT(DoClear()));

}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::ShowQueue() {
    auto t = q.show();
    ui->allCircleplainTextEdit->clear();
    for(auto x : t)
    {
        ui->allCircleplainTextEdit->appendPlainText(QString::fromStdString(x));
    }
}

void mainwindow::previousElement() {
    try {
        auto t = q.GoLeftCircle();
        ui->oneLineplainTextEdit->setPlainText(QString::fromStdString(t));
    }
    catch(...)
    {
        QMessageBox message;
        message.setText("empty queue");
        message.exec();
        return;
    }
}

void mainwindow::NextElement() {
    try {
        auto t = q.GoRightCircle();
        ui->oneLineplainTextEdit->setPlainText(QString::fromStdString(t));
    }
    catch (...)
    {
        QMessageBox message;
        message.setText("empty queue");
        message.exec();
        return;
    }
}

void mainwindow::DoDequeue() {
    try {
        auto t = q.dequeue();
        if(q.isEmpty())
        {
            ui->oneLineplainTextEdit->clear();
            GetSize();
        }
        else
        {
            ui->oneLineplainTextEdit->setPlainText(QString::fromStdString(q.GetNode()));
            GetSize();
        }
        ShowQueue();
    }
    catch(...)
    {
        QMessageBox message;
        message.setText("empty queue");
        message.exec();
        return;
    }
}

void mainwindow::DoEnqueue() {
    auto t = ui->addLineplainTextEdit->toPlainText().toStdString();
    ui->addLineplainTextEdit->clear();
    q.enqueue(t);
    ui->oneLineplainTextEdit->setPlainText(QString::fromStdString(q.GetNode()));
    GetSize();
    ShowQueue();
}

void mainwindow::GetSize() {
    ui->sizeplainTextEdit->setPlainText(QString::number(q.size()));
}

void mainwindow::ShowFront() {
    try
    {
        ui->elementplainTextEdit->setPlainText(QString::fromStdString(q.front()));
    }
    catch (...)
    {
        QMessageBox message;
        message.setText("empty queue");
        message.exec();
        return;
    }
}

void mainwindow::ShowBack() {
    try
    {
        ui->elementplainTextEdit->setPlainText(QString::fromStdString(q.back()));
    }
    catch (...)
    {
        QMessageBox message;
        message.setText("empty queue");
        message.exec();
        return;
    }
}

void mainwindow::DoClear() {
    q.clear();
    ShowQueue();
    GetSize();
    ui->oneLineplainTextEdit->clear();

}
