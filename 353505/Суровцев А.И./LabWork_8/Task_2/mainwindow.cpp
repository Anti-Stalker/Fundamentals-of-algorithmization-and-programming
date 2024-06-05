#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //model = new QStandardItemModel(this);
    //ui->treeView->setModel(model);
    //ui->treeView->header()->hide();
    //ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display(PriorityQueue<int> &priorityQueue)
{
    ui->label->clear();
    QVector<int> priorityQueueVector = priorityQueue.toVec();
    QString ans = "[ ";
    for (int i : priorityQueueVector) {
        ans += QString::number(i) + ' ';
    }
    ans += "]";
    ui->label->setWordWrap(true);
    ui->label->setText(ans);
}

/*void MainWindow::displayPriorityQueue(QStandardItem* parentItem, PriorityQueue<int>& priorityQueue)
{
    QVector<int> priorityQueueVector = priorityQueue.toVec();
    int size = priorityQueueVector.size();

    QStandardItem* root = new QStandardItem(QString::number(priorityQueueVector[0]));
    if (parentItem) {
        parentItem->appendRow(root);
    } else {
        model->appendRow(root);
    }

    int i = 1;
    while (i < size) {
        QStandardItem* leftChild = new QStandardItem(QString::number(priorityQueueVector[i]));
        root->appendRow(leftChild);

        i++;
        if (i < size) {
            QStandardItem* rightChild = new QStandardItem(QString::number(priorityQueueVector[i]));
            root->appendRow(rightChild);
        }

        root = leftChild;
        i++;
    }

    ui->treeView->expand(model->indexFromItem(root));
}*/



void MainWindow::on_bnt_add_item_clicked()
{
    binHeap.push(ui->spinBox->value());
    display(binHeap);
    //model->clear();
    //displayPriorityQueue(model->invisibleRootItem(), binHeap);
    //ui->treeView->expandAll();
}


void MainWindow::on_bnt_remove_clicked()
{
    binHeap.pop();
    display(binHeap);
    //model->clear();
    //displayPriorityQueue(model->invisibleRootItem(), binHeap);
    //ui->treeView->expandAll();
}


void MainWindow::on_bnt_getMax_clicked()
{
    int max = binHeap.getMax();
    QString ans = QString::number(max);
    QMessageBox::information(this, "Максимальный элемент                     ", ans);
}


void MainWindow::on_bnt_getMin_clicked()
{
    int min = binHeap.getMin();
    QString ans = QString::number(min);
    QMessageBox::information(this, "Минимальный элемент                     ", ans);
}

