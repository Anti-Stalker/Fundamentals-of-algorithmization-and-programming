//
// Created by u on 31.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"


QStandardItem *main_window::buildPtr(std::shared_ptr<Node> cur)
{
    if (!cur)
        return nullptr;

    QStandardItem *it = new QStandardItem();
    it->setText(QString::number(cur->val));

    QStandardItem *p = buildPtr(cur->left);
    if (p)
        it->appendRow(p);

    p = buildPtr(cur->right);
    if (p)
        it->appendRow(p);

    return it;
}

QStandardItem *main_window::buildArray(int cur)
{
    if (cur == 1)
        heap = ah.getHeap();
    if (cur >= heap.size())
        return nullptr;

    QStandardItem *it = new QStandardItem();
    it->setText(QString::number(heap[cur]));

    QStandardItem *p = buildArray(cur * 2);
    if (p)
        it->appendRow(p);

    p = buildArray(cur * 2 + 1);
    if (p)
        it->appendRow(p);

    return it;
}

void main_window::on_add_clicked()
{
    if (type)
    {
        ph.push(ui->val->value());

        QStandardItemModel *model = new QStandardItemModel();
        QStandardItem *rootItem = model->invisibleRootItem();
        rootItem->appendRow(buildPtr(ph.getRoot()));

        ui->treeView->setModel(model);
        ui->treeView->expandAll();

        update();
    }
    else
    {
        ah.push(ui->val->value());

        QStandardItemModel *model = new QStandardItemModel();
        QStandardItem *rootItem = model->invisibleRootItem();
        rootItem->appendRow(buildArray(1));

        ui->treeView->setModel(model);
        ui->treeView->expandAll();

        update();
    }
}

void main_window::on_erase_clicked()
{
    if (type)
    {
        ph.pop();

        QStandardItemModel *model = new QStandardItemModel();
        QStandardItem *rootItem = model->invisibleRootItem();
        rootItem->appendRow(buildPtr(ph.getRoot()));

        ui->treeView->setModel(model);
        ui->treeView->expandAll();

        update();
    }
    else
    {
        ah.pop();

        QStandardItemModel *model = new QStandardItemModel();
        QStandardItem *rootItem = model->invisibleRootItem();
        rootItem->appendRow(buildArray(1));

        ui->treeView->setModel(model);
        ui->treeView->expandAll();

        update();
    }
}

void main_window::on_changeType_clicked()
{
    type = !type;
    if (type)
    {
        QStandardItemModel *model = new QStandardItemModel();
        QStandardItem *rootItem = model->invisibleRootItem();
        rootItem->appendRow(buildPtr(ph.getRoot()));

        ui->treeView->setModel(model);
        ui->treeView->expandAll();

        update();
    }
    else
    {
        QStandardItemModel *model = new QStandardItemModel();
        QStandardItem *rootItem = model->invisibleRootItem();
        rootItem->appendRow(buildArray(1));

        ui->treeView->setModel(model);
        ui->treeView->expandAll();

        update();
    }
}

main_window::main_window(QWidget *parent) :
        QWidget(parent), ui(new Ui::main_window)
{
    QTreeWidgetItem *p = new QTreeWidgetItem();


    ui->setupUi(this);
}

main_window::~main_window() {
    delete ui;
}
