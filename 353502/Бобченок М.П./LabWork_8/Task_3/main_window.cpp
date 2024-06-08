//
// Created by u on 31.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"


QStandardItem *main_window::buildTree(Treap<int, int>::Node *cur)
{
    if (!cur)
        return nullptr;

    QStandardItem *it = new QStandardItem();
    if (!type)
        it->setText(QString::number(cur->key) + " - " + QString::number(cur->value));
    else
        it->setText(QString::number(cur->key));


    QStandardItem *p = buildTree(cur->l);
    if (p)
        it->appendRow(p);

    p = buildTree(cur->r);
    if (p)
        it->appendRow(p);

    return it;
}

void main_window::on_add_clicked()
{
    if (type == 0)
    {
        mp.insert(ui->key->value(), ui->val->value());

        QStandardItemModel *model = new QStandardItemModel();
        QStandardItem *rootItem = model->invisibleRootItem();
        rootItem->appendRow(buildTree(mp.getT().getRoot()));

        ui->treeView->setModel(model);
        ui->treeView->expandAll();

        update();
    }
    else
    {
        st.insert(ui->key->value());

        QStandardItemModel *model = new QStandardItemModel();
        QStandardItem *rootItem = model->invisibleRootItem();
        rootItem->appendRow(buildTree(st.getT().getRoot()));

        ui->treeView->setModel(model);
        ui->treeView->expandAll();

        update();
    }
}

void main_window::on_erase_clicked()
{
    if (type == 0)
    {
        mp.getT().erase(ui->key->value());

        QStandardItemModel *model = new QStandardItemModel();
        QStandardItem *rootItem = model->invisibleRootItem();
        rootItem->appendRow(buildTree(mp.getT().getRoot()));

        ui->treeView->setModel(model);
        ui->treeView->expandAll();

        update();
    }
    else
    {
        st.getT().erase(ui->key->value());

        QStandardItemModel *model = new QStandardItemModel();
        QStandardItem *rootItem = model->invisibleRootItem();
        rootItem->appendRow(buildTree(st.getT().getRoot()));

        ui->treeView->setModel(model);
        ui->treeView->expandAll();

        update();
    }
}

void main_window::on_get_clicked()
{
    if (type == 0)
    {
        ui->textBrowser->setText(QString::number(mp[ui->key->value()]));
        update();
    }
}

void main_window::on_change_clicked()
{
    type = !type;
    if (!type)
    {
        ui->change->setText("goToMap");

        QStandardItemModel *model = new QStandardItemModel();
        QStandardItem *rootItem = model->invisibleRootItem();
        rootItem->appendRow(buildTree(mp.getT().getRoot()));

        ui->treeView->setModel(model);
        ui->treeView->expandAll();

        update();
    }
    else
    {
        ui->change->setText("goToSet");

        QStandardItemModel *model = new QStandardItemModel();
        QStandardItem *rootItem = model->invisibleRootItem();
        rootItem->appendRow(buildTree(st.getT().getRoot()));

        ui->treeView->setModel(model);
        ui->treeView->expandAll();

        update();
    }
}

void main_window::on_output_clicked()
{
    if (type)
    {
        QVector<int> v;
        st.getT().direct(v);

        QString s;
        for (auto &u : v)
            s += QString::number(u) + " ";

        ui->textBrowser->setText(s);
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
