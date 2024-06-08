#include <QString>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bitset.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateBitset();

    ui->testLineEdit->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateBitset()
{
    auto s = bitset.to_string();
    QString tmp;
    tmp.reserve(s.size() * 1.125);
    for (int i = 0; i < s.size(); ++i)
    {
        tmp.push_back(s[i]);
        if (i % 16 == 15)
        {
            tmp.push_back('\n');
        }
    }

    ui->bitsetTextEdit->setText(tmp);
    updateInfo();
}

void MainWindow::updateInfo()
{
    QString html = "<div style='text-align: center;'>"
                   "<table border='1'>"
                   "<tr><th>Function</th><th style='text-align: center;'>Function value</th></tr>"
                   "<tr><td>Size()</td><td style='text-align: center;'>" + QString::number(bitset.size()) + "</td></tr>"
                   "<tr><td>Count()</td><td style='text-align: center;'>" + QString::number(bitset.count()) + "</td></tr>"
                   "<tr><td>All()</td><td style='text-align: center;'>" + (bitset.all() ? "true" : "false") + "</td></tr>"
                   "<tr><td>Any()</td><td style='text-align: center;'>" + (bitset.any() ? "true" : "false") + "</td></tr>"
                   "<tr><td>None()</td><td style='text-align: center;'>" + (bitset.none() ? "true" : "false") + "</td></tr>"
                   "<tr><td>To_ullong()</td><td style='text-align: center;'>" + QString::number(bitset.to_ullong()) + "</td></tr>"
                   "<tr><td>To_ulong()</td><td style='text-align: center;'>" + QString::number(bitset.to_ulong()) + "</td></tr>"
                   "</table>";
    ui->bitsetInformationTextEdit->setHtml(html);
}

void MainWindow::on_flipButton_clicked()
{
    bitset.flip();
    updateBitset();
}

void MainWindow::on_flipIndexButton_clicked()
{
    bitset.flip(ui->indexSpinBox->value());
    updateBitset();
}

void MainWindow::on_setButton_clicked()
{
    bitset.set();
    updateBitset();
}

void MainWindow::on_setIndexButton_clicked()
{
    bitset.set(ui->indexSpinBox->value());
    updateBitset();
}

void MainWindow::on_resetButton_clicked()
{
    bitset.reset();
    updateBitset();
}

void MainWindow::on_resetIndexButton_clicked()
{
    bitset.reset(ui->indexSpinBox->value());
    updateBitset();
}

void MainWindow::on_testIndexButton_clicked()
{
    ui->testLineEdit->setText(bitset.test(ui->indexSpinBox->value()) ? "true" : "false");
    updateBitset();
}