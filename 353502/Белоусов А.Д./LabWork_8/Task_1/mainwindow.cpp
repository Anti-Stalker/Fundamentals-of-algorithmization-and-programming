#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mtree<int> tree1, tree2;

    tree1.addVertex(1);
    tree1.addVertex(2);
    tree1.addVertex(5);

    tree2.addVertex(3);
    tree2.addVertex(4);
    tree2.addVertex(91);

    tree1.addTree(&tree2);

    auto sym = tree1.traverseSymmetric();

    for (auto inst : sym)
    {
        qDebug() << inst;
    }

    qDebug() << tree1.lca(3, 91)->_value;
}

MainWindow::~MainWindow()
{
    delete ui;
}

