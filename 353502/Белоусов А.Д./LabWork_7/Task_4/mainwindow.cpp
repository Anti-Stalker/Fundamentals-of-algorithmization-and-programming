#include "mainwindow.h"
#include "./ui_mainwindow.h"

const size_t TABLE1_SIZE = 128;
const size_t TABLE2_SIZE = 2048;
const size_t TABLE3_SIZE = 32678;
const size_t TABLE4_SIZE = 100000;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRandomGenerator rng;
    mhash_table<int> table1(TABLE1_SIZE);
    mhash_table<int> table2(TABLE2_SIZE);
    mhash_table<int> table3(TABLE3_SIZE);
    mhash_table<int> table4(TABLE4_SIZE);
    std::string answer1 = "";
    std::string answer2 = "";
    std::string answer3 = "";
    std::string answer4 = "";

    for (int i = 0;i<TABLE1_SIZE;i++)
    {
        clock_t startTime = clock();
        int key = rng.generate();
        int val = rng.generate();

        table1[key] = val;
        assert(table1[key] == val);

        answer1 += std::to_string((double)(clock() - startTime) / CLOCKS_PER_SEC) + " sec \n";
    }

    for (int i = 0;i<TABLE2_SIZE;i++)
    {
        clock_t startTime = clock();
        int key = rng.generate();
        int val = rng.generate();

        table2[key] = val;
        assert(table2[key] == val);

        answer2 += std::to_string((double)(clock() - startTime) / CLOCKS_PER_SEC) + " sec \n";
    }

    for (int i = 0;i<TABLE3_SIZE;i++)
    {
        clock_t startTime = clock();
        int key = rng.generate();
        int val = rng.generate();

        table3[key] = val;
        assert(table3[key] == val);

        answer3 += std::to_string((double)(clock() - startTime) / CLOCKS_PER_SEC) + " sec \n";
    }

    for (int i = 0;i<TABLE4_SIZE;i++)
    {
        clock_t startTime = clock();
        int key = rng.generate();
        int val = rng.generate();

        table4[key] = val;
        assert(table4[key] == val);

        answer4 += std::to_string((double)(clock() - startTime) / CLOCKS_PER_SEC) + " sec \n";
    }

    ui->textBrowser->setText(QString::fromStdString(answer1));
    ui->textBrowser_2->setText(QString::fromStdString(answer2));
    ui->textBrowser_3->setText(QString::fromStdString(answer3));
    ui->textBrowser_4->setText(QString::fromStdString(answer4));
}

MainWindow::~MainWindow()
{
    delete ui;
}

