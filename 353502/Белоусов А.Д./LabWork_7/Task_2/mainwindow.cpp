#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer (new QTimer)
    , rng(new QRandomGenerator)
    , tree(new vertex)
{
    ui->setupUi(this);

    timer->setInterval(TICK_TIME);
    timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateTreeWidget(QTreeWidgetItem* item, vertex *curr, int depth)
{
    if (curr == nullptr)
    {
        delete item;
        return;
    }

    item->setText(depth, curr->_value);
    item->setExpanded(true);

    if (curr->_left != nullptr)
    {
        item->addChild(new QTreeWidgetItem);
        UpdateTreeWidget(item->child(item->childCount() - 1), curr->_left, depth + 1);
    }

    if (curr->_right != nullptr)
    {
        item->addChild(new QTreeWidgetItem);
        UpdateTreeWidget(item->child(item->childCount() - 1), curr->_right, depth + 1);
    }

}
