//
// Created by darina on 5/27/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include <iostream>
#include <QTreeWidgetItem>
#include <stack>
#include "mainwindow.h"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    tree = new Tree();

    srand(time(0));
    for(int i = 0; i < 20; i ++)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        int k = ui->tableWidget->rowCount();
        ui->tableWidget->setItem(k - 1, 1, new QTableWidgetItem("value " + QString::number(i + 1)));
        ui->tableWidget->setItem(k - 1, 0, new QTableWidgetItem(QString::number(rand() % 100 + 1)));
    }

    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QString::number(1)));
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem(QString::number(2)));
    ui->tableWidget->setItem(2, 0, new QTableWidgetItem(QString::number(3)));

    connect(ui->fillbasetreepushButton, SIGNAL(clicked(bool)), this, SLOT(next_node_add_clicked()));
    connect(ui->addnodepushButton, SIGNAL(clicked(bool)), this, SLOT(add_node_clicked()));
    connect(ui->findpushButton, SIGNAL(clicked()), this, SLOT(find_in_tree()));
    connect(ui->deletenodepushButton, SIGNAL(clicked()), this, SLOT(delete_in_tree()));

    connect(ui->getInfo_1pushButton, SIGNAL(clicked(bool)), this, SLOT(Info_1_clicked()));
    connect(ui->getInfo_2pushButton, SIGNAL(clicked(bool)), this, SLOT(Info_2_clicked()));
    connect(ui->getInfo_3pushButton, SIGNAL(clicked(bool)), this, SLOT(Info_3_clicked()));
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::next_node_add_clicked() {
    //  for(int i =0; i < 5; i ++) {
    ui->treeWidget->clear();
    auto key = stoi(ui->tableWidget->item(cur, 0)->text().toStdString());
    auto value = ui->tableWidget->item(cur, 1)->text().toStdString();

    tree->Insert(key, value);

    cur++;
    if (cur == ui->tableWidget->rowCount())
        ui->fillbasetreepushButton->setEnabled(0);

    std::vector<std::pair<int, int> > v = tree->getTree();

    for (auto x: v) {
        std::cout << x.first << " " << x.second << " : ";
    }
    std::cout << '\n';

    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget);
    rootItem->setText(0, QString::number(v[0].second));
    std::stack<std::pair<QTreeWidgetItem *, int> > hierarchy;
    hierarchy.push({rootItem, v[0].second});
    for (int i = 1; i < v.size(); i++) {
        while (v[i].first != hierarchy.top().second) {
            hierarchy.pop();
        }
        QTreeWidgetItem *newItem = new QTreeWidgetItem(hierarchy.top().first);
        newItem->setText(0, QString::number(v[i].second));
        hierarchy.push({newItem, v[i].second});
    }
    ui->treeWidget->expandAll();
//    }
}

void mainwindow::add_node_clicked() {
    int key = ui->plainTextEdit->toPlainText().toInt();
    std::string value = ui->plainTextEdit_2->toPlainText().toStdString();
    ui->treeWidget->clear();

    tree->Insert(key, value);

    std::vector<std::pair<int, int> > v = tree->getTree();

    for (auto x: v) {
        std::cout << x.first << " " << x.second << " : ";
    }
    std::cout << '\n';

    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget);
    if(v.size() == 0)
    {

    }
    else {
        rootItem->setText(0, QString::number(v[0].second));
        std::stack<std::pair<QTreeWidgetItem *, int> > hierarchy;
        hierarchy.push({rootItem, v[0].second});
        for (int i = 1; i < v.size(); i++) {
            while (v[i].first != hierarchy.top().second) {
                hierarchy.pop();
            }
            QTreeWidgetItem *newItem = new QTreeWidgetItem(hierarchy.top().first);
            newItem->setText(0, QString::number(v[i].second));
            hierarchy.push({newItem, v[i].second});
        }
        ui->treeWidget->expandAll();
    }
}

void mainwindow::find_in_tree() {
    int k = ui->plainTextEdit_4->toPlainText().toInt();
    auto t = tree->Find(k);
    ui->plainTextEdit_4->setPlainText(QString::fromStdString(t));
}

void mainwindow::delete_in_tree() {
    int k = ui->plainTextEdit_3->toPlainText().toInt();
    auto t = tree->Find(k);
    if(t == "Не найдено в дереве")
    {
        ui->plainTextEdit_3->setPlainText(QString::fromStdString(t));
    }
    else
    {
        tree->Delete(k);
        ui->treeWidget->clear();
        ui->plainTextEdit_3->setPlainText("Успешно удалено");
        std::vector<std::pair<int, int> > v = tree->getTree();

        for (auto x: v) {
            std::cout << x.first << " " << x.second << " : ";
        }
        std::cout << '\n';

        QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget);
        if(v.size() != 0) {
            rootItem->setText(0, QString::number(v[0].second));
            std::stack<std::pair<QTreeWidgetItem *, int> > hierarchy;
            hierarchy.push({rootItem, v[0].second});
            for (int i = 1; i < v.size(); i++) {
                while (v[i].first != hierarchy.top().second) {
                    hierarchy.pop();
                }
                QTreeWidgetItem *newItem = new QTreeWidgetItem(hierarchy.top().first);
                newItem->setText(0, QString::number(v[i].second));
                hierarchy.push({newItem, v[i].second});
            }
            ui->treeWidget->expandAll();
        }
    }
}

void mainwindow::Info_1_clicked() {
    std::vector<std::pair<int, std::string> > v = tree->GetInfo(1);
    ui->showtreeplainTextEdit->clear();
    for(int i = 0; i < v.size(); i ++)
    {
        ui->showtreeplainTextEdit->appendPlainText(QString::number(v[i].first) + " : " + QString::fromStdString(v[i].second) + "\n");
    }
}

void mainwindow::Info_3_clicked() {
    std::vector<std::pair<int, std::string> > v = tree->GetInfo(3);
    ui->showtreeplainTextEdit->clear();
    for(int i = 0; i < v.size(); i ++)
    {
        ui->showtreeplainTextEdit->appendPlainText(QString::number(v[i].first) + " : " + QString::fromStdString(v[i].second) + "\n");
    }
}

void mainwindow::Info_2_clicked() {
    std::vector<std::pair<int, std::string> > v = tree->GetInfo(2);
    ui->showtreeplainTextEdit->clear();
    for(int i = 0; i < v.size(); i ++)
    {
        ui->showtreeplainTextEdit->appendPlainText(QString::number(v[i].first) + " : " + QString::fromStdString(v[i].second) + "\n");
    }

}
