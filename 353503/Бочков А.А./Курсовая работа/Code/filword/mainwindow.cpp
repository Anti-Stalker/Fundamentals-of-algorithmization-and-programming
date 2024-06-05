
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

void MainWindow::close()
{
    if (QMessageQuestion::setQuestion(tr("Выход"), tr("Вы действительно хотите выйти из игры?"))
            ->exec()
        == QMessageBox::Yes) {
        QCoreApplication::quit();
    }
}
