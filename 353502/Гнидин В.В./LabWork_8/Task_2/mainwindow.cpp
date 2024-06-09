//
// Created by volodya-petarda on 5/31/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);
    setHeapType(0);
    connect(this->ui->heapType, SIGNAL(currentIndexChanged(int)), this, SLOT(setHeapType(int)));
    connect(this->ui->addNumberButton, SIGNAL(clicked()), this, SLOT(add()));
    connect(this->ui->maxButton, SIGNAL(clicked()), this, SLOT(getMax()));
    connect(this->ui->deleteMaxButton, SIGNAL(clicked()), this, SLOT(deleteMax()));
    connect(this->ui->increaseButton, SIGNAL(clicked()), this, SLOT(increaseElement()));
    connect(this->ui->decreaseButton, SIGNAL(clicked()), this, SLOT(decreaseElement()));
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::setHeapType(int type) {
    switch(type){
        case(0):{
            heap = new HeapList();
            break;
        }
        case(1):{
            heap = new HeapArray();
            break;
        }
        default:{
            break;
        }
    }
}

void mainwindow::showHeap() {
    std::vector<int> v = heap->getHeap();
    std::string result = "";
    for(int a : v){
        result += " " + std::to_string(a);
    }
    this->ui->list->setText(QString::fromStdString(result));
}

void mainwindow::add() {
    int val = this->ui->addNumberInput->value();
    this->heap->add(val);
    showHeap();
}

void mainwindow::getMax() {
    int val = -1;
    if(heap->size() >= 1)
        val = heap->getMax();
    this->ui->maxResult->setText(QString::number(val));
}

void mainwindow::deleteMax() {
    if(this->heap->size() >= 1)
        this->heap->extractMax();
    showHeap();
}

void mainwindow::increaseElement() {
    int val = this->ui->valueInput->value();
    int delt = this->ui->deltaInput->value();
    this->heap->increaseValue(val, delt);
    showHeap();
}

void mainwindow::decreaseElement() {
    int val = this->ui->valueInput->value();
    int delt = this->ui->deltaInput->value();
    this->heap->decreaseValue(val, delt);
    showHeap();
}
