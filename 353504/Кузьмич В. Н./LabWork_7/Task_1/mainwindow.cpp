#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QFile file("/home/vlad/Lab7_T1/mainwindow.cpp");
    ui->setupUi(this);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw std::runtime_error(QString("Не удалось открыть файл: %1").arg("../mainwindow.cpp").toStdString());
    }
    QTextStream in(&file);
    QStringList lines;
    int stringCounter = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        queue.enqueue(line);
        stringCounter++;
    }
    file.close();
    ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
    displayQueue();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayQueue(){
    ui->listWidget->clear();
    auto res = queue.toVector();
    for (auto & i : res) {
        ui->listWidget->addItem(i);
    }
}


void MainWindow::on_insertButton_clicked(){
    int indexToInsert = -1;
    for (int i = 0; i < ui->listWidget->count(); i++) {
        QListWidgetItem* item = ui->listWidget->item(i);
        if (item->isSelected()) {
            indexToInsert = i;
        }
    }
    if(indexToInsert != -1){
        insertElementsBefore(indexToInsert, selectedElems);
        displayQueue();
    }
}

void MainWindow::insertElementsBefore(int index, QVector<QString>& elementsToInsert) {
    QVector<QString> poppedElems;
    int indexCounter = 0;
    while(indexCounter != index){
        poppedElems.push_back(queue.front());
        queue.dequeue();
        indexCounter++;
    }
    while(!elementsToInsert.isEmpty()){
        queue.insert(elementsToInsert.back(), 0);
        elementsToInsert.pop_back();
    }
    while(!poppedElems.isEmpty()){
        queue.insert(poppedElems.back(), 0);
        poppedElems.pop_back();
    }
}

void MainWindow::on_pushButton_clicked(){
    removeSelectedItemsFromQueue();
    makeListOfSelectedElems();
    displayQueue();
}

void MainWindow::makeListOfSelectedElems(){
    for (int i = 0; i < ui->listWidget->count(); i++) {
        QListWidgetItem* item = ui->listWidget->item(i);
        if (item->isSelected()) {
            selectedElems.push_back(item->text());
        }
    }
}

void MainWindow::removeSelectedItemsFromQueue(){
    QVector<int> indexes;
    int counter = 0;
    for (int i = 0; i < ui->listWidget->count(); i++) {
        QListWidgetItem* item = ui->listWidget->item(i);
        if (item->isSelected()) {
            indexes.push_back(i - counter);
            counter++;
        }
    }
    for(size_t i = 0; i < indexes.size(); i++){
        removeElementByIndex(queue, indexes[i]);
    }
}

void MainWindow::removeElementByIndex(Queue<QString>& deque, size_t index) {
    Queue<QString> tempDeque;
    for (size_t i = 0; i < index; i++) {
        tempDeque.insert(deque.front(), 0);
        deque.dequeue();
    }
    deque.dequeue();
    while (!(tempDeque.getSize() == 0)){
        deque.insert(tempDeque.front(), 0);
        tempDeque.dequeue();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}

