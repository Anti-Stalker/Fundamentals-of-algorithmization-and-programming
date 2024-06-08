#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    PushFrontButton = new QPushButton(this);
    PushFrontButton->setGeometry(0, 300, 200, 30);
    PushFrontButton->setText("PushFront");

    PushBackButton = new QPushButton(this);
    PushBackButton->setGeometry(260, 300, 200, 30);
    PushBackButton->setText("PushBack");

    PopFrontButton = new QPushButton(this);
    PopFrontButton->setGeometry(0, 340, 200, 30);
    PopFrontButton->setText("PopFront");

    PopBackButton = new QPushButton(this);
    PopBackButton->setGeometry(260, 340, 200, 30);
    PopBackButton->setText("PopBack");

    listLineEdit = new QLineEdit(this);
    listLineEdit->setGeometry(0, 0, 460, 30);
    listLineEdit->setEnabled(false);

    ItemLineEdit = new QLineEdit(this);
    ItemLineEdit->setGeometry(0, 50, 200, 30);
    IntValidator *val = new IntValidator();
    ItemLineEdit->setValidator(val);

    ClearButton = new QPushButton(this);
    ClearButton->setGeometry(0, 260, 200, 30);
    ClearButton->setText("Clear");

    SizeButton = new QPushButton(this);
    SizeButton->setGeometry(260, 260, 200, 30);
    SizeButton->setText("Size");

    connect(PushFrontButton, &QPushButton::clicked,[=](){
        if (ItemLineEdit->text().isEmpty()) {
            QMessageBox::critical(this, "Ошибка", "Не было введено значение");
            return;
        }
        deque.push_front(ItemLineEdit->text().toInt());
        showInformatoin();
    } );

    connect(PushBackButton, &QPushButton::clicked,[=](){
        if (ItemLineEdit->text().isEmpty()) {
            QMessageBox::critical(this, "Ошибка", "Не было введено значение");
            return;
        }
        deque.push_back(ItemLineEdit->text().toInt());
        showInformatoin();

    } );

    connect(PopFrontButton, &QPushButton::clicked,[=](){
        if (deque.empty()) {
            QMessageBox::critical(this, "Ошибка", "Очередь пуста");
            return;
        }
        deque.pop_front();
        showInformatoin();

    } );

    connect(PopBackButton, &QPushButton::clicked,[=](){
        if (deque.empty()) {
            QMessageBox::critical(this, "Ошибка", "Очередь пуста");
            return;
        }
        deque.pop_back();
        showInformatoin();
    } );

    connect(ClearButton, &QPushButton::clicked,[=](){
        deque.clear();
        showInformatoin();
    } );

    connect(SizeButton, &QPushButton::clicked,[=](){
            QMessageBox::information(this, "", "Размер очереди - " + QString::number(deque.size()));
    } );
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showInformatoin()
{
    listLineEdit->setText("");
    if (deque.empty()) return;
    Node <int>* node = deque.head;
    do {
        listLineEdit->setText(listLineEdit->text() + QString::number(node->data) + " ");
        node = node->next;
    } while (node != nullptr);
}
