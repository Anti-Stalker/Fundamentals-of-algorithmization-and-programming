//
// Created by volodya-petarda on 5/30/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ScapegoatTree.h"
#include "Treap.h"


mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);
    selectTree(0);
    connect(this->ui->comboBox, SIGNAL(activated(int)), this, SLOT(selectTree(int)));
    connect(this->ui->addElementButton, SIGNAL(clicked()), this, SLOT(addElement()));
    connect(this->ui->addRandomButton, SIGNAL(clicked()), this, SLOT(addRandom()));
    connect(this->ui->addSequenceButton, SIGNAL(clicked()), this, SLOT(addSequence()));
    connect(this->ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteKey()));
    connect(this->ui->findButton, SIGNAL(clicked()), this, SLOT(findKey()));
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::selectTree(int ind) {
    switch (ind) {
        case (0):{
            this->tree = new BinaryTree();
            break;
        }
        case(1):{
            this->tree = new ScapegoatTree();
            break;
        }
        case(2):{
            this->tree = new Treap();
            break;
        }
        default:{
            break;
        }
    }
}

void mainwindow::addElement() {
    int key = this->ui->keyInput->value();
    std::string value = this->ui->valueInput->toPlainText().toStdString();
    this->tree->insert(key, value);
    this->tree->printTree();
    showTree();
}

void mainwindow::showTree() {
    this->ui->treeWidget->clear();
    std::vector<std::vector<std::string>> v;
    tree->getTree(v);
    if(v.size() == 0)
        return;
    std::vector<std::pair<std::string, QTreeWidgetItem*>> stack;
    QTreeWidgetItem *root = new QTreeWidgetItem(this->ui->treeWidget);
    root->setText(0, QString::fromStdString(v[0][2] + " " + v[0][3]));
    stack.push_back({v[0][2], root});
    for(int i = 1; i < v.size(); i++){
        auto last = stack.back();
        if(last.first == v[i][0]){
            QTreeWidgetItem *newItem = new QTreeWidgetItem(last.second);
            newItem->setText(0, QString::fromStdString(v[i][2] + " " + v[i][3]));
            stack.push_back({v[i][2], newItem});
        }
        else{
            i--;
            stack.pop_back();
            continue;
        }
    }
    this->ui->treeWidget->expandAll();
}

void mainwindow::addRandom() {
    int count = this->ui->randomCount->value();
    while(count--){
        int key = rand() % 1000000;
        std::string value = "";
        this->tree->insert(key, value);
    }
    showTree();
}

void mainwindow::addSequence() {
    int from = this->ui->sequence1->value();
    int to = this->ui->sequence2->value();
    for(int i = from; i <= to; i++){
        tree->insert(i, "");
    }
    showTree();
}

void mainwindow::deleteKey() {
    int key = this->ui->deleteKey->value();
    this->tree->erase(key);
    showTree();
}

void mainwindow::findKey() {
    int key = this->ui->findKey->value();
    std::string text = this->tree->find(key);
    this->ui->findResult->setText(QString::fromStdString(text));
}
