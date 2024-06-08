//
// Created by u on 31.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"


QStandardItem *main_window::buildTree(Treap<int>::Node *cur)
{
    if (!cur)
        return nullptr;

    QStandardItem *it = new QStandardItem();
    it->setText(QString::number(cur->value));

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
    std::mt19937_64 rnd(time(nullptr));

    t.insert(ui->key->value(), ui->val->value(), rnd());

    QStandardItemModel *model = new QStandardItemModel();
    QStandardItem *rootItem = model->invisibleRootItem();
    rootItem->appendRow(buildTree(t.getRoot()));

    ui->treeView->setModel(model);
    ui->treeView->expandAll();

    update();
}

void main_window::on_erase_clicked()
{
    t.erase(ui->key->value());

    QStandardItemModel *model = new QStandardItemModel();
    QStandardItem *rootItem = model->invisibleRootItem();
    rootItem->appendRow(buildTree(t.getRoot()));

    ui->treeView->setModel(model);
    ui->treeView->expandAll();

    update();
}

void main_window::on_find_clicked()
{
    int res = t.find(ui->key->value());
    ui->textBrowser->setText(QString::number(res));

    QStandardItemModel *model = new QStandardItemModel();
    QStandardItem *rootItem = model->invisibleRootItem();
    rootItem->appendRow(buildTree(t.getRoot()));

    ui->treeView->setModel(model);
    ui->treeView->expandAll();

    update();

}

void main_window::on_direct_clicked()
{
    QVector<int> v;
    t.direct(v);
    QString s;
    for (auto &u : v)
        s += QString::number(u) + " ";

    ui->textBrowser->setText(s);
    update();
}

void main_window::on_back_clicked()
{
    QVector<int> v;
    t.back(v);
    QString s;
    for (auto &u : v)
        s += QString::number(u) + " ";

    ui->textBrowser->setText(s);
    update();
}

void main_window::on_byKey_clicked()
{
    QVector<int> v;
    t.byKey(v);
    QString s;
    for (auto &u : v)
        s += QString::number(u) + " ";

    ui->textBrowser->setText(s);
    update();
}

void main_window::on_leaves_clicked()
{
    ui->textBrowser->setText(QString::number(t.numOfLeaves()));
    update();
}

void main_window::on_eraseSubTree_clicked()
{
    int pos = ui->key->value();

    auto n = t.getNodeOnPos(pos);
    if (!n)
        return;

    int l = t.numOfLeft(n, pos);
    int r = t.numOfRight(n, pos);

    while (r >= l)
    {
        t.erase(l);
        r--;
    }

    QStandardItemModel *model = new QStandardItemModel();
    QStandardItem *rootItem = model->invisibleRootItem();
    rootItem->appendRow(buildTree(t.getRoot()));

    ui->treeView->setModel(model);
    ui->treeView->expandAll();

    update();
}

void main_window::on_findPar_clicked()
{
    auto first = t.getNodeOnPos(ui->first->value());
    auto second = t.getNodeOnPos(ui->second->value());

    while (first != second)
    {
        if (t.getSize(first) < t.getSize(second))
            first = first->par;
        else
            second = second->par;
    }

    ui->textBrowser->setText(QString::number(first->value));
    update();
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
