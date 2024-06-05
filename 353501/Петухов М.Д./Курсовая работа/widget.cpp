#include "widget.h"
#include "ui_widget.h"
#include "mainwindow.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

  ui->startGameButton->setStyleSheet("QPushButton { background-color: transparent; border: none; "
                         "background-image: url('../resources/button.png'); "
                         "color: white; font-weight: bold; font-size: 20px; font-family: 'Comic Sans MS'; }");
  ui->startGameButton->setFixedSize(225, 53);
  ui->startGameButton->setText("Начать игру");
  ui->rulesDialogButton->setStyleSheet("QPushButton { background-color: transparent; border: none; "
                         "background-image: url('../resources/button.png'); "
                         "color: white; font-weight: bold; font-size: 20px; font-family: 'Comic Sans MS'; }");
  ui->rulesDialogButton->setFixedSize(225, 53);
  ui->rulesDialogButton->setText("Как играть");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startGameButton_clicked(){
    this->hide();

    mainGameWindowPtr = nullptr;
    MainWindow* mainGameWindow;
    if(mainGameWindowPtr != nullptr){
        delete mainGameWindowPtr;
        mainGameWindowPtr = nullptr;
    }
    if(mainGameWindowPtr == nullptr){
        mainGameWindow = new MainWindow(this);
        mainGameWindowPtr = dynamic_cast<QMainWindow* >(mainGameWindow);
    }
    mainGameWindow->show();
}

void Widget::on_rulesDialogButton_clicked(){
    RulesDialog rules;
    rules.exec();
}

void Widget::execute(){
    this->show();
}

