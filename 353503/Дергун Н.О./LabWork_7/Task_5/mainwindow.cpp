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

void MainWindow::on_push_front_clicked()
{
    _deque.push_front(ui->input->text());
    updateUI();
}


void MainWindow::on_pop_front_clicked()
{
    _deque.pop_front();
    updateUI();
}


void MainWindow::on_push_back_clicked()
{
    _deque.push_back(ui->input->text());
    updateUI();
}


void MainWindow::on_pop_back_clicked()
{
    _deque.pop_back();
    updateUI();
}


void MainWindow::on_index_valueChanged(int arg1)
{
    ui->output->setText(_deque[arg1]);
}


void MainWindow::on_Clear_clicked()
{
    _deque.clear();
    updateUI();
}

void MainWindow::updateUI()
{
    ui->empty->setText(_deque.empty() ? "true" : "false");
    ui->size->setText(QString::number(_deque.size()));

    ui->list->clear();
    for (auto it = _deque.begin(); it != _deque.end(); ++it) {
        ui->list->addItem(new QListWidgetItem(*it));
    }

    ui->index->setMaximum(_deque.size() - 1);
    ui->index->setMinimum(0);
    ui->index->setReadOnly(_deque.empty());
}

