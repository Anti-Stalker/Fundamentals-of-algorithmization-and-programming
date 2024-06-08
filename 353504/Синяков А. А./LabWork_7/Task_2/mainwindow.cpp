#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_insertButton_clicked() {
    int key = ui->keyEdit->text().toInt();
    QString data = ui->dataEdit->text();
    tree.insert(key, data);
    ui->logText->append("Inserted: " + QString::number(key) + " - " + data);
}

void MainWindow::on_removeButton_clicked() {
    int key = ui->keyEdit->text().toInt();
    tree.remove(key);
    ui->logText->append("Removed: " + QString::number(key));
}

void MainWindow::on_findButton_clicked() {
    int key = ui->keyEdit->text().toInt();
    QString result = tree.find(key);
    ui->logText->append("Found: " + QString::number(key) + " - " + result);
}

void MainWindow::on_preOrderButton_clicked() {
    QString result = tree.preOrder();
    ui->logText->append("PreOrder traversal:\n" + result);
}

void MainWindow::on_inOrderButton_clicked() {
    QString result = tree.inOrder();
    ui->logText->append("InOrder traversal:\n" + result);
}

void MainWindow::on_postOrderButton_clicked() {
    QString result = tree.postOrder();
    ui->logText->append("PostOrder traversal:\n" + result);
}

void MainWindow::on_singleChildNodesButton_clicked()
{

      int singleChildNodes = tree.countNodesWithSingleChild();
     ui->logText->append("Number of nodes with single child: " + QString::number(singleChildNodes));

}

