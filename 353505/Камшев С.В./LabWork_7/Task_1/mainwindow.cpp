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

    SwapButton = new QPushButton(this);
    SwapButton->setGeometry(130, 200, 200, 30);
    SwapButton->setText("Swap");

    // intQRadioButton = new QRadioButton(this);
    // intQRadioButton->setText("Int");
    // intQRadioButton->setGeometry(0, 100, 100, 20);
    // intQRadioButton->setChecked(true);

    // doubleRadioButton = new QRadioButton(this);
    // doubleRadioButton->setText("Double");
    // doubleRadioButton->setGeometry(0, 130, 100, 20);

    // stringRadioButton = new QRadioButton(this);
    // stringRadioButton->setText("String");
    // stringRadioButton->setGeometry(0, 160, 100, 20);

    // connect(intQRadioButton, &QRadioButton::clicked,[=](){
    //     listLineEdit->setText("");
    //     ItemLineEdit->setText("");
    //     IntValidator *val = new IntValidator();
    //     ItemLineEdit->setValidator(val);
    // } );

    // connect(intQRadioButton, &QRadioButton::clicked,[=](){
    //     listLineEdit->setText("");
    //     ItemLineEdit->setText("");
    //     IntValidator *val = new IntValidator();
    //     ItemLineEdit->setValidator(val);
    // } );

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

    connect(SwapButton, &QPushButton::clicked,[=](){
        if (deque.empty()) {
            QMessageBox::critical(this, "Ошибка", "Очередь пуста");
            return;
        }
        deque.swap();
        showInformatoin();
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
