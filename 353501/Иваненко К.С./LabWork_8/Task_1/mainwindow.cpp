#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tree.h"

MainWindow::MainWindow() : ui(new Ui::MainWindow), tree(new BinarySearchTree)
{
    ui->setupUi(this);
    ui->textEdit->setFont(QFont("Courier New", 10));

    for (int i = 0; i < 40; ++i)
    {   
        tree->insert(QString("auto - %0").arg(i), rand() % 100);
    }

    ui->textEdit->setText(tree->drawTree());

    std::cout << "Обход в порядке предшественника: ";
    std::cout << tree->preOrderTraversal().toStdString();

    std::cout << '\n';
}

void MainWindow::on_insert_clicked()
{
    tree->insert("inserted", ui->spinBox->value());
    ui->textEdit->setPlainText(tree->drawTree());
}

void MainWindow::on_test_clicked()
{

}

void MainWindow::on_remove_clicked()
{
    int searchKey = ui->removeSpinBox->value();
    if (tree->find(searchKey))
    {
        std::cout << "Узел с ключом " << searchKey << " найден." << std::endl;
    }
    else
    {
        std::cout << "Узел с ключом " << searchKey << " не найден." << std::endl;
    }
    tree->remove(searchKey);
    ui->textEdit->setPlainText(tree->drawTree());
}

void MainWindow::on_removeSubtree_clicked()
{
    int searchKey = ui->removeSubtreeSpinBox->value();
    if (tree->find(searchKey))
    {
        std::cout << "Узел с ключом " << searchKey << " найден." << std::endl;
    }
    else
    {
        std::cout << "Узел с ключом " << searchKey << " не найден." << std::endl;
    }
    tree->removeSubtree(searchKey);
    ui->textEdit->setPlainText(tree->drawTree());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tree;
}
