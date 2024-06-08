#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userinputdialog.h"
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initWithStr();
    initWithCode();
    initWithPtr();
    initWithRef();

    input = new UserInputDialog();
    connect(input, &UserInputDialog::inputInit, this, &MainWindow::initUserInput);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWithStr()
{
    strInit = {2012, 20, 'S', true, {'c', 'l', 'o', 't','h'}, {12, 23, 32, 45}};

    QString str = QString::number(strInit.year) + "|" + QString::number(strInit.cost) + "|" + strInit.size + "|" + (strInit.has ? "true" : "false") + "|" + QString(strInit.store) + "|";

    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(strInit.post[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser->setText(str);
}

void MainWindow::initWithCode()
{
    codeInit.size = 'S';
    codeInit.cost = 50;
    codeInit.year = 2021;
    codeInit.has = true;
    char codeInitStore[] = "Zwitter";
    for (int i = 0; i < 7; ++i)
    {
        codeInit.store[i] = codeInitStore[i];
    }

    int codeInitPost[] = {24,23,49,800};
    for (int i = 0; i < 4; ++i)
    {
        codeInit.post[i] = codeInitPost[i];
    }

    QString str = QString::number(codeInit.year) + "|" + QString::number(codeInit.cost) + "|" + codeInit.size + "|" + (codeInit.has ? "true" : "false") + "|" + QString(codeInit.store) + "|";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(codeInit.post[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_2->setText(str);
}

void MainWindow::initWithPtr()
{
    ptr->size = 'L';
    ptr->cost = 100.52;
    ptr->year = 2024;
    ptr->has = false;
    char ptrInitStore[] = "T-shirt";
    for (int i = 0; i < 8; ++i)
    {
        ptr->store[i] = ptrInitStore[i];
    }
    int ptrInitPost[] = {99,87,374,939};
    for (int i = 0; i < 4; ++i)
    {
        ptr->post[i] = ptrInitPost[i];
    }

    QString str = QString::number(ptr->year) + "|" + QString::number(ptr->cost) + "|" + ptr->size + "|" + (ptr->has ? "true" : "false") + "|" + QString(ptr->store) + "|";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(ptr->post[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_3->setText(str);
}

void MainWindow::initWithRef()
{
    ref.size = 'M';
    ref.cost = 427;
    ref.year = 2021;
    ref.has = true;
    char refInitStore[] = "Trousers";
    for (int i = 0; i < 8; ++i)
    {
        ref.store[i] = refInitStore[i];
    }
    int refInitPost[] = {0,0,0,0
    };
    for (int i = 0; i < 4; ++i)
    {
        ref.post[i] = refInitPost[i];
    }

    QString str = QString::number(ref.year) + "|" + QString::number(ref.cost) + "|" + ref.size + "|" + (ref.has ? "true" : "false") + "|" + QString(ref.store)+ "|";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(ref.post[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_4->setText(str);
}

void MainWindow::initUserInput(Cloth userInit)
{
    QString str = QString::number(userInit.year) + "|" + QString::number(userInit.cost) + "|" + userInit.size + "|" + (userInit.has ? "true" : "false") + "|" + QString(userInit.store) + "|";
    for (int i = 0; i < 4; ++i)
    {
        str += QString::number(userInit.post[i]) + (i == 3 ? "" : ", ");
    }
    ui->textBrowser_5->setText(str);
}

void MainWindow::on_pushButton_clicked()
{
    input->setWindowModality(Qt::ApplicationModal);
    input->show();
}


void MainWindow::on_pushButton_print_clicked()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    printDialog.setWindowTitle(tr("Print"));
    if (printDialog.exec() != QDialog::Accepted)
    {
        return;
    }

    QTextDocument doc;
    doc.setHtml(ui->textBrowser_5->toHtml());
    doc.print(&printer);
}
