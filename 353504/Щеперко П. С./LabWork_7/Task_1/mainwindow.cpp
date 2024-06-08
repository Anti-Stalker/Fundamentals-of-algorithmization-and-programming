#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dequeueView->setSelectionMode(QAbstractItemView::MultiSelection);
    deque = new Dequeue<QString>;
    QString sourceCode = "template <typename T>\n"
                         "class Dequeue\n"
                         "{\n"
                         "public:\n"
                         "\tDequeue();\n"
                         "\t~Dequeue();\n"
                         "\tbool isEmpty();"
                         "\n\tvoid insertFront(T value);"
                         "\n\tvoid insertRear(T value);\n"
                         "\tvoid removeFront();\n"
                         "\tvoid removeRear();\n"
                         "\tT getFront();\n"
                         "\tT getRear();\n "
                         "private:\n"
                         "\tNode<T> *front;\n"
                         "\tNode<T> *rear;\n"
                         "\tqsizetype size;\n"
                         "};";
    QStringList lines = sourceCode.split("\n");
    for (const auto &line : lines) {
        deque->insertRear(line);
    }
    SetListValues();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetListValues()
{
    QStringList dequeList = deque->getValues();
    QStringListModel *model = new QStringListModel();
    model->setStringList(dequeList);
    ui->dequeueView->setModel(model);
}

void MainWindow::on_dequeueSizePushButton_clicked()
{
    ui->outputLabel->setText("Dequeue size: " + QString::number(deque->getSize()));
}

void MainWindow::on_enqueuePushButton_clicked()
{
    ui->inputPlainTextEdit->setPlainText("Type here...");
    ui->inputPlainTextEdit->setEnabled(true);
}

void MainWindow::on_dequeuePushButton_clicked()
{
    deque->removeFront();
    SetListValues();
}

void MainWindow::on_inputPlainTextEdit_textChanged()
{
    if (ui->inputPlainTextEdit->toPlainText().contains('\n')) {
        ui->inputPlainTextEdit->setEnabled(false);
        deque->insertRear(ui->inputPlainTextEdit->toPlainText().removeLast());
        SetListValues();
    }
}

void MainWindow::on_isEmptyPushButton_clicked()
{
    ui->outputLabel->setText("Is dequeue empty: " + QVariant(deque->isEmpty()).toString());
}

void MainWindow::on_frontPushButton_clicked()
{
    ui->outputLabel->setText("Front element: " + deque->getFront());
}

void MainWindow::on_saveValuesPushButton_clicked()
{
    ui->outputLabel->clear();
    selectedValues = ui->dequeueView->selectionModel()->selectedIndexes();
    for (auto index : selectedValues) {
        savedElements.push_back(index.data(Qt::DisplayRole).toString());
    }
    if (savedElements.empty()) {
        ui->outputLabel->setText("Values are not selected");
    }
}

void MainWindow::on_moveValuesPushButton_clicked()
{
    if (savedElements.empty()) {
        ui->outputLabel->setText("Values are not saved");
    } else if (ui->dequeueView->selectionModel()->selectedIndexes().empty()) {
        ui->outputLabel->setText("Value is not selected");
    } else if (ui->dequeueView->selectionModel()->selectedIndexes().size() > 1) {
        ui->outputLabel->setText("Too many values selected");
    } else {
        QModelIndex index = ui->dequeueView->selectionModel()->selectedIndexes()[0];

        QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->dequeueView->model());
        for (auto index : selectedValues) {
            model->removeRow(index.row());
            qDebug() << index.row();
        }
        ui->dequeueView->setModel(model);
    }
}

